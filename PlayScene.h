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
	//level1
	Stopwatch stopwatch_{ StartImmediately::Yes };			//経過時間
	int sec_;						//残り時間
	Vec2 move_;						//走行距離
	const Texture PlayerChar_;		//プレイヤーキャラ
	Vec2 PlayerPos_;				//プレイヤーキャラの座標
	Vec2 camera_;					//表示位置

	//level2
	const double GA_;				//重力加速度
	const Texture Life_;			//ライフ
	Vec2 LifePos_;					//ライフの座標

	//level3
	const Texture ItemMoney_;		//お金
	Vec2 MoneyPos_;					//お金の座標
};
