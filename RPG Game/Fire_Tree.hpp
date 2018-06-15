//
//  Fire_Tree.hpp
//  RPG Game
//
//  Created by Mac Paweł on 02.06.2017.
//  Copyright © 2017 Macbook PRO 13. All rights reserved.
//

#ifndef Fire_Tree_hpp
#define Fire_Tree_hpp


#include "Object.hpp"
#include "RandomLib.hpp"
using namespace std;

class Fire_Tree: public Object
{
public:
    int anime_frame;
    int HP;
    int attackDamage;
    bool alive;
    sf::Clock clock_frame;
    sf::SoundBuffer buffer_scary_laugh;
    sf::Sound sound_scary_laugh;
    


    Fire_Tree();
    ~Fire_Tree();
    
    void Update();
    void animation();
    void scary_laugh();
    void scary_laugh_stop();

    
};


#endif /* Fire_Tree_hpp */
