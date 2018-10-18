#include "DBLevel.h"
#include "Bricks.h"
#include "Goal.h"

DBLevel::DBLevel() {

}
DBLevel::~DBLevel() {
	this->removeAllChildren();
}

DBLevel* DBLevel::create(LevelData levelData) {
	DBLevel* dbl = new DBLevel();
	
	if (dbl && dbl->initWithLevelData(levelData)) {
		dbl->autorelease();
		return dbl;
	}
	CC_SAFE_FREE(dbl);
	return nullptr;
}

bool DBLevel::initWithLevelData(LevelData leveldata) {
	if (!Layer::init()) {
		return false;
	}
	_levelData = leveldata;
	switch (leveldata.levelS)
	{
	case 1: initLevel01BrickLayout(); break;
	case 2: initLevel02BrickLayout(); break;
	case 3: initLevel03BrickLayout(); break;
	case 4: initLevel04BrickLayout(); break;
	case 5: initLevel05BrickLayout(); break;
	case 6: initLevel06BrickLayout(); break;
	case 7: initLevel07BrickLayout(); break;
	case 8: initLevel08BrickLayout(); break;
	case 9: initLevel09BrickLayout(); break;
	}
	return true;
}

void DBLevel::initLevel03BrickLayout() {
	int space = 10;
		for (int row = 0; row < 2; row++) {
			for (int column = 0; column < _levelData.columns; column++) {
				Brick1* brick = Brick1::create();

				int space = 10;
				auto size = brick->getContentSize();

				brick->setPosition(Vec2(
					(size.width/2 + space) * column + size.width / 2,
					(size.height/2 + space) * row + size.height / 2
				));
				if (column % 2 == 0) {
					brick->setTag(2);
				}
				else if (column % 3 == 0 && row % 2 == 0) {
					brick->setTag(1000);
				}
				else if (column % 3 == 0 && row % 3 == 0) {
					brick->setTag(3000);
				}
				else brick->setTag(20);
				this->addChild(brick);
				}
			}

		for (int row = 2; row < 4; row++) {
			for (int column = 0; column < _levelData.columns; column++) {
				Brick2* brick = Brick2::create();

				int space = 10;
				auto size = brick->getContentSize();

				brick->setPosition(Vec2(
					(size.width / 2 + space) * column + size.width / 2,
					(size.height / 2 + space) * row + size.height / 2
				));
				if (column % 2 == 0) {
					brick->setTag(2);
				}
				else if (column % 3 == 0 && row % 2 == 0) {
					brick->setTag(1000);
				}
				else if (column % 3 == 0 && row % 3 == 0) {
					brick->setTag(3000);
				}
				else brick->setTag(20);
				this->addChild(brick);
			}
		}

		for (int row = 4; row < 6; row++) {
			for (int column = 0; column < _levelData.columns; column++) {
				if (column != 1 && column != 2 && column != 4 && column != 5 && column != 7 && column != 8) {
					Brick3* brick = Brick3::create();

					auto size = brick->getContentSize();

					brick->setPosition(Vec2(
						(size.width / 2 + space) * column + size.width / 2,
						(size.height / 2 + space) * row + size.height / 2
					));
					if (column % 2 == 0) {
						brick->setTag(2);
					}
					else if (column % 3 == 0 && row % 2 == 0) {
						brick->setTag(1000);
					}
					else if (column % 3 == 0 && row % 3 == 0) {
						brick->setTag(3000);
					}
					else brick->setTag(20);
					this->addChild(brick);
				}
			}
		}

		for (int row = 6; row < _levelData.rows; row++) {
			for (int column = 0; column < _levelData.columns; column++) {
				if (column != 5 && column != 4) {
					Brick4* brick = Brick4::create();

					int space = 10;
					auto size = brick->getContentSize();

					brick->setPosition(Vec2(
						(size.width / 2 + space) * column + size.width / 2,
						(size.height / 2 + space) * row + size.height / 2
					));
					if (column % 2 == 0) {
						brick->setTag(2);
					}
					else if (column % 3 == 0 && row % 2 == 0) {
						brick->setTag(1000);
					}
					else if (column % 3 == 0 && row % 3 == 0) {
						brick->setTag(3000);
					}
					else brick->setTag(20);
					this->addChild(brick);

					if (column == _levelData.columns - 1 && row == _levelData.rows - 1) {
						this->setContentSize(Size((size.width + space) * column + size.width, (size.height + space) * row + size.height));
					}
				}
			}
		}

		//add3 goal
		{
			Goal* goal1 = Goal::create();
			goal1->setPosition(Vec2(620, 220));
			Goal* goal2 = Goal::create();
			goal2->setPosition(Vec2(180, 220));
			Goal* goal3 = Goal::create();
			goal3->setPosition(Vec2(400, 220));

			CCActionInterval * orbitcamera1 = CCOrbitCamera::create(1.4, 1, 0, 0, 360, 0, 0);
			CCActionInterval * orbitcamera2 = CCOrbitCamera::create(1.4, 1, 0, 0, 360, 0, 0);
			CCActionInterval * orbitcamera3 = CCOrbitCamera::create(1.4, 1, 0, 0, 360, 0, 0);
			goal1->runAction(RepeatForever::create(orbitcamera1));
			goal2->runAction(RepeatForever::create(orbitcamera2));
			goal3->runAction(RepeatForever::create(orbitcamera3));

			goal1->setTag(3);
			goal2->setTag(3);
			goal3->setTag(3);
			this->addChild(goal3);
			this->addChild(goal1);
			this->addChild(goal2);
		}
}

