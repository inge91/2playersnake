#include <iostream>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include "sdl_functions.h"
#include "playerSnake.h"
#include "timer.h"
#include "mouse.h"
#include "deadscreen.h"

using namespace std;
const int FRAMES_PER_SECOND = 8;

int main(int argc, char* args[])
{
    int frame = 0;


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
    //screen = SDL_SetVideoMode(1000,700 , 32,
    //        SDL_SWSURFACE);
    // Check for errors
    if(screen == NULL){
        return 1;
    }

    // Set the window caption
    SDL_WM_SetCaption("2Player Snake", NULL);

    // Load picture into background image
    background= load_image("../imgs/background.bmp");



    fill_background(background, screen);

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
        int x,y;
        if(!mySnake.touched_self()&& !mySnake.wall_collision(screen))
        {

            // while there is an event to handle
            fill_background(background, screen);
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
            frame++;

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


