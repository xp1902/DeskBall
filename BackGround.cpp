#include "BackGround.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

USING_NS_CC;

using namespace cocostudio::timeline;

BackGround::BackGround() {

}

BackGround::~BackGround() {
	unscheduleUpdate();
}

bool BackGround::init() {
	if (!Node::init()) {
		return false;
	}
	bg = Sprite::create("imgs/background3.jpg");
	bg->setAnchorPoint(Vec2(0, 0));
	bg->setScale(1.876f, 1.2476f);
	//Texture2D::TexParams tp = { GL_LINEAR, GL_LINEAR, GL_REPEAT, GL_REPEAT };
	//bg->getTexture()->setTexParameters(tp);
	//auto viewSize = Director::getInstance()->getVisibleSize();
	//bg->setTextureRect(Rect(0, 0, viewSize.width, viewSize.height));
	addChild(bg);
	addHud();
	//addEdges();
	addPaddle2();
	//scheduleUpdate();
	return true;
}

void BackGround::addHud()
{
	auto hud = Sprite::create("imgs/hud.png");
	{
		auto hudBody = PhysicsBody::create();
		Point vert1[3] = { Point(217.00000,-246.00000), Point(256.00000,-256.00000), Point(214.00000,-256.00000) };
		auto shape1 = PhysicsShapePolygon::create(vert1, 3);
		shape1->setFriction(0);
		shape1->setRestitution(1.0f);
		hudBody->addShape(shape1);

		Point vert2[4] = { Point(220.00000,-218.00000), Point(222.00000,-213.00000), Point(256.00000,-256.00000), Point(217.00000,-246.00000) };
		auto shape2 = PhysicsShapePolygon::create(vert2, 4);
		shape2->setFriction(0);
		shape2->setRestitution(1.0f);
		hudBody->addShape(shape2);

		Point vert3[3] = { Point(-256.00000,-256.00000), Point(-217.00000,-246.00000), Point(-214.00000,-256.00000) };
		auto shape3 = PhysicsShapePolygon::create(vert3, 3);
		shape3->setFriction(0);
		shape3->setRestitution(1.0f);
		hudBody->addShape(shape3);

		Point vert4[4] = { Point(-256.00000,-256.00000), Point(-222.00000,-213.00000), Point(-220.00000,-218.00000), Point(-217.00000,-246.00000) };
		auto shape4 = PhysicsShapePolygon::create(vert4, 4);
		shape4->setFriction(0);
		shape4->setRestitution(1.0f);
		hudBody->addShape(shape4);

		Point vert5[5] = { Point(6.00000,165.00000), Point(-6.00000,163.00000), Point(-6.00000,165.00000), Point(20.00000,175.00000), Point(13.00000,167.00000) };
		auto shape5 = PhysicsShapePolygon::create(vert5, 5);
		shape5->setFriction(0);
		shape5->setRestitution(1.0f);
		hudBody->addShape(shape5);

		Point vert6[4] = { Point(-21.00000,176.00000), Point(20.00000,175.00000), Point(-6.00000,165.00000), Point(-13.00000,167.00000) };
		auto shape6 = PhysicsShapePolygon::create(vert6, 4);
		shape6->setFriction(0);
		shape6->setRestitution(1.0f);
		hudBody->addShape(shape6);

		Point vert7[4] = { Point(-234.00000,187.00000), Point(-256.00000,256.00000), Point(-230.00000,193.00000), Point(-230.00000,191.00000) };
		auto shape7 = PhysicsShapePolygon::create(vert7, 4);
		shape7->setFriction(0);
		shape7->setRestitution(1.0f);
		hudBody->addShape(shape7);

		Point vert8[3] = { Point(-6.00000,163.00000), Point(6.00000,165.00000), Point(6.00000,163.00000) };
		auto shape8 = PhysicsShapePolygon::create(vert8, 3);
		shape8->setFriction(0);
		shape8->setRestitution(1.0f);
		hudBody->addShape(shape8);

		Point vert9[5] = { Point(-38.00000,183.00000), Point(41.00000,183.00000), Point(20.00000,175.00000), Point(-21.00000,176.00000), Point(-33.00000,179.00000) };
		auto shape9 = PhysicsShapePolygon::create(vert9, 5);
		shape9->setFriction(0);
		shape9->setRestitution(1.0f);
		hudBody->addShape(shape9);

		Point vert10[4] = { Point(-165.00000,188.00000), Point(256.00000,256.00000), Point(-149.00000,187.00000), Point(-161.00000,186.00000) };
		auto shape10 = PhysicsShapePolygon::create(vert10, 4);
		shape10->setFriction(0);
		shape10->setRestitution(1.0f);
		hudBody->addShape(shape10);

		Point vert11[4] = { Point(231.00000,-137.00000), Point(256.00000,-256.00000), Point(229.00000,-156.00000), Point(229.00000,-144.00000) };
		auto shape11 = PhysicsShapePolygon::create(vert11, 4);
		shape11->setFriction(0);
		shape11->setRestitution(1.0f);
		hudBody->addShape(shape11);

		Point vert12[4] = { Point(-229.00000,-156.00000), Point(-256.00000,-256.00000), Point(-231.00000,-137.00000), Point(-229.00000,-144.00000) };
		auto shape12 = PhysicsShapePolygon::create(vert12, 4);
		shape12->setFriction(0);
		shape12->setRestitution(1.0f);
		hudBody->addShape(shape12);

		Point vert13[4] = { Point(-245.00000,159.00000), Point(-256.00000,256.00000), Point(-241.00000,172.00000), Point(-243.00000,162.00000) };
		auto shape13 = PhysicsShapePolygon::create(vert13, 4);
		shape13->setFriction(0);
		shape13->setRestitution(1.0f);
		hudBody->addShape(shape13);

		Point vert14[4] = { Point(233.00000,-116.00000), Point(256.00000,-256.00000), Point(231.00000,-137.00000), Point(231.00000,-124.00000) };
		auto shape14 = PhysicsShapePolygon::create(vert14, 4);
		shape14->setFriction(0);
		shape14->setRestitution(1.0f);
		hudBody->addShape(shape14);

		Point vert15[4] = { Point(-231.00000,-137.00000), Point(-256.00000,-256.00000), Point(-233.00000,-116.00000), Point(-231.00000,-124.00000) };
		auto shape15 = PhysicsShapePolygon::create(vert15, 4);
		shape15->setFriction(0);
		shape15->setRestitution(1.0f);
		hudBody->addShape(shape15);

		Point vert16[3] = { Point(20.00000,175.00000), Point(41.00000,183.00000), Point(38.00000,180.00000) };
		auto shape16 = PhysicsShapePolygon::create(vert16, 3);
		shape16->setFriction(0);
		shape16->setRestitution(1.0f);
		hudBody->addShape(shape16);

		Point vert17[4] = { Point(227.00000,-163.00000), Point(229.00000,-156.00000), Point(256.00000,-256.00000), Point(222.00000,-213.00000) };
		auto shape17 = PhysicsShapePolygon::create(vert17, 4);
		shape17->setFriction(0);
		shape17->setRestitution(1.0f);
		hudBody->addShape(shape17);

		Point vert18[4] = { Point(-256.00000,-256.00000), Point(-229.00000,-156.00000), Point(-227.00000,-163.00000), Point(-222.00000,-213.00000) };
		auto shape18 = PhysicsShapePolygon::create(vert18, 4);
		shape18->setFriction(0);
		shape18->setRestitution(1.0f);
		hudBody->addShape(shape18);

		Point vert19[4] = { Point(238.00000,-52.00000), Point(256.00000,-256.00000), Point(236.00000,-79.00000), Point(236.00000,-62.00000) };
		auto shape19 = PhysicsShapePolygon::create(vert19, 4);
		shape19->setFriction(0);
		shape19->setRestitution(1.0f);
		hudBody->addShape(shape19);

		Point vert20[3] = { Point(-193.00000,190.00000), Point(-165.00000,188.00000), Point(-192.00000,188.00000) };
		auto shape20 = PhysicsShapePolygon::create(vert20, 3);
		shape20->setFriction(0);
		shape20->setRestitution(1.0f);
		hudBody->addShape(shape20);

		Point vert21[4] = { Point(240.00000,-19.00000), Point(256.00000,-256.00000), Point(238.00000,-52.00000), Point(238.00000,-32.00000) };
		auto shape21 = PhysicsShapePolygon::create(vert21, 4);
		shape21->setFriction(0);
		shape21->setRestitution(1.0f);
		hudBody->addShape(shape21);

		Point vert22[4] = { Point(-238.00000,-52.00000), Point(-256.00000,-256.00000), Point(-240.00000,-19.00000), Point(-238.00000,-32.00000) };
		auto shape22 = PhysicsShapePolygon::create(vert22, 4);
		shape22->setFriction(0);
		shape22->setRestitution(1.0f);
		hudBody->addShape(shape22);

		Point vert23[4] = { Point(236.00000,-79.00000), Point(256.00000,-256.00000), Point(233.00000,-116.00000), Point(233.00000,-102.00000) };
		auto shape23 = PhysicsShapePolygon::create(vert23, 4);
		shape23->setFriction(0);
		shape23->setRestitution(1.0f);
		hudBody->addShape(shape23);

		Point vert24[3] = { Point(-227.00000,193.00000), Point(-193.00000,190.00000), Point(-216.00000,191.00000) };
		auto shape24 = PhysicsShapePolygon::create(vert24, 3);
		shape24->setFriction(0);
		shape24->setRestitution(1.0f);
		hudBody->addShape(shape24);

		Point vert25[4] = { Point(-256.00000,-256.00000), Point(-238.00000,-52.00000), Point(-236.00000,-62.00000), Point(-233.00000,-116.00000) };
		auto shape25 = PhysicsShapePolygon::create(vert25, 4);
		shape25->setFriction(0);
		shape25->setRestitution(1.0f);
		hudBody->addShape(shape25);

		Point vert26[3] = { Point(240.00000,-19.00000), Point(256.00000,256.00000), Point(256.00000,-256.00000) };
		auto shape26 = PhysicsShapePolygon::create(vert26, 3);
		shape26->setFriction(0);
		shape26->setRestitution(1.0f);
		hudBody->addShape(shape26);

		Point vert27[6] = { Point(80.00000,183.00000), Point(-38.00000,183.00000), Point(-149.00000,187.00000), Point(256.00000,256.00000), Point(230.00000,192.00000), Point(156.00000,186.00000) };
		auto shape27 = PhysicsShapePolygon::create(vert27, 6);
		shape27->setFriction(0);
		shape27->setRestitution(1.0f);
		hudBody->addShape(shape27);

		Point vert28[4] = { Point(-256.00000,256.00000), Point(-245.00000,112.00000), Point(-240.00000,-19.00000), Point(-256.00000,-256.00000) };
		auto shape28 = PhysicsShapePolygon::create(vert28, 4);
		shape28->setFriction(0);
		shape28->setRestitution(1.0f);
		hudBody->addShape(shape28);

		Point vert29[3] = { Point(-256.00000,256.00000), Point(-245.00000,159.00000), Point(-245.00000,112.00000) };
		auto shape29 = PhysicsShapePolygon::create(vert29, 3);
		shape29->setFriction(0);
		shape29->setRestitution(1.0f);
		hudBody->addShape(shape29);

		Point vert30[3] = { Point(-256.00000,256.00000), Point(-234.00000,187.00000), Point(-241.00000,172.00000) };
		auto shape30 = PhysicsShapePolygon::create(vert30, 3);
		shape30->setFriction(0);
		shape30->setRestitution(1.0f);
		hudBody->addShape(shape30);

		Point vert31[4] = { Point(256.00000,256.00000), Point(-227.00000,193.00000), Point(-230.00000,193.00000), Point(-256.00000,256.00000) };
		auto shape31 = PhysicsShapePolygon::create(vert31, 4);
		shape31->setFriction(0);
		shape31->setRestitution(1.0f);
		hudBody->addShape(shape31);

		Point vert32[3] = { Point(-149.00000,187.00000), Point(-38.00000,183.00000), Point(-130.00000,185.00000) };
		auto shape32 = PhysicsShapePolygon::create(vert32, 3);
		shape32->setFriction(0);
		shape32->setRestitution(1.0f);
		hudBody->addShape(shape32);

		Point vert33[3] = { Point(-227.00000,193.00000), Point(256.00000,256.00000), Point(-165.00000,188.00000) };
		auto shape33 = PhysicsShapePolygon::create(vert33, 3);
		shape33->setFriction(0);
		shape33->setRestitution(1.0f);
		hudBody->addShape(shape33);

		Point vert34[3] = { Point(245.00000,159.00000), Point(256.00000,256.00000), Point(243.00000,47.00000) };
		auto shape34 = PhysicsShapePolygon::create(vert34, 3);
		shape34->setFriction(0);
		shape34->setRestitution(1.0f);
		hudBody->addShape(shape34);

		Point vert35[3] = { Point(239.00000,177.00000), Point(256.00000,256.00000), Point(245.00000,159.00000) };
		auto shape35 = PhysicsShapePolygon::create(vert35, 3);
		shape35->setFriction(0);
		shape35->setRestitution(1.0f);
		hudBody->addShape(shape35);

		Point vert36[3] = { Point(230.00000,192.00000), Point(256.00000,256.00000), Point(239.00000,177.00000) };
		auto shape36 = PhysicsShapePolygon::create(vert36, 3);
		shape36->setFriction(0);
		shape36->setRestitution(1.0f);
		hudBody->addShape(shape36);

		hud->setPhysicsBody(hudBody);
		hud->getPhysicsBody()->setDynamic(false);
		hud->getPhysicsBody()->setCategoryBitmask(0x0001);
		hud->getPhysicsBody()->setCollisionBitmask(0x0001);
		hud->getPhysicsBody()->setContactTestBitmask(0x0001);
	}

	hud->setTag(6);
	hud->setScale(1.872f, 1.25f);
	hud->setAnchorPoint(Vec2(0, 0));
	hud->setPosition(Vec2(0, 0));

	addChild(hud);
}

