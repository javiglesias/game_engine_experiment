#include "Lighting.hpp"
float Lighting::CalculateLight(int actualX, int actualY)
{
	float lightPercentage = 1.0;
	if(actualX >= Position[0] - Intensity)
	{
		if(actualX <= Position[0] + Intensity)
		{
			if(actualY >= Position[1] - Intensity)
			{
				if(actualY <= Position[1] + Intensity)
				{
					lightPercentage = (actualX-Position[0]
					+ actualY-Position[1])/Intensity;
				}
			}
		}
	}
	return lightPercentage;
}
