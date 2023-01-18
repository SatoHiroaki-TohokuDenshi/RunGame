# include "ScoreScene.h"

Score::Score(const InitData& init)
	: IScene{ init }, RankS_{ U"Images/s_score.png" }, RankA_{ U"Images/a_score.png" },
	RankB_{ U"Images/b_score.png" }, RankC_{ U"Images/c_score.png" }, RankD_{ U"Images/d_score.png" }
{
}

void Score::update()
{

	if (400 >= 500)
	{
		RankS_.draw(100, 100);
	}
	else if (300 >= 400)
	{
		RankA_.draw(100, 100);
	}
	else if (200 >= 300)
	{
		RankB_.draw(100, 100);
	}
	else if (100 >= 200)
	{
		RankC_.draw(100, 100);
	}
	else if (0 >= 100)
	{
		RankD_.draw(100, 100);
	}
}

void Score::draw() const
{
}
#include "stdafx.h"
#include "ScoreScene.h"
