//
//  FreezeGun.hpp
//  RPG Game
//
//  Created by Mac Paweł on 26.05.2017.
//  Copyright © 2017 Macbook PRO 13. All rights reserved.
//

#ifndef FreezeGun_hpp
#define FreezeGun_hpp

#include <stdio.h>
#include "Object.hpp"

class FreezeGun: public Object
{
    
public:
    sf::Texture texture;
    sf::Sprite sprite;
    int anime_frame;
    int price;
    sf::Clock clock;
    string name;
    int damage;
    
    FreezeGun();
    
    
    void Update();
    
};

#endif /* FreezeGun.hpp */
