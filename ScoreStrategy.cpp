#include "ScoreStrategy.h"

ScoreStragy::ScoreStragy(): _contiuous(0)
{
}
ScoreStragy::~ScoreStragy()
{
}
void ScoreStragy::execute(ScoreData* data, int tag)
{
		_contiuous++;
		if (_contiuous > data->maxContinues) {
			data->maxContinues = _contiuous;
		}
		if (tag == 2 || tag == 20) {
			data->score += 10 * _contiuous;
		}
		else _contiuous = 1;
		if (tag == 3) {
			data->score += 500;
		}
		if (tag == 3000) {
			data->score += 3000;
		}
		if (tag == 1000) {
			data->score -= 1000;
		}
}
