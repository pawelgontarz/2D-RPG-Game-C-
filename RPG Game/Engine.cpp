//
//  Engine.cpp
//  RPG Game
//
//  Created by Mac Paweł on 30.04.2017.
//  Copyright © 2017 Macbook PRO 13. All rights reserved.
//

#include "Engine.hpp"
using namespace  std;

sf::Window windowMenu;



Engine::Engine(sf::RenderWindow &win)
{
    state_level = END;
    
    window = &win;
    
    counter1=0; //bullets
    counter_bullet_star = 0;
    counter_enemy_bullet = 0;
    counter2=0; //enemy
    counter_fire_tree = 0;
    counter_bad_tree = 0;
    counter_walking_tree = 0;
    counterText=0;
    counterText_buy = 0;
    counterCoins=0;
    counterWalls=0;
    counterBox = 0;
    counterFloor = 0;
    counterHouse = 0;
    counterDoor = 0;
    counterSign = 0;
    
    

    isPlayerDead = false;
    canShowPredatorDistance = false;
    shootingTime = 0.35;
    CanEdit = false;
    code = "";
    distance_predator = 0;
    window->setFramerateLimit(framerate);
    window->setVerticalSyncEnabled(true);
    
    state_level = LEVEL1;
    
    game = true;
    fromShop = false;
    fromLevel1 = false;
    fromLevel2 = false;
    fromLevel3 = false;
    
    
    can_buy_ring = false;
    can_buy_fire_gun = false;
    can_buy_star_gun = false;
    can_buy_hp_potion = false;
    can_buy_freeze_gun = false;
    can_buy_poskramiacz = false;

    
    
 

    

   
    
}


Engine::~Engine()
{
    //zapis stanu gry, nazwa poziomu itp..
   //save aby mozna było wrócić do gry???
}




void Engine::runEngine()
{

    
    cout<<"Engine started"<<endl;
    load_Textures();

    //setting text position on the screen
    moneyText.text.setPosition(0, 0);
    moneyText.text.setFont(moneyText.font_mr_otis);
    moneyText.text.setFillColor(sf::Color::Yellow);
    moneyText.text.setCharacterSize(25);
    
    playerLifeText.text.setPosition(0, 50);
    playerLifeText.text.setFont(playerLifeText.font_mr_otis);
    playerLifeText.text.setFillColor(sf::Color::Red);
    playerLifeText.text.setCharacterSize(30);
    
    
    playerWeapon.text.setPosition(0, 50);
    playerWeapon.text.setFont(playerWeapon.font_mr_otis);
    playerWeapon.text.setFillColor(sf::Color::Cyan);
    playerWeapon.text.setCharacterSize(35);
    
    attack_damage.text.setPosition(0, 50);
    attack_damage.text.setFont(playerWeapon.font_mr_otis);
    attack_damage.text.setFillColor(sf::Color::Cyan);
    attack_damage.text.setCharacterSize(35);


    
    //setting view
    sf::View view1 (sf::Vector2f(200, 200), sf::Vector2f(300, 200));
    view1.setSize(sf::Vector2f(window->getSize().x, window->getSize().y ));
    view1.setCenter(sf::Vector2f(view1.getSize().x/2,view1.getSize().y/2));
    window->setView(view1);
    
    loadEngine();
  //////////////////////////////START THE GAME LOOP/////////////////////////
    while(game)
    {
        
    while(state_level != END)
    {
        
        switch (state_level)
        {
            case LevelState::LEVEL1:
           
                level_1();
                break;

            case LevelState::LEVEL2:
                level_2();
                break;
            case LevelState::LEVEL3:
                level_3();
                break;
            case LevelState::SHOP:
                shop();
                break;
                
            default:
                break;
        }

        


    }

          //set default view in menu
          window->setView(window->getDefaultView());
          game = false;
       
    }

}

void Engine::load_Textures()
{
    //load texture enemy predator
    if(!texture_wolf.loadFromFile(resourcePath()+"enemy_wolf.png"))
    {
        cout<<"Cant load: enemy_wolf.png"<<endl;
        return EXIT_FAILURE;
    }
    else cout<<"Texture enemy_wolf.png was loaded successfully"<<endl;
    
    //load texture wall
    if(!texture_wall.loadFromFile(resourcePath()+"tile_elements.png"))
    {
        cout<<"Cant load tile_elements.png!"<<endl;
        return EXIT_FAILURE;
    }
     else cout<<"Texture tile_elements.png was loaded successfully"<<endl;
    
    //load texture
    if(!texture_house.loadFromFile(resourcePath()+"house_sprite.png"))
    {
        cout<<"Cant load house_sprite.png!"<<endl;
        return EXIT_FAILURE;
    }
     else cout<<"Texture house_sprite.png was loaded successfully"<<endl;
    
    //load texture grass
    if(!textureGround1.loadFromFile(resourcePath()+"background_grass.png"))
    {
        cout<<"Cant load background_grass.png!"<<endl;
        return EXIT_FAILURE;
    }
     else cout<<"Texture background_grass.png was loaded successfully"<<endl;
    
    //load texture shop
    if(!texture_shop.loadFromFile(resourcePath()+"Shop_background.png"))
    {
        cout<<"Cant load Shop_background.png!"<<endl;
        return EXIT_FAILURE;
    }
     else cout<<"Texture Shop_background.png was loaded successfully"<<endl;
    
    
    
    //load texture sign down
    if(!texture_sign_down.loadFromFile(resourcePath()+"go_down.png"))
    {
        cout<<"Cant load go_down.png!"<<endl;
        return EXIT_FAILURE;
    }
     else cout<<"Texture go_down.png was loaded successfully"<<endl;
    
    //load texture sign up
    if(!texture_sign_up.loadFromFile(resourcePath()+"go_up.png"))
    {
        cout<<"Cant load go_up.png!"<<endl;
        return EXIT_FAILURE;
    }
     else cout<<"Texture go_up.png was loaded successfully"<<endl;
    //load texture sign left
    if(!texture_sign_left.loadFromFile(resourcePath()+"go_left.png"))
    {
        cout<<"Cant load go_left.png!"<<endl;
        return EXIT_FAILURE;
    }
     else cout<<"Texture go_left.png was loaded successfully"<<endl;
    
    //load texture sign right
    if(!texture_sign_right.loadFromFile(resourcePath()+"go_right.png"))
    {
        cout<<"Cant load go_right.png!"<<endl;
        return EXIT_FAILURE;
    }
     else cout<<"Texture go_right.png was loaded successfully"<<endl;
    
    //load texture box
    if(!texture_box.loadFromFile(resourcePath()+"box.png"))
    {
        cout<<"Cant load box.png!"<<endl;
        return EXIT_FAILURE;
    }
         else cout<<"Texture box.png was loaded successfully"<<endl;
    
    //load texture fire tree
    if(!texture_fire_tree.loadFromFile(resourcePath()+"scary_tree.png"))
    {
        cout<<"Cant load  scary_tree.png!"<<endl;
        return EXIT_FAILURE;
    }
    else cout<<"Texture scary_tree.png was loaded successfully"<<endl;
    
    //load texture bad tree
    if(!texture_bad_tree.loadFromFile(resourcePath()+"Bad_tree.png"))
    {
        cout<<"Cant load  Bad_tree.png!"<<endl;
        return EXIT_FAILURE;
    }
    else cout<<"Texture Bad_tree.png was loaded successfully"<<endl;
    
    //load texture walking tree
    if(!texture_walking_tree.loadFromFile(resourcePath()+"tree_monster.png"))
    {
        cout<<"Cant load  tree_monster.png!"<<endl;
        return EXIT_FAILURE;
    }
    else cout<<"Texture tree_monster.png was loaded successfully"<<endl;
    
   
}

