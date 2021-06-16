#ifndef DATA_STORE_H
#define DATA_STORE_H

#include <fstream>
#include <iostream>
#include <string>

#ifdef __linux__
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#endif

#include "orchid/common/logger.h"

using namespace orchid;

namespace orchid
{
namespace utility
{

template <class T> class DataStore
{
private:
    DataStore();

public:
    DataStore(int size, std::string filename, bool clear = false);
    ~DataStore();

public:
    T* getData() { return data; }
    int getCount() { return *nelem; }
    T* append(const T* elem);

    int syncOnce(); // linux 使用mmap 需要进行sync， windows下是空方法

private:
    int* nelem;  // count 指针
    T* data;     // dataarea 指针
    int maxSize; //最大文件大小

#ifdef WIN32
    HANDLE m_hFile;
    HANDLE m_hFileMap;
    PBYTE pbFile;
#else
    int fd_;
    char* mapaddr_;
#endif
};

template <class T>
DataStore<T>::DataStore(int size, std::string fname, bool clear)
    : nelem(0), data(0)
{
    if (size < 1)
    {
        std::cerr << "datastore error " << std::endl;
        exit(-1);
    }

    maxSize = sizeof(int) + size * sizeof(T);
    if (clear || (access(fname.c_str(), 0)) == -1)
    { //如果不存在，则创建该文件，并将值赋为0
        std::filebuf fbuf;
        fbuf.open(fname.c_str(), std::ios_base::in | std::ios_base::out |
                                     std::ios_base::trunc |
                                     std::ios_base::binary);
        fbuf.pubseekoff(maxSize, std::ios_base::beg);
        fbuf.sputc(0);
        fbuf.close();
    }
#ifdef WIN32
    m_hFile = CreateFileA(fname.c_str(), GENERIC_READ | GENERIC_WRITE,
                          FILE_SHARE_READ | FILE_SHARE_WRITE, NULL,
                          OPEN_ALWAYS, // OPEN_EXISTING,
                          FILE_ATTRIBUTE_NORMAL, NULL);

    __int64 qwFileOffset = 0;

    if (INVALID_HANDLE_VALUE == m_hFile)
    {
        std::cerr << "open file error : " << fname << std::endl;
        exit(-1);
        return;
    }

    m_hFileMap = CreateFileMapping(m_hFile, NULL, PAGE_READWRITE,
                                   (DWORD)(qwFileOffset >> 32),
                                   (DWORD)(qwFileOffset & 0xFFFFFFFF), NULL);
    if (NULL == m_hFileMap)
    {
        std::cerr << "create file mapping error :" << fname << std::endl;
        exit(-1);
        return;
    }
    DWORD dwBytesInBlock = GetFileSize(m_hFile, NULL); //文件长度
    pbFile = (PBYTE)::MapViewOfFile(m_hFileMap, FILE_MAP_ALL_ACCESS, 0, 0,
                                    dwBytesInBlock);

    char* addr = (char*)pbFile;
    if (clear)
    {
        memset(addr, 0, maxSize);
    }

#else

    fd_ = open(fname.c_str(), O_CREAT | O_RDWR, S_IRUSR | S_IWUSR);
    if (fd_ == -1)
    {
        perror("open");
        exit(-1);
    }

    mapaddr_ =
        (char*)mmap(0, maxSize, PROT_READ | PROT_WRITE, MAP_SHARED, fd_, 0);
    if (mapaddr_ == MAP_FAILED)
    {
        perror("mmap");
        exit(-1);
    }

    char* addr = mapaddr_;
    if (clear)
    {
        memset(addr, 0, maxSize);
    }

#endif

    nelem = (int*)(addr);
    data = (T*)(addr + sizeof(int));

    // ORCHID_LOG(info, "mmapped file: [ {} ]", fname);
}

template <class T> DataStore<T>::~DataStore()
{
#ifdef WIN32
    ::UnmapViewOfFile(pbFile);
    ::CloseHandle(m_hFileMap);
    ::CloseHandle(m_hFile);
#else
    munmap(mapaddr_, maxSize);
    close(fd_);
#endif
}

template <class T> T* DataStore<T>::append(const T* elem)
{
    if (((char*)(data + *nelem + 1)) - ((char*)nelem) > maxSize)
    {
        std::cerr << "append above max size ! "
                  << ((char*)(data + *nelem + 1)) - ((char*)nelem) << "---"
                  << maxSize << std::endl;
        return NULL;
    }
    memcpy(data + *nelem, elem, sizeof(T));
    (*nelem)++;
    return data + *nelem - 1;
}

template <class T> int DataStore<T>::syncOnce()
{
    int ret = 0;
#ifndef WIN32
    ret = msync(mapaddr_, maxSize, MS_SYNC);
#else

#endif
    return ret;
}

} // namespace utility
} // namespace orchid

#endif
