#include "ChoiceScene.h"
#include "StartScene.h"
#include "ui/CocosGUI.h"
#include "cocostudio/CocoStudio.h"
#include "UserData.h"
#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"

ChoiceScene::ChoiceScene()
{
}
ChoiceScene::~ChoiceScene()
{
}

Scene * ChoiceScene::createScene()
{
	ChoiceScene* Layer = ChoiceScene::create();
	Scene* scene = Scene::create();
	scene->addChild(Layer);
	return scene;
}

bool ChoiceScene::init()
{
	if (!Layer::init()) {
		return false;
	}

	auto choiceScene = CSLoader::createNode("ChoiceScene.csb");

	auto l1Btn = static_cast<ui::Button*>(choiceScene->getChildByName("level1"));
	auto l2Btn = static_cast<ui::Button*>(choiceScene->getChildByName("level2"));
	auto l3Btn = static_cast<ui::Button*>(choiceScene->getChildByName("level3"));
	auto l4Btn = static_cast<ui::Button*>(choiceScene->getChildByName("level4"));
	auto l5Btn = static_cast<ui::Button*>(choiceScene->getChildByName("level5"));
	auto l6Btn = static_cast<ui::Button*>(choiceScene->getChildByName("level6"));
	auto l7Btn = static_cast<ui::Button*>(choiceScene->getChildByName("level7"));
	auto l8Btn = static_cast<ui::Button*>(choiceScene->getChildByName("level8"));
	auto l9Btn = static_cast<ui::Button*>(choiceScene->getChildByName("level9"));
	l2Btn->setBright(false);
	l3Btn->setBright(false);
	l4Btn->setBright(false);
	l5Btn->setBright(false);
	l6Btn->setBright(false);
	l7Btn->setBright(false);
	l8Btn->setBright(false);
	l9Btn->setBright(false);
	auto returnBtn = static_cast<ui::Button*>(choiceScene->getChildByName("returnButton"));

	l1Btn->addTouchEventListener(CC_CALLBACK_2(ChoiceScene::gotoLevel1, this));
	returnBtn->addTouchEventListener(CC_CALLBACK_2(ChoiceScene::returnStartMenu, this));

	addChild(choiceScene);
}

void ChoiceScene::gotoLevel1(Ref * sender, cocos2d::ui::Widget::TouchEventType type)
{
	CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("sounds/sndMenuButtonRollover.mp3");
	Director::getInstance()->replaceScene(TransitionProgressRadialCW::create(0.5, HelloWorld::createScene()));
}

void ChoiceScene::returnStartMenu(Ref * sender, cocos2d::ui::Widget::TouchEventType type)
{
	CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("sounds/sndMenuButtonRollover.mp3");
	Director::getInstance()->replaceScene(TransitionProgressRadialCW::create(0.5, StartScene::createScene()));
}

