//
//  Game.cpp
//  RPG Game
//
//  Created by Mac Paweł on 29.04.2017.
//  Copyright © 2017 Macbook PRO 13. All rights reserved.
//

#include "Game.hpp"

int const window_width = 1440;
int const window_height = 900;

sf::RenderWindow window(sf::VideoMode(window_width,window_height),"IMiRon The Game", sf::Style::Close);

//1440,900


Game::Game()
{
    
    
    window.setFramerateLimit(40);
    
    state = END;
    
    if(!font.loadFromFile(resourcePath()+"Mecha.ttf"))
    {
        cout<<"Cant load Mecha.tff!"<<endl;
        return EXIT_FAILURE;
    }
    if(!font1.loadFromFile(resourcePath()+"kurt-Bold.ttf"))
    {
        cout<<"Cant load sensation.tff!"<<endl;
        return EXIT_FAILURE;
    }
    
    if(!font2.loadFromFile(resourcePath()+"blind_signature.ttf"))
    {
        cout<<"Cant load sensation.tff!"<<endl;
        return EXIT_FAILURE;
    }
    if(!fontMenu.loadFromFile(resourcePath()+"the-dark-titan.ttf"))
    {
        cout<<"Cant load sensation.tff!"<<endl;
        return EXIT_FAILURE;
    }
    
    // Set the Icon
    if (!icon.loadFromFile(resourcePath() + "icon.png")) {
        return EXIT_FAILURE;
    }
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
    
    

    
    
    state = MENU;

    
    
    
    
}


void Game::runGame()
{
    
    music.musicMenu.play();
    music.musicMenu.setLoop(true);
    
    while(state != END)
    {
        
        switch (state)
        {
            case GameState::MENU:
                
                menu();
                break;
            case GameState::GAME:
                single();
             
                break;
            case GameState::CREDITS:
                credits();
                break;
            case GameState::CONTROL:
                control();
                break;
            case GameState::END:
                //
                break;
        }
    }
}


void Game::menu()
{
    cout<<"Game started"<<endl;
    window.setFramerateLimit(70);
    /////animation title variables
    int alphaPlus = -155;
    int alphaMinus = 255;
    int alpha=255;
    /////////////////////////////////
    
    sf::Text title("IMiR'on The Game",fontMenu,140);
    title.setStyle(sf::Text::Bold);
    
    
    title.setPosition(window.getSize().x/2-title.getGlobalBounds().width/2,40);
    
    const int text_number = 4;
    
    sf::Text text[text_number];
    
    string str[] = {"GRAJ","O GRZE","STEROWANIE","WYJSCIE Z GRY"};
    for(int i=0;i<text_number;i++)
    {
        text[i].setFont(font2);
        text[i].setCharacterSize(65);
        
        text[i].setString(str[i]);
        text[i].setPosition(window.getSize().x/2-text[i].getGlobalBounds().width/2,250+i*120);
    }
    
    //particles
    
    // create the particle system
    ParticleSystem particles(10000);
    // create a clock to track the elapsed time
    sf::Clock clock;
 
    
    
    
    
    while(state == MENU)
    {
        
        
        ////anime title
        title.setFillColor(sf::Color(250,100,0,alpha));
        /////////////////////////////////////////////
        
        
        sf::Vector2f mouse(sf::Mouse::getPosition(window));
        sf::Event event;
        
        
        // make the particle system emitter follow the mouse
        sf::Vector2i mouse1 = sf::Mouse::getPosition(window);
        sf::Vector2i coord(700,450);
        particles.setEmitter(window.mapPixelToCoords(mouse1));
        
        // update it
        sf::Time elapsed = clock.restart();
        particles.update(elapsed);

        
        
        
        
        sf::Time elapsed1 = clock1.getElapsedTime();
       
        sf::Time elapsed3 = clock3.getElapsedTime();
       
        
        
        
        while(window.pollEvent(event))
        {
            //press ESC or button X
            if(event.type == sf::Event::Closed || (event.type == sf::Event::KeyPressed &&
                                                   event.key.code == sf::Keyboard::Escape))
            {
                audio.chooseMenu();
                state = END;
            }
            
          
            //click GAME
            else if(text[0].getGlobalBounds().contains(mouse) &&
                    event.type == sf::Event::MouseButtonReleased && event.key.code == sf::Mouse::Left)
            {
                audio.chooseMenu();
                state = GAME;
            }
            //click CREDITS
            else if(text[1].getGlobalBounds().contains(mouse) &&
                    event.type == sf::Event::MouseButtonReleased && event.key.code == sf::Mouse::Left)
            {
                audio.chooseMenu();
                state = CREDITS;
            }
            
            //click CONTROL
            else if(text[2].getGlobalBounds().contains(mouse) &&
                    event.type == sf::Event::MouseButtonReleased && event.key.code == sf::Mouse::Left)
            {
                audio.chooseMenu();
                state = CONTROL;
            }
            
            //click EXIT
            else if(text[3].getGlobalBounds().contains(mouse) &&
                    event.type == sf::Event::MouseButtonReleased && event.key.code == sf::Mouse::Left)
            {
                audio.chooseMenu();
                state = END;
            }
        }
                    for(int i=0;i<text_number;i++)
                    if(text[i].getGlobalBounds().contains(mouse))
                    {
                       
                    text[i].setColor(sf::Color::Red);
                    text[i].setCharacterSize(90);
                        text[i].setPosition(window.getSize().x/2-text[i].getGlobalBounds().width/2,250+i*120);
                        
                    }
                    else
                    {
                     text[i].setCharacterSize(65);
                     text[i].setColor(sf::Color::White);
                      text[i].setPosition(window.getSize().x/2-text[i].getGlobalBounds().width/2,250+i*120);
                    }
                    
                    window.clear();
        
      /*
       SHOWING COORDINATES MOUSE
       
       if(elapsed3.asSeconds() >= 0.09)
        {
            system("clear");
       cout<<"mouse coord x: "<<sf::Mouse::getPosition(window).x<<endl;
      cout<<"mouse coord y: "<<sf::Mouse::getPosition(window).y<<endl;
       
            clock3.restart();
        }
        
       */
        
        
        ////////////////////////////////////////////animation title///////////////////////////////////////////////////
        if(elapsed1.asSeconds() >= 0.008)
        {
 
        alphaPlus= alphaPlus+5;
        
            alphaMinus = alphaMinus  - 5;
        
        if(alpha<=255 && alpha>=50)
        {
            alpha=alphaMinus;
        }
        if(alpha<50)
        {
            alpha = alphaPlus;
        }
        else;
        
        if(alphaPlus==255)
        {
            alphaPlus=-155;
        }
        else;
        
        if(alphaMinus==-155)
        {
            alphaMinus=255;
        }
        
        
       
            
            clock1.restart();
        }
   /*
    cout<<"Alpha: "<<alpha<<endl;
   cout<<"AlphaPlus: "<<alphaPlus<<endl;
       cout<<"AlphaMinus: "<<alphaMinus<<endl;
        
    */    

                    window.draw(particles);
                    window.draw(title);
                    for(int i=0;i<text_number;i++)
                    {
                    window.draw(text[i]);
                    }
                     
                    window.display();
    }
}

