#include "Options.h"
#include "ui/CocosGUI.h"
#include "ui/UIText.h"   
#include "cocostudio/CocoStudio.h"
#include "HelloWorldScene.h"
#include "StartScene.h"
#include "StartChart.h"
#include "SimpleAudioEngine.h"

Options::Options() {
}
Options::~Options() {
}

Scene * Options::createScene(RenderTexture *rt)
{
	Scene* scene = Scene::create();
	Options* layer = Options::create();
	scene->addChild(layer, 1);

	Sprite *bg = Sprite::createWithTexture(rt->getSprite()->getTexture());
	bg->setPosition(480, 320);
	bg->setFlipY(true);
	bg->setColor(Color3B(190, 190, 190));
	scene->addChild(bg, 0);
	return scene;
}

bool Options::init() {
	if (!Layer::init()) {
		return false;
	}
	auto options = CSLoader::createNode("options.csb");
	auto viewSize = Director::getInstance()->getVisibleSize();

	auto _returnBtn = static_cast<ui::Button*>(options->getChildByName("returnBtn"));
	_returnBtn->addTouchEventListener(CC_CALLBACK_2(Options::returnCallback, this));
	auto _music = static_cast<ui::CheckBox*>(options->getChildByName("music"));
	auto _effect = static_cast<ui::CheckBox*>(options->getChildByName("effect"));

	_music->addEventListenerCheckBox(this, checkboxselectedeventselector(Options::musicCallback));
	_effect->addEventListenerCheckBox(this, checkboxselectedeventselector(Options::effectCallback));

	auto _slider1 = static_cast<ui::Slider*>(options->getChildByName("slider1"));
	_slider1->addEventListenerSlider(this, sliderpercentchangedselector(Options::slider1Callback));

	auto snow = ParticleRain::create();
	snow->setPosition(Vec2(viewSize.width / 2, viewSize.height));
	addChild(snow);
	addChild(options);

	return true;
}

void Options::returnCallback(Ref* sender, ui::Widget::TouchEventType type) {
	
	CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("sounds/sndMenuButtonRollover.mp3");
	Director::getInstance()->popScene();
}

void Options::slider1Callback(Ref* ref, SliderEventType type)
{
	auto item = (Slider*)(ref);
	switch (type)
	{
	case::SLIDER_PERCENTCHANGED:
		if (item->getPercent() == 100) {
			item->setEnabled(false);
		}
		else {
			CocosDenshion::SimpleAudioEngine::getInstance()->setBackgroundMusicVolume(item->getPercent() / 100.0f);
		}; break;
	}
}

void Options::musicCallback(Ref * ref, CheckBoxEventType type)
{
	switch (type)
	{
	case CHECKBOX_STATE_EVENT_UNSELECTED:
		CocosDenshion::SimpleAudioEngine::getInstance()->pauseBackgroundMusic(); break;
	case CHECKBOX_STATE_EVENT_SELECTED:
		CocosDenshion::SimpleAudioEngine::getInstance()->resumeBackgroundMusic(); break;
	}
}

void Options::effectCallback(Ref * ref, CheckBoxEventType type)
{
	switch (type)
	{
	case CHECKBOX_STATE_EVENT_UNSELECTED:
		CocosDenshion::SimpleAudioEngine::getInstance()->pauseAllEffects(); break;
	case CHECKBOX_STATE_EVENT_SELECTED:
		CocosDenshion::SimpleAudioEngine::getInstance()->resumeAllEffects(); break;
	}
}
