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
private:
    // load in image of the mouse
    SDL_Surface* mmouse;


};

#endif // MOUSE_H
