#pragma once
#ifndef  _DB_BBall_H_
#define  _DB_BBall_H_

#include "cocos2d.h" 
USING_NS_CC;

class Goal : public Sprite {
public:
	Goal();
	virtual ~Goal();
	virtual bool init();
	CREATE_FUNC(Goal);
};

class Obstruct: public Sprite {
public:
	Obstruct();
	virtual ~Obstruct();
	virtual bool init();
	CREATE_FUNC(Obstruct);
};

class Icebug: public Sprite {
public:
	Icebug();
	virtual ~Icebug();
	virtual bool init();
	CREATE_FUNC(Icebug);
};

class Gift:public Sprite{
public:
	Gift();
	virtual ~Gift();
	virtual bool init();
	CREATE_FUNC(Gift);
};

class Bomb: public Sprite
{
public:
	Bomb();
	virtual ~Bomb();
	virtual bool init();
	CREATE_FUNC(Bomb);
};

class Candy:public Sprite
{
public:
	Candy();
	~Candy();
	virtual bool init();
	CREATE_FUNC(Candy);
};

#endif