void Game::single()
{
    Engine engine(window);
    cout<<"Single game started"<<endl;
    music.musicMenu.stop();
    engine.runEngine();
    if(engine.isPlayerDead == true)
    {
        showGame_over();
        state = MENU;
    }
    else
    {
      state = MENU;
        
    }
    music.musicMenu.play();
    
}


void Game::credits()
{
    showCredits();
    state = MENU;
}

void Game::showCredits()
{
    cout<<"Go to Credits"<<endl;
    
 sf::Time elapsed4 = clock4.getElapsedTime();
    
    const int text_number = 6;
    sf::Text text[text_number];
    string str[] = {"Tworca: Pawel Gontarz","Rok studiow: I","Kierunek: Inzynieria Mechatroniczna (WIMiR)","Uczelnia: AGH ","IMiRon The Game zostala napisana w pelni w C++ oraz SFML'u.", "Nacisnij ESC, aby powrocic do MENU glownego."};
    for(int i=0;i<text_number;i++)
    {
        text[i].setFont(font);
        text[i].setCharacterSize(55);
        
        text[i].setString(str[i]);
        text[i].setPosition(window.getSize().x/2-text[i].getGlobalBounds().width/2,250+i*90);
    }
    //text[5].setFillColor(sf::Color::Green);
    
    
    int alphaPlus = -55;
    int alphaMinus = 255;
    int alpha=255;
    
    //particles
    
    // create the particle system
    ParticleSystem particles(1000);
    // create a clock to track the elapsed time
    sf::Clock clock;
    
    bool menu = false;
    while(!menu)
    {
        
        
        // make the particle system emitter follow the mouse
        sf::Vector2i mouse1 = sf::Mouse::getPosition(window);
        sf::Vector2i coord(700,450);
        particles.setEmitter(window.mapPixelToCoords(mouse1));
        
        // update it
        sf::Time elapsed = clock.restart();
        particles.update(elapsed);

        
        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Escape)
            {
                menu = true;
                cout<<"Back to main MENU"<<endl;
            }
            else;
        }
        
        text[5].setFillColor(sf::Color(255,255,0,alpha));
        
        if(elapsed4.asSeconds() >= 0.02)
        {
            clock4.restart();
            alphaPlus= alphaPlus + 5;
            
            alphaMinus -=5;
            
            if(alpha<=255 && alpha>=100)
            {
                alpha=alphaMinus;
            }
            if(alpha<100)
            {
                alpha = alphaPlus;
            }
            else;
            
            if(alphaPlus==255)
            {
                alphaPlus=-55;
            }
            else;
            
            if(alphaMinus==-55)
            {
                alphaMinus=255;
            }
            
        }

        
                window.clear();
            sf::Text title("O GRZE",font1,60);
            title.setStyle(sf::Text::Bold);
            title.setFillColor(sf::Color::Red);
            title.setPosition(window.getSize().x/2-title.getGlobalBounds().width/2,40);

            //DRAW TEXT

            window.draw(title);
        window.draw(particles);
            for(int i=0;i<text_number;i++)
                window.draw(text[i]);
        
            window.display();
        
        
    }
}



