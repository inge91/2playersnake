#include "background.h"

background::background()
{
    // Load all initial image values
    background_tile      = load_image("../imgs/walls/level1/background.bmp");
    background_up        = load_image("../imgs/walls/level1/background.bmp");
    background_right     = load_image("../imgs/walls/level1/background.bmp");
    background_left      = load_image("../imgs/walls/level1/background.bmp");
    background_down      = load_image("../imgs/walls/level1/background.bmp");
    background_corner_dl = load_image("../imgs/walls/level1/background.bmp");
    background_corner_dr = load_image("../imgs/walls/level1/background.bmp");
    background_corner_ul = load_image("../imgs/walls/level1/background.bmp");
    background_corner_ur = load_image("../imgs/walls/level1/background.bmp");

}

background::apply_background(){


}


