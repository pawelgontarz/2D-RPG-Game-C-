//
//  Fire_Tree.cpp
//  RPG Game
//
//  Created by Mac Paweł on 02.06.2017.
//  Copyright © 2017 Macbook PRO 13. All rights reserved.
//

#include "Fire_Tree.hpp"

Fire_Tree::Fire_Tree()
{
    
    
    rect.setSize(sf::Vector2f(200,200));
    rect.setFillColor(sf::Color::Green);
    rect.setPosition(0,0);
    
    anime_frame = 0;
    //STATS
    HP=10;
    attackDamage = 3;
    alive = true;
    sprite.setTextureRect(sf::IntRect(600,0, 200, 200));
    
    //sound scary laugh
    if(!buffer_scary_laugh.loadFromFile(resourcePath() + "scary_laugh.wav"))
    {
        cout<<"Cant load file  scary_laugh.wav! "<<endl;
        return EXIT_FAILURE;
    }
    sound_scary_laugh.setBuffer(buffer_scary_laugh);
    


}
Fire_Tree::~Fire_Tree()
{
    
}

void Fire_Tree::Update()
{
    sprite.setPosition(rect.getPosition());
   
}

void Fire_Tree::animation()
{
    sf::Time elapsed_frame = clock_frame.getElapsedTime();
    
    sprite.setTextureRect(sf::IntRect(200*anime_frame,0, 200, 200));
    
    if(elapsed_frame.asSeconds()>=0.2)
    {
        anime_frame++;
        clock_frame.restart();
    }
    
    if(anime_frame==4)
    {
        anime_frame=0;
    }
}

void Fire_Tree::scary_laugh()
{
    sound_scary_laugh.setVolume(80);
    sound_scary_laugh.play();
}
void Fire_Tree::scary_laugh_stop()
{
    sound_scary_laugh.stop();
}
