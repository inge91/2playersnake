#include "deadscreen.h"

deadScreen::deadScreen(SDL_Surface *screen)
{
    mdeadScreen = load_image("../imgs/dead_screen/dead_screen.bmp");
    mdeadScreenNo = load_image("../imgs/dead_screen/dead_screen_no.bmp");
    mdeadScreenYes = load_image("../imgs/dead_screen/dead_screen_yes.bmp");

    // Position in midst of screen
    mx = screen->w/2 - mdeadScreen->w/2;
    my = screen->h/2 - mdeadScreen->h/2;

    //position left
    mleft = true;


}
// Draws the dying message on the screen, and depending on mouse position
// displays one of the possible screens
void deadScreen::draw_screen(SDL_Surface* surface, SDL_Event event){
    // Handle the look of the dead screen
    if(event.type == SDL_KEYDOWN){
        if(event.key.keysym.sym == SDLK_RIGHT && mleft)
        {

            apply_surface(mx, my, mdeadScreenNo, surface, NULL);
            mleft = false;

        }
        else if (event.key.keysym.sym == SDLK_LEFT && !mleft)
        {
            apply_surface(mx, my, mdeadScreenYes, surface, NULL);
            mleft = true;

        }
    }
    else{

        if(mleft)
        {
            apply_surface(mx, my, mdeadScreenYes, surface, NULL);

        }
        else if(!mleft){

            apply_surface(mx, my, mdeadScreenNo, surface, NULL);

        }
    }

    // Refresh the screen!
    SDL_Flip(surface);
}

// Return value of !mleft
bool deadScreen::exit(){
    return(!mleft);
}
