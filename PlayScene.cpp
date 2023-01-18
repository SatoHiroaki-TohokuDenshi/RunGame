# include "PlayScene.h"

Play::Play(const InitData& init)
	: IScene{ init }, GA_(1.0), camera_(0, 0), move_(0, 0),
	 PlayerPos_(40, 450), MoneyPos_(300, 450),sec_(30),
	 LifePos_(200, 200),
	 PlayerChar_{ U"Images/Man_Run1.png", TextureDesc::Mipped },
	 ItemMoney_{ U"Images/money_item.png", TextureDesc::Mipped },
	 Life_{ U"Images/Life.png", TextureDesc::Mipped }
{
	//Stopwatch stopwatch_{ StartImmediately::Yes };
}

void Play::update()
{
	//ジャンプの処理
	if (PlayerPos_.y != 450)
	{
		PlayerPos_ += move_;
		move_.y += GA_;
	}

	if (PlayerPos_.y == 450)
	{
		if (KeySpace.down())
		{
			move_.y = -21.0;
			PlayerPos_ += move_;
		}
	}

	if (PlayerPos_.y >= 450)
	{
		move_.y = 0;
		PlayerPos_.y = 450;
	}

	//時間の処理
	sec_ = 30 - stopwatch_.s();
	if (sec_ == 0)
	{
		changeScene(State::Score);
	}


}

void Play::draw() const
{
	FontAsset(U"GameScore")(sec_).draw(10, 10);
	PlayerChar_.scaled(0.3).draw(PlayerPos_);
	ItemMoney_.scaled(0.3).drawAt(MoneyPos_);
}
