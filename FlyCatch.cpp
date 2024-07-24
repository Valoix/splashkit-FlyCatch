

#include "splashkit.h"

int main() {

    write_line("Fly Catch");
    write_line("Running...");

    // CONSTANTS
    const int SCREEN_WIDTH = 800;
    const int SCREEN_HEIGHT = 600;

    const int SPIDER_RADIUS = 25;
    const int SPIDER_SPEED = 5;

    const int FLY_RADIUS = 15;

    // VARIABLES
    int spider_x = SCREEN_WIDTH / 2;
    int spider_y = SCREEN_HEIGHT / 2;

    bool window_running = true;

    // Init Window
    open_window("Fly Catch", SCREEN_WIDTH, SCREEN_HEIGHT);

    // GAME LOOP
    while (window_running) {
        // Handle Input
        if (key_down(key_code(ESCAPE_KEY))){
            window_running = false;
        }

        if (key_down(key_code(RIGHT_KEY)) && spider_x + SPIDER_RADIUS < SCREEN_WIDTH)
        {
            spider_x += SPIDER_SPEED;
        }
        if (key_down(key_code(LEFT_KEY)) && spider_x - SPIDER_RADIUS > 0)
        {
            spider_x -= SPIDER_SPEED;
        }
        if (key_down(key_code(UP_KEY)) && spider_y - SPIDER_RADIUS > 0)
        {
            spider_y -= SPIDER_SPEED;
        }
        if (key_down(key_code(DOWN_KEY)) && spider_y + SPIDER_RADIUS < SCREEN_HEIGHT)
        {
            spider_y += SPIDER_SPEED;
        }

        clear_screen(color_white());
        fill_circle(color_black(), spider_x, spider_y, SPIDER_RADIUS);
        refresh_screen(60);
        delay(100);
    }

}