#pragma once
#include "Entity.h"

using namespace std;

class Score :
	public Entity
{
private:
	long score = 0;
public:
	Score();
	~Score();

	void startScoreCount(score);
	string getScore(score);

	virtual void draw();
};

