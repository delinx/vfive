#include "log.h"
#include <stdio.h>

void log_internal_print(enum LOG_LEVEL_ENUM level, const i8* str, i32 line, const char* file)
{
    char terminal_buffer[LOG_BUFFER_LIMIT];
    u32 terminal_buffer_length = 0;
    i32 terminal_buffer_space_left = sizeof(terminal_buffer);

    if(log_save_to_file)
    {
        // save to file
        FILE* log_file = NULL;
        log_file = fopen("log.txt", "a");
        if(log_file != NULL)
        {
            fprintf(log_file, "%lu %s:%d", (unsigned long)time(NULL), file, line);
            switch(level)
            {
                case LOG_LEVEL_ENUM_DEBUG:
                    fprintf(log_file, " %s", log_level_from_enum[LOG_LEVEL_ENUM_DEBUG]);
                    break;
                case LOG_LEVEL_ENUM_INFORMATION:
                    fprintf(log_file, "  %s", log_level_from_enum[LOG_LEVEL_ENUM_INFORMATION]);
                    break;
                case LOG_LEVEL_ENUM_WARNING:
                    fprintf(log_file, "  %s", log_level_from_enum[LOG_LEVEL_ENUM_WARNING]);
                    break;
                case LOG_LEVEL_ENUM_ERROR:
                    fprintf(log_file, " %s", log_level_from_enum[LOG_LEVEL_ENUM_ERROR]);
                    break;
            }
            fprintf(log_file, " %s\n", str);
            fclose(log_file);
        }
    }

    // add colored file name:file line
    terminal_buffer_length = snprintf(terminal_buffer + (sizeof(terminal_buffer) - terminal_buffer_space_left), terminal_buffer_space_left,
                                      "%s%s%s%s:%s%s%d%s ",
                                      log_color_from_enum[LOG_COLOR_ENUM_BLACK],
                                      log_color_from_enum[LOG_COLOR_ENUM_BG_WHITE],
                                      file,
                                      log_color_from_enum[LOG_COLOR_ENUM_RESET],
                                      log_color_from_enum[LOG_COLOR_ENUM_WHITE],
                                      log_color_from_enum[LOG_COLOR_ENUM_BG_BLACK],
                                      line,
                                      log_color_from_enum[LOG_COLOR_ENUM_RESET]);
    terminal_buffer_space_left -= terminal_buffer_length;

    // add colored level tag
    switch(level)
    {
        case LOG_LEVEL_ENUM_DEBUG:
            terminal_buffer_length = snprintf(terminal_buffer + (sizeof(terminal_buffer) - terminal_buffer_space_left), terminal_buffer_space_left,
                                              "%s%s%s%s",
                                              log_color_from_enum[LOG_COLOR_ENUM_BLACK],
                                              log_color_from_enum[LOG_COLOR_ENUM_BG_GREEN],
                                              log_level_from_enum[LOG_LEVEL_ENUM_DEBUG],
                                              log_color_from_enum[LOG_COLOR_ENUM_RESET]);
            terminal_buffer_space_left -= terminal_buffer_length;
            break;

        case LOG_LEVEL_ENUM_INFORMATION:
            terminal_buffer_length = snprintf(terminal_buffer + (sizeof(terminal_buffer) - terminal_buffer_space_left), terminal_buffer_space_left,
                                              " %s%s%s%s",
                                              log_color_from_enum[LOG_COLOR_ENUM_CYAN],
                                              log_color_from_enum[LOG_COLOR_ENUM_BG_WHITE],
                                              log_level_from_enum[LOG_LEVEL_ENUM_INFORMATION],
                                              log_color_from_enum[LOG_COLOR_ENUM_RESET]);
            terminal_buffer_space_left -= terminal_buffer_length;
            break;

        case LOG_LEVEL_ENUM_WARNING:
            terminal_buffer_length = snprintf(terminal_buffer + (sizeof(terminal_buffer) - terminal_buffer_space_left), terminal_buffer_space_left,
                                              " %s%s%s%s",
                                              log_color_from_enum[LOG_COLOR_ENUM_BLACK],
                                              log_color_from_enum[LOG_COLOR_ENUM_BG_YELLOW],
                                              log_level_from_enum[LOG_LEVEL_ENUM_WARNING],
                                              log_color_from_enum[LOG_COLOR_ENUM_RESET]);
            terminal_buffer_space_left -= terminal_buffer_length;
            break;

        case LOG_LEVEL_ENUM_ERROR:
            terminal_buffer_length = snprintf(terminal_buffer + (sizeof(terminal_buffer) - terminal_buffer_space_left), terminal_buffer_space_left,
                                              "%s%s%s%s",
                                              log_color_from_enum[LOG_COLOR_ENUM_WHITE],
                                              log_color_from_enum[LOG_COLOR_ENUM_BG_RED],
                                              log_level_from_enum[LOG_LEVEL_ENUM_ERROR],
                                              log_color_from_enum[LOG_COLOR_ENUM_RESET]);
            terminal_buffer_space_left -= terminal_buffer_length;
            break;
    }

    // add the log message
    terminal_buffer_length = snprintf(terminal_buffer + (sizeof(terminal_buffer) - terminal_buffer_space_left), terminal_buffer_space_left, " %s", str);
    terminal_buffer_space_left -= terminal_buffer_length;


    printf("%s\n", terminal_buffer);
}
