#pragma once
#include "PlayableCharacter.h"

//Credits for John Horton
//reference : https://www.linkedin.com/learning/c-plus-plus-game-programming-2/the-sfml-drawable-class?u=2147385


class Bob : public PlayableCharacter
{
public:
	// A constructor specific to Bob
	Bob();
	
	// The overriden input handler for Bob
	bool virtual handleInput();

};