void DBLevel::initLevel01BrickLayout() {
	int space = 10;

	for (int row = 0; row < 2; row++) {
		for (int column = 0; column < _levelData.columns; column++) {
			Brick1* brick = Brick1::create();

			int space = 10;
			auto size = brick->getContentSize();

			brick->setPosition(Vec2(
				(size.width / 2 + space) * column + size.width / 2,
				(size.height / 2 + space) * row + size.height / 2
			));
			if (column % 2 == 0) {
				brick->setTag(2);
			}
			else if (column % 3 == 0 && row % 3 == 0) {
				brick->setTag(3000);
			}
			else if (column % 3 == 0 && row % 2 == 0) {
				brick->setTag(1000);
			}
			else brick->setTag(20);
			this->addChild(brick);
		}
	}

	for (int row = 2; row < 4; row++) {
		for (int column = 0; column < _levelData.columns; column++) {
				if (column != 1 && column != 8) {
					Brick2* brick = Brick2::create();

					int space = 10;
					auto size = brick->getContentSize();

					brick->setPosition(Vec2(
						(size.width / 2 + space) * column + size.width / 2,
						(size.height / 2 + space) * row + size.height / 2
					));
					if (column % 2 == 0) {
						brick->setTag(2);
					}
					else if (column % 3 == 0 && row % 3 == 0) {
						brick->setTag(3000);
					}
					else if (column % 3 == 0 && row % 2 == 0) {
						brick->setTag(1000);
					}
					else brick->setTag(20);
					this->addChild(brick);
				}
		}
	}

	for (int row = 4; row < 6; row++) {
		for (int column = 0; column < _levelData.columns; column++) {
			if (column != 1 && column != 8 && column != 4 && column != 5) {
				Brick3* brick = Brick3::create();

				auto size = brick->getContentSize();

				brick->setPosition(Vec2(
					(size.width / 2 + space) * column + size.width / 2,
					(size.height / 2 + space) * row + size.height / 2
				));
				if (column % 2 == 0) {
					brick->setTag(2);
				}
				else if (column % 3 == 0 && row % 3 == 0) {
					brick->setTag(3000);
				}
				else if (column % 4 == 3 && row % 2 == 0) {
					brick->setTag(1000);
				}
				else brick->setTag(20);
				this->addChild(brick);
			}
		}
	}

	for (int row = 6; row < _levelData.rows; row++) {
		for (int column = 0; column < _levelData.columns; column++) {
				Brick4* brick = Brick4::create();

				int space = 10;
				auto size = brick->getContentSize();

				brick->setPosition(Vec2(
					(size.width / 2 + space) * column + size.width / 2,
					(size.height / 2 + space) * row + size.height / 2
				));
				if (column % 2 == 0) {
					brick->setTag(2);
				}
				else if (column % 3 == 0 && row % 3 == 0) {
					brick->setTag(3000);
				}
				else if (column % 4 == 3 && row % 2 == 0) {
					brick->setTag(1000);
				}
				else brick->setTag(20);
				this->addChild(brick);

				if (column == _levelData.columns - 1 && row == _levelData.rows - 1) {
					this->setContentSize(Size((size.width + space) * column + size.width, (size.height + space) * row + size.height));
				}
			}
	}

	//add 3 goals
	{
		Goal* goal1 = Goal::create();
		//goal1->setPosition(Vec2(660, 250));
		Goal* goal2 = Goal::create();
		/*goal2->setPosition(Vec2(140, 220));*/
		Goal* goal3 = Goal::create();
		goal3->setPosition(Vec2(400, 220));

		CCActionInterval * orbitcamera1 = CCOrbitCamera::create(1.4, 1, 0, 0, 360, 0, 0);
		goal2->runAction(RepeatForever::create(Spawn::create(
			Sequence::create(MoveTo::create(0.7f, Vec2(140, 250)),
				MoveTo::create(0.7f, Vec2(140, 100)),
				MoveTo::create(0.7f, Vec2(140, 250)),
				NULL), orbitcamera1, NULL)));
		CCActionInterval * orbitcamera2 = CCOrbitCamera::create(1.4, 1, 0, 0, 360, 0, 0);
		goal1->runAction(RepeatForever::create(Spawn::create(
			Sequence::create(MoveTo::create(0.7f, Vec2(660, 250)),
				MoveTo::create(0.7f, Vec2(660, 100)),
				MoveTo::create(0.7f, Vec2(660, 250)),
				NULL), orbitcamera2, NULL)));
		CCActionInterval * orbitcamera3 = CCOrbitCamera::create(1, 1, 0, 0, 360, 0, 0);
		goal3->runAction(RepeatForever::create( orbitcamera3));

		goal1->setTag(3);
		goal2->setTag(3);
		goal3->setTag(3);
		this->addChild(goal3);
		this->addChild(goal1);
		this->addChild(goal2);
	}
	//add 2 obstructs
	{
		Obstruct* ob1 = Obstruct::create();
		Obstruct* ob2 = Obstruct::create();
		ob1->setPosition(Vec2(0, 0));
		ob2->setPosition(Vec2(800, 0));
		ob1->setTag(4);
		ob2->setTag(4);
		this->addChild(ob1);
		this->addChild(ob2);
	}
}

