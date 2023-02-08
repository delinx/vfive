#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Weverything"
#endif
#include "raylib.h"
#ifdef __clang__
#pragma clang diagnostic pop
#endif

#include <stdio.h>

#include "log/log.h"
#include "types.h"

i32 main()
{
    const u32 screenWidth = 600;
    const u32 screenHeight = 400;

    log_debug("bug me");
    log_information("inform me");
    log_warning("warn me");
    log_error("tell me I am wrong");

    InitWindow(screenWidth, screenHeight, "raylib [core] example - input mouse wheel");
    SetTargetFPS(60);

    while(!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(DARKGRAY);
        DrawText("Test", 10, 10, 20, GRAY);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
