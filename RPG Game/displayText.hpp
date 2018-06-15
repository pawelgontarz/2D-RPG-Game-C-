//
//  displayText.hpp
//  RPG Game
//
//  Created by Mac Paweł on 05.05.2017.
//  Copyright © 2017 Macbook PRO 13. All rights reserved.
//

#ifndef displayText_hpp
#define displayText_hpp

#include <stdio.h>
#include "Object.hpp"


class displayText : public Object
{
public:
    string myString;
    int speed;
    int counter;
    int lifeTime;
    bool destroy;
    sf::Font font_Mecha;
    sf::Font font_kurt_Bold;
    sf::Font font_blind_signature;
    sf::Font font_Balloonish;
    sf::Font font_mr_otis;
    sf::Font font_coco_gothic;
    
    displayText();
    ~displayText();
    
    
    void Update();
    
    
    
};

#endif /* displayText_hpp */
