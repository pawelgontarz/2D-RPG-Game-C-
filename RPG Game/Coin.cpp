//
//  Coin.cpp
//  RPG Game
//
//  Created by Mac Paweł on 05.05.2017.
//  Copyright © 2017 Macbook PRO 13. All rights reserved.
//

#include "Coin.hpp"


Coin::Coin()
{
    rect.setSize(sf::Vector2f(50,50));
    rect.setFillColor(sf::Color::Green);
    rect.setPosition(0,0);
    
    
    //load texture
    if(!texture.loadFromFile(resourcePath()+"coins.png"))
    {
        cout<<"Cant load Coins.jpg!"<<endl;
        return EXIT_FAILURE;
    }
    //set sprites
    sprite.setTexture(texture);
    texture.setSmooth(true);
    sprite.setTextureRect(sf::IntRect(0,0,50,50));
    
    //SETTINGS
    anime_frame= 0;
    
    time = 0;
    destroy = false;
    value= 1;
    
    
    
    
}

void Coin::Update()
{
    sprite.setPosition(rect.getPosition());
    
    sf::Time elapsed = clock.getElapsedTime();
    
    if(anime_frame==0)
    {
        sprite.setTextureRect(sf::IntRect(0,0,50,50));
    }
    if(anime_frame==1)
    {
        sprite.setTextureRect(sf::IntRect(50,0,50,50));
        
    }
    if(anime_frame==2)
    {
        sprite.setTextureRect(sf::IntRect(100,0,50,50));
    }
    if(anime_frame==3)
    {
        sprite.setTextureRect(sf::IntRect(200,0,50,50));
    }
    if(anime_frame==4)
    {
        sprite.setTextureRect(sf::IntRect(250,0,50,50));
    }
    if(anime_frame==5)
    {
        sprite.setTextureRect(sf::IntRect(300,0,50,50));
    }
    if(anime_frame==6)
    {
        sprite.setTextureRect(sf::IntRect(350,0,50,50));
    }
    if(anime_frame==7)
    {
        sprite.setTextureRect(sf::IntRect(0,50,50,50));
    }
    if(anime_frame==8)
    {
        sprite.setTextureRect(sf::IntRect(50,50,50,50));
    }
    if(anime_frame==9)
    {
        sprite.setTextureRect(sf::IntRect(100,50,50,50));
    }
    if(anime_frame==10)
    {
        sprite.setTextureRect(sf::IntRect(150,50,50,50));
    }
    if(anime_frame==11)
    {
        sprite.setTextureRect(sf::IntRect(200,50,50,50));
    }
    if(anime_frame==12)
    {
        sprite.setTextureRect(sf::IntRect(250,50,50,50));
    }
    if(anime_frame==13)
    {
        sprite.setTextureRect(sf::IntRect(300,50,50,50));
    }
    if(anime_frame==14)
    {
        sprite.setTextureRect(sf::IntRect(350,50,50,50));
    }
    
    if(elapsed.asSeconds() >= 0.01)
    {
    anime_frame++;
    clock.restart();
    }
    
    if(anime_frame==14)
    {
        anime_frame=0;
    }
    
    
}