int Engine::Collisions()
{
    /////////////////////////////COLLISIONS////////////////////////////////////////////

     sf::Time elapsed5 = clock5.getElapsedTime();

   //COLLISION PLAYER WITH WALLS
    counterWalls = 0;
    for(iter5=WallArray.begin(); iter5 !=WallArray.end(); iter5++)
    {
        
        if(player.rect.getGlobalBounds().intersects(WallArray[counterWalls].rect.getGlobalBounds()))
        {
            //cout<<"Wall collision"<<endl;
            
            if(player.direction==1) //down
            {
                player.canMoveDown =false;
                
                player.rect.move(0, -5);
            }
            else if(player.direction==2) //up
            {
                player.canMoveUp =false;
                
                player.rect.move(0, 5);
            }
            else if(player.direction==3) //left
            {
                player.canMoveLeft =false;
                
                player.rect.move(5, 0);
            }
            else if(player.direction==4) //right
            {
                player.canMoveRight =false;
                
                player.rect.move(-5, 0);
            }
            else
            {
                
            }
            
            
        }
        counterWalls++;
    }
    
    
    //COLLISION PLAYER WITH BOX
    
    counterBox = 0;
    for(iterBox=BoxArray.begin(); iterBox !=BoxArray.end(); iterBox++)
    {
        
        if(player.rect.getGlobalBounds().intersects(BoxArray[counterBox].rect.getGlobalBounds()))
        {
            //cout<<"Box collision"<<endl;
            
            if(player.direction==1) //down
            {
                player.canMoveDown =false;
                
                player.rect.move(0, -5);
            }
            else if(player.direction==2) //up
            {
                player.canMoveUp =false;
                
                player.rect.move(0, 5);
            }
            else if(player.direction==3) //left
            {
                player.canMoveLeft =false;
                
                player.rect.move(5, 0);
            }
            else if(player.direction==4) //right
            {
                player.canMoveRight =false;
                
                player.rect.move(-5, 0);
            }
            else
            {
                
            }
            
            
            
        }
        counterBox++;
    }
    
    //COLLISION PLAYER WITH HOUSE
    counterHouse = 0;
    for(iterHouse = HouseArray.begin(); iterHouse!= HouseArray.end(); iterHouse++)
    {
        
        if(player.rect.getGlobalBounds().intersects(HouseArray[counterHouse].rect.getGlobalBounds()))
        {
            //cout<<"House collision"<<endl;
            
            if(player.direction==1) //down
            {
                player.canMoveDown =false;
                
                player.rect.move(0, -5);
            }
            else if(player.direction==2) //up
            {
                player.canMoveUp =false;
                
                player.rect.move(0, 5);
            }
            else if(player.direction==3) //left
            {
                player.canMoveLeft =false;
                
                player.rect.move(5, 0);
            }
            else if(player.direction==4) //right
            {
                player.canMoveRight =false;
                
                player.rect.move(-5, 0);
            }
            else
            {
                
            }
            
  
        }

        counterHouse++;
    }
    
    
    //COLLISION PLAYER WITH COINS
    counterCoins = 0;
    for(iter4=CoinArray.begin(); iter4 !=CoinArray.end(); iter4++)
    {
        
        if(player.rect.getGlobalBounds().intersects(CoinArray[counterCoins].rect.getGlobalBounds()))
        {
            player.gold = player.gold + coin.value;
            audioEngine.getCoin();
            
            CoinArray[counterCoins].destroy= true;
            cout<<"Collision with coins!"<<endl;
        }
        counterCoins++;
    }
    
    //COLLISION PLAYER WITH DOORS
    counterDoor = 0;
    for(iterDoor=DoorArray.begin(); iterDoor !=DoorArray.end(); iterDoor++)
    {
        
        if(player.rect.getGlobalBounds().intersects(DoorArray[counterDoor].rect.getGlobalBounds()))
        {
            cout<<"Player collide with door1"<<endl;
            door1.can_go_next = true;
        }
        else
        {
            door1.can_go_next = false;
        }
        counterDoor++;
    }
    
    
    //COLLISION PLAYER WITH SIGNS
    counterSign = 0;
    for(iterSign=SignArray.begin(); iterSign !=SignArray.end(); iterSign++)
    {
        
        if(player.rect.getGlobalBounds().intersects(SignArray[counterSign].rect.getGlobalBounds()))
        {
            cout<<"Player collide with sign"<<endl;
            SignArray[counterSign].can_go_next = true;
        }
        else
        {
            SignArray[counterSign].can_go_next = false;
        }
        counterSign++;
    }
    
    //COLLISION FIRE TREE BULLETS PLAYER
    counter_enemy_bullet = 0;
    for(iter_enemy_bullet=EnemyBulletArray.begin(); iter_enemy_bullet !=EnemyBulletArray.end(); iter_enemy_bullet++)
    {
      
            if(EnemyBulletArray[counter_enemy_bullet].rect.getGlobalBounds().intersects(player.rect.getGlobalBounds()))
            {
                audioEngine.getPunch();
                ;
                player.HP -= fire_tree.attackDamage;
                
                EnemyBulletArray[counter_enemy_bullet].destroyBullet = true;
                
                
                //Text display
                display_text.text.setString(to_string(fire_tree.attackDamage));
                //Center text and set him over player
                display_text.text.setPosition(player.rect.getPosition().x+player.rect.getSize().x/2, player.rect.getPosition().y+player.rect.getSize().y/2);
                displayTextArray.push_back(display_text);
                
            }
        
        counter_enemy_bullet++;
    }

    
    //COLLISION ENEMY WITH WALLS
    
    counter2 = 0;
    for(iter2 = EnemyArray.begin(); iter2 != EnemyArray.end(); iter2++)
    {
        
        counterWalls = 0;
        for(iter5=WallArray.begin(); iter5 !=WallArray.end(); iter5++)
        {
            if(EnemyArray[counter2].rect.getGlobalBounds().intersects(WallArray[counterWalls].rect.getGlobalBounds()))
            {
                //cout<<"Enemy Wall collision"<<endl;
                
                if(EnemyArray[counter2].direction==1) //down
                {
                    EnemyArray[counter2].canMoveDown =false;
                    EnemyArray[counter2].rect.move(0, -5);
                }
                else if(EnemyArray[counter2].direction==2) //up
                {
                    EnemyArray[counter2].canMoveUp =false;
                    EnemyArray[counter2].rect.move(0, 5);
                }
                else if(EnemyArray[counter2].direction==3) //left
                {
                    EnemyArray[counter2].canMoveLeft =false;
                    EnemyArray[counter2].rect.move(5, 0);
                }
                else if(EnemyArray[counter2].direction==4) //right
                {
                    EnemyArray[counter2].canMoveRight =false;
                    EnemyArray[counter2].rect.move(-5, 0);
                }
                else
                {
                    
                }
                
                
                
            }
            counterWalls++;
        }
        
        counter2++;
    }
    
    
    
    //COLLISION ENEMY WITH BOX
    counter2 = 0;
    for(iter2 = EnemyArray.begin(); iter2 != EnemyArray.end(); iter2++)
    {
        
        counterBox = 0;
        for(iterBox=BoxArray.begin(); iterBox !=BoxArray.end(); iterBox++)
        {
            if(EnemyArray[counter2].rect.getGlobalBounds().intersects(BoxArray[counterBox].rect.getGlobalBounds()))
            {
               // cout<<"Box collision"<<endl;
                
                if(EnemyArray[counter2].direction==1) //down
                {
                    EnemyArray[counter2].canMoveDown =false;
                    EnemyArray[counter2].rect.move(0, -5);
                }
                else if(EnemyArray[counter2].direction==2) //up
                {
                    EnemyArray[counter2].canMoveUp =false;
                    EnemyArray[counter2].rect.move(0, 5);
                }
                else if(EnemyArray[counter2].direction==3) //left
                {
                    EnemyArray[counter2].canMoveLeft =false;
                    EnemyArray[counter2].rect.move(5, 0);
                }
                else if(EnemyArray[counter2].direction==4) //right
                {
                    EnemyArray[counter2].canMoveRight =false;
                    EnemyArray[counter2].rect.move(-5, 0);
                }
                else
                {
                    
                }
   
                
            }
            counterBox++;
        }
        
        counter2++;
    }
    
    //COLLISION ENEMY WITH HOUSE
    counter2 = 0;
    for(iter2 = EnemyArray.begin(); iter2 != EnemyArray.end(); iter2++)
    {
        
        counterHouse = 0;
        for(iterHouse=HouseArray.begin(); iterHouse !=HouseArray.end(); iterHouse++)
        {
            if(EnemyArray[counter2].rect.getGlobalBounds().intersects(HouseArray[counterHouse].rect.getGlobalBounds()))
            {
                // cout<<"Enemy collide with house "<<endl;
                
                if(EnemyArray[counter2].direction==1) //down
                {
                    EnemyArray[counter2].canMoveDown =false;
                    EnemyArray[counter2].rect.move(0, -5);
                }
                else if(EnemyArray[counter2].direction==2) //up
                {
                    EnemyArray[counter2].canMoveUp =false;
                    EnemyArray[counter2].rect.move(0, 5);
                }
                else if(EnemyArray[counter2].direction==3) //left
                {
                    EnemyArray[counter2].canMoveLeft =false;
                    EnemyArray[counter2].rect.move(5, 0);
                }
                else if(EnemyArray[counter2].direction==4) //right
                {
                    EnemyArray[counter2].canMoveRight =false;
                    EnemyArray[counter2].rect.move(-5, 0);
                }
                else
                {
                    
                }
                
                
            }
            counterHouse++;
        }
        
        counter2++;
    }
    

    
    //COLLISION ENEMY WITH PLAYER
    counter2 = 0;
    for(iter2=EnemyArray.begin(); iter2 !=EnemyArray.end(); iter2++)
    {
        
        if(player.rect.getGlobalBounds().intersects(EnemyArray[counter2].rect.getGlobalBounds()))
        {
            if(elapsed5.asSeconds() >= 0.8)
            {
            
                player.HP -= EnemyArray[counter2].attackDamage;
                EnemyArray[counter2].aggroed = true;
                //Text display
                display_text.text.setString(to_string(EnemyArray[counter2].attackDamage));
                //Center text and set him over enemy
                display_text.text.setPosition(player.rect.getPosition().x+player.rect.getSize().x/2, player.rect.getPosition().y+player.rect.getSize().y/2);
                displayTextArray.push_back(display_text);
                audioEngine.enemyBite();
                audioEngine.getPunch();
                clock5.restart();

            }
            
           
                //enemy cant move
                if(EnemyArray[counter2].direction==1) //down
                {
                    EnemyArray[counter2].canMoveDown =false;
                    //EnemyArray[counter2].rect.move(0, -5);
                }
                else if(EnemyArray[counter2].direction==2) //up
                {
                    EnemyArray[counter2].canMoveUp =false;
                   // EnemyArray[counter2].rect.move(0, 5);
                }
                else if(EnemyArray[counter2].direction==3) //left
                {
                    EnemyArray[counter2].canMoveLeft =false;
                  //  EnemyArray[counter2].rect.move(5, 0);
                }
                else if(EnemyArray[counter2].direction==4) //right
                {
                    EnemyArray[counter2].canMoveRight =false;
                  //  EnemyArray[counter2].rect.move(-5, 0);
                }
                else
                {
                    
                }
                 }
               counter2++;
    }

    
    //COLLISION BULLETS WITH ENEMY
    counter1 = 0;
    for(iter=BulletArray.begin(); iter !=BulletArray.end(); iter++)
    {
        counter2 = 0;
        for(iter2=EnemyArray.begin(); iter2 !=EnemyArray.end(); iter2++)
        {
            if(BulletArray[counter1].rect.getGlobalBounds().intersects(EnemyArray[counter2].rect.getGlobalBounds()))
            {
                audioEngine.getPunch();
                //cout<<"Collision!"<<endl;
                EnemyArray[counter2].HP -= player.attackDamage;
                //enemy aggroed
                EnemyArray[counter2].aggroed = true;
                //cout<<"Enemy HP: "<< EnemyArray[counter2].HP<<endl;
                BulletArray[counter1].destroyBullet = true;
                
                
                //Text display
                display_text.text.setString(to_string(player.attackDamage));
                //Center text and set him over enemy
                display_text.text.setPosition(EnemyArray[counter2].rect.getPosition().x+EnemyArray[counter2].rect.getSize().x/2, EnemyArray[counter2].rect.getPosition().y+EnemyArray[counter2].rect.getSize().y/2);
                displayTextArray.push_back(display_text);
                
                if(EnemyArray[counter2].HP<=0)
                {
                    EnemyArray[counter2].alive = false;
                }
            }
            counter2++;
        }
        counter1++;
    }
    
    
    //COLLISION BULLETS STAR WITH ENEMY
    counter_bullet_star = 0;
    for(iter_bullet_Star=Bullet_StarArray.begin(); iter_bullet_Star !=Bullet_StarArray.end(); iter_bullet_Star++)
    {
        counter2 = 0;
        for(iter2=EnemyArray.begin(); iter2 !=EnemyArray.end(); iter2++)
        {
            if(Bullet_StarArray[counter_bullet_star].rect.getGlobalBounds().intersects(EnemyArray[counter2].rect.getGlobalBounds()))
            {
                audioEngine.getPunch();
                //cout<<"Collision!"<<endl;
                EnemyArray[counter2].HP -= player.attackDamage;
                //enemy aggroed
                EnemyArray[counter2].aggroed = true;
                //cout<<"Enemy HP: "<< EnemyArray[counter2].HP<<endl;
                Bullet_StarArray[counter_bullet_star].destroyBullet = true;
                
                
                //Text display
                display_text.text.setString(to_string(player.attackDamage));
                //Center text and set him over enemy
                display_text.text.setPosition(EnemyArray[counter2].rect.getPosition().x+EnemyArray[counter2].rect.getSize().x/2, EnemyArray[counter2].rect.getPosition().y+EnemyArray[counter2].rect.getSize().y/2);
                displayTextArray.push_back(display_text);
                
                if(EnemyArray[counter2].HP<=0)
                {
                    EnemyArray[counter2].alive = false;
                }
            }
            counter2++;
        }
        counter_bullet_star++;
    }
    

    
    
    //COLLISION FIRE TREE ENEMY WITH PLAYER
    counter_fire_tree = 0;
    for(iter_fire_tree=Fire_TreeArray.begin(); iter_fire_tree !=Fire_TreeArray.end(); iter_fire_tree++)
    {
        
        if(player.rect.getGlobalBounds().intersects(Fire_TreeArray[counter_fire_tree].rect.getGlobalBounds()))
        {
            if(elapsed5.asSeconds() >= 0.8)
            {
                
                player.HP -= Fire_TreeArray[counter_fire_tree].attackDamage;
                //Text display
                display_text.text.setString(to_string(Fire_TreeArray[counter_fire_tree].attackDamage));
                //Center text and set him over enemy
                display_text.text.setPosition(player.rect.getPosition().x+player.rect.getSize().x/2, player.rect.getPosition().y+player.rect.getSize().y/2);
                displayTextArray.push_back(display_text);
                audioEngine.getPunch();
                clock5.restart();
                
            }
            
        }
        counter_fire_tree++;
    }
    
    
    //COLLISION BULLETS WITH FIRE TREE ENEMY
    counter1 = 0;
    for(iter=BulletArray.begin(); iter !=BulletArray.end(); iter++)
    {
        counter_fire_tree = 0;
        for(iter_fire_tree=Fire_TreeArray.begin(); iter_fire_tree !=Fire_TreeArray.end(); iter_fire_tree++)
        {
            if(BulletArray[counter1].rect.getGlobalBounds().intersects(Fire_TreeArray[counter_fire_tree].rect.getGlobalBounds()))
            {
                audioEngine.getPunch();
                //cout<<"Collision!"<<endl;
                Fire_TreeArray[counter_fire_tree].HP -= player.attackDamage;
                //cout<<"Enemy HP: "<< EnemyArray[counter2].HP<<endl;
                BulletArray[counter1].destroyBullet = true;
                
                
                //Text display
                display_text.text.setString(to_string(player.attackDamage));
                //Center text and set him over enemy
                display_text.text.setPosition(Fire_TreeArray[counter_fire_tree].rect.getPosition().x+Fire_TreeArray[counter_fire_tree].rect.getSize().x/2, Fire_TreeArray[counter_fire_tree].rect.getPosition().y+Fire_TreeArray[counter_fire_tree].rect.getSize().y/2);
                displayTextArray.push_back(display_text);
                
                if(Fire_TreeArray[counter_fire_tree].HP<=0)
                {
                    Fire_TreeArray[counter_fire_tree].alive = false;
                }
            }
            counter_fire_tree++;
        }
        counter1++;
    }
    
    
    //COLLISION BULLETS STAR WITH FIRE TREE ENEMY
    counter_bullet_star = 0;
    for(iter_bullet_Star=Bullet_StarArray.begin(); iter_bullet_Star !=Bullet_StarArray.end(); iter_bullet_Star++)
    {
        counter_fire_tree = 0;
        for(iter_fire_tree=Fire_TreeArray.begin(); iter_fire_tree !=Fire_TreeArray.end(); iter_fire_tree++)
        {
            if(Bullet_StarArray[counter_bullet_star].rect.getGlobalBounds().intersects(Fire_TreeArray[counter_fire_tree].rect.getGlobalBounds()))
            {
                audioEngine.getPunch();
                //cout<<"Collision!"<<endl;
                Fire_TreeArray[counter_fire_tree].HP -= player.attackDamage;
                //cout<<"Enemy HP: "<< EnemyArray[counter2].HP<<endl;
                Bullet_StarArray[counter_bullet_star].destroyBullet = true;
                
                
                //Text display
                display_text.text.setString(to_string(player.attackDamage));
                //Center text and set him over enemy
                display_text.text.setPosition(Fire_TreeArray[counter_fire_tree].rect.getPosition().x+Fire_TreeArray[counter_fire_tree].rect.getSize().x/2, Fire_TreeArray[counter_fire_tree].rect.getPosition().y+Fire_TreeArray[counter_fire_tree].rect.getSize().y/2);
                displayTextArray.push_back(display_text);
                
                if(Fire_TreeArray[counter_fire_tree].HP<=0)
                {
                    Fire_TreeArray[counter_fire_tree].alive = false;
                }
            }
            counter_fire_tree++;
        }
        counter_bullet_star++;
    }

    
    //COLLISION BAD TREE ENEMY WITH PLAYER
    counter_bad_tree = 0;
    for(iter_bad_tree=Bad_TreeArray.begin(); iter_bad_tree !=Bad_TreeArray.end(); iter_bad_tree++)
    {
        
        if(player.rect.getGlobalBounds().intersects(Bad_TreeArray[counter_bad_tree].rect.getGlobalBounds()))
        {
            if(elapsed5.asSeconds() >= 0.8)
            {
                
                player.HP -= Bad_TreeArray[counter_bad_tree].attackDamage;
                //Text display
                display_text.text.setString(to_string(Bad_TreeArray[counter_bad_tree].attackDamage));
                //Center text and set him over enemy
                display_text.text.setPosition(player.rect.getPosition().x+player.rect.getSize().x/2, player.rect.getPosition().y+player.rect.getSize().y/2);
                displayTextArray.push_back(display_text);
                audioEngine.getPunch();
                clock5.restart();
                
            }
            
        }
        counter_bad_tree++;
    }
    
    //COLLISION BULLETS WITH BAD TREE ENEMY
    counter1 = 0;
    for(iter=BulletArray.begin(); iter !=BulletArray.end(); iter++)
    {
        counter_bad_tree = 0;
        for(iter_bad_tree=Bad_TreeArray.begin(); iter_bad_tree !=Bad_TreeArray.end(); iter_bad_tree++)
        {
            if(BulletArray[counter1].rect.getGlobalBounds().intersects(Bad_TreeArray[counter_bad_tree].rect.getGlobalBounds()))
            {
                audioEngine.getPunch();
                //cout<<"Collision!"<<endl;
                Bad_TreeArray[counter_bad_tree].HP -= player.attackDamage;
                //cout<<"Enemy HP: "<< EnemyArray[counter2].HP<<endl;
                BulletArray[counter1].destroyBullet = true;
                
                
                //Text display
                display_text.text.setString(to_string(player.attackDamage));
                //Center text and set him over enemy
                display_text.text.setPosition(Bad_TreeArray[counter_bad_tree].rect.getPosition().x+Bad_TreeArray[counter_bad_tree].rect.getSize().x/2, Bad_TreeArray[counter_bad_tree].rect.getPosition().y+Bad_TreeArray[counter_bad_tree].rect.getSize().y/2);
                displayTextArray.push_back(display_text);
                
                if(Bad_TreeArray[counter_bad_tree].HP<=0)
                {
                    Bad_TreeArray[counter_bad_tree].alive = false;
                }
            }
            counter_bad_tree++;
        }
        counter1++;
    }
    
    
    //COLLISION BULLETS star WITH BAD TREE ENEMY
    counter_bullet_star = 0;
    for(iter_bullet_Star=Bullet_StarArray.begin(); iter_bullet_Star !=Bullet_StarArray.end(); iter_bullet_Star++)
    {
        counter_bad_tree = 0;
        for(iter_bad_tree=Bad_TreeArray.begin(); iter_bad_tree !=Bad_TreeArray.end(); iter_bad_tree++)
        {
            if(Bullet_StarArray[counter_bullet_star].rect.getGlobalBounds().intersects(Bad_TreeArray[counter_bad_tree].rect.getGlobalBounds()))
            {
                audioEngine.getPunch();
                //cout<<"Collision!"<<endl;
                Bad_TreeArray[counter_bad_tree].HP -= player.attackDamage;
                //cout<<"Enemy HP: "<< EnemyArray[counter2].HP<<endl;
                Bullet_StarArray[counter_bullet_star].destroyBullet = true;
                
                
                //Text display
                display_text.text.setString(to_string(player.attackDamage));
                //Center text and set him over enemy
                display_text.text.setPosition(Bad_TreeArray[counter_bad_tree].rect.getPosition().x+Bad_TreeArray[counter_bad_tree].rect.getSize().x/2, Bad_TreeArray[counter_bad_tree].rect.getPosition().y+Bad_TreeArray[counter_bad_tree].rect.getSize().y/2);
                displayTextArray.push_back(display_text);
                
                if(Bad_TreeArray[counter_bad_tree].HP<=0)
                {
                    Bad_TreeArray[counter_bad_tree].alive = false;
                }
            }
            counter_bad_tree++;
        }
        counter_bullet_star++;
    }

    
    //COLLISION WALKING TREE ENEMY WITH PLAYER
    counter_walking_tree = 0;
    for(iter_walking_tree= Walking_TreeArray.begin(); iter_walking_tree !=Walking_TreeArray.end(); iter_walking_tree++)
    {
        
        if(player.rect.getGlobalBounds().intersects(Walking_TreeArray[counter_walking_tree].rect.getGlobalBounds()))
        {
            if(elapsed5.asSeconds() >= 0.8)
            {
                
                player.HP -= Walking_TreeArray[counter_walking_tree].attackDamage;
                //Text display
                display_text.text.setString(to_string(Walking_TreeArray[counter_walking_tree].attackDamage));
                //Center text and set him over enemy
                display_text.text.setPosition(player.rect.getPosition().x+player.rect.getSize().x/2, player.rect.getPosition().y+player.rect.getSize().y/2);
                displayTextArray.push_back(display_text);
                audioEngine.getPunch();
                clock5.restart();
                
            }
            
            Walking_TreeArray[counter_walking_tree].aggroed = true;
            //enemy cant move
            if(Walking_TreeArray[counter_walking_tree].direction==1) //down
            {
                Walking_TreeArray[counter_walking_tree].canMoveDown =false;
                
            }
            else if(Walking_TreeArray[counter_walking_tree].direction==2) //up
            {
                Walking_TreeArray[counter_walking_tree].canMoveUp =false;
               
            }
            else if(Walking_TreeArray[counter_walking_tree].direction==3) //left
            {
                Walking_TreeArray[counter_walking_tree].canMoveLeft =false;
                
            }
            else if(Walking_TreeArray[counter_walking_tree].direction==4) //right
            {
                Walking_TreeArray[counter2].canMoveRight =false;
               
            }
            else
            {
                
            }
            
        }
        counter_walking_tree++;
    }
    
    //COLLISION BULLETS WITH WALKING TREE ENEMY
    counter1 = 0;
    for(iter=BulletArray.begin(); iter !=BulletArray.end(); iter++)
    {
        counter_walking_tree = 0;
        for(iter_walking_tree=Walking_TreeArray.begin(); iter_walking_tree !=Walking_TreeArray.end(); iter_walking_tree++)
        {
            if(BulletArray[counter1].rect.getGlobalBounds().intersects(Walking_TreeArray[counter_walking_tree].rect.getGlobalBounds()))
            {
                audioEngine.getPunch();
                //cout<<"Collision!"<<endl;
                Walking_TreeArray[counter_walking_tree].HP -= player.attackDamage;
                Walking_TreeArray[counter_walking_tree].aggroed = true; //enemy aggroed
                
                //cout<<"Enemy HP: "<< EnemyArray[counter2].HP<<endl;
                BulletArray[counter1].destroyBullet = true;
                
                
                //Text display
                display_text.text.setString(to_string(player.attackDamage));
                //Center text and set him over enemy
                display_text.text.setPosition(Walking_TreeArray[counter_walking_tree].rect.getPosition().x+Walking_TreeArray[counter_walking_tree].rect.getSize().x/2, Walking_TreeArray[counter_walking_tree].rect.getPosition().y+Walking_TreeArray[counter_walking_tree].rect.getSize().y/2);
                displayTextArray.push_back(display_text);
                
                if(Walking_TreeArray[counter_walking_tree].HP<=0)
                {
                    Walking_TreeArray[counter_walking_tree].alive = false;
                }
            }
            counter_walking_tree++;
        }
        counter1++;
    }
    
    
    
    //COLLISION BULLETS Star WITH WALKING TREE ENEMY
    counter_bullet_star = 0;
    for(iter_bullet_Star=Bullet_StarArray.begin(); iter_bullet_Star !=Bullet_StarArray.end(); iter_bullet_Star++)
    {
        counter_walking_tree = 0;
        for(iter_walking_tree=Walking_TreeArray.begin(); iter_walking_tree !=Walking_TreeArray.end(); iter_walking_tree++)
        {
            if(Bullet_StarArray[counter_bullet_star].rect.getGlobalBounds().intersects(Walking_TreeArray[counter_walking_tree].rect.getGlobalBounds()))
            {
                audioEngine.getPunch();
                //cout<<"Collision!"<<endl;
                Walking_TreeArray[counter_walking_tree].HP -= player.attackDamage;
                Walking_TreeArray[counter_walking_tree].aggroed = true; //enemy aggroed
                
                //cout<<"Enemy HP: "<< EnemyArray[counter2].HP<<endl;
                Bullet_StarArray[counter_bullet_star].destroyBullet = true;
                
                
                //Text display
                display_text.text.setString(to_string(player.attackDamage));
                //Center text and set him over enemy
                display_text.text.setPosition(Walking_TreeArray[counter_walking_tree].rect.getPosition().x+Walking_TreeArray[counter_walking_tree].rect.getSize().x/2, Walking_TreeArray[counter_walking_tree].rect.getPosition().y+Walking_TreeArray[counter_walking_tree].rect.getSize().y/2);
                displayTextArray.push_back(display_text);
                
                if(Walking_TreeArray[counter_walking_tree].HP<=0)
                {
                    Walking_TreeArray[counter_walking_tree].alive = false;
                }
            }
            counter_walking_tree++;
        }
        counter_bullet_star++;
    }

    
    //COLLISION WALKING TREE ENEMY WITH BAD TREE ENEMY
    
    counter_walking_tree = 0;
    for(iter_walking_tree = Walking_TreeArray.begin(); iter_walking_tree != Walking_TreeArray.end(); iter_walking_tree++)
    {
        
        counter_bad_tree = 0;
        for(iter_bad_tree=Bad_TreeArray.begin(); iter_bad_tree !=Bad_TreeArray.end(); iter_bad_tree++)
        {
            if(Walking_TreeArray[counter_walking_tree].rect.getGlobalBounds().intersects(Bad_TreeArray[counter_bad_tree].rect.getGlobalBounds()))
            {
                //cout<<"Enemy Wall collision"<<endl;
                
                if(Walking_TreeArray[counter_walking_tree].direction==1) //down
                {
                    Walking_TreeArray[counter_walking_tree].canMoveDown =false;
                    Walking_TreeArray[counter_walking_tree].rect.move(0, -5);
                }
                else if(Walking_TreeArray[counter_walking_tree].direction==2) //up
                {
                    Walking_TreeArray[counter_walking_tree].canMoveUp =false;
                    Walking_TreeArray[counter_walking_tree].rect.move(0, 5);
                }
                else if(Walking_TreeArray[counter_walking_tree].direction==3) //left
                {
                    Walking_TreeArray[counter_walking_tree].canMoveLeft =false;
                    Walking_TreeArray[counter_walking_tree].rect.move(5, 0);
                }
                else if(Walking_TreeArray[counter_walking_tree].direction==4) //right
                {
                    Walking_TreeArray[counter_walking_tree].canMoveRight =false;
                    Walking_TreeArray[counter_walking_tree].rect.move(-5, 0);
                }
                else
                {
                    
                }
                
                
                
            }
            counter_bad_tree++;
        }
        
        counter_walking_tree++;
    }
    
    
    //COLLISION WALKING TREE ENEMY WITH FIRE TREE ENEMY
    
    counter_walking_tree = 0;
    for(iter_walking_tree = Walking_TreeArray.begin(); iter_walking_tree != Walking_TreeArray.end(); iter_walking_tree++)
    {
        
        counter_fire_tree = 0;
        for(iter_fire_tree=Fire_TreeArray.begin(); iter_fire_tree !=Fire_TreeArray.end(); iter_fire_tree++)
        {
            if(Walking_TreeArray[counter_walking_tree].rect.getGlobalBounds().intersects(Fire_TreeArray[counter_fire_tree].rect.getGlobalBounds()))
            {
                //cout<<"Enemy Wall collision"<<endl;
                
                if(Walking_TreeArray[counter_walking_tree].direction==1) //down
                {
                    Walking_TreeArray[counter_walking_tree].canMoveDown =false;
                    Walking_TreeArray[counter_walking_tree].rect.move(0, -5);
                }
                else if(Walking_TreeArray[counter_walking_tree].direction==2) //up
                {
                    Walking_TreeArray[counter_walking_tree].canMoveUp =false;
                    Walking_TreeArray[counter_walking_tree].rect.move(0, 5);
                }
                else if(Walking_TreeArray[counter_walking_tree].direction==3) //left
                {
                    Walking_TreeArray[counter_walking_tree].canMoveLeft =false;
                    Walking_TreeArray[counter_walking_tree].rect.move(5, 0);
                }
                else if(Walking_TreeArray[counter_walking_tree].direction==4) //right
                {
                    Walking_TreeArray[counter_walking_tree].canMoveRight =false;
                    Walking_TreeArray[counter_walking_tree].rect.move(-5, 0);
                }
                else
                {
                    
                }
                
                
                
            }
            counter_fire_tree++;
        }
        
        counter_walking_tree++;
    }
    
    
    
    //COLLISION WALKING TREE ENEMY WITH WALLS
    
    counter_walking_tree = 0;
    for(iter_walking_tree = Walking_TreeArray.begin(); iter_walking_tree != Walking_TreeArray.end(); iter_walking_tree++)
    {
        
        counterWalls = 0;
        for(iter5=WallArray.begin(); iter5 !=WallArray.end(); iter5++)
        {
            if(Walking_TreeArray[counter_walking_tree].rect.getGlobalBounds().intersects(WallArray[counterWalls].rect.getGlobalBounds()))
            {
                //cout<<"Enemy Wall collision"<<endl;
                
                if(Walking_TreeArray[counter_walking_tree].direction==1) //down
                {
                    Walking_TreeArray[counter_walking_tree].canMoveDown =false;
                    Walking_TreeArray[counter_walking_tree].rect.move(0, -5);
                }
                else if(Walking_TreeArray[counter_walking_tree].direction==2) //up
                {
                    Walking_TreeArray[counter_walking_tree].canMoveUp =false;
                    Walking_TreeArray[counter_walking_tree].rect.move(0, 5);
                }
                else if(Walking_TreeArray[counter_walking_tree].direction==3) //left
                {
                    Walking_TreeArray[counter_walking_tree].canMoveLeft =false;
                    Walking_TreeArray[counter_walking_tree].rect.move(5, 0);
                }
                else if(Walking_TreeArray[counter_walking_tree].direction==4) //right
                {
                    Walking_TreeArray[counter_walking_tree].canMoveRight =false;
                    Walking_TreeArray[counter_walking_tree].rect.move(-5, 0);
                }
                else
                {
                    
                }
                
                
                
            }
            counterWalls++;
        }
        
        counter_walking_tree++;
    }
    
    
    //COLLISION BULLETS WITH WALLS
    counter1 = 0;
    for(iter=BulletArray.begin(); iter !=BulletArray.end(); iter++)
    {
        counterWalls = 0;
        for(iter5=WallArray.begin(); iter5 !=WallArray.end(); iter5++)
        {
            if(BulletArray[counter1].rect.getGlobalBounds().intersects(WallArray[counterWalls].rect.getGlobalBounds()))
            {
                
                BulletArray[counter1].destroyBullet = true;
                if(wall.canDestroy==true)
                {
                    WallArray[counterWalls].HP = WallArray[counterWalls].HP - player.attackDamage;
                    //Text display
                    display_text.text.setString(to_string(player.attackDamage));
                    //Center text and set him over enemy
                    display_text.text.setPosition(WallArray[counterWalls].rect.getPosition().x+WallArray[counterWalls].rect.getSize().x/2, WallArray[counterWalls].rect.getPosition().y+WallArray[counterWalls].rect.getSize().y/2);
                    displayTextArray.push_back(display_text);
                }
                else;
                if(WallArray[counterWalls].HP<=0)
                {
                    WallArray[counterWalls].destroy = true;
                }
                else;
                
            }
            counterWalls++;
        }
        counter1++;
    }
    
    //COLLISION BULLETS Star WITH WALLS
    counter_bullet_star = 0;
    for(iter_bullet_Star=Bullet_StarArray.begin(); iter_bullet_Star !=Bullet_StarArray.end(); iter_bullet_Star++)
    {
        counterWalls = 0;
        for(iter5=WallArray.begin(); iter5 !=WallArray.end(); iter5++)
        {
            if(Bullet_StarArray[counter_bullet_star].rect.getGlobalBounds().intersects(WallArray[counterWalls].rect.getGlobalBounds()))
            {
                
                Bullet_StarArray[counter_bullet_star].destroyBullet = true;
                if(wall.canDestroy==true)
                {
                    WallArray[counterWalls].HP = WallArray[counterWalls].HP - player.attackDamage;
                    //Text display
                    display_text.text.setString(to_string(player.attackDamage));
                    //Center text and set him over enemy
                    display_text.text.setPosition(WallArray[counterWalls].rect.getPosition().x+WallArray[counterWalls].rect.getSize().x/2, WallArray[counterWalls].rect.getPosition().y+WallArray[counterWalls].rect.getSize().y/2);
                    displayTextArray.push_back(display_text);
                }
                else;
                if(WallArray[counterWalls].HP<=0)
                {
                    WallArray[counterWalls].destroy = true;
                }
                else;
                
            }
            counterWalls++;
        }
        counter_bullet_star++;
    }
    
    
    //COLLISION FIRE TREE BULLETS WITH WALLS
    counter_enemy_bullet = 0;
    for(iter_enemy_bullet=EnemyBulletArray.begin(); iter_enemy_bullet !=EnemyBulletArray.end(); iter_enemy_bullet++)
    {
        counterWalls = 0;
        for(iter5=WallArray.begin(); iter5 !=WallArray.end(); iter5++)
        {
            if(EnemyBulletArray[counter_enemy_bullet].rect.getGlobalBounds().intersects(WallArray[counterWalls].rect.getGlobalBounds()))
            {
                
                EnemyBulletArray[counter_enemy_bullet].destroyBullet = true;
                
            }
            counterWalls++;
        }
        counter_enemy_bullet++;
    }
    

    
    
    //COLLISION BULLETS WITH HOUSE
    counter1 = 0;
    for(iter=BulletArray.begin(); iter !=BulletArray.end(); iter++)
    {
        counterHouse = 0;
        for(iterHouse = HouseArray.begin(); iterHouse !=HouseArray.end(); iterHouse++)
        {
            if(BulletArray[counter1].rect.getGlobalBounds().intersects(HouseArray[counterHouse].rect.getGlobalBounds()))
            {
                
                BulletArray[counter1].destroyBullet = true;
       
                
            }
            counterHouse++;
        }
        counter1++;
    }
    
    //COLLISION BULLETS star WITH HOUSE
    counter_bullet_star = 0;
    for(iter_bullet_Star=Bullet_StarArray.begin(); iter_bullet_Star !=Bullet_StarArray.end(); iter_bullet_Star++)
    {
        counterHouse = 0;
        for(iterHouse = HouseArray.begin(); iterHouse !=HouseArray.end(); iterHouse++)
        {
            if(Bullet_StarArray[counter_bullet_star].rect.getGlobalBounds().intersects(HouseArray[counterHouse].rect.getGlobalBounds()))
            {
                
                Bullet_StarArray[counter_bullet_star].destroyBullet = true;
                
                
            }
            counterHouse++;
        }
        counter_bullet_star++;
    }
    
 
    
    //COLLISION BULLETS WITH BOX
    counter1 = 0;
    for(iter=BulletArray.begin(); iter !=BulletArray.end(); iter++)
    {
        counterBox = 0;
        for(iterBox=BoxArray.begin(); iterBox !=BoxArray.end(); iterBox++)
        {
            if(BulletArray[counter1].rect.getGlobalBounds().intersects(BoxArray[counterBox].rect.getGlobalBounds()))
            {
                
                BulletArray[counter1].destroyBullet = true;
                
                BoxArray[counterBox].HP = BoxArray[counterBox].HP - player.attackDamage;
                //Text display
                display_text.text.setString(to_string(player.attackDamage));
                //Center text and set him over enemy
                display_text.text.setPosition(BoxArray[counterBox].rect.getPosition().x+BoxArray[counterBox].rect.getSize().x/2, BoxArray[counterBox].rect.getPosition().y+BoxArray[counterBox].rect.getSize().y/2);
                displayTextArray.push_back(display_text);
                
                if(BoxArray[counterBox].HP<=0)
                {
                    
                    BoxArray[counterBox].startDestruction = true;
                    
                    
                }
                else BoxArray[counterBox].startDestruction = false;
                
            }
            counterBox++;
            
            
            
        }
        counter1++;
    }
    
    //COLLISION BULLETS Star WITH BOX
    counter_bullet_star = 0;
    for(iter_bullet_Star=Bullet_StarArray.begin(); iter_bullet_Star !=Bullet_StarArray.end(); iter_bullet_Star++)
    {
        counterBox = 0;
        for(iterBox=BoxArray.begin(); iterBox !=BoxArray.end(); iterBox++)
        {
            if(Bullet_StarArray[counter_bullet_star].rect.getGlobalBounds().intersects(BoxArray[counterBox].rect.getGlobalBounds()))
            {
                
                Bullet_StarArray[counter_bullet_star].destroyBullet = true;
                
                BoxArray[counterBox].HP = BoxArray[counterBox].HP - player.attackDamage;
                //Text display
                display_text.text.setString(to_string(player.attackDamage));
                //Center text and set him over enemy
                display_text.text.setPosition(BoxArray[counterBox].rect.getPosition().x+BoxArray[counterBox].rect.getSize().x/2, BoxArray[counterBox].rect.getPosition().y+BoxArray[counterBox].rect.getSize().y/2);
                displayTextArray.push_back(display_text);
                
                if(BoxArray[counterBox].HP<=0)
                {
                    
                    BoxArray[counterBox].startDestruction = true;
                    
                    
                }
                else BoxArray[counterBox].startDestruction = false;
                
            }
            counterBox++;
            
            
            
        }
        counter_bullet_star++;
    }

    
    return state_level;
}


