#include "Bricks.h"

Brick1::~Brick1() {

}
Brick1::Brick1() {

}
bool Brick1::init() {
	Sprite::initWithFile("imgs/brick1.png");

	this ->setScale(0.5, 0.5);

	auto playerPhysicsBody = PhysicsBody::createBox(getContentSize());
	this -> setPhysicsBody(playerPhysicsBody);
	playerPhysicsBody->getShape(0)->setFriction(0);
	playerPhysicsBody->getShape(0)->setRestitution(1.0f);

	this->getPhysicsBody()->setCategoryBitmask(0x0001);
	this->getPhysicsBody()->setCollisionBitmask(0x0001);
	this->getPhysicsBody()->setContactTestBitmask(0x0001);

	this->getPhysicsBody()->setDynamic(false);
	return true;
}

Brick2::~Brick2() {

}
Brick2::Brick2() {

}
bool Brick2::init() {
	Sprite::initWithFile("imgs/brick2.png");

	this->setScale(0.5, 0.5);

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

Brick3::~Brick3() {

}
Brick3::Brick3() {

}
bool Brick3::init() {
	Sprite::initWithFile("imgs/brick3.png");

	this->setScale(0.5, 0.5);

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

Brick4::~Brick4() {

}
Brick4::Brick4() {

}
bool Brick4::init() {
	Sprite::initWithFile("imgs/brick4.png");

	this->setScale(0.5, 0.5);

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

Brick5::~Brick5() {

}
Brick5::Brick5() {

}
bool Brick5::init() {
	Sprite::initWithFile("imgs/brick5.png");

	this->setScale(0.5, 0.5);

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

Brick6::~Brick6() {

}
Brick6::Brick6() {

}
bool Brick6::init() {
	Sprite::initWithFile("imgs/brick6.png");

	this->setScale(0.5, 0.5);

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