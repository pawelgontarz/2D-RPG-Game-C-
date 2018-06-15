//
//  Door.hpp
//  RPG Game
//
//  Created by Mac Paweł on 20.05.2017.
//  Copyright © 2017 Macbook PRO 13. All rights reserved.
//

#ifndef Door_hpp
#define Door_hpp

#include <stdio.h>
#include "Object.hpp"

class Door : public Object
{
public:
    Door();
    bool can_go_next;
    void Update();
};

#endif /* Door_hpp */
