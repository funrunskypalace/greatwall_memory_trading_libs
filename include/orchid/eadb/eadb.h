//! @file
//! @brief database engine using Memory-Mapped Files
//! @author ECNU, Jiang Sanyi
//! @todo:
//!
//! version 21.0311 (21.0311.1100)
//! - add counters..
//!
//! version 14.0516.1400
//! - add "reopen" function to support multiple app reading when writing.
//!
//! version 14.0424.1200
//! - using namespace name "jsy" instead of "eadb".
//!
//! version 13.0813
//! - add intptr_t & uintptr_t(ptrdiff) to represent pointer data type which
//!   will adapt x86/x64 os.
//! - fixed EADB bug under x64: get record failed!
//!
//! version 13.0624
//! - add RLE (Run-Length encoding) functions: from_rle & to_rle.
//!
//! version 13.0623
//! - fixed mapViewWrite static_cast<uint32_t>() truncation when file size
//!   is much larger than view-mapped-position. This usually occurs when
//!   a large database file is already and being used by overwriting.
//!
//! version 13.0515
//! - Update for compile on QtQuick(with MinGW 4.4 & Qt 4.8.4)
//! - reserve an area for record, don't alloc new area if
//!   size not to be exceeded when update a record.
//!
//! version 13.0412
//! - Fixed readAtPosition error, input parameter dsiz must equal to 0
//!
//! version 13.0404
//! - Support max record size: 2GB(EADB_MAX_MAPPEDWINDOWSIZE)
//!
//! version 13.0331
//! - Add leveldb::Slice here.
//!
//! version 13.0330
//! - Implement index using KC IndexDB.
//!
//! version 13.0320
//! - add ENVIRONMENT64 & ENVIRONMENT32 macros
//! - fix compile errors with mingw440/Qt4.8.4 including 'xstring: No such fle
//! or directory' and '::GetFileSizeEx: not declared in this scope'.
//!
//! version 13.0311
//! - obsolete INDEX0 macro, make it a selectable feature.
//!
//! version 13.0310
//! - changed DB::add() return value from bool to int64_t, indicates the
//! record's index in data file.
//! - fixed File Pool efficiency problem that is tested when doing LevelDB
//!   benchmark. (by adding _pfile && _pfileIndex0 member variable)
//! - merge functions of different OSs into one function for coding convenience.
//!
//! version 13.0309
//! - fixed _mapWriteView size issue: when remaining 10B, but there are 20B to
//! be write, next time we should make the size of Mapped View for Write larger
//!   than _mappedWndSize+(20-10)B.
//! - add clear() function to File.
//! - Done benchmark with LevelDB(Batch mode), FILE+fputs, and EADB.
//!
//! version 13.0308
//! - start using date as version.
//! - using eadbASSERT and EADB_DEBUG to avoid assert when
//!   releasing.
//! - seems eadb::EvolutionaryAlgoDB has some problem, so it is
//!   not used when testing EvolutionaryAlgoDB with MOEA/D+Knapsak
//!
//! version 13.0305 (v2.2)
//! - added File Pool feature.
//!
//! version 13.0228 (v2.1)
//! - added Index0 feature.
//! - test with Funshare on Android and QT necessitas,
//!   Android should not use 64 bit integer.
//!

#ifndef __EADB_H__
#define __EADB_H__

#ifdef ORCHID_STATIC
#define EADBLIB_STATIC // always static for orchid-common
#endif

#ifdef __linux__
#define EADBLIB_API __attribute__((visibility("default")))
#else
#ifdef EADBLIB_STATIC
#define EADBLIB_API
#else
#if defined(libeadb_EXPORTS)
#define EADBLIB_API __declspec(dllexport)
#else
#define EADBLIB_API __declspec(dllimport)
#endif
#endif
#endif

#define EADBLIB_COMDAT __declspec(selectany)

/**
 * About EADB
 *
 * EADB uses memory-mapped files to write & read data records.
 * Each data records can be organized with ASON serializer into
 * an ASONObj object.
 *
 * Some utilities are provided and should be chosed as needed:
 * - RLE (Run-Length Encoding) functions,  helps decrease data size
 */

////////////////////////////////////////////////////////////////////////////////////////////////
//!
//! Version Macro
//!
#define EADB_VERSION_MAIN 0x14
#define EADB_VERSION_MINOR 0x0516
#define _EADB_VERSION "14.0516"

////////////////////////////////////////////////////////////////////////////////////////////////
//!
//! Switcheres of features
//!
//!--------------------------------------------------------------------------------------------
//! Feature Groups
#ifndef EADB_NO_DEFALT_FEATURES
#define EADB_NO_DEFALT_FEATURES 0
#endif

//!--------------------------------------------------------------------------------------------
#if (EADB_NO_DEFALT_FEATURES == 0)
#ifdef _EADEBUG // please define _EADEBUG in compiler command arguments
#define EADB_DEBUG 1
#else
#define EADB_DEBUG 0
#endif
/*File Pool feature*/
// If enabled, EADB will not close file until clean_eadb() is called.
#define EADB_ENABLE_FILEPOOL 0
//!*********************************
//!
//! Performance tuners
//!
#define EADB_USE_COMPACTRECORD 1
#define EADB_USE_CLEAR_INSTEADOF_OVERWRITE 1
// Mapping and expand size each time
#define EADB_DEF_MAPPEDWINDOWSIZE 512 * 1024 * 1024

#elif defined(EADB_FEATURES_LEVELDBBENCH) && (EADB_FEATURES_LEVELDBBENCH == 1)
#define EADB_DEBUG 0
#define EADB_ENABLE_FILEPOOL 0
#define EADB_USE_COMPACTRECORD 1
#define EADB_USE_CLEAR_INSTEADOF_OVERWRITE 1
#define EADB_DEF_MAPPEDWINDOWSIZE 1048576 // 1*1024*1024

#elif defined(EADB_FEATURES_MOEADALGO) && (EADB_FEATURES_MOEADALGO == 1)
#define EADB_DEBUG 0
#define EADB_ENABLE_FILEPOOL 1
#define EADB_USE_COMPACTRECORD 1
#define EADB_USE_CLEAR_INSTEADOF_OVERWRITE 1
#define EADB_DEF_MAPPEDWINDOWSIZE                                              \
    65536 // DON'T CHANGE! SHOULD BE 0x10000, AND IS THE SIZE OF FILE HEADER

#endif

#define EADB_MAX_MAPPEDWINDOWSIZE 2147483648 // 2GB
#define EADB_MIN_MAPPEDWINDOWSIZE                                              \
    65536 // DON'T CHANGE! SHOULD BE 0x10000, AND IS THE SIZE OF FILE HEADER

////////////////////////////////////////////////////////////////////////////////

/*******************************************************************************
 * system discrimination
 ******************************************************************************/
#ifndef EADB_UNIQUE_SYSDISCRIMINATION

#if defined(__linux__)

#define INVALID_HANDLE_VALUE -1
#define _SYS_LINUX_
#define _EADB_OSNAME "Linux"

#elif defined(__FreeBSD__)

#define _SYS_FREEBSD_
#define _EADB_OSNAME "FreeBSD"

#elif defined(__NetBSD__)

#define _SYS_NETBSD_
#define _EADB_OSNAME "NetBSD"

#elif defined(__OpenBSD__)

#define _SYS_OPENBSD_
#define _EADB_OSNAME "OpenBSD"

#elif defined(__sun__) || defined(__sun)

#define _SYS_SUNOS_
#define _EADB_OSNAME "SunOS"

#elif defined(__hpux)

#define _SYS_HPUX_
#define _EADB_OSNAME "HP-UX"

#elif defined(__osf)

#define _SYS_TRU64_
#define _EADB_OSNAME "Tru64"

#elif defined(_AIX)

#define _SYS_AIX_
#define _EADB_OSNAME "AIX"

#elif defined(__APPLE__) && defined(__MACH__)

#define _SYS_MACOSX_
#define _EADB_OSNAME "Mac OS X"

#elif defined(_MSC_VER)

#define _SYS_MSVC_
#define _EADB_OSNAME "Windows (VC++)"

#elif defined(_WIN32)

#define _SYS_MINGW_
#define _EADB_OSNAME "Windows (MinGW)"

#elif defined(__CYGWIN__)

#define _SYS_CYGWIN_
#define _EADB_OSNAME "Windows (Cygwin)"

#else

#define _SYS_GENERIC_
#define _EADB_OSNAME "Generic"

#endif

#if defined(_SYS_MINGW_) || defined(_SYS_MSVC_) || defined(_SYS_CYGWIN_)
#define _SYS_WINDOWS_
#define EADB_WINDOWS_OS
#endif

#if defined(__GNUC__)
#define _SYS_UNIX_LINUX_
#define EADB_LINUX_OS
#define EADB_UNIX_OS
#endif

#if defined(_SYS_MACOSX_)
#define _SYS_MAC_
#define EADB_MAC_OS
#endif

/******************************************************************************/

#if defined(__GNUC__)

#define NOINLINE_DECL __attribute__((noinline))
#define PACKED_DECL __attribute__((packed))

#elif defined(_MSC_VER)

#define NOINLINE_DECL __declspec(noinline)
#define PACKED_DECL

#else

#define NOINLINE_DECL
#define PACKED_DECL

#endif

