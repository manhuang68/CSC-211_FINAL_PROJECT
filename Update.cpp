#include "stdafx.h"
#include "Engine.h"
#include <SFML/Graphics.hpp>
#include <sstream>
#include <iostream>
#include <fstream>
using namespace std;

using namespace sf;

void Engine::update(float dtAsSeconds)
{
	if (m_NewLevelRequired)
	{
		// These calls to spawn will be moved to a new
		// LoadLevel function soon
		// Spawn Thomas and Bob
		//m_Thomas.spawn(Vector2f(0,0), GRAVITY);
		//m_Bob.spawn(Vector2f(100, 0), GRAVITY);

		// Make sure spawn is called only once
		//m_TimeRemaining = 10;
		//m_NewLevelRequired = false;

		// Load a level
		loadLevel();
		
	}

	if (m_Playing)
	{
		// Update Thomas
		m_Thomas.update(dtAsSeconds);

		// Update Bob
		m_Bob.update(dtAsSeconds);

		m_Mario.update(dtAsSeconds);

		// Detect collisions and see if characters have reached the goal tile
		// The second part of the if condition is only executed
		// when thomas is touching the home tile
		if (detectCollisions(m_Thomas) && detectCollisions(m_Bob) && detectCollisions(m_Mario))
		{
			// New level required
			m_NewLevelRequired = true;

			// Play the reach goal sound
			m_SM.playReachGoal();
			cout << "The Characters passed the level " << m_LM.getCurrentLevel()<<endl;
			ofstream outfile;
			outfile.open("test.dat", ios::out | ios::app);
			if (!outfile) {
				//cerr << "error opening output file :-(" << endl;
				throw "error opening output file";
			}
			outfile << "The Characters passed the level " << m_LM.getCurrentLevel() << endl;
	
			outfile << endl;
			outfile.close();
		}
		else
		{
			// Run bobs collision detection
			detectCollisions(m_Bob);
			detectCollisions(m_Mario);
		}

		// Let bob and thomas jump on each others heads
		if (m_Bob.getFeet().intersects(m_Thomas.getHead()))
		{
			m_Bob.stopFalling(m_Thomas.getHead().top);
		}
		else if (m_Thomas.getFeet().intersects(m_Bob.getHead()))
		{
			m_Thomas.stopFalling(m_Bob.getHead().top);
		}
		else if (m_Bob.getFeet().intersects(m_Mario.getHead()))
		{
			m_Bob.stopFalling(m_Mario.getHead().top);
		}
		else if (m_Mario.getFeet().intersects(m_Bob.getHead()))
		{
			m_Mario.stopFalling(m_Bob.getHead().top);
		}
		else if (m_Mario.getFeet().intersects(m_Thomas.getHead()))
		{
			m_Mario.stopFalling(m_Thomas.getHead().top);
		}
		else if (m_Thomas.getFeet().intersects(m_Mario.getHead()))
		{
			m_Thomas.stopFalling(m_Mario.getHead().top);
		}
		// Count down the time the player has left
		m_TimeRemaining -= dtAsSeconds;

		// Have Thoma, Mario and Bob run out of time?
		if (m_TimeRemaining <= 0)
		{
			m_NewLevelRequired = true;
			cout << "The Characters did not pass the level " << m_LM.getCurrentLevel() << endl;
			ofstream outfile;
			outfile.open("test.dat", ios::out | ios::app);
			if (!outfile) {
				//cerr << "error opening output file :-(" << endl;
				throw "error opening output file";
			}
			outfile << "The Characters did not pass the level " << m_LM.getCurrentLevel() << endl;

			outfile << endl;
			outfile.close();

		}

	}// End if playing
		
	// Set the appropriate view around the appropriate character
	if (m_SplitScreen)
	{
		m_LeftView.setCenter(m_Thomas.getCenter());
		m_RightView.setCenter(m_Bob.getCenter());
	}
	else
	{
		// Centre full screen around appropriate character
		if (m_Character1)
		{
			m_MainView.setCenter(m_Thomas.getCenter());
			
		}
		else
		{
			m_MainView.setCenter(m_Bob.getCenter());
			m_MainView.setCenter(m_Mario.getCenter());
		}
	}

	m_FramesSinceLastHUDUpdate++;

	// Update the HUD every m_TargetFramesPerHUDUpdate frames
	if (m_FramesSinceLastHUDUpdate > m_TargetFramesPerHUDUpdate)
	{
		// Update game HUD text
		stringstream ssTime;
		stringstream ssLevel;

		// Update the time text
		ssTime << (int)m_TimeRemaining;
		m_Hud.setTime(ssTime.str());

		// Update the level text
		ssLevel << "Level:" << m_LM.getCurrentLevel();
		m_Hud.setLevel(ssLevel.str());

		m_FramesSinceLastHUDUpdate = 0;
	}
}