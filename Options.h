#include "cocos2d.h"
#include "ui/UIWidget.h"
#include "cocostudio/CocoStudio.h"   
#include "cocostudio/WidgetCallBackHandlerProtocol.h"   
#include <stdio.h>
#include "ui/cocosGUI.h"
USING_NS_CC;
using namespace cocos2d::ui;

class Options :public Layer, public cocostudio::WidgetCallBackHandlerProtocol {
public:
	Options();
	virtual ~Options();
	CREATE_FUNC(Options);

	virtual bool init();
	static Scene* Options::createScene(RenderTexture *);

	void musicCallback(Ref* ref, CheckBoxEventType type);
	void effectCallback(Ref* ref, CheckBoxEventType type);
	void slider1Callback(Ref* ref, SliderEventType type);
	void returnCallback(Ref* sender, ui::Widget::TouchEventType type);
};