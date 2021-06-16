#include "pch/compat.h"

#include "strategy.h"

using namespace framework;

#ifdef __linux__
extern "C" __attribute__((visibility("default"))) void
#else
extern "C" __declspec(dllexport) void __cdecl
#endif
make_strategy(strat::ContextPtr& context, strat::InstancePtr& strategy)
{
    std::cerr << "[DLL Attached] ExportPositions strategy." << std::endl;
    strategy = std::make_shared<ExportPositionsStrategy>(context);
}
