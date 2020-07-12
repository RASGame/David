#pragma once
#include<SDL.h>
#include<iostream>
#include <SDL_image.h>
#include  <SDL_mixer.h>






struct InputCon
{
	bool Up = false;
	bool Down = false;
	bool Left = false;
	bool Right = false;
	bool a = false;
	bool x = false;
	bool b = false;
	bool y = false;
};

class Input
{
public:
	InputCon GetInput();
	InputCon GetCon();
	InputCon GetKey();

};