void Engine::Aggro_walking_tree()
{
    sf::Time elapsed_aggroed = clock_aggroed.getElapsedTime();
    counter_walking_tree = 0;
    for(iter_walking_tree = Walking_TreeArray.begin(); iter_walking_tree != Walking_TreeArray.end(); iter_walking_tree++)
    {
        
        if(Walking_TreeArray[counter_walking_tree].aggroed == true)
        {
            if(elapsed_aggroed.asSeconds()>=0.4)
            {
                
                clock_aggroed.restart();
                int rand_activity = generateRandom(3);
                
               // 1 -> down, 2 -> up, 3 -> left , 4 -> right
                
                if(rand_activity==1) //shoot an chases player
                {
                    cout<<"shooting"<<endl;
                    
                    //player to left
                    if(player.rect.getPosition().x < Walking_TreeArray[counter_walking_tree].rect.getPosition().x && (abs(player.rect.getPosition().y - Walking_TreeArray[counter_walking_tree].rect.getPosition().y)<=100))
                    {
                        audioEngine.enemy_shooting();
                        enemy_bullet.direction = 3;
                        enemy_bullet.rect.setPosition(Walking_TreeArray[counter_walking_tree].rect.getPosition().x + Walking_TreeArray[counter_walking_tree].rect.getSize().x/2 - enemy_bullet.rect.getSize().x/2, Walking_TreeArray[counter_walking_tree].rect.getPosition().y + Walking_TreeArray[counter_walking_tree].rect.getSize().y/2 - enemy_bullet.rect.getSize().y/2);
                        EnemyBulletArray.push_back(enemy_bullet);
                        //change enemy direction
                        Walking_TreeArray[counter_walking_tree].direction=3;
                        
                    }
                    
                    //player to right
                    if((player.rect.getPosition().x > Walking_TreeArray[counter_walking_tree].rect.getPosition().x) && (abs(player.rect.getPosition().y - Walking_TreeArray[counter_walking_tree].rect.getPosition().y) <=100))
                    {
                        audioEngine.enemy_shooting();
                        enemy_bullet.direction = 4;
                        enemy_bullet.rect.setPosition(Walking_TreeArray[counter_walking_tree].rect.getPosition().x + Walking_TreeArray[counter_walking_tree].rect.getSize().x/2 - enemy_bullet.rect.getSize().x/2, Walking_TreeArray[counter_walking_tree].rect.getPosition().y + Walking_TreeArray[counter_walking_tree].rect.getSize().y/2-enemy_bullet.rect.getSize().y/2);
                        EnemyBulletArray.push_back(enemy_bullet);
                        //change enemy direction
                        Walking_TreeArray[counter_walking_tree].direction = 4;
                    }
                    
                    //player to top
                    if((player.rect.getPosition().y < Walking_TreeArray[counter_walking_tree].rect.getPosition().y) && (abs(player.rect.getPosition().x - Walking_TreeArray[counter_walking_tree].rect.getPosition().x) <= 100))
                    {
                        audioEngine.enemy_shooting();
                        enemy_bullet.direction = 2;
                        enemy_bullet.rect.setPosition(Walking_TreeArray[counter_walking_tree].rect.getPosition().x + Walking_TreeArray[counter_walking_tree].rect.getSize().x/2 - enemy_bullet.rect.getSize().x/2, Walking_TreeArray[counter_walking_tree].rect.getPosition().y + Walking_TreeArray[counter_walking_tree].rect.getSize().y/2 - enemy_bullet.rect.getSize().y/2);
                        EnemyBulletArray.push_back(enemy_bullet);
                        //change enemy direction
                        Walking_TreeArray[counter_walking_tree].direction = 2;
                        
                    }
                    
                    
                    //player to down
                    if((player.rect.getPosition().y > Walking_TreeArray[counter_walking_tree].rect.getPosition().y) && (abs(player.rect.getPosition().x - Walking_TreeArray[counter_walking_tree].rect.getPosition().x) <= 100))
                    {
                        audioEngine.enemy_shooting();
                        enemy_bullet.direction = 1;
                        enemy_bullet.rect.setPosition(Walking_TreeArray[counter_walking_tree].rect.getPosition().x + Walking_TreeArray[counter_walking_tree].rect.getSize().x/2 - enemy_bullet.rect.getSize().x/2, Walking_TreeArray[counter_walking_tree].rect.getPosition().y + Walking_TreeArray[counter_walking_tree].rect.getSize().y/2 - enemy_bullet.rect.getSize().y/2);
                        EnemyBulletArray.push_back(enemy_bullet);
                        //change enemy direction
                        Walking_TreeArray[counter_walking_tree].direction = 1;
                        
                    }
                    
                    
                    
                }
                
                //1 -> down, 2 -> up, 3 -> left , 4 -> right
                
                else if(rand_activity ==2) //enemy chases player (starts on Y direction)
                {
                    cout<<"chases Y"<<endl;
                    if(player.rect.getPosition().y < Walking_TreeArray[counter_walking_tree].rect.getPosition().y)
                    {
                        Walking_TreeArray[counter_walking_tree].direction = 2; // up
                    }
                    else if (player.rect.getPosition().y > Walking_TreeArray[counter_walking_tree].rect.getPosition().y)
                    {
                        Walking_TreeArray[counter_walking_tree].direction = 1; //down
                    }
                    else if ( player.rect.getPosition().x < Walking_TreeArray[counter_walking_tree].rect.getPosition().x)
                    {
                        Walking_TreeArray[counter_walking_tree].direction = 3; //left
                    }
                    else if (player.rect.getPosition().x > Walking_TreeArray[counter_walking_tree].rect.getPosition().x)
                    {
                        Walking_TreeArray[counter_walking_tree].direction = 4; //right
                    }
                }
                else //enemy chases player (starts on X direction)
                {
                    cout<<"chases X"<<endl;
                    if(player.rect.getPosition().x <Walking_TreeArray[counter_walking_tree].rect.getPosition().x)
                    {
                        Walking_TreeArray[counter_walking_tree].direction = 3; //left
                    }
                    else if(player.rect.getPosition().x > Walking_TreeArray[counter_walking_tree].rect.getPosition().x)
                    {
                        Walking_TreeArray[counter_walking_tree].direction = 4; //right
                    }
                    else if(player.rect.getPosition().y < Walking_TreeArray[counter_walking_tree].rect.getPosition().y)
                    {
                        Walking_TreeArray[counter_walking_tree].direction = 2; //up
                    }
                    else if(player.rect.getPosition().y > Walking_TreeArray[counter_walking_tree].rect.getPosition().y)
                    {
                        Walking_TreeArray[counter_walking_tree].direction = 1; //down
                    }
                }
            }
        }
        
        counter_walking_tree++;
    }
}



