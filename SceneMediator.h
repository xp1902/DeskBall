#pragma once
#include "stdio.h"
#include "cocos2d.h"
USING_NS_CC;

class SceneMediator
{
public:
	static SceneMediator* getInstance();
	virtual void gotoStartScene();
	virtual void gotoGameScene();
	virtual void gotoChoiceScene();
protected:
	static SceneMediator* _instance;
};