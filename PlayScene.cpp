# include "PlayScene.h"

Play::Play(const InitData& init)
	: IScene{ init }, GA_(0.5), Camera_(0, 0), Move_(0), Velocity_(3), MoveDist_(0),
	 PlayerPos_(40, 350), MoneyPos_(300, 450),Sec_(30),
	 LifePos_(200, 200),
	 BackGround_{ U"Images/Field.png", TextureDesc::Mipped },
	 PlayerChar_{ U"Images/Man_Run1.png", TextureDesc::Mipped },
	 Tree_{ U"Images/tree.png", TextureDesc::Mipped },
	 ItemMoney_{ U"Images/money_item.png", TextureDesc::Mipped },
	 Life_{ U"Images/Life.png", TextureDesc::Mipped },
	Obstacle_{U"Images/cardboard_障害物.png",TextureDesc::Mipped }
{
	TreePos_[0] = Vec2(100, 300);
	TreePos_[1] = Vec2(400, 300);
	TreePos_[2] = Vec2(700, 300);
	ObstaclePos_[0] = Vec2{ 280,450 };
	ObstaclePos_[1] = Vec2{ 580,450 };
	ObstaclePos_[2] = Vec2{ 880,450 };
	ObstaclePos_[3] = Vec2{ 1180,450 };
	
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
		}
		else {
			ObstaclePos_[i].x -= Velocity_;
		}
	}
    

	if (Sec_ % 5 == 0)
	{
		Velocity_ += 0.001;
	}
}

void Play::draw() const
{
	BackGround_.draw(0, 0);

	FontAsset(U"GameScore")(Sec_).draw(10, 10);

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
