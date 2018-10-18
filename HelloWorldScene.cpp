#include "HelloWorldScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "SimpleAudioEngine.h"
#include "Goal.h"

USING_NS_CC;
using namespace cocostudio::timeline;

HelloWorld::~HelloWorld() {
	this->removeAllChildren();
}
Scene* HelloWorld::createScene()
{
    auto scene = Scene::createWithPhysics();

	auto pWorld = scene->getPhysicsWorld();
	pWorld->setGravity(Vec2(0, -1));

    auto layer = HelloWorld::create();

    scene->addChild(layer);

    return scene;
}
bool HelloWorld::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
	CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("sounds/gameplay_1.mp3");
	auto visibleSize = Director::getInstance()->getVisibleSize();
	_visibleSize = visibleSize;

	initUI();
	initLevelDataList();
	auto snow = ParticleRain::create();
	snow->setPosition(Vec2(visibleSize.width / 2, visibleSize.height));
	addChild(snow);

	gameStart("imgs/go.png");
	_scoreData = new ScoreData();
	_scoreStagy = new ScoreStragy();
	newGame();

	gameStart("imgs/go.png");
	scheduleUpdate();
    return true;
}
void HelloWorld::initLevelDataList()
{
}
void HelloWorld::update(float dt) {
	_timeSec++;

	_scoreText->set_text(_scoreData->score);
	_timeText ->set_text(_timeSec / 100);
	_restBall   ->set_text(life);
	_levelText->set_text(_nowLevel);

	if (_ball->getPositionY() < 0) {
		if (life - 1) {
			gameStart("imgs/Lost_ball.png");
			_ball->removeFromParent();
			addBall(Vec2(_paddle->getPositionX(), 30));
			life--;
		}
		else {
			_nowLevel--;
			_nowLevelLayer->removeFromParent();
			newGame();
			gameStart("imgs/tryagain.png");
		}
	}
	if (!goal) {
		fillChart();

		_ball->removeFromParent();
		_paddle->removeFromParent();
		_nowLevelLayer->removeFromParent();
		addCharts();
		addPaddle();
		addBall(Vec2(_visibleSize.width / 2, 30));
		_timeSec = 0;
		nextLevel();
	}
}

void HelloWorld::fillChart() {

	UserDefault::getInstance()->setIntegerForKey(StringUtils::format("%s%d", NOW_SORE, 0).c_str(), _scoreData->score);
	UserDefault::getInstance()->setIntegerForKey(StringUtils::format("%s%d", SPEND_TIME, 0).c_str(), _timeSec / 100);

		scoreList.push_back(_scoreData->score);
		for (int i = 0; i < 5; i++) {
			int score = UserDefault::getInstance()->getIntegerForKey(StringUtils::format("%s%d", RANK_SORE, i).c_str(), _scoreData->score);
			scoreList.push_back(score);
		}
		std::sort(scoreList.begin(), scoreList.end(), [](int& a, int& b) {
			return a > b;
		});

		int rank = 0;
		for (auto i = scoreList.begin(); i != scoreList.end(); i++) {
			UserDefault::getInstance()->setIntegerForKey(StringUtils::format("%s%d", RANK_SORE, rank).c_str(), *i);
			rank++;
		}
}

void HelloWorld::onEnter()
{
	Layer::onEnter();
	{
		auto listener1 = EventListenerTouchOneByOne::create();
		auto listener2 = EventListenerPhysicsContact::create();
		auto listener3 = EventListenerKeyboard::create();
		listener1->setSwallowTouches(true);
		listener1->onTouchBegan = CC_CALLBACK_2(HelloWorld::onTouchBegan, this);
		listener1->onTouchMoved = CC_CALLBACK_2(HelloWorld::onTouchMoved, this);
		listener1->onTouchEnded = CC_CALLBACK_2(HelloWorld::onTouchEnded, this);
		_eventDispatcher->addEventListenerWithSceneGraphPriority(listener1, this);

		listener2->onContactBegin = CC_CALLBACK_1(HelloWorld::onContactBegin, this);
		listener2->onContactPreSolve = CC_CALLBACK_1(HelloWorld::onContactPreSlove, this);
		listener2->onContactPostSolve = CC_CALLBACK_1(HelloWorld::onContactPostSolve, this);
		listener2->onContactSeparate = CC_CALLBACK_1(HelloWorld::onContactSeparate, this);
		Director::getInstance()->getEventDispatcher()->addEventListenerWithFixedPriority(listener2, 1);

		listener3->onKeyPressed = CC_CALLBACK_2(HelloWorld::onKeyPressed, this);
		listener3->onKeyReleased = CC_CALLBACK_2(HelloWorld::onKeyReleased, this);
		_eventDispatcher->addEventListenerWithSceneGraphPriority(listener3, this);
	}
	this->scheduleUpdate();
}
void HelloWorld::onExit()
{
	this->unscheduleUpdate();
	Layer::onExit();
	//removeAllChildren();
	//Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
	
}
void HelloWorld::initUI() {
	addBg();
	addScoreText();
}