void Engine::Aggro_wolf()
{
    sf::Time elapsed_aggroed = clock_aggroed.getElapsedTime();
    counter2 = 0;
    for(iter2 = EnemyArray.begin(); iter2 != EnemyArray.end(); iter2++)
    {
        
        if(EnemyArray[counter2].aggroed == true)
        {
            EnemyArray[counter2].movement_speed = 10;
            if(elapsed_aggroed.asSeconds()>=0.4)
            {
                
                clock_aggroed.restart();
                int rand_activity = generateRandom(2);
                
 
                //1 -> down, 2 -> up, 3 -> left , 4 -> right
                
                 if(rand_activity ==1) //enemy chases player (starts on Y direction)
                {
                    cout<<"chases Y"<<endl;
                    if(player.rect.getPosition().y < EnemyArray[counter2].rect.getPosition().y)
                    {
                        EnemyArray[counter2].direction = 2; // up
                    }
                    else if (player.rect.getPosition().y > EnemyArray[counter2].rect.getPosition().y)
                    {
                        EnemyArray[counter2].direction = 1; //down
                    }
                    else if ( player.rect.getPosition().x < EnemyArray[counter2].rect.getPosition().x)
                    {
                        EnemyArray[counter2].direction = 3; //left
                    }
                    else if (player.rect.getPosition().x > EnemyArray[counter2].rect.getPosition().x)
                    {
                        EnemyArray[counter2].direction = 4; //right
                    }
                }
                else //enemy chases player (starts on X direction)
                {
                    cout<<"chases X"<<endl;
                    if(player.rect.getPosition().x < EnemyArray[counter2].rect.getPosition().x)
                    {
                        EnemyArray[counter2].direction = 3; //left
                    }
                    else if(player.rect.getPosition().x > EnemyArray[counter2].rect.getPosition().x)
                    {
                        EnemyArray[counter2].direction = 4; //right
                    }
                    else if(player.rect.getPosition().y < EnemyArray[counter2].rect.getPosition().y)
                    {
                        EnemyArray[counter2].direction = 2; //up
                    }
                    else if(player.rect.getPosition().y > EnemyArray[counter2].rect.getPosition().y)
                    {
                        EnemyArray[counter2].direction = 1; //down
                    }
                }
            }
        }
        
        counter2++;
    }
}


void Engine::Item_shop_collisions()
{
    //with poskramiacz
    if(player.rect.getGlobalBounds().intersects(poskramiacz.rect.getGlobalBounds()))
    {
        cout<<"Collision with poskramiacz!"<<endl;
        
        
        if(player.direction==1) //down
        {
            player.canMoveDown =false;
            
            player.rect.move(0, -5);
        }
        else if(player.direction==2) //up
        {
            player.canMoveUp =false;
            
            player.rect.move(0, 5);
        }
        else if(player.direction==3) //left
        {
            player.canMoveLeft =false;
            
            player.rect.move(5, 0);
        }
        else if(player.direction==4) //right
        {
            player.canMoveRight =false;
            
            player.rect.move(-5, 0);
        }
        else
        {
            
        }
    }
    
    
    //with fire gun
    if(player.rect.getGlobalBounds().intersects(fire_gun.rect.getGlobalBounds()))
    {
        cout<<"Collision with fire_gun!"<<endl;
        
        if(player.direction==1) //down
        {
            player.canMoveDown =false;
            
            player.rect.move(0, -5);
        }
        else if(player.direction==2) //up
        {
            player.canMoveUp =false;
            
            player.rect.move(0, 5);
        }
        else if(player.direction==3) //left
        {
            player.canMoveLeft =false;
            
            player.rect.move(5, 0);
        }
        else if(player.direction==4) //right
        {
            player.canMoveRight =false;
            
            player.rect.move(-5, 0);
        }
        else
        {
            
        }
    }
    
    //with freeze gun
    if(player.rect.getGlobalBounds().intersects(freeze_gun.rect.getGlobalBounds()))
    {
        cout<<"Collision with freeze_gun!"<<endl;
        
        if(player.direction==1) //down
        {
            player.canMoveDown =false;
            
            player.rect.move(0, -5);
        }
        else if(player.direction==2) //up
        {
            player.canMoveUp =false;
            
            player.rect.move(0, 5);
        }
        else if(player.direction==3) //left
        {
            player.canMoveLeft =false;
            
            player.rect.move(5, 0);
        }
        else if(player.direction==4) //right
        {
            player.canMoveRight =false;
            
            player.rect.move(-5, 0);
        }
        else
        {
            
        }
    }
    
    //with ring
    if(player.rect.getGlobalBounds().intersects(ring.rect.getGlobalBounds()))
    {
        cout<<"Collision with ring!"<<endl;
        
        if(player.direction==1) //down
        {
            player.canMoveDown =false;
            
            player.rect.move(0, -5);
        }
        else if(player.direction==2) //up
        {
            player.canMoveUp =false;
            
            player.rect.move(0, 5);
        }
        else if(player.direction==3) //left
        {
            player.canMoveLeft =false;
            
            player.rect.move(5, 0);
        }
        else if(player.direction==4) //right
        {
            player.canMoveRight =false;
            
            player.rect.move(-5, 0);
        }
        else
        {
            
        }
    }
    
    //with star gun
    if(player.rect.getGlobalBounds().intersects(star_gun.rect.getGlobalBounds()))
    {
        cout<<"Collision with star gun!"<<endl;
        
        if(player.direction==1) //down
        {
            player.canMoveDown =false;
            
            player.rect.move(0, -5);
        }
        else if(player.direction==2) //up
        {
            player.canMoveUp =false;
            
            player.rect.move(0, 5);
        }
        else if(player.direction==3) //left
        {
            player.canMoveLeft =false;
            
            player.rect.move(5, 0);
        }
        else if(player.direction==4) //right
        {
            player.canMoveRight =false;
            
            player.rect.move(-5, 0);
        }
        else
        {
            
        }
    }
    
    //with hp potion
    if(player.rect.getGlobalBounds().intersects(hp_potion.rect.getGlobalBounds()))
    {
        cout<<"Collision with hp_potion!"<<endl;
        
        if(player.direction==1) //down
        {
            player.canMoveDown =false;
            
            player.rect.move(0, -5);
        }
        else if(player.direction==2) //up
        {
            player.canMoveUp =false;
            
            player.rect.move(0, 5);
        }
        else if(player.direction==3) //left
        {
            player.canMoveLeft =false;
            
            player.rect.move(5, 0);
        }
        else if(player.direction==4) //right
        {
            player.canMoveRight =false;
            
            player.rect.move(-5, 0);
        }
        else
        {
            
        }
    }
    
    //with doors
    if(player.rect.getGlobalBounds().intersects(exit_shop_door.rect.getGlobalBounds()))
    {
        cout<<"Player collide with exit_shop_door"<<endl;
        exit_shop_door.can_go_next = true;
    }
    else
    {
        exit_shop_door.can_go_next = false;
    }
    
}

void Engine::check_IsPredatorNear(int distance_predator)
{
    counter2 = 0;
    sf::Time elapsed_predatorIsHere = clock_predatorIsHere.getElapsedTime();
    for(iter2=EnemyArray.begin(); iter2 !=EnemyArray.end(); iter2++)
    {

    //cheking if predator is near
    distance_predator = check_distance(player.rect.getPosition().x, player.rect.getPosition().y, EnemyArray[counter2].rect.getPosition().x, EnemyArray[counter2].rect.getPosition().y);
    if(canShowPredatorDistance==true)
    {
        cout<<"Predator's distance: "<<distance_predator<<endl;
    }
    else;
    //distance in pixels
    if(enemy_wolf.canBeInvisible==true)
    {
        
            if(distance_predator<=290&&distance_predator>270)
            {
            
                EnemyArray[counter2].sprite.setColor(sf::Color(100,100,100,20));
            }
            else if(distance_predator<=280&&distance_predator>270)
            {
            
                EnemyArray[counter2].sprite.setColor(sf::Color(100,100,100,40));
            }
            else if(distance_predator<=270&&distance_predator>260)
            {
            
                EnemyArray[counter2].sprite.setColor(sf::Color(100,100,100,60));
            }
            else if(distance_predator<=260&&distance_predator>240)
            {
            
                EnemyArray[counter2].sprite.setColor(sf::Color(100,100,100,80));
            }
            else if(distance_predator<=240&&distance_predator>230)
            {
            
                EnemyArray[counter2].sprite.setColor(sf::Color(100,100,100,100));
            }
            else if(distance_predator<=230&&distance_predator>220)
            {
            
                EnemyArray[counter2].sprite.setColor(sf::Color(100,100,100,120));
            }
            else if(distance_predator<=220&&distance_predator>210)
            {
            
                EnemyArray[counter2].sprite.setColor(sf::Color(100,100,100,140));
            }
            else if(distance_predator<=210&&distance_predator>200)
            {
            
                EnemyArray[counter2].sprite.setColor(sf::Color(100,100,100,150));
            }
            else if(distance_predator<=200&&distance_predator>190)
            {
            
                EnemyArray[counter2].sprite.setColor(sf::Color(100,100,100,170));
            }
        
            else if(distance_predator<=190&&distance_predator>180)
            {
            
                EnemyArray[counter2].sprite.setColor(sf::Color(100,100,100,190));
            }
            else if(distance_predator<=180&&distance_predator>160)
            {
            
                EnemyArray[counter2].sprite.setColor(sf::Color(100,100,100,200));
            }
            else if(distance_predator<=160&&distance_predator>160)
            {
            
                EnemyArray[counter2].sprite.setColor(sf::Color(100,100,100,220));
            }
            else if(distance_predator<=160&&distance_predator>150)
            {
            
                EnemyArray[counter2].sprite.setColor(sf::Color(100,100,100,240));
            }
            else  if(distance_predator<=150)
            {
                if(elapsed_predatorIsHere.asSeconds()>=5.5)
                {
                    int change_sound = generateRandom(4); //from 1 to 4, without 0!
                    clock_predatorIsHere.restart();
                    audioEngine.enemyIsHere(change_sound);
                    cout<<"Predator is here!!"<<endl;
                }
                EnemyArray[counter2].sprite.setColor(sf::Color(255,255,255,255));
            }
            else
            {
            EnemyArray[counter2].sprite.setColor(sf::Color(0,0,0,0));
            }
        
        
        }
        else
        {
            EnemyArray[counter2].sprite.setColor(sf::Color(255,255,255,255));
        }
        
   counter2++;
    }
}

void Engine::check_distance_from_items(bool *can_play1, bool *can_play2, bool *can_play3, bool *can_play4, bool *can_play5, bool *can_play6)
{
    float distance_poskramiacz = check_distance(player.rect.getPosition().x+27, player.rect.getPosition().y+35, poskramiacz.rect.getPosition().x+40, poskramiacz.rect.getPosition().y+40);
    float distance_ring = check_distance(player.rect.getPosition().x+27, player.rect.getPosition().y+35, ring.rect.getPosition().x+40, ring.rect.getPosition().y+40);
    float distance_freeze_gun = check_distance(player.rect.getPosition().x+27, player.rect.getPosition().y+35, freeze_gun.rect.getPosition().x+40, freeze_gun.rect.getPosition().y+40);
    float distance_star_gun = check_distance(player.rect.getPosition().x+27, player.rect.getPosition().y+35, star_gun.rect.getPosition().x+40, star_gun.rect.getPosition().y+40);
    float distance_hp_potion = check_distance(player.rect.getPosition().x+27, player.rect.getPosition().y+35, hp_potion.rect.getPosition().x+40, hp_potion.rect.getPosition().y+40);
    float distance_fire_gun = check_distance(player.rect.getPosition().x+27, player.rect.getPosition().y+35, fire_gun.rect.getPosition().x+40, fire_gun.rect.getPosition().y+40);
    
    int distance = 100;
    int new_size = 25;
    int old_size = 0;
    float time =0.8;
    
    sf::Time elapsed_select = clock_select.getElapsedTime();

    
    if(distance_poskramiacz<=distance)
    {
       
        price_poskramiacz.text.setCharacterSize(new_size);
        can_buy_poskramiacz = true;
        
        if(elapsed_select.asSeconds()>=time && *can_play1 == true)
        {
            audioEngine.select();
            *can_play1= false;
            clock_select.restart();
        }
        
        
   
    }
    else
    {
        can_buy_poskramiacz = false;
        *can_play1= true;
    price_poskramiacz.text.setCharacterSize(old_size);
    }
    
    
    if(distance_ring<=distance)
    {
        can_buy_ring = true;
        price_ring.text.setCharacterSize(new_size);
        
        if(elapsed_select.asSeconds()>=time && *can_play2 == true)
        {
            audioEngine.select();
            *can_play2= false;
            clock_select.restart();
        }
        
    }
    else
    {
        can_buy_ring = false;
       *can_play2= true;
    price_ring.text.setCharacterSize(old_size);
    }
    
    if(distance_fire_gun<=distance)
    {
        can_buy_fire_gun = true;
        price_fire_gun.text.setCharacterSize(new_size);
        
        if(elapsed_select.asSeconds()>=time && *can_play3 == true)
        {
        
            audioEngine.select();
            *can_play3 = false;
            clock_select.restart();
        }
        
        
    }
    else
    {
        can_buy_fire_gun = false;
        *can_play3 = true;
    price_fire_gun.text.setCharacterSize(old_size);
    }

    if(distance_star_gun<=distance)
    {
        can_buy_star_gun = true;
        price_star_gun.text.setCharacterSize(new_size);
        
        if(elapsed_select.asSeconds()>=time && *can_play4 == true)
        {
            audioEngine.select();
            *can_play4 = false;
            clock_select.restart();
        }
        
    }
    else
    {
        can_buy_star_gun = false;
       *can_play4 = true;
    price_star_gun.text.setCharacterSize(old_size);
    }
    
    if(distance_freeze_gun<=distance)
    {
        can_buy_freeze_gun = true;
        
        price_freeze_gun.text.setCharacterSize(new_size);
        
        if(elapsed_select.asSeconds()>=time && *can_play5 == true)
        {
            audioEngine.select();
            *can_play5 = false;
            clock_select.restart();
        }
        
    }
    else
    {
        can_buy_freeze_gun = false;
     *can_play5 = true;
    price_freeze_gun.text.setCharacterSize(old_size);
    }
    
    if(distance_hp_potion<=distance)
    {
        can_buy_hp_potion = true;
        price_hp_potion.text.setCharacterSize(new_size);
        
        if(elapsed_select.asSeconds()>=time && *can_play6 == true)
        {
            audioEngine.select();
            *can_play6 = false;
            clock_select.restart();
        }
        
    }
    else
    {
        can_buy_hp_potion = false;
        *can_play6 = true;
        price_hp_potion.text.setCharacterSize(old_size);
    }
    
    


}


