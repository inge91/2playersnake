#ifndef PLAYERSNAKE_H
#define PLAYERSNAKE_H
//#include <iostream>
#include <vector>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include "sdl_functions.h"


using namespace std;

class playerSnake
{
public:
    playerSnake();
    std::vector <SDL_Rect> return_partLocation();
    void make_move(SDL_Event event, SDL_Surface *surface);


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
    std::vector <SDL_Rect*> mclip_locations;

    // A vector that keeps track of the direction of all elements of the snake
    std::vector <int> mdirections;

    void draw_snake(SDL_Surface* surface);

};

#endif // PLAYERSNAKE_H