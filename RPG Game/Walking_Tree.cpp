//
//  Walking_Tree.cpp
//  RPG Game
//
//  Created by Mac Paweł on 02.06.2017.
//  Copyright © 2017 Macbook PRO 13. All rights reserved.
//






#include "Walking_Tree.hpp"

using namespace std;




Walking_Tree::Walking_Tree()

{
    
    
    rect.setSize(sf::Vector2f(96,96));
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
    
    sprite.setTextureRect(sf::IntRect(0,0,96,96));
    
    
}

Walking_Tree::~Walking_Tree()
{
    
}



void Walking_Tree::Update()
{
    sprite.setPosition(rect.getPosition());
    
}


void Walking_Tree::Movement()
{
    
    
    sf::Time elapsed_movement = clock_movement.getElapsedTime();
    
    if (direction==2) ////UP
    {
        if(canMoveUp==true)
        {
            rect.move(0, -movement_speed); ///UP
            sprite.setTextureRect(sf::IntRect(96*anime_frame ,96*3, 96, 96));
            
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
            sprite.setTextureRect(sf::IntRect(96*anime_frame,0,96,96));
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
            sprite.setTextureRect(sf::IntRect(96*anime_frame, 96, 96, 96));
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
            sprite.setTextureRect(sf::IntRect(96*anime_frame,96*2, 96, 96));
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
    if(elapsed_movement.asSeconds()>=0.05)
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


