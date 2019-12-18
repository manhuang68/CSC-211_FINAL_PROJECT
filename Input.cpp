#include "stdafx.h"
#include "Engine.h"
#include <fstream>
#include <iostream>
using namespace std;
using namespace sf;

void Engine::input()
{
	Event event;
	while (m_Window.pollEvent(event))
	{
		if (event.type == Event::KeyPressed)
		{
			

			// Handle the player quitting
			if (Keyboard::isKeyPressed(Keyboard::Escape))
			{
				m_Window.close();
				cout << "Mario jumped " << getMarioij() << " times" << endl;
				cout << "John jumped " << getThomasjump() << " times" << endl;
				cout << "Baby jumped " << getBobjump() << " times" << endl;
			}

			// Handle the player starting the game
			if (Keyboard::isKeyPressed(Keyboard::Return))
			{
				m_Playing = true;
			}

			// Switch between Thomas and Bob
			if (Keyboard::isKeyPressed(Keyboard::Q))
			{
				m_Character1 = !m_Character1;
			}

			// Switch between full and split-screen
			if (Keyboard::isKeyPressed(Keyboard::E))
			{
				m_SplitScreen = !m_SplitScreen;
			}

			
		}
		try
			{
				//check(m_CurrentLevel, NUM_LEVELS);
				if (m_LM.getCurrentLevel() > 4)
				{
					cout << "Mario jumped "<<getMarioij()<<" times"<<endl;
					cout << "John jumped " << getThomasjump() << " times" << endl;
					cout << "Baby jumped " << getBobjump() << " times" << endl;
					ofstream outfile;
					outfile.open("test.dat", ios::out | ios::app);
					if (!outfile) {
						//cerr << "error opening output file :-(" << endl;
						throw "error opening output file";
					}
						outfile << "Mario jumped " << getMarioij() << " times" << endl;
						outfile << "John jumped " << getThomasjump() << " times" << endl;
						outfile << "Baby jumped " << getBobjump() << " times" << endl;
				
				   outfile << endl;
				   outfile.close();

					throw int(4);

					//m_CurrentLevel = 1;
					//m_TimeModifier -= .1f;
				}
			}
			catch (int lo)
			{
				cout << "There are only " << lo << " levels and you finished already. The Game Quit succesfully"<<endl;
				exit(0);
			}
	}	

	// Handle input specific to Thomas
	// Handle input specific to Thomas
	if (m_Thomas.handleInput())
	{
		// Play a jump sound
		m_SM.playJump();
		Thomasjump++;
	}

	// Handle input specific to Bob
	if (m_Bob.handleInput())
	{
		// Play a jump sound
		m_SM.playJump();
		Bobjump++;
	}
	//For mario
	if (m_Mario.handleInput())
	{
		m_SM.playJump();
		
		Marioij++;
		
	}
}
int Engine::getMarioij()
{
	return Marioij;
}
int Engine::getBobjump()
{
	return Bobjump;
}
int Engine::getThomasjump()
{
	return Thomasjump;
}