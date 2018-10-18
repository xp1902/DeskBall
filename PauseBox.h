#pragma once
#include "stdio.h"
#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"   
#include "cocostudio/WidgetCallBackHandlerProtocol.h"   

USING_NS_CC;

class PauseBox :public Layer, public cocostudio::WidgetCallBackHandlerProtocol {
public:
	PauseBox();
	virtual ~PauseBox();
	CREATE_FUNC(PauseBox);

	/*void onExit();*/

	virtual bool init();
	static Scene* PauseBox::createScene(RenderTexture *);

	void resumeCallback(Ref* sender, cocos2d::ui::Widget::TouchEventType type);
	void optionCallback(Ref* sender, cocos2d::ui::Widget::TouchEventType type);
	void restartCallback(Ref* sender, cocos2d::ui::Widget::TouchEventType type);
	void menuCallback(Ref* sender, cocos2d::ui::Widget::TouchEventType type);
};