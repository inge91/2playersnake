#ifndef BACKGROUND_H
#define BACKGROUND_H
#include <iostream>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"

class background
{
public:
    background();
private:
    SDL_Surface* background_tile;
    SDL_Surface* background_corner_ul;
    SDL_Surface* background_corner_ur;
    SDL_Surface* background_corner_dr;
    SDL_Surface* background_corner_dl;
    SDL_Surface* background_up;
    SDL_Surface* background_down;
    SDL_Surface* background_left;
    SDL_Surface* background_right;

};

#endif // BACKGROUND_H
