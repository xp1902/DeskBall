#pragma once
#include <iostream>
#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"   
#include "cocostudio/WidgetCallBackHandlerProtocol.h"   
#include "StartScene.h"

USING_NS_CC;

class HelpScene :public Layer, public cocostudio::WidgetCallBackHandlerProtocol {
public:
	HelpScene();
	virtual ~HelpScene();
	CREATE_FUNC(HelpScene);

	virtual bool init();
	static Scene* HelpScene::createScene();// RenderTexture *

	void H_ReturnMainMenu(Ref* sender, cocos2d::ui::Widget::TouchEventType type);
};

