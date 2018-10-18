#include "cocos2d.h"
USING_NS_CC;

class SlideBar: public Node {
protected:
	ProgressTimer* _progress;
	Sprite* _bg;
	float _pectage;
public:
	SlideBar();
	~SlideBar();
	bool virtual init();
	CREATE_FUNC(SlideBar);
	void updateView(int value);
};