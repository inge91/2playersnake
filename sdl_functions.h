#ifndef SDL_FUNCTIONS_H
#define SDL_FUNCTIONS_H

#include <iostream>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
SDL_Surface *load_image( std::string filename );
void fill_background(SDL_Surface* the_background, SDL_Surface* the_screen);
void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip);
SDL_Surface *load_image( std::string filename );
#endif // SDL_FUNCTIONS_H
