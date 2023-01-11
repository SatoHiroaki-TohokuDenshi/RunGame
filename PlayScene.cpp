# include "PlayScene.h"

Play::Play(const InitData& init)
	: IScene{ init }, PlayerChar_{ U"Images/Man_Run1.png" } {}

void Play::update()
{
}

void Play::draw() const
{
	PlayerChar_.draw(40, 20);
}
