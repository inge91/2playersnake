#include "playerSnake.h"

// This is the class for the snake controlled by the player
// TODO:write a cleanup function that releases all the images

// TODO: make an abstract method which creates an instant of the mouse in the constructor and after that
// Constructor
playerSnake::playerSnake()
{
    // Load initial images of playerSnake and sets position of head and tail
    mHead = load_image("../imgs/playersnake/head.bmp");
    mBody = load_image("../imgs/playersnake/body.bmp");
    mTail = load_image("../imgs/playersnake/tail.bmp");

    SDL_Rect* first;
    SDL_Rect* second;
    SDL_Rect* third;
    SDL_Rect* fourth;

    // all sides
    first->x = 0;
    first->y = 0;
    first->h = mHead->h/2;
    first->w = mHead->w/2;

    second->x = mHead->h/2;
    second->y = 0;
    second->h = mHead->h/2;
    second->w = mHead->w;

    third = second;
    third->x = 0;
    third->y = mHead->w/2;
    third->h = mHead->h;
    third->w = mHead->w/2;


    fourth = second;
    fourth->x = mHead->h/2;
    fourth->y = mHead->w/2;
    fourth->h = mHead->h;
    fourth->w = mHead->w;

    // Set the clips
    mclip_locations.insert(mclip_locations.begin()    , first);
    mclip_locations.insert(mclip_locations.begin() + 1, second);
    mclip_locations.insert(mclip_locations.begin() + 2, third);
    mclip_locations.insert(mclip_locations.begin() + 3, fourth);

    // Give the begin location of playerSnake
    SDL_Rect headLoc;
    SDL_Rect tailLoc;
    headLoc.x = 30;
    headLoc.y = 30;
    headLoc.w = 60;
    headLoc.h = 60;
    tailLoc.x = 0;
    tailLoc.y = 30;
    tailLoc.w = 30;
    tailLoc.h = 30;
    mparts_locations.insert(mparts_locations.begin(), tailLoc);
    // Head gets on the front
    mparts_locations.insert(mparts_locations.begin(), headLoc);

    mdirections.insert(mdirections.begin(), RIGHT);
    mdirections.insert(mdirections.begin(), RIGHT);

    mlast_press = RIGHT;
}

// Drawing the snake on a surface
void playerSnake::draw_snake(SDL_Surface* surface){
    int size = mparts_locations.size();

    SDL_Rect loc;
    int dir;
    //first draw the head
    loc = mparts_locations.at(0);
    dir = mdirections.at(0);

    apply_surface(loc.x, loc.y, mHead, surface, mclip_locations.at(dir));

    // Draw the body
    for(int i = 1; i < size-1; i++){
        loc = mparts_locations.at(i);
        dir = mdirections.at(i);
        apply_surface(loc.x, loc.y, mBody, surface, mclip_locations.at(dir));
    }

    // Draw the tail
    loc = mparts_locations.at(size-1);
    dir = mdirections.at(size-1);
    apply_surface(loc.x, loc.y, mTail, surface, mclip_locations.at(dir));

    // Refresh snake image
    SDL_Flip(surface);

}

// Listens for a move and performs it.
// if a new move in a direction is made, go that way, else
// move the same direction as you did last.
void playerSnake::make_move(SDL_Event event, SDL_Surface* surface){
    SDL_Rect loc;

    //If a key was pressed
    if( event.type == SDL_KEYDOWN )
    {

        //Set the proper consequence
        switch( event.key.keysym.sym )
        {
            case SDLK_UP:
                loc = mparts_locations.at(0);
                loc.y = loc.y - 30;
                mparts_locations.insert(mparts_locations.begin(), loc);
                mdirections.insert(mdirections.begin(), UP);
                mlast_press = UP;
                break;

            case SDLK_DOWN:
                loc = mparts_locations.at(0);
                loc.y = loc.y + 30;
                mparts_locations.insert(mparts_locations.begin(), loc);
                mdirections.insert(mdirections.begin(), DOWN);
                mlast_press = DOWN;
                break;

            case SDLK_LEFT:
                loc = mparts_locations.at(0);
                loc.x = loc.x - 30;
                mparts_locations.insert(mparts_locations.begin(), loc);
                mdirections.insert(mdirections.begin(), LEFT);
                mlast_press = LEFT;
                break;

            case SDLK_RIGHT:

                loc = mparts_locations.at(0);
                loc.x = loc.x + 30;
                mparts_locations.insert(mparts_locations.begin(), loc);
                mdirections.insert(mdirections.begin(), RIGHT);
                mlast_press = RIGHT;
                break;
        }

    }
    // Cases not button was pressed
    else{
         loc = mparts_locations.at(0);
        if(mlast_press == NONE)
        {
            //do nothing
        }
        else if(mlast_press == UP){
            loc.y -= 30;
            mparts_locations.insert(mparts_locations.begin(), loc);
            mdirections.insert(mdirections.begin(), UP);

        }
        else if(mlast_press == DOWN){
            loc.y += 30;
            mparts_locations.insert(mparts_locations.begin(), loc);
            mdirections.insert(mdirections.begin(), DOWN);
        }
        else if(mlast_press == RIGHT){
            loc.x += 30;

            mparts_locations.insert(mparts_locations.begin(), loc);
            mdirections.insert(mdirections.begin(), RIGHT);
        }
        else if(mlast_press == LEFT){
            loc.x -= 30;
            mparts_locations.insert(mparts_locations.begin(), loc);
            mdirections.insert(mdirections.begin(), LEFT);
        }

    }

    // Remove position of tail, but only if the snake moves
    if(mlast_press != NONE){
        mparts_locations.erase(mparts_locations.begin()+ mparts_locations.size()-1);

        mdirections.erase(mdirections.begin()+ mdirections.size()-1);

    }


    // draw the snake
    draw_snake(surface);

}


// Returns the location of all parts
std::vector <SDL_Rect> playerSnake::return_partLocation(){
    return mparts_locations;
}
