//
//  Door.cpp
//  RPG Game
//
//  Created by Mac Paweł on 20.05.2017.
//  Copyright © 2017 Macbook PRO 13. All rights reserved.
//

#include "Door.hpp"

Door::Door()
{
    rect.setSize(sf::Vector2f(30,30));
    rect.setFillColor(sf::Color::Red);
    rect.setPosition(0,0);
    can_go_next = false;
}


void Door::Update()
{
    sprite.setPosition(rect.getPosition());
}
