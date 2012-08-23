#include "aisnake.h"

aiSnake::aiSnake(SDL_Surface* surface)
{
    // Load initial images of computerSnake and sets position of head and tail
        mHead = load_image("../imgs/computersnake/head.bmp");
        mBody = load_image("../imgs/computersnake/body.bmp");
        mTail = load_image("../imgs/computersnake/tail.bmp");

        SDL_Rect first;
        SDL_Rect second;
        SDL_Rect third;
        SDL_Rect fourth;

        // all sides
        first.x = 0;
        first.y = 0;
        first.h = mHead->h/2;
        first.w = mHead->w/2;

        second.x = mHead->h/2;
        second.y = 0;
        second.h = mHead->h/2;
        second.w = mHead->w;

        third = second;
        third.x = 0;
        third.y = mHead->w/2;
        third.h = mHead->h/2;
        third.w = mHead->w/2;


        fourth = second;
        fourth.x = mHead->h/2;
        fourth.y = mHead->w/2;
        fourth.h = mHead->h/2;
        fourth.w = mHead->w/2;

        // Set the clips
        mclip_locations.insert(mclip_locations.begin()    , first);
        mclip_locations.insert(mclip_locations.begin() + 1, second);
        mclip_locations.insert(mclip_locations.begin() + 2, third);
        mclip_locations.insert(mclip_locations.begin() + 3, fourth);

        respawn(surface);
}

void aiSnake::respawn(SDL_Surface* surface){
    mparts_locations.clear();
    mdirections.clear();
    // Give the begin location of computerSnake
    SDL_Rect headLoc;
    SDL_Rect tailLoc;
    headLoc.x = surface->w - 100;
    headLoc.y = surface->h - 75;
    headLoc.w = mHead->w/2;
    headLoc.h = mHead->h/2;
    tailLoc.x = surface->w - 75;
    tailLoc.y = surface->h - 75;
    tailLoc.w = mHead->w/2;
    tailLoc.h = mHead->h/2;
    mparts_locations.insert(mparts_locations.begin(), tailLoc);
    // Head gets on the front
    mparts_locations.insert(mparts_locations.begin(), headLoc);

    mdirections.insert(mdirections.begin(), LEFT);
    mdirections.insert(mdirections.begin(), LEFT);

    mlast_press = NONE;
}

//void aiSnake::go_to_mouse(){

//}
