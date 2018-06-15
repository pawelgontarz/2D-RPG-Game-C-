//
//  Ring.hpp
//  RPG Game
//
//  Created by Mac Paweł on 26.05.2017.
//  Copyright © 2017 Macbook PRO 13. All rights reserved.
//

#ifndef Ring_hpp
#define Ring_hpp

#include <stdio.h>
#include "Object.hpp"

class Ring: public Object
{
    
public:
    sf::Texture texture;
    sf::Sprite sprite;
    int anime_frame;
    int price;
    sf::Clock clock;
    int max_HP;
    Ring();
    
    
    void Update();
    
};

#endif /* Ring_hpp */
