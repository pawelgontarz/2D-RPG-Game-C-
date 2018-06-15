//
//  ItemShop.hpp
//  RPG Game
//
//  Created by Mac Paweł on 20.05.2017.
//  Copyright © 2017 Macbook PRO 13. All rights reserved.
//

#ifndef Poskramiacz_hpp
#define Poskramiacz_hpp
#include "Object.hpp"
#include <stdio.h>

class Poskramiacz: public Object
{
    
public:
    sf::Texture texture;
    sf::Sprite sprite;
    int anime_frame;
    int price;
    sf::Clock clock;
    string name;
    int damage;
    
     Poskramiacz();

    
    void Update();
    
};

#endif /* Poskramiacz_hpp */
