#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <cmath>
#include <string>
#include <vector>

#include "module/osc.hpp"
#include "module/out.hpp"
#include "module/wire.hpp"

using namespace std;

int main()
{
    sf::VideoMode SCREEN_SIZE = sf::VideoMode::getDesktopMode();
    
    
    // создаем окно

    sf::RenderWindow window(sf::VideoMode(SCREEN_SIZE), "");
    window.sf::Window::setVerticalSyncEnabled(1);

    //добавление модуля
    Oscillator *oscillator = new Oscillator;
    std::shared_ptr<Basic> osc = std::make_shared<Oscillator>(*oscillator);
    
    Out *output = new Out;
    std::shared_ptr<Basic> out = std::make_shared<Out>(*output);
    std::vector<std::shared_ptr<Basic>> modules;
    modules.push_back(osc);
    modules.push_back(out);
   modules[0]->set_position(56, 32);

    for (size_t i = 0; i < 50000; i++)
    {
        for (size_t i = 0; i < modules.size(); i++)
        {
            modules[i]->process(44100);
        }

        set_wires();
    }
    
    
    // приложение будет работать, пока окно открыто
    while (window.isOpen())
    {
        // проверяем все события окна, которые были запущены с предыдущей итерации цикла
        sf::Event event;
        while (window.pollEvent(event))
        {
            // сработало событие закрытия окна - закроем его
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color(3, 71, 105));
        
        for(size_t i=0; i < modules.size();i++)
    {
        modules[i]->draw(window);
    }
    
        window.display();
        
    }

    return 0;
}