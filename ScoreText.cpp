#include "ScoreText.h"

ScoreText::ScoreText()
{
}

ScoreText::~ScoreText()
{
}

bool ScoreText::init() {
	if (!Node::init()) {
		return false;
	}
	_text = ui::TextAtlas::create("0", "imgs/numbers2.png", 55, 51, "0");
	_text->setAnchorPoint(Vec2(0.5, 0.5));
	addChild(_text);
	scheduleUpdate();
	return true;
}

void ScoreText::set_text(int value) {
	_text->setString(StringUtils::format("%d", value));
}