//
//  Libraries.cpp
//  RPG Game
//
//  Created by Mac Paweł on 12.05.2017.
//  Copyright © 2017 Macbook PRO 13. All rights reserved.
//

#include "Libraries.hpp"



float check_distance ( int posX1, int posY1, int posX2, int posY2)
{
    float distance;
    distance = sqrtf((posX2-posX1)*(posX2-posX1)+(posY2-posY1)*(posY2-posY1));
    return distance;
}
