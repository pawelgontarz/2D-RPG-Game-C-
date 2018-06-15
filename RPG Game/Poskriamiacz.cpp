//
//  ItemShop.cpp
//  RPG Game
//
//  Created by Mac Paweł on 20.05.2017.
//  Copyright © 2017 Macbook PRO 13. All rights reserved.
//

#include "Poskramiacz.hpp"


Poskramiacz::Poskramiacz()
{
    rect.setSize(sf::Vector2f(80,80));
    rect.setFillColor(sf::Color::Green);
    rect.setPosition(0,0);
    
    
    //load textures
    if(!texture.loadFromFile(resourcePath()+"Poskramiacz.png"))
    {
        cout<<"Cant load Poskramiacz.png!"<<endl;
        return EXIT_FAILURE;
    }
    
   
    //set sprites
    sprite.setTexture(texture);
    texture.setSmooth(true);
    sprite.setTextureRect(sf::IntRect(0,0,80,80));
   
    
    //SETTINGS
    anime_frame= 0;
    
    //VALUE
    price = 10;
    
    name = "Poskramiacz";
    damage = 3;

    
}

void Poskramiacz::Update()
{
   
    
   
    sprite.setPosition(rect.getPosition());
    sf::Time elapsed = clock.getElapsedTime();
    sprite.setTextureRect(sf::IntRect(80*anime_frame,0,80,80));
    if(elapsed.asSeconds() >= 0.08)
    {
        anime_frame++;
        clock.restart();
    }
    
    if(anime_frame==9)
    {
        anime_frame=0;
    }

}

