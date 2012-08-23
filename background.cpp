#include "background.h"

background::background()
{
    background_tile      = NULL;
    background_up        = NULL;
    background_right     = NULL;
    background_left      = NULL;
    background_down      = NULL;
    background_corner_dl = NULL;
    background_corner_dr = NULL;
    background_corner_ul = NULL;
    background_corner_ur = NULL;
    // Load all initial image values
    background_tile      = load_image("../imgs/walls/level1/background.bmp");
    background_up        = load_image("../imgs/walls/level1/background_up1.bmp");
    background_right     = load_image("../imgs/walls/level1/background_right1.bmp");
    background_left      = load_image("../imgs/walls/level1/background_left1.bmp");
    background_down      = load_image("../imgs/walls/level1/background_down1.bmp");
    background_corner_dl = load_image("../imgs/walls/level1/background_corner_downleft1.bmp");
    background_corner_dr = load_image("../imgs/walls/level1/background_corner_downright1.bmp");
    background_corner_ul = load_image("../imgs/walls/level1/background_corner_upleft1.bmp");
    background_corner_ur = load_image("../imgs/walls/level1/background_corner_upright1.bmp");

}

// Applying the background to the screen
void background::apply_background(SDL_Surface* surface)
{
    apply_surface(0,0, background_corner_ul, surface, NULL);

    int max_size_x = (surface->w - (2 * background_corner_ul->w)  );
    int max_size_y = (surface->h - (2 * background_corner_ul->h)  );
    int x;
    for(x = background_corner_ul->w ; x < max_size_x; x += background_up->w)
    {
        apply_surface(x,0, background_up, surface, NULL);
    }


    apply_surface(x, 0, background_corner_ur, surface, NULL);

    int y;
    for(y = background_corner_ul->h ; y < max_size_y; y += background_left->h)
    {
        apply_surface(0,y, background_left, surface, NULL);
    }

    apply_surface(0,y, background_corner_dl, surface, NULL);

    apply_surface(x,y, background_corner_dr, surface, NULL);

    for(y = background_corner_ul->h ; y < max_size_y; y += background_right->h)
    {
        apply_surface(x,y, background_right, surface, NULL);
    }

    for(x = background_corner_ul->w ; x < max_size_x; x += background_down->w)
    {
        apply_surface(x,y, background_down, surface, NULL);
    }

    fill_background(background_tile, surface, background_corner_ul->w, background_corner_ul->h);

    SDL_Flip(surface);

}


