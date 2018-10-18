#pragma once
#include <iostream>
#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"   
#include "cocostudio/WidgetCallBackHandlerProtocol.h"   
#include "ChoiceScene.h"

USING_NS_CC;

class StartScene :public Layer, public cocostudio::WidgetCallBackHandlerProtocol {
public:
	StartScene();
	virtual ~StartScene();
	CREATE_FUNC(StartScene);

	virtual bool init();
	void gotoChartScene(Ref * sender, cocos2d::ui::Widget::TouchEventType type);
	static Scene* StartScene::createScene();// RenderTexture *


	void gotoChoiceScene(Ref* sender, cocos2d::ui::Widget::TouchEventType type);
	void openOptionCallback(Ref * sender, cocos2d::ui::Widget::TouchEventType type);
	void quitGameCallback(Ref * sender, cocos2d::ui::Widget::TouchEventType type);
};
