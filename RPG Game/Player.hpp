#ifndef Player_hpp
#define Player_hpp

#include "Object.hpp"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <ncurses.h>
#include <unistd.h>
#include "ResourcePath.hpp"
#include <iostream>
#include "Audio.hpp"



class Player: public Object
{
public:
    int movement_speed;
    int anime_frame;
    int direction; //1 -> down, 2 -> up, 3 -> left , 4 -> right
    int HP;
    bool isDead;
    int gold;
    int attackDamage;
    //weapon
    string current_weapon;
    // 0 -> Ogniki, 1 -> Lodowa Zamiec  , 2 -> Poskramiacz    , 3 -> Ognisty Jezyk  , 4 ->  Gwiezdna Rozdzczka
    int current_weapon_int;
    
    bool canMoveUp;
    bool canMoveDown;
    bool canMoveRight;
    bool canMoveLeft;
    
    sf::Clock clock_movement;
    sf::Clock clock_movement_sound;
    
    float soundPlayTime;
    
    Player();
    //~Player();
    
    void Update();
    void Movement();
   
    Audio audio;

    sf::Sprite sprite;
    sf::Texture texture;
   /* sf::SoundBuffer buffer;
    sf::Sound sound;  
  */  
    

   
    
    
};

#endif /* Player_hpp */
