#ifndef LOG_H
#define LOG_H
#pragma once
#include "../types.h"
#include <stdio.h>
#include <string.h>
#include <time.h>

static const usize LOG_BUFFER_LIMIT = 1024;

enum LOG_COLOR_ENUM
{
    LOG_COLOR_ENUM_BLACK,
    LOG_COLOR_ENUM_RED,
    LOG_COLOR_ENUM_GREEN,
    LOG_COLOR_ENUM_YELLOW,
    LOG_COLOR_ENUM_BLUE,
    LOG_COLOR_ENUM_MAGENTA,
    LOG_COLOR_ENUM_CYAN,
    LOG_COLOR_ENUM_WHITE,
    LOG_COLOR_ENUM_BG_BLACK,
    LOG_COLOR_ENUM_BG_RED,
    LOG_COLOR_ENUM_BG_GREEN,
    LOG_COLOR_ENUM_BG_YELLOW,
    LOG_COLOR_ENUM_BG_BLUE,
    LOG_COLOR_ENUM_BG_MAGENTA,
    LOG_COLOR_ENUM_BG_CYAN,
    LOG_COLOR_ENUM_BG_WHITE,
    LOG_COLOR_ENUM_RESET,
    LOG_COLOR_ENUM_COUNT
};

static const char* log_color_from_enum[] = {
    "\033[30m",
    "\033[31m",
    "\033[32m",
    "\033[33m",
    "\033[34m",
    "\033[35m",
    "\033[36m",
    "\033[37m",
    "\033[40m",
    "\033[41m",
    "\033[42m",
    "\033[43m",
    "\033[44m",
    "\033[45m",
    "\033[46m",
    "\033[47m",
    "\033[39;49m",
};

enum LOG_LEVEL_ENUM
{
    LOG_LEVEL_ENUM_DEBUG,
    LOG_LEVEL_ENUM_INFORMATION,
    LOG_LEVEL_ENUM_WARNING,
    LOG_LEVEL_ENUM_ERROR,
};

static const char* log_level_from_enum[] = {
    "[DEBUG]",
    "[INFO]",
    "[WARN]",
    "[ERROR]"
};

// print.c
extern void log_internal_print(enum LOG_LEVEL_ENUM level, const i8* str, i32 line, const char* file);
static bool log_save_to_file = true;

#define __FILENAME__ (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)

#define log_debug(a)       log_internal_print(LOG_LEVEL_ENUM_DEBUG, a, __LINE__, __FILENAME__);
#define log_information(a) log_internal_print(LOG_LEVEL_ENUM_INFORMATION, a, __LINE__, __FILENAME__);
#define log_warning(a)     log_internal_print(LOG_LEVEL_ENUM_WARNING, a, __LINE__, __FILENAME__);
#define log_error(a)       log_internal_print(LOG_LEVEL_ENUM_ERROR, a, __LINE__, __FILENAME__);

#endif  // !LOG_H
