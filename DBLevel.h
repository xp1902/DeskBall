#pragma once
#ifndef _DB_DBLevel_H_
#define  _DB_DBLevel_H_

#include "cocos2d.h" 
#include "Bricks.h"
#include "LevelData.h"
USING_NS_CC;

class DBLevel : public Layer {
private:
	LevelData _levelData;
	int _unFinishedBricks;

public:
	DBLevel();
	virtual ~DBLevel();

	CREATE_FUNC(DBLevel);

	static DBLevel* create(LevelData);

	virtual bool initWithLevelData(LevelData);

protected:
	void initLevel01BrickLayout();
	void initLevel02BrickLayout();
	void initLevel03BrickLayout();
	void initLevel04BrickLayout();
	void initLevel05BrickLayout();
	void initLevel06BrickLayout();
	void initLevel07BrickLayout();
	void initLevel08BrickLayout();
	void initLevel09BrickLayout();
};
#endif