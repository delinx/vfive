#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Weverything"
#endif
#ifdef __clang__
#pragma clang diagnostic pop
#endif

#include <stdio.h>

#include "log/log.h"
#include "types.h"

i32 main()
{
    log_debug("bug me!");
    log_information("inform me!");
    log_warning("warn me!");
    log_error("tell me I am wrong!");

    log_error("This is really cool!");
    log_error("Hello lift!");

    return 0;
}
