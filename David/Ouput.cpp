#include "Ouput.h"

SDL_Texture* Terrein = NULL;
SDL_Texture* Player = NULL;
SDL_Texture* Backround = NULL;
SDL_Texture* Trees = NULL;
SDL_Texture* DialogBox = NULL;
SDL_Texture* Portaits = NULL;
SDL_Texture* gTextTexture = NULL;
TTF_Font* gFont = NULL;




void screen::render(SDL_Renderer* renderer, pos Playerpos, pos Camerapos, std::string level, InputCon& in, short& a)
{
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderClear(renderer);
   // // Draw Grid
   // for (int i = 0; i < 80; i++)
   // {
   //     for (int k = 0; k < 45; k++)
   //     {
   //         SDL_Rect fillRect = { i * 16,k * 16,16,16 };


   //         SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
   //         SDL_RenderDrawRect(renderer, &fillRect);


   //     }
   // }
   // //****************************************************************************************************************  
   ////Load Textures
    if (Terrein == NULL)
    {
        Terrein = LoadTextures(renderer, "Data/Sprites/Snow.png");
    }
    if (Player == NULL) {
        Player = LoadTextures(renderer, "Data/Sprites/Davidse.png");
    }
    if (Backround == NULL) {
        Backround = LoadTextures(renderer, "Data/Sprites/Mountains_Backround.png");
    }
    if (Trees == NULL) {
        Trees = LoadTextures(renderer, "Data/Sprites/Trees.png");
    }
    if (DialogBox == NULL) {
        DialogBox = LoadTextures(renderer, "Data/Sprites/Dialog_Box.png");
    }
    if (Portaits == NULL)
    {
        Portaits = LoadTextures(renderer, "Data/Sprites/Portraits.png");
    }

    


    


    SDL_Rect backround;
    backround.x = 0;
    backround.y = 0;
    backround.w = 1280;
    backround.h = 640;


   // SDL_RenderCopy(renderer, Backround, NULL, NULL);
    SDL_RenderCopyEx(renderer, Backround, NULL, &backround, 0.0, NULL, SDL_FLIP_NONE);


 //Draw Camera *******************************************************************      
    SDL_Rect Tile;      
    Tile.x = 0;
    Tile.y = 0;
    Tile.h = 32;
    Tile.w = 32;


    SDL_Rect Snow;
    Snow.x = 0;
    Snow.y = 0;
    Snow.h = 16;
    Snow.w = 16;

    SDL_Rect UnderSnow;
    UnderSnow.x = 16;
    UnderSnow.y = 0;
    UnderSnow.h = 16;
    UnderSnow.w = 16;

    SDL_Rect TreeHigh;
    TreeHigh.x = 0;
    TreeHigh.y = 0;
    TreeHigh.h = 64;
    TreeHigh.w = 32;

    SDL_Rect TreeLow;
    TreeLow.x = 32;
    TreeLow.y = 0;
    TreeLow.h = 64;
    TreeLow.w = 32;

    SDL_Rect Tree;
    Tree.x = 0;
    Tree.y = 0;
    Tree.h = 128;
    Tree.w = 64;

    SDL_Rect OwlTree;
    OwlTree.x = 0;
    OwlTree.y = 128;
    OwlTree.h = 64;
    OwlTree.w = 32;


    SDL_Rect player;
    player.x = Playerpos.x;
    player.y = Playerpos.y;
    player.h = 64;
    player.w = 64;

    SDL_Rect Animatated;
    Animatated.x = 0;
    Animatated.y = 0;
    Animatated.h = 32;
    Animatated.w = 32;
   
    if (a > 30) {
        a = -30;
    }
    if (in.Left && a > 0) {
        Animatated.x = 32;
        OwlTree.x = 128;
        
    }
    else if (in.Left && a < 0)
    {
        Animatated.x = 0;
    }

    
    if (in.Right && a > 0) {
        Animatated.x = 32;
        OwlTree.x = 128;

    }
    else if (in.Right && a < 0)
    {
        Animatated.x = 0;
    }

   



    for (int i = 0; i < 40;i++) 
    {
        for (int k = 0; k < 20; k++)
        {
            if (level[(i + Camerapos.x) + (k + Camerapos.y) * 119] == 'B')
            {
                Tree.x = i * 32;
                Tree.y = k * 32;
                SDL_RenderCopyEx(renderer, Trees, &TreeHigh, &Tree, 0.0, NULL, SDL_FLIP_NONE);
            }

            if (level[(i + Camerapos.x) + (k + Camerapos.y) * 119] == 'O')
            {
                Tree.x = i * 32;
                Tree.y = k * 32;
                SDL_RenderCopyEx(renderer, Trees, &OwlTree, &Tree, 0.0, NULL, SDL_FLIP_NONE);
            }

            if (level[(i + Camerapos.x) + (k + Camerapos.y) * 119] == 'b')
            {
                Tree.x = i * 32;
                Tree.y = k * 32;
                SDL_RenderCopyEx(renderer, Trees, &TreeLow, &Tree, 0.0, NULL, SDL_FLIP_NONE);
            }
            
            if (level[(i+Camerapos.x) + (k+Camerapos.y) * 119] =='S')
            {
                Tile.x = i * 32;
                Tile.y = k * 32;
                

                SDL_RenderCopyEx(renderer, Terrein, &Snow, &Tile, 0.0, NULL, SDL_FLIP_NONE);
            }

            if (level[(i + Camerapos.x) + (k + Camerapos.y) * 119] == 's')
            {
                Tile.x = i * 32;
                Tile.y = k * 32;


                SDL_RenderCopyEx(renderer, Terrein, &UnderSnow, &Tile, 0.0, NULL, SDL_FLIP_NONE);
            }
        }
    }

    if (in.Left)
    {
        flip = SDL_FLIP_HORIZONTAL;
        
    }
    if (in.Right)
    {
        flip = SDL_FLIP_NONE;
    }

    SDL_Rect David;
    David.x = 0;
    David.y = 0;
    David.h = 400;
    David.w = 400;

    SDL_Rect Robot;
    Robot.x = 0;
    Robot.y = 0;
    Robot.h = 400;
    Robot.w = 400;

    SDL_Rect portrait;
    portrait.x = 216;
    portrait.y = 116;
    portrait.w = 148;
    portrait.h = 148;

    SDL_Rect dialogBox;
    dialogBox.x = 200;
    dialogBox.y = 100;
    dialogBox.w = 1120;
    dialogBox.h = 240;

    SDL_Rect Text;
    Text.x = 425;
    Text.y = 116;
    Text.w = 800;
    Text.h = 60;


    SDL_RenderCopyEx(renderer, DialogBox, NULL, &dialogBox, 0.0, NULL, SDL_FLIP_NONE);
    SDL_RenderCopyEx(renderer, Portaits, &David, &portrait, 0.0, NULL, SDL_FLIP_NONE);
    
    if (gTextTexture == NULL) {
        TextTexture("My naam is Piet en Koos is my friend ons hou van brood ", renderer);
    }
    
 
        SDL_RenderCopyEx(renderer, gTextTexture, NULL, &Text, 0.0, NULL, SDL_FLIP_NONE);

    SDL_RenderCopyEx(renderer, Player, &Animatated, &player, 0.0, NULL, flip);

    



    SDL_RenderPresent(renderer);

    




   // SDL_RenderCopyEx(renderer, Terrein, &Snow, &Tile, 0.0, NULL, SDL_FLIP_NONE);

    


	




}

