# include "PlayScene.h"

Play::Play(const InitData& init)
	: IScene{ init }, PlayerChar_{ U"Images/Man_Run1.png", TextureDesc::Mipped }, GA_(1.0),
	PlayerCharCoordinate_(40, 450), camera_(0, 0), move_(0, 0)
{
}

void Play::update()
{
	if (PlayerCharCoordinate_.y != 450)
	{
		PlayerCharCoordinate_ += move_;
		move_.y += GA_;
	}

	if (PlayerCharCoordinate_.y == 450)
	{
		if (KeySpace.down())
		{
			move_.y = -21.0;
			PlayerCharCoordinate_ += move_;
		}
	}

	if (PlayerCharCoordinate_.y >= 450)
	{
		move_.y = 0;
		PlayerCharCoordinate_.y = 450;
	}
}

void Play::draw() const
{
	PlayerChar_.scaled(0.3).draw(PlayerCharCoordinate_);

}