void Engine::DeleteObjects()
{
    
    //Delete dead enemy
    counter2 = 0;
    for(iter2 = EnemyArray.begin(); iter2 != EnemyArray.end(); iter2++)
    {
        if(EnemyArray[counter2].alive == false)
        {
            audioEngine.enemyDead();
            //generate random coin
            if(generateRandom(2)==1)
            {
                //CoinArray[counterCoins].rect.setPosition(EnemyArray[counter2].rect.getPosition());
                coin.rect.setPosition(EnemyArray[counter2].rect.getPosition());
                CoinArray.push_back(coin);
                audioEngine.getCoin();
            }
            cout<<"Enemy has been deleted"<<endl;
            EnemyArray.erase(iter2);
            break;
        }
        counter2++;
    }
    
    //Delete dead enemy fire tree
    counter_fire_tree = 0;
    for(iter_fire_tree =Fire_TreeArray.begin(); iter_fire_tree != Fire_TreeArray.end(); iter_fire_tree++)
    {
        if(Fire_TreeArray[counter_fire_tree].alive == false)
        {
            audioEngine.enemyDead();
            //generate random coin
            if(generateRandom(2)==1)
            {
                //CoinArray[counterCoins].rect.setPosition(EnemyArray[counter2].rect.getPosition());
                coin.rect.setPosition(Fire_TreeArray[counter_fire_tree].rect.getPosition());
                CoinArray.push_back(coin);
                audioEngine.getCoin();
            }
            cout<<"Enemy has been deleted"<<endl;
            Fire_TreeArray.erase(iter_fire_tree);
            break;
        }
        counter_fire_tree++;
    }
    
    //Delete dead enemy bad tree
    counter_bad_tree = 0;
    for(iter_bad_tree = Bad_TreeArray.begin(); iter_bad_tree != Bad_TreeArray.end(); iter_bad_tree++)
    {
        if(Bad_TreeArray[counter_bad_tree].alive == false)
        {
            audioEngine.enemyDead();
            //generate random coin
            if(generateRandom(2)==1)
            {
                //CoinArray[counterCoins].rect.setPosition(EnemyArray[counter2].rect.getPosition());
                coin.rect.setPosition(Bad_TreeArray[counter_bad_tree].rect.getPosition());
                CoinArray.push_back(coin);
                audioEngine.getCoin();
            }
            cout<<"Enemy has been deleted"<<endl;
            Bad_TreeArray.erase(iter_bad_tree);
            break;
        }
        counter_bad_tree++;
    }
    
    //Delete dead enemy walking tree
    counter_walking_tree = 0;
    for(iter_walking_tree = Walking_TreeArray.begin(); iter_walking_tree != Walking_TreeArray.end(); iter_walking_tree++)
    {
        if(Walking_TreeArray[counter_walking_tree].alive == false)
        {
            audioEngine.enemyDead();
            //generate random coin
            if(generateRandom(2)==1)
            {
                //CoinArray[counterCoins].rect.setPosition(EnemyArray[counter2].rect.getPosition());
                coin.rect.setPosition(Walking_TreeArray[counter_walking_tree].rect.getPosition());
                CoinArray.push_back(coin);
                audioEngine.getCoin();
            }
            Walking_TreeArray.erase(iter_walking_tree);
            break;
        }
        counter_walking_tree++;
    }
    
    
    //DELETE  BOXES
    counterBox = 0;
    for(iterBox = BoxArray.begin(); iterBox!= BoxArray.end(); iterBox++)
    {
        if(BoxArray[counterBox].destroy == true)
        {
            
            
           
            //generate random coin
            if(generateRandom(1)==1)
            {
                coin.rect.setPosition(BoxArray[counterBox].rect.getPosition());
               // CoinArray[counterCoins].rect.setPosition(CoinArray[counterBox].rect.getPosition());
               // coin.rect.setPosition(BoxArray[counterBox].rect.getPosition().x,BoxArray[counterBox].rect.getPosition().y);
                cout<<"Coin future position X: "<<BoxArray[counterBox].rect.getPosition().x<<"  Y: "<<BoxArray[counterBox].rect.getPosition().y<<endl;
                CoinArray.push_back(coin);
                cout<<"Coin created"<<endl;
                cout<<"Coin coords: "<<coin.rect.getPosition().x<<" : "<<coin.rect.getPosition().y<<endl;
                audioEngine.getCoin();
                
                
            
            }
            
             BoxArray.erase(iterBox);
            break;
        }
        
        
        counterBox++;
    }
    
    
    
    //Delete bullet after collision and after bulletLifeTime
    counter1= 0;
    for(iter = BulletArray.begin(); iter != BulletArray.end(); iter++)
    {
        if(BulletArray[counter1].destroyBullet == true)
        {
            //cout<<"Bullet has been deleted"<<endl;
            BulletArray.erase(iter);
            break;
        }
        counter1++;
    }
    
    //Delete bullet star after collision and after bulletLifeTime
    counter_bullet_star= 0;
    for(iter_bullet_Star = Bullet_StarArray.begin(); iter_bullet_Star != Bullet_StarArray.end(); iter_bullet_Star++)
    {
        if(Bullet_StarArray[counter_bullet_star].destroyBullet == true)
        {
            //cout<<"Bullet has been deleted"<<endl;
            Bullet_StarArray.erase(iter_bullet_Star);
            break;
        }
        counter_bullet_star++;
    }
    
    //Delete fire tree bullet after collision and after bulletLifeTime
    counter_enemy_bullet= 0;
    for(iter_enemy_bullet = EnemyBulletArray.begin(); iter_enemy_bullet != EnemyBulletArray.end(); iter_enemy_bullet++)
    {
        if(EnemyBulletArray[counter_enemy_bullet].destroyBullet == true)
        {
            //cout<<"Bullet has been deleted"<<endl;
            EnemyBulletArray.erase(iter_enemy_bullet);
            break;
        }
        counter_enemy_bullet++;
    }
    
    //DELETE TEXT AFTER LIFETIME
    counterText = 0;
    for(iter3 = displayTextArray.begin(); iter3!= displayTextArray.end(); iter3++)
    {
        if(displayTextArray[counterText].destroy == true)
        {
            displayTextArray.erase(iter3);
            break;
        }
        counterText++;
    }
    //DELETE BUY-ITEMS-TEXT AFTER LIFETIME
    counterText_buy = 0;
    for(iter_buy = displayTextBuyArray.begin(); iter_buy!= displayTextBuyArray.end(); iter_buy++)
    {
        if(displayTextBuyArray[counterText_buy].destroy == true)
        {
            displayTextBuyArray.erase(iter_buy);
            break;
        }
        counterText_buy++;
    }
    
    //DELETE Coins
    counterCoins = 0;
    for(iter4 = CoinArray.begin(); iter4!= CoinArray.end(); iter4++)
    {
        if(CoinArray[counterCoins].destroy == true)
        {
            CoinArray.erase(iter4);
            cout<<"Coin deleted"<<endl;
            break;
        }
        counterCoins++;
    }
    
    
    //DELETE  WALLS (if canDestroy)
    counterWalls = 0;
    for(iter5 = WallArray.begin(); iter5!= WallArray.end(); iter5++)
    {
        if(WallArray[counterWalls].destroy == true)
        {
            WallArray.erase(iter5);
            break;
        }
        counterWalls++;
    }
    

    
    
}



void Engine::KeyboardEvents(bool *canShowPredatorDistance ,int distance_predator)
{
    sf::Event event;
    
    sf::Time elapsed1 = clock1.getElapsedTime();
    sf::Time elapsed_show_invisible = clock_show_invisible.getElapsedTime();
    sf::Time elapsed_distance_from_predator = clock_distance_from_predator.getElapsedTime();
     sf::Time elapsedShowPos = clockShowPos.getElapsedTime();
    int shoot = 0;
    
    //BACK TO MAIN MENU
    
    while(window->pollEvent(event))
    {
        if(event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Escape)
        {
            state_level = END;
            cout<<"Back to main MENU"<<endl;
        }
        
        
    }
    
    
    
    
    //PUSHING-BACK BULLETS//////////////////
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        
    {
        
        if(elapsed1.asSeconds() >= shootingTime)
        {
            ////// SETTING BULLET IN THE MIDDLE PLAYER  /////////////
            bullet.rect.setPosition(player.rect.getPosition().x + player.rect.getSize().x/2 -bullet.rect.getSize().x/2, player.rect.getPosition().y+player.rect.getSize().y/2-bullet.rect.getSize().y/2);
            //star bullet
            bullet_star.rect.setPosition(player.rect.getPosition().x + player.rect.getSize().x/2 -bullet_star.rect.getSize().x/2, player.rect.getPosition().y+player.rect.getSize().y/2-bullet_star.rect.getSize().y/2);
            /////////////////////////////////////////////////////////
            bullet.direction = player.direction;
            bullet_star.direction = player.direction;
            
            // 0 -> Ogniki, 1 -> Lodowa Zamiec  , 2 -> Poskramiacz    , 3 -> Ognisty Jezyk  , 4 ->  Gwiezdna Rozdzczka

            
            if(player.current_weapon_int == 4)
            {
                cout<<"Bullet star!"<<endl;
                Bullet_StarArray.push_back(bullet_star);
            }
            else if( player.current_weapon_int ==1 )
            {
                bullet.bulletLifeTime = 8;
                bullet.sprite.setScale(sf::Vector2f(1,1));
                cout<<"Freeze bullet"<<endl;
                bullet.sprite.setColor(sf::Color::Blue);
            BulletArray.push_back(bullet);
            }
            else if( player.current_weapon_int ==2 )
            {
                bullet.bulletLifeTime = 12;
                bullet.sprite.setScale(sf::Vector2f(1,1));
                cout<<"Freeze bullet"<<endl;
                bullet.sprite.setColor(sf::Color::Cyan);
                BulletArray.push_back(bullet);
            }
            else if( player.current_weapon_int ==3 )
            {
                bullet.bulletLifeTime = 14;
                cout<<"Freeze bullet"<<endl;
                bullet.sprite.setScale(sf::Vector2f(1,1));
                 bullet.sprite.setColor(sf::Color(255,255,255,255));
                BulletArray.push_back(bullet);
            }
            
            
            else //( player.current_weapon_int ==0 )
            {
                bullet.bulletLifeTime = 6;
                bullet.sprite.setScale(sf::Vector2f(0.5,0.5));
                cout<<"Normal bullet"<<endl;
                BulletArray.push_back(bullet);
            }
            
            cout<<"SHOOT!"<<endl;
            audioEngine.shooting(shoot);
            clock1.restart();
            shoot++;
            if(shoot==5)
            {
                shoot=0;
            }
            
        }
    }
    
    
    //change level
    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::L))
    {
        
        state_level = LEVEL2;
            cout<<"level changed -> LEVEL2"<<endl;
       
        
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::M))
    {
        
        state_level = LEVEL1;
        cout<<"level changed -> LEVEL1"<<endl;
        
        
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::K))
    {
        
        state_level = SHOP;
        cout<<"level changed -> LEVEL3"<<endl;
        
        
    }

    
    //SETTING ENEMY'S INVISIBLE
    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::I))
    {
        if(elapsed_show_invisible.asSeconds()>=0.5)
        {
            if(enemy_wolf.canBeInvisible==true)
            {
                enemy_wolf.canBeInvisible = false;
            }
            else if(enemy_wolf.canBeInvisible==false)
            {
                enemy_wolf.canBeInvisible=true;
            }
            cout<<"Invisbile: "<<enemy_wolf.canBeInvisible<<endl;
            clock_show_invisible.restart();
        }
    }
    
    //SHOW DISTANCE PREDATOR-PLAYER
    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::O))
    {
        if(elapsed_distance_from_predator.asSeconds()>=0.3)
        {
            if(*canShowPredatorDistance==false)
            {
                *canShowPredatorDistance=true;
            }
            else if (*canShowPredatorDistance==true)
            {
                *canShowPredatorDistance= false;
            }
            else;
            cout<<"canShowPredatorDistance STATUS IS: "<<*canShowPredatorDistance<<endl;
            clock_distance_from_predator.restart();
        }
    }
    
    
    //show Player coordinates
    if(elapsedShowPos.asSeconds()>=0.15)
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            
        {
            cout<<"Player coord (X: "<<player.rect.getPosition().x<<", Y: "<<player.rect.getPosition().y<<")"<<endl;
            //cout<<"Mouse coord (X: "<<sf::Mouse::getPosition(*window).x<<", Y: "<<sf::Mouse::getPosition(*window).y<<")"<<endl;
        }
        clockShowPos.restart();
    }
    
}

void Engine::Fire_Tree_shooting()
{
    float distance = 0;
    counter_fire_tree = 0;
    sf::Time elapsed_Fire_Tree_shoot = clock_Fire_Tree_shoot.getElapsedTime();
    sf::Time elapsed_scary_laugh = clock_scary_laugh.getElapsedTime();
    for(iter_fire_tree= Fire_TreeArray.begin(); iter_fire_tree !=Fire_TreeArray.end(); iter_fire_tree++)
    {
        
        //cheking if predator is near
        distance = check_distance(player.rect.getPosition().x, player.rect.getPosition().y, Fire_TreeArray[counter_fire_tree].rect.getPosition().x+ 100, Fire_TreeArray[counter_fire_tree].rect.getPosition().y+ 100);
        //cout<<"Distance: "<<distance<<endl;
        
       // cout<<"elapsed: "<<elapsed_scary_laugh.asSeconds()<<endl;
        if(distance<=400)
        {
            
            Fire_TreeArray[counter_fire_tree].animation();
            if(elapsed_scary_laugh.asSeconds()>2.6)
            {
                Fire_TreeArray[counter_fire_tree].scary_laugh();
                clock_scary_laugh.restart();
            }
           
            

            if(elapsed_Fire_Tree_shoot.asSeconds()>=0.8)
            {
               
                clock_Fire_Tree_shoot.restart();
                enemy_bullet.direction=1; // down
                if(abs((player.rect.getPosition().x+30)-(Fire_TreeArray[counter_fire_tree].rect.getPosition().x+100))<120 && player.rect.getPosition().y>Fire_TreeArray[counter_fire_tree].rect.getPosition().y)
                   {
                      enemy_bullet.rect.setPosition(player.rect.getPosition().x, Fire_TreeArray[counter_fire_tree].rect.getPosition().y+ 100);
                   }
                else
                   {
                      enemy_bullet.rect.setPosition(Fire_TreeArray[counter_fire_tree].rect.getPosition().x+ 80, Fire_TreeArray[counter_fire_tree].rect.getPosition().y+ 100);
                   }
                audioEngine.enemy_shooting();
                EnemyBulletArray.push_back(enemy_bullet);
                
              
                enemy_bullet.direction=2; // up
                if(abs((player.rect.getPosition().x+30)-(Fire_TreeArray[counter_fire_tree].rect.getPosition().x+100))<120 && player.rect.getPosition().y<Fire_TreeArray[counter_fire_tree].rect.getPosition().y)
                {
                enemy_bullet.rect.setPosition(player.rect.getPosition().x, Fire_TreeArray[counter_fire_tree].rect.getPosition().y+ 100);
                }
                else
                {
                enemy_bullet.rect.setPosition(Fire_TreeArray[counter_fire_tree].rect.getPosition().x+ 80, Fire_TreeArray[counter_fire_tree].rect.getPosition().y+ 100);
                }
                audioEngine.enemy_shooting();
                EnemyBulletArray.push_back(enemy_bullet);
                
                
               // cout<<"abs left: "<<abs(player.rect.getPosition().y+30-(Fire_TreeArray[counter_fire_tree].rect.getPosition().y+100))<<endl;
                
                enemy_bullet.direction=3; // left
                 if(abs((player.rect.getPosition().y+30)-(Fire_TreeArray[counter_fire_tree].rect.getPosition().y+100))<120 && player.rect.getPosition().x<Fire_TreeArray[counter_fire_tree].rect.getPosition().x)
                 {
                    
                     enemy_bullet.rect.setPosition(Fire_TreeArray[counter_fire_tree].rect.getPosition().x+ 80, player.rect.getPosition().y);                 }
                 else
                 {
                    
                 enemy_bullet.rect.setPosition(Fire_TreeArray[counter_fire_tree].rect.getPosition().x+ 80, Fire_TreeArray[counter_fire_tree].rect.getPosition().y+ 100);
                 }
                audioEngine.enemy_shooting();
                EnemyBulletArray.push_back(enemy_bullet);
                
                
                enemy_bullet.direction=4; // right
                if(abs((player.rect.getPosition().y+30)-(Fire_TreeArray[counter_fire_tree].rect.getPosition().y+100))<120 && player.rect.getPosition().x>Fire_TreeArray[counter_fire_tree].rect.getPosition().x)
                {
                    enemy_bullet.rect.setPosition(Fire_TreeArray[counter_fire_tree].rect.getPosition().x+ 100, player.rect.getPosition().y);
                }
                else
                {
                    enemy_bullet.rect.setPosition(Fire_TreeArray[counter_fire_tree].rect.getPosition().x+ 80, Fire_TreeArray[counter_fire_tree].rect.getPosition().y+ 100);
                }
                audioEngine.enemy_shooting();
                EnemyBulletArray.push_back(enemy_bullet);
                
            }
            else;
        }
        else
        {
            Fire_TreeArray[counter_fire_tree].sprite.setTextureRect(sf::IntRect(600,0, 200, 200));
            
            Fire_TreeArray[counter_fire_tree].scary_laugh_stop();
           
        }
        counter_fire_tree++;
    }
}

void Engine::Editor()
{
    
    sf::Time elapsed2 = clock2.getElapsedTime();
   
    
    
    //ACTIVE COMMANDS
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        
        cout<<"Enter the code: ";
        cin>>code;
        if(code=="editON")
        {
            CanEdit = true;
        }
        if(code=="editOFF")
        {
            CanEdit = false;
        }
        else;
        cout<<"Edit status is: "<<CanEdit<<endl;
    }
    
    
    
    
    if(CanEdit==true)
    {
        
        
        //Change wall canDestroy
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
        {
            cout<<"Wall canDestroy now is: "<<wall.canDestroy<<endl;
            cout<<"Enter the code: ";
            cin>>code;
            if(code=="destroyWallON")
            {
                wall.canDestroy = true;
            }
            if(code=="destroyWallOFF")
            {
                wall.canDestroy = false;
            }
            else;
            cout<<"Wall canDestroy status is: "<<wall.canDestroy<<endl;
        }
        //PUSH-BACK ENEMIES
        
        if(elapsed2.asSeconds() >= 0.15)
        {
            clock2.restart();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::C))
            {
                EnemyArray.push_back(enemy_wolf);
                enemy_wolf.rect.setPosition(generateRandom(4000), generateRandom(400));
                
                // cout<<"Object ENEMY has been created."<<endl;
                // cout<<enemy.rect.getPosition().x<<endl;
                // cout<<enemy.rect.getPosition().y<<endl;
            }
        }
        
        
    
        
        
        
        
        
    }
    
    else{}
}

