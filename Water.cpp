#include "Water.h"
using namespace sf; 

void Water::display(RenderWindow& Window)
{
    //draw rectangle
    RectangleShape water (Vector2f(WaterX,Window.getSize().y-40- WaterY));
    //need to set random position
    water.setPosition(20, 20+ WaterY);
    //define color
    water.setFillColor(Color(102,102,255,255));
    Window.draw(water);
}

void Water::size(int RangeW, int RangeH)
{
     WaterX = RangeW;
     WaterY = RangeH;
}
