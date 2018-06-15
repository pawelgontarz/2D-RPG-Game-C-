//
//  Music.hpp
//  RPG Game
//
//  Created by Mac Paweł on 11.05.2017.
//  Copyright © 2017 Macbook PRO 13. All rights reserved.
//

#ifndef Music_hpp
#define Music_hpp

#include <stdio.h>
#include <SFML/Audio.hpp>
#include "ResourcePath.hpp"
#include <iostream>


class Music
{
public:
    sf::Music scary_music;
    sf::Music music_level1;
    sf::Music musicMenu;
    sf::Music musicLose;
    sf::Music music_shop;
    sf::Music music_level3;
    
    Music();
    
 
};
#endif /* Music_hpp */