void DBLevel::initLevel02BrickLayout() {
	int space = 10;

	for (int row = 0; row < 2; row++) {
		for (int column = 0; column < _levelData.columns; column++) {
			Brick1* brick = Brick1::create();

			int space = 10;
			auto size = brick->getContentSize();

			brick->setPosition(Vec2(
				(size.width / 2 + space) * column + size.width / 2,
				(size.height / 2 + space) * row + size.height / 2
			));
			if (column % 2 == 0) {
				brick->setTag(2);
			}
			else if (column % 3 == 0 && row % 3 == 0) {
				brick->setTag(3000);
			}
			else if (column % 3 == 0 && row % 2 == 0) {
				brick->setTag(1000);
			}
			else brick->setTag(20);
			this->addChild(brick);
		}
	}

	for (int row = 2; row < 4; row++) {
		for (int column = 0; column < _levelData.columns; column++) {
			if (column != 1 && column != 8) {
				Brick2* brick = Brick2::create();

				int space = 10;
				auto size = brick->getContentSize();

				brick->setPosition(Vec2(
					(size.width / 2 + space) * column + size.width / 2,
					(size.height / 2 + space) * row + size.height / 2
				));
				if (column % 2 == 0) {
					brick->setTag(2);
				}
				else if (column % 3 == 0 && row % 3 == 0) {
					brick->setTag(3000);
				}
				else if (column % 3 == 0 && row % 2 == 0) {
					brick->setTag(1000);
				}
				else brick->setTag(20);
				this->addChild(brick);
			}
		}
	}

	for (int row = 4; row < 6; row++) {
		for (int column = 0; column < _levelData.columns; column++) {
			if (column != 1 && column != 8 && column != 4 && column != 5) {
				Brick3* brick = Brick3::create();

				auto size = brick->getContentSize();

				brick->setPosition(Vec2(
					(size.width / 2 + space) * column + size.width / 2,
					(size.height / 2 + space) * row + size.height / 2
				));
				if (column % 2 == 0) {
					brick->setTag(2);
				}
				else if (column % 3 == 0 && row % 3 == 0) {
					brick->setTag(3000);
				}
				else if (column % 3 == 0 && row % 2 == 0) {
					brick->setTag(1000);
				}
				else brick->setTag(20);
				this->addChild(brick);
			}
		}
	}

	for (int row = 6; row < _levelData.rows; row++) {
		for (int column = 0; column < _levelData.columns; column++) {
			Brick4* brick = Brick4::create();

			int space = 10;
			auto size = brick->getContentSize();

			brick->setPosition(Vec2(
				(size.width / 2 + space) * column + size.width / 2,
				(size.height / 2 + space) * row + size.height / 2
			));
			if (column % 2 == 0) {
				brick->setTag(2);
			}
			else if (column % 3 == 0 && row % 3 == 0) {
				brick->setTag(3000);
			}
			else if (column % 3 == 0 && row % 2 == 0) {
				brick->setTag(1000);
			}
			else brick->setTag(20);
			this->addChild(brick);

			if (column == _levelData.columns - 1 && row == _levelData.rows - 1) {
				this->setContentSize(Size((size.width + space) * column + size.width, (size.height + space) * row + size.height));
			}
		}
	}

	//add 3 goals
	{
		Goal* goal1 = Goal::create();
		//goal1->setPosition(Vec2(660, 250));
		Goal* goal2 = Goal::create();
		/*goal2->setPosition(Vec2(140, 220));*/
		Goal* goal3 = Goal::create();
		goal3->setPosition(Vec2(400, 220));

		CCActionInterval * orbitcamera1 = CCOrbitCamera::create(1.4, 1, 0, 0, 360, 0, 0);
		goal2->runAction(RepeatForever::create(Spawn::create(
			Sequence::create(MoveTo::create(0.7f, Vec2(140, 250)),
				MoveTo::create(0.7f, Vec2(140, 100)),
				MoveTo::create(0.7f, Vec2(140, 250)),
				NULL), orbitcamera1, NULL)));
		CCActionInterval * orbitcamera2 = CCOrbitCamera::create(1.4, 1, 0, 0, 360, 0, 0);
		goal1->runAction(RepeatForever::create(Spawn::create(
			Sequence::create(MoveTo::create(0.7f, Vec2(660, 250)),
				MoveTo::create(0.7f, Vec2(660, 100)),
				MoveTo::create(0.7f, Vec2(660, 250)),
				NULL), orbitcamera2, NULL)));
		CCActionInterval * orbitcamera3 = CCOrbitCamera::create(1, 1, 0, 0, 360, 0, 0);
		goal3->runAction(RepeatForever::create(orbitcamera3));

		goal1->setTag(3);
		goal2->setTag(3);
		goal3->setTag(3);
		this->addChild(goal3);
		this->addChild(goal1);
		this->addChild(goal2);
	}
	//add 2 obstructs
	{
		Obstruct* ob1 = Obstruct::create();
		Obstruct* ob2 = Obstruct::create();
		ob1->setPosition(Vec2(0, 0));
		ob2->setPosition(Vec2(800, 0));
		ob1->setTag(4);
		ob2->setTag(4);
		this->addChild(ob1);
		this->addChild(ob2);
	}
	{
		for (int i = 0; i < 3; i++) {
			Icebug* ib1 = Icebug::create();
			ib1->setPosition(Vec2(50 + i * 40, 0));
			Icebug* ib2 = Icebug::create();
			ib2->setPosition(Vec2(750 - i * 40, 0));
			ib1->setTag(7);
			ib2->setTag(7);
			this->addChild(ib1);
			this->addChild(ib2);
		}
	}
}

