//
//  Audio.cpp
//  RPG Game
//
//  Created by Mac Paweł on 02.05.2017.
//  Copyright © 2017 Macbook PRO 13. All rights reserved.
//

#include "Audio.hpp"
using namespace std;

Audio::Audio()
{
    
    //load sounds
    if(!buffer1.loadFromFile(resourcePath() + "moving_step.wav"))
    {
        cout<<"Cant load file moving_step.wav! "<<endl;
        return EXIT_FAILURE;
    }
    soundMovement.setBuffer(buffer1);
    

    if(!buffer2.loadFromFile(resourcePath() + "magicShoot1.wav"))
    {
        cout<<"Cant load file  magicShoot1.wav! "<<endl;
        return EXIT_FAILURE;
    }
    soundShooting[0].setBuffer(buffer2);
    
    
    if(!buffer3.loadFromFile(resourcePath() + "magicShoot2.wav"))
    {
        cout<<"Cant load file  magicShoot2.wav! "<<endl;
        return EXIT_FAILURE;
    }
    soundShooting[1].setBuffer(buffer3);
    
    if(!buffer4.loadFromFile(resourcePath() + "magicShoot3.wav"))
    {
        cout<<"Cant load file  magicShoot3.wav! "<<endl;
        return EXIT_FAILURE;
    }
    soundShooting[2].setBuffer(buffer4);
    
    if(!buffer5.loadFromFile(resourcePath() + "magicShoot4.wav"))
    {
        cout<<"Cant load file  magicShoot4.wav! "<<endl;
        return EXIT_FAILURE;
    }
    soundShooting[3].setBuffer(buffer5);
    
    if(!buffer6.loadFromFile(resourcePath() + "magicShoot5.wav"))
    {
        cout<<"Cant load file  magicShoot5.wav! "<<endl;
        return EXIT_FAILURE;
    }
    soundShooting[4].setBuffer(buffer2);
    //get coin
    if(!bufferCoin.loadFromFile(resourcePath() + "pickup_coin.wav"))
    {
        cout<<"Cant load file  pickup_coin.wav! "<<endl;
        return EXIT_FAILURE;
    }
    soundGetCoin.setBuffer(bufferCoin);
    
    //punch 0
    if(!bufferPunch[0].loadFromFile(resourcePath() + "punch.wav"))
    {
        cout<<"Cant load file  punch.wav! "<<endl;
        return EXIT_FAILURE;
    }
    soundPunch[1].setBuffer(bufferPunch[0]);
    
    //punch 1
    if(!bufferPunch[1].loadFromFile(resourcePath() + "PUNCH1.wav"))
    {
        cout<<"Cant load file  PUNCH1.wav! "<<endl;
        return EXIT_FAILURE;
    }
    soundPunch[2].setBuffer(bufferPunch[1]);
    
    //punch 2
    if(!bufferPunch[2].loadFromFile(resourcePath() + "PUNCH_2.wav"))
    {
        cout<<"Cant load file  PUNCH_2.wav! "<<endl;
        return EXIT_FAILURE;
    }
    soundPunch[3].setBuffer(bufferPunch[2]);

    
    //choose menu
    if(!bufferChoose_menu.loadFromFile(resourcePath() + "choose_menu.wav"))
    {
        cout<<"Cant load file  choose_menu.wav! "<<endl;
        return EXIT_FAILURE;
    }
    sounChoose_Menu.setBuffer(bufferChoose_menu);
    
    ////////////ENEMY IS HERE SOUND
    //predator sound
    if(!bufferEnemyIsHere[0].loadFromFile(resourcePath() + "predator_sound.wav"))
    {
        cout<<"Cant load file  predator_sound.wav! "<<endl;
        return EXIT_FAILURE;
    }
    soundEnemyIsHere[1].setBuffer(bufferEnemyIsHere[0]);
    
    //howling wolf sound
    if(!bufferEnemyIsHere[1].loadFromFile(resourcePath() + "howling_wolf.wav"))
    {
        cout<<"Cant load file   howling_wolf.wav! "<<endl;
        return EXIT_FAILURE;
    }
    soundEnemyIsHere[2].setBuffer(bufferEnemyIsHere[1]);
    //howling wolf sound
    if(!bufferEnemyIsHere[2].loadFromFile(resourcePath() + "wolf3.wav"))
    {
        cout<<"Cant load file  wolf3.wav! "<<endl;
        return EXIT_FAILURE;
    }
    soundEnemyIsHere[3].setBuffer(bufferEnemyIsHere[2]);
    //howling wolf sound
    if(!bufferEnemyIsHere[3].loadFromFile(resourcePath() + "wolf5.wav"))
    {
        cout<<"Cant load file  wolf5.wav! "<<endl;
        return EXIT_FAILURE;
    }
    soundEnemyIsHere[4].setBuffer(bufferEnemyIsHere[3]);

    //sound enemy bite
    if(!bufferEnemyBite[0].loadFromFile(resourcePath() + "bite1.wav"))
    {
        cout<<"Cant load file  bite1.wav! "<<endl;
        return EXIT_FAILURE;
    }
    soundEnemyBite[1].setBuffer(bufferEnemyBite[0]);
    
    //sound enemy bite
    if(!bufferEnemyBite[1].loadFromFile(resourcePath() + "bite2.wav"))
    {
        cout<<"Cant load file  bite2.wav! "<<endl;
        return EXIT_FAILURE;
    }
    soundEnemyBite[2].setBuffer(bufferEnemyBite[1]);
    
    //sound enemy bite
    if(!bufferEnemyBite[2].loadFromFile(resourcePath() + "bite3.wav"))
    {
        cout<<"Cant load file  bite3.wav! "<<endl;
        return EXIT_FAILURE;
    }
    soundEnemyBite[3].setBuffer(bufferEnemyBite[2]);
    
    
    //sound enemy dead
    if(!bufferEnemyDead.loadFromFile(resourcePath() + "SPLAT.wav"))
    {
        cout<<"Cant load file  SPLAT.wav! "<<endl;
        return EXIT_FAILURE;
    }
    soundEnemyDead.setBuffer(bufferEnemyDead);
    
    //sound select
    if(!bufferSelect.loadFromFile(resourcePath() + "select.wav"))
    {
        cout<<"Cant load file  select.wav! "<<endl;
        return EXIT_FAILURE;
    }
    soundSelect.setBuffer(bufferSelect);
    
    //sound enemy shoot
    if(!buffer_enemy_shoot.loadFromFile(resourcePath() + "enemy_shoot.wav"))
    {
        cout<<"Cant load file  enemy_shoot.wav! "<<endl;
        return EXIT_FAILURE;
    }
    sound_enemy_shoot.setBuffer(buffer_enemy_shoot);
   

    
    
}

