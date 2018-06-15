//
//  displayText.cpp
//  RPG Game
//
//  Created by Mac Paweł on 05.05.2017.
//  Copyright © 2017 Macbook PRO 13. All rights reserved.
//

#include "displayText.hpp"


displayText::displayText()
{
    
    //set default string
    myString = " string";
    
    
    //Setters
    text.setPosition(0,0);
    text.setFillColor(sf::Color::Red);
    text.setCharacterSize(40);
    text.setFont(font_Balloonish);
    text.setString(myString);
    
    speed = 6;
    destroy = false;
    counter = 0;
    lifeTime = 30;
    
    
    //loading FONTS
    if(!font_Mecha.loadFromFile(resourcePath()+"Mecha.ttf"))
    {
        cout<<"Cant load Mecha.tff!"<<endl;
        return EXIT_FAILURE;
    }
    if(!font_kurt_Bold.loadFromFile(resourcePath()+"kurt-Bold.ttf"))
    {
        cout<<"Cant load kurt-Bold.ttf!"<<endl;
        return EXIT_FAILURE;
    }
    
    if(!font_blind_signature.loadFromFile(resourcePath()+"blind_signature.ttf"))
    {
        cout<<"Cant load blind_signature.ttf!"<<endl;
        return EXIT_FAILURE;
    }
    if(!font_Balloonish.loadFromFile(resourcePath()+"Balloonish.ttf"))
    {
        cout<<"Cant load Balloonish.ttf!"<<endl;
        return EXIT_FAILURE;
    }

    if(!font_mr_otis.loadFromFile(resourcePath()+"mr_otis.ttf"))
    {
        cout<<"Cant load mr_otis.ttf!"<<endl;
        return EXIT_FAILURE;
    }
    
    if(!font_coco_gothic.loadFromFile(resourcePath()+"CocoGothic-Bold_trial.ttf"))
    {
        cout<<"Cant load  CocoGothic-Bold_trial.ttf!"<<endl;
        return EXIT_FAILURE;
    }
    
   
    
}




displayText::~displayText()
{
    
}


void displayText::Update()
{
    text.move(0,-speed);
    counter++;
    if(counter >= lifeTime)
    {
        destroy = true;
    }
    
}
