#ifndef AISNAKE_H
#define AISNAKE_H
#include <iostream>
#include <vector>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include "sdl_functions.h"
#include "mouse.h"
class aiSnake
{
public:
    aiSnake(SDL_Surface *surface);
    void respawn(SDL_Surface *surface);
private:
    // the image holders
    SDL_Surface*  mHead;
    SDL_Surface*  mTail;
    SDL_Surface*  mBody;

    // An enumeration containing the possible directions of the snake
    enum direction
    {
        RIGHT,
        DOWN,
        UP,
        LEFT,
        NONE
    };
    int mlast_press;

    // Stores all the bodypart locations of the playersnake
    std::vector <SDL_Rect>  mparts_locations;

    // Stores the clip locations
    std::vector <SDL_Rect> mclip_locations;

    // A vector that keeps track of the direction of all elements of the snake
    std::vector <int> mdirections;

};

#endif // AISNAKE_H
