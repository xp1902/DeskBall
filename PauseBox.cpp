#include "PauseBox.h"
#include "ui/CocosGUI.h"
#include "ui/UIText.h"   
#include "cocostudio/CocoStudio.h"
#include "HelloWorldScene.h"
#include "StartScene.h"
#include "StartChart.h"
#include "Options.h"
#include "SimpleAudioEngine.h"

PauseBox::PauseBox() {
}
PauseBox::~PauseBox() {
}

Scene * PauseBox::createScene(RenderTexture *rt)
{
	Scene* scene = Scene::create();
	PauseBox* layer = PauseBox::create();
	scene->addChild(layer, 1);

	Sprite *bg = Sprite::createWithTexture(rt->getSprite()->getTexture());
	bg->setPosition(480, 320);
	bg->setFlipY(true);
	bg->setColor(Color3B(190, 190, 190));
	scene->addChild(bg, 0);
	return scene;
}

bool PauseBox::init() {
	if (!Layer::init()){
		return false;
	}
	auto pauseBox= CSLoader::createNode("pauseBox.csb");
	auto viewSize = Director::getInstance()->getVisibleSize();

	auto _menuBtn = static_cast<ui::Button*>(pauseBox->getChildByName("menuBtn"));
	auto _resumeBtn = static_cast<ui::Button*>(pauseBox->getChildByName("resumeBtn"));
	auto _restartBtn = static_cast<ui::Button*>(pauseBox->getChildByName("restartBtn"));
	auto _optionBtn = static_cast<ui::Button*>(pauseBox->getChildByName("optionBtn"));

	_resumeBtn->addTouchEventListener(CC_CALLBACK_2(PauseBox::resumeCallback, this));
	_optionBtn->addTouchEventListener(CC_CALLBACK_2(PauseBox::optionCallback, this));
	_restartBtn->addTouchEventListener(CC_CALLBACK_2(PauseBox::restartCallback, this));
	_menuBtn->addTouchEventListener(CC_CALLBACK_2(PauseBox::menuCallback, this));

	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = ([](Touch* touch, Event* event) {return true; });
	listener->setSwallowTouches(true);
	pauseBox->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);

	addChild(pauseBox);
	return true;
}

void PauseBox::resumeCallback(Ref* sender, cocos2d::ui::Widget::TouchEventType type) {
	CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("sounds/sndMenuButtonRollover.mp3");
	Director::getInstance()->popScene();
}

void PauseBox::optionCallback(Ref* sender, cocos2d::ui::Widget::TouchEventType type) {
	auto visibleSize = Director::getInstance()->getVisibleSize();
	CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("sounds/sndMenuButtonRollover.mp3");

	RenderTexture *renderTexture = RenderTexture::create(visibleSize.width, visibleSize.height);
	renderTexture->begin();
	this->getParent()->visit();
	renderTexture->end();

	Director::getInstance()->pushScene(Options::createScene(renderTexture));
}

void PauseBox::restartCallback(Ref* sender, cocos2d::ui::Widget::TouchEventType type) {
	CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("sounds/sndMenuButtonRollover.mp3");
	Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
	Director::getInstance()->replaceScene(TransitionProgressRadialCW::create(0.5, HelloWorld::createScene()));
}

void PauseBox::menuCallback(Ref* sender, cocos2d::ui::Widget::TouchEventType type) {
	Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
	CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("sounds/sndMenuButtonRollover.mp3");
	Director::getInstance()->replaceScene(TransitionProgressRadialCW::create(0.5, StartScene::createScene()));
}