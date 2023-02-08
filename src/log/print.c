#include "log.h"
#include <stdio.h>

void log_internal_print(enum LOG_LEVEL_ENUM level, const i8* str, i32 line, const char* file)
{
    char buffer[LOG_BUFFER_LIMIT];
    u32 buffer_length = 0;
    i32 buffer_space_left = sizeof(buffer);

    // add colored file name : file line
    buffer_length = snprintf(buffer + (sizeof(buffer) - buffer_space_left), buffer_space_left,
                             "%s%s%s%s:%s%s%d%s ",
                             log_colorcode_from_enum[LOG_COLOR_ENUM_BLACK],
                             log_colorcode_from_enum[LOG_COLOR_ENUM_BG_WHITE],
                             file,
                             log_colorcode_from_enum[LOG_COLOR_ENUM_RESET],
                             log_colorcode_from_enum[LOG_COLOR_ENUM_WHITE],
                             log_colorcode_from_enum[LOG_COLOR_ENUM_BG_BLACK],
                             line,
                             log_colorcode_from_enum[LOG_COLOR_ENUM_RESET]);
    buffer_space_left -= buffer_length;

    switch(level)
    {
        case LOG_LEVEL_ENUM_DEBUG:
            buffer_length = snprintf(buffer + (sizeof(buffer) - buffer_space_left), buffer_space_left,
                                     "%s%s%s%s",
                                     log_colorcode_from_enum[LOG_COLOR_ENUM_BLACK],
                                     log_colorcode_from_enum[LOG_COLOR_ENUM_BG_GREEN],
                                     log_level_from_enum[LOG_LEVEL_ENUM_DEBUG],
                                     log_colorcode_from_enum[LOG_COLOR_ENUM_RESET]);
            buffer_space_left -= buffer_length;
            break;

        case LOG_LEVEL_ENUM_INFORMATION:
            buffer_length = snprintf(buffer + (sizeof(buffer) - buffer_space_left), buffer_space_left,
                                     " %s%s%s%s",
                                     log_colorcode_from_enum[LOG_COLOR_ENUM_CYAN],
                                     log_colorcode_from_enum[LOG_COLOR_ENUM_BG_WHITE],
                                     log_level_from_enum[LOG_LEVEL_ENUM_INFORMATION],
                                     log_colorcode_from_enum[LOG_COLOR_ENUM_RESET]);
            buffer_space_left -= buffer_length;
            break;

        case LOG_LEVEL_ENUM_WARNING:
            buffer_length = snprintf(buffer + (sizeof(buffer) - buffer_space_left), buffer_space_left,
                                     " %s%s%s%s",
                                     log_colorcode_from_enum[LOG_COLOR_ENUM_BLACK],
                                     log_colorcode_from_enum[LOG_COLOR_ENUM_BG_YELLOW],
                                     log_level_from_enum[LOG_LEVEL_ENUM_WARNING],
                                     log_colorcode_from_enum[LOG_COLOR_ENUM_RESET]);
            buffer_space_left -= buffer_length;
            break;

        case LOG_LEVEL_ENUM_ERROR:
            buffer_length = snprintf(buffer + (sizeof(buffer) - buffer_space_left), buffer_space_left,
                                     "%s%s%s%s",
                                     log_colorcode_from_enum[LOG_COLOR_ENUM_WHITE],
                                     log_colorcode_from_enum[LOG_COLOR_ENUM_BG_RED],
                                     log_level_from_enum[LOG_LEVEL_ENUM_ERROR],
                                     log_colorcode_from_enum[LOG_COLOR_ENUM_RESET]);
            buffer_space_left -= buffer_length;
            break;
    }

    buffer_length = snprintf(buffer + (sizeof(buffer) - buffer_space_left), buffer_space_left, " %s", str);
    buffer_space_left -= buffer_length;

    printf("%s\n", buffer);
}

void log_internal_debug(const i8* str, i32 line, const char* file)
{
    log_internal_print(LOG_LEVEL_ENUM_DEBUG, str, line, file);
}

void log_internal_information(const i8* str, i32 line, const char* file)
{
    log_internal_print(LOG_LEVEL_ENUM_INFORMATION, str, line, file);
}

void log_internal_warning(const i8* str, i32 line, const char* file)
{
    log_internal_print(LOG_LEVEL_ENUM_WARNING, str, line, file);
}

void log_internal_error(const i8* str, i32 line, const char* file)
{
    log_internal_print(LOG_LEVEL_ENUM_ERROR, str, line, file);
}
