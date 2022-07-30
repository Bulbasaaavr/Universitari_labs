/*Лаба 9. 3 вариант.
Создайте 3 прямоугольника разных цветов и размеров. Перемещайте их из исходного положения влево до конца экрана с разной скоростью.
При достижении конца экрана остановите фигуры.
*/

#include <SFML/Graphics.hpp>
#include <thread>
#include <chrono>

using namespace std::chrono_literals;

int main()
{
	int x1 = 1000;
	int y1 = 700;
	sf::RenderWindow window(sf::VideoMode(x1, y1), "SFML Graphics");

	int rectangle_x1 = 900; //координата x
	int rectangle_y1 = 100; //координата y
	int rectangle_x2 = 850;
	int rectangle_y2 = 250;
	int rectangle_x3 = 800;
	int rectangle_y3 = 400;
	

	//1 фигура
	float rx1 = 176; float ry1 = 76;
	sf::RectangleShape rectangle1(sf::Vector2f(rx1, ry1)); //размер фигуры  Vector2f-контейнер(float)
	rectangle1.setFillColor(sf::Color(255, 255, 0)); // цвет
	rectangle1.setOrigin(rx1/2, ry1/2); //координаты центральной точки
	rectangle1.setPosition(rectangle_x1, rectangle_y1);

	//2 фигура
	float rx2 = 200; float ry2 = 126;
	sf::RectangleShape rectangle2(sf::Vector2f(rx2, ry2));
	rectangle2.setFillColor(sf::Color(0, 255, 255));
	rectangle2.setOrigin(rx2/2, ry2/2);
	rectangle2.setPosition(rectangle_x2, rectangle_y2);

	//3 фигура
	float rx3 = 400; float ry3 = 100;
	sf::RectangleShape rectangle3(sf::Vector2f(rx3, ry3));
	rectangle3.setFillColor(sf::Color(128, 0, 128));
	rectangle3.setOrigin(rx3/2, ry3/2);
	rectangle3.setPosition(rectangle_x3, rectangle_y3);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event)) // пока есть события, обрабатывать их
		{
			if (event.type == sf::Event::Closed)	//закрытие окна
				window.close();
		}

		if (rectangle_x1 > -1.1+(rx1/2))
		{
			rectangle1.setPosition(rectangle_x1, rectangle_y1); // расположение 
			rectangle_x1 = rectangle_x1 - 3;  // скорость 1 фигуры
		}
		
		if (rectangle_x2 > -2.1 + (rx2 / 2))
		{
			rectangle2.setPosition(rectangle_x2, rectangle_y2);
			rectangle_x2 = rectangle_x2 - 4;
		}

		if (rectangle_x3 > -1.9 + (rx3 / 2))
		{
			rectangle3.setPosition(rectangle_x3, rectangle_y3);
			rectangle_x3 = rectangle_x3 - 5;
		}

		window.clear(sf::Color(255, 0, 0)); // цвет экрана

		window.draw(rectangle1); //отображение фигуры
		window.draw(rectangle2);
		window.draw(rectangle3);

		window.display(); //показ

		std::this_thread::sleep_for(5ms);
	}

	return 0;
}