void HelloWorld::gameStart(std::string img) {
	auto go = Sprite::create(img);
	go->setAnchorPoint(Vec2(0.5, 0.5));
	go->setPosition(_visibleSize.width / 2, _visibleSize.height / 2);
	go->setOpacity(1);
	go->setScale(2);
	addChild(go);
	go->runAction(Sequence::create(Spawn::create(FadeIn::create(1), ScaleTo::create(1, 1), NULL), RemoveSelf::create(true), NULL));
}
void HelloWorld::scorePlus(std::string img, Vec2 pos) {
	auto score = Sprite::create(img);
	score->setPosition(pos);
	score->setOpacity(0.5);
	addChild(score);
	score->runAction(Sequence::create(Spawn::create(FadeIn::create(0.5), ScaleTo::create(0.5, 2), NULL), RemoveSelf::create(true), NULL));
}

void HelloWorld::addBg() {
	bg = BackGround::create();
	_bg = bg;
	addChild(_bg);
}
void HelloWorld::addBall(Vec2 pos) {
	Ball* ball = Ball::create();
	ball->setAnchorPoint(Vec2(0.5, 0.5));
	ball->setPosition(pos);
	ball->setTag(1);
	addChild(ball, 0, tag_ball);
	_ball = ball;
}
void HelloWorld::addPaddle() {
	auto * paddle = Sprite::create("imgs/paddle.png");
	paddle->setPosition(_visibleSize.width / 2, 1);

	auto playerPhysicsBody = PhysicsBody::createBox(paddle->getContentSize());
	paddle->setPhysicsBody(playerPhysicsBody);
	playerPhysicsBody->getShape(0)->setFriction(0);
	playerPhysicsBody->getShape(0)->setRestitution(1.0f);
	playerPhysicsBody->setDynamic(false);

	paddle->getPhysicsBody()->setCollisionBitmask(0x0001);
	paddle->getPhysicsBody()->setCategoryBitmask(0x0001);
	paddle->getPhysicsBody()->setContactTestBitmask(0x0001);

	paddle->setScale(0.6f);
	movableSprites.pushBack(paddle);
	paddle->setTag(0);
	paddle->setAnchorPoint(Vec2(0.5f, 0));
	addChild(paddle, 0, tag_paddle);
	_paddle = paddle;
}

void HelloWorld::newGame(){
	if(_ball) _ball->removeFromParent();
	if(_paddle) _paddle->removeFromParent();
	_timeSec = 0;
	_nowLevel = 0;
	addPaddle();
	addBall(Vec2(_visibleSize.width / 2, 30));
	nextLevel();
}
void HelloWorld::nextLevel()
{
	_scoreData->score = 0;
	life = 3;
	goal = 3;
	_nowLevel++;
	if (_nowLevel == 10) {
		Director::getInstance()->replaceScene(EndScene::createScene());
	}
	LevelData leveldata = {};
	leveldata.levelS = _nowLevel;
	leveldata.columns = 10;
	leveldata.rows = 8;

	auto level = DBLevel::create(leveldata);
	auto size = level->getContentSize();
	level->setAnchorPoint(Vec2(0, 0));
	level->ignoreAnchorPointForPosition(false);

	level->setPosition(Vec2(83, _visibleSize.height / 2 - 140));
	addChild(level);

	_nowLevelLayer = level;
}

