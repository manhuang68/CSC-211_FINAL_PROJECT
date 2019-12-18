#include "stdafx.h"
#include "Engine.h"
#include <iostream>
using namespace std;

//Credits for John Horton
//reference : https://www.linkedin.com/learning/c-plus-plus-game-programming-2/the-sfml-drawable-class?u=2147385

void check( Engine& engine,int t);
int main()
{
	int p;
  Engine engine;
	
  cout << "Enter additional time left (second) for the game between 0-30: ";
  cin >> p;
 
	try
	{ 
		check( engine,p);
	}
	catch (string error)
	{
		cout << error;
		exit(0);
	}
	// Declare an instance of Engine

	// Start the engine

	// Quit in the usual way when the engine is stopped
	return 0;
}
void check( Engine& engine, int t)
{

	if (t < 0)
	{
		throw string("Error: The number you entered is less than 0\n");
	}
	else if (t > 30)
	{
		throw string("Error: The number is greater than 30\n");
	}
	else
	{
		engine.additional(t);
		engine.run();
	}
	
}