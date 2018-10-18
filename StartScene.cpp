#include "StartScene.h"
#include "ui/CocosGUI.h"
#include "ui/UIText.h"   
#include "cocostudio/CocoStudio.h"
#include "ChoiceScene.h"
#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#include "StartChart.h"
#include "HelpScene.h"

StartScene::StartScene() {}
StartScene::~StartScene() {
}

Scene * StartScene::createScene()//RenderTexture *rt
{
	Scene* scene = Scene::create();
	StartScene* layer = StartScene::create();
	scene->addChild(layer, 1);
	return scene;
}

bool StartScene::init()
{
	if (!Layer::init()) {
		return false;
	}
	CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("sounds/gameplay_2.mp3");
	auto StartScene = CSLoader::createNode("StartScene.csb");

	auto _menuBtn_1 = static_cast<ui::Button*>(StartScene->getChildByName("PlayButton"));
	auto _menuBtn_2 = static_cast<ui::Button*>(StartScene->getChildByName("auitButton"));
	auto _menuBtn_3 = static_cast<ui::Button*>(StartScene->getChildByName("optionsButton"));
	auto _menuBtn_4 = static_cast<ui::Button*>(StartScene->getChildByName("chartsBtn"));

	_menuBtn_1->addTouchEventListener(CC_CALLBACK_2(StartScene::gotoChoiceScene, this));
	_menuBtn_3->addTouchEventListener(CC_CALLBACK_2(StartScene::openOptionCallback, this));
	_menuBtn_2->addTouchEventListener(CC_CALLBACK_2(StartScene::quitGameCallback, this));
	_menuBtn_4->addTouchEventListener(CC_CALLBACK_2(StartScene::gotoChartScene, this));

	addChild(StartScene);
	return true;
}

void StartScene::gotoChartScene(Ref* sender, cocos2d::ui::Widget::TouchEventType type)
{
	CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("sounds/sndMenuButtonRollover.mp3");
	Director::getInstance()->replaceScene(TransitionProgressRadialCW::create(0.5, StartChart::createScene()));
}

void StartScene::gotoChoiceScene(Ref* sender, cocos2d::ui::Widget::TouchEventType type)
{
	CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("sounds/sndMenuButtonRollover.mp3");
	Director::getInstance()->replaceScene(TransitionProgressRadialCW::create(0.5, ChoiceScene::createScene()));
}

void StartScene::openOptionCallback(Ref* sender, cocos2d::ui::Widget::TouchEventType type)
{
	CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("sounds/sndMenuButtonRollover.mp3");
	Director::getInstance()->replaceScene(TransitionProgressRadialCW::create(0.5, HelpScene::createScene()));
}

void StartScene::quitGameCallback(Ref* sender, cocos2d::ui::Widget::TouchEventType type)
{
	CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("sounds/sndMenuButtonRollover.mp3");
	Director::getInstance()->end();
}