# include "PlayScene.h"

Play::Play(const InitData& init)
	: IScene{ init }, GA_(0.5), Move_(0), Velocity_(3), MoveDist_(0),
	 PlayerPos_(40, 350), MoneyPos_(300, 450),Sec_(30),
	 BackGround_{ U"Images/Field.png", TextureDesc::Mipped },
	 PlayerChar_{ U"Images/Man_Run1.png", TextureDesc::Mipped },
	 Tree_{ U"Images/tree.png", TextureDesc::Mipped },
	 ItemMoney_{ U"Images/money_item.png", TextureDesc::Mipped },
	 Obstacle_{U"Images/cardboard_障害物.png",TextureDesc::Mipped }
{
	TreePos_[0] = Vec2(100, 300);
	TreePos_[1] = Vec2(400, 300);
	TreePos_[2] = Vec2(700, 300);
	ObstaclePos_[0] = Vec2{ 480,450 };
	ObstaclePos_[1] = Vec2{ 780,450 };
	ObstaclePos_[2] = Vec2{ 1080,450 };
	ObstaclePos_[3] = Vec2{ 1380,450 };
	
}


void Play::update()
{
	//ジャンプの処理
	if (PlayerPos_.y != 350)
	{
		PlayerPos_.y += Move_;
		Move_ += GA_;
	}

	if (PlayerPos_.y == 350)
	{
		if (KeySpace.down())
		{
			Move_ = -17;
			PlayerPos_.y += Move_;
		}
	}

	if (PlayerPos_.y > 350)
	{
		Move_ = 0;
		PlayerPos_.y = 350;
	}

	//タイムアップ処理
	Sec_ = 30 - Stopwatch_.s();
	if (Sec_ == 0)
	{
		getData().score += 150;
		changeScene(State::Score);
	}

	//移動処理
	for (int i = 0; i < 3; i++)
	{
		if (TreePos_[i].x < -80)
		{
			TreePos_[i].x = 900;
		}
		else {
			TreePos_[i].x -= Velocity_;
		}
	}

	for (int i = 0; i < 4; i++)
	{
		if (ObstaclePos_[i].x < -100)
		{
			ObstaclePos_[i].x = 1300;
			ObstaclePos_[i].y = rand() % 400 + 70;
		}
		else {
			ObstaclePos_[i].x -= Velocity_;
		}
	}

	MoveDist_ += Velocity_ / 200;

	//当たり判定の処理（仮）
	const Rect Player(PlayerPos_.x + 40, PlayerPos_.y + 20, 40, 80);
	Player.draw();
	for (int i = 0; i < 4; i++)
	{
		Obstacle_.scaled(0.3).drawAt(ObstaclePos_[i]);
		Rect(ObstaclePos_[i].x - 50, ObstaclePos_[i].y - 40, 80, 80).draw();
		if (Rect(ObstaclePos_[i].x - 50, ObstaclePos_[i].y - 40, 80, 80).intersects(Player))
		{
			getData().score += (int)MoveDist_;
			changeScene(State::Score);
		}
	}

	
	if (Sec_ % 5 == 0)
	{
		Velocity_ += 0.004;
	}
}

void Play::draw() const
{
	BackGround_.draw(0, 0);

	FontAsset(U"GameScore")(U"残り時間：").draw(10, 10);
	FontAsset(U"GameScore")(Sec_).draw(150, 10);

	FontAsset(U"GameScore")((int)MoveDist_).draw(300, 10);
	FontAsset(U"GameScore")(U"ｍ走ったよ").draw(350, 10);

	for (int i = 0; i < 3; i++)
	{
		Tree_.scaled(0.3).drawAt(TreePos_[i]);
	}
	PlayerChar_.scaled(0.3).draw(PlayerPos_);
	

	ItemMoney_.scaled(0.3).drawAt(MoneyPos_);

	for (int i = 0; i < 4; i++)
	{
		Obstacle_.scaled(0.3).drawAt(ObstaclePos_[i]);
	}
}
