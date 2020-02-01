#pragma once
#include <string>

class Player
{
private:
	float Position[2] = {0.0, 0.0};
	float Size[2] = {10.0, 10.0};
	float LifePoints = 100.0;
	int ActualRoom = 0;
	std::string texture;
public:
	void SetStart(float, float, float, float);
	void Move(float, int);
	void CheckRoom(float, float);
	void GetHit(float);
	float* GetSize();
	float* CheckPosition();
	~Player();
};
