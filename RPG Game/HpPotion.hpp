//
//  HpPotion.hpp
//  RPG Game
//
//  Created by Mac Paweł on 26.05.2017.
//  Copyright © 2017 Macbook PRO 13. All rights reserved.
//

#ifndef HpPotion_hpp
#define HpPotion_hpp

#include <stdio.h>
#include "Object.hpp"

class HpPotion: public Object
{
    
public:
    sf::Texture texture;
    sf::Sprite sprite;
    int anime_frame;
    int price;
    sf::Clock clock;
    
    HpPotion();
    
    
    void Update();
    
};


#endif /* HpPotion_hpp */
