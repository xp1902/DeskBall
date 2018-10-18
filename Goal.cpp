#include "Goal.h"

Goal::Goal() {

}
Goal::~Goal() {

}
bool Goal::init() {
	Sprite::initWithFile("imgs/goal.png");
	
	auto playerPhysicsBody = PhysicsBody::createBox(getContentSize());
	setPhysicsBody(playerPhysicsBody);
	playerPhysicsBody->getShape(0)->setFriction(0);
	playerPhysicsBody->getShape(0)->setRestitution(1.0f);

	this->getPhysicsBody()->setCategoryBitmask(0x0001);
	this->getPhysicsBody()->setCollisionBitmask(0x0001);
	this->getPhysicsBody()->setContactTestBitmask(0x0001);

	this->getPhysicsBody()->setDynamic(false);
	return true;
}

Obstruct::Obstruct() {

}
Obstruct::~Obstruct() {

}
bool Obstruct::init() {
	Sprite::initWithFile("imgs/Obstruct.png");

	auto playerPhysicsBody = PhysicsBody::createBox(getContentSize());
	this->setPhysicsBody(playerPhysicsBody);
	playerPhysicsBody->getShape(0)->setFriction(0);
	playerPhysicsBody->getShape(0)->setRestitution(1.01f);

	this->getPhysicsBody()->setCategoryBitmask(0x0001);
	this->getPhysicsBody()->setCollisionBitmask(0x0001);
	this->getPhysicsBody()->setContactTestBitmask(0x0001);

	this->getPhysicsBody()->setDynamic(false);
	return true;
}

Icebug::Icebug() {

}
Icebug::~Icebug() {

}
bool Icebug::init() {
	Sprite::initWithFile("imgs/Icebug.png");

	auto playerPhysicsBody = PhysicsBody::createBox(getContentSize());
	this->setPhysicsBody(playerPhysicsBody);
	playerPhysicsBody->getShape(0)->setFriction(0);
	playerPhysicsBody->getShape(0)->setRestitution(1.0f);

	this->getPhysicsBody()->setCategoryBitmask(0x0001);
	this->getPhysicsBody()->setCollisionBitmask(0x0001);
	this->getPhysicsBody()->setContactTestBitmask(0x0001);

	this->getPhysicsBody()->setDynamic(false);
	return true;
}

Gift::Gift()
{
}
Gift::~Gift()
{
}
bool Gift::init() {
	Sprite::initWithFile("imgs/gift.png");

	auto playerPhysicsBody = PhysicsBody::createBox(getContentSize());
	this->setPhysicsBody(playerPhysicsBody);
	playerPhysicsBody->getShape(0)->setFriction(0);
	playerPhysicsBody->getShape(0)->setRestitution(1.0f);
	return true;
}

Bomb::Bomb()
{
}
Bomb::~Bomb()
{
}
bool Bomb::init() {
	Sprite::initWithFile("imgs/bomb.png");

	auto playerPhysicsBody = PhysicsBody::createBox(getContentSize());
	this->setPhysicsBody(playerPhysicsBody);
	playerPhysicsBody->getShape(0)->setFriction(0);
	playerPhysicsBody->getShape(0)->setRestitution(1.0f);
	return true;
}


Candy::Candy()
{
}
Candy::~Candy()
{
}
bool Candy::init()
{
	if (!Sprite::init()) {
		return false;
	}
	Sprite::initWithFile("imgs/candy.png");

	auto playerPhysicsBody = PhysicsBody::createBox(getContentSize());
	this->setPhysicsBody(playerPhysicsBody);
	playerPhysicsBody->getShape(0)->setFriction(0);
	playerPhysicsBody->getShape(0)->setRestitution(1.0f);
	return true;
}