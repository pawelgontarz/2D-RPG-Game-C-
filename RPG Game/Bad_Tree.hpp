//
//  Bad_Tree.hpp
//  RPG Game
//
//  Created by Mac Paweł on 02.06.2017.
//  Copyright © 2017 Macbook PRO 13. All rights reserved.
//

#ifndef Bad_Tree_hpp
#define Bad_Tree_hpp

#include "Object.hpp"
#include "RandomLib.hpp"
using namespace std;

class Bad_Tree: public Object
{
public:
    int anime_frame;
    int HP;
    int attackDamage;
    bool alive;
    sf::Clock clock_frame;
    
    
    Bad_Tree();
    ~Bad_Tree();
    
    void Update();
    
    
};


#endif /* Bad_Tree_hpp */
