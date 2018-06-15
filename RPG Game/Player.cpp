

#include "Player.hpp"

using namespace std;





Player::Player()

{
    
    
    rect.setSize(sf::Vector2f(55,70));
    rect.setFillColor(sf::Color::Blue);
    rect.setPosition(800,900);
    
   
 
    if(!texture.loadFromFile(resourcePath()+"Player.jpg"))
    {
        cout<<"Cant load Player.jpg!"<<endl;
        return EXIT_FAILURE;
    }
    
    
    sprite.setTexture(texture);
    texture.setSmooth(true);
    sprite.setTextureRect(sf::IntRect(0,192,96,96));
    
    
    anime_frame = 0;
    movement_speed =6;
    
    //STATS
     direction = 1;
    HP = 200;
    isDead = false;
    gold = 0;
    
    canMoveUp = true;
    canMoveDown = true;
    canMoveRight = true;
    canMoveLeft = true;
    soundPlayTime = 0.3;
    
    attackDamage = 1;
    current_weapon = "Ogniki";
    current_weapon_int = 0;
}


void Player::Update()
{
    sprite.setPosition(rect.getPosition()-sf::Vector2f(20,20));

    
}



void Player::Movement()
{
   
    sf::Time elapsed_movement = clock_movement.getElapsedTime();
    sf::Time elapsed_movement_sound = clock_movement_sound.getElapsedTime();
    
    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        if(canMoveUp==true)
        {
        rect.move(0, -movement_speed);
        sprite.setTextureRect(sf::IntRect(anime_frame*96 ,96*0, 96, 96));
        
       // cout<<"Is pressed key UP.   Coordinates Player(X: "<<rect.getPosition().x<<", "<<rect.getPosition().y<<" )"<<endl;
        
        direction =2;
        ////PLAY MOVEMENT SOUND
        if(elapsed_movement_sound.asSeconds()>=soundPlayTime)
        {
            audio.movement();
            clock_movement_sound.restart();
        }
        //////////////////
            canMoveUp = true;
            canMoveDown = true;
            canMoveLeft = true;
            canMoveRight = true;
        }
        else;
    }
    
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        if(canMoveDown==true)
        {
        rect.move(0, movement_speed);
        sprite.setTextureRect(sf::IntRect(anime_frame*96, 96*2, 96, 96));
        // cout<<"Is pressed key DOWN.   Coordinates Player(X: "<<rect.getPosition().x<<", "<<rect.getPosition().y<<" )"<<endl;
        
        direction = 1;
        ////PLAY MOVEMENT SOUND
            if(elapsed_movement_sound.asSeconds()>=soundPlayTime)
            {
                audio.movement();
                clock_movement_sound.restart();
            }
        //////////////////
            canMoveUp = true;
            canMoveDown = true;
            canMoveLeft = true;
            canMoveRight = true;
        }
        
        else;
    }
    
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        if(canMoveLeft==true)
        {
        rect.move(-movement_speed, 0);
        sprite.setTextureRect(sf::IntRect(anime_frame*96, 96*1, 96, 96));
        //cout<<"Is pressed key LEFT.   Coordinates Player(X: "<<rect.getPosition().x<<", "<<rect.getPosition().y<<" )"<<endl;
        
        direction = 3;
        ////PLAY MOVEMENT SOUND
            if(elapsed_movement_sound.asSeconds()>=soundPlayTime)
            {
                audio.movement();
                clock_movement_sound.restart();
            }
        //////////////////
            canMoveUp = true;
            canMoveDown = true;
            canMoveLeft = true;
            canMoveRight = true;
        }
        else;
        
        
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        if(canMoveRight==true)
        {
        rect.move(movement_speed, 0);
        sprite.setTextureRect(sf::IntRect(anime_frame*96, 96*3, 96, 96));
        // cout<<"Is pressed key RIGHT.   Coordinates Player(X: "<<rect.getPosition().x<<", "<<rect.getPosition().y<<" )"<<endl;
        
        direction = 4;
        
        ////PLAY MOVEMENT SOUND
            if(elapsed_movement_sound.asSeconds()>=soundPlayTime)
            {
                audio.movement();
                clock_movement_sound.restart();
            }
        //////////////////
            canMoveUp = true;
            canMoveDown = true;
            canMoveLeft = true;
            canMoveRight = true;
        }
        else;
    }
    
    else
    {
        if(direction==1)
        {
            sprite.setTextureRect(sf::IntRect(0 ,96*2, 96, 96));
        }
        else if(direction==2)
        {
            sprite.setTextureRect(sf::IntRect(0 ,0, 96, 96));
        }
        else if(direction==3)
        {
            sprite.setTextureRect(sf::IntRect(0 ,96, 96, 96));
        }
        else if(direction==4)
        {
            sprite.setTextureRect(sf::IntRect(0 ,96*3, 96, 96));
        }
    }

    

    if(elapsed_movement.asSeconds()>=0.05)
    {
        anime_frame++;
        clock_movement.restart();
    }
    
    if(anime_frame==8)
    {
        anime_frame=0;
    }
    
}

