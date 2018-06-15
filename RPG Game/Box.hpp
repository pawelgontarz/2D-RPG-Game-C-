//
//  Box.hpp
//  RPG Game
//
//  Created by Mac Paweł on 07.05.2017.
//  Copyright © 2017 Macbook PRO 13. All rights reserved.
//

#ifndef Box_hpp
#define Box_hpp

#include <stdio.h>
#include "Object.hpp"

class Box: public Object
{
public:
    
    
    Box();
    bool destroy;
    int HP;
    void Update();
    void destroyAnimation();
    int i;
    bool startDestruction;
    
};

#endif /* Box_hpp */
