# include "PlayScene.h"

Play::Play(const InitData& init)
	: IScene{ init } {}

void Play::update()
{
}

void Play::draw() const
{
	PlayerChar.draw(40, 20);
}
