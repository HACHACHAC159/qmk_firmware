

#pragma once

#include "config_common.h"
#include <serial_config.h>

#define USE_I2C
#define USE_SERIAL

#if !defined(NO_ACTION_MACRO)
    #define NO_ACTION_MACRO
#endif
#if !defined(NO_ACTION_FUNCTION)
    #define NO_ACTION_FUNCTION
#endif
