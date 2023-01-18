﻿# pragma once
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
	Stopwatch Stopwatch_{ StartImmediately::Yes };			//経過時間
	int Sec_;						//残り時間
	double Velocity_;				//移動量
	double MoveDist_;					//移動距離
	const Texture BackGround_;		//背景
	const Texture Tree_;			//背景の木
	Vec2 TreePos_[3];
	const Texture PlayerChar_;		//プレイヤーキャラ
	Vec2 PlayerPos_;				//プレイヤーキャラの座標

	//level2
	const double GA_;				//重力加速度
	double Move_;					//ジャンプの移動量
	const Texture Obstacle_;		//障害物
	Vec2 ObstaclePos_[4];

	//level3
	const Texture ItemMoney_;		//お金
	Vec2 MoneyPos_;					//お金の座標
};