void Engine::loadPlayer(Player *player)
{
    
    //loading player from file
    int coordXPlayer;
    int coordYPlayer;
    int hp;
    int money;
    int weapon;
    int attack;
    int move_speed;
    int line_number = 1;
    
    file_player.open("player.txt", ios::in);
    {
        if(file_player.good()==false)
        {
            cout<<"Cant open player.txt"<<endl;;
            return EXIT_FAILURE;
        }
        string line;
        while (getline(file_player, line))
        {
            
            
            switch (line_number)
            {
                case 1:
                    coordXPlayer = atoi(line.c_str());
                    break;
                case 2:
                    coordYPlayer = atoi(line.c_str());
                    break;
                case 3:
                    hp = atoi(line.c_str());
                    break;
                case 4:
                    money = atoi(line.c_str());
                    break;
                case 5:
                    weapon = atoi(line.c_str());
                    break;
                case 6:
                    attack = atoi(line.c_str());
                    break;
                case 7:
                    move_speed = atoi(line.c_str());
                    break;
            }
            
            
            line_number++;
        }
        
        if(hp<=0)
        {
            hp=10;
            money = 0;
            move_speed = 5;
            weapon =0;
        }
        else;
        
        if(move_speed<=0)
        {
            move_speed = 5;
            
        }
        else;
        
        string attack_string = to_string(attack);
        if(attack==0 || attack_string =="")
        {
            attack = 1;
        }
        else;
        
        
        // 0 -> Ogniki, 1 -> Lodowa Zamiec  , 2 -> Poskramiacz    , 3 -> Ognisty Jezyk  , 4 ->  Gwiezdna Rozdzczka
        if(weapon==0)
        {
            player->current_weapon = "Ogniki";
            player->current_weapon_int = 0;
            attack = 1;
        }
        else if(weapon == 1)
        {
            player->current_weapon = "Lodowa Zamiec";
            player->current_weapon_int = 1;

            attack = freeze_gun.damage;
        }
        
        else if(weapon == 2)
        {
            player->current_weapon = "Poskramiacz";
            player->current_weapon_int = 2;

            attack = poskramiacz.damage;
        }
        
        else if(weapon == 3)
        {
            player->current_weapon = "Ognisty Jezyk";
            player->current_weapon_int = 3;

            attack = fire_gun.damage;
        }
        
        else if(weapon == 4)
        {
            player->current_weapon = "Gwiezdna Rozdzczka";
            player->current_weapon_int = 4;

            attack = star_gun.damage;
        }
        
        
  
        else
        {
            player->current_weapon = "Ogniki";
            player->current_weapon_int = 0;

            attack = 1;
        }
        

       
    file_player.close();
    player->rect.setPosition(coordXPlayer, coordYPlayer);
    player->HP = hp;
    player->gold = money;
    player->movement_speed = move_speed;
    //player->current_weapon = weapon;
    player->attackDamage = attack;
    cout<<"Player is loaded"<<endl;
    cout<<"Player pos X: "<<player->rect.getPosition().x<<endl;
    cout<<"Player pos Y: "<<player->rect.getPosition().y<<endl;
    cout<<"Player HP: "<<player->HP<<endl;
    cout<<"Player GOLD: "<<player->gold<<endl;
    cout<<"Player WEAPON: "<<player->current_weapon<<endl;
    cout<<"Player ATTACK DAMAGE: "<<player->attackDamage<<endl;
    cout<<"Player MOVEMENT SPEED: "<<player->movement_speed<<endl;
    
}
}

int Engine::loadEngine()
{
    int level;
    int line_number = 1;
    
    file.open("engine.txt", ios::in);
    {
        if(file.good()==false)
        {
            cout<<"Cant open engine.txt"<<endl;;
            return EXIT_FAILURE;
        }
        string line;
        while (getline(file, line))
        {
            
            
            switch (line_number)
            {
                case 1:
                    level = atoi(line.c_str());
                    break;

            }
            
            
            line_number++;
        }
        
    }
    
    if(level == 0)
    {
        state_level = LEVEL1;
    }
    else if(level == 1)
    {
        state_level =LEVEL2;
    }
    else if(level == 2)
    {
        state_level = LEVEL3;
    }
    else if(level == 3)
    {
        state_level =SHOP;
    }
    
    else
    {
        cout<<"Level is default: 0"<<endl;
        state_level = LEVEL1;
    }
    cout<<"Loaded level is: "<<state_level<<endl;
    return state_level;
    
}


void Engine::savePlayer()
{
    file_player.open("player.txt", ios::out);
    {
        file_player<<player.rect.getPosition().x<<endl;
        file_player<<player.rect.getPosition().y<<endl;
        file_player<<player.HP<<endl;
        file_player<<player.gold<<endl;
        file_player<<player.current_weapon_int<<endl;
        file_player<<player.attackDamage<<endl;
        file_player<<player.movement_speed<<endl;
        cout<<"Save Player succesfull"<<endl;
        
    }
    file_player.close();
}

void Engine::saveEngine(int level_number)
{
    
    file.open("engine.txt", ios::out);
    {
        file<<level_number;
        cout<<"Level saved is: "<<level_number<<endl;
        cout<<"Save engine succesfull"<<endl;
        
        
    }
    file.close();
    
}

void Engine::save_enemy_wolf()
{
    cout<<"Saving enemies"<<endl;
    file_wolf.open("wolf_live.txt", ios::out);
    {
        counter2 = 0;
       // file_wolf<<EnemyArray.size()<<endl;
        for(iter2 = EnemyArray.begin(); iter2 != EnemyArray.end(); iter2++)
        {
            //file_wolf<<EnemyArray.size();
            file_wolf<<EnemyArray[counter2].alive<<endl;
            counter2++;
        }
        
    }
    file_wolf.close();
}

void Engine::load_enemy_wolf()
{
    int line_number = 1;
    
    file_wolf.open("wolf_live.txt", ios::in);
    {
        if(file_wolf.good()==false)
        {
            cout<<"Cant open wolf.txt"<<endl;;
            return EXIT_FAILURE;
        }
        string line;
        
        
        
        while (getline(file_wolf, line))
        {
            
            switch (line_number)
            {
                case 1:
                    EnemyArray[0].alive = atoi(line.c_str());
                    break;
                case 2:
                    EnemyArray[1].alive =  atoi(line.c_str());
                    break;
                case 3:
                    EnemyArray[2].alive =  atoi(line.c_str());
                    break;
            }
            line_number++;
        }
        
        if(EnemyArray[0].alive == 1)
        {
            EnemyArray[0].alive = true;
            cout<<"true"<<endl;
        }
        else EnemyArray[0].alive = false;
        
        if(EnemyArray[1].alive == 1)
        {
            EnemyArray[1].alive = true;cout<<"true"<<endl;
        }
        else EnemyArray[1].alive = false;
        
        if(EnemyArray[2].alive == 1)
        {
            EnemyArray[2].alive = true;cout<<"true"<<endl;
        }
        else EnemyArray[2].alive = false;
        
    }
    
                    
}

void Engine::destructionAnimation()
{
    //Box destrucion animation
    sf::Time elapsed3 = clock3.getElapsedTime();
    counterBox = 0;
    for(iterBox=BoxArray.begin(); iterBox !=BoxArray.end(); iterBox++)
    {
        if(BoxArray[counterBox].startDestruction==true)
        {
            if(elapsed3.asSeconds()>=0.025)
            {
                BoxArray[counterBox].i++;
                clock3.restart();
            }
            BoxArray[counterBox].destroyAnimation();
            if(BoxArray[counterBox].i==12)
            {
                BoxArray[counterBox].destroy = true;
            }
            else BoxArray[counterBox].destroy = false;
        }
        else{}
        counterBox++;
    }
}

void Engine::clearMap()
{
    WallArray.clear();
    BoxArray.clear();
    CoinArray.clear();
    displayTextArray.clear();
    displayTextBuyArray.clear();
    EnemyArray.clear();
    Fire_TreeArray.clear();
    Bad_TreeArray.clear();
    Walking_TreeArray.clear();
    BulletArray.clear();
    HouseArray.clear();
    DoorArray.clear();
    SignArray.clear();
    cout<<"Vector's array's cleared"<<endl;
}

void Engine::reserve_memory()
{
    
    //reserve memory for vector arrays
    WallArray.reserve(1000);
    BoxArray.reserve(20);
    CoinArray.reserve(20);
    displayTextArray.reserve(20);
    displayTextBuyArray.reserve(20);
    EnemyArray.reserve(20);
    Fire_TreeArray.reserve(20);
    Bad_TreeArray.reserve(10);
    Walking_TreeArray.reserve(10);
    BulletArray.reserve(20);
    HouseArray.reserve(5);
    SignArray.reserve(5);
    cout<<"Memory reserved for arrays"<<endl;
}


void Engine::check_isPlayer_dead(bool game)
{
    if(player.HP<=0)
    {
        cout<<"Player is dead!"<<endl;
        state_level = END;
        game = false;
        isPlayerDead = true;
        
        
    }
   
}



void Engine::drawEngine(bool draw_background, sf::Sprite *sprite_background)
{
    
    /////////////////////////////////// DRAWING ///////////////////////////////////
    if(draw_background==true)
    {
        //draw background
        window->draw(*sprite_background);
    }
    else;
    
    //DRAW WALLS
    counterWalls = 0;
    for(iter5 = WallArray.begin(); iter5!= WallArray.end(); iter5++)
    {
        WallArray[counterWalls].Update();
        window->draw(WallArray[counterWalls].rect);
        window->draw(WallArray[counterWalls].sprite);
        counterWalls++;
    }
    
    //DRAW BOX
    counterBox = 0;
    for(iterBox = BoxArray.begin(); iterBox!= BoxArray.end(); iterBox++)
    {
        BoxArray[counterBox].Update();
        //window->draw(BoxArray[counterBox].rect);
        window->draw(BoxArray[counterBox].sprite);
        counterBox++;
    }
    
    //DRAW DOORS
    counterDoor = 0;
    for(iterDoor = DoorArray.begin(); iterDoor!= DoorArray.end(); iterDoor++)
    {
        // window->draw(DoorArray[counterDoor].rect);
        counterDoor++;
    }
    
    //DRAW TEXT
    counterText = 0;
    for(iter3 = displayTextArray.begin(); iter3!= displayTextArray.end(); iter3++)
    {
        displayTextArray[counterText].Update(); //text moving
        window->draw(displayTextArray[counterText].text);
        counterText++;
    }
    

    
  
    //DRAW BULLETS
    counter1 = 0;
    for(iter = BulletArray.begin(); iter!= BulletArray.end(); iter++)
    {
        BulletArray[counter1].Update(); //bullets moving
        window->draw(BulletArray[counter1].rect);
        window->draw(BulletArray[counter1].sprite);
        counter1++;
    }
    
    //DRAW BULLETS STAR
    counter_bullet_star = 0;
    for(iter_bullet_Star = Bullet_StarArray.begin(); iter_bullet_Star!= Bullet_StarArray.end(); iter_bullet_Star++)
    {
        Bullet_StarArray[counter_bullet_star].Update(); //bullets moving
        window->draw(Bullet_StarArray[counter_bullet_star].rect);
        window->draw(Bullet_StarArray[counter_bullet_star].sprite);
        counter_bullet_star++;
    }
    
    
    
    
    //DRAW ENEMY BULLETS
    counter_enemy_bullet = 0;
    for(iter_enemy_bullet = EnemyBulletArray.begin(); iter_enemy_bullet!= EnemyBulletArray.end(); iter_enemy_bullet++)
    {
        EnemyBulletArray[counter_enemy_bullet].Update(); //bullets moving
        window->draw(EnemyBulletArray[counter_enemy_bullet].rect);
        window->draw(EnemyBulletArray[counter_enemy_bullet].sprite);
        counter_enemy_bullet++;
    }
    
    
    
    
    //DRAW HOUSE
    counterHouse = 0;
    for(iterHouse = HouseArray.begin(); iterHouse!= HouseArray.end(); iterHouse++)
    {
        HouseArray[counterHouse].Update(); //coin updates animation
        //window->draw(HouseArray[counterHouse].rect);
        window->draw(HouseArray[counterHouse].sprite);
        counterHouse++;
    }
    
    //DRAW COINS
    counterCoins = 0;
    for(iter4 = CoinArray.begin(); iter4!= CoinArray.end(); iter4++)
    {
        CoinArray[counterCoins].Update(); //coin updates animation
        //window->draw(CoinArray[counterCoins].rect);
        window->draw(CoinArray[counterCoins].sprite);
        counterCoins++;
    }
    
    //DRAW ENEMIES WOLF
    counter2 = 0;
    for(iter2 = EnemyArray.begin(); iter2!= EnemyArray.end(); iter2++)
    {
        EnemyArray[counter2].Update();
        EnemyArray[counter2].Movement_Wolf();
        // window.draw(EnemyArray[counter2].rect);
        window->draw(EnemyArray[counter2].sprite);
        counter2++;
    }
    
    //DRAW ENEMIES FIRE TREE
    counter_fire_tree = 0;
    for(iter_fire_tree = Fire_TreeArray.begin(); iter_fire_tree!= Fire_TreeArray.end(); iter_fire_tree++)
    {
        Fire_TreeArray[counter_fire_tree].Update();
       // window->draw(Fire_TreeArray[counter_fire_tree].rect);
        window->draw(Fire_TreeArray[counter_fire_tree].sprite);
        counter_fire_tree++;
    }
    
    //DRAW ENEMIES BAD TREE
    counter_bad_tree = 0;
    for(iter_bad_tree = Bad_TreeArray.begin(); iter_bad_tree!= Bad_TreeArray.end(); iter_bad_tree++)
    {
        Bad_TreeArray[counter_bad_tree].Update();
        // window->draw(Fire_TreeArray[counter_fire_tree].rect);
        window->draw(Bad_TreeArray[counter_bad_tree].sprite);
        counter_bad_tree++;
    }
    
    //DRAW ENEMIES WALKING TREE
    counter_walking_tree = 0;
    for(iter_walking_tree = Walking_TreeArray.begin(); iter_walking_tree!= Walking_TreeArray.end(); iter_walking_tree++)
    {
        Walking_TreeArray[counter_walking_tree].Update();
        Walking_TreeArray[counter_walking_tree].Movement();
        // window->draw(Fire_TreeArray[counter_fire_tree].rect);
        window->draw(Walking_TreeArray[counter_walking_tree].sprite);
        counter_walking_tree++;
    }
    
    //DRAW PLAYER
    //window->draw(player.rect);
    window->draw(player.sprite);
    
    
    //DRAW SIGNS
    counterSign = 0;
    for(iterSign = SignArray.begin(); iterSign!= SignArray.end(); iterSign++)
    {
        SignArray[counterSign].Update();
        //window->draw(SignArray[counterSign].rect);
        window->draw(SignArray[counterSign].sprite);
        counterSign++;
    }
    
    //DRAW TEXTS
    //COINS
    moneyText.text.setString("Monety: "+ to_string(player.gold));
    window->draw(moneyText.text);
    //PLAYER LIFE
    playerLifeText.text.setString("Zdrowie: "+ to_string(player.HP));
    window->draw(playerLifeText.text);
    //PLAYER WEAPON
    playerWeapon.text.setString("Bron: "+ player.current_weapon);
    window->draw(playerWeapon.text);
    //ATTACK-DAMAGE
    attack_damage.text.setString("ATAK: "+ to_string(player.attackDamage));
    window->draw(attack_damage.text);
    
    
}


void Engine::draw_Shop_Items()
{
    //fire gun
    fire_gun.Update();
    window->draw(fire_gun.sprite);
    //freeze gun
    freeze_gun.Update();
    window->draw(freeze_gun.sprite);
    //star gun
    star_gun.Update();
    window->draw(star_gun.sprite);
    //poskramiacz
    poskramiacz.Update();
    window->draw(poskramiacz.sprite);
    //ring
    ring.Update();
    window->draw(ring.sprite);
    //hp potion
    hp_potion.Update();
    window->draw(hp_potion.sprite);
    //texts
    window->draw(price_poskramiacz.text);
    window->draw(price_hp_potion.text);
    window->draw(price_freeze_gun.text);
    window->draw(price_star_gun.text);
    window->draw(price_fire_gun.text);
    window->draw(price_ring.text);
    //doors
    exit_shop_door.Update();
    window->draw(exit_shop_door.sprite);
    //DRAW TEXT BUY
    counterText_buy = 0;
    for(iter_buy = displayTextBuyArray.begin(); iter_buy!= displayTextBuyArray.end(); iter_buy++)
    {
        displayTextBuyArray[counterText_buy].Update(); //text moving
        window->draw(displayTextBuyArray[counterText_buy].text);
        counterText_buy++;
    }
    
}



void Engine::createLevelEnd(int roomSize, int roomStartPositionX, int roomStartPositionY, sf::Texture *texture)
{
    
    
    wall.sprite.setTexture(*texture);
    
    
    wall.sprite.setTextureRect(sf::IntRect(0,0,50,50));
    //horizontal wall
    int counterW = 0;
    while(counterW<roomSize)
    {
        wall.rect.setPosition(50*counterW + roomStartPositionX, roomStartPositionY);
        WallArray.push_back(wall);
        
        
        counterW++;
    }
    
    //horizontal wall
    counterW = 0;
    while(counterW<roomSize)
    {
        wall.rect.setPosition(50*counterW + roomStartPositionX, 50*roomSize+roomStartPositionY);
        WallArray.push_back(wall);
        
        
        counterW++;
    }
    
    //vertical wall
    counterW=0;
    while(counterW<roomSize)
    {
        wall.rect.setPosition(roomStartPositionX, 50*counterW + roomStartPositionY);
        WallArray.push_back(wall);
        
        
        counterW++;
    }
    
    
    //vertical wall
    counterW=0;
    while(counterW<roomSize+1)
    {
        
        wall.rect.setPosition(50*roomSize+roomStartPositionX, 50*counterW + roomStartPositionY);
        WallArray.push_back(wall);
        
        
        counterW++;
    }
    
    //cout<<"Level end created"<<endl;
   // cout<<"Number created walls = "<<WallArray.size()<<endl;
    
}



