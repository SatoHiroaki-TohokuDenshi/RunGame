# include "ScoreScene.h"

Score::Score(const InitData& init)
	: IScene{ init }, PlayScore_(0), RankPos_(400, 250), EvaluationPos_(400, 350),
	RankS_{ U"Images/s_score.png" }, RankA_{ U"Images/a_score.png" },
	RankB_{ U"Images/b_score.png" }, RankC_{ U"Images/c_score.png" }, RankD_{ U"Images/d_score.png" },
	RankUpper_{U"Audio/Phrase02-1.mp3"}, RankMiddle_{U"Audio/Phrase03-1.mp3"}, RankLower_{U"Audio/Phrase04-1.mp3"}
{
	auto& data = getData();
	PlayScore_ = data.score;
}

void Score::update()
{
	m_startTransition.update(m_titleButton.mouseOver());

	if (m_titleButton.mouseOver())
	{
		Cursor::RequestStyle(CursorStyle::Hand);
	}

	if (m_titleButton.leftClicked())
	{
		// ゲームシーンへ
		changeScene(State::Title);
	}
}

void Score::draw() const
{
	//点数に沿ってランクS～Dを表示させる
	if (PlayScore_ >= 300)
	{
		RankS_.drawAt(RankPos_);
		FontAsset(U"ScoreScene")(U"たいへんよくできました").drawAt(EvaluationPos_);
		if (getData().RankSE)
		{
			RankUpper_.play();
			getData().RankSE = false;
		}
	}
	else if (PlayScore_ >= 250)
	{
		RankA_.drawAt(RankPos_);
		FontAsset(U"ScoreScene")(U"素晴らしい出来でした").drawAt(EvaluationPos_, ColorF{ 0.25 });
		if (getData().RankSE)
		{
			RankUpper_.play();
			getData().RankSE = false;
		}
	}
	else if (PlayScore_ >= 150)
	{
		RankB_.drawAt(RankPos_);
		FontAsset(U"ScoreScene")(U"悪くありませんでした").drawAt(EvaluationPos_, ColorF{ 0.25 });
		if (getData().RankSE)
		{
			RankMiddle_.play();
			getData().RankSE = false;
		}
	}
	else if (PlayScore_ >= 50)
	{
		RankC_.drawAt(RankPos_);
		FontAsset(U"ScoreScene")(U"もっと頑張りましょう").drawAt(EvaluationPos_, ColorF{ 0.25 });
		if (getData().RankSE)
		{
			RankLower_.play();
			getData().RankSE = false;
		}
	}
	else
	{
		RankD_.drawAt(RankPos_);
		FontAsset(U"ScoreScene")(U"やり直しましょう").drawAt(EvaluationPos_, ColorF{ 0.25 });
		if (getData().RankSE)
		{
			RankLower_.play();
			getData().RankSE = false;
		}

	}

	m_titleButton.draw(ColorF{ 1.0, m_startTransition.value() }).drawFrame(2);

	FontAsset(U"Menu")(U"Rank")
		.drawAt(TextStyle::OutlineShadow(0.2, ColorF{ 0.2, 0.6, 0.2 }, Vec2{ 3, 3 }, ColorF{ 0.0, 0.5 }), 100, Vec2{ 400, 100 });

	FontAsset(U"Menu")(U"TITLE").drawAt(m_titleButton.center(), ColorF{ 0.25 });
}
