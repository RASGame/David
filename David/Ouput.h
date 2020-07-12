#pragma once
#include<SDL.h>
#include<iostream>
#include <SDL_image.h>
#include  <SDL_mixer.h>
#include "Game.h"
#include <String>
#include <SDL_ttf.h>



class screen
{
public:
	void render(SDL_Renderer* renderer, pos Playerpos, pos Camerapos,std::string level, InputCon& in,short& a);
private:
	SDL_Texture* LoadTextures(SDL_Renderer* renderer, std::string path);
	SDL_RendererFlip flip =SDL_FLIP_NONE;
	void TextTexture(std::string textureText, SDL_Renderer* renderer);
};