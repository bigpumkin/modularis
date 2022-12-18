#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <cmath>
#include <string>

#include "module/osc.hpp"

using namespace std;
using namespace sf;

int main()
{
	VideoMode SCREEN_SIZE = sf::VideoMode::getDesktopMode();
	// создаем окно
	RenderWindow window(VideoMode(SCREEN_SIZE), "");

	Oscillator osc1;

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
        
        osc1.draw(78, 56, window);

		window.display();
	}

	return 0;
}