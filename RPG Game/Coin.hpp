//
//  Coin.hpp
//  RPG Game
//
//  Created by Mac Paweł on 05.05.2017.
//  Copyright © 2017 Macbook PRO 13. All rights reserved.
//

#ifndef Coin_hpp
#define Coin_hpp
#include "Object.hpp"
#include <stdio.h>

class Coin: public Object
{

    
public:
    
    int anime_frame;
    int time;
    bool destroy;
    int value;
    sf::Clock clock;
    
    Coin();
    void Update();
    
};

#endif /* Coin_hpp */
