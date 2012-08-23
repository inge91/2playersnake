#include "mouse.h"
#include <cstdlib>
#include <ctime>

// Mouse class makes an instant of a mouse that has to be eaten by the snake
// TODO: let mouse spawn somewhere else than on the snake
mouse::mouse(SDL_Surface* screen)
{
    mmouse = load_image("../imgs/mouse.bmp");

    if( mmouse == NULL)
    {
        std::cout<<"o hai";
    }
    // choose a random position to spawn the mouse on the screen
    srand(time(0));
    mx = (rand() % (screen->w - 30));
    my = (rand() % (screen->h - 30));
    mx = mx - (mx % 60) + 15;
    my = my - (my % 60) + 15;

}

// get the position of the mouse
SDL_Rect mouse::get_pos(){
    SDL_Rect loc;
    loc.x = mx;
    loc.y = my;
    loc.w = mmouse->w;
    loc.h = mmouse->h;
    return loc;
}

void mouse::respawn(SDL_Surface* surface){
    srand(time(0));
    mx = (rand() % surface->w - 30);
    my = (rand() % surface->h - 30);
    mx = mx - (mx % 60)+15;
    my = my - (my % 60)+15;
}

// Draw the mouse on a surface
void mouse::draw_image(SDL_Surface* surface){
    // paint hte image
    apply_surface(mx, my, mmouse, surface,  NULL);
    SDL_Flip(surface);
}
