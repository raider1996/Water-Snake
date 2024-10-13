#pragma once
#include <vector>

class Food;
class Snake;
class Game
{
private:
	std::vector<Snake*>SnakeVector;
	std::vector<Food*>FoodVector;

public:
	void Run();
};

