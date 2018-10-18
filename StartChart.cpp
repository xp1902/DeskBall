#include "StartChart.h"
#include "StartScene.h"
#include "ui/CocosGUI.h"
#include "cocostudio/CocoStudio.h"
#include "UserData.h"
#include "SimpleAudioEngine.h"

StartChart::StartChart()
{
}
StartChart::~StartChart()
{
}

Scene* StartChart::createScene() {
	Scene* scene = Scene::create();
	StartChart* layer = StartChart::create();
	scene->addChild(layer, 1);
	return scene;
}

bool StartChart::init()
{
	if (!Layer::init()) {
		return false;
	}
	auto chartsScene = CSLoader::createNode("ChartsScene.csb");

	auto _returnBtn = static_cast<ui::Button*>(chartsScene->getChildByName("returnBtn"));

	_returnBtn->addTouchEventListener(CC_CALLBACK_2(StartChart::gotoMainScene, this));

	addChild(chartsScene);

	for (int i = 0; i < 5; i++) {
		int score = UserDefault::getInstance()->getIntegerForKey(StringUtils::format("%s%d", RANK_SORE, i).c_str(), UserDefault::getInstance()->getIntegerForKey(StringUtils::format("%s%d", NOW_SORE, i).c_str()));
		auto row = createCharts(i, score);
		row->setPosition(Vec2(480, 500 - i * 80));
		addChild(row);
	}

	return true;
}

void StartChart::gotoMainScene(Ref* sender, cocos2d::ui::Widget::TouchEventType type)
{
	CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("sounds/sndMenuButtonRollover.mp3");
	Director::getInstance()->replaceScene(TransitionProgressRadialCW::create(0.5, StartScene::createScene()));
}

Node * StartChart::createCharts(int rank, int score)
{
	auto row = Node::create();
	auto r = ui::TextAtlas::create(StringUtils::format("%d", rank + 1), "imgs/numbers2.png", 55, 51, "0");
	auto s = ui::TextAtlas::create(StringUtils::format("%d", score), "imgs/numbers2.png", 55, 51, "0");

	r->setScale(0.8);
	s->setScale(0.8);
	r->setAnchorPoint(Vec2(0, 0.5));
	s->setAnchorPoint(Vec2(1, 0.5));

	r->setPosition(Vec2(80, 0));
	s->setPosition(Vec2(500, 0));

	row->addChild(r);
	row->addChild(s);

	row->setContentSize(Size(600, 80));
	row->setAnchorPoint(Vec2(0.5, 0.5));

	return row;
}
