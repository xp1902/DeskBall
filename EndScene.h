#pragma once
#include <iostream>
#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"   
#include "cocostudio/WidgetCallBackHandlerProtocol.h"   

USING_NS_CC;

class EndScene :public Layer, public cocostudio::WidgetCallBackHandlerProtocol {
public:
	EndScene();
	virtual ~EndScene();
	CREATE_FUNC(EndScene);

	virtual bool init();
	void mainMenuCallback(Ref * sender, cocos2d::ui::Widget::TouchEventType type);
	static Scene* EndScene::createScene();
};

