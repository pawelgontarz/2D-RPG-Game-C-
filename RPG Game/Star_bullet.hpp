//
//  Star_bullet.hpp
//  RPG Game
//
//  Created by Mac Paweł on 07.06.2017.
//  Copyright © 2017 Macbook PRO 13. All rights reserved.
//

#ifndef Star_bullet_hpp
#define Star_bullet_hpp

#include <stdio.h>
#include "Object.hpp"


class Bullet_Star: public Object
{
public:
    
    int movement_speed;
    int direction; //1 -> down, 2 -> up, 3 -> left , 4 -> right
    bool destroyBullet;
    int bulletLifeCounter;
    int bulletLifeTime;
    int anime_frame;
    
    
    Bullet_Star();
    ~Bullet_Star();
    void Update();
    
    
    sf::Clock clock_movement;
    sf::Clock clock_movement_speed;
    
    sf::Sprite sprite;
    sf::Texture texture;
    
    
    
    
    
    
};


#endif /* Star_bullet_hpp */
