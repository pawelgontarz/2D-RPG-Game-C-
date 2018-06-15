//
//  Object.hpp
//  Game
//
//  Created by Mac Paweł on 23.04.2017.
//  Copyright © 2017 Macbook PRO Paweł. All rights reserved.
//

#ifndef Object_hpp
#define Object_hpp

#include <stdio.h>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <ncurses.h>
#include <unistd.h>
#include "ResourcePath.hpp"
#include <iostream>
using namespace std;







class Object 
{
public:
    
    sf::RectangleShape rect;
    sf::Sprite sprite;
    sf::Texture texture;
    sf::Text text;
    
};

#endif  //Object_hpp



