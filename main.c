#include <stdio.h>
#include <stdlib.h>
#include "SDL2/SDL.h"
#include "SDL_image.h"
#include "createForm.h"


int main(int argc, char *argv[])
{
    SDL_Manager SDL_wrts;
    SDL_Rect SDL_posPng;

     //cree la fenetre
        SDL_wrts.pWindow = SDL_CreateWindow("SDL_Application",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,1024,780,SDL_WINDOW_SHOWN);

        if(SDL_wrts.pWindow!= NULL)
        {
            //si la fenerte est cree alors on va cree le rendu
            SDL_wrts.pRenderer = SDL_CreateRenderer(SDL_wrts.pWindow,-1,SDL_RENDERER_PRESENTVSYNC);
        }

    SDL_posPng.x =0; //positon de l'image
    SDL_posPng.y = 0; //positino de l'image
    SDL_wrts.pSurface = IMG_Load("blackmage.jpg");
    if(!SDL_wrts.pSurface)
    {
        printf("Erreur de chargement de l'image : %s",SDL_GetError());
    }
    SDL_wrts.pTexture = SDL_CreateTextureFromSurface(SDL_wrts.pRenderer,SDL_wrts.pSurface);
    SDL_RenderCopy(SDL_wrts.pRenderer,SDL_wrts.pTexture,NULL,&SDL_posPng);
    SDL_RenderPresent(SDL_wrts.pRenderer);
    SDL_Delay(1000);



    return 0;
}