void Engine::createRoom(int roomSize, int roomStartPositionX, int roomStartPositionY, int doorPosition, int numberEnemies,sf::Texture *texture_wall, sf::Texture *texture_enemy)
{
    
    
    

    wall.sprite.setTexture(*texture_wall);
    wall.sprite.setTextureRect(sf::IntRect(0,50,50,50));
    
    

    enemy_wolf.sprite.setTexture(*texture_enemy);
    enemy_wolf.sprite.setTextureRect(sf::IntRect(110,0,56,80));
    
    //create enemies
    for(int i=0; i<numberEnemies; i++)
    {
        enemy_wolf.rect.setPosition(roomStartPositionX+roomSize*50/2+generateRandom(400),roomStartPositionY+roomSize*50/2+generateRandom(400));
        EnemyArray.push_back(enemy_wolf);
    }
    
    //cout<<"Enemy created. Number created enemies = "<<EnemyArray.size()<<endl;
    
    
    //horizontal wall
    int counterW = 0;
    while(counterW<roomSize)
    {
        wall.rect.setPosition(50*counterW + roomStartPositionX, roomStartPositionY);
        WallArray.push_back(wall);
        
        
        counterW++;
    }
    
    //horizontal wall
    counterW = 0;
    while(counterW<roomSize)
    {
        wall.rect.setPosition(50*counterW + roomStartPositionX, 50*roomSize+roomStartPositionY);
        WallArray.push_back(wall);
        
        
        counterW++;
    }
    
    //vertical wall
    counterW=0;
    while(counterW<roomSize)
    {
        wall.rect.setPosition(roomStartPositionX, 50*counterW + roomStartPositionY);
        WallArray.push_back(wall);
        
        
        counterW++;
    }
    
    
    //vertical wall
    counterW=0;
    while(counterW<roomSize+1)
    {
        if(counterW!=doorPosition-1 && counterW!=doorPosition && counterW!=doorPosition+1)
        {
            wall.rect.setPosition(50*roomSize+roomStartPositionX, 50*counterW + roomStartPositionY);
            WallArray.push_back(wall);
        }
        
        counterW++;
    }
    
    //cout<<"Wall created. Number created walls = "<<WallArray.size()<<endl;
    //cout<<"Room created"<<endl;
    
    
}


void Engine::createRoom_with_2_doors(int roomSize, int roomStartPositionX, int roomStartPositionY, int door1Position,int door2Position, sf::Texture *texture_wall)
{
    
    wall.sprite.setTexture(*texture_wall);
    wall.sprite.setTextureRect(sf::IntRect(0,50,50,50));
    
    //horizontal wall
    int counterW = 0;
    while(counterW<roomSize)
    {
        wall.rect.setPosition(50*counterW + roomStartPositionX, roomStartPositionY);
        WallArray.push_back(wall);
        
        
        counterW++;
    }
    
    //horizontal wall
    counterW = 0;
    while(counterW<roomSize)
    {
        wall.rect.setPosition(50*counterW + roomStartPositionX, 50*roomSize+roomStartPositionY);
        WallArray.push_back(wall);
        
        
        counterW++;
    }
    
    //vertical wall
    counterW=0;
    while(counterW<roomSize+1)
    {
        if(counterW!=door1Position-1 && counterW!=door1Position && counterW!=door1Position+1)
        {
        
        wall.rect.setPosition(roomStartPositionX, 50*counterW + roomStartPositionY);
        WallArray.push_back(wall);
        }
        
        
        counterW++;
    }
    
    
    //vertical wall
    counterW=0;
    while(counterW<roomSize+1)
    {
        if(counterW!=door2Position-1 && counterW!=door2Position && counterW!=door2Position+1)
        {
            wall.rect.setPosition(50*roomSize+roomStartPositionX, 50*counterW + roomStartPositionY);
            WallArray.push_back(wall);
        }
        
        counterW++;
    }
}


void Engine::create_horizontal_wall( int roomStartPositionX, int roomStartPositionY, int roomSize, sf::Texture *texture_wall)
{
    wall.sprite.setTexture(*texture_wall);
    wall.sprite.setTextureRect(sf::IntRect(0,50,50,50));
    
    //horizontal wall
    int counterW = 0;
    while(counterW<roomSize)
    {
        wall.rect.setPosition(50*counterW + roomStartPositionX, roomStartPositionY);
        WallArray.push_back(wall);
        counterW++;
    }
    
 
}

void Engine::create_vertical_wall( int roomStartPositionX, int roomStartPositionY, int roomSize, sf::Texture *texture_wall)
{
    wall.sprite.setTexture(*texture_wall);
    wall.sprite.setTextureRect(sf::IntRect(0,50,50,50));
    
    //vertical wall
    int counterW=0;
    while(counterW<roomSize+1)
    {
        wall.rect.setPosition(roomStartPositionX, 50*counterW + roomStartPositionY);
        WallArray.push_back(wall);
        counterW++;
    }
    
    
}

void Engine::create_house(int PositionX, int PositionY, sf::Texture *texture)
{

    //set sprites
    
    int width = 318;
    int height = 366;
    house.sprite.setTexture(*texture);
    texture->setSmooth(true);
    house.sprite.setTextureRect(sf::IntRect(0,0,width,height));
    
    house.rect.setPosition(PositionX, PositionY);
    HouseArray.push_back(house);
   // cout<<"House created on Positions: (X: "<<PositionX<<", Y: "<<PositionY<<")"<<endl;
    
    door1.rect.setPosition(PositionX+width/2-10, PositionY+height);
    DoorArray.push_back(door1);
    //cout<<"Doors created on Positions: (X: "<<PositionX+width/2-10<<", Y: "<<PositionY+height<<")"<<endl;
    
    
}



void Engine::createBackground(int choose,int PositionX, int PositionY, sf::Texture *texture,  int transparency)
{
    
    if(choose == 1) // grass
    {
    
        //set sprites
    
        spriteGround1.setTexture(textureGround1);
        textureGround1.setSmooth(true);
        spriteGround1.setTextureRect(sf::IntRect(0,0,4120,3912));
        spriteGround1.setPosition(PositionX, PositionY);
        spriteGround1.setColor(sf::Color(255,128,128,transparency));
        
        cout<<"Background created with file: background_grass.png"<<endl;
        
    }
    else if(choose == 2) //shop
    {
    
        //set sprite shop
        texture_shop.setSmooth(true);
        sprite_shop.setTexture(texture_shop);
        sprite_shop.setPosition(PositionX, PositionY);
        sprite_shop.setTextureRect(sf::IntRect(0,0,800,800));
        cout<<"Background created with file: Shop_background.png"<<endl;
    }
        
    else
    {
        cout<<"Error during creating background!"<<endl;
        return EXIT_FAILURE;
    }
       
}

void Engine::create_box(int PositionX, int PositionY, sf::Texture *texture)
{
    
    //set sprites
    box.sprite.setTexture(*texture);
    texture->setSmooth(true);
    box.sprite.setTextureRect(sf::IntRect(0,0,50,48));
    
    //create box
    box.rect.setPosition(PositionX, PositionY);
    BoxArray.push_back(box);
    //cout<<"Box created in position (X: "<<PositionX<<", Y: "<<PositionY<<")"<<endl;
}

void Engine::createSign(int PositionX, int PositionY, sf::Texture *texture)
{
    sign.sprite.setTexture(*texture);
    sign.rect.setPosition(PositionX, PositionY);
    SignArray.push_back(sign);

}

void Engine::create_Fire_Tree(int PositionX, int PositionY, sf::Texture *texture)
{
    fire_tree.sprite.setTexture(*texture);
    fire_tree.rect.setPosition(PositionX, PositionY);
    Fire_TreeArray.push_back(fire_tree);

}

void Engine::create_Bad_Tree(int PositionX, int PositionY, sf::Texture *texture)
{
    bad_tree.sprite.setTexture(*texture);
    bad_tree.rect.setPosition(PositionX, PositionY);
    Bad_TreeArray.push_back(bad_tree);
    
}
void Engine::create_wolf(int PositionX, int PositionY, sf::Texture *texture)
{
    enemy_wolf.sprite.setTexture(*texture);
    enemy_wolf.rect.setPosition(PositionX, PositionY);
    EnemyArray.push_back(enemy_wolf);
    
}

void Engine::create_walking_tree(int PositionX, int PositionY, sf::Texture *texture)
{
    walking_tree.sprite.setTexture(*texture);
    walking_tree.rect.setPosition(PositionX, PositionY);
    Walking_TreeArray.push_back(walking_tree);
    
}


void Engine::BuyItems()
{
    sf::Time elapsed_buy_items = clock_buy_items.getElapsedTime();
    //set text parameters
    display_text_buy.text.setCharacterSize(40);
    display_text_buy.text.setFillColor(sf::Color::Black);
    display_text_buy.text.setFont(display_text_buy.font_coco_gothic);
    
    cout<<"can buy :"<<can_buy_poskramiacz<<endl;
    if(can_buy_poskramiacz == true)
    {
        
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::B))
        {
            if(elapsed_buy_items.asSeconds()>=0.8)
            {
            
                if(player.gold>=poskramiacz.price)
                {
                    player.gold = player.gold - poskramiacz.price;
                    player.current_weapon = "Poskramiacz";
                    player.attackDamage = poskramiacz.damage;
                    player.current_weapon_int = 2;
                    cout<<"Bought a new weapon: "<<player.current_weapon<<endl;
                    //Text display
                    display_text_buy.text.setString("Kupiono nowa bron!");
                    //Center text and set him over enemy
                    display_text_buy.text.setPosition(player.rect.getPosition().x-50, player.rect.getPosition().y+player.rect.getSize().y/2);
                    displayTextBuyArray.push_back(display_text_buy);
                
                }
                else if(player.gold-poskramiacz.price<0)
                {
                    cout<<"zbyt malo zlota"<<endl;
                    //Text display
                    display_text_buy.text.setString("Zbyt malo zlota!");
                    //Center text and set him over enemy
                    display_text_buy.text.setPosition(player.rect.getPosition().x-50, player.rect.getPosition().y+player.rect.getSize().y/2);
                    displayTextBuyArray.push_back(display_text_buy);
                }
            clock_buy_items.restart();
            }
            
        }
   
    }
    else;
  
    
    if(can_buy_hp_potion==true)
    {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::B))
        {
            if(elapsed_buy_items.asSeconds()>=0.8)
            {
                
                if(player.gold>=hp_potion.price)
                {
                    player.gold = player.gold - hp_potion.price;
                    player.HP = player.HP +1;
                    
                    cout<<"Bought a hp potion"<<endl;
                    //Text display
                    display_text_buy.text.setString("IMiRon zostal uleczony!");
                    //Center text and set him over enemy
                    display_text_buy.text.setPosition(player.rect.getPosition().x-50, player.rect.getPosition().y+player.rect.getSize().y/2);
                    displayTextBuyArray.push_back(display_text_buy);
                    
                }
                else if(player.gold-hp_potion.price <0)
                {
                    cout<<"zbyt malo zlota"<<endl;
                    //Text display
                    display_text_buy.text.setString("Zbyt malo zlota!");
                    //Center text and set him over enemy
                    display_text_buy.text.setPosition(player.rect.getPosition().x-50, player.rect.getPosition().y+player.rect.getSize().y/2);
                    displayTextBuyArray.push_back(display_text_buy);
                }
                clock_buy_items.restart();
            }
            
        }
    }
    else;
    
    if(can_buy_freeze_gun==true)
    {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::B))
        {
            if(elapsed_buy_items.asSeconds()>=0.8)
            {
                
                if(player.gold>=freeze_gun.price)
                {
                    player.gold = player.gold - freeze_gun.price;
                    player.current_weapon = "Lodowa zamiec";
                    player.current_weapon_int = 1;
                    player.attackDamage = freeze_gun.damage;
                    cout<<"Bought a new weapon: "<<player.current_weapon<<endl;
                    //Text display
                    display_text_buy.text.setString("Kupiono nowa bron!");
                    //Center text and set him over enemy
                    display_text_buy.text.setPosition(player.rect.getPosition().x-50, player.rect.getPosition().y+player.rect.getSize().y/2);
                    displayTextBuyArray.push_back(display_text_buy);
                    
                }
                else if(player.gold-freeze_gun.price<0)
                {
                    cout<<"zbyt malo zlota"<<endl;
                    //Text display
                    display_text_buy.text.setString("Zbyt malo zlota!");
                    //Center text and set him over enemy
                    display_text_buy.text.setPosition(player.rect.getPosition().x-50, player.rect.getPosition().y+player.rect.getSize().y/2);
                    displayTextBuyArray.push_back(display_text_buy);
                }
                clock_buy_items.restart();
            }
            
        }
    }
    else;
    
    if(can_buy_star_gun==true)
    {
        
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::B))
        {
            if(elapsed_buy_items.asSeconds()>=0.8)
            {
                
                if(player.gold>=star_gun.price)
                {
                    player.gold = player.gold - star_gun.price;
                    player.current_weapon = "Gwiezdna rozdzka";
                    player.attackDamage = star_gun.damage;
                    player.current_weapon_int = 4;
                    cout<<"Bought a new weapon: "<<player.current_weapon<<endl;
                    //Text display
                    display_text_buy.text.setString("Kupiono nowa bron!");
                    //Center text and set him over enemy
                    display_text_buy.text.setPosition(player.rect.getPosition().x-50, player.rect.getPosition().y+player.rect.getSize().y/2);
                    displayTextBuyArray.push_back(display_text_buy);
                    
                }
                else if(player.gold-star_gun.price<0)
                {
                    cout<<"zbyt malo zlota"<<endl;
                    //Text display
                    display_text_buy.text.setString("Zbyt malo zlota!");
                    //Center text and set him over enemy
                    display_text_buy.text.setPosition(player.rect.getPosition().x-50, player.rect.getPosition().y+player.rect.getSize().y/2);
                    displayTextBuyArray.push_back(display_text_buy);
                }
                clock_buy_items.restart();
            }
            
        }
 
    }
    else;
    
    if(can_buy_ring==true)
    {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::B))
        {
            if(elapsed_buy_items.asSeconds()>=0.8)
            {
                
                if(player.gold>=ring.price)
                {
                    player.gold = player.gold - ring.price;
                    cout<<"Bought a ring"<<endl;
                    //Text display
                    display_text_buy.text.setString("Kupiono Pierscien Szybkosci!");
                    if(player.movement_speed<8)
                    {
                    player.movement_speed = player.movement_speed + 1;
                    }
                    else;
                    //Center text and set him over enemy
                    display_text_buy.text.setPosition(player.rect.getPosition().x-50, player.rect.getPosition().y+player.rect.getSize().y/2);
                    displayTextBuyArray.push_back(display_text_buy);
                    
                }
                else if(player.gold-ring.price<0)
                {
                    cout<<"zbyt malo zlota"<<endl;
                    //Text display
                    display_text_buy.text.setString("Zbyt malo zlota!");
                    //Center text and set him over enemy
                    display_text_buy.text.setPosition(player.rect.getPosition().x-50, player.rect.getPosition().y+player.rect.getSize().y/2);
                    displayTextBuyArray.push_back(display_text_buy);
                }
                clock_buy_items.restart();
            }
            
        }
    }
    else;
    
    if(can_buy_fire_gun==true)
    {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::B))
        {
            if(elapsed_buy_items.asSeconds()>=0.8)
            {
                
                if(player.gold>=fire_gun.price)
                {
                    player.gold = player.gold - fire_gun.price;
                    player.current_weapon = "Ognisty jezyk";
                    player.current_weapon_int = 3;
                    player.attackDamage = fire_gun.damage;
                    cout<<"Bought a new weapon: "<<player.current_weapon<<endl;
                    //Text display
                    display_text_buy.text.setString("Kupiono nowa bron!");
                    //Center text and set him over enemy
                    display_text_buy.text.setPosition(player.rect.getPosition().x-50, player.rect.getPosition().y+player.rect.getSize().y/2);
                    displayTextBuyArray.push_back(display_text_buy);
                    
                }
                else if(player.gold-fire_gun.price<0)
                {
                    cout<<"zbyt malo zlota"<<endl;
                    //Text display
                    display_text_buy.text.setString("Zbyt malo zlota!");
                    //Center text and set him over enemy
                    display_text_buy.text.setPosition(player.rect.getPosition().x-50, player.rect.getPosition().y+player.rect.getSize().y/2);
                    displayTextBuyArray.push_back(display_text_buy);
                }
                clock_buy_items.restart();
            }
            
        }
    }
    else;
}


