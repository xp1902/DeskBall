#include "cocos2d.h"
#include "ui\CocosGUI.h"
#include "UserData.h"
USING_NS_CC;

class ChartsScene: public Layer
{
public:
	ChartsScene();
	~ChartsScene();
	CREATE_FUNC(ChartsScene);
	void gameStart(std::string img);
	virtual bool init();
	void backBtnCallback(Ref* sender, cocos2d::ui::Widget::TouchEventType type);
	static Scene* createScene(RenderTexture *);
	//static void getNowScore(int score);
	//static void getSpendTime(int time);
protected:
	ui::TextAtlas* score;
	ui::TextAtlas* time;
};