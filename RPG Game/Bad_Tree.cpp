//
//  Bad_Tree.cpp
//  RPG Game
//
//  Created by Mac Paweł on 02.06.2017.
//  Copyright © 2017 Macbook PRO 13. All rights reserved.
//

#include "Bad_Tree.hpp"

Bad_Tree::Bad_Tree()
{
    
    
    rect.setSize(sf::Vector2f(200,200));
    rect.setFillColor(sf::Color::Green);
    rect.setPosition(0,0);
    
    anime_frame = 0;
    //STATS
    HP=10;
    attackDamage = 2;
    alive = true;
    
    
    
}
Bad_Tree::~Bad_Tree()
{
    
}

void Bad_Tree::Update()
{
    sprite.setPosition(rect.getPosition());
    sf::Time elapsed_frame = clock_frame.getElapsedTime();
    
    sprite.setTextureRect(sf::IntRect(200*anime_frame,0, 200, 200));
    
    if(elapsed_frame.asSeconds()>=0.1)
    {
        anime_frame++;
        clock_frame.restart();
    }
    
    if(anime_frame==4)
    {
        anime_frame=0;
    }
    
}
