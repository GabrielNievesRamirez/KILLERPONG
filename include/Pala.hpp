#ifndef PALA_HPP
#define PALA_HPP

#include <SFML/Graphics.hpp>

class Pala {
private:
    sf::RectangleShape shape;
    sf::Vector2f velocidad;

public:
    Pala(float x, float y);
    void Update(float deltaTime, bool movingUp, bool movingDown);
    void Draw(sf::RenderWindow& window);
    sf::Vector2f getPosition();
};

#endif // PALA_HPP