void DBLevel::initLevel04BrickLayout() {
	int space = 10;

	for (int row = 0; row < 2; row++) {
		for (int column = 0; column < _levelData.columns; column++) {
			Brick1* brick = Brick1::create();

			int space = 10;
			auto size = brick->getContentSize();

			brick->setPosition(Vec2(
				(size.width / 2 + space) * column + size.width / 2,
				(size.height / 2 + space) * row + size.height / 2
			));
			if (column % 2 == 0) {
				brick->setTag(2);
			}
			else if (column % 3 == 0 && row % 3 == 0) {
				brick->setTag(3000);
			}
			else if (column % 4 == 0 && row % 4 == 0) {
				brick->setTag(1000);
			}
			else brick->setTag(20);
			this->addChild(brick);
		}
	}

	for (int row = 2; row < 4; row++) {
		for (int column = 0; column < _levelData.columns; column++) {
			if (column != 1 && column != 8) {
				Brick2* brick = Brick2::create();

				int space = 10;
				auto size = brick->getContentSize();

				brick->setPosition(Vec2(
					(size.width / 2 + space) * column + size.width / 2,
					(size.height / 2 + space) * row + size.height / 2
				));
				if (column % 2 == 0) {
					brick->setTag(2);
				}
				else if (column % 3 == 0 && row % 3 == 0) {
					brick->setTag(3000);
				}
				else if (column % 4 == 0 && row % 4 == 0) {
					brick->setTag(1000);
				}
				else brick->setTag(20);
				this->addChild(brick);
			}
		}
	}

	for (int row = 4; row < 6; row++) {
		for (int column = 0; column < _levelData.columns; column++) {
			if (column != 1 && column != 8 && column != 4 && column != 5) {
				Brick3* brick = Brick3::create();

				auto size = brick->getContentSize();

				brick->setPosition(Vec2(
					(size.width / 2 + space) * column + size.width / 2,
					(size.height / 2 + space) * row + size.height / 2
				));
				if (column % 2 == 0) {
					brick->setTag(2);
				}
				else if (column % 3 == 0 && row % 3 == 0) {
					brick->setTag(3000);
				}
				else if (column % 4 == 0 && row % 4 == 0) {
					brick->setTag(1000);
				}
				else brick->setTag(20);
				this->addChild(brick);
			}
		}
	}

	for (int row = 6; row < _levelData.rows; row++) {
		for (int column = 0; column < _levelData.columns; column++) {
			Brick4* brick = Brick4::create();

			int space = 10;
			auto size = brick->getContentSize();

			brick->setPosition(Vec2(
				(size.width / 2 + space) * column + size.width / 2,
				(size.height / 2 + space) * row + size.height / 2
			));
			if (column % 2 == 0) {
				brick->setTag(2);
			}
			else if (column % 3 == 0 && row % 3 == 0) {
				brick->setTag(3000);
			}
			else if (column % 4 == 0 && row % 4 == 0) {
				brick->setTag(1000);
			}
			else brick->setTag(20);
			this->addChild(brick);

			if (column == _levelData.columns - 1 && row == _levelData.rows - 1) {
				this->setContentSize(Size((size.width + space) * column + size.width, (size.height + space) * row + size.height));
			}
		}
	}

	//add 3 goals
	{
		Goal* goal1 = Goal::create();
		//goal1->setPosition(Vec2(660, 250));
		Goal* goal2 = Goal::create();
		/*goal2->setPosition(Vec2(140, 220));*/
		Goal* goal3 = Goal::create();
		goal3->setPosition(Vec2(400, 220));

		CCActionInterval * orbitcamera1 = CCOrbitCamera::create(1.4, 1, 0, 0, 360, 0, 0);
		goal2->runAction(RepeatForever::create(Spawn::create(
			Sequence::create(MoveTo::create(0.7f, Vec2(140, 250)),
				MoveTo::create(0.7f, Vec2(140, 100)),
				MoveTo::create(0.7f, Vec2(140, 250)),
				NULL), orbitcamera1, NULL)));
		CCActionInterval * orbitcamera2 = CCOrbitCamera::create(1.4, 1, 0, 0, 360, 0, 0);
		goal1->runAction(RepeatForever::create(Spawn::create(
			Sequence::create(MoveTo::create(0.7f, Vec2(660, 250)),
				MoveTo::create(0.7f, Vec2(660, 100)),
				MoveTo::create(0.7f, Vec2(660, 250)),
				NULL), orbitcamera2, NULL)));
		CCActionInterval * orbitcamera3 = CCOrbitCamera::create(1, 1, 0, 0, 360, 0, 0);
		goal3->runAction(RepeatForever::create(orbitcamera3));

		goal1->setTag(3);
		goal2->setTag(3);
		goal3->setTag(3);
		this->addChild(goal3);
		this->addChild(goal1);
		this->addChild(goal2);
	}
	//add 2 obstructs
	{
		Obstruct* ob1 = Obstruct::create();
		Obstruct* ob2 = Obstruct::create();
		ob1->setPosition(Vec2(0, 0));
		ob2->setPosition(Vec2(800, 0));
		ob1->setTag(4);
		ob2->setTag(4);
		this->addChild(ob1);
		this->addChild(ob2);
	}
	{
		for (int i = 0; i < 3; i++) {
			Icebug* ib1 = Icebug::create();
			ib1->setPosition(Vec2(50 + i * 40, 0));
			Icebug* ib2 = Icebug::create();
			ib2->setPosition(Vec2(750 - i * 40, 0));
			ib1->setTag(7);
			ib2->setTag(7);
			this->addChild(ib1);
			this->addChild(ib2);
		}
	}
}

