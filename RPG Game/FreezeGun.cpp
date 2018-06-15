//
//  freeze_gun.cpp
//  RPG Game
//
//  Created by Mac Paweł on 26.05.2017.
//  Copyright © 2017 Macbook PRO 13. All rights reserved.
//

#include "FreezeGun.hpp"

FreezeGun::FreezeGun()
{
    rect.setSize(sf::Vector2f(80,80));
    rect.setFillColor(sf::Color::Green);
    rect.setPosition(0,0);
    
    
    //load textures
    if(!texture.loadFromFile(resourcePath()+"freeze_gun.png"))
    {
        cout<<"Cant load freeze_gun.png"<<endl;
        return EXIT_FAILURE;
    }
    
    
    //set sprites
    sprite.setTexture(texture);
    texture.setSmooth(true);
    sprite.setTextureRect(sf::IntRect(0,0,80,80));
    
    
    //SETTINGS
    anime_frame= 0;
    
    price = 5;
    name = "Lodowa zamiec";
    damage = 2;
}

void FreezeGun::Update()
{
    
    
    
    sprite.setPosition(rect.getPosition());
    sf::Time elapsed = clock.getElapsedTime();
    if(anime_frame==0)
    {
        sprite.setTextureRect(sf::IntRect(0,0,80,80));
    }
    if(anime_frame==1)
    {
        sprite.setTextureRect(sf::IntRect(80,0,80,80));
    }
    if(anime_frame==2)
    {
        sprite.setTextureRect(sf::IntRect(160,0,80,80));
    }
    if(anime_frame==3)
    {
        sprite.setTextureRect(sf::IntRect(240,0,80,80));
    }
    if(anime_frame==4)
    {
        sprite.setTextureRect(sf::IntRect(320,0,80,80));
    }

       
    if(elapsed.asSeconds() >= 0.08)
    {
        anime_frame++;
        clock.restart();
    }
    
    if(anime_frame==4)
    {
        anime_frame = 0;
    }
    
}

