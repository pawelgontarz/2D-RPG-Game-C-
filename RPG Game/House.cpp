//
//  House.cpp
//  RPG Game
//
//  Created by Mac Paweł on 19.05.2017.
//  Copyright © 2017 Macbook PRO 13. All rights reserved.
//

#include "House.hpp"


House::House()
{
    rect.setSize(sf::Vector2f(318,366));
    rect.setFillColor(sf::Color::Yellow);
    rect.setPosition(0,0);
    
}

void House::Update()
{
         sprite.setPosition(rect.getPosition());
}