void HelloWorld::addCharts()
{
	RenderTexture *renderTexture = RenderTexture::create(_visibleSize.width, _visibleSize.height);
	renderTexture->begin();
	this->getParent()->visit();
	renderTexture->end();

	Director::getInstance()->pushScene(ChartsScene::createScene(renderTexture));
}
void HelloWorld::addPauseBox() {
	RenderTexture *renderTexture = RenderTexture::create(_visibleSize.width, _visibleSize.height);
	renderTexture->begin();
	this->getParent()->visit();
	renderTexture->end();

	Director::getInstance()->pushScene(PauseBox::createScene(renderTexture));
}
void HelloWorld::addScoreText() {
	_scoreText = ScoreText::create();
	_scoreText->setPosition(Vec2(720, 625));
	_scoreText->setScale(0.5f);
	addChild(_scoreText, 10);

	_timeText = ScoreText::create();
	_timeText->setPosition(Vec2(480, 625));
	_timeText->setScale(0.5f);
	addChild(_timeText, 10);

	_restBall = ScoreText::create();
	_restBall->setPosition(Vec2(480, 560));
	_restBall->setScale(1.0f);
	addChild(_restBall, 10);

	_levelText = ScoreText::create();
	_levelText->setPosition(Vec2(80, 625));
	_levelText->setScale(0.5f);
	addChild(_levelText, 10);
}

void HelloWorld::addParticleSystem(Sprite* spriteB, int i) {
	auto visibleSize = Director::getInstance()->getVisibleSize();
	switch (i)
	{
	case 1:
		ParticleSystemQuad* particleSystem1;
		particleSystem1 = ParticleSystemQuad::create("plists/redstars.plist"); 
		particleSystem1->setPosition(Vec2(spriteB->getPosition().x + 70, spriteB->getPosition().y + visibleSize.height / 2 - 50));
		this->addChild(particleSystem1);
		break;
	case 2:
		ParticleSystemQuad* particleSystem2;
		particleSystem2 = ParticleSystemQuad::create("plists/explode.plist"); 
		particleSystem2->setPosition(Vec2(spriteB->getPosition().x + 70, spriteB->getPosition().y + visibleSize.height / 2 - 50));
		this->addChild(particleSystem2); 
		break;
	case 3:
		ParticleSystemQuad* particleSystem3;
		particleSystem3 = ParticleSystemQuad::create("plists/stars.plist");
		particleSystem3->setPosition(Vec2(spriteB->getPosition().x + 70, spriteB->getPosition().y + visibleSize.height / 2 - 50));
		this->addChild(particleSystem3); break;
	}
}

bool HelloWorld::onTouchBegan(Touch* touch, Event* event)
{
    Point touchLocation = this->convertTouchToNodeSpace(touch);
	Size s = this->getContentSize();
	Rect rect = Rect(0, 0, s.width, s.height);
	if (rect.containsPoint(touchLocation)) {
		Sprite* bs = (Sprite*)this->getChildByTag(tag_ball);
		if (abs(bs->getPhysicsBody()->getVelocity().x) - 1 < 0){
			bs->getPhysicsBody()->setVelocity(Vec2(10, 650));
		}
		return true;
	}
    return false;
}
void HelloWorld::onTouchMoved(Touch* touch, Event* event)
{
	Point touchLocation = this->convertTouchToNodeSpace(touch);
	//if (event->getCurrentTarget()->getBoundingBox().containsPoint(touch->getLocation())) {
	//	this->selectSpriteForTouch(touchLocation);
	//}

	Sprite* pd = (Sprite*)this->getChildByTag(tag_paddle);
	//if (pd->getBoundingBox().containsPoint(touch->getLocation())) {
	if (touch->getLocation().x > 81 && touch->getLocation().x < 855) {
		pd->setPositionX(touch->getLocation().x);
	}
	//}
}
void HelloWorld::onTouchEnded(Touch* touch, Event* event)
{
}
void HelloWorld::selectSpriteForTouch(Point touchLocation)
{
	Sprite * newSprite = NULL;
	
}

