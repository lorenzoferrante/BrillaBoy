#include <iostream>
#include <string>
#include "CPU.h"
#include "GUI.h"
#include <SDL2/SDL.h>

/*
 *            *     ,MMM8&&&.            *
 *                 MMMM88&&&&&    .
 *                MMMM88&&&&&&&
 *    *           MMM88&&&&&&&&
 *                MMM88&&&&&&&&
 *                'MMM88&&&&&&'
 *                  'MMM8&&&'      *
 *         |\___/|
 *         )     (             .              '
 *        =\     /=      *
 *          )===(
 *         /     \
 *         |     |
 *        /       \
 *        \       /
 * _/\_/\_/\__  _/_/\_/\_/\_/\_/\_/\_/\_/\_/\_
 * |  |  |  |( (  |  |  |  |  |  |  |  |  |  |
 * |  |  |  | ) ) |  |  |  |  |  |  |  |  |  |
 * |  |  |  |(_(  |  |  |  |  |  |  |  |  |  |
 * |  |  |  |  |  |  |  |  |  |  |  |  |  |  |
 * |  |  |  |  |  |  |  |  |  |  |  |  |  |  |
 *  ____   ____   ____  _      _       ____  ____    ___   __ __
 * |    \ |    \ |    || |    | |     /    ||    \  /   \ |  |  |
 * |  o  )|  D  ) |  | | |    | |    |  o  ||  o  )|     ||  |  |
 * |     ||    /  |  | | |___ | |___ |     ||     ||  O  ||  ~  |
 * |  O  ||    \  |  | |     ||     ||  _  ||  O  ||     ||___, |
 * |     ||  .  \ |  | |     ||     ||  |  ||     ||     ||     |
 * |_____||__|\_||____||_____||_____||__|__||_____| \___/ |____/
 *
 *
 */

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <ROM>\n";
        std::exit(EXIT_FAILURE);
    }

    CPU cpu = CPU(argv[1]);

    GUI gui;

    int videoPitch = sizeof(cpu.video[0]) * SCREEN_WIDTH;

    bool is_running = true;
    SDL_Event event;

    while (is_running) {
        gui.update(cpu.video, videoPitch);
        cpu.execute();

        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                is_running = false;
            }
        }
        //SDL_Delay(1);
    }

    return 0;
}
