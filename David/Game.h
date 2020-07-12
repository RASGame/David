#pragma once
#include "Input.h"



struct pos {
	float x=0;
	float y=0;
};


class Game {
public:
	void  OnUpdate(pos &PlayerPos, pos& CameraPos, InputCon & in, std::string Level);
	void OnCreate();
	
private:
	pos PlayerNewPos;
	pos Vel;
	bool Jumped = false;
	int Jumtime = 30;
};