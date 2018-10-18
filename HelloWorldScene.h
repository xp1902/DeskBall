#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "Box2D\Box2D.h"
#include "BackGround.h"
#include "Bricks.h"
#include "BBall.h"
#include "DBLevel.h"
#include "LevelData.h"
#include <memory>
#include "PauseBox.h"
#include "ScoreText.h"
#include "ChartsScene.h"
#include "UserData.h"
#include "ScoreData.h"
#include "ScoreStrategy.h"
#include "EndScene.h"

using namespace cocos2d;

typedef enum {
	tag_paddle,
	tag_ball,
	tag_BG,
	tag_pause,
}tagForMove;

class HelloWorld : public cocos2d::Layer
{
protected:
	std::vector<int> scoreList;
	int life;
	int goal;
	int _timeSec;
	int _nowLevel;
	DBLevel * _nowLevelLayer;
	LevelData* _nowLevelData;
	std::vector<LevelData> _levelDataList;
	ScoreStragy* _scoreStagy;
	ScoreText* _scoreText;
	ScoreText* _timeText;
	ScoreText* _restBall;
	ScoreText* _levelText;
	ScoreData* _scoreData;

	PauseBox* _pauseBox;
	Ball* _ball;
	Sprite* _paddle;
	Size _visibleSize;
	BackGround* _bg;
public:
	cocos2d::Sprite * selSprite;
	cocos2d::Vector<cocos2d::Sprite *> movableSprites;
private:
	BackGround * bg;
public:
	~HelloWorld();
	static cocos2d::Scene* createScene();
	virtual bool init();
	virtual void initLevelDataList();
	virtual void update(float dt);
	void fillChart();
	virtual void newGame();
	virtual void nextLevel();

	void addBall(Vec2 pos);
	void addBg();
	void addPaddle();
	void addCharts();
	void addPauseBox();
	void addScoreText();

	void addParticleSystem(Sprite * spriteB, int i);

	bool onTouchBegan(Touch * touch, Event * event);
	void onTouchMoved(Touch * touch, Event * event);
	void onTouchEnded(Touch * touch, Event * event);
	void selectSpriteForTouch(Point touchLocation);

	bool onContactBegin(const PhysicsContact & contact);
	bool onContactPreSlove(const PhysicsContact & contact);
	bool onContactSeparate(const PhysicsContact & contact);

	bool onContactPostSolve(const PhysicsContact & contact);

	void onKeyPressed(EventKeyboard::KeyCode e, Event * event);

	void onKeyReleased(EventKeyboard::KeyCode code, Event * event);

	void onEnter();
	void onExit();

	void initUI();
	void gameStart(std::string img);
	void scorePlus(std::string img, Vec2 pos);

    CREATE_FUNC(HelloWorld);
};

#endif
