# pragma once
# include <Siv3D.hpp>

// シーンの名前
enum class State
{
	Title,
	Play,
	Score
};

// 共有するデータ
struct GameData
{
	int score;
};

using App = SceneManager<State, GameData>;
