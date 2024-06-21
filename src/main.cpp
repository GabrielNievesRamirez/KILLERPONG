#include <SFML/Graphics.hpp>
#include "Pelota.hpp"
#include "Pala.hpp"

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;

int main() {
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Pong");

    Pelota pelota(10.0f);
    Pala palaJugador1(50.0f, WINDOW_HEIGHT / 2);
    Pala palaJugador2(WINDOW_WIDTH - 50.0f, WINDOW_HEIGHT / 2);

    sf::Clock clock;
    float deltaTime = 0.0f;

    while (window.isOpen()) {
        deltaTime = clock.restart().asSeconds();

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        bool moveUp1 = sf::Keyboard::isKeyPressed(sf::Keyboard::W);
        bool moveDown1 = sf::Keyboard::isKeyPressed(sf::Keyboard::S);
        bool moveUp2 = sf::Keyboard::isKeyPressed(sf::Keyboard::Up);
        bool moveDown2 = sf::Keyboard::isKeyPressed(sf::Keyboard::Down);

        palaJugador1.Update(deltaTime, moveUp1, moveDown1);
        palaJugador2.Update(deltaTime, moveUp2, moveDown2);

        pelota.Update(deltaTime);

        // Lógica de colisiones y rebotes
        sf::Vector2f pelotaPos = pelota.getPosition();
        float pelotaRadius = pelota.getRadius();

        if (pelotaPos.x - pelotaRadius < 0) {
            // Punto para Jugador 2
            // Reiniciar la pelota
            pelota.Rebotar();
        } else if (pelotaPos.x + pelotaRadius > WINDOW_WIDTH) {
            // Punto para Jugador 1
            // Reiniciar la pelota
            pelota.Rebotar();
        }

        if (pelotaPos.y - pelotaRadius < 0 || pelotaPos.y + pelotaRadius > WINDOW_HEIGHT) {
            pelota.Rebotar();
        }

        // Comprobar colisiones con las palas
        sf::FloatRect pala1Bounds = palaJugador1.getPosition().getGlobalBounds();
        sf::FloatRect pala2Bounds = palaJugador2.getPosition().getGlobalBounds();
        sf::FloatRect pelotaBounds = pelota.shape.getGlobalBounds();

        if (pelotaBounds.intersects(pala1Bounds) || pelotaBounds.intersects(pala2Bounds)) {
            pelota.Rebotar();
        }

        window.clear(sf::Color::Black);
        pelota.Draw(window);
        palaJugador1.Draw(window);
        palaJugador2.Draw(window);
        window.display();
    }

    return 0;
}
