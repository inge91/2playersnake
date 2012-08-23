#include "sdl_functions.h"

void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip = NULL )
{
    // Holds offsets
    SDL_Rect offset;

    // Get offsets
    offset.x = x;
    offset.y = y;

    // Blit
    SDL_BlitSurface( source, clip, destination, &offset );
}

// Fill the background using input image
void fill_background(SDL_Surface* the_background, SDL_Surface* the_screen,int offset_x = 0,int offset_y = 0)
{
    for (int i = offset_x; i < the_screen->w - offset_x; i += the_background->w)
    {
        for (int j = offset_y; j < the_screen->h - offset_y; j += the_background->h)
        {
            apply_surface(i,j,the_background, the_screen);
        }
    }
}

SDL_Surface *load_image( std::string filename )
{
    //The image that's loaded
    SDL_Surface* loadedImage = NULL;

    //The optimized image that will be used
    SDL_Surface* optimizedImage = NULL;

    //Load the image
    loadedImage = IMG_Load( filename.c_str() );

    //If the image loaded
    if( loadedImage != NULL )
    {
        //Create an optimized image
        optimizedImage = SDL_DisplayFormat( loadedImage );

        //Free the old image
        SDL_FreeSurface( loadedImage );
    }

    if( optimizedImage != NULL){
        //Map the color key
        Uint32 colorkey = SDL_MapRGB( optimizedImage->format, 0, 0xFF, 0xFF );
        //Set all pixels of color R 0, G 0xFF, B 0xFF to be transparent
        SDL_SetColorKey( optimizedImage, SDL_SRCCOLORKEY, colorkey );


        //Return the optimized image
        return optimizedImage;
    }

    return loadedImage;

}


// detects if two squares are collided,
// Returns true if there is a collision, else falls
bool detect_collision(SDL_Rect a,
                         SDL_Rect b)
{
    // all x and y values of all rectangle sides
    int leftSide1 = a.x;
    int rightSide1 = a.x + a.w;
    int upSide1 = a.y;
    int downSide1 = a.y + a.h;

    int leftSide2 = b.x ;
    int rightSide2 =  b.x + b.w;
    int upSide2 = b.y;
    int downSide2 = b.y + b.h;


    // if statemens detect no collisions
    if(downSide1 <= upSide2)
    {
        return false;
    }

    if(rightSide1 <= leftSide2)
    {
        return false;
    }

    if( upSide1 >= downSide2)
    {
        return false;
    }

    if(leftSide1 >= rightSide2)
    {
        return false;
    }

    // collission has been detected
    return true;
}









