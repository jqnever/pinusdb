#pragma once

#include <stdio.h>
#include "spdlog/spdlog.h"

namespace spd = spdlog;

#define LOG_LEVEL_MIN_VAL        1

#define LOG_LEVEL_DEBUG          1
#define LOG_LEVEL_INFO           2
#define LOG_LEVEL_WARNING        3
#define LOG_LEVEL_ERROR          4

#define LOG_LEVEL_MAX_VAL        4


#define LOG_LEVEL_DEBUG_STR      "debug"
#define LOG_LEVEL_INFO_STR       "info"
#define LOG_LEVEL_WARNING_STR    "warning"
#define LOG_LEVEL_ERROR_STR      "error"

#ifdef NO_LOG

#define LOG_ERROR(FORMAT, ...) do { } while(0)
#define LOG_WARNING(FORMAT, ...) do { } while(0)
#define LOG_INFO(FORMAT, ...) do { } while(0)
#define LOG_DEBUG(FORMAT, ...) do { } while(0)

#else


#define LOG_ERROR(FORMAT, ...) do { \
  spd::get("pdb")->error(FORMAT, ## __VA_ARGS__); } while(0)

#define LOG_WARNING(FORMAT, ...) do { \
  spd::get("pdb")->warn(FORMAT, ## __VA_ARGS__); } while(0)

#define LOG_INFO(FORMAT, ...) do { \
  spd::get("pdb")->info(FORMAT, ## __VA_ARGS__); } while(0)

#define LOG_DEBUG(FORMAT, ...) do { \
  spd::get("pdb")->info(FORMAT, ## __VA_ARGS__); } while(0)

#endif

