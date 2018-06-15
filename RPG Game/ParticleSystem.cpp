//
//  ParticleSystem.cpp
//  RPG Game
//
//  Created by Mac Paweł on 14.05.2017.
//  Copyright © 2017 Macbook PRO 13. All rights reserved.
//

#include "ParticleSystem.hpp"




 ParticleSystem::ParticleSystem(unsigned int count) :
m_particles(count),
m_vertices(sf::Points, count),
m_lifetime(sf::seconds(3)),
m_emitter(0, 0)
{
}

void ParticleSystem::setEmitter(sf::Vector2f position)
{
    m_emitter = position;
}

void ParticleSystem::update(sf::Time elapsed)
{
    for (std::size_t i = 0; i < m_particles.size(); ++i)
    {
        // update the particle lifetime
        Particle& p = m_particles[i];
        p.lifetime -= elapsed;
        
        // if the particle is dead, respawn it
        if (p.lifetime <= sf::Time::Zero)
            resetParticle(i);
        
        // update the position of the corresponding vertex
        m_vertices[i].position += p.velocity * elapsed.asSeconds();
        
        // update the alpha (transparency) of the particle according to its lifetime
        float ratio = p.lifetime.asSeconds() / m_lifetime.asSeconds();
        
        // main color
         sf::Color color = sf::Color::Cyan;
         m_vertices[i].color = color;
         
        //m_vertices[i].color.a = static_cast<sf::Uint8>(ratio * 255);
    }
}

 void ParticleSystem::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    // apply the transform
    states.transform *= getTransform();
    
    // our particles don't use a texture
    states.texture = NULL;
    
    // draw the vertex array
    target.draw(m_vertices, states);
}


void ParticleSystem::resetParticle(std::size_t index)
{
    // give a random velocity and lifetime to the particle
    float angle = (std::rand() % 360) * 3.14f / 180.f;
    float speed = (std::rand() % 150) ;
    m_particles[index].velocity = sf::Vector2f(std::cos(angle) * speed, std::sin(angle) * speed);
    m_particles[index].lifetime = sf::milliseconds((std::rand() % 2000) );
    
    // reset the position of the corresponding vertex
    m_vertices[index].position = m_emitter;
}