void DBLevel::initLevel05BrickLayout() {
	int space = 10;

	for (int row = 0; row < 2; row++) {
		for (int column = 0; column < _levelData.columns; column++) {
			Brick1* brick = Brick1::create();

			int space = 10;
			auto size = brick->getContentSize();

			brick->setPosition(Vec2(
				(size.width / 2 + space) * column + size.width / 2,
				(size.height / 2 + space) * row + size.height / 2
			));
			if (column % 2 == 0) {
				brick->setTag(2);
			}
			else if (column % 3 == 0 && row % 3 == 0) {
				brick->setTag(3000);
			}
			else if (column % 4 == 0 && row % 4 == 0) {
				brick->setTag(1000);
			}
			else brick->setTag(20);
			this->addChild(brick);
		}
	}

	for (int row = 2; row < 4; row++) {
		for (int column = 0; column < _levelData.columns; column++) {
			if (column != 1 && column != 8) {
				Brick2* brick = Brick2::create();

				int space = 10;
				auto size = brick->getContentSize();

				brick->setPosition(Vec2(
					(size.width / 2 + space) * column + size.width / 2,
					(size.height / 2 + space) * row + size.height / 2
				));
				if (column % 2 == 0) {
					brick->setTag(2);
				}
				else if (column % 3 == 0 && row % 3 == 0) {
					brick->setTag(3000);
				}
				else if (column % 4 == 0 && row % 4 == 0) {
					brick->setTag(1000);
				}
				else brick->setTag(20);
				this->addChild(brick);
			}
		}
	}

	for (int row = 4; row < 6; row++) {
		for (int column = 0; column < _levelData.columns; column++) {
			if (column != 1 && column != 8 && column != 4 && column != 5) {
				Brick3* brick = Brick3::create();

				auto size = brick->getContentSize();

				brick->setPosition(Vec2(
					(size.width / 2 + space) * column + size.width / 2,
					(size.height / 2 + space) * row + size.height / 2
				));
				if (column % 2 == 0) {
					brick->setTag(2);
				}
				else if (column % 3 == 0 && row % 3 == 0) {
					brick->setTag(3000);
				}
				else if (column % 4 == 0 && row % 4 == 0) {
					brick->setTag(1000);
				}
				else brick->setTag(20);
				this->addChild(brick);
			}
		}
	}

	for (int row = 6; row < _levelData.rows; row++) {
		for (int column = 0; column < _levelData.columns; column++) {
			Brick4* brick = Brick4::create();

			int space = 10;
			auto size = brick->getContentSize();

			brick->setPosition(Vec2(
				(size.width / 2 + space) * column + size.width / 2,
				(size.height / 2 + space) * row + size.height / 2
			));
			if (column % 2 == 0) {
				brick->setTag(2);
			}
			else if (column % 3 == 0 && row % 3 == 0) {
				brick->setTag(3000);
			}
			else if (column % 4 == 0 && row % 4 == 0) {
				brick->setTag(1000);
			}
			else brick->setTag(20);
			this->addChild(brick);

			if (column == _levelData.columns - 1 && row == _levelData.rows - 1) {
				this->setContentSize(Size((size.width + space) * column + size.width, (size.height + space) * row + size.height));
			}
		}
	}

	//add 3 goals
	{
		Goal* goal1 = Goal::create();
		//goal1->setPosition(Vec2(660, 250));
		Goal* goal2 = Goal::create();
		/*goal2->setPosition(Vec2(140, 220));*/
		Goal* goal3 = Goal::create();
		goal3->setPosition(Vec2(400, 220));

		CCActionInterval * orbitcamera1 = CCOrbitCamera::create(1.4, 1, 0, 0, 360, 0, 0);
		goal2->runAction(RepeatForever::create(Spawn::create(
			Sequence::create(MoveTo::create(0.7f, Vec2(140, 250)),
				MoveTo::create(0.7f, Vec2(140, 100)),
				MoveTo::create(0.7f, Vec2(140, 250)),
				NULL), orbitcamera1, NULL)));
		CCActionInterval * orbitcamera2 = CCOrbitCamera::create(1.4, 1, 0, 0, 360, 0, 0);
		goal1->runAction(RepeatForever::create(Spawn::create(
			Sequence::create(MoveTo::create(0.7f, Vec2(660, 250)),
				MoveTo::create(0.7f, Vec2(660, 100)),
				MoveTo::create(0.7f, Vec2(660, 250)),
				NULL), orbitcamera2, NULL)));
		CCActionInterval * orbitcamera3 = CCOrbitCamera::create(1, 1, 0, 0, 360, 0, 0);
		goal3->runAction(RepeatForever::create(orbitcamera3));

		goal1->setTag(3);
		goal2->setTag(3);
		goal3->setTag(3);
		this->addChild(goal3);
		this->addChild(goal1);
		this->addChild(goal2);
	}
	//add 2 obstructs
	{
		Obstruct* ob1 = Obstruct::create();
		Obstruct* ob2 = Obstruct::create();
		ob1->setPosition(Vec2(0, 0));
		ob2->setPosition(Vec2(800, 0));
		ob1->setTag(4);
		ob2->setTag(4);
		this->addChild(ob1);
		this->addChild(ob2);
	}
	{
		for (int i = 0; i < 3; i++) {
			Icebug* ib1 = Icebug::create();
			ib1->setPosition(Vec2(50 + i * 40, 0));
			Icebug* ib2 = Icebug::create();
			ib2->setPosition(Vec2(750 - i * 40, 0));
			ib1->setTag(7);
			ib2->setTag(7);
			this->addChild(ib1);
			this->addChild(ib2);
		}
	}
}

