# include "SceneBase.h"
# include "TitleScene.h"
# include "PlayScene.h"
# include "ScoreScene.h"

void Main()
{
	App manager;
	manager.add<Title>(State::Title);
	manager.add<Play>(State::Play);
	manager.add<Score>(State::Score);

	while (System::Update())
	{
		if (not manager.update())
		{
			break;
		}
	}
}
