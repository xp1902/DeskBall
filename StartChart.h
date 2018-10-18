#pragma once
#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"   
#include "cocostudio/WidgetCallBackHandlerProtocol.h"   
USING_NS_CC;

class StartChart: public Layer, public cocostudio::WidgetCallBackHandlerProtocol
{
public:
	StartChart();
	virtual ~StartChart();
	virtual bool init();
	static Scene* createScene();
	CREATE_FUNC(StartChart);
	void gotoMainScene(Ref* sender, cocos2d::ui::Widget::TouchEventType type);
protected:
	Node* createCharts(int, int);
};