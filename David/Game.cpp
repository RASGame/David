#include "Game.h"

void Game::OnUpdate(pos& PlayerPos, pos& CameraPos, InputCon & in, std::string Level)
{
	CameraPos.x = PlayerPos.x/32;
	CameraPos.y = 20;
	Vel.x = 0;
	Vel.y = 0;
	


	float speed = 15;
	
	//PlayerNewPos
	if (in.Left) {
		Vel.x = -speed;
	}
	if (in.Right) {
		Vel.x = speed;
	}

	
	Vel.y = 18;

	

	if (in.a && Jumtime> 0) {
		Vel.y =  -speed*2*(Jumtime/15);
		Jumtime--;
	}




	std::cout << Vel.y;
	

	PlayerNewPos.x = PlayerNewPos.x+Vel.x * 0.17f;
	PlayerNewPos.y = PlayerNewPos.y+Vel.y * 0.17f;
	//std::cout << "	" << (PlayerNewPos.y)/32;
//	std::cout << "	" << (PlayerNewPos.x) / 32;
//	std::cout << "	" << (PlayerNewPos.y) / 32;

	int x = (int)((PlayerNewPos.x) / 32 );
	int y = (int)((PlayerNewPos.y) / 32 );

//	std::cout << "	"<<x;




	if (Vel.x >= 0)
	{

		if (Level[(x + CameraPos.x) + 2 + (y + CameraPos.y) * 119] == 'S' || Level[(x + CameraPos.x) + 2 + ((y + CameraPos.y)+1) * 119] == 'S')
		{
			PlayerNewPos.x = x * 32;
		}
		else
		{
			PlayerPos.x = PlayerNewPos.x;
		}	

	}
	else if(Vel.x <0)
	{
		if (Level[(x + CameraPos.x)  + (y + CameraPos.y) * 119] == 'S' || Level[(x + CameraPos.x)  + ((y + CameraPos.y) + 1) * 119] == 'S')
		{
			PlayerNewPos.x = (x+1) * 32;
		}
		else
		{
			PlayerPos.x = PlayerNewPos.x;
		}
	}

	if (Vel.y > 0)
	{
		if (Level[(x + CameraPos.x) +((y + CameraPos.y)+2) * 119] == 'S' || Level[(x + CameraPos.x) + ((y + CameraPos.y) + 2) * 119] == 'S'|| Level[(x + CameraPos.x)+2 + ((y + CameraPos.y) + 2) * 119] == 'S' || Level[(x + CameraPos.x)+2 + ((y + CameraPos.y) + 2) * 119] == 'S')
		{
			PlayerNewPos.y = y * 32;
			Jumtime = 30;
		}
		else
		{
			PlayerPos.y = PlayerNewPos.y;
		}
	}
	else if (Vel.y < 0)
	{
		PlayerPos.y = PlayerNewPos.y;
	}

	




}

void Game::OnCreate()
{
}
