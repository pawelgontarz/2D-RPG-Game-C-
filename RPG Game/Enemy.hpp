//
//  Enemy.hpp
//  RPG Game
//
//  Created by Mac Paweł on 01.05.2017.
//  Copyright © 2017 Macbook PRO 13. All rights reserved.
//

#ifndef Enemy_hpp
#define Enemy_hpp

#include "Object.hpp"
#include "RandomLib.hpp"
using namespace std;

class Enemy: public Object
{
public:
    int movement_speed;
    int anime_frame;
    int time;
    int direction; //1 -> down, 2 -> up, 3 -> left , 4 -> right
    int counterRandom;
    int movement_lenght;
    int HP;
    int attackDamage;
    bool alive;
    bool canBeInvisible;
    bool aggroed;
    sf::Clock clock_movement;
    
    bool canMoveUp;
    bool canMoveDown;
    bool canMoveRight;
    bool canMoveLeft;
    
    Enemy();
    ~Enemy();
    
    void Update();
    void Movement_Wolf();
    
    
    
    sf::Sprite sprite;
    sf::Texture texture;

    
};
#endif /* Enemy_hpp */