/******************************************************************************/
// Check windows
#if _WIN32 || _WIN64
#if _WIN64
#define ENVIRONMENT64
#else
#define ENVIRONMENT32
#endif
#endif

// Check GCC
#if __GNUC__
#if __x86_64__ || __ppc64__
#define ENVIRONMENT64
#else
#define ENVIRONMENT32
#endif
#endif
/******************************************************************************/
/*                                                                            */
/******************************************************************************/

#define EADB_UNIQUE_SYSDISCRIMINATION
#endif
/******************************************************************************/

/*******************************************************************************
 * standard system development includes
 ******************************************************************************/
extern "C"
{
#include <stdint.h>
}
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#if defined(_SYS_MSVC_) || defined(_SYS_MINGW_)
//#include <WinSock2.h>
#include <windows.h>
#if defined(_SYS_MINGW_)
extern size_t __cdecl strnlen(const char* s, size_t maxlen);
#endif
#else
#include "sys/mman.h"
typedef int32_t HANDLE;
// extern void __cdecl strcpy_s(char *dst, unsigned len, const char *src);
#include <string.h>
#endif

typedef uint64_t eadb_address_t;
typedef int64_t eadb_index_t;
// must be int, not uint!!!
typedef int32_t eadb_size32_t;
typedef int64_t eadb_size64_t;

/**
 * Use this on a type declaration to specify its minimum alignment.
 *
 * Alignments should probably always be powers of two.  Also, note that most
 * allocators will not be able to guarantee better than 16- or 32-byte
 * alignment.
 *
 * Correct:
 *    class EADB_COMPILER_ALIGN_TYPE(16) MyClass {...};
 *
 * Incorrect:
 *    EADB_COMPILER_ALIGN_TYPE(16) class MyClass {...};
 *    class MyClass{...} MONGO_COMPILER_ALIGN_TYPE(16);
 */
#if defined(_SYS_MSVC_) || defined(_SYS_MINGW_)
#define EADB_COMPILER_ALIGN_TYPE(ALIGNMENT) __declspec(align(ALIGNMENT))
#else
#define EADB_COMPILER_ALIGN_TYPE(ALIGNMENT)                                    \
    __attribute__((__aligned__(ALIGNMENT)))
#endif

#include <assert.h>
#if defined(_EDBUYIELD)
#if defined(_MSC_VER)
#define _yield_() ::Sleep(0)
#else
#include <sched.h>
#define _yield_() ::sched_yield()
#endif
#define _testyield_()                                                          \
    do                                                                         \
    {                                                                          \
        static int32_t _EDB_seed = 725;                                        \
        _EDB_seed = _EDB_seed * 123456761 + 211;                               \
        if (_EDB_seed % 0x100 == 0) _yield_();                                 \
    } while (false)
#define _assert_(EDB_a)                                                        \
    do                                                                         \
    {                                                                          \
        _testyield_();                                                         \
        assert(EDB_a);                                                         \
    } while (false)
#elif defined(_EDBDEBUG)
#define _yield_()
#define _testyield_()
#define eadbASSERT(EDB_a) assert(EDB_a)
#else
#define _yield_()         ///< for debugging
#define _testyield_()     ///< for debugging
#define eadbASSERT(EDB_a) ///< for debugging
#endif
#undef assert

#if defined(_MSC_VER)
#define snprintf _snprintf
#endif

#if defined(__CYGWIN__)
inline long double modfl(long double val, long double* iptr)
{
    double integ;
    double fract = std::modf(val, &integ);
    *iptr = integ;
    return fract;
}
#endif

/*******************************************************************************
 * Utility functions
 ******************************************************************************/
extern uint64_t AppMemorySize();

/******************************************************************************/

/*******************************************************************************
 * STL includes and usage criteria
 ******************************************************************************/
#include <limits>
#include <string>
#include <vector>
namespace std
{
using ::modfl;
using ::snprintf;
} // namespace std

#if __cplusplus > 199711L || defined(__GXX_EXPERIMENTAL_CXX0X__) ||            \
    defined(_MSC_VER)

#include <unordered_map>
#include <unordered_set>

#else

#include <tr1/unordered_map>
#include <tr1/unordered_set>

namespace std
{
using tr1::hash;
using tr1::unordered_map;
using tr1::unordered_set;
} // namespace std

#endif
/******************************************************************************/

/*******************************************************************************
 * STL includes and usage criteria
 ******************************************************************************/
#undef VERSION
#undef LIBVER
#undef LIBREV
#undef OSNAME
#undef BIGEND
#undef CLOCKTICK
#undef PAGESIZ
#undef FEATURES
#undef NUMBUFSIZ
#undef MEMMAXSIZ

#undef IOBUFSIZ
#undef SUCCESS
#undef NOIMPL
#undef INVALID
#undef NOREPOS
#undef NOPERM
#undef BROKEN
#undef DUPREC
#undef NOREC
#undef LOGIC
#undef SYSTEM
#undef MISC

#undef DEBUG
#undef INFO
#undef WARN
#undef ERROR
#undef OPEN
#undef CLOSE
#undef CLEAR
#undef ITERATE
#undef SYNCHRONIZE
#undef OCCUPY
#undef BEGINTRAN
#undef COMMITTRAN
#undef ABORTTRAN

#undef INT8MAX
#undef INT16MAX
#undef INT32MAX
#undef INT64MAX
#undef INT8MIN
#undef INT16MIN
#undef INT32MIN
#undef INT64MIN
#undef UINT8MAX
#undef UINT16MAX
#undef UINT32MAX
#undef UINT64MAX
#undef SIZEMAX
#undef FLTMAX
#undef DBLMAX
#undef DBLMIN

#ifndef NUMERIC_LIMITS
#define NUMERIC_LIMITS

/** The maximum value of int8_t. */
const int8_t INT8MAX = (std::numeric_limits<int8_t>::max)();

/** The maximum value of int16_t. */
const int16_t INT16MAX = (std::numeric_limits<int16_t>::max)();

/** The maximum value of int32_t. */
const int32_t INT32MAX = (std::numeric_limits<int32_t>::max)();

/** The maximum value of int64_t. */
const int64_t INT64MAX = (std::numeric_limits<int64_t>::max)();

/** The minimum value of int8_t. */
const int8_t INT8MIN = (std::numeric_limits<int8_t>::min)();

/** The minimum value of int16_t. */
const int16_t INT16MIN = (std::numeric_limits<int16_t>::min)();

/** The minimum value of int32_t. */
const int32_t INT32MIN = (std::numeric_limits<int32_t>::min)();

/** The minimum value of int64_t. */
const int64_t INT64MIN = (std::numeric_limits<int64_t>::min)();

/** The maximum value of uint8_t. */
const uint8_t UINT8MAX = (std::numeric_limits<uint8_t>::max)();

/** The maximum value of uint16_t. */
const uint16_t UINT16MAX = (std::numeric_limits<uint16_t>::max)();

/** The maximum value of uint32_t. */
const uint32_t UINT32MAX = (std::numeric_limits<uint32_t>::max)();

/** The maximum value of uint64_t. */
const uint64_t UINT64MAX = (std::numeric_limits<uint64_t>::max)();

/** The maximum value of size_t. */
const size_t SIZEMAX = (std::numeric_limits<size_t>::max)();

/** The maximum value of float. */
const float FLTMAX = (std::numeric_limits<float>::max)();

/** The maximum value of double. */
const double DBLMAX = (std::numeric_limits<double>::max)();

/** The minimum value of double. */
const double DBLMIN = (std::numeric_limits<double>::min)();

const int64_t FILEMAXSIZ = INT64MAX - INT32MAX;

#endif // NUMERIC_LIMITS

// using std::min;
// using std::max;
/******************************************************************************/

////////////////////////////////////////////////////////////////////////////////////////////////
//!
//! Global functions
//!
//#ifdef __cplusplus
// extern "C" {
//#endif

