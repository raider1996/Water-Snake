#include "Food.h"
#include<iostream>


void Food::display(RenderWindow& Window)
{
    if (FoodAlive == false) return;
    //draw circlw with radius
    CircleShape Food(8);
    //need to set random position
    Food.setPosition(FoodX, FoodY);
    //set origin
    Food.setOrigin(5, 5);
    //define color
    Food.setOutlineThickness(2);
    Food.setOutlineColor(Color(0, 0, 0, 255));
    //Food.setFillColor(FoodColour);
    Food.setTexture(&FoodTexture);
    Window.draw(Food);
}

Food::Food(int RangeW, int RangeH)
{
    
}
void Food::Spawn(int RangeW, int RangeH, int WaterLevel)
{
    Texture Gold;
    if (Gold.loadFromFile("texture/Gold.png"))
    {
      //  std::cout << "failed";
    }
    Texture Silver;
    if (Silver.loadFromFile("texture/Silver.png"))
    {
    //    std::cout << "failed";
    }
    Texture Bronze;
    if (Bronze.loadFromFile("texture/Bronze.png"))
    {
     //   std::cout << "failed";
    }
    int RandomItem;
    RandomItem = rand() % 100;
    if (RandomItem < 50)//bronze
    {
        FoodScore = 5;
        FoodTexture = (Gold);
        //FoodColour = Color(204, 102, 0, 255);

    }
    else if (RandomItem < 80)//silver
    {
        FoodScore = 10;
        FoodTexture = (Silver);
        //FoodColour = Color(191, 191, 191, 255);
    }
    else if (RandomItem < 100)//gold
    {
        FoodScore = 15;
        FoodTexture = Bronze;
        //FoodColour = Color(255, 255, 153, 255);
    }

    // spawns food where water level is
    RangeH -= WaterLevel;
    RangeW -= 20;
    FoodX = int(rand() % RangeW / 20) * 20 + 40;
    FoodY = int(rand() % RangeH / 20) * 20 + 20 + (WaterLevel / 20) * 20;
    FoodAlive = true;
}
Vector2f Food::GetPosition()
{
    return Vector2f(FoodX, FoodY);
}

