//
//  RandomLib.cpp
//  RPG Game
//
//  Created by Mac Paweł on 01.05.2017.
//  Copyright © 2017 Macbook PRO 13. All rights reserved.
//

#include "RandomLib.hpp"
using namespace std;

int generateRandom(int max)
{
    int randomNumber = rand();
    float random = (randomNumber%max) + 1;
    int myRandom = random;
    return  myRandom;
}



