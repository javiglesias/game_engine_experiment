#pragma once
class Player
{
private:
	float Position[2] = {0.0, 0.0};
	float LifePoints = 100.0;
	int ActualRoom = 0;
public:
	void SetStart(float, float);
	void Move(float, int);
	void CheckRoom(float, float);
	void GetHit(float);
	float* CheckPosition();
	~Player();
};
