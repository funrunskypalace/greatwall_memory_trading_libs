#ifndef OR_PRE_H
#define OR_PRE_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef NOMINMAX
#define NOMINMAX
#endif

#ifdef __linux__
#define ORAPI __attribute__((visibility("default")))
#else
#ifdef LIBOR_STATIC
#define ORAPI
#else
#if defined(OPENORDERAPI_EXPORTS)
#define ORAPI __declspec(dllexport)
#else
#define ORAPI __declspec(dllimport)
#endif
#endif
#endif

#define LIBOR_COMDAT __declspec(selectany)

#include <algorithm>
#include <atomic>
#include <memory>
#include <sstream>

#endif
