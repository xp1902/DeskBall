#include "StartScene.h"
#include "ui/CocosGUI.h"
#include "ui/UIText.h"   
#include "cocostudio/CocoStudio.h"
#include "HelpScene.h"
#include "StartScene.h"
#include "SimpleAudioEngine.h"

HelpScene::HelpScene() {}
HelpScene::~HelpScene() {}

Scene * HelpScene::createScene()//RenderTexture *rt
{
	Scene* scene = Scene::create();
	HelpScene* layer = HelpScene::create();
	scene->addChild(layer, 2);
	return scene;
}

bool HelpScene::init()
{
	if (!Layer::init()) {
		return false;
	}
	auto HelpScene = CSLoader::createNode("HelpScene.csb");

	auto _menuBtn = static_cast<ui::Button*>(HelpScene->getChildByName("Help_ReturnButton"));

	_menuBtn->addTouchEventListener(CC_CALLBACK_2(HelpScene::H_ReturnMainMenu, this));

	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = ([](Touch* touch, Event* event) {return true; });
	listener->setSwallowTouches(true);
	HelpScene->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);

	addChild(HelpScene);
	return true;
}

void HelpScene::H_ReturnMainMenu(Ref* sender, cocos2d::ui::Widget::TouchEventType type)
{
	CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("sounds/sndMenuButtonRollover.mp3");
	Director::getInstance()->replaceScene(TransitionProgressRadialCW::create(0.5, StartScene::createScene()));
}