void Game::control()
{
    showControl();
    state = MENU;
}

void Game::showControl()
{
    cout<<"Go to Control"<<endl;
    
 

    sf::Time elapsed2 = clock2.getElapsedTime();


    
    const int text_number = 7;
    sf::Text text[text_number];
    string str[] = {"Poruszanie sie w lewo --> Strzalka w lewo","Poruszanie sie w prawo --> Strzalka w prawo","Poruszanie sie w gore --> Strzalka w gore", "Poruszanie sie w dol --> Strzalka w dol", "Strzelanie --> SPACJA", "Kupowanie --> B","Nacisnij ESC, aby powrocic do MENU glownego."};
    for(int i=0;i<text_number;i++)
    {
        text[i].setFont(font);
        text[i].setCharacterSize(45);
        
        text[i].setString(str[i]);
        text[i].setPosition(window.getSize().x/2-text[i].getGlobalBounds().width/2,240+i*85);
    }
   
   
    int alphaPlus = -55;
    int alphaMinus = 255;
    int alpha=255;
    
    //particles
    
    // create the particle system
    ParticleSystem particles(1000);
    // create a clock to track the elapsed time
    sf::Clock clock;

    bool menu1 = false;
    while(!menu1)
    {
         text[6].setFillColor(sf::Color(255,255,0,alpha));
        
        // make the particle system emitter follow the mouse
        sf::Vector2i mouse1 = sf::Mouse::getPosition(window);
        sf::Vector2i coord(700,450);
        particles.setEmitter(window.mapPixelToCoords(mouse1));
        
        // update it
        sf::Time elapsed = clock.restart();
        particles.update(elapsed);

        
        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Escape)
            {
                menu1 = true;
                cout<<"Back to main MENU"<<endl;
                
            }
            else;
        }
        
        if(elapsed2.asSeconds() >= 0.02)
        {
            clock2.restart();
        alphaPlus= alphaPlus + 5;
       
        alphaMinus -=5;
        
        if(alpha<=255 && alpha>=100)
        {
            alpha=alphaMinus;
        }
        if(alpha<100)
        {
            alpha = alphaPlus;
        }
        else;
        
        if(alphaPlus==255)
        {
            alphaPlus=-55;
        }
        else;
        
        if(alphaMinus==-55)
        {
            alphaMinus=255;
        }
            

        }
        
        
        sf::Text title("STEROWANIE",font1,80);
        title.setStyle(sf::Text::Bold);
        title.setFillColor(sf::Color::Red);
        title.setPosition(window.getSize().x/2-title.getGlobalBounds().width/2,40);
        
        
        window.clear();
        //DRAW TEXT
        window.draw(title);
        window.draw(particles);
        for(int i=0;i<text_number;i++)
            window.draw(text[i]);
        window.display();
        
    }
}


void Game::showGame_over()
{
    window.clear();
    
    sf::Time elapsed_game_over = clock_game_over.getElapsedTime();
    cout<<"Go to Game Over"<<endl;
    
    const int text_number = 1;
    sf::Text text[text_number];
    string str[] = {"IMiR'on polegl! Nacisnij ESC aby wrocic do MENU glownego"};
    for(int i=0;i<text_number;i++)
    {
        text[i].setFont(font);
        text[i].setCharacterSize(45);
        
        text[i].setString(str[i]);
        text[i].setPosition(window.getSize().x/2-text[i].getGlobalBounds().width/2,400+i*60);
    }
    text[0].setFillColor(sf::Color::Green);
    
    int alphaPlus = -55;
    int alphaMinus = 255;
    int alpha=255;

    
    bool menu1 = false;
    //play music lose
   music.musicLose.play();
    music.musicLose.setLoop(true);
    while(!menu1)
    {
        
        


        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Escape)
            {
                menu1 = true;
                cout<<"Back to main MENU"<<endl;
            }
            else;
        }
        
        
        
        if(elapsed_game_over.asSeconds() >= 0.02)
        {
            clock_game_over.restart();
            alphaPlus= alphaPlus + 5;
            
            alphaMinus -=5;
            
            if(alpha<=255 && alpha>=100)
            {
                alpha=alphaMinus;
            }
            if(alpha<100)
            {
                alpha = alphaPlus;
            }
            else;
            
            if(alphaPlus==255)
            {
                alphaPlus=-55;
            }
            else;
            
            if(alphaMinus==-55)
            {
                alphaMinus=255;
            }
        }
        
            window.clear();
            sf::Text title("KONIEC GRY!",font1,160);
            title.setStyle(sf::Text::Bold);
            title.setFillColor(sf::Color(255,100,80,alpha));
            title.setPosition(window.getSize().x/2-title.getGlobalBounds().width/2,40);
            
            //DRAW TEXT
            window.draw(title);
  
            for(int i=0;i<text_number;i++)
                window.draw(text[i]);
            window.display();
    }
    
        //stop play music lose
    music.musicLose.stop();
        
}


void Game::showIntro()
{
    
    
    
}


