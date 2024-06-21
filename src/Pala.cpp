#include "Pala.hpp"

Pala::Pala(float x, float y) {
    shape.setSize(sf::Vector2f(10, 100));
    shape.setFillColor(sf::Color::White);
    shape.setOrigin(5, 50);
    shape.setPosition(x, y);
}

void Pala::Update(float deltaTime, bool movingUp, bool movingDown) {
    if (movingUp) {
        shape.move(0, -400.0f * deltaTime); // ajustar velocidad según necesidades
    }
    if (movingDown) {
        shape.move(0, 400.0f * deltaTime);
    }
}

void Pala::Draw(sf::RenderWindow& window) {
    window.draw(shape);
}

sf::Vector2f Pala::getPosition() {
    return shape.getPosition();
}
