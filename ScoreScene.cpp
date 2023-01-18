# include "ScoreScene.h"

Score::Score(const InitData& init)
	: IScene{ init }, PlayScore_(0), RankPos_(400, 250), EvaluationPos_(400, 450),
	RankS_{ U"Images/s_score.png" }, RankA_{ U"Images/a_score.png" },
	RankB_{ U"Images/b_score.png" }, RankC_{ U"Images/c_score.png" }, RankD_{ U"Images/d_score.png" }
{
	//auto& data = getData();
	//PlayScore_ = data.score;
}

void Score::update()
{
	
}

void Score::draw() const
{
	//点数に沿ってランクS～Dを表示させる
	if (PlayScore_ >= 500)
	{
		RankS_.drawAt(RankPos_);
		FontAsset(U"ScoreScene")(U"たいへんよくできました").drawAt(10, 10);
	}
	else if (PlayScore_ >= 400)
	{
		RankA_.drawAt(RankPos_);
		FontAsset(U"ScoreScene")(U"素晴らしい出来でした").drawAt(EvaluationPos_, ColorF{ 0.25 });
	}
	else if (PlayScore_ >= 300)
	{
		RankB_.drawAt(RankPos_);
		FontAsset(U"ScoreScene")(U"悪くありませんでした").drawAt(EvaluationPos_, ColorF{ 0.25 });
	}
	else if (PlayScore_ >= 200)
	{
		RankC_.drawAt(RankPos_);
		FontAsset(U"ScoreScene")(U"もっと頑張りましょう").drawAt(EvaluationPos_, ColorF{ 0.25 });
	}
	else
	{
		RankD_.drawAt(RankPos_);
		FontAsset(U"ScoreScene")(U"やり直しましょう").drawAt(EvaluationPos_, ColorF{ 0.25 });
	}
}

