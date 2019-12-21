#pragma once
#include <cctype>
#include <string>
#include <cstdlib>
#include <cmath>

class Point {
public:
    float Position [3];
    
    Point RotatePoint (std::string plane, float rotation){
        Point rotatedPoint;
        if(plane == std::string("XY")){
            rotatedPoint.Position[0] =
                cos(rotation)*Position[0] +
                (-sin(rotation)*Position[1])+
                0*Position[2];
            rotatedPoint.Position[1] =
                sin(rotation)*Position[0] +
                cos(rotation)*Position[1] +
                0*Position[2];
            rotatedPoint.Position[2] =
                0*Position[0] +
                0*Position[1] +
                1*Position[2];
        }
        else if(plane == std::string("XZ")) {
            rotatedPoint.Position[0] =
                cos(rotation)*Position[0] +
                0*Position[1] +
                sin(rotation)*Position[2];
            rotatedPoint.Position[1] =
                0*Position[0] +
                1*Position[1] +
                0*Position[2];
            rotatedPoint.Position[2] =
                (-sin(rotation)*Position[0]) +
                0*Position[1] +
                cos(rotation)*Position[2];

        }
        else if(plane == std::string("YZ")){
            rotatedPoint.Position[0] =
                1*Position[0] +
                0*Position[1] +
                0*Position[2];
            rotatedPoint.Position[1] =
                0*Position[0] +
                cos(rotation)*Position[1] +
                (-sin(rotation)*Position[2]);
            rotatedPoint.Position[2] =
                0*Position[0] +
                sin(rotation)*Position[1]+
                cos(rotation)*Position[2];
        }
        return rotatedPoint;
    }
    Point Scale (float X, float Y, float Z) {
        Point scaledPoint;
        scaledPoint.Position[0] = X*Position[0];
        scaledPoint.Position[1] = Y*Position[1];
        scaledPoint.Position[2] = Z*Position[2];
        return scaledPoint;
    }
};
