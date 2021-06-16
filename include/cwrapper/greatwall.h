#ifndef GREATWALL_CWRAPPER_H_
#define GREATWALL_CWRAPPER_H_

#ifdef __cplusplus
extern "C"
{
#endif

typedef MARKET_CALLBACK void (*)(int32_t dataType, const char* data,
                                 size_t datasiz);

void gw_on_market_depth(int32_t dataType, const char* data, size_t datasiz);

void gw_start_service(const char* configFileDir);

#ifdef __cplusplus
}
#endif

#endif // GREATWALL_CWRAPPER_H_