#ifndef _Player_
#define _Player_

class Player
{
private:
    sf::CircleShape playerShape;
    sf::Clock clock;
    sf::Time t;
    float radius;
    float speed = 100.0f;
    float angle = 3.14f*2;
public:
    void eye(sf::RenderWindow &w);
    void move(float dt);
    sf::Time render(sf::RenderWindow &w, float td);
    Player(sf::Vector2f vector, float radius);
    ~Player();
};

#endif