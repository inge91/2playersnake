#include "computersnake.h"

computerSnake::computerSnake(SDL_Surface* surface)
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

// Drawing the snake on a surface
void computerSnake::draw_snake(SDL_Surface* surface){

    int size = mparts_locations.size();
    std::cout<<size;
    std::cout<<"\n";
    SDL_Rect loc;
    int dir;
    //first draw the head
    loc = mparts_locations.at(0);
    dir = mdirections.at(0);

    SDL_Rect* p = &mclip_locations.at(dir);
    apply_surface(loc.x, loc.y, mHead, surface, p);

    // Draw the body
    for(int i = 1; i < size-1; i++){
        loc = mparts_locations.at(i);
        dir = mdirections.at(i);
        p = &mclip_locations.at(dir);
        apply_surface(loc.x, loc.y, mBody, surface, p);
    }

    // Draw the tail
    loc = mparts_locations.at(size-1);
    dir = mdirections.at(size-1);
    p = &mclip_locations.at(dir);
    apply_surface(loc.x, loc.y, mTail, surface, p);

    // Refresh snake image
    SDL_Flip(surface);

}

// Listens for a move and performs it.
// if a new move in a direction is made, go that way, else
// move the same direction as you did last.
void computerSnake::make_move(SDL_Event event, SDL_Surface* surface){
    SDL_Rect loc;


    //Set the proper consequence
    switch( event.key.keysym.sym )
    {
    case SDLK_w:
        loc = mparts_locations.at(0);
        loc.y = loc.y - 30;
        mparts_locations.insert(mparts_locations.begin(), loc);
        mdirections.insert(mdirections.begin(), UP);
        mlast_press = UP;
        break;

    case SDLK_s:
        loc = mparts_locations.at(0);
        loc.y = loc.y + 30;
        mparts_locations.insert(mparts_locations.begin(), loc);
        mdirections.insert(mdirections.begin(), DOWN);
        mlast_press = DOWN;
        break;

    case SDLK_a:
        loc = mparts_locations.at(0);
        loc.x = loc.x - 30;
        mparts_locations.insert(mparts_locations.begin(), loc);
        mdirections.insert(mdirections.begin(), LEFT);
        mlast_press = LEFT;
        break;

    case SDLK_d:

        loc = mparts_locations.at(0);
        loc.x = loc.x + 30;
        mparts_locations.insert(mparts_locations.begin(), loc);
        mdirections.insert(mdirections.begin(), RIGHT);
        mlast_press = RIGHT;
        break;
    default:
        // Cases not button was pressed
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
        break;

    }

    // Remove position of tail, but only if the snake moves
    if(mlast_press != NONE && mIsGrowing == false){
        mparts_locations.erase(mparts_locations.begin()+ mparts_locations.size()-1);

        mdirections.erase(mdirections.begin()+ mdirections.size()-1);

    }
    // draw the snake
    draw_snake(surface);

}

// Detects if the snake has collided with a wall.
bool computerSnake::wall_collision(SDL_Surface* screen){
    SDL_Rect head = mparts_locations.at(0);
    if(head.x < 0 || head.y < 0 || head.x+ head.w > screen->w || head.y + head.h > screen->h){
        return true;
    }
    else{
        return false;
    }
}

// Touched the mouse?
bool computerSnake::touched_mouse(mouse myMouse){
    SDL_Rect mouseLoc =myMouse.get_pos();
    SDL_Rect head = mparts_locations.at(0);

    return detect_collision(mouseLoc, head);
}

// sets mISGrowing depending on if the mouse is catched
bool computerSnake::grow_snake(mouse myMouse){
    if(touched_mouse(myMouse)){
        mIsGrowing = true;
        return true;
    }
    else{
        mIsGrowing = false;
        return false;
    }

}

// While in sleep should still respond to keypresses
void computerSnake::only_respond(SDL_Event event, SDL_Surface *surface){
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
    // Cases not button was pressed DO NOTHING
    else{

    }

    // Remove position of tail, but only if the snake moves
    if(mlast_press != NONE && mIsGrowing == false){
        mparts_locations.erase(mparts_locations.begin()+ mparts_locations.size()-1);

        mdirections.erase(mdirections.begin()+ mdirections.size()-1);
        mIsGrowing = true;
    }
    // draw the snake
    draw_snake(surface);
}

// Checks if the snake has bitten itself
bool computerSnake::touched_self(){
    // Locate position of the head
    SDL_Rect locHead = mparts_locations.at(0);
    SDL_Rect part;

    // Now check if the head has collided with other elements of the body
    for(int i = 1; i < mparts_locations.size(); i ++){
        part = mparts_locations.at(i);
        if(detect_collision(locHead, part) == true){
            return true;
        }
    }
    return false;
}

void computerSnake::respawn(SDL_Surface* surface){
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


// Returns the location of all parts
std::vector <SDL_Rect> computerSnake::return_partLocation(){
    return mparts_locations;
}

