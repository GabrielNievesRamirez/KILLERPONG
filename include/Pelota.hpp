#ifndef PELOTA_HPP
#define PELOTA_HPP

#include <SFML/Graphics.hpp>

class Pelota {
private:
    sf::CircleShape shape;
    sf::Vector2f velocidad;

public:
    Pelota(float radius);
    void Update(float deltaTime);
    void Draw(sf::RenderWindow& window);
    sf::Vector2f getPosition();
    float getRadius();
    void Rebotar();
};

#endif // PELOTA_HPP
