#include "programloop.h"

programLoop::programLoop()

{

      //The background images
      screen = NULL;

      // Start SDL
      SDL_Init( SDL_INIT_EVERYTHING);

      // Set up the screen
      screen = SDL_SetVideoMode(630, 450, 32,
              SDL_SWSURFACE);
      // Check for errors
      screen == NULL;

      // Set the window caption
      SDL_WM_SetCaption("2Player Snake", NULL);

}
// Runs the program starting with the welcome prompt
void programLoop::run(){

    welcomeScreen myWelcomeScreen(screen);
    background myBackground;
    myBackground.apply_background(screen);
    myWelcomeScreen.draw_screen(screen, event);

    // Refresh the screen
    SDL_Flip(screen);

    bool quit = false;
    bool play;

    // Start running with the welcome prompt
    while(quit == false)
    {

        while(SDL_PollEvent(&event))
        {

            myWelcomeScreen.draw_screen(screen, event);

            if(event.key.keysym.sym  == SDLK_RETURN)
            {
                play = true;
                quit = true;
                break;
            }
            else if(event.type == SDL_QUIT)
            {
                clean_up();
                exit(0);
            }
        }

    }

    if(play == true){
        if(myWelcomeScreen.get_left())
        {
            myWelcomeScreen.delete_surfaces();
            single_play(myBackground);
        }
        else if(myWelcomeScreen.get_middle())
        {
          pvp_play(myBackground);
        }
        else if(myWelcomeScreen.get_right())
        {
           // pvc_play();
        }
    }
    else
    {
        // Program terminates
    }
}


void programLoop::single_play(background myBackground)
{

    playerSnake mySnake;
    mouse myMouse(screen);
    bool quit = false;

    while(!mySnake.touched_self()&& !mySnake.wall_collision(screen) && quit == false)
    {
        fps.start();
        // while there is an event to handle
        //fill_background(background, screen,0,0);
        myBackground.apply_background(screen);
        myMouse.draw_image(screen);
        mySnake.make_move(event, screen);
        myMouse.draw_image(screen);
        if(mySnake.grow_snake(myMouse)){
            myMouse.respawn(screen);
        }

        while(SDL_PollEvent(&event)){


            if(event.type == SDL_QUIT)
            {
                clean_up();
                exit(0);
            }

        }
        //If we want to cap the frame rate
        if( ( fps.get_ticks() < 1000 / FRAMES_PER_SECOND ) )
        {
            //Sleep the remaining frame time
            SDL_Delay( ( 1000 / FRAMES_PER_SECOND ) - fps.get_ticks() );
        }


    }

    dead_screen();

}

void programLoop::pvp_play(background myBackground)
{
    playerSnake mySnake;
    computerSnake myCompSnake(screen);
    mouse myMouse(screen);
    bool quit = false;

    while(!mySnake.touched_self()&& !mySnake.wall_collision(screen) && quit == false)
    {
        fps.start();
        // while there is an event to handle

        myBackground.apply_background(screen);
        myMouse.draw_image(screen);
        mySnake.make_move(event, screen);
        myCompSnake.make_move(event,screen);
        myMouse.draw_image(screen);
        if(mySnake.grow_snake(myMouse)){
            myMouse.respawn(screen);
        }

        while(SDL_PollEvent(&event)){


            if(event.type == SDL_QUIT)
            {
                clean_up();
                exit(0);
            }

        }
        //If we want to cap the frame rate
        if( ( fps.get_ticks() < 1000 / FRAMES_PER_SECOND ) )
        {
            //Sleep the remaining frame time
            SDL_Delay( ( 1000 / FRAMES_PER_SECOND ) - fps.get_ticks() );
        }


    }

    dead_screen();

}

void programLoop::dead_screen(){

    deadScreen myDead(screen);
    myDead.draw_screen(screen, event);
    bool quit = false;
    while(quit == false)
    {
        while(SDL_PollEvent(&event)){
            myDead.draw_screen(screen, event);
            if(event.key.keysym.sym == SDLK_RETURN){
                if(myDead.exit())
                {
                    clean_up();
                    exit(0);
                }
                else{
                    SDL_Delay(200);
                    SDL_PollEvent(&event);
                    run();

                }


            break;
            }
            if(event.type == SDL_QUIT )
            {
                clean_up();
                // Quit the loop
                exit(0);
            }
        }
    }
}

void programLoop::clean_up(){

    SDL_FreeSurface(screen);
    SDL_Quit();

}
