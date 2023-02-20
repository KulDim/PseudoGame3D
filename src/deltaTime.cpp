#include <SFML/Graphics.hpp>
#include "deltaTime.h"

sf::Time DeltaTime::get()
{
    return t;
}


void DeltaTime::update()
{
    t = clock.restart();
}

DeltaTime::DeltaTime()
{
    t = clock.restart();
}

DeltaTime::~DeltaTime()
{

}