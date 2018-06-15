//
//  EnemyBullet.hpp
//  RPG Game
//
//  Created by Mac Paweł on 02.06.2017.
//  Copyright © 2017 Macbook PRO 13. All rights reserved.
//

#ifndef EnemyBullet_hpp
#define EnemyBullet_hpp

#include <stdio.h>
#include "Object.hpp"




class EnemyBullet: public Object
{
public:
    
    int movement_speed;
    int direction; //1 -> down, 2 -> up, 3 -> left , 4 -> right
    bool destroyBullet;
    int bulletLifeCounter;
    int bulletLifeTime;
    int anime_frame;
    
    
    EnemyBullet();
    ~EnemyBullet();
    void Update();
    
    
    sf::Clock clock_movement;
    sf::Clock clock_movement_speed;
};

#endif /* EnemyBullet_hpp */
