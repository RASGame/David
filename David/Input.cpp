#include "Input.h"

const int JOYSTICK_DEAD_ZONE = 8000;
SDL_Joystick* gGameController = NULL;
SDL_Event e;
InputCon out;

InputCon Input::GetInput()
{
	InputCon out;
	if (SDL_NumJoysticks() < 1)
	{
		out = GetKey();
		printf("Warning: No joysticks connected!\n");
		
	}
	else
	{
		//Load joystick
		gGameController = SDL_JoystickOpen(0);
		if (gGameController == NULL)
		{
			printf("Warning: Unable to open game controller! SDL Error: %s\n", SDL_GetError());
			
		}
		out =GetCon();


	}
	return out;
}

InputCon Input::GetCon()
{
	
	
	while (SDL_PollEvent(&e) != 0)
	{
		
		//User requests quit
		if (e.type == SDL_QUIT)
		{
			
		}
		else if (e.type == SDL_JOYAXISMOTION)
		{
			
			// Leftstick x-axis
			if (e.jaxis.axis == 0)
			{
				if (e.jaxis.value < -JOYSTICK_DEAD_ZONE)
				{
					out.Left = true;
				}
				else
				{
					out.Left = false;
				}
				if (e.jaxis.value > JOYSTICK_DEAD_ZONE)
				{
					out.Right = true;
				}
				else
				{
					out.Right=false;
				}
			}
			if (e.jaxis.axis == 1)
			{
				if (e.jaxis.value < -JOYSTICK_DEAD_ZONE)
				{
					out.Up = true;
				}
				else
				{
					out.Up = false;
				}
				if (e.jaxis.value > JOYSTICK_DEAD_ZONE)
				{
					out.Down = true;
				}
				else
				{
					out.Down = false;
				}
			}

		}
		else if (e.type == SDL_JOYBUTTONDOWN)
		{
			if (e.jbutton.button == 0)
			{			
					out.a = true;	
			}
			else
			{
				out.a = false;
			}
			if (e.jbutton.button == 1)
			{
				out.b = true;
			}
			else
			{
				out.b = false;
			}
			if (e.jbutton.button == 2)
			{
				out.x = true;
			}
			else
			{
				out.x = false;
			}
			if (e.jbutton.button == 3)
			{
				out.y = true;

			}
			else
			{
				out.x = false;
			}
		}
		else if (e.type == SDL_JOYBUTTONUP)
		{
			if (e.jbutton.button == 0)
			{
				out.a = false;
			}

		}

	}
	return out;
}

InputCon Input::GetKey()
{
	out.a = false;
	while (SDL_PollEvent(&e) != 0)
	{
		//User requests quit
		if (e.type == SDL_QUIT)
		{

		}
	}
	
	const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);
	if (currentKeyStates[SDL_SCANCODE_W])
	{
		out.Up = true;
	}
	else
	{
		out.Up = false;
	}
	if (currentKeyStates[SDL_SCANCODE_S])
	{
		out.Down = true;
	}
	else
	{
		out.Down = false;
	}
	if (currentKeyStates[SDL_SCANCODE_A])
	{
		out.Left = true;
	}
	else
	{
		out.Left = false;
	}
	if (currentKeyStates[SDL_SCANCODE_D])
	{
		out.Right = true;
	}
	else
	{
		out.Right = false;
	}
	if (currentKeyStates[SDL_SCANCODE_U] || currentKeyStates[SDL_SCANCODE_SPACE])
	{
		out.a = true;
	}
	else
	{
		out.a = false;
	}
	if (currentKeyStates[SDL_SCANCODE_H])
	{
		out.x = true;
	}
	else
	{
		out.x = false;
	}
	if (currentKeyStates[SDL_SCANCODE_J])
	{
		out.b = true;
	}
	else
	{
		out.b = false;
	}
	if (currentKeyStates[SDL_SCANCODE_K])
	{
		out.y = true;
	}
	else
	{
		out.y = false;
	}



	return out;
}