SDL_Texture* screen::LoadTextures(SDL_Renderer* renderer, std::string path)
{
    //The final texture
    SDL_Texture* newTexture = NULL;

    //Load image at specified path
    SDL_Surface* loadedSurface = IMG_Load(path.c_str());
    if (loadedSurface == NULL)
    {
        printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
    }
    else
    {
        //Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
        if (newTexture == NULL)
        {
            printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
        }

        //Get rid of old loaded surface
        SDL_FreeSurface(loadedSurface);
    }



    return newTexture;


}

void screen::TextTexture(std::string textureText,SDL_Renderer *renderer)
{
    gFont = TTF_OpenFont("Data/Fonts/GABRIOLA.TTF", 20);
    if (gFont == NULL)
    {
        printf("Failed to load lazy font! SDL_ttf Error: %s\n", TTF_GetError());        
    }
    else
    {
        //Render text
        SDL_Color textColor = { 205, 100, 0 };
        //Render text surface
        SDL_Surface* textSurface = TTF_RenderText_Solid(gFont, textureText.c_str(), textColor);
        if (textSurface == NULL)
        {
            printf("Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError());
        }
        else
        {
            //Create texture from surface pixels
            gTextTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
            if (gTextTexture == NULL)
            {
                printf("Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError());
            }
        }
    }
    
}
