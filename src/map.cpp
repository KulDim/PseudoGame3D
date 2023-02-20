#include <SFML/Graphics.hpp>
#include <iostream>
#include <string.h>

#include "map.h"



sf::Time Map::render(sf::RenderWindow &w)
{
    clock.restart();
    block.setSize(sf::Vector2f(20,20));

    for(int i = 0; i < SIZE; i++)
    {
        for(int j = 0; j < MAP[i].size(); j++)
        {
            if(MAP[i][j] == ' ') 
            {
                continue;
            }
            block.setPosition(sf::Vector2f(j * 20, i * 20));
            w.draw(block);
        }

        // &w.draw();
    }
    t = clock.restart();
    return t;
}

Map::~Map()
{
}