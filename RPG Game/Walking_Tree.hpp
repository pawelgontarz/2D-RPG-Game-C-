//
//  Walking_Tree.hpp
//  RPG Game
//
//  Created by Mac Paweł on 02.06.2017.
//  Copyright © 2017 Macbook PRO 13. All rights reserved.
//

#ifndef Walking_Tree_hpp
#define Walking_Tree_hpp

#include "Object.hpp"
#include "RandomLib.hpp"
using namespace std;

class Walking_Tree: public Object
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
    bool aggroed;
    sf::Clock clock_movement;
    
    bool canMoveUp;
    bool canMoveDown;
    bool canMoveRight;
    bool canMoveLeft;
    
    Walking_Tree();
    ~Walking_Tree();
    
    void Update();
    void Movement();
    
};

#endif /* Walking_Tree_hpp */
