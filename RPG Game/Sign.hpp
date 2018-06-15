//
//  Sign.hpp
//  RPG Game
//
//  Created by Mac Paweł on 31.05.2017.
//  Copyright © 2017 Macbook PRO 13. All rights reserved.
//

#ifndef Sign_hpp
#define Sign_hpp

#include <stdio.h>
#include "Object.hpp"

class Sign : public Object
{
public:
    Sign();
    bool can_go_next;
    void Update();
};
#endif /* Sign_hpp */
