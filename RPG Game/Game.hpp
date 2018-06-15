//
//  Game.hpp
//  RPG Game
//
//  Created by Mac Paweł on 29.04.2017.
//  Copyright © 2017 Macbook PRO 13. All rights reserved.
//

#ifndef Game_hpp
#define Game_hpp

#include <stdio.h>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "ResourcePath.hpp"
#include <string>
#include <ncurses.h>
#include <unistd.h>
#include <iostream>
#include "Engine.hpp"
#include <stdlib.h>
#include <ncurses.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "Audio.hpp"
#include "Music.hpp"
#include "ParticleSystem.hpp"

using namespace std;


class Game
{
public:
    Game();
   //~Game();
 
    sf::Clock clock1;
    sf::Clock clock2;
    sf::Clock clock3;
    sf::Clock clock4;
    sf::Clock clock_game_over;
    
    sf::Image icon;

    void runGame();
    
    enum GameState {MENU,GAME,CREDITS,CONTROL,END};
    GameState state;
    
    
    void showGame_over();
    Audio audio;
    Music music;
     void showIntro();

    
    
    
protected:
    sf::Font font,font1,font2,fontMenu;
    void single();
    void menu();
    void credits();
    void showCredits();
    void control();
    void showControl();

};





#endif /* Game_hpp */