void DBLevel::initLevel06BrickLayout() {
	int space = 10;

	for (int row = 0; row < 2; row++) {
		for (int column = 0; column < _levelData.columns; column++) {
			Brick1* brick = Brick1::create();

			int space = 10;
			auto size = brick->getContentSize();

			brick->setPosition(Vec2(
				(size.width / 2 + space) * column + size.width / 2,
				(size.height / 2 + space) * row + size.height / 2
			));
			if (column % 2 == 0) {
				brick->setTag(2);
			}
			else brick->setTag(20);
			this->addChild(brick);
		}
	}

	for (int row = 2; row < 4; row++) {
		for (int column = 0; column < _levelData.columns; column++) {
			if (column != 1 && column != 8) {
				Brick2* brick = Brick2::create();

				int space = 10;
				auto size = brick->getContentSize();

				brick->setPosition(Vec2(
					(size.width / 2 + space) * column + size.width / 2,
					(size.height / 2 + space) * row + size.height / 2
				));
				if (column % 2 == 0) {
					brick->setTag(2);
				}
				else brick->setTag(20);
				this->addChild(brick);
			}
		}
	}

	for (int row = 4; row < 6; row++) {
		for (int column = 0; column < _levelData.columns; column++) {
			if (column != 1 && column != 8 && column != 4 && column != 5) {
				Brick3* brick = Brick3::create();

				auto size = brick->getContentSize();

				brick->setPosition(Vec2(
					(size.width / 2 + space) * column + size.width / 2,
					(size.height / 2 + space) * row + size.height / 2
				));
				if (column % 2 == 0) {
					brick->setTag(2);
				}
				else brick->setTag(20);
				this->addChild(brick);
			}
		}
	}

	for (int row = 6; row < _levelData.rows; row++) {
		for (int column = 0; column < _levelData.columns; column++) {
			Brick4* brick = Brick4::create();

			int space = 10;
			auto size = brick->getContentSize();

			brick->setPosition(Vec2(
				(size.width / 2 + space) * column + size.width / 2,
				(size.height / 2 + space) * row + size.height / 2
			));
			if (column % 2 == 0) {
				brick->setTag(2);
			}
			else brick->setTag(20);
			this->addChild(brick);

			if (column == _levelData.columns - 1 && row == _levelData.rows - 1) {
				this->setContentSize(Size((size.width + space) * column + size.width, (size.height + space) * row + size.height));
			}
		}
	}

	//add 3 goals
	{
		Goal* goal1 = Goal::create();
		//goal1->setPosition(Vec2(660, 250));
		Goal* goal2 = Goal::create();
		/*goal2->setPosition(Vec2(140, 220));*/
		Goal* goal3 = Goal::create();
		goal3->setPosition(Vec2(400, 220));

		CCActionInterval * orbitcamera1 = CCOrbitCamera::create(1.4f, 1, 0, 0, 360, 0, 0);
		goal2->runAction(RepeatForever::create(Spawn::create(
			Sequence::create(MoveTo::create(0.7f, Vec2(140, 250)),
				MoveTo::create(0.7f, Vec2(140, 100)),
				MoveTo::create(0.7f, Vec2(140, 250)),
				NULL), orbitcamera1, NULL)));
		CCActionInterval * orbitcamera2 = CCOrbitCamera::create(1.4f, 1, 0, 0, 360, 0, 0);
		goal1->runAction(RepeatForever::create(Spawn::create(
			Sequence::create(MoveTo::create(0.7f, Vec2(660, 250)),
				MoveTo::create(0.7f, Vec2(660, 100)),
				MoveTo::create(0.7f, Vec2(660, 250)),
				NULL), orbitcamera2, NULL)));
		CCActionInterval * orbitcamera3 = CCOrbitCamera::create(1, 1, 0, 0, 360, 0, 0);
		goal3->runAction(RepeatForever::create(orbitcamera3));

		goal1->setTag(3);
		goal2->setTag(3);
		goal3->setTag(3);
		this->addChild(goal3);
		this->addChild(goal1);
		this->addChild(goal2);
	}
	//add 2 obstructs
	{
		Obstruct* ob1 = Obstruct::create();
		Obstruct* ob2 = Obstruct::create();
		ob1->setPosition(Vec2(0, 0));
		ob2->setPosition(Vec2(800, 0));
		ob1->setTag(4);
		ob2->setTag(4);
		this->addChild(ob1);
		this->addChild(ob2);
	}
}