namespace jsy
{

// release resources that is maintained by eadb
void clean_eadb(void);
std::string wstring2string(const std::wstring& wstr);

#if defined(EADB_ENABLE_FILEPOOL) && (EADB_ENABLE_FILEPOOL == 1)

#endif

class ASONElement;
/* l and r MUST have same type when called: check that first. */
int32_t compareElementValues(const ASONElement& l, const ASONElement& r);

/******************************************************************************/
/* utility data types*/
/******************************************************************************/

extern int64_t counter_asonobjbuilder;
extern int64_t counter_asonobj;

////////////////////////////////////////////////////////////////////////////////////////////////
//!
//! 2013-08-13 support address data type which will adapt for x86 and x64
//! address type.
//!
/*
        uintptr_t and ptrdiff_t is guaranteed to be the same size as a pointer,
   i.e.

        sizeof(void *) == sizeof(uintptr_t)
        && sizeof(void *) == sizeof(ptrdiff_t)

        Note: use uintptr_t to represent address ! since 2013-08-13.

        EADB Design Philosophy:
        - use uint64_t as the data type for database size, record location, and
   etc.
        - use uint32_t as size type. (do not use size_t: it is uint64 in win
   x64).
        - use uintptr_t as the data type for mapped view address.
        */
#if defined(_SYS_MSVC_) || defined(_SYS_MINGW_)
#else
template <int> struct IntegerForSize;
template <> struct IntegerForSize<1>
{
    typedef uint8_t Unsigned;
    typedef int8_t Signed;
};
template <> struct IntegerForSize<2>
{
    typedef uint16_t Unsigned;
    typedef int16_t Signed;
};
template <> struct IntegerForSize<4>
{
    typedef uint32_t Unsigned;
    typedef int32_t Signed;
};
template <> struct IntegerForSize<8>
{
    typedef uint64_t Unsigned;
    typedef int64_t Signed;
};
template <class T> struct IntegerForSizeof : IntegerForSize<sizeof(T)>
{
};
typedef IntegerForSizeof<void*>::Unsigned uintptr_t;
typedef IntegerForSizeof<void*>::Signed ptrdiff_t;
typedef ptrdiff_t intptr_t;
#endif

typedef uint32_t ref_count_t;
typedef uint32_t array_size_t;
typedef uint32_t rec_size_t;
#define REC_SIZE_SIZE 4 /*size of record-header-size-field*/

/******************************************************************************/
/* utility classes*/
/******************************************************************************/

namespace noncopyable_ // protection from unintended ADL
{
class noncopyable
{
protected:
    noncopyable() {}
    ~noncopyable() {}

private: // emphasize the following members are private
    noncopyable(const noncopyable&);
    const noncopyable& operator=(const noncopyable&);
};
} // NAMESPACE noncopyable_

typedef noncopyable_::noncopyable noncopyable;

//
//  intrusive_ptr
//
//  A smart pointer that uses intrusive reference counting.
//
//  Relies on unqualified calls to
//
//      void intrusive_ptr_add_ref(T * p);
//      void intrusive_ptr_release(T * p);
//
//          (p != 0)
//
//  The object is responsible for destroying itself.
//

template <class T> class intrusive_ptr
{
private:
    typedef intrusive_ptr this_type;

public:
    typedef T element_type;

    intrusive_ptr() : px(0) {}

    intrusive_ptr(T* p, bool add_ref = true) : px(p)
    {
        if (px != 0 && add_ref) intrusive_ptr_add_ref(px);
    }

    intrusive_ptr(const intrusive_ptr& rhs) : px(rhs.px)
    {
        if (px != 0) intrusive_ptr_add_ref(px);
    }

    ~intrusive_ptr()
    {
        if (px != 0) intrusive_ptr_release(px);
    }

    intrusive_ptr& operator=(intrusive_ptr const& rhs)
    {
        this_type(rhs).swap(*this);
        return *this;
    }

    intrusive_ptr& operator=(T* rhs)
    {
        this_type(rhs).swap(*this);
        return *this;
    }

    void reset() { this_type().swap(*this); }

    void reset(T* rhs) { this_type(rhs).swap(*this); }

    T* get() const { return px; }

    T& operator*() const
    {
        eadbASSERT(px != 0);
        return *px;
    }

    T* operator->() const
    {
        eadbASSERT(px != 0);
        return px;
    }

    void swap(intrusive_ptr& rhs)
    {
        T* tmp = px;
        px = rhs.px;
        rhs.px = tmp;
    }

private:
    T* px;
};

template <class T>
inline bool operator<(intrusive_ptr<T> const& a, intrusive_ptr<T> const& b)
{
    return std::less<T*>()(a.get(), b.get());
}

template <class T> void swap(intrusive_ptr<T>& lhs, intrusive_ptr<T>& rhs)
{
    lhs.swap(rhs);
}

// mem_fn support

template <class T> T* get_pointer(intrusive_ptr<T> const& p) { return p.get(); }

// Slice is a simple structure containing a pointer into some external
// storage and a size.  The user of a Slice must ensure that the slice
// is not used after the corresponding external storage has been
// deallocated.
//
// Multiple threads can invoke const methods on a Slice without
// external synchronization, but if any of the threads may call a
// non-const method, all threads accessing the same Slice must use
// external synchronization.
class Slice
{
public:
    // Create an empty slice.
    Slice() : data_(""), size_(0) {}

    // Create a slice that refers to d[0,n-1].
    Slice(const char* d, size_t n) : data_(d), size_(n) {}

    // Create a slice that refers to the contents of "s"
    Slice(const std::string& s) : data_(s.data()), size_(s.size()) {}

    // Create a slice that refers to s[0,strlen(s)-1]
    Slice(const char* s) : data_(s), size_(strlen(s)) {}

    // Return a pointer to the beginning of the referenced data
    const char* data() const { return data_; }

    // Return the length (in bytes) of the referenced data
    size_t size() const { return size_; }

    // Return true iff the length of the referenced data is zero
    bool empty() const { return size_ == 0; }

    // Return the ith byte in the referenced data.
    // REQUIRES: n < size()
    char operator[](size_t n) const
    {
        eadbASSERT(n < size());
        return data_[n];
    }

    // Change this slice to refer to an empty array
    void clear()
    {
        data_ = "";
        size_ = 0;
    }

    // Drop the first "n" bytes from this slice.
    void remove_prefix(size_t n)
    {
        eadbASSERT(n <= size());
        data_ += n;
        size_ -= n;
    }

    // Return a string that contains the copy of the referenced data.
    std::string ToString() const { return std::string(data_, size_); }

    // Three-way comparison.  Returns value:
    //   <  0 iff "*this" <  "b",
    //   == 0 iff "*this" == "b",
    //   >  0 iff "*this" >  "b"
    int compare(const Slice& b) const;

    // Return true iff "x" is a prefix of "*this"
    bool starts_with(const Slice& x) const
    {
        return ((size_ >= x.size_) && (memcmp(data_, x.data_, x.size_) == 0));
    }

private:
    const char* data_;
    size_t size_;

    // Intentionally copyable
};

inline bool operator==(const Slice& x, const Slice& y)
{
    return ((x.size() == y.size()) &&
            (memcmp(x.data(), y.data(), x.size()) == 0));
}

inline bool operator!=(const Slice& x, const Slice& y) { return !(x == y); }

inline int Slice::compare(const Slice& b) const
{
    const int min_len = (size_ < b.size_) ? size_ : b.size_;
    int r = memcmp(data_, b.data_, min_len);
    if (r == 0)
    {
        if (size_ < b.size_)
            r = -1;
        else if (size_ > b.size_)
            r = +1;
    }
    return r;
}
/******************************************************************************/

/******************************************************************************
 * Atomic UInt
 ******************************************************************************/
/**
 * An unsigned integer supporting atomic read-modify-write operations.
 *
 * Many operations on these types depend on natural alignment (4 byte alignment
 * for 4-byte words, i.e.).
 */
struct EADB_COMPILER_ALIGN_TYPE(4) AtomicUInt
{
    AtomicUInt() : x(0) {}
    AtomicUInt(unsigned z) : x(z) {}

    operator unsigned() const { return x; }
    unsigned get() const { return x; }
    inline void set(unsigned newX);

    inline AtomicUInt operator++();    // ++prefix
    inline AtomicUInt operator++(int); // postfix++
    inline AtomicUInt operator--();    // --prefix
    inline AtomicUInt operator--(int); // postfix--
    inline void signedAdd(int by);
    inline void zero() { set(0); }
    volatile unsigned x;
};

#if defined(_SYS_MSVC_) || defined(_SYS_MINGW_)
void AtomicUInt::set(unsigned newX)
{
    InterlockedExchange((volatile long*)&x, newX);
}

AtomicUInt AtomicUInt::operator++()
{
    return InterlockedIncrement((volatile long*)&x);
}
AtomicUInt AtomicUInt::operator++(int)
{
    return InterlockedIncrement((volatile long*)&x) - 1;
}
AtomicUInt AtomicUInt::operator--()
{
    return InterlockedDecrement((volatile long*)&x);
}
AtomicUInt AtomicUInt::operator--(int)
{
    return InterlockedDecrement((volatile long*)&x) + 1;
}
#if defined(ENVIRONMENT64)
// don't see an InterlockedAdd for _WIN32...hmmm
void AtomicUInt::signedAdd(int by) { InterlockedAdd((volatile long*)&x, by); }
#endif
#elif defined(__GCC_HAVE_SYNC_COMPARE_AND_SWAP_4)
// this is in GCC >= 4.1
inline void AtomicUInt::set(unsigned newX)
{
    __sync_synchronize();
    x = newX;
}
AtomicUInt AtomicUInt::operator++() { return __sync_add_and_fetch(&x, 1); }
AtomicUInt AtomicUInt::operator++(int) { return __sync_fetch_and_add(&x, 1); }
AtomicUInt AtomicUInt::operator--() { return __sync_add_and_fetch(&x, -1); }
AtomicUInt AtomicUInt::operator--(int) { return __sync_fetch_and_add(&x, -1); }
void AtomicUInt::signedAdd(int by) { __sync_fetch_and_add(&x, by); }
#elif defined(__GNUC__) && (defined(__i386__) || defined(__x86_64__))
inline void AtomicUInt::set(unsigned newX)
{
    asm volatile("mfence" ::: "memory");
    x = newX;
}

// from boost 1.39 interprocess/detail/atomic.hpp
inline unsigned atomic_int_helper(volatile unsigned* x, int val)
{
    int r;
    asm volatile("lock\n\txadd %1, %0"
                 : "+m"(*x), "=r"(r)
                 : // outputs (%0, %1)
                 "1"(val)
                 :              // inputs (%2 == %1)
                 "memory", "cc" // clobbers
    );
    return r;
}
AtomicUInt AtomicUInt::operator++() { return atomic_int_helper(&x, 1) + 1; }
AtomicUInt AtomicUInt::operator++(int) { return atomic_int_helper(&x, 1); }
AtomicUInt AtomicUInt::operator--() { return atomic_int_helper(&x, -1) - 1; }
AtomicUInt AtomicUInt::operator--(int) { return atomic_int_helper(&x, -1); }
void AtomicUInt::signedAdd(int by) { atomic_int_helper(&x, by); }
#else
#error "unsupported compiler or platform"
#endif

/******************************************************************************/

/******************************************************************************/
/* infrastructure classes*/
/******************************************************************************/
#pragma pack(1)
class Record
{
public:
    rec_size_t length; // WithHeaders;
    char reserved[64 - sizeof(rec_size_t)];
    enum
    {
        HeaderSize = 64
    }; // 64B header size

