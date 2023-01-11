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
};