void DBLevel::initLevel07BrickLayout() {
	int space = 10;

	for (int row = 0; row < 2; row++) {
		for (int column = 0; column < _levelData.columns; column++) {
			Brick1* brick = Brick1::create();

			int space = 10;
			auto size = brick->getContentSize();

			brick->setPosition(Vec2(
				(size.width / 2 + space) * column + size.width / 2,
				(size.height / 2 + space) * row + size.height / 2
			));
			if (column % 2 == 0) {
				brick->setTag(2);
			}
			else brick->setTag(20);
			this->addChild(brick);
		}
	}

	for (int row = 2; row < 4; row++) {
		for (int column = 0; column < _levelData.columns; column++) {
			if (column != 1 && column != 8) {
				Brick2* brick = Brick2::create();

				int space = 10;
				auto size = brick->getContentSize();

				brick->setPosition(Vec2(
					(size.width / 2 + space) * column + size.width / 2,
					(size.height / 2 + space) * row + size.height / 2
				));
				if (column % 2 == 0) {
					brick->setTag(2);
				}
				else brick->setTag(20);
				this->addChild(brick);
			}
		}
	}

	for (int row = 4; row < 6; row++) {
		for (int column = 0; column < _levelData.columns; column++) {
			if (column != 1 && column != 8 && column != 4 && column != 5) {
				Brick3* brick = Brick3::create();

				auto size = brick->getContentSize();

				brick->setPosition(Vec2(
					(size.width / 2 + space) * column + size.width / 2,
					(size.height / 2 + space) * row + size.height / 2
				));
				if (column % 2 == 0) {
					brick->setTag(2);
				}
				else brick->setTag(20);
				this->addChild(brick);
			}
		}
	}

	for (int row = 6; row < _levelData.rows; row++) {
		for (int column = 0; column < _levelData.columns; column++) {
			Brick4* brick = Brick4::create();

			int space = 10;
			auto size = brick->getContentSize();

			brick->setPosition(Vec2(
				(size.width / 2 + space) * column + size.width / 2,
				(size.height / 2 + space) * row + size.height / 2
			));
			if (column % 2 == 0) {
				brick->setTag(2);
			}
			else brick->setTag(20);
			this->addChild(brick);

			if (column == _levelData.columns - 1 && row == _levelData.rows - 1) {
				this->setContentSize(Size((size.width + space) * column + size.width, (size.height + space) * row + size.height));
			}
		}
	}

	//add 3 goals
	{
		Goal* goal1 = Goal::create();
		//goal1->setPosition(Vec2(660, 250));
		Goal* goal2 = Goal::create();
		/*goal2->setPosition(Vec2(140, 220));*/
		Goal* goal3 = Goal::create();
		goal3->setPosition(Vec2(400, 220));

		CCActionInterval * orbitcamera1 = CCOrbitCamera::create(1.4f, 1, 0, 0, 360, 0, 0);
		goal2->runAction(RepeatForever::create(Spawn::create(
			Sequence::create(MoveTo::create(0.7f, Vec2(140, 250)),
				MoveTo::create(0.7f, Vec2(140, 100)),
				MoveTo::create(0.7f, Vec2(140, 250)),
				NULL), orbitcamera1, NULL)));
		CCActionInterval * orbitcamera2 = CCOrbitCamera::create(1.4f, 1, 0, 0, 360, 0, 0);
		goal1->runAction(RepeatForever::create(Spawn::create(
			Sequence::create(MoveTo::create(0.7f, Vec2(660, 250)),
				MoveTo::create(0.7f, Vec2(660, 100)),
				MoveTo::create(0.7f, Vec2(660, 250)),
				NULL), orbitcamera2, NULL)));
		CCActionInterval * orbitcamera3 = CCOrbitCamera::create(1, 1, 0, 0, 360, 0, 0);
		goal3->runAction(RepeatForever::create(orbitcamera3));

		goal1->setTag(3);
		goal2->setTag(3);
		goal3->setTag(3);
		this->addChild(goal3);
		this->addChild(goal1);
		this->addChild(goal2);
	}
	//add 2 obstructs
	{
		Obstruct* ob1 = Obstruct::create();
		Obstruct* ob2 = Obstruct::create();
		ob1->setPosition(Vec2(0, 0));
		ob2->setPosition(Vec2(800, 0));
		ob1->setTag(4);
		ob2->setTag(4);
		this->addChild(ob1);
		this->addChild(ob2);
	}
}

void DBLevel::initLevel08BrickLayout() {
	int space = 10;

	for (int row = 0; row < 2; row++) {
		for (int column = 0; column < _levelData.columns; column++) {
			Brick1* brick = Brick1::create();

			int space = 10;
			auto size = brick->getContentSize();

			brick->setPosition(Vec2(
				(size.width / 2 + space) * column + size.width / 2,
				(size.height / 2 + space) * row + size.height / 2
			));
			if (column % 2 == 0) {
				brick->setTag(2);
			}
			else brick->setTag(20);
			this->addChild(brick);
		}
	}

	for (int row = 2; row < 4; row++) {
		for (int column = 0; column < _levelData.columns; column++) {
			if (column != 1 && column != 8) {
				Brick2* brick = Brick2::create();

				int space = 10;
				auto size = brick->getContentSize();

				brick->setPosition(Vec2(
					(size.width / 2 + space) * column + size.width / 2,
					(size.height / 2 + space) * row + size.height / 2
				));
				if (column % 2 == 0) {
					brick->setTag(2);
				}
				else brick->setTag(20);
				this->addChild(brick);
			}
		}
	}

	for (int row = 4; row < 6; row++) {
		for (int column = 0; column < _levelData.columns; column++) {
			if (column != 1 && column != 8 && column != 4 && column != 5) {
				Brick3* brick = Brick3::create();

				auto size = brick->getContentSize();

				brick->setPosition(Vec2(
					(size.width / 2 + space) * column + size.width / 2,
					(size.height / 2 + space) * row + size.height / 2
				));
				if (column % 2 == 0) {
					brick->setTag(2);
				}
				else brick->setTag(20);
				this->addChild(brick);
			}
		}
	}

	for (int row = 6; row < _levelData.rows; row++) {
		for (int column = 0; column < _levelData.columns; column++) {
			Brick4* brick = Brick4::create();

			int space = 10;
			auto size = brick->getContentSize();

			brick->setPosition(Vec2(
				(size.width / 2 + space) * column + size.width / 2,
				(size.height / 2 + space) * row + size.height / 2
			));
			if (column % 2 == 0) {
				brick->setTag(2);
			}
			else brick->setTag(20);
			this->addChild(brick);

			if (column == _levelData.columns - 1 && row == _levelData.rows - 1) {
				this->setContentSize(Size((size.width + space) * column + size.width, (size.height + space) * row + size.height));
			}
		}
	}

	//add 3 goals
	{
		Goal* goal1 = Goal::create();
		//goal1->setPosition(Vec2(660, 250));
		Goal* goal2 = Goal::create();
		/*goal2->setPosition(Vec2(140, 220));*/
		Goal* goal3 = Goal::create();
		goal3->setPosition(Vec2(400, 220));

		CCActionInterval * orbitcamera1 = CCOrbitCamera::create(1.4f, 1, 0, 0, 360, 0, 0);
		goal2->runAction(RepeatForever::create(Spawn::create(
			Sequence::create(MoveTo::create(0.7f, Vec2(140, 250)),
				MoveTo::create(0.7f, Vec2(140, 100)),
				MoveTo::create(0.7f, Vec2(140, 250)),
				NULL), orbitcamera1, NULL)));
		CCActionInterval * orbitcamera2 = CCOrbitCamera::create(1.4f, 1, 0, 0, 360, 0, 0);
		goal1->runAction(RepeatForever::create(Spawn::create(
			Sequence::create(MoveTo::create(0.7f, Vec2(660, 250)),
				MoveTo::create(0.7f, Vec2(660, 100)),
				MoveTo::create(0.7f, Vec2(660, 250)),
				NULL), orbitcamera2, NULL)));
		CCActionInterval * orbitcamera3 = CCOrbitCamera::create(1, 1, 0, 0, 360, 0, 0);
		goal3->runAction(RepeatForever::create(orbitcamera3));

		goal1->setTag(3);
		goal2->setTag(3);
		goal3->setTag(3);
		this->addChild(goal3);
		this->addChild(goal1);
		this->addChild(goal2);
	}
	//add 2 obstructs
	{
		Obstruct* ob1 = Obstruct::create();
		Obstruct* ob2 = Obstruct::create();
		ob1->setPosition(Vec2(0, 0));
		ob2->setPosition(Vec2(800, 0));
		ob1->setTag(4);
		ob2->setTag(4);
		this->addChild(ob1);
		this->addChild(ob2);
	}
}

