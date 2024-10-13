#include "snake.h"
#include <SFML/Graphics.hpp>
#include"food.h"
#include<iostream>
using namespace sf;

int Snake::NumSnakes = 0;


void Snake::Move(int CurrentWaterLevel, int TankBoarder, int RangeW, int RangeH)
{
    
    Vector2f Position = Segments.front();
    breath--;

    if (Position.y < CurrentWaterLevel)
    {
        breath = 100;
    }

    if (breath <= 0)
    {
        breath = 0;
        GrowAmount = -1;
        TotalScore--;
    }

    if (TotalScore < 0)
    {
        TotalScore = 0;
    }

    switch (direction)
  {
    case Direction::left:
        Position.x -= 20;
        break;
    case Direction::right:
        Position.x += 20;
        break;
    case Direction::up:
        Position.y -= 20;
        break;
    case Direction::down:
        Position.y += 20;
        break;
    default:
        break;
    }

    // when breath is zero it loses tail and score
    Segments.push_front(Position);
    if (GrowAmount == 0)
        Segments.pop_back();
    else if (GrowAmount < 0)
    {
        if (Segments.size() == 2)
        {
            //kill snake
            SnakeAlive = false;
        }
        else
        {
            Segments.pop_back();
            Segments.pop_back();
            GrowAmount++;
        }
    }

else
        GrowAmount--;

    // collision with itself
    auto CurrentSegment = Segments.begin(); 
    while (CurrentSegment != Segments.end())
    {
        if (Segments.begin() == CurrentSegment)
        {

        }
        else
        {
            if (*CurrentSegment == Segments.front())
            {
                SnakeAlive = false;
            }

        }
        CurrentSegment++;
    }


   //collision with wall
    if (Position.x < TankBoarder)
    {
        SnakeAlive = false;
    }
    else if (Position.x >= TankBoarder + RangeW)
    {
        SnakeAlive = false;
    }
    else if (Position.y < TankBoarder)
    {
        SnakeAlive = false;
    }
    else if (Position.y >= TankBoarder + RangeH)
    {
        SnakeAlive = false; 
    }
    
    //std::cout << SnakeAlive << std::endl;

    // snake key pressed 
    if (SnakeID == 0)
    {
        if (Keyboard::isKeyPressed(Keyboard::Left) && !(direction == Direction::right))
        {
            direction = Direction::left;
        }
        else if (Keyboard::isKeyPressed(Keyboard::Right) && !(direction == Direction::left))
        {
            direction = Direction::right;
        }
        else if (Keyboard::isKeyPressed(Keyboard::Up) && !(direction == Direction::down))
        {
            direction = Direction::up;
        }
        else if (Keyboard::isKeyPressed(Keyboard::Down) && !(direction == Direction::up))
        {
            direction = Direction::down;
        }
    }
    else if (SnakeID == 1)
    {
        if (Keyboard::isKeyPressed(Keyboard::A) && !(direction == Direction::right))
        {
            direction = Direction::left;
        }
        else if (Keyboard::isKeyPressed(Keyboard::D) && !(direction == Direction::left))
        {
            direction = Direction::right;
        }
        else if (Keyboard::isKeyPressed(Keyboard::W) && !(direction == Direction::down))
        {
            direction = Direction::up;
        }
        else if (Keyboard::isKeyPressed(Keyboard::S) && !(direction == Direction::up))
        {
            direction = Direction::down;
        }
    }
}

bool Snake::Collides(Vector2f other_head)
{
 //    collision with other
    if (Segments.front() == other_head)
    {
      //  head hits head
        return true;
    }
    auto CurrentSegment = Segments.begin();
    while (CurrentSegment != Segments.end())
    {
        {
            if (*CurrentSegment == other_head)
            {
                return true;
            }

        }
        CurrentSegment++;

    }


    return false;
}


void Snake::FoodCollision(std::vector<Food*>& FoodVector)
{
    for (Food* F : FoodVector)
    {
        if (Segments.front() == F->GetPosition())
        {
            GrowAmount += F->GetFoodScore() / 5;
            TotalScore += F->GetFoodScore();
            F->die();
            
        }
    }
}




int Snake::Getbreath()
{
    return breath;
}

// snake starting position 
Snake::Snake()
{
    SnakeID = NumSnakes;

    if (SnakeID == 0)
    {
        Segments.push_front({ 200.f,300.f });
    }
    else if (SnakeID == 1)
    {
        Segments.push_front({ 100.f,400.f });
    }
    NumSnakes++;
   
   
}

void Snake::display(RenderWindow& Window)
{
    //draw circlw with radius
    CircleShape Circle(8);
    // resize it to 100 points
    Circle.setPointCount(100);
    //set origin and position
    Circle.setOrigin(5, 5);
    //define color
    Circle.setOutlineThickness(2);
    Circle.setOutlineColor(Color(0, 0, 0, 255));
    if (SnakeID == 0)
    {
        Circle.setFillColor(Color(0, 153, 51, 255));
    }
    else if (SnakeID == 1)
    {
        Circle.setFillColor(Color(230, 0, 0, 255));
    }
    for (Vector2f pos : Segments)
    {
        Circle.setPosition(pos);
        Window.draw(Circle);
    }
}


