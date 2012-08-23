#ifndef PROGRAMLOOP_H
#define PROGRAMLOOP_H
#include <vector>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include "sdl_functions.h"
#include "timer.h"
#include "background.h"
#include "deadscreen.h"
#include "welcomescreen.h"
#include "mouse.h"
#include "playerSnake.h"
#include "computersnake.h"

const int FRAMES_PER_SECOND = 10;

class programLoop
{
public:
    programLoop();
    void run();

private:
    SDL_Surface* screen;
    // Stores the event data
    SDL_Event event;
    void single_play(background myBackground);
    void pvp_play(background myBackground);
    void dead_screen();
    void clean_up();


    Timer fps;
};

#endif // PROGRAMLOOP_H