Audio::~Audio()
{
    
}

void Audio::movement()
{
    soundMovement.setVolume(80);
    soundMovement.play();
    
}

void Audio::getCoin()
{
    soundGetCoin.play();
    
}

void Audio::getPunch()
{
    int change_punch = generateRandom(3);
    soundPunch[change_punch].setVolume(15);
    soundPunch[change_punch].play();
}

void Audio::shooting(int shoot)
{
    
  // int shoot = generateRandom(4);
    soundShooting[shoot].setVolume(70);
    soundShooting[shoot].play();
}
void Audio::enemyBite()
{
    int change_sound_bite = generateRandom(3);
    soundEnemyBite[change_sound_bite].setVolume(20);
    soundEnemyBite[change_sound_bite].play();
}

void Audio::chooseMenu()
{
    sounChoose_Menu.play();
}

void Audio::enemyIsHere(int change_sound)
{
    soundEnemyIsHere[change_sound].setVolume(50);
    soundEnemyIsHere[change_sound].play();
}


void Audio::enemyDead()
{
    soundEnemyDead.setVolume(50);
    soundEnemyDead.play();
}

void Audio::select()
{
    soundSelect.setVolume(50);
    soundSelect.play();
}

void Audio::enemy_shooting()
{
    sound_enemy_shoot.setVolume(70);
    sound_enemy_shoot.play();
}




