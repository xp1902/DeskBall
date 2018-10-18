#include "SlideBar.h"

SlideBar::SlideBar() :_pectage(0) {

}
SlideBar::~SlideBar() {

}
bool SlideBar::init() {
	if (!Node::init()) {
		return false;
	}
	//_progress = ProgressTimer::create(Sprite::create("menu_bar.png"));
	//_progress->setMidpoint(Vec2(0, 0));
	//_progress->setBarChangeRate(Vec2(1, 0));

	_bg = Sprite::create("menu_bar.png");
	this->addChild(_bg);
	//this->addChild(_progress);

	this->setContentSize(_bg->getContentSize());
	return true;

}
void SlideBar::updateView(int value) {

}