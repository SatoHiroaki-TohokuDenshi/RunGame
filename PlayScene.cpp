# include "PlayScene.h"

Play::Play(const InitData& init)
	: IScene{ init }, PlayerChar_{ U"Images/Man_Run1.png", TextureDesc::Mipped } {}

void Play::update()
{
}

void Play::draw() const
{
	PlayerChar_.scaled(0.3).draw(40, 450);
}
