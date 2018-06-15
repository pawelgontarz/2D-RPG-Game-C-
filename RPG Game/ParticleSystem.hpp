//
//  ParticleSystem.hpp
//  RPG Game
//
//  Created by Mac Paweł on 14.05.2017.
//  Copyright © 2017 Macbook PRO 13. All rights reserved.
//

#ifndef ParticleSystem_hpp
#define ParticleSystem_hpp

#include <stdio.h>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <tgmath.h>


class ParticleSystem : public sf::Drawable, public sf::Transformable
{
public:
    
    
    ParticleSystem(unsigned int count);
    void setEmitter(sf::Vector2f position);
    void update(sf::Time elapsed);
    
private:
    
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    
private:
    
    struct Particle
    {
        sf::Vector2f velocity;
        sf::Time lifetime;
    };
    
    void resetParticle(std::size_t index);
    
    std::vector<Particle> m_particles;
    sf::VertexArray m_vertices;
    sf::Time m_lifetime;
    sf::Vector2f m_emitter;
};




#endif /* ParticleSystem_hpp */
