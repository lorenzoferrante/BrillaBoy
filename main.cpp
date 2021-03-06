#include <iostream>
#include <string>
#include "CPU.h"
#include "GUI.h"
#include <SDL2/SDL.h>

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <ROM>\n";
        std::exit(EXIT_FAILURE);
    }

    CPU cpu = CPU(argv[0]);

    GUI gui;

    int videoPitch = sizeof(cpu.video[0]) * SCREEN_WIDTH;

    bool is_running = true;
    SDL_Event event;

    while (is_running) {
        //gui.update(cpu.video, videoPitch);
        cpu.execute();
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                is_running = false;
            }
        }
        SDL_Delay(16);
    }

    return 0;
}
