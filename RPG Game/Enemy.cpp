//
//  Enemy.cpp
//  RPG Game
//
//  Created by Mac Paweł on 01.05.2017.
//  Copyright © 2017 Macbook PRO 13. All rights reserved.
//

#include "Enemy.hpp"

using namespace std;





Enemy::Enemy()

{
    

    rect.setSize(sf::Vector2f(80,80));
    rect.setFillColor(sf::Color::Red);
    rect.setPosition(700,400);

    anime_frame = 0;
    movement_speed = 4;
    time = 0;
        
    direction = 1; //1 -> down, 2 -> up, 3 -> left , 4 -> right
    counterRandom = 0;
    
    //STATS
    movement_lenght = 60;
    HP=3;
    attackDamage = 1;
    alive = true;
    aggroed = false;
    
    
    canMoveUp = true;
    canMoveDown = true;
    canMoveRight = true;
    canMoveLeft = true;
    
    canBeInvisible = true;
    sprite.setTextureRect(sf::IntRect(110,0,80,80));


}

Enemy::~Enemy()
{
    
}



void Enemy::Update()
{
    sprite.setPosition(rect.getPosition());
    
}


void Enemy::Movement_Wolf()
{
   
    
    sf::Time elapsed_movement = clock_movement.getElapsedTime();
    
    if (direction==2) ////UP
    {
        if(canMoveUp==true)
        {
        rect.move(0, -movement_speed); ///UP
        sprite.setTextureRect(sf::IntRect(310 ,100*anime_frame, 50, 80));
        
            canMoveUp = true;
            canMoveDown = true;
            canMoveLeft = true;
            canMoveRight = true;
        }
       
   
    }
    
    else if (direction == 1)  ////DOWN
    {
        if(canMoveDown==true)
        {
        rect.move(0, movement_speed);
        sprite.setTextureRect(sf::IntRect(110,anime_frame*100,80,80));
            canMoveUp = true;
            canMoveDown = true;
            canMoveLeft = true;
            canMoveRight = true;
        }
    
      
    }
    
    else if (direction==3)   ///LEFT
    {
        if(canMoveLeft==true)
        {
        rect.move(-movement_speed, 0);
        sprite.setTextureRect(sf::IntRect(0, anime_frame*100, 80, 80));
            canMoveUp = true;
            canMoveDown = true;
            canMoveLeft = true;
            canMoveRight = true;
        }
        

        
        
    }
    else if (direction==4) //RIGHT
    {
        if(canMoveRight==true)
        {
        rect.move(movement_speed, 0);
        sprite.setTextureRect(sf::IntRect(200,anime_frame*100, 80, 80));
            canMoveUp = true;
            canMoveDown = true;
            canMoveLeft = true;
            canMoveRight = true;
        }
        
        
    }
    
    else
    {
        //NO MOVE
    }
    //random movement
    if(elapsed_movement.asSeconds()>=0.055)
    {
    anime_frame++;
    clock_movement.restart();
    }
    
    if(anime_frame==4)
    {
        anime_frame=0;
    }
    counterRandom++;
    if(counterRandom>=movement_lenght)
    {
        direction = generateRandom(5);
        counterRandom = 0;
    }
}


