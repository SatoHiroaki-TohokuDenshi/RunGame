# pragma once
# include "SceneBase.h"

// ゲームシーン
class Play : public App::Scene
{
public:

	Play(const InitData& init);

	void update() override;

	void draw() const override;

private:
	const Texture PlayerChar_;		//プレイヤーキャラ
	const double GA_;				//重力加速度
	Vec2 PlayerCharCoordinate_;		//プレイヤーキャラの座標
	Vec2 camera_;					//表示位置
	Vec2 move_;
};
