#pragma once
#include <math.h>

class Vector
{
public:
	//https://www.mathsisfun.com/algebra/vectors.html
	float x, y;

	Vector();
	Vector(float x, float y);

	Vector minus(Vector other){
		Vector n;
		n.x = x - other.x;
		n.y = y - other.y;

		return n;
	}

	//returns force or speed, but without direction
	float magnitude(){
		return sqrt(pow(x, 2) + pow(y, 2));
	}

	//rotate vector, keep speed, but change direction
	Vector setAngle(float radians){
		Vector v = *this;//copy current vector values across

		v.x = cos(radians)*50;
		v.y = sin(radians)*50;

		return v;
	}

};