bool HelloWorld::onContactBegin(const PhysicsContact& contact)
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Sprite* spriteA = (Sprite*)contact.getShapeA()->getBody()->getNode();
	Sprite* spriteB = (Sprite*)contact.getShapeB()->getBody()->getNode();
	if (spriteA && spriteB) {
		int tagA = spriteA->getTag();
		int tagB = spriteB->getTag();
		if (tagA == 1 && tagB == 0 || tagA == 1 && tagB == 0)
		{
			CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("sounds/sndBallBounce.mp3");
		}
		if (tagA == 1 && tagB == 20 || tagA == 20 && tagB == 1)
		{
			//particleSystem2->setPosition(Vec2(spriteB->getPosition().x + 70, spriteB->getPosition().y + visibleSize.height / 2 - 50));
			//this->addChild(particleSystem2);
			addParticleSystem(spriteB, 2);
			this->scorePlus("imgs/10.png", Vec2(spriteB->getPosition().x + 70, spriteB->getPosition().y + visibleSize.height / 2 - 50));
			spriteB->removeFromParent();
			CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("sounds/collect_03.mp3");
		}
		if (tagA == 1 && tagB == 2 || tagA == 2 && tagB == 1)
		{
			//particleSystem1->setPosition(Vec2(spriteB->getPosition().x + 70, spriteB->getPosition().y + visibleSize.height / 2 - 50));
			//this->addChild(particleSystem1);
			addParticleSystem(spriteB, 1);
			this->scorePlus("imgs/10.png", Vec2(spriteB->getPosition().x + 70, spriteB->getPosition().y + visibleSize.height / 2 - 50));
			spriteB->removeFromParent();
			CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("sounds/collect_03.mp3");
		}
		if (tagA == 1 && tagB == 3 || tagA == 3 && tagB == 1)
		{
			addParticleSystem(spriteB, 3);
			this->scorePlus("imgs/starplus.png", Vec2(480, spriteB->getPosition().y + visibleSize.height / 2 - 50));
			this->scorePlus("imgs/1000.png", Vec2(480, spriteB->getPosition().y + visibleSize.height / 2 + 50));
			spriteB->removeFromParent();
			goal--;
			CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("sounds/collect_01.mp3");
		}
		if (tagA == 1 && tagB == 3000 || tagA == 3000 && tagB == 1) {
			addParticleSystem(spriteB, 3);
			spriteB->removeFromParent();
			CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("sounds/collect_05.mp3");
			this->scorePlus("imgs/gift.png", Vec2(480, 320));
			this->scorePlus("imgs/3000.png", Vec2(480, 370));
		}
		if (tagA == 1 && tagB == 1000 || tagA == 1000 && tagB == 1) {
			//particleSystem2->setPosition(Vec2(spriteB->getPosition().x + 70, spriteB->getPosition().y + visibleSize.height / 2 - 50));
			//this->addChild(particleSystem2);
			addParticleSystem(spriteB, 2);
			spriteB->removeFromParent();
			CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("sounds/bomb_02.mp3");

			this->scorePlus("imgs/bomb.png", Vec2(480, 320));
			this->scorePlus("imgs/-1000.png", Vec2(480, 370));
		}
		if (tagA == 1 && tagB == 5 || tagA == 5 && tagB == 1)
		{
			CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("sounds/sndRoundPaddleBounce.mp3");
		}
		if (tagA == 1 && tagB == 6 || tagA == 6 && tagB == 1)
		{
			CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("sounds/sndPaddleBounce.mp3");
		}
		if (tagA == 1 && tagB == 7 || tagA == 7 && tagB == 1) {
			spriteB->removeFromParent();
			CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("sounds/sndGlassBreakaway.mp3");
		}
		_scoreStagy->execute(_scoreData, tagB);
	}
	return true;
}
bool HelloWorld::onContactPreSlove(const PhysicsContact& contact) {
	//log("presolved");
	return true;
}
bool HelloWorld::onContactPostSolve(const PhysicsContact& contact){

		//log("onContactPostSolve");
		return true;
};
bool HelloWorld::onContactSeparate(const PhysicsContact& contact) {
	//log("onContactSeperate");
	return false;
};

void HelloWorld::onKeyPressed(EventKeyboard::KeyCode code, Event* event) {
	addPauseBox();
	switch (code)
	{
	case cocos2d::EventKeyboard::KeyCode::KEY_ENTER:
		//this->getChildByTag(101)->removeFromParent();
		break;
	}
}
void HelloWorld::onKeyReleased(EventKeyboard::KeyCode code, Event* event) {
}