void DBLevel::initLevel09BrickLayout() {
	int space = 10;

	for (int row = 0; row < 2; row++) {
		for (int column = 0; column < _levelData.columns; column++) {
			Brick1* brick = Brick1::create();

			int space = 10;
			auto size = brick->getContentSize();

			brick->setPosition(Vec2(
				(size.width / 2 + space) * column + size.width / 2,
				(size.height / 2 + space) * row + size.height / 2
			));
			if (column % 2 == 0) {
				brick->setTag(2);
			}
			else brick->setTag(20);
			this->addChild(brick);
		}
	}

	for (int row = 2; row < 4; row++) {
		for (int column = 0; column < _levelData.columns; column++) {
			if (column != 1 && column != 8) {
				Brick2* brick = Brick2::create();

				int space = 10;
				auto size = brick->getContentSize();

				brick->setPosition(Vec2(
					(size.width / 2 + space) * column + size.width / 2,
					(size.height / 2 + space) * row + size.height / 2
				));
				if (column % 2 == 0) {
					brick->setTag(2);
				}
				else brick->setTag(20);
				this->addChild(brick);
			}
		}
	}

	for (int row = 4; row < 6; row++) {
		for (int column = 0; column < _levelData.columns; column++) {
			if (column != 1 && column != 8 && column != 4 && column != 5) {
				Brick3* brick = Brick3::create();

				auto size = brick->getContentSize();

				brick->setPosition(Vec2(
					(size.width / 2 + space) * column + size.width / 2,
					(size.height / 2 + space) * row + size.height / 2
				));
				if (column % 2 == 0) {
					brick->setTag(2);
				}
				else brick->setTag(20);
				this->addChild(brick);
			}
		}
	}

	for (int row = 6; row < _levelData.rows; row++) {
		for (int column = 0; column < _levelData.columns; column++) {
			Brick4* brick = Brick4::create();

			int space = 10;
			auto size = brick->getContentSize();

			brick->setPosition(Vec2(
				(size.width / 2 + space) * column + size.width / 2,
				(size.height / 2 + space) * row + size.height / 2
			));
			if (column % 2 == 0) {
				brick->setTag(2);
			}
			else brick->setTag(20);
			this->addChild(brick);

			if (column == _levelData.columns - 1 && row == _levelData.rows - 1) {
				this->setContentSize(Size((size.width + space) * column + size.width, (size.height + space) * row + size.height));
			}
		}
	}

	//add 3 goals
	{
		Goal* goal1 = Goal::create();
		//goal1->setPosition(Vec2(660, 250));
		Goal* goal2 = Goal::create();
		/*goal2->setPosition(Vec2(140, 220));*/
		Goal* goal3 = Goal::create();
		goal3->setPosition(Vec2(400, 220));

		CCActionInterval * orbitcamera1 = CCOrbitCamera::create(1.4f, 1, 0, 0, 360, 0, 0);
		goal2->runAction(RepeatForever::create(Spawn::create(
			Sequence::create(MoveTo::create(0.7f, Vec2(140, 250)),
				MoveTo::create(0.7f, Vec2(140, 100)),
				MoveTo::create(0.7f, Vec2(140, 250)),
				NULL), orbitcamera1, NULL)));
		CCActionInterval * orbitcamera2 = CCOrbitCamera::create(1.4f, 1, 0, 0, 360, 0, 0);
		goal1->runAction(RepeatForever::create(Spawn::create(
			Sequence::create(MoveTo::create(0.7f, Vec2(660, 250)),
				MoveTo::create(0.7f, Vec2(660, 100)),
				MoveTo::create(0.7f, Vec2(660, 250)),
				NULL), orbitcamera2, NULL)));
		CCActionInterval * orbitcamera3 = CCOrbitCamera::create(1, 1, 0, 0, 360, 0, 0);
		goal3->runAction(RepeatForever::create(orbitcamera3));

		goal1->setTag(3);
		goal2->setTag(3);
		goal3->setTag(3);
		this->addChild(goal3);
		this->addChild(goal1);
		this->addChild(goal2);
	}
	//add 2 obstructs
	{
		Obstruct* ob1 = Obstruct::create();
		Obstruct* ob2 = Obstruct::create();
		ob1->setPosition(Vec2(0, 0));
		ob2->setPosition(Vec2(800, 0));
		ob1->setTag(4);
		ob2->setTag(4);
		this->addChild(ob1);
		this->addChild(ob2);
	}
}