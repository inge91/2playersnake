#include "welcomescreen.h"

welcomeScreen::welcomeScreen(SDL_Surface* screen)
{
    welcome_screen = NULL;
    welcome_screen_single = NULL;
    welcome_screen_pvp = NULL;
    welcome_screen_pvc = NULL;

    welcome_screen = load_image("../imgs/welcome_screen/welcome_screen.bmp");
    welcome_screen_single = load_image("../imgs/welcome_screen/welcome_screen_single.bmp");
    welcome_screen_pvp = load_image("../imgs/welcome_screen/welcome_screen_pvp.bmp");
    welcome_screen_pvc = load_image("../imgs/welcome_screen/welcome_screen_pvc.bmp");

    // Position in midst of screen
    mx = screen->w/2 - welcome_screen->w/2;
    my = screen->h/2 - welcome_screen->h/2;

    // Initialise the right screen
    mleft = true;
    mmiddle, mright = false;
}

// Draws the menu message on the screen, and depending on mouse position
// displays one of the possible screens
void welcomeScreen::draw_screen(SDL_Surface* surface, SDL_Event event)
{
    //std::cout<<"here";
    // Handle the look of the dead screen
    if(event.type == SDL_KEYDOWN){
        if(event.key.keysym.sym == SDLK_RIGHT && mleft)
        {

            apply_surface(mx, my, welcome_screen_pvp, surface, NULL);
            mleft = false;
            mmiddle = true;
            mright = false;

        }
        else if(event.key.keysym.sym == SDLK_RIGHT && mmiddle)
        {
            apply_surface(mx, my, welcome_screen_pvc, surface, NULL);
            mleft = false;
            mmiddle = false;
            mright = true;
        }
        else if (event.key.keysym.sym == SDLK_LEFT && mright)
        {
            apply_surface(mx, my, welcome_screen_pvp, surface, NULL);
            mleft = false;
            mmiddle = true;
            mright = false;
        }
        else if (event.key.keysym.sym == SDLK_LEFT && mmiddle)
        {
            apply_surface(mx, my, welcome_screen_single, surface, NULL);
            mleft = true;
            mmiddle = false;
            mright = false;
        }
    }
    else{

        if(mleft)
        {
            apply_surface(mx, my, welcome_screen_single, surface, NULL);

        }
        else if(mmiddle){

            apply_surface(mx, my, welcome_screen_pvp, surface, NULL);

        }
        else if(mright){
               apply_surface(mx, my, welcome_screen_pvc, surface, NULL);

        }
    }

    // Refresh the screen!
    SDL_Flip(surface);
}

// Return private field value
bool welcomeScreen::get_left(){
    return mleft;
}

bool welcomeScreen::get_middle(){
    return mmiddle;
}

bool welcomeScreen::get_right(){
    return mright;
}

// Delete all assigned values of the object
void welcomeScreen::delete_surfaces(){
    SDL_FreeSurface(welcome_screen);
    SDL_FreeSurface(welcome_screen_single);
    SDL_FreeSurface(welcome_screen_pvp);
    SDL_FreeSurface(welcome_screen_pvc);
}
