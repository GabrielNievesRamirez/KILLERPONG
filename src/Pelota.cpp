#include "Pelota.hpp"

Pelota::Pelota(float radius) {
    shape.setRadius(radius);
    shape.setFillColor(sf::Color::White);
    shape.setOrigin(radius, radius);
}

void Pelota::Update(float deltaTime) {
    shape.move(velocidad * deltaTime);
}

void Pelota::Draw(sf::RenderWindow& window) {
    window.draw(shape);
}

sf::Vector2f Pelota::getPosition() {
    return shape.getPosition();
}

float Pelota::getRadius() {
    return shape.getRadius();
}

void Pelota::Rebotar() {
    velocidad.x = -velocidad.x;
}
