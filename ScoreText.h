#pragma once
#include <stdio.h>
#include "ui/CocosGUI.h"
#include "cocos2d.h"
USING_NS_CC;

class ScoreText: public Node
{
public:
	ScoreText();
	~ScoreText();
	CREATE_FUNC(ScoreText);
	virtual bool init();
	void set_text(int value);
protected:
	ui::TextAtlas* _text;
};
