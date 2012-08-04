#include <iostream>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include "sdl_functions.h"
#include "playerSnake.h"
#include "timer.h"
#include "mouse.h"

using namespace std;


int main(int argc, char* args[])
{
    int frame = 0;

    bool cap = true;

    Timer fps;

    //The background images
    SDL_Surface* screen = NULL;
    SDL_Surface* background = NULL;

    // Stores the event data
    SDL_Event event;


    // Start SDL
    if( SDL_Init( SDL_INIT_EVERYTHING) == -1)
    {
        return 1;
    }

    // Set up the screen
    screen = SDL_SetVideoMode(640, 480, 32,
            SDL_SWSURFACE);

    // Check for errors
    if(screen == NULL){
        return 1;
    }

    // Set the window caption
    SDL_WM_SetCaption("2Player Snake", NULL);

    // Load picture into background image
    background= SDL_LoadBMP("../imgs/background.bmp");



    fill_background(background, screen);

    // Create an instance of the playersnake
    playerSnake mySnake;
    mouse myMouse;

    // Updating the screen
    SDL_Flip(screen);



    // Now the mainloop is started
    bool quit = false;
    while( quit == false){
        fps.start();
        int x,y;

        for(x = 0; x < 2000; x++)
        {
            for(y = 0; y < 20000; y++)
            {
            }
        }
        // while there is an event to handle
        fill_background(background, screen);
        myMouse.draw_image(screen);
        mySnake.make_move(event, screen);
        myMouse.draw_image(screen);
        mySnake.grow_snake(myMouse);
        while(SDL_PollEvent(&event)){
            frame++;
            //If we want to cap the frame rate
            if( ( cap == true ) && ( fps.get_ticks() < 1000 / 20 ) )
            {
               //Sleep the remaining frame time
               SDL_Delay( ( 1000 / 20 ) - fps.get_ticks() );
            }
            if(event.type == SDL_QUIT)
            {

                // Quit the loop
                quit = true;
            }
        }

    }


    // The cleanup
    SDL_FreeSurface(
            background);
    SDL_Quit();

    return
        0;
}


