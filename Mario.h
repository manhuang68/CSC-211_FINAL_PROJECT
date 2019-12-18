#pragma once
#include "PlayableCharacter.h"

class Mario : public PlayableCharacter
{

public:
	// A constructor specific to Mario
	Mario();
	// The overriden input handler for Mario
	bool virtual handleInput();

};
