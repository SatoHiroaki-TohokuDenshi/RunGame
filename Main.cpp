# include "SceneBase.h"

void Main()
{
	// 背景の色を設定 | Set background color
	Scene::SetBackground(ColorF{ 0.8, 0.9, 1.0 });
	// 通常のフォントを作成 | Create a new font
	const Font font{ 60 };


	while (System::Update())
	{
		
	}
}
