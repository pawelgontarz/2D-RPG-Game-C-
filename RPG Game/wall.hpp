//
//  wall.hpp
//  RPG Game
//
//  Created by Mac Paweł on 05.05.2017.
//  Copyright © 2017 Macbook PRO 13. All rights reserved.
//

#ifndef wall_hpp
#define wall_hpp

#include <stdio.h>
#include "Object.hpp"


class Wall : public Object
{
    
public:
    
    
    Wall();
    bool canDestroy;
    bool destroy;
    int HP;
    void Update();
};

#endif /* wall_hpp */