    /** be careful when referencing this that your write intent was correct */
    char data[4];

    bool init(rec_size_t datasize)
    {
        length = HeaderSize + datasize;

        return true;
    }

    rec_size_t netLength() const { return length - HeaderSize; }
};
/******************************************************************************/

class CompactRecord
{
public:
    rec_size_t length; // WithHeaders;
    enum
    {
        HeaderSize = sizeof(rec_size_t)
    }; // 4B header size

    /** be careful when referencing this that your write intent was correct */
    /** this is used only when dereferencing from mmaped area*/
    char data[4];

    bool init(rec_size_t datasize)
    {
        length = HeaderSize + datasize;

        return true;
    }

    rec_size_t netLength() const { return length - HeaderSize; }
};
/******************************************************************************/

class DataFileHeader
{
    friend class File;

public:
    enum
    {
        HeaderSize = EADB_MIN_MAPPEDWINDOWSIZE
    }; // 64KB header size
    // first 16 bytes
    int32_t version;
    int32_t versionMinor;
    uint64_t fileLength;
    // second 16 bytes
    /* unused is the portion of the file that doesn't belong to any allocated
     * records. -1 = no more */
    /* unused includes the header size (initialized to 'HeaderSize') */
    uint64_t unused;
    uint64_t unusedLength;
    // third 16 bytes
    uint8_t compact; /*whether uses CompactRecord*/
    uint8_t fixed; /*whether saved records' number is same for all generations*/
    uint8_t index0; /*0-index0 is not enabled. 1-index0 is enabled.*/
    uint8_t reserved_uint8_t_01;
    uint16_t fixedLength; /*the length of data within a record, not including
                             record header's length*/
    uint8_t reserved_uint8_t_02;
    uint8_t reserved_uint8_t_03;
    int32_t reserved_001;
    eadb_size32_t headerLength; // same as HeaderSize
    // fourth 16 bytes
    eadb_size32_t maxRecordLength; /*the mappedwndsiz determines the record's
                                      maximum length*/
    int32_t reserved_int32_t_01;
    uint64_t recordCount;

private:
    int8_t reserved[960 /*1024-64*/ /*sizeof(int32_t)*12*/];

private:
    char cache[HeaderSize - 1024]; // used to store DB Metadata
    char data[4]; // first record starts here. shall not be included in
                  // HeaderSize

public:
    bool uninitialized() const { return fileLength == 0; }
    void init(uint64_t fileLen, int verMain, int verMinor,
              uint8_t useCompactRecord, uint8_t useFixed, int8_t useIndex0,
              eadb_size32_t maxRecLen)
    {
        if (uninitialized())
        {
            eadbASSERT(fileLen > 32768);

            version = verMain;
            versionMinor = verMinor; // change from 1 to 2 to support
                                     // 1-dimensional indexing
            fileLength = fileLen;
            compact = useCompactRecord;
            fixed = useFixed;
            headerLength = HeaderSize;
            unusedLength = fileLength - headerLength;
            unused = headerLength;
            recordCount = 0;
            index0 = useIndex0;
            maxRecordLength = maxRecLen;
        }
        if (fileLength < fileLen)
        {
            unusedLength += fileLen - fileLength;
            fileLength = fileLen;
        }
    }
    bool isEmpty() const
    {
        return uninitialized() || (unusedLength == fileLength - HeaderSize);
    }
    char* getData(void) { return data; }
    char* getCache(void) { return cache; }
    void setCache(const char*, uint16_t);
    eadb_size32_t getCacheSize() const { return HeaderSize - 1024; }
    void setFixedLength(uint16_t len) { fixedLength = len; }
    eadb_size32_t headerSize(void)
    {
        return (1 == compact) ? (CompactRecord::HeaderSize)
                              : (Record::HeaderSize);
    }
};
#pragma pack()

/*******************************************************************************
 *      ASON: Algorithm Serialized Objects Notation,
 *    Data Notation for Multi-Dimensional Algorithm
 ******************************************************************************/
/* Accessing unaligned doubles on ARM generates an alignment trap and aborts
 * with SIGBUS on Linux. Wrapping the double in a packed struct forces gcc to
 * generate code that works with unaligned values too. The generated code for
 * other architectures (which already allow unaligned accesses) is the same as
 * if there was a direct pointer access.
 */
struct PackedDouble
{
    double d;
} PACKED_DECL;

/* Note the limit here is rather arbitrary and is simply a standard. generally
 * the code works with any object that fits in ram.
 *
 *   Also note that the server has some basic checks to enforce this limit but
 * those checks are not exhaustive for example need to check for size too big
 * after update $push (append) operation various db.eval() type operations
 */
const eadb_size32_t ASONObjMaxUserSize = 16 * 1024 * 1024;

/*
 *   Sometimes we need objects slightly larger - an object in the replication
 * local.oplog is slightly larger than a user object for example.
 */
const eadb_size32_t ASONObjMaxInternalSize = ASONObjMaxUserSize + (16 * 1024);

const eadb_size32_t BufferMaxSize = 64 * 1024 * 1024;

/**
 *A StringData object wraps a 'const string&' or a 'const char*' without
 * copying its contents. The most common usage is as a function argument that
 * takes any of the two forms of strings above. Fundamentally, this class tries
 * go around the fact that string literals in C++ are char[N]'s.
 *
 * Note that the object StringData wraps around must be alive while the
 *StringData is.
 */
class StringData
{
public:
    /**
     * Construct a StringData, for the case where the length of
     * string is not known. 'c' must be a pointer to a null-terminated string.
     */
    StringData(const char* c) : _data(c), _size(std::string::npos) {}

    /**
     * Construct a StringData explicitly, for the case where the length of the
     * string is already known. 'c' must be a pointer to a null-terminated
     * string, and strlenOfc must be the length that strlen(c) would return,
     * a.k.a the index of the terminator in c.
     */
    StringData(const char* c, size_t len) : _data(c), _size(len) {}

    /**
     * Construct a StringData, for the case of a string.
     */
    StringData(const std::string& s) : _data(s.c_str()), _size(s.size()) {}

    // Construct a StringData explicitly, for the case of a literal whose size
    // is known at compile time.
    struct LiteralTag
    {
    };
    template <size_t N>
    StringData(const char (&val)[N], LiteralTag) : _data(&val[0]), _size(N - 1)
    {
    }

