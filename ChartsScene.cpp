#include "ChartsScene.h"
#include "cocostudio/CocoStudio.h"   
#include "cocostudio/WidgetCallBackHandlerProtocol.h"  
#include "SimpleAudioEngine.h"

ChartsScene::ChartsScene()
{
}

ChartsScene::~ChartsScene()
{
}

Scene* ChartsScene::createScene(RenderTexture *rt) {
	Scene* scene = Scene::create();
	ChartsScene* layer = ChartsScene::create();
	scene->addChild(layer, 1);

	Sprite *bg = Sprite::createWithTexture(rt->getSprite()->getTexture());
	bg->setPosition(480, 320);
	bg->setFlipY(true);
	bg->setColor(Color3B(190, 190, 190));
	scene->addChild(bg, 0);
	return scene;
}

//ChartsScene * ChartsScene::getInstance()
//{
//	if (_instance == nullptr) {
//		_instance == new ChartsScene();
//	}
//	return _instance;
//}
//
//void ChartsScene::getNowScore(int score)
//{
//	_nowScore = score;
//}
//
//void ChartsScene::getSpendTime(int time)
//{
//	_spendTime = time;
//}

void ChartsScene::gameStart(std::string img) {
	auto go = Sprite::create(img);
	go->setAnchorPoint(Vec2(0.5, 0.5));
	go->setPosition(480, 320);
	go->setOpacity(1);
	go->setScale(2);
	addChild(go);
	go->runAction(Sequence::create(Spawn::create(FadeIn::create(1), ScaleTo::create(1, 1), NULL), RemoveSelf::create(true), NULL));
}

bool ChartsScene::init() {
	if (!Layer::init()) {
		return false;
	}

	auto charts = CSLoader::createNode("charts.csb");
	auto viewSize = Director::getInstance()->getVisibleSize();

	auto _backBtn = static_cast<ui::Button*>(charts->getChildByName("backBtn"));
	_backBtn->addTouchEventListener(CC_CALLBACK_2(ChartsScene::backBtnCallback, this));

	score = ui::TextAtlas::create("0", "imgs/numbers2.png", 55, 51, "0");
	score->setPosition(Vec2(596, 364));
	auto nowScore = UserDefault::getInstance()->getIntegerForKey(StringUtils::format("%s%d", NOW_SORE, 0).c_str(), 1200);
	score->setString(StringUtils::format("%d", nowScore));
	score->setScale(0.8f);
	this->addChild(score, 2);

	time = ui::TextAtlas::create("0", "imgs/numbers2.png", 55, 51, "0");
	time->setPosition(Vec2(596, 250));
	auto spendTime = UserDefault::getInstance()->getIntegerForKey(StringUtils::format("%s%d", SPEND_TIME, 0).c_str(), 10);
	time->setString(StringUtils::format("%d", spendTime));
	time->setScale(0.8f);
	this->addChild(time, 2);

	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = ([](Touch* touch, Event* event) {return true; });
	listener->setSwallowTouches(true);
	charts->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);


	auto snow = ParticleFireworks::create();
	snow->setPosition(Vec2(3 * viewSize.width / 4, 3* viewSize.height / 4));
	addChild(snow);

	addChild(charts);
	return true;
}

void ChartsScene::backBtnCallback(Ref* sender, cocos2d::ui::Widget::TouchEventType type)
{
	CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("sounds/sndMenuButtonClick.mp3");
	Director::getInstance()->popScene();
}