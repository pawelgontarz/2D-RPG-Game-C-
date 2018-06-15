//
//  Box.cpp
//  RPG Game
//
//  Created by Mac Paweł on 07.05.2017.
//  Copyright © 2017 Macbook PRO 13. All rights reserved.
//

#include "Box.hpp"


Box::Box()
{
    
    rect.setSize(sf::Vector2f(50,48));
    rect.setFillColor(sf::Color::Yellow);
    rect.setPosition(0,0);
    

        
        
        HP = 3;
    
        destroy = false;
        i= 0;
        startDestruction = false;
}

void Box::Update()
{
    sprite.setPosition(rect.getPosition());
}

void Box::destroyAnimation()
{
        if(i==0)
        {
          sprite.setTextureRect(sf::IntRect(0,0,50,48));
        }
        if(i==1)
        {
            sprite.setTextureRect(sf::IntRect(65,0,50,48));
        }
        if(i==2)
        {
            sprite.setTextureRect(sf::IntRect(126,0,50,48));
        }
        if(i==3)
        {
            sprite.setTextureRect(sf::IntRect(188,0,50,48));
        }
        if(i==4)
        {
            sprite.setTextureRect(sf::IntRect(0,52,50,48));
        }
        if(i==5)
        {
            sprite.setTextureRect(sf::IntRect(65,52,50,48));
        }
        if(i==6)
        {
            sprite.setTextureRect(sf::IntRect(130,52,50,48));
        }
        if(i==7)
        {
            sprite.setTextureRect(sf::IntRect(190,52,50,48));
        }
        if(i==8)
        {
            sprite.setTextureRect(sf::IntRect(0,102,50,48));
        }
        if(i==9)
        {
            sprite.setTextureRect(sf::IntRect(65,102,50,48));
        }
        if(i==10)
        {
            sprite.setTextureRect(sf::IntRect(130,102,50,48));
        }
        if(i==11)
        {
            sprite.setTextureRect(sf::IntRect(190,102,50,48));
        }
       
 
    
   
}

