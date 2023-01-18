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
	Stopwatch Stopwatch_{ StartImmediately::Yes };			//経過時間
	int Sec_;						//残り時間
	double Velocity_;					//移動量
	int MoveDist_;
	const Texture BackGround_;		//背景
	const Texture Tree_;			//背景の木
	Vec2 TreePos_[3];
	const Texture PlayerChar_;		//プレイヤーキャラ
	Vec2 PlayerPos_;				//プレイヤーキャラの座標
	Vec2 Camera_;					//表示位置

	//level2
	const double GA_;				//重力加速度
	double Move_;						//ジャンプの移動量
	const Texture Life_;			//ライフ
	Vec2 LifePos_;					//ライフの座標
	const Texture Obstacle_;       //障害物
	Vec2 ObstaclePos_[4];

	//level3
	const Texture ItemMoney_;		//お金
	Vec2 MoneyPos_;					//お金の座標
};
