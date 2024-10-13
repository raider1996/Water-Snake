#include "Game.h"
#include "snake.h"
#include "Food.h"
#include "Water.h"
#include <iostream>
#include <SFML/Graphics.hpp>

void Game::Run()
{
    // Screen Size
    constexpr int ScreenWidth{ 500 };
    constexpr int ScreenHeight{ 500 };
    const int TankBoarder{ 20 };

    int RangeW = ScreenWidth - TankBoarder - TankBoarder;
    int RangeH = ScreenHeight - TankBoarder - TankBoarder;

    // game varables
    Clock clock;
    Clock Countdown;
    clock.restart();
    Snake Player;
    SnakeVector.push_back(&Player);
    Snake Player2;
    SnakeVector.push_back(&Player2);
    Water Tank;
    float TankRate = ScreenHeight / 90.0f /10.0f; 
    float CurrentWaterLevel{ 0 };

    //draw text for timer
    Text text;
    Font font;
    if (!font.loadFromFile("arial.ttf"))
    {
        std::cout << "failed";
    }
    // select the font
    text.setFont(font);
    // set the character size
    text.setCharacterSize(15); // in pixels, not points!
    // set the color
    text.setFillColor(Color::Blue);
    // set the text style
    text.setStyle(Text::Bold | Text::Underlined);
    //set position 
    text.setPosition(200, 1);

    //draw text for score player1
    Text Score;
    Font font2;
    if (!font2.loadFromFile("arial.ttf"))
    {
        std::cout << "failed";
    }
    // select the font
    Score.setFont(font2);
    // set the character size
    Score.setCharacterSize(15); // in pixels, not points!
    // set the color
    Score.setFillColor(Color(0, 153, 51, 255));
    // set the text style
    Score.setStyle(Text::Bold | Text::Underlined);
    //set position 
    Score.setPosition(15, 1);

    //draw text for breathing player1
    Text Breath;
    Font font3;
    if (!font3.loadFromFile("arial.ttf"))
    {
        std::cout << "failed";
    }
    // select the font
    Breath.setFont(font3);
    // set the character size
    Breath.setCharacterSize(15); // in pixels, not points!
    // set the color
    Breath.setFillColor(Color(0, 153, 51, 255));
    // set the text style
    Breath.setStyle(Text::Bold | Text::Underlined);
    //set position 
    Breath.setPosition(300, 1);

    //draw text for breathing player2
    Text Breath2;
    Font font4;
    if (!font4.loadFromFile("arial.ttf"))
    {
        std::cout << "failed";
    }
    // select the font
    Breath2.setFont(font4);
    // set the character size
    Breath2.setCharacterSize(15); // in pixels, not points!
    // set the color
    Breath2.setFillColor(Color::Red);
    // set the text style
    Breath2.setStyle(Text::Bold | Text::Underlined);
    //set position 
    Breath2.setPosition(400, 1);

    //draw text for score player2
    Text Score2;
    Font font5;
    if (!font5.loadFromFile("arial.ttf"))
    {
        std::cout << "failed";
    }
    // select the font
    Score2.setFont(font5);
    // set the character size
    Score2.setCharacterSize(15); // in pixels, not points!
    // set the color
    Score2.setFillColor(Color::Red);
    // set the text style
    Score2.setStyle(Text::Bold | Text::Underlined);
    //set position 
    Score2.setPosition(100, 1);

    //draw text for Game Over
    Text End;
    Font font6;
    if (!font6.loadFromFile("arial.ttf"))
    {
        std::cout << "failed";
    }
    // select the font
    End.setFont(font6);
    // set the character size
    End.setCharacterSize(30); // in pixels, not points!
    // set the color
    End.setFillColor(Color::Red);
    // set the text style
    End.setStyle(Text::Bold | Text::Underlined);
    //set position 
    End.setPosition(100, 1);

    //draw text for Winner
    Text Win;
    Font font7;
    if (!font7.loadFromFile("arial.ttf"))
    {
        std::cout << "failed";
    }
    // select the font
    Win.setFont(font7);
    // set the character size
    Win.setCharacterSize(24); // in pixels, not points!
    // set the color
    Win.setFillColor(Color::White);
    // set the text style
    Win.setStyle(Text::Bold | Text::Underlined);
    //set position 
    Win.setPosition(100, 200);

    //draw text for Winner name
    Text Name;
    Font font8;
    if (!font8.loadFromFile("arial.ttf"))
    {
        std::cout << "failed";
    }
    // select the font
    Name.setFont(font8);
    // set the character size
    Name.setCharacterSize(24); // in pixels, not points!
    // set the color
    Name.setFillColor(Color::White);
    // set the text style
    Name.setStyle(Text::Bold);
    //set position 
    Name.setPosition(100, 250);

    //create wall left
    RectangleShape WallL(Vector2f(20, 460));
    WallL.setPosition(0, 20);
    WallL.setFillColor(Color(57,38,19,255));

    //create wall Right
    RectangleShape WallR(Vector2f(20, 460));
    WallR.setPosition(480, 20);
    WallR.setFillColor(Color(57,38,19,255));

    //create wall Bottom
    RectangleShape WallB(Vector2f(500, 20));
    WallB.setPosition(0, 480);
    WallB.setFillColor(Color(57,38,19,255));


    //create screen
    std::cout << "linked list:";
    RenderWindow Window(VideoMode(ScreenWidth, ScreenHeight), "Snake Game!");
    Window.setFramerateLimit(60);

    // timer
    Countdown.restart();
    srand(time(0));

    // creating food
    for (size_t i = 0; i < 5; i++)
    {
        FoodVector.push_back(new Food(RangeW, RangeH));
    }

    bool GameOver = false;

    while (Window.isOpen())
    {
      
        //std::cout << 90 - Countdown.getElapsedTime().asSeconds()<< std::endl;
        text.setString("Times:"+std::to_string(90 - (int) Countdown.getElapsedTime().asSeconds()));
        
            //text for score for player1
            Score.setString("Score:" + std::to_string(SnakeVector[0]->TotalScore));
            // text for breath for player 1
            Breath.setString("Breath:" + std::to_string(SnakeVector[0]->Getbreath()));
            //text for score for player2
            Score2.setString("Score:" + std::to_string(SnakeVector[1]->TotalScore));
            // text for breath for player 2
            Breath2.setString("Breath:" + std::to_string(SnakeVector[1]->Getbreath()));
            // text for game over
            End.setString("Game Over");

            if (GameOver)
            {
                // text for winner
                Win.setString("The Winner is:");
                if (SnakeVector[0]->TotalScore > SnakeVector[1]->TotalScore)
                {
                    Name.setString("Player Green Wins");
                }
                else if (SnakeVector[1]->TotalScore > SnakeVector[0]->TotalScore)
                {
                    Name.setString("Player Red Wins");
                }
                else
                {
                    Name.setString("Draw");
                }
            }

        // time for water level
        if (clock.getElapsedTime().asSeconds() >= 0.2f)
        {
            Player.Move(CurrentWaterLevel, TankBoarder, RangeW, RangeH);
            Player2.Move(CurrentWaterLevel, TankBoarder, RangeW, RangeH);
            //CurrentWaterLevel++;
            Tank.size(RangeW,CurrentWaterLevel);
            CurrentWaterLevel += TankRate;
            clock.restart();

            // food collision
            for (Snake* S : SnakeVector)
            {
                S->FoodCollision(FoodVector);
            }

            for (int i = 0; i < SnakeVector.size(); i++)
            {
                for (int j = i + 1; j < SnakeVector.size(); j++)
                {
                    if (SnakeVector[i]->Collides(SnakeVector[j]->GetPosition()))
                    {
                        GameOver = true;

                    }
               
                }
            }

            for (int k = 0; k < SnakeVector.size(); k++)
            {
                if (SnakeVector[k]->snakeAlive()==false)
                {
                    GameOver = true; 
                }
            }

        }
        
            //respawn food
            if (rand() % 100 == 0)
            {
                for (size_t i = 0; i < 5; i++)
                {
                    if (!FoodVector[i]->IsAlive())
                    {
                        FoodVector[i]->Spawn(RangeW, RangeH, CurrentWaterLevel);
                        break;
                    }
                }
            }
        
        // display on screen 
       

        if (GameOver)
        {
            Window.clear(Color::Blue);
            Window.draw(End);
            Window.draw(Win);
            Window.draw(Name);
        }
        else
        {
            Window.clear(Color::White);
            Tank.display(Window);
            Player.display(Window);
            Player2.display(Window);
            Window.draw(text);
            Window.draw(Score);
            Window.draw(Score2);
            Window.draw(Breath);
            Window.draw(Breath2);
            Window.draw(WallL);
            Window.draw(WallR);
            Window.draw(WallB);

            for (Food* SelectFood : FoodVector)
            {
                SelectFood->display(Window);
            }
        }

        Window.display();

        // close the window 
        Event event;
        while (Window.pollEvent(event))
        {
            switch (event.type)
            {
            case Event::Closed:
                Window.close();
                break;
                if (Keyboard::isKeyPressed(Keyboard::Escape))
                {
                    Window.close();
                }
                break;
            default:
                break;
            }
        }
    }
}