    // accessors
    const char* data() const { return _data; }
    size_t size() const
    {
        if (_size == std::string::npos) _size = strlen(_data);
        return _size;
    }

private:
    const char* const _data; // is always null terminated
    mutable size_t _size;    // 'size' does not include the null terminator
};

class TrivialAllocator
{
public:
    void* Malloc(size_t sz) { return malloc(sz); }
    void* Realloc(void* p, size_t sz) { return realloc(p, sz); }
    void Free(void* p) { free(p); }
};

class StackAllocator
{
public:
    enum
    {
        SZ = 512
    };
    void* Malloc(size_t sz)
    {
        if (sz <= SZ) return buf;
        return malloc(sz);
    }
    void* Realloc(void* p, size_t sz)
    {
        if (p == buf)
        {
            if (sz <= SZ) return buf;
            void* d = malloc(sz);
            eadbASSERT(d != 0);
            memcpy(d, p, SZ);
            return d;
        }
        return realloc(p, sz);
    }
    void Free(void* p)
    {
        if (p != buf) free(p);
    }

private:
    char buf[SZ];
};

template <class Allocator> class _BufBuilder
{
    // non-copyable, non-assignable
    _BufBuilder(const _BufBuilder&);
    _BufBuilder& operator=(const _BufBuilder&);
    Allocator al;

public:
    _BufBuilder(eadb_size32_t initsize = 512) : size(initsize)
    {
        if (size > 0)
        {
            data = (char*)al.Malloc(size);
            eadbASSERT(data != 0);
        }
        else
        {
            data = 0;
        }
        l = 0;
    }
    ~_BufBuilder() { kill(); }

    void kill()
    {
        if (data)
        {
            al.Free(data);
            data = 0;
        }
    }

    void reset() { l = 0; }
    void reset(eadb_size32_t maxSize)
    {
        l = 0;
        if (maxSize && size > maxSize)
        {
            al.Free(data);
            data = (char*)al.Malloc(maxSize);
            eadbASSERT(data != 0);
            size = maxSize;
        }
    }

    /** leave room for some stuff later
                @return point to region that was skipped.  pointer may change
       later (on realloc), so for immediate use only
                */
    char* skip(eadb_size32_t n) { return grow(n); }

    /* note this may be deallocated (realloced) if you keep writing. */
    char* buf() { return data; }
    const char* buf() const { return data; }

    /**
     * @brief decouple decouple data buffer.
     *
     * the caller assume ownership of the buffer - caller must then free() it
     */
    void decouple() { data = 0; }

    void appendChar(char j) { *((char*)grow(sizeof(char))) = j; }
    void appendNum(char j) { *((char*)grow(sizeof(char))) = j; }
    void appendNum(double j)
    {
        (reinterpret_cast<PackedDouble*>(grow(sizeof(double))))->d = j;
    }
    void appendNum(int32_t j) { *((int32_t*)grow(sizeof(int32_t))) = j; }
    void appendNum(int64_t j) { *((int64_t*)grow(sizeof(int64_t))) = j; }
    void appendNum(uint32_t j) { *((uint32_t*)grow(sizeof(uint32_t))) = j; }
    void appendNum(uint64_t j) { *((uint64_t*)grow(sizeof(uint64_t))) = j; }
    void appendArraySize(array_size_t j)
    {
        *((array_size_t*)grow(sizeof(array_size_t))) = j;
    }

    void appendBuf(const void* src, size_t len)
    {
        memcpy(grow((eadb_size32_t)len), src, len);
    }

    void appendStr(const StringData& str, bool includeEndingNull = true)
    {
        const eadb_size32_t len = str.size() + (includeEndingNull ? 1 : 0);
        memcpy(grow(len), str.data(), len);
    }

    /** @return length of current string */
    eadb_size32_t len() const { return l; }
    void setlen(eadb_size32_t newLen) { l = newLen; }
    /** @return size of the buffer */
    eadb_size32_t getSize() const { return size; }

    /* returns the pre-grow write position */
    inline char* grow(eadb_size32_t by)
    {
        eadb_size32_t oldlen = l;
        l += by;
        if (l > size)
        {
            grow_reallocate();
        }
        return data + oldlen;
    }

private:
    /* "slow" portion of 'grow()'  */
    void NOINLINE_DECL grow_reallocate()
    {
        int32_t a = 64;
        while (a < l) a = a * 2;
        if (a > BufferMaxSize)
        {
            eadbASSERT(false);
        }
        data = (char*)al.Realloc(data, a);
        eadbASSERT(data != NULL);
        size = a;
    }

    char* data;
    eadb_size32_t l;
    eadb_size32_t size;
};

typedef _BufBuilder<TrivialAllocator> BufBuilder;

/** The StackBufBuilder builds smaller datasets on the stack instead of using
   malloc. this can be significantly faster for small bufs.  However, you can
   not decouple() the buffer with StackBufBuilder. While designed to be a
   variable on the stack, if you were to dynamically allocate one, nothing bad
   would happen.  In fact in some circumstances this might make sense, say,
        embedded in some other object.
        */
class StackBufBuilder : public _BufBuilder<StackAllocator>
{
public:
    StackBufBuilder() : _BufBuilder<StackAllocator>(StackAllocator::SZ) {}
    void decouple(); // not allowed. not implemented.
};

template <typename T> class FieldValue
{
public:
    FieldValue(const std::string& name, const T& t) : _name(name), _t(t) {}

    const T& value() const { return _t; }
    const std::string& name() const { return _name; }

private:
    std::string _name;
    T _t;
};
template <typename T> class Field
{
public:
    Field(const std::string& name) : _name(name) {}

    FieldValue<T> make(const T& t) const { return FieldValue<T>(_name, t); }

    FieldValue<T> operator()(const T& t) const
    {
        return FieldValue<T>(_name, t);
    }

    const std::string& name() const { return _name; }

    std::string operator()() const { return _name; }

private:
    std::string _name;
};

enum Type
{
    /** smaller than all other types */
    MinKey = -1,
    /** end of object */
    EOO = 0,
    /** double precision floating point value */
    NumberDouble = 1,
    /** single precision floating point value */
    NumberFloat = 2,
    /** 32 bit signed integer */
    NumberInt = 16,
    /** 32 bit unsigned integer */
    NumberUInt = 17,
    /** 64 bit signed integer */
    NumberLong = 18,
    /** 64 bit unsigned integer */
    NumberULong = 19,
    /** ascii string */
    ByteString = 20,
    /** larger than all other types */
    MaxKey = 127 /*canbe hold in one byte*/
};

/** ASONElement represents an "element" in a ASONObj.  So for the object { a :
   [3,], b : [1,2,3] }, 'a : [3,]' is the first element (key+value).

        The ASONElement object points into the ASONObj's data.  Thus the ASONObj
   must stay in scope for the life of the ASONElement.

        internals:
        <type><fieldName    ><arrsiz><values-array>
        -----value------------
        --array-value-
        -------- size() ---------------------------
        -fieldNameSize-
        value()
        type()

        ASONElement doesn't explicitly support unsigned int/long type,
        you should manually cast the type.
        */
class EADBLIB_API ASONElement
{
public:
    int64_t Long(int32_t index = 0) const
    {
        return chk(NumberLong)._numberLong(index);
    }
    int32_t Int(int32_t index = 0) const
    {
        return chk(NumberInt)._numberInt(index);
    }
    uint64_t ULong(int32_t index = 0) const
    {
        return (int64_t)chk(NumberULong)._numberLong(index);
    }
    uint32_t UInt(int32_t index = 0) const
    {
        return (int32_t)chk(NumberUInt)._numberInt(index);
    }
    double Double(int32_t index = 0) const
    {
        return chk(NumberDouble)._numberDouble(index);
    }
    float Float(int32_t index = 0) const
    {
        return (float)chk(NumberFloat)._numberDouble(index);
    }
    const char* String() const
    {
        return reinterpret_cast<const char*>(arraydata());
    }
    /** field name of the element.  e.g., for
                name : "Joename" is the fieldname
                */
    const char* fieldName() const
    {
        if (eoo()) return ""; // no fieldname for it.
        return data + 1;
    }
    eadb_size32_t fieldNameSize() const
    {
        if (fieldNameSize_ == -1)
            fieldNameSize_ = (eadb_size32_t)strlen(fieldName()) + 1;
        return fieldNameSize_;
    }
    template <typename T> std::vector<T> array(const T& dummy)
    {
        std::vector<T> arr;
        arr.assign(((T*)arraydata()), ((T*)arraydata()) + arraysize());
        return arr;
    }

    /** raw data of the element's value (so be careful),
                not includes <type><field-name><array-size> fields. */
    const char* arraydata() const
    {
        return (data + fieldNameSize() + 1 +
                sizeof(eadb_size32_t) /*arr-size*/);
    }
    /** size in bytes of the element's data (when applicable).
                not includes <type><field-name><array-size> fields.
                for a whole length of this element, use size().
                */
    eadb_size32_t arraydatasize() const { return arraysize() * typesize(); }
    /** size of array. */
    eadb_size32_t arraysize() const
    {
        if (eoo()) return 0;
        return *reinterpret_cast<const eadb_size32_t*>(data + fieldNameSize() +
                                                       1);
    }
    /** raw data of the element's value (so be careful),
                includes <type><field-name><array-size> fields. */
    const char* rawdata() const { return data; }
    /** Returns the type of the element */
    Type type() const
    {
        return (Type) * reinterpret_cast<const signed char*>(data);
    }
    /** Indicates if it is the end-of-object element, which is present at the
       end of every ASONObj object.
                */
    bool eoo() const { return type() == EOO; }
    eadb_size32_t typesize() const;
    /** raw data size of the element's value (so be careful),
                includes <type><field-name><array-size> fields. */
    eadb_size32_t size() const;
    bool updateData(const char* data, eadb_size32_t dsiz) const;

public:
    ASONElement()
    {
        static char z = 0;
        data = &z;
        fieldNameSize_ = 0;
        totalSize = 1;
    }
    // @param maxLen don't scan more than maxLen bytes
    explicit ASONElement(const char* d, eadb_size32_t maxLen) : data(d)
    {
        if (eoo())
        {
            totalSize = 1;
            fieldNameSize_ = 0;
        }
        else
        {
            totalSize = -1;
            fieldNameSize_ = -1;
            if (maxLen != -1)
            {
                eadb_size32_t size =
                    (eadb_size32_t)strnlen(fieldName(), maxLen - 1);
                eadbASSERT(size != -1); // uassert( 10333 ,  "Invalid field
                                        // name", size != -1 );
                fieldNameSize_ = size + 1;
            }
        }
    }
    explicit ASONElement(const char* d) : data(d)
    {
        fieldNameSize_ = -1;
        totalSize = -1;
        if (eoo())
        {
            fieldNameSize_ = 0;
            totalSize = 1;
        }
    }
    /** Retrieve the numeric value of the element.  If not of a numeric type,
       returns 0. Note: casts to double, data loss may occur with large (>52
       bit) NumberLong values.
                */
    double numberDouble(int32_t index) const
    {
        switch (type())
        {
        case NumberDouble:
            return _numberDouble(index);
        case NumberInt:
            return _numberInt(index);
        case NumberUInt:
            return (uint32_t)_numberInt(index);
        case NumberLong:
            return (double)_numberLong(index);
        case NumberULong:
            return (double)(uint64_t)_numberLong(index);
        default:
            return 0;
        }
    }
    /** Retrieve the numeric value of the element.  If not of a numeric type,
       returns 0. Note: casts to double, data loss may occur with large (>52
       bit) NumberLong values.
                */
    double number(int32_t index) const { return numberDouble(index); }

private:
    const char* data;
    mutable eadb_size32_t fieldNameSize_; // cached value

