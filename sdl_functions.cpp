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
void fill_background(SDL_Surface* the_background, SDL_Surface* the_screen)
{
    for (int i = 0; i < the_screen->w; i += the_background->w)
    {
        for (int j = 0; j < the_screen->h; j += the_background->h)
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


}