void BackGround::addEdges() {
	auto ground = Sprite::create();
	auto groundBody = PhysicsBody::createBox(Size(960, 0));
	groundBody->getShape(0)->setRestitution(1.0f);
	groundBody->getShape(0)->setFriction(1.0f);
	groundBody->setCategoryBitmask(0x0001);
	groundBody->setCollisionBitmask(0x0001);
	groundBody->setContactTestBitmask(0x0001);
	groundBody->setDynamic(false);
	ground->setAnchorPoint(Vec2(0.5, 0));
	ground->setPosition(Vec2(480, 0));
	ground->setPhysicsBody(groundBody);
	ground->setTag(10);
	ground->setVisible(false);
	addChild(ground);
}

void BackGround::addPaddle2() {
	auto *paddle2_1 = Sprite::create("imgs/Paddle2_1.png");
	auto *paddle2_2 = Sprite::create("imgs/Paddle2_1.png");
	auto *paddle2_3 = Sprite::create("imgs/Paddle2_1.png");
	auto *paddle2_4 = Sprite::create("imgs/Paddle2_1.png");

	auto paddleBody1 = PhysicsBody::createBox(paddle2_1->getContentSize());
	paddleBody1->getShape(0)->setRestitution(1.0f);
	paddleBody1->getShape(0)->setFriction(0);
	paddleBody1->setCategoryBitmask(0x0001);
	paddleBody1->setCollisionBitmask(0x0001);
	paddleBody1->setContactTestBitmask(0x0001);
	paddleBody1->setDynamic(false);

	auto paddleBody2 = PhysicsBody::createBox(paddle2_1->getContentSize());
	paddleBody2->getShape(0)->setRestitution(1.0f);
	paddleBody2->getShape(0)->setFriction(0);
	paddleBody2->setCategoryBitmask(0x0001);
	paddleBody2->setCollisionBitmask(0x0001);
	paddleBody2->setContactTestBitmask(0x0001);
	paddleBody2->setDynamic(false);

	auto paddleBody3 = PhysicsBody::createBox(paddle2_1->getContentSize());
	paddleBody3->getShape(0)->setRestitution(1.0f);
	paddleBody3->getShape(0)->setFriction(0);
	paddleBody3->setCategoryBitmask(0x0001);
	paddleBody3->setCollisionBitmask(0x0001);
	paddleBody3->setContactTestBitmask(0x0001);
	paddleBody3->setDynamic(false);

	auto paddleBody4 = PhysicsBody::createBox(paddle2_1->getContentSize());
	paddleBody4->getShape(0)->setRestitution(1.0f);
	paddleBody4->getShape(0)->setFriction(0);
	paddleBody4->setCategoryBitmask(0x0001);
	paddleBody4->setCollisionBitmask(0x0001);
	paddleBody4->setContactTestBitmask(0x0001);
	paddleBody4->setDynamic(false);

	paddle2_1->setPhysicsBody(paddleBody1);
	paddle2_2->setPhysicsBody(paddleBody2);
	paddle2_3->setPhysicsBody(paddleBody3);
	paddle2_4->setPhysicsBody(paddleBody4);

	paddle2_1->setAnchorPoint(Vec2(1, 0));
	paddle2_1->setRotation(-93.30f);
	paddle2_1->setScaleY(1.5f);
	paddle2_1->setPosition(70.6, 482.21);

	paddle2_2->setAnchorPoint(Vec2(1, 0));
	paddle2_2->setRotation(-96.53);
	paddle2_2->setScaleY(1.43);
	paddle2_2->setPosition(73.6, 329.72);

	paddle2_3->setAnchorPoint(Vec2(0, 0));
	paddle2_3->setRotation(92.87f);
	paddle2_3->setScaleY(1.5f);
	paddle2_3->setPosition(890.63, 482.21);

	paddle2_4->setAnchorPoint(Vec2(0, 0));
	paddle2_4->setRotation(94.46f);
	paddle2_4->setScaleY(1.4269f);
	paddle2_4->setPosition(885.71, 329.72);

	paddle2_1->setTag(5); paddle2_2->setTag(5); paddle2_3->setTag(5); paddle2_4->setTag(5);

	addChild(paddle2_1);
	addChild(paddle2_2);
	addChild(paddle2_3);
	addChild(paddle2_4);
}
//void BackGround::update(float f) {
//	Node::update(f);
//	auto rect = bg->getTextureRect();
//	rect.origin.x += 100.0f * f;
//	rect.origin.y += 100.0f * f;
//	bg->setTextureRect(rect);
//}
