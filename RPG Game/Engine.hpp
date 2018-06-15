//
//  Engine.hpp
//  RPG Game
//
//  Created by Mac Paweł on 30.04.2017.
//  Copyright © 2017 Macbook PRO 13. All rights reserved.
//

#ifndef Engine_hpp
#define Engine_hpp

#pragma once

#include "Player.hpp"
#include "Bullet.hpp"
#include "Enemy.hpp"
#include "displayText.hpp"
#include "Coin.hpp"
#include "wall.hpp"
#include "Box.hpp"
#include "Box.hpp"
#include "Music.hpp"
#include <fstream>
#include "Libraries.hpp"
#include "House.hpp"
#include "Door.hpp"
#include "Poskramiacz.hpp"
#include "Ring.hpp"
#include "FreezeGun.hpp"
#include "StarGun.hpp"
#include "HpPotion.hpp"
#include "FireGun.hpp"
#include "Sign.hpp"
#include "Fire_Tree.hpp"
#include "Bad_Tree.hpp"
#include "Walking_Tree.hpp"
#include "EnemyBullet.hpp"
#include "Star_bullet.hpp"

using namespace std;

#define framerate 60

class Engine
{
private:
    
public:
    
    fstream file, file_player, file_wolf;
    sf::RenderWindow *window;
    //COUNTERS
    int counter1; //bullet
    int counter_bullet_star;
    int counter_enemy_bullet;
    int counter2; //enemy
    int counter_fire_tree;
    int counter_bad_tree;
    int counter_walking_tree;
    int counterText;
    int counterText_buy;
    int counterCoins; 
    int counterWalls;
    int counterBox;
    int counterFloor;
    int counterHouse;
    int counterDoor;
    int counterSign;

    // 0 -> Ogniki, 1 -> Lodowa Zamiec  , 2 -> Poskramiacz    , 3 -> Ognisty Jezyk  , 4 ->  Gwiezdna Rozdzczka
    
    int current_weapon;
    
    //CLOCKS
    sf::Clock clock1;
    sf::Clock clock2;
    sf::Clock clock3;
    sf::Clock clock4;
    sf::Clock clock5;
    sf::Clock clock_show_invisible;
    sf::Clock clockShowPos;
    sf::Clock clock_predatorIsHere;
    sf::Clock clock_distance_from_predator;
    sf::Clock clock_shop;
    sf::Clock clock_select;
    sf::Clock clock_buy_items;
    sf::Clock clock_Fire_Tree_shoot;
    sf::Clock clock_scary_laugh;
    sf::Clock clock_aggroed;

    bool CanEdit;
    //VARIABLES
    float shootingTime;
    bool isPlayerDead;
    string code;
    int distance_predator;
    bool canShowPredatorDistance;
    bool game;
    bool can_buy_poskramiacz;
    bool can_buy_ring;
    bool can_buy_freeze_gun;
    bool can_buy_star_gun;
    bool can_buy_hp_potion;
    bool can_buy_fire_gun;



    sf::Texture textureBackground;
    sf::Sprite spriteBackground;
    //BACKGROUNDS
    sf::Texture textureGround1;
    sf::Texture texture_shop;
    sf::Texture texture_house;
    sf::Texture texture_sign_left;
    sf::Texture texture_sign_right;
    sf::Texture texture_sign_up;
    sf::Texture texture_sign_down;
    sf::Texture texture_wall;
    sf::Texture texture_wolf;
    sf::Texture texture_box;
    sf::Texture texture_fire_tree;
    sf::Texture texture_bad_tree;
    sf::Texture texture_walking_tree;
    sf::Sprite spriteGround1;
    sf::Sprite sprite_shop;
    
    //CHANGE ROOMS
    bool fromShop;
    bool fromLevel1;
    bool fromLevel2;
    bool fromLevel3;

    
    Engine(sf::RenderWindow &win);
    ~Engine(void);


    ///////ENGINE FUNCTIONS
    void check_isPlayer_dead(bool game);
    void check_IsPredatorNear(int distance_predator);
    void destructionAnimation();
    void runEngine();
    void KeyboardEvents(bool *canShowPredatorDistance ,int distance_predator);
    int Collisions();
    void Item_shop_collisions();
    void BuyItems();
    void load_Textures();
    void Fire_Tree_shooting();
    void Aggro_walking_tree();
    void Aggro_wolf();
    
    
    //SAVE AND LOAD
    void loadPlayer(Player *player);
    void savePlayer();
    int loadEngine();
    void saveEngine(int level_number);
    void load_enemy_wolf();
    void save_enemy_wolf();
    
    
    
    //LEVELS ENUMERATIONS
    enum LevelState {LEVEL1,LEVEL2,SHOP,LEVEL3,END};
    LevelState state_level;
    
    //LEVELS
    void level_1();
    void level_2();
    void level_3();
    void shop();
    
    //CLEARING AND PREPARE
    void DeleteObjects();
    void clearMap();
    void reserve_memory();
    
