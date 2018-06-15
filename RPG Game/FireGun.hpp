//
//  FireGun.hpp
//  RPG Game
//
//  Created by Mac Paweł on 26.05.2017.
//  Copyright © 2017 Macbook PRO 13. All rights reserved.
//

#ifndef FireGun_hpp
#define FireGun_hpp

#include <stdio.h>
#include "Object.hpp"

class FireGun: public Object
{
    
public:
    sf::Texture texture;
    sf::Sprite sprite;
    int anime_frame;
    int price;
    sf::Clock clock;
    string name;
    int damage;
    
    FireGun();
    
    
    void Update();
    
};

#endif /* FireGun_hpp */
