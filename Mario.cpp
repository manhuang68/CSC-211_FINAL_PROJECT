#include "stdafx.h"
#include "Mario.h"
#include "TextureHolder.h"

Mario::Mario()
{
	m_JumpDuration = .5;
	// Associate a texture with the sprite
	m_Sprite = Sprite(TextureHolder::GetTexture(
		"graphics/mario.png"));

	
}
// A virtual function
bool Mario::handleInput()
{
	m_JustJumped = false;

	if (Keyboard::isKeyPressed(Keyboard::I))
	{

		// Start a jump if not already jumping
		// but only if standing on a block (not falling)
		if (!m_IsJumping && !m_IsFalling)
		{
			m_IsJumping = true;
			m_TimeThisJump = 0;
			m_JustJumped = true;
		}
	}
	else
	{
		m_IsJumping = false;
		m_IsFalling = true;

	}
	if (Keyboard::isKeyPressed(Keyboard::J))
	{
		m_LeftPressed = true;
	}
	else
	{
		m_LeftPressed = false;
	}


	if (Keyboard::isKeyPressed(Keyboard::L))
	{
		m_RightPressed = true;
	}
	else
	{
		m_RightPressed = false;
	}

	return m_JustJumped;
}