//
//  Star_bullet.cpp
//  RPG Game
//
//  Created by Mac Paweł on 07.06.2017.
//  Copyright © 2017 Macbook PRO 13. All rights reserved.
//

#include "Star_bullet.hpp"



Bullet_Star::Bullet_Star()
{
    rect.setSize(sf::Vector2f(40,40));
    rect.setFillColor(sf::Color::Transparent);
    rect.setPosition(0,0);
    // rect.setTextureRect(sf::IntRect(0,0,32,32));
    
    //load texture
    if(!texture.loadFromFile(resourcePath()+"star_bullets.png"))
    {
        cout<<"Cant load star_bullets.png!"<<endl;
        return EXIT_FAILURE;
    }
    //set sprites
    sprite.setTexture(texture);
    texture.setSmooth(true);
    sprite.setTextureRect(sf::IntRect(0,0,40,40));
    
    
    
    movement_speed=1;
    direction = 1;
    destroyBullet =false;
    bulletLifeCounter = 0;
    bulletLifeTime = 25;
    anime_frame = 0;
}

Bullet_Star::~Bullet_Star()
{
    
}

void Bullet_Star::Update()
{
    sf::Time elapsed_movement = clock_movement.getElapsedTime();
    sf::Time elapsed_movement_speed = clock_movement_speed.getElapsedTime();
    
    sprite.setPosition(rect.getPosition());
    if(direction ==1 )//down
    {
        rect.move(0, movement_speed);
        sprite.setTextureRect(sf::IntRect(anime_frame*40,0,40,40));
    }
    
    if(direction ==2 )//up
    {
        rect.move(0, -movement_speed);
        sprite.setTextureRect(sf::IntRect(anime_frame*40,0,40,40));
    }
    
    if(direction ==3 )//left
    {
        rect.move(-movement_speed, 0);
        sprite.setTextureRect(sf::IntRect(anime_frame*40,0,40,40));
    }
    
    if(direction ==4 )//right
    {
        rect.move(movement_speed, 0);
        sprite.setTextureRect(sf::IntRect(anime_frame*40,0,40,40));
    }
    
    
    
    if(bulletLifeCounter>=bulletLifeTime)
    {
        destroyBullet = true;
    }
    
    if(elapsed_movement.asSeconds()>=0.08)
    {
        movement_speed=movement_speed*2.2;
        bulletLifeCounter++;
        anime_frame++;
        clock_movement.restart();
    }

    if(anime_frame==4)
    {
        anime_frame=0;
    }
    
}
