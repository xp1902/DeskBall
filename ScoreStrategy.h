#pragma once
#include "cocos2d.h"
#include "ScoreData.h"
USING_NS_CC;

class ScoreStragy
{
public:
	ScoreStragy();
	~ScoreStragy();
	void execute(ScoreData*, int);
private:
	int _contiuous = 0;
};
