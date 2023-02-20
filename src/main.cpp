#include <SFML/Graphics.hpp>
#include <iostream>
#include <string> 

#include "imgui/imgui.h"
#include "imgui/imgui-sfml.h"

#include "deltaTime.h"
#include "map.h"
#include "player.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 800), "");
    ImGui::SFML::Init(window);
    // window.setFramerateLimit(60);

    sf::Event event;
    DeltaTime dt = DeltaTime();

    Map map;
    sf::Time mapRenderTime;
    sf::Time playerRenderTime;

    Player player = Player(sf::Vector2f(400,400), 10.0f);

 

    while (window.isOpen())
    {   
        dt.update();
        
        while (window.pollEvent(event))
        {
            ImGui::SFML::ProcessEvent(window, event);
            if (event.type == sf::Event::Closed) window.close();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) window.close();
        }
        

        std::string s = "FPS: " + std::to_string(int(1.0f / dt.get().asSeconds()));
        std::string ss = "One Frame : " + std::to_string(dt.get().asSeconds()) + " seconds";
        std::string sss = "mapRenderTime : " + std::to_string(mapRenderTime.asSeconds()) + " seconds";
        std::string ssss = "playerRenderTime : " + std::to_string(playerRenderTime.asSeconds()) + " seconds";
        ImGui::SFML::Update(window, dt.get());
        ImGui::Begin("Debuger");
        ImGui::Text(s.c_str());
        ImGui::Text(ss.c_str());
        ImGui::Text(sss.c_str());
        ImGui::Text(ssss.c_str());
        ImGui::End();


        window.clear();
        mapRenderTime = map.render(window);
        playerRenderTime = player.render(window, dt.get().asSeconds());
        ImGui::SFML::Render(window);
        window.display();
    }
    ImGui::SFML::Shutdown();
    return 0;
}