#pragma once
//#include "Number.h"
#include <SFML/Graphics.hpp>

//#include "Engine.h"
using namespace sf;
using namespace std;


class LevelManager
{
private:
	Vector2i m_LevelSize;
	Vector2f m_StartPosition;
	float m_TimeModifier = 1;
	float m_BaseTimeLimit = 0;
	int m_CurrentLevel;
	const int NUM_LEVELS = 4;
	//float case1, case8; int case2 = 10, case3;
    int case7;
	//float loco;

public:
	
	const int TILE_SIZE = 50;
	const int VERTS_IN_QUAD = 4;
	
	float getTimeLimit();

	Vector2f getStartPosition();

	int** nextLevel(VertexArray& rVaLevel);

	Vector2i getLevelSize();

	int getCurrentLevel();
	
	//void getCase1d();


	void ja(int t);
	int getja();

};
