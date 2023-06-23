#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <cmath>
#include <string>

#include "module/osc.hpp"
#include "module/wire.hpp"

using namespace std;

int main()
{
	sf::VideoMode SCREEN_SIZE = sf::VideoMode::getDesktopMode();
	// создаем окно
;	sf::RenderWindow window(sf::VideoMode(SCREEN_SIZE), "");

    vector<unique_ptr<Basic>> modules;
    for (size_t i = 0; i < modules.size(); i++)
    {
       modules[i]->process(44100);
    }
    
    set_wires();
    
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
        
        //osc1.draw(78, 56, window);
		//osc1.process();
		window.display();
	}

	return 0;
}