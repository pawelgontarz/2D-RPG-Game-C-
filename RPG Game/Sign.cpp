//
//  Sign.cpp
//  RPG Game
//
//  Created by Mac Paweł on 31.05.2017.
//  Copyright © 2017 Macbook PRO 13. All rights reserved.
//

#include "Sign.hpp"


Sign::Sign()
{
    rect.setSize(sf::Vector2f(150,150));
    rect.setFillColor(sf::Color::Red);
    rect.setPosition(0,0);
    can_go_next = false;
}


void Sign::Update()
{
    sprite.setPosition(rect.getPosition());
}