    mutable eadb_size32_t totalSize; /* caches the computed size */
    const ASONElement& chk(int32_t t) const
    {
        if (t != type())
        {
            eadbASSERT(false);
        }
        return *this;
    }
    const ASONElement& chk(bool expr) const
    {
        eadbASSERT(expr);
        return *this;
    }

protected:
    /** Return double value for this field. MUST be NumberDouble type. */
    double _numberDouble(int32_t index) const
    {
        return (reinterpret_cast<const PackedDouble*>(arraydata() +
                                                      typesize() * index))
            ->d;
    }
    /** Return int32_t value for this field. MUST be NumberInt type. */
    int32_t _numberInt(int32_t index) const
    {
        return *reinterpret_cast<const int32_t*>(arraydata() +
                                                 typesize() * index);
    }
    /** Return int64_t value for this field. MUST be NumberLong type. */
    int64_t _numberLong(int32_t index) const
    {
        return *reinterpret_cast<const int64_t*>(arraydata() +
                                                 typesize() * index);
    }
};

//! {
//!     "gen": int32_t,
//! "chromo":[double, double, ..., double],
//! "fitness":[double|int32_t|long[, double|int32_t|long, ...]]
//! }

//!
//!  ASON: Structured Data Notation
//!  ASONObj object format:
//!
//!     code
//!     <unsigned totalSize> {<byte ASONObjType><cstring FieldName><Data>}* EOO
//!
//!     totalSize includes itself.
//!
class ASONObj
{
public:
    /** Construct a ASONObj from data in the proper format.
     *  Use this constructor when something else owns msgdata's buffer
     */
    explicit ASONObj(const char* msgdata) { init(msgdata); }

    /** Construct a ASONObj from data in the proper format.
     *  Use this constructor when you want ASONObj to free(holder) when it is no
     * longer needed
     */
    class Holder;
    explicit ASONObj(Holder* holder) {
        ++counter_asonobj;
        init(holder); 
    }
    /** Construct an empty ASONObj -- that is, {}. */
    ASONObj()
    {
        ++counter_asonobj;

        /* little endian ordering here, but perhaps that is ok regardless as
           BSON is spec'd to be little endian external to the system. (i.e. the
           rest of the implementation of bson, not this part, fails to support
           big endian)
                        */
        static char p[] = {
            5, 0, 0, 0, 0}; /*4 bytes for size: first 4 chars become an integer,
                               little-endian, the last '0' means eoo */
        _objdata = p;
    };

    ~ASONObj()
    {
        _objdata = 0; // defensive
        --counter_asonobj;
    }
    ASONElement getField(const StringData& name) const;
    /**
                A ASONObj can use a buffer it "owns" or one it does not.

                OWNED CASE
                If the ASONObj owns the buffer, the buffer can be shared among
       several ASONObj's (by assignment). In this case the buffer is basically
       implemented as a shared_ptr. Since ASONObj's are typically immutable,
       this works well. All objects created by "explicit ASONObj(Holder*
       holder)" belong to this case.

                UNOWNED CASE
                A ASONObj can also point to BSON data in some other data
       structure it does not "own" or free later. For example, in a memory
       mapped file.  In this case, it is important the original data stays in
                scope for as long as the ASONObj is in use.  If you think the
       original data may go out of scope, call ASONObj::getOwned() to promote
       your ASONObj to having its own copy. Object get via db.get() is Unowned.

                On a ASONObj assignment, if the source is unowned, both the
       source and dest will have unowned pointers to the original buffer after
       the assignment.

                If you are not sure about ownership but need the buffer to last
       as long as the ASONObj, call getOwned().  getOwned() is a no-op if the
       buffer is already owned.  If not already owned, a malloc and memcpy will
       result.

                Most ways to create ASONObj's create 'owned' variants.  Unowned
       versions can be created with: (1) specifying true for the ifree parameter
       in the constructor (2) calling ASONObjBuilder::done().  Use
       ASONObjBuilder::obj() to get an owned copy (3) retrieving a subobject
       retrieves an unowned pointer into the parent ASON object

                @return true if this is in owned mode
                */
    bool isOwned() const { return _holder.get() != 0; }
    /** @return the raw data of the object,, including <size(4B)><asonelements>
     */
    const char* objdata() const { return _objdata; }
    /** @return total size of the BSON object in bytes, including
     * <size(4B)><asonelements> */
    eadb_size32_t objsize() const
    {
        return *(reinterpret_cast<const uint32_t*>(objdata()));
    }
    /** check whether the object is empty, that is, only 5 bytes. */
    bool isEmpty() const { return objsize() > 5 ? false : true; }
    bool updateField(int32_t fieldIndex, const char* data, eadb_size32_t dsiz);

#pragma pack(1)
    class Holder : noncopyable
    {
    private:
        Holder(); // this class should never be explicitly created
        AtomicUInt refCount;

    public:
        char data[4]; // start of object
        void zero() { refCount = 0; }
        /**not include refCount*/
        eadb_size32_t size(void)
        {
            return *reinterpret_cast<eadb_size32_t*>(data);
        }

        // these are called automatically by boost::intrusive_ptr
        friend void intrusive_ptr_add_ref(Holder* h) { h->refCount++; }
        friend void intrusive_ptr_release(Holder* h)
        {
#if defined(_DEBUG) // cant use dassert or DEV here
            eadbASSERT((int32_t)h->refCount >
                       0); // make sure we haven't already freed the buffer
#endif
            if (--(h->refCount) == 0)
            {
#if defined(_DEBUG)
                // @fixme why sometimes sz < 0?
                eadb_size32_t sz = h->size();
                if (sz > ASONObjMaxInternalSize * 3)
                {
                    eadbASSERT(sz < ASONObjMaxInternalSize * 3);
                }
                else
                {
                    memset(h->data, 0xdd, sz);
                }
#endif
                free(h);
            }
        }
    };
#pragma pack()

private:
    void init(Holder* holder)
    {
        _holder = holder; // holder is now managed by intrusive_ptr
        init(holder->data);
    }
    void init(const char* data)
    {
        _objdata = data;
        if (!isValid())
        {
            eadbASSERT(false); // JSY@todo//_assertInvalid();
        }
    }
    /** performs a cursory check on the object's size only. */
    bool isValid() const;

    const char*
        _objdata; // the internal data pointer (managed or not by _holder)
    intrusive_ptr<Holder> _holder;
    array_size_t _puresize; // total size of each array
};

inline bool ASONObj::isValid() const
{
    eadb_size32_t x = objsize();
    return x > 0 && x <= ASONObjMaxInternalSize;
}

class ASONObjBuilder;
// Utility class to implement ASONObj( name << val << name << val ... )
// as described above.
class ASONObjBuilderValueStream : public noncopyable
{
public:
    ASONObjBuilderValueStream(ASONObjBuilder* builder);

    ASONObjBuilder& operator<<(const ASONElement& e);

    template <class T> ASONObjBuilder& operator<<(T value);

