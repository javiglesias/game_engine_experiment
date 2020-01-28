#pragma once
#include <vector>

class Lighting
{
public:
	float CalculateLight(int, int);
	int Position[2] = { 0,0 };//x,y
private:
	int Color[3] = {255,255,255};//rgb
	float Intensity = 1050.0;//lighting radius
};
