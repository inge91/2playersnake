#ifndef MOUSE_H
#define MOUSE_H
#include <iostream>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include "sdl_functions.h"

class mouse
{
public:
    mouse();
    void draw_image(SDL_Surface* surface);
    SDL_Rect get_pos();
    void respawn();
private:
    // load in image of the mouse
    SDL_Surface* mmouse;

    // position (above left corner) of the
    int mx;
    int my;

};



#endif // MOUSE_H
