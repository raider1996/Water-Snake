#pragma once
#include <SFML/Graphics.hpp>
#include <list>
#include"Food.h"
using namespace sf;


//set direction of snake
enum class Direction {left,right,up,down};

class Snake
	
{
public:
	Snake();

	//void insert(int value) {}

	void display(RenderWindow& Window);

	void Move(int CurrentWaterLevel, int TankBoarder, int RangeW, int RangeH);
	bool Collides(Vector2f other_head);

	int TotalScore=0;

	~Snake() {}
	//check Collision
	void FoodCollision(std::vector<Food*>& FoodVector);

	int Getbreath();

	Vector2f GetPosition()
	{
		return Segments.front();
	}
	bool snakeAlive()
	{
		return SnakeAlive;
	}

private:
	
	Direction direction=Direction::up;
	int GrowAmount{ 0 };

	std::list<Vector2f>Segments;	
	bool SnakeAlive{ true };

	int breath = 100; 

	int SnakeID{ 0 };

	static int NumSnakes;


};

