#include "Player.hpp"

void Player::SetStart(float startX, float startY, float sizeX, float sizeY)
{
	Position[0] = startX;
	Position[1] = startY;
	Size[0] = sizeX;
	Size[1] = sizeY;
}
//
void Player::Move(float distance, int direction)
{
	if (direction == 0)//DOWN
	{
		Position[1] += distance;
	}
	if (direction == 1)//UP
	{
		Position[1] -= distance;
	}
	if (direction == 2)//RIGHT
	{
		Position[0] += distance;
	}
	if (direction == 3)//LEFT
	{
		Position[0] -= distance;
	}
}

void Player::CheckRoom(float actualX, float actualY)
{
	ActualRoom = 0;
}

void Player::GetHit(float hitForce)
{
	LifePoints -= hitForce;
}

float* Player::CheckPosition()
{
	return Position;
}
float* Player::GetSize()
{
	return Size;
}

Player::~Player() { }
