//
// Created by Lorenzo Ferrante on 06/03/21.
//

#ifndef BRILLABOY_GUI_H
#define BRILLABOY_GUI_H

#include <cstdint>

const int SCREEN_WIDTH = 160;
const int SCREEN_HEIGHT = 144;

class SDL_Window;
class SDL_Renderer;
class SDL_Texture;

class GUI {

public:
    GUI();
    ~GUI();
    void update(void const* buffer, int pitch);

private:
    SDL_Window* window{};
    SDL_Renderer* renderer{};
    SDL_Texture* texture{};
};


#endif //BRILLABOY_GUI_H
