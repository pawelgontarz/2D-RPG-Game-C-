//
//  Music.cpp
//  RPG Game
//
//  Created by Mac Paweł on 11.05.2017.
//  Copyright © 2017 Macbook PRO 13. All rights reserved.
//

#include "Music.hpp"
using namespace std;

Music::Music()
{
    //load scary music
    if (!scary_music.openFromFile(resourcePath()+"Ominous_Suspense.ogg"))
    {
        cout<<"Cant load Dungeon_Theme.mp3"<<endl;
        return EXIT_FAILURE;
    }
     scary_music.setVolume(100);
    
    //load music level 1
    if (!music_level1.openFromFile(resourcePath()+"Dungeon_Theme.ogg"))
    {
        cout<<"Cant load Dungeon_Theme.ogg"<<endl;
        return EXIT_FAILURE;
    }
    music_level1.setVolume(100);

    //load musicMenu
    if (!musicMenu.openFromFile(resourcePath()+"theme_menu.wav"))
    {
        cout<<"Cant load theme_menu.wav"<<endl;
        return EXIT_FAILURE;
    }
    //load musicMenu
    if (!musicLose.openFromFile(resourcePath()+"SAD_MUSIC_2.wav"))
    {
        cout<<"Cant load SAD_MUSIC_2.wav"<<endl;
        return EXIT_FAILURE;
    }
    //load music_shop
    if (!music_shop.openFromFile(resourcePath()+"shop_music.ogg"))
    {
        cout<<"Cant load shop_music.ogg"<<endl;
        return EXIT_FAILURE;
    }
    
    //load music_level3
    if (!music_level3.openFromFile(resourcePath()+"Gray_Trip.ogg"))
    {
        cout<<"Cant load Gray_Trip.ogg"<<endl;
        return EXIT_FAILURE;
    }
    
    
   
}

