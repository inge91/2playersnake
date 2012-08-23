#include <iostream>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include "sdl_functions.h"
#include "playerSnake.h"
#include "timer.h"
#include "mouse.h"
#include "deadscreen.h"
#include "background.h"
#include "programloop.h"

using namespace std;
//const int FRAMES_PER_SECOND = 8;

int main(int argc, char* args[])
{
    programLoop myLoop;

    myLoop.run();
/*
    Timer fps;

    //The background images
    SDL_Surface* screen = NULL;
    //SDL_Surface* background = NULL;

    // Stores the event data
    SDL_Event event;


    // Start SDL
    if( SDL_Init( SDL_INIT_EVERYTHING) == -1)
    {
        return 1;
    }

    // Set up the screen
    screen = SDL_SetVideoMode(630, 450, 32,
            SDL_SWSURFACE);
    //screen = SDL_SetVideoMode(1000,700 , 32,
    //        SDL_SWSURFACE);
    // Check for errors
    if(screen == NULL){
        return 1;
    }

    // Set the window caption
    SDL_WM_SetCaption("2Player Snake", NULL);

    // Load picture into background image
    //background= load_image("../imgs/background.bmp");

    background myBackground;

    //fill_background(background, screen, 0, 0);
    myBackground.apply_background(screen);


    // Create an instance of the playersnake
    playerSnake mySnake;
    mouse myMouse;
    deadScreen myDead(screen);



    // Updating the screen
    SDL_Flip(screen);



    // Now the mainloop is started
    bool quit = false;
    while( quit == false){
        fps.start();

        if(!mySnake.touched_self()&& !mySnake.wall_collision(screen))
        {

            // while there is an event to handle
            //fill_background(background, screen,0,0);
            myBackground.apply_background(screen);
            myMouse.draw_image(screen);
            mySnake.make_move(event, screen);
            myMouse.draw_image(screen);
            if(mySnake.grow_snake(myMouse)){
                myMouse.respawn();
            }
        }
        else{

            myDead.draw_screen(screen, event);
            while(SDL_PollEvent(&event)){
                myDead.draw_screen(screen, event);
                if(event.key.keysym.sym == SDLK_RETURN){
                    if(myDead.exit()){
                    quit = true;
                    }
                    else{

                    mySnake.respawn();
                    myMouse.respawn();

                    break;
                    }


                break;
                }
                if(event.type == SDL_QUIT )
                {
                    // Quit the loop
                    quit = true;
                    break;
                }


            }

        }



        while(SDL_PollEvent(&event)){


            if(event.type == SDL_QUIT)
            {

                // Quit the loop
                quit = true;
            }

        }
        //If we want to cap the frame rate
            if( ( fps.get_ticks() < 1000 / FRAMES_PER_SECOND ) )
            {
                //Sleep the remaining frame time
                SDL_Delay( ( 1000 / FRAMES_PER_SECOND ) - fps.get_ticks() );
            }

    }


    // The cleanup
    //SDL_FreeSurface(background);
    SDL_Quit();

    return
        0;
        */
}


