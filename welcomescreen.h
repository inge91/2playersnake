#ifndef WELCOMESCREEN_H
#define WELCOMESCREEN_H
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include "sdl_functions.h"

class welcomeScreen
{
public:
    welcomeScreen(SDL_Surface *screen);
    void draw_screen(SDL_Surface* surface, SDL_Event event);
    bool get_left();
    bool get_right();
    bool get_middle();
    void delete_surfaces();

private:
    SDL_Surface* welcome_screen;
    SDL_Surface* welcome_screen_single;
    SDL_Surface* welcome_screen_pvp;
    SDL_Surface* welcome_screen_pvc;
    int mx, my;
    bool mleft, mmiddle, mright;

};


#endif // WELCOMESCREEN_H
