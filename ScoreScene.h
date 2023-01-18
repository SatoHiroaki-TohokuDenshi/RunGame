# pragma once
# include "SceneBase.h"

// タイトルシーン
class Score : public App::Scene
{
public:

	Score(const InitData& init);

	void update() override;

	void draw() const override;

private:
	const Texture RankS_;
	const Texture RankA_;
	const Texture RankB_;
	const Texture RankC_;
	const Texture RankD_;
	const Vec2 RankPos_;
	const Vec2 EvaluationPos_;

	int PlayScore_;
};
