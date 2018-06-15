//
//  Audio.hpp
//  RPG Game
//
//  Created by Mac Paweł on 02.05.2017.
//  Copyright © 2017 Macbook PRO 13. All rights reserved.
//

#ifndef Audio_hpp
#define Audio_hpp

#include <stdio.h>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <ncurses.h>
#include <unistd.h>
#include "ResourcePath.hpp"
#include <iostream>
#include "RandomLib.hpp"

class Audio
{
public:
    
    
    //buffers
    sf::SoundBuffer buffer1;
    sf::SoundBuffer buffer2;
    sf::SoundBuffer buffer3;
    sf::SoundBuffer buffer4;
    sf::SoundBuffer buffer5;
    sf::SoundBuffer buffer6;
    sf::SoundBuffer bufferCoin;
    sf::SoundBuffer bufferPunch[3];
    sf::SoundBuffer bufferChoose_menu;
    sf::SoundBuffer bufferEnemyIsHere[4];
    sf::SoundBuffer bufferEnemyBite[3];
    sf::SoundBuffer bufferEnemyDead;
    sf::SoundBuffer bufferSelect;
    sf::SoundBuffer buffer_enemy_shoot;
    
    
    //sounds
    sf::Sound soundMovement;
    sf::Sound soundShooting[5];
    sf::Sound soundGetCoin;
    sf::Sound soundPunch[4];
    sf::Sound sounChoose_Menu;
    sf::Sound soundEnemyIsHere[5]; // 1-4, without 0
    sf::Sound soundEnemyBite[4];// 1-3, without 0
    sf::Sound soundEnemyDead;
    sf::Sound soundSelect;
    sf::Sound sound_enemy_shoot;
    
    

    
    
    Audio();
    ~Audio();
    
    void movement();
    void shooting(int shoot);
    void getCoin();
    void getPunch();
    void chooseMenu();
    void enemyIsHere(int change_sound);
    void enemyBite();
    void enemyDead();
    void select();
    void enemy_shooting();

    



  
};


#endif /* Audio_hpp */
