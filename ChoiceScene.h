#pragma once
#include <iostream>
#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"   
#include "cocostudio/WidgetCallBackHandlerProtocol.h"   

USING_NS_CC;

class ChoiceScene :public Layer, public cocostudio::WidgetCallBackHandlerProtocol {
public:
	ChoiceScene();
	virtual ~ChoiceScene();
	CREATE_FUNC(ChoiceScene);
	static Scene* ChoiceScene::createScene();

	virtual bool init();
	void gotoLevel1(Ref * sender, cocos2d::ui::Widget::TouchEventType type);
	void returnStartMenu(Ref* sender, cocos2d::ui::Widget::TouchEventType type);
};
