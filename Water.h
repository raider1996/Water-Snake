#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class Water
{
public:
	void display(RenderWindow& Window);
	void size(int RangeW, int RangeH);

private:

	float WaterX;
	float WaterY;
};