    void endField(const char* nextFieldName = 0);

private:
    const char* _fieldName;
    ASONObjBuilder* _builder;
};

class ASONObjBuilder : public noncopyable
{
public:
    /** @param initsize this is just a hint as to the final size of the object
     */
    ASONObjBuilder(eadb_size32_t initsize = 512)
        : _b(_buf), _buf(initsize + sizeof(eadb_size32_t) /*4B for _offset*/),
          _offset(sizeof(eadb_size32_t)), _s(this), _doneCalled(false)
    {
        ++counter_asonobjbuilder;
        _b.appendNum((ref_count_t)0); // ref-count
        _b.skip(4);                   /*leave room for size field*/
    }
    ~ASONObjBuilder()
    {
        if (!_doneCalled && _b.buf() && _buf.getSize() == 0)
        {
            _done();
        }
        --counter_asonobjbuilder;
    }
    /** Append a double array elements */
    ASONObjBuilder& append(const std::string& fieldName,
                           const std::vector<double>& vals)
    {
        _b.appendChar((char)NumberDouble); // Data Type
        _b.appendStr(fieldName);
        _b.appendArraySize((array_size_t)vals.size());
        for (size_t i = 0; i < vals.size(); ++i) _b.appendNum(vals[i]);
        return *this;
    }
    /** Append a float array elements */
    ASONObjBuilder& append(const std::string& fieldName,
                           const std::vector<float>& vals)
    {
        _b.appendChar((char)NumberFloat); // Data Type
        _b.appendStr(fieldName);
        _b.appendArraySize((array_size_t)vals.size());
        for (size_t i = 0; i < vals.size(); ++i) _b.appendNum(vals[i]);
        return *this;
    }
    /** Append a int32 array elements */
    ASONObjBuilder& append(const std::string& fieldName,
                           const std::vector<eadb_size32_t>& vals)
    {
        _b.appendChar((char)NumberInt); // Data Type
        _b.appendStr(fieldName);
        _b.appendArraySize((array_size_t)vals.size());
        for (size_t i = 0; i < vals.size(); ++i) _b.appendNum(vals[i]);
        return *this;
    }
    /** Append a int64 array elements */
    ASONObjBuilder& append(const std::string& fieldName,
                           const std::vector<int64_t>& vals)
    {
        _b.appendChar((char)NumberLong); // Data Type
        _b.appendStr(fieldName);
        _b.appendArraySize((array_size_t)vals.size());
        for (size_t i = 0; i < vals.size(); ++i) _b.appendNum(vals[i]);
        return *this;
    }
    ASONObjBuilder& append(const std::string& fieldName,
                           const std::vector<uint32_t>& vals)
    {
        _b.appendChar((char)NumberUInt); // Data Type
        _b.appendStr(fieldName);
        _b.appendArraySize((array_size_t)vals.size());
        for (size_t i = 0; i < vals.size(); ++i) _b.appendNum(vals[i]);
        return *this;
    }
    /** Append a int64 array elements */
    ASONObjBuilder& append(const std::string& fieldName,
                           const std::vector<uint64_t>& vals)
    {
        _b.appendChar((char)NumberULong); // Data Type
        _b.appendStr(fieldName);
        _b.appendArraySize((array_size_t)vals.size());
        for (size_t i = 0; i < vals.size(); ++i) _b.appendNum(vals[i]);
        return *this;
    }
    /** Append an ascii string*/
    ASONObjBuilder& append(const std::string& fieldName,
                           const std::string& vals)
    {
        _b.appendChar((char)ByteString); // Data Type
        _b.appendStr(fieldName);
        _b.appendArraySize(
            (array_size_t)vals.size() /*+1 fixme: whether to add the '\0'?*/);
        _b.appendStr(vals, true);
        return *this;
    }
    /** Append an ascii string*/
    ASONObjBuilder& append(const std::string& fieldName, const char* vals)
    {
        return append(fieldName, std::string(vals));
    }
#if 0
		// when `type` is a QString object,
		// the following code line:
		//  `ASON("event"<<event.toStdString()<<"type"<<type`)
		// will cause QtCreator return "error 1" when compiling.
		/** Append a 1-dimensional element */
		template<typename T>
		ASONObjBuilder& append(const std::string& fieldName, T val) {
			std::vector<T> vals(1); vals[0] = val;
			return append(fieldName, vals);
		}
#else
    ASONObjBuilder& append(const std::string& fieldName, int32_t val)
    {
        std::vector<int32_t> vals(1);
        vals[0] = val;
        return append(fieldName, vals);
    }
    ASONObjBuilder& append(const std::string& fieldName, uint32_t val)
    {
        std::vector<uint32_t> vals(1);
        vals[0] = val;
        return append(fieldName, vals);
    }
    ASONObjBuilder& append(const std::string& fieldName, int64_t val)
    {
        std::vector<int64_t> vals(1);
        vals[0] = val;
        return append(fieldName, vals);
    }
    ASONObjBuilder& append(const std::string& fieldName, uint64_t val)
    {
        std::vector<uint64_t> vals(1);
        vals[0] = val;
        return append(fieldName, vals);
    }
    ASONObjBuilder& append(const std::string& fieldName, float val)
    {
        std::vector<float> vals(1);
        vals[0] = val;
        return append(fieldName, vals);
    }
    ASONObjBuilder& append(const std::string& fieldName, double val)
    {
        std::vector<double> vals(1);
        vals[0] = val;
        return append(fieldName, vals);
    }

#endif
    /** append element to the object we are building */
    ASONObjBuilder& append(const ASONElement& e)
    {
        eadbASSERT(!e.eoo()); // do not append eoo, that would corrupt us. the
                              // builder auto appends when done() is called.
        _b.appendBuf((void*)e.rawdata(), e.size());
        return *this;
    }
    /** append an element but with a new name */
    ASONObjBuilder& appendAs(const ASONElement& e, const StringData& fieldName)
    {
        eadbASSERT(!e.eoo()); // do not append eoo, that would corrupt us. the
                              // builder auto appends when done() is called.
        _b.appendNum((char)e.type());
        _b.appendStr(fieldName);
        _b.appendBuf((void*)e.rawdata(), e.size());
        return *this;
    }

    /**
     * destructive
     * The returned ASONObj will free the buffer when it is finished.
     * @return owned ASONObj
     */
    ASONObj obj()
    {
        bool own = owned();
        eadbASSERT(
            own); // massert( 10335 , "builder does not own memory", own );
        doneFast();
        ASONObj::Holder* h = (ASONObj::Holder*)_b.buf();
        decouple(); // sets _b.buf() to NULL
        return ASONObj(h);
    }

    /** Fetch the object we have built.
                BSONObjBuilder still frees the object when the builder goes out
       of scope -- very important to keep in mind.  Use obj() if you would like
       the ASONObj to last longer than the builder.
                */
    ASONObj done() { return ASONObj(_done()); }

    // Like 'done' above, but does not construct a ASONObj to return to the
    // caller.
    void doneFast() { (void)_done(); }
    void decouple()
    {
        _b.decouple(); // post done() call version.  be sure jsobj frees...
    }

    /** Stream oriented way to add field names and values. */
    ASONObjBuilderValueStream& operator<<(const char* name)
    {
        _s.endField(name);
        return _s;
    }
    template <typename T> ASONObjBuilder& operator<<(const FieldValue<T>& v)
    {
        append(v.name(), v.value());
        return *this;
    }
    /** @return true if we are using our own bufbuilder, and not an alternate
     * that was given to us in our constructor */
    bool owned() const { return &_b == &_buf; }

private:
    BufBuilder& _b;
    BufBuilder _buf;
    eadb_size32_t
        _offset; // leave room for ref-count (used by intrusive_ptr Holder)
    ASONObjBuilderValueStream _s;
    bool _doneCalled;

    char* _done()
    {
        if (_doneCalled) return _b.buf() + _offset;

        _doneCalled = true;
        _b.appendChar((char)EOO);
        char* data = _b.buf() + _offset;
        eadb_size32_t size = _b.len() - _offset;
        *((eadb_size32_t*)data) = size;
        return data;
    }
};

//===========================================================================//
// g++ requires the definition of _builder's class (ASONObjBuilder) defined
// before used. so I placed ASONObjBuilderValueStream definitions after
// the definition of class ASONObjBuilder.
inline ASONObjBuilder&
ASONObjBuilderValueStream::operator<<(const ASONElement& e)
{
    _builder->appendAs(e, _fieldName);
    _fieldName = 0;
    return *_builder;
}

inline ASONObjBuilderValueStream::ASONObjBuilderValueStream(
    ASONObjBuilder* builder)
{
    _fieldName = 0;
    _builder = builder;
}

template <class T>
inline ASONObjBuilder& ASONObjBuilderValueStream::operator<<(T value)
{
    _builder->append(_fieldName, value);
    _fieldName = 0;
    return *_builder;
}

inline void ASONObjBuilderValueStream::endField(const char* nextFieldName)
{
    _fieldName = nextFieldName;
}
//===========================================================================//

/** Use ASON macro to build a ASONObj from a stream. Embedded document is not
        supported yet.

        e.g.,
        ASON( "name" << "joe" << "age" << 33 )
        */
#define ASON(x) ((ASONObjBuilder(512) << x).obj())

/** iterator for a ASONObj

        Note each ASONObj ends with an EOO element: so you will get more() on an
   empty object, although next().eoo() will be true.

        The ASONObj must stay in scope for the duration of the iterator's
   execution.

        todo: we may want to make a more stl-like iterator interface for this
        with things like begin() and end()
        */
class ASONObjIterator
{
public:
    /** Create an iterator for a BSON object.
     */
    ASONObjIterator(const ASONObj& jso)
    {
        eadb_size32_t sz = jso.objsize();
        if (sz == 0)
        {
            _pos = _theend = 0;
            return;
        }
        _pos = jso.objdata() + 4;
        _theend = jso.objdata() + sz - 1;
    }

    ASONObjIterator(const char* start, const char* end)
    {
        _pos = start + 4;
        _theend = end - 1;
    }

    /** @return true if more elements exist to be enumerated. */
    bool more() { return _pos < _theend; }

    /** @return true if more elements exist to be enumerated INCLUDING the EOO
     * element which is always at the end. */
    bool moreWithEOO() { return _pos <= _theend; }

    /** @return the next element in the object. For the final element,
     * element.eoo() will be true. */
    ASONElement next(bool checkEnd)
    {
        eadbASSERT(_pos <= _theend);

        eadb_size32_t maxLen = -1;
        if (checkEnd)
        {
            maxLen = _theend + 1 - _pos;
            eadbASSERT(maxLen > 0);
        }

        ASONElement e(_pos, maxLen);
        eadb_size32_t esize = e.size(/*maxLen*/);
        eadbASSERT(esize >
                   0); //( 16446, "ASONElement has bad size", esize > 0 );
        _pos += esize;

        return e;
    }
    ASONElement next()
    {
        eadbASSERT(_pos <= _theend);
        ASONElement e(_pos);
        _pos += e.size();
        return e;
    }
    void operator++() { next(); }
    void operator++(int32_t) { next(); }

