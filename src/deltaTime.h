#ifndef _DeltaTime_
#define _DeltaTime_

class DeltaTime
{
private:
    sf::Clock clock;
    sf::Time t;
public:
    sf::Time get();
    void update();
    DeltaTime();
    ~DeltaTime();
};

#endif