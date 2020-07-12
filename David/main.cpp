#include<SDL.h>
#include<iostream>
#include <SDL_image.h>
#include  <SDL_mixer.h>
#include <string>
#include "Input.h"
#include "Ouput.h"

const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;


int main(int argc, char* args[])
{
	SDL_Window* window;
	SDL_Renderer* renderer;
	bool GameOver = false;
	


	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_JOYSTICK) < 0)
	{
		std::cout << "Could not intialize SDL! %s\n" << SDL_GetError();
	}
	else
	{
		window = SDL_CreateWindow("David", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_FULLSCREEN);
		if (window == NULL)
		{
			std::cout << "Could not create window! %s\n" << SDL_GetError();
		}
		else
		{
			if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
			{
				std::cout << "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError();

			}
			Mix_Music* gMusic = NULL;
			if (TTF_Init() == -1)
			{
				printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
				
			}
			
			renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
			if (renderer == NULL)
			{
				std::cout << "Could not create renderer! %s\n" << SDL_GetError();
			}
			else
			{
				//Load Music
				gMusic = Mix_LoadMUS("Data/Songs/Game Jam Trippy Song.wav");
				if (gMusic == NULL)
				{
					std::cout << "Failed to load beat music! SDL_mixer Error: %s\n", Mix_GetError();
				}
				///////////////
				InputCon input;
				std::string Level;


				Level += ".......................................................................................................................";
				Level += ".......................................................................................................................";
				Level += ".......................................................................................................................";
				Level += ".......................................................................................................................";
				Level += ".......................................................................................................................";
				Level += ".......................................................................................................................";
				Level += ".......................................................................................................................";
				Level += ".......................................................................................................................";
				Level += ".......................................................................................................................";
				Level += ".......................................................................................................................";
				Level += ".......................................................................................................................";
				Level += ".......................................................................................................................";
				Level += ".......................................................................................................................";
				Level += ".......................................................................................................................";
				Level += ".......................................................................................................................";
				Level += ".......................................................................................................................";
				Level += ".......................................................................................................................";
				Level += ".......................................................................................................................";
				Level += ".......................................................................................................................";
				Level += ".......................................................................................................................";
				Level += ".......................................................................................................................";
				Level += ".......................................................................................................................";
				Level += ".......................................................................................................................";
				Level += ".......................................................................................................................";
				Level += ".......................................................................................................................";
				Level += ".......................................................................................................................";
				Level += ".......................................................................................................................";
				Level += ".......................................................................................................................";
				Level += ".......................................................................................................................";
				Level += ".......................................................................................................................";
				Level += ".......................................................................................................................";
				Level += ".......................................................................................................................";
				Level += ".......................................................................................................................";
				Level += ".......................................................................................................................";
				Level += "......O....................b..............................................b...b...B...B....B...........................";
				Level += ".......................................................................................................................";
				Level += ".......................................................................................................................";
				Level += ".......................................................................................................................";
				Level += "SSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS";
				Level += "sssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss";
				Level += "SSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS";
				






				pos PlayerPos;
				pos CameraPos;
				Game game;
				game.OnCreate();
				PlayerPos.y = 0;
				PlayerPos.x = 0;
				short a = 0;

				while (true)
				{
					
					a++;
					std::cout << a;
					Mix_Volume(0, 5);

					if (Mix_PlayingMusic() == 0)
					{
						//Play the music
						Mix_PlayMusic(gMusic, -1);

					}
					

					// Input **********************************************************************
					Input in;
					input =in.GetInput();
					// Processing *****************************************************************
					
					
					game.OnUpdate(PlayerPos, CameraPos,input,  Level);
					

				
					// Output ********************************************************************
					screen Screen;
					Screen.render(renderer, PlayerPos, CameraPos, Level,input,a);

				
				}
			}
		}
		//close stuff
		//Destroy window
		SDL_DestroyWindow(window);

		//Quit SDL subsystems
		SDL_Quit();
	}




	return 0;

}