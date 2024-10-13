#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class Food
{
public:
	void display(RenderWindow& Window);
	~Food(){}
	Food(int RangeW, int RangeH);
	void Spawn(int RangeW, int RangeH, int WaterLevel);
	Vector2f GetPosition();
	void die()
	{
		FoodAlive = false;
	}
	int GetFoodScore()
	{
		return FoodScore;
	}
	bool IsAlive()
	{
		return FoodAlive;
	}

private:
	int FoodScore;
	//Color FoodColour;
	Texture FoodTexture;
	float FoodX;
	float FoodY;
	bool FoodAlive{ false };
	
};

