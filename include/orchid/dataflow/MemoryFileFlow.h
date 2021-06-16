#pragma once

#include "orchid/dataflow/MemoryFlow.h"
#include "orchid/message/Package.h"

using namespace orchid::net;

namespace orchid { namespace utility {

class CMemoryFileFlow : public CMemoryFlow {
public:
    CMemoryFileFlow(const PackagePoolPtr& packagePool, const char* szFilename, const char* szPath, bool bReuse, int nMaxObjects,
                    int nBlockSize);

    CMemoryFileFlow(const PackagePoolPtr& packagePool, int _id, const char* szPath, bool bReuse, int nMaxObjects, int nBlockSize);

    virtual ~CMemoryFileFlow();

protected:
    PackagePoolPtr package_pool_;
};

}} // namespace orchid::utility
