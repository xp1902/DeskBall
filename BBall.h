#pragma once
#ifndef  _DB_BBall_H_
#define  _DB_BBall_H_

#include "cocos2d.h" 
USING_NS_CC;

class Ball : public Sprite {
public:
	Ball();
	virtual ~Ball();
	virtual bool init();
	CREATE_FUNC(Ball);
};

#endif