void Engine::level_1()
{
    {
        
        
        cout<<"LEVEL1"<<endl;
        clearMap();
        reserve_memory();
        
        //load player parameters
        loadPlayer(&player);
       //load_enemy_wolf();
        //check if player came back from room
        if(fromShop==true)
        {
            player.rect.setPosition(3000, 1500);
            cout<<"Player came back from the shop"<<endl;
        }
        else if(fromLevel2==true)
        {
            player.rect.setPosition(1000, 1070);
        }
        else;
        fromLevel2=false;
        fromShop=false;
        //setting view
        sf::View view1 (sf::Vector2f(200, 200), sf::Vector2f(300, 200));
        view1.setSize(sf::Vector2f(window->getSize().x, window->getSize().y ));
        view1.setCenter(sf::Vector2f(view1.getSize().x/2,view1.getSize().y/2));
        window->setView(view1);
        //////create level
        createLevelEnd(50, 750, 640, &texture_wall);
        //(int roomSize, int roomStartPositionX, int roomStartPositionY, int doorPosition, int numberEnemies)
        //createRoom(20,1400,1000,10,3, &texture_wall, &texture_wolf);
        createRoom_with_2_doors(20, 1400, 1000, 10, 10, &texture_wall);

        //boxes
        create_box(1700, 1300, &texture_box);
        create_box(1700, 1660, &texture_box);
        create_box(2000, 1300, &texture_box);
        create_box(2000, 1660, &texture_box);
        
       
        //house
        create_house(2860, 1078, &texture_house);
        //sign
        createSign(800, 1070, &texture_sign_left);
        //create background
        createBackground(1,0,0, &textureGround1, 255);
        //set music background
        music.music_level1.play();
        music.music_level1.setVolume(50);
        music.music_level1.setLoop(true);
        //game loop
        while(state_level==LEVEL1)
        {
            
            //keyboard events
            KeyboardEvents(&canShowPredatorDistance ,distance_predator);
            //clear window
            window->clear();
            //collisions
            Collisions();
            
            check_isPlayer_dead(game);
            //checking distance beetwen predator enemy and player
            check_IsPredatorNear(distance_predator);
            //destruction animation
            destructionAnimation();
            //delete objects
            DeleteObjects();
            //EDITOR
            Editor();
            //PLAYER MOVE AND UPDATE POSITION WITH RECTANGLE
            player.Movement();
            player.Update();
            //PLAYER VIEW AND TEXT
            window->setView(view1);
            
            view1.setCenter(player.rect.getPosition());
            //drawing
            window->clear();
            //drawBackground();
            drawEngine(true, &spriteGround1);
            //set display text position
            moneyText.text.setPosition(player.rect.getPosition().x-window->getSize().x/2, player.rect.getPosition().y-window->getSize().y/2);
            playerLifeText.text.setPosition(player.rect.getPosition().x-window->getSize().x/2, player.rect.getPosition().y-window->getSize().y/2+30);
            playerWeapon.text.setPosition(player.rect.getPosition().x-window->getSize().x/2, player.rect.getPosition().y-window->getSize().y/2+65);
            attack_damage.text.setPosition(player.rect.getPosition().x-window->getSize().x/2, player.rect.getPosition().y-window->getSize().y/2+100);
            
        
            /////////////////////////////////// DISPLAY ///////////////////////////////////
            window->display();
            //check if player can go to next room
            if(door1.can_go_next==true)
            {
                state_level = SHOP;
                cout<<"Go to shop!"<<endl;
            }
            
            for(iterSign = SignArray.begin(); iterSign!= SignArray.end(); iterSign++)
            {
                if(SignArray[0].can_go_next==true)
                {
                    state_level = LEVEL2;
                    cout<<"Go to level2!"<<endl;
                    fromLevel1 = true;
                }
                else;
            }
            
            

        }
        
        saveEngine(0);
        music.music_level1.stop();
        savePlayer();
       //file_wolf<<EnemyArray.size(); save_enemy_wolf();
    }
}


void Engine::level_2()
{
    {
        
        

        clearMap();
        cout<<"LEVEL2"<<endl;
        reserve_memory();
        //load player parameters
        loadPlayer(&player);
        
        if(fromLevel1==true)
        {
            player.rect.setPosition(3200, 980);
        }
        fromLevel1 = false;
        
        if(fromLevel3==true)
        {
            player.rect.setPosition(1583, 2340);
        }
        fromLevel3 = false;

        //setting view
        sf::View view1 (sf::Vector2f(200, 200), sf::Vector2f(300, 200));
        view1.setSize(sf::Vector2f(window->getSize().x, window->getSize().y ));
        view1.setCenter(sf::Vector2f(view1.getSize().x/2,view1.getSize().y/2));
        window->setView(view1);
        //////create level
        createLevelEnd(40, 1450, 640, &texture_wall);
        //create sign right
        createSign(3300, 980, &texture_sign_right);
        createSign(1583, 2480, &texture_sign_down);
        
        createBackground(1, 0, 0, &textureGround1, 150);
        //level create
        create_horizontal_wall(1850, 1395, 32, &texture_wall);
        create_horizontal_wall(1500, 1730, 32, &texture_wall);
        create_vertical_wall(3050, 1780, 10, &texture_wall);
        createRoom_with_2_doors(17, 2200, 1730, 3, 14, &texture_wall);
        //create fire trees
       // create_Fire_Tree(2350, 2350, &texture_fire_tree);
       // create_Fire_Tree(2450, 2100, &texture_fire_tree);
        
        create_Fire_Tree(2600, 1900, &texture_fire_tree);
        create_Fire_Tree(2600, 2300, &texture_fire_tree);
        create_Fire_Tree(2400, 1000, &texture_fire_tree);
        
        create_walking_tree(2300, 1000, &texture_walking_tree);
        create_walking_tree(2400, 1000, &texture_walking_tree);
        create_walking_tree(2400, 1000, &texture_walking_tree);
        create_walking_tree(2400, 1000, &texture_walking_tree);
        
       create_walking_tree(2156, 1564, &texture_walking_tree);
       create_walking_tree(2940, 1564, &texture_walking_tree);
       create_walking_tree(3244, 2140, &texture_walking_tree);
       create_walking_tree(2876, 2172, &texture_walking_tree);
        create_walking_tree(2412, 2172, &texture_walking_tree);
        create_walking_tree(2044, 2092, &texture_walking_tree);
        create_walking_tree(1724, 2092, &texture_walking_tree);
        create_walking_tree(1884, 2396, &texture_walking_tree);
        
    

        //set music background
        music.scary_music.play();
        music.scary_music.setLoop(true);
        //game loop
        while(state_level==LEVEL2)
        {
      
            //keyboard events
            KeyboardEvents(&canShowPredatorDistance ,distance_predator);
            //clear window
            window->clear();
            //collisions
            Collisions();
            Aggro_walking_tree();
            check_isPlayer_dead(game);
            Fire_Tree_shooting();
            //checking distance beetwen predator enemy and player
            check_IsPredatorNear(distance_predator);
            //destruction animation
            destructionAnimation();
            //delete objects
            DeleteObjects();
            //EDITOR
            Editor();
            //PLAYER MOVE AND UPDATE POSITION WITH RECTANGLE
            player.Movement();
            player.Update();
            //PLAYER VIEW AND TEXT
            window->setView(view1);
            view1.setCenter(player.rect.getPosition());
            
            //drawing
            window->clear();
            //drawBackground();
            drawEngine(true, &spriteGround1);
            //set display text position
            moneyText.text.setPosition(player.rect.getPosition().x-window->getSize().x/2, player.rect.getPosition().y-window->getSize().y/2);
            playerLifeText.text.setPosition(player.rect.getPosition().x-window->getSize().x/2, player.rect.getPosition().y-window->getSize().y/2+30);
            playerWeapon.text.setPosition(player.rect.getPosition().x-window->getSize().x/2, player.rect.getPosition().y-window->getSize().y/2+60);
            attack_damage.text.setPosition(player.rect.getPosition().x-window->getSize().x/2, player.rect.getPosition().y-window->getSize().y/2+100);
            /////////////////////////////////// DISPLAY ///////////////////////////////////
            window->display();
            
            for(iterSign = SignArray.begin(); iterSign!= SignArray.end(); iterSign++)
            {
                if(SignArray[0].can_go_next==true)
                {
                    state_level = LEVEL1;
                    cout<<"Go to level1!"<<endl;
                    fromLevel2 = true;
                }
                if(SignArray[1].can_go_next==true)
                {
                    state_level = LEVEL3;
                    cout<<"Go to level3!"<<endl;
                    fromLevel2 = true;
                }
                else;
            }
            

            
        }
        
        saveEngine(1);
        music.scary_music.stop();
        savePlayer();
       
        
        
    }
}

void Engine::level_3()
{
    
        
        
        
        clearMap();
        cout<<"LEVEL3"<<endl;
        reserve_memory();
        //load player parameters
        loadPlayer(&player);
        
        if(fromLevel2==true)
        {
            player.rect.setPosition(3000, 980);
        }
        fromLevel2 = false;
        
        //setting view
        sf::View view1 (sf::Vector2f(200, 200), sf::Vector2f(300, 200));
        view1.setSize(sf::Vector2f(window->getSize().x, window->getSize().y ));
        view1.setCenter(sf::Vector2f(view1.getSize().x/2,view1.getSize().y/2));
        window->setView(view1);
        //////create level
        createLevelEnd(40, 1450, 640, &texture_wall);
        //create sign right
        createSign(3300, 980, &texture_sign_right);
    
    

    
    
        createBackground(1, 0, 0, &textureGround1, 150);
    
    
 
    

        
        
        //set music background
        music.music_level3.play();
    music.music_level3.setVolume(50);
        music.music_level3.setLoop(true);
        //game loop
        while(state_level==LEVEL3)
        {
            //spawn wolfs
            if(EnemyArray.size()<=25)
            {
                create_wolf(2440, 1764, &texture_wolf);
            }
            Aggro_wolf();
            //keyboard events
            KeyboardEvents(&canShowPredatorDistance ,distance_predator);
            //clear window
            window->clear();
            //collisions
            Collisions();
            Aggro_walking_tree();
            check_isPlayer_dead(game);
            Fire_Tree_shooting();
            //checking distance beetwen predator enemy and player
            check_IsPredatorNear(distance_predator);
            //destruction animation
            destructionAnimation();
            //delete objects
            DeleteObjects();
            //EDITOR
            Editor();
            //PLAYER MOVE AND UPDATE POSITION WITH RECTANGLE
            player.Movement();
            player.Update();
            //PLAYER VIEW AND TEXT
            window->setView(view1);
            view1.setCenter(player.rect.getPosition());
            
            //drawing
            window->clear();
            //drawBackground();
            drawEngine(true, &spriteGround1);
            //set display text position
            moneyText.text.setPosition(player.rect.getPosition().x-window->getSize().x/2, player.rect.getPosition().y-window->getSize().y/2);
            playerLifeText.text.setPosition(player.rect.getPosition().x-window->getSize().x/2, player.rect.getPosition().y-window->getSize().y/2+30);
            playerWeapon.text.setPosition(player.rect.getPosition().x-window->getSize().x/2, player.rect.getPosition().y-window->getSize().y/2+60);
            attack_damage.text.setPosition(player.rect.getPosition().x-window->getSize().x/2, player.rect.getPosition().y-window->getSize().y/2+100);
            /////////////////////////////////// DISPLAY ///////////////////////////////////
            window->display();
            
            for(iterSign = SignArray.begin(); iterSign!= SignArray.end(); iterSign++)
            {
                if(SignArray[0].can_go_next==true)
                {
                    state_level = LEVEL2;
                    cout<<"Go to level2!"<<endl;
                    fromLevel3 = true;
                }
                else;
            }
            
            
            
        }
        
        saveEngine(2);
        music.music_level3.stop();
        savePlayer();
        
        
        
    

}

void Engine::shop()
{
    
    {
        
        
        clearMap();
        cout<<"Shop"<<endl;
        reserve_memory();
        //load player parameters
        loadPlayer(&player);
        player.rect.setPosition(420, 640);
        //setting text position on the screen
        moneyText.text.setPosition(0, 0);
        moneyText.text.setFont(moneyText.font_mr_otis);
        playerLifeText.text.setPosition(0, 55);
        playerLifeText.text.setFont(playerLifeText.font_mr_otis);
        //setting view
        sf::View view1 (sf::Vector2f(200, 200), sf::Vector2f(300, 200));
        view1.setSize(sf::Vector2f(window->getSize().x, window->getSize().y ));
        view1.setCenter(sf::Vector2f(view1.getSize().x/2,view1.getSize().y/2));
        window->setView(view1);
    
        //load door texture

        if(!exit_shop_door.texture.loadFromFile(resourcePath()+"exit_doors.png"))
        {
            cout<<"Cant load exit_doors.png!"<<endl;
            return EXIT_FAILURE;
        }
        //set sprite
        exit_shop_door.texture.setSmooth(true);
        exit_shop_door.sprite.setTexture(exit_shop_door.texture);
        exit_shop_door.sprite.setTextureRect(sf::IntRect(0,0,60,90));
        exit_shop_door.rect.setPosition(420, 760);
        
        

        
        //////create level
        createLevelEnd(16, 0, 0, &texture_wall);
        createBackground(2, 0, 0, &texture_shop,255);
        //set items
        poskramiacz.rect.setPosition(180, 180);
        star_gun.rect.setPosition(180, 390);
        fire_gun.rect.setPosition(180, 590);
        hp_potion.rect.setPosition(630, 180);
        ring.rect.setPosition(630, 390);
        freeze_gun.rect.setPosition(630, 590);
        
        int text_size = 20;
        
        //POSKRAMIACZ
        price_poskramiacz.text.setString("Poskramiacz: "+ to_string(poskramiacz.price));
        price_poskramiacz.text.setPosition(poskramiacz.rect.getPosition().x-60, poskramiacz.rect.getPosition().y-50);
        price_poskramiacz.text.setFont(price_poskramiacz.font_mr_otis);
        price_poskramiacz.text.setCharacterSize(text_size);
        
        //FIRE GUN
        price_fire_gun.text.setString("Ognisty jezyk: "+ to_string(fire_gun.price));
        price_fire_gun.text.setPosition(fire_gun.rect.getPosition().x-100, fire_gun.rect.getPosition().y-50);
        price_fire_gun.text.setFont(price_fire_gun.font_mr_otis);
        price_fire_gun.text.setCharacterSize(text_size);
        
        
        //RING
        price_ring.text.setString("Pierscien szybkosci: "+ to_string(ring.price));
        price_ring.text.setPosition(ring.rect.getPosition().x-170, ring.rect.getPosition().y-50);
        price_ring.text.setFont(price_ring.font_mr_otis);
        price_ring.text.setCharacterSize(text_size);
        
        
        //STAR GUN
        price_star_gun.text.setString("Gwiezdna rozdzka: "+ to_string(star_gun.price));
        price_star_gun.text.setPosition(star_gun.rect.getPosition().x-120, star_gun.rect.getPosition().y-50);
        price_star_gun.text.setFont(price_star_gun.font_mr_otis);
        price_star_gun.text.setCharacterSize(text_size);
        
        
        //FREEZE GUN
        price_freeze_gun.text.setString("Lodowa zamiec: "+ to_string(freeze_gun.price));
        price_freeze_gun.text.setPosition(freeze_gun.rect.getPosition().x-170, freeze_gun.rect.getPosition().y-50);
        price_freeze_gun.text.setFont(price_freeze_gun.font_mr_otis);
        price_freeze_gun.text.setCharacterSize(text_size);
        
        
        //HP POTION
        price_hp_potion.text.setString("Mikstura lecznicza: "+ to_string(hp_potion.price));
        price_hp_potion.text.setPosition(hp_potion.rect.getPosition().x-210, hp_potion.rect.getPosition().y-50);
        price_hp_potion.text.setFont(price_hp_potion.font_mr_otis);
        price_hp_potion.text.setCharacterSize(text_size);
        
        //variables
        bool can_play1 = true;
        bool can_play2 = true;
        bool can_play3 = true;
        bool can_play4 = true;
        bool can_play5 = true;
        bool can_play6 = true;
        
        
        sf::Time elapsed_shop = clock_shop.getElapsedTime();
        sf::Time elpased_select = clock_select.getElapsedTime();

        
        int alphaPlus = -55;
        int alphaMinus = 255;
        int alpha=255;
        
        
        
        //set music background
        music.music_shop.play();
        music.music_shop.setLoop(true);
        //game loop
        while(state_level==SHOP)
        {
            
            price_poskramiacz.text.setFillColor(sf::Color(alpha,50,20,alpha));
            price_fire_gun.text.setFillColor(sf::Color(alpha,50,20,alpha));
            price_ring.text.setFillColor(sf::Color(alpha,50,20,alpha));
            price_star_gun.text.setFillColor(sf::Color(alpha,50,20,alpha));
            price_freeze_gun.text.setFillColor(sf::Color(alpha,50,20,alpha));
            price_hp_potion.text.setFillColor(sf::Color(alpha,50,20,alpha));
            
            if(elapsed_shop.asSeconds() >= 0.1)
            {
                alphaPlus= alphaPlus + 2;
                
                alphaMinus -=2;
                
                if(alpha<=255 && alpha>=100)
                {
                    alpha=alphaMinus;
                }
                if(alpha<100)
                {
                    alpha = alphaPlus;
                }
                else;
                
                if(alphaPlus>=255)
                {
                    alphaPlus=-55;
                }
                else;
                
                if(alphaMinus<=-55)
                {
                    alphaMinus=255;
                }
                clock_shop.restart();
            }
            //check distance
            check_distance_from_items(&can_play1, &can_play2, &can_play3, &can_play4, &can_play5, &can_play6);
            //buy items
            BuyItems();
            //keyboard events
            KeyboardEvents(&canShowPredatorDistance ,distance_predator);
            //clear window
            window->clear();
            //collisions
            Collisions();
            Item_shop_collisions();
            check_isPlayer_dead(game);
            //checking distance beetwen predator enemy and player
            check_IsPredatorNear(distance_predator);
            //destruction animation
            destructionAnimation();
            //delete objects
            DeleteObjects();
            //EDITOR
            Editor();
            //PLAYER MOVE AND UPDATE POSITION WITH RECTANGLE
            player.Movement();
            player.Update();
            //PLAYER VIEW AND TEXT
            window->setView(view1);
            view1.setCenter(player.rect.getPosition());
            
            //drawing
            window->clear();
            //drawBackground();
            
            drawEngine(true, &sprite_shop);
            draw_Shop_Items();
            
            //set display text position
            moneyText.text.setPosition(player.rect.getPosition().x-window->getSize().x/2, player.rect.getPosition().y-window->getSize().y/2);
            playerLifeText.text.setPosition(player.rect.getPosition().x-window->getSize().x/2, player.rect.getPosition().y-window->getSize().y/2+30);
            playerWeapon.text.setPosition(player.rect.getPosition().x-window->getSize().x/2, player.rect.getPosition().y-window->getSize().y/2+60);
            attack_damage.text.setPosition(player.rect.getPosition().x-window->getSize().x/2, player.rect.getPosition().y-window->getSize().y/2+100);
            /////////////////////////////////// DISPLAY ///////////////////////////////////
            window->display();
            if(exit_shop_door.can_go_next==true)
            {
                state_level = LEVEL1;
                cout<<"Go to Level1!"<<endl;
                fromShop = true;
            }
            else;
            
        }
        
        saveEngine(3);
        music.music_shop.stop();
        savePlayer();
        
        
    }

}





