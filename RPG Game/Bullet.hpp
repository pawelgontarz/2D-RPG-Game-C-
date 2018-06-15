//
//  Bullet.hpp
//  RPG Game
//
//  Created by Mac Paweł on 30.04.2017.
//  Copyright © 2017 Macbook PRO 13. All rights reserved.
//

#ifndef Bullet_hpp
#define Bullet_hpp

#include <stdio.h>
#include "Object.hpp"




class Bullet: public Object
{
public:
    
    int movement_speed;
    int direction; //1 -> down, 2 -> up, 3 -> left , 4 -> right
    bool destroyBullet;
    int bulletLifeCounter;
    int bulletLifeTime;
    int anime_frame;
    
    
    Bullet();
   ~Bullet();
    void Update();

    
    sf::Clock clock_movement;
    sf::Clock clock_movement_speed;
    
    sf::Sprite sprite;
    sf::Texture texture;

    
    

    
    
};

#endif /* Bullet_hpp */