    ASONElement operator*()
    {
        eadbASSERT(_pos <= _theend);
        return ASONElement(_pos);
    }

private:
    const char* _pos;
    const char* _theend;
};

inline ASONElement ASONObj::getField(const StringData& name) const
{
    ASONObjIterator i(*this);
    while (i.more())
    {
        ASONElement e = i.next();
        if (strcmp(e.fieldName(), name.data()) == 0
            //** 2016-01-21 临时�?改BUG�? head desc
            //为空的情况，直接读取内�??**//
            || ((char)e.fieldNameSize() == 1)
            //**//
        )
            return e;
    }
    return ASONElement();
}

//! @class
//!
//! @note Mongo uses MongoMMF--private->MemoryMappedView--public-->MongoFile
//! hierarchy, and save file handles in MongoMMF.
//! while for our EastDB, now we just use one File class.
//!
//! @todo: now the same read() is defined in both efile_win.cpp and
//! efile_posix.cpp, it is no good. I should learn from LevelDB and
//! use Env-like classes to hide the OS difference under File.
#if defined(EADB_ENABLE_FILEPOOL) && (EADB_ENABLE_FILEPOOL == 1)
class FilePool;
#endif

struct FileStats
{
    int32_t append_times;
    int32_t reopen_times;
    FileStats() { memset(this, 0, sizeof(FileStats)); }
};
class File
{
#if defined(EADB_ENABLE_FILEPOOL) && (EADB_ENABLE_FILEPOOL == 1)
    friend class FilePool;
#endif
public:
    File();
    ~File() { close(); }

    /*the mappedwndsiz determines the record's maximum length*/
    bool create(const std::string& path, bool overwrite,
                eadb_size32_t mappedWndSiz, int verMajor = EADB_VERSION_MAIN,
                int verMinor = EADB_VERSION_MINOR, uint8_t compact = 0,
                uint8_t fixed = 1, int8_t index0 = 1);
    void close(void);
    void clear(void);
    bool isOpened(void) const;
    /*
                @param [out]recaddr the address of the newly appended record if
       provided.
                */
    bool append(const char* data, size_t dsiz, eadb_address_t* recaddr = 0);
    bool update(eadb_index_t index, ASONObj obj, bool indexAsAddress = false);
    //! Allocate and return a buffer space for write.
    //! @return a buffer with dsiz length for direct write,
    //! this buffer points to the body of a file record
    char* writethrough(size_t dsiz);
    //! @return data pointer to a Record's data field, that is, an ASONObj
    //!  data size is stored in dsiz
    char* readAtIndex(int64_t index /*0-based*/, eadb_size32_t& dsiz,
                      int64_t* nextAddressOffset = 0);
    char* readAtPosition(
        eadb_address_t
            recordPos /*includes record header, not includes file header size*/,
        eadb_size32_t& dsiz);
    DataFileHeader* header() const { return (DataFileHeader*)_map; }
    void tunePadding(int32_t padding);

private:
    bool _expand(void);
    //! @param dataPos: the data to be read, not view address.
    //!                 not including header size.
    //!                 set to 0 to map start from first record.
    bool _mapReadView(eadb_address_t dataPos, eadb_size32_t dsiz);
    //! @param dataPos: the data to be read, not view address.
    //!                 not including header size.
    //!                 set to 0 to map start from first record.
    bool _mapWriteView(eadb_address_t dataPos, eadb_size32_t dsiz);
    void _doClose(void);

private:
    ::HANDLE fh;                 /*file descriptor*/
    ::HANDLE _mapHandle;         /*file mapping handle. no use in Linux/Posix*/
    uint64_t _filePhysiz;        // file map length, maximum is 16EB(win32) or
                                 // 2TB(Linux/ext3)!
    eadb_size32_t _mappedWndSiz; //! the size of bufferred area that user wants
                                 //! for data writing when enlarge file.
    void* _map;                  //! mapped view for File Header!
    eadb_address_t _writeViewOffset; // current pointer offset for write within
                                     // the whole file (not mapped view )
    // the value of _writeViewOffset should include the HeaderSize
    void* _mapWrite;                //! mapped view for sequential data writing!
    eadb_address_t _readViewOffset; // current pointer offset for read within
                                    // the whole file (not mapped view)
    // the value of _readViewOffset should include the HeaderSize
    void* _mapRead; //! mapped view for data reading
    uint64_t _mapSiz;
    uint64_t _mapWriteSiz;
    uint64_t _mapReadSiz;
    int32_t _padding; // record padding, default 0.

public:
    FileStats Stats;
};

class DB : noncopyable
{
public:
    virtual std::string getHeaderDesc(const std::string& defaultDesc) const = 0;
    virtual uint64_t recordCountDynamic() const = 0;
    virtual uint64_t recordCountStatic() const = 0;

private:
    eadb_size32_t _mappedWndSiz;
};

//! @brief the database
class EADBLIB_API VMemDB : public DB
{
public:
    enum
    {
        SMALL_BUF = 0,
        MEDIUM_BUF,
        LARGE_BUF
    };

    VMemDB();
    virtual ~VMemDB();
    bool isOpened(void) { return _opened; }
    bool useIndex0(void) const;
    // JSY@todo//Using a Status object as return value
    /**
     * @param mappedWndSiz Mapping area size. Don't exceed 65MB.
     */
    virtual bool
    open(const std::string& path, bool overwrite, bool fixed, bool index0,
         eadb_size32_t mappedWndSiz = EADB_DEF_MAPPEDWINDOWSIZE,
         eadb_size64_t targetFileSize = (int64_t)10 * (int64_t)1024 *
                                        (int64_t)1024 * (int64_t)1024);
    virtual bool reopen(bool overwrite);
    /*!
                @return -1 on failure, otherwise
                if index0 is enabled, the return value is the 0-based index
       value if index0 is not enabled, the return value is the address of the
                newly added record.
                */
    virtual eadb_address_t add(const ASONObj& obj, eadb_address_t* pAddress);
    virtual bool updateAtIndex(eadb_index_t index, const ASONObj& obj);
    virtual bool updateAtAddress(eadb_address_t address, const ASONObj& obj);
    /*!
                @param isAddress if true, 'index' is the address in the file.
                */
    virtual ASONObj get(int64_t index /*0-based*/, bool isAddress = false,
                        int64_t* nextAddressOffset = 0);
    // virtual bool accept(const char* kbuf, size_t ksiz, Visitor* visitor);
    virtual void close(void);

    void tunePadding(int32_t padding);

    std::string getHeaderDesc(const std::string& defaultDesc) const;
    void setHeaderDesc(const std::string&);
    uint64_t recordCountDynamic() const;
    uint64_t recordCountStatic() const;
    int32_t fileVersionMajor(void) const { return _fileHeader()->version; }
    int32_t fileVersionMinor(void) const { return _fileHeader()->versionMinor; }
    bool isFixed() const;
    std::string pathName() const;
    FileStats fileStats() const;

protected:
    File& getFile(void) const;
    File& getFileIndex0(void) const;
    DataFileHeader* _fileHeader() const { return getFile().header(); }

private:
    /** Dummy constructor to forbid the use. */
    VMemDB(const VMemDB&);
    /** Dummy Operator to forbid the use. */
    VMemDB& operator=(const VMemDB&);
    eadb_address_t indexToAddress(eadb_index_t index);

    bool _opened;
    std::string m_pathName;
    bool m_overWrite;
    eadb_size32_t m_mappedWndSiz;
#if defined(EADB_ENABLE_FILEPOOL) && (EADB_ENABLE_FILEPOOL == 1)
    File* _pfile;
#else
    File _file;
#endif

    File _fileIndex0;
    File* _pfileIndex0;
    int32_t _padding;
    uint64_t _recordCountWhenOpen;

    bool _notFoundIndex0;
};

////////////////////////////////////////////////////////////////////////////////
// assemble pure data
intrusive_ptr<ASONObj::Holder> pureData(const ASONObj& obj);
//! @return the array-values of all elements in an ASONObj,
//! not including 4B length.
eadb_size32_t pureSize(const ASONObj& obj);
void updatePureData(ASONObj& obj, const char* data, eadb_size32_t siz);

////////////////////////////////////////////////////////////////////////////////
// Run-Length Encoding
extern void to_rle(const std::vector<int>& input, std::vector<int>& values,
                   std::vector<int>& occurs);
extern std::vector<int>& from_rle(const std::vector<int>& values,
                                  const std::vector<int>& occurs,
                                  std::vector<int>& output);

#ifdef EADB_WINDOWS_OS
class HRTimer
{
private:
    LARGE_INTEGER start;
    LARGE_INTEGER stop;
    LARGE_INTEGER frequency;
    LARGE_INTEGER timeElapsed;

public:
    HRTimer()
    {
        // get CPU frequency
        QueryPerformanceFrequency(&frequency);
    }

    void startTimer()
    {
        // store initial value
        QueryPerformanceCounter(&start);
    }

    void stopTimer()
    {
        // store end value
        QueryPerformanceCounter(&stop);
    }

    /**
     * @brief getElapsedTime
     * @return in Microseconds.
     */
    int64_t /*double*/ getElapsedTime()
    {
        // get elapsed time
        timeElapsed.QuadPart =
            ((stop.QuadPart - start.QuadPart) * 1000000) / frequency.QuadPart;
        // double elapsedS = (double)timeElapsed.QuadPart /
        // (double)frequency.QuadPart;

        // return elapsed time in Microseconds
        return /*elapsedS*/ timeElapsed.QuadPart;
    }

    int64_t getElapsedTicks()
    {
        timeElapsed.QuadPart = stop.QuadPart - start.QuadPart;
        return timeElapsed.QuadPart;
    }

    int64_t calcElapsedMicroseconds(int64_t ticks)
    {
        return (ticks * 1000000) / frequency.QuadPart;
    }
};

#endif

} // namespace jsy
#undef min
#undef max

#endif
