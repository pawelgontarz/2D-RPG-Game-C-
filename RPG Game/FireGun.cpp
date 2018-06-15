//
//  FireGun.cpp
//  RPG Game
//
//  Created by Mac Paweł on 26.05.2017.
//  Copyright © 2017 Macbook PRO 13. All rights reserved.
//

#include "FireGun.hpp"


FireGun::FireGun()
{
    rect.setSize(sf::Vector2f(80,80));
    rect.setFillColor(sf::Color::Green);
    rect.setPosition(0,0);
    
    
    //load textures
    if(!texture.loadFromFile(resourcePath()+"fire_gun.png"))
    {
        cout<<"Cant load fire_gun.png"<<endl;
        return EXIT_FAILURE;
    }
    
    
    //set sprites
    sprite.setTexture(texture);
    texture.setSmooth(true);
    sprite.setTextureRect(sf::IntRect(0,0,80,80));
    
    
    //SETTINGS
    anime_frame= 0;
    
    price = 15;
    name = "Ognisty jezyk";
    damage = 5;
    
}

void FireGun::Update()
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
    if(anime_frame==5)
    {
        sprite.setTextureRect(sf::IntRect(400,0,80,80));
    }
    
    if(anime_frame==6)
    {
        sprite.setTextureRect(sf::IntRect(480,0,80,80));
    }
    if(anime_frame==7)
    {
        sprite.setTextureRect(sf::IntRect(560,0,80,80));
    }
    if(anime_frame==8)
    {
        sprite.setTextureRect(sf::IntRect(640,0,80,80));
    }
    if(anime_frame==8)
    {
        sprite.setTextureRect(sf::IntRect(720,0,80,80));
    }
    if(elapsed.asSeconds() >= 0.08)
    {
        anime_frame++;
        clock.restart();
    }
    
    if(anime_frame==9)
    {
        anime_frame = 0;
    }
    
}
