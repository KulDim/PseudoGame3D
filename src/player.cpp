#include <SFML/Graphics.hpp>
#include <iostream>
#include <string.h>
#include <math.h>
#include "player.h"

void Player::eye(sf::RenderWindow &w)
{

    sf::Vertex line[] =
    {
        sf::Vertex
            (sf::Vector2f(
                playerShape.getPosition().x + radius ,
                playerShape.getPosition().y + radius 
            ),
                sf::Color::Red),
        sf::Vertex(
            sf::Vector2f(
                        playerShape.getPosition().x + radius + std::cos(angle) * radius, 
                        playerShape.getPosition().y + radius + std::sin(angle) * radius
            ),
                sf::Color::Red)
    };
    w.draw(line, 2, sf::Lines);
}

void Player::move(float dt)
{
    if(angle < 0) angle = 3.14f * 2;
    if(angle > 3.14f*2) angle = 0;

    float x = (speed * std::cos(angle) * dt);
    float y = (speed * std::sin(angle) * dt);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
            angle -= 0.01f ;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
            angle += 0.01f ;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        playerShape.move(x, y);

    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        playerShape.move(-x, -y);
    }
}

sf::Time Player::render(sf::RenderWindow &w, float dt)
{
    clock.restart();
    move(dt);
    w.draw(playerShape);
    eye(w);
    t = clock.restart();
    return t;
}

Player::Player(sf::Vector2f vector, float radius)
{
    this->radius = radius;
    playerShape.setRadius(this->radius);
    playerShape.setPosition(vector.x - this->radius, vector.y - this->radius);

}

Player::~Player()
{


}