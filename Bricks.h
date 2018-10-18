#ifndef  _DB_Bricks_H_
#define  _DB_Bricks_H_

#include "cocos2d.h" 
USING_NS_CC;

class Brick1 : public cocos2d::Sprite{
public:
	Brick1();
	~Brick1();
	virtual bool init();
	CREATE_FUNC(Brick1)
private:

};

class Brick2 : public cocos2d::Sprite {
public:
	Brick2();
	~Brick2();
	virtual bool init();
	CREATE_FUNC(Brick2)
private:

};

class Brick3 : public cocos2d::Sprite {
public:
	Brick3();
	~Brick3();
	virtual bool init();
	CREATE_FUNC(Brick3)
private:

};

class Brick4 : public cocos2d::Sprite {
public:
	Brick4();
	~Brick4();
	virtual bool init();
	CREATE_FUNC(Brick4)
private:

};

class Brick5 : public cocos2d::Sprite {
public:
	Brick5();
	~Brick5();
	virtual bool init();
	CREATE_FUNC(Brick5)
private:

};

class Brick6 : public cocos2d::Sprite {
public:
	Brick6();
	~Brick6();
	virtual bool init();
	CREATE_FUNC(Brick6)
private:

};
#endif // _APP_DELEGATE_H_