    //CREATE LEVEL TOOLS
    void create_house(int PositionX, int PositionY, sf::Texture *texture);
    void createRoom(int roomSize, int roomStartPositionX, int roomStartPositionY, int doorPosition, int numberEnemies, sf::Texture *texture, sf::Texture *texture_enemy);
    void createRoom_with_2_doors(int roomSize, int roomStartPositionX, int roomStartPositionY, int door1Position,int door2Position, sf::Texture *texture_wall);
    void createRoom_with_floor();
    void createLevelEnd(int roomSize, int roomStartPositionX, int roomStartPositionY, sf::Texture *texture);
    void createBackground(int choose,int PositionX, int PositionY, sf::Texture *texture, int transparency);
    void create_box(int PositionX, int PositionY, sf::Texture *texture);
    void create_horizontal_wall( int roomStartPositionX, int roomStartPositionY, int roomSize, sf::Texture *texture_wall);
    void create_vertical_wall( int roomStartPositionX, int roomStartPositionY, int roomSize, sf::Texture *texture_wall);
    void drawEngine(bool draw_background, sf::Sprite *sprite_background);
    void draw_Shop_Items();
    void check_distance_from_items(bool *can_play1,bool *can_play2,bool *can_play3,bool *can_play4,bool *can_play5,bool *can_play6);
    void Editor();
    void createSign(int PositionX, int PositionY, sf::Texture *texture);
    void create_Fire_Tree(int PositionX, int PositionY, sf::Texture *texture);
    void create_Bad_Tree(int PositionX, int PositionY, sf::Texture *texture);
    void create_wolf(int PositionX, int PositionY, sf::Texture *texture);
    void create_walking_tree(int PositionX, int PositionY, sf::Texture *texture);
    

    //SOUNDS
    Audio audioEngine;
    //MUSIC
    Music music;
    
    //TEXTS
    displayText moneyText;
    displayText playerLifeText;
    displayText playerWeapon;
    displayText attack_damage;
    displayText price_poskramiacz;
    displayText price_ring;
    displayText price_freeze_gun;
    displayText price_star_gun;
    displayText price_hp_potion;
    displayText price_fire_gun;

    
    //Create Player object
    Player player;
    
    //Create Bullet object
    Bullet bullet;
    //Create Bullet vector
    vector<Bullet>::const_iterator iter;
    vector<Bullet> BulletArray;
    
    
    //Create Bullet object
    Bullet_Star bullet_star;
    //Create Bullet star vector
    vector<Bullet_Star>::const_iterator iter_bullet_Star;
    vector<Bullet_Star> Bullet_StarArray;
    
    //Create Bullet object
    EnemyBullet enemy_bullet;
    //Create Bullet vector
    vector<EnemyBullet>::const_iterator iter_enemy_bullet;
    vector<EnemyBullet> EnemyBulletArray;
    
    //Create Enemy object
    Enemy enemy_wolf;
    //Create Enemy vector
    vector<Enemy>::const_iterator iter2;
    vector<Enemy> EnemyArray;
    
    //Create Fire Tree enemy object
    Fire_Tree fire_tree;
    //Create Fire Tree vector
    vector<Fire_Tree>::const_iterator iter_fire_tree;
    vector<Fire_Tree>  Fire_TreeArray;
    
    //Create Bad Tree enemy object
    Bad_Tree bad_tree;
    //Create Bad Tree vector
    vector<Bad_Tree>::const_iterator iter_bad_tree;
    vector<Bad_Tree>  Bad_TreeArray;
    
    
    //Create Walking Tree enemy object
    Walking_Tree walking_tree;
    //Create Walking Tree vector
    vector<Walking_Tree>::const_iterator iter_walking_tree;
    vector<Walking_Tree>  Walking_TreeArray;
    
    //Create displayText enemy hurt object
    displayText display_text;
    //Create displayText enemy hurt vector
    vector<displayText>::const_iterator iter3;
    vector<displayText> displayTextArray;
    
    //Create displayText buy items
    displayText display_text_buy;
    //Create displayText buy items vector
    vector<displayText>::const_iterator iter_buy;
    vector<displayText> displayTextBuyArray;
    
    
    //Create Coin object
     Coin coin;
    //Create Coin vector
    vector<Coin>::const_iterator iter4;
    vector<Coin> CoinArray;
    

    //Create Wall object
    Wall wall;
    //Create Wall vector
    vector<Wall>::const_iterator iter5;
    vector<Wall> WallArray;
    
    
    //Create Box object
    Box box;
    //Create Box vector
    vector<Box>::const_iterator iterBox;
    vector<Box> BoxArray;
    
    //Create House object
    House house;
    //Create House vector
    vector<House>::const_iterator iterHouse;
    vector<House> HouseArray;
    
    //Create Door object
    Door door1;
    //Create Door vector
    vector<Door>::const_iterator iterDoor;
    vector<Door> DoorArray;
    
    //Create Sign object
    Sign sign;
    //Create Sign vector
    vector<Sign>::const_iterator iterSign;
    vector<Sign> SignArray;
    
    
    
    //////SHOP ITEMS
    Door exit_shop_door;
    
    //SHOP ITEMS
    Poskramiacz poskramiacz;
    Ring ring;
    FreezeGun freeze_gun;
    StarGun star_gun;
    HpPotion hp_potion;
    FireGun fire_gun;



};

#endif //Engine_hpp
