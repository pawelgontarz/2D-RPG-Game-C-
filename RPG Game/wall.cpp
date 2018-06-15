//
//  wall.cpp
//  RPG Game
//
//  Created by Mac Paweł on 05.05.2017.
//  Copyright © 2017 Macbook PRO 13. All rights reserved.
//

#include "wall.hpp"

Wall::Wall()
{
    rect.setSize(sf::Vector2f(50,50));
    rect.setFillColor(sf::Color::Green);
    rect.setPosition(0,0);
   /*
    //load texture
    if(!texture.loadFromFile(resourcePath()+"tile_elements.png"))
    {
        cout<<"Cant load Coins.jpg!"<<endl;
        return EXIT_FAILURE;
    }
   */
    
    HP = 2;
    canDestroy = false;
    destroy = false;
    
    
}


void Wall::Update()
{

    //set sprites
    //sprite.setTexture(texture);
    texture.setSmooth(true);
    //sprite.setTextureRect(sf::IntRect(0,50,50,50));
     sprite.setPosition(rect.getPosition());
}
