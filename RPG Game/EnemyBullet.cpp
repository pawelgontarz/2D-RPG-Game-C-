//
//  EnemyBullet.cpp
//  RPG Game
//
//  Created by Mac Paweł on 02.06.2017.
//  Copyright © 2017 Macbook PRO 13. All rights reserved.
//

#include "EnemyBullet.hpp"


EnemyBullet::EnemyBullet()
{
    rect.setSize(sf::Vector2f(32,32));
    rect.setFillColor(sf::Color::Transparent);
    rect.setPosition(0,0);
    // rect.setTextureRect(sf::IntRect(0,0,32,32));
    
    //load texture
    if(!texture.loadFromFile(resourcePath()+"FireBall.PNG"))
    {
        cout<<"Cant load FireBall.PNG!"<<endl;
        return EXIT_FAILURE;
    }
    //set sprites
    sprite.setTexture(texture);
    texture.setSmooth(true);
    sprite.setTextureRect(sf::IntRect(0,0,32,32));
    
    
    
    movement_speed=4;
    direction = 1;
    destroyBullet =false;
    bulletLifeCounter = 0;
    bulletLifeTime = 8;
    anime_frame = 0;
}

EnemyBullet::~EnemyBullet()
{
    
}

void EnemyBullet::Update()
{
    sf::Time elapsed_movement = clock_movement.getElapsedTime();
    sf::Time elapsed_movement_speed = clock_movement_speed.getElapsedTime();
    
    sprite.setPosition(rect.getPosition());
    if(direction ==1 )//down
    {
        rect.move(0, movement_speed);
        sprite.setTextureRect(sf::IntRect(anime_frame*60,0,60,60));
    }
    
    if(direction ==2 )//up
    {
        rect.move(0, -movement_speed);
        sprite.setTextureRect(sf::IntRect(anime_frame*60,3*60,60,60));
    }
    
    if(direction ==3 )//left
    {
        rect.move(-movement_speed, 0);
        sprite.setTextureRect(sf::IntRect(anime_frame*60,1*60,60,60));
    }
    
    if(direction ==4 )//right
    {
        rect.move(movement_speed, 0);
        sprite.setTextureRect(sf::IntRect(anime_frame*60,2*60,60,60));
    }
    
    
    
    if(bulletLifeCounter>=bulletLifeTime)
    {
        destroyBullet = true;
    }
    
    if(elapsed_movement.asSeconds()>=0.1)
    {
        movement_speed+=2;
        bulletLifeCounter++;
        anime_frame++;
        clock_movement.restart();
    }
    if(elapsed_movement_speed.asSeconds()>=1)
    {
        movement_speed+=1;
        bulletLifeCounter++;
        clock_movement_speed.restart();
    }
    
    if(anime_frame==3)
    {
        anime_frame=0;
    }
    
}
