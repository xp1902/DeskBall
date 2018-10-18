#ifndef  _DB_BACKGROUND_
#define  _DB_BACKGROUND_

#include "cocos2d.h" 
using namespace cocos2d;

class BackGround : public cocos2d::Node {
private:
	Sprite *bg;
public:
	static Scene * createScene();
	BackGround();
	virtual ~BackGround();

	CREATE_FUNC(BackGround);
	virtual bool init();
	void addHud();
	void addEdges();
	void addPaddle2();
	//virtual void update(float f);
};
#endif // _APP_DELEGATE_H_