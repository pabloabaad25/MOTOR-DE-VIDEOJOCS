// PROGRAMA --> MOTOR DE VIDEOJOCS
// AUTOR --> Pablo Abad Ortega
// DATA --> 3/2/2026

#include "Tomas.h"
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

// CONSTRUCTOR 
Tomas::Tomas(float x, float y) : Personatge(x, y, 250.0f, -450.0f)
{
    forma.setFillColor(Color::Green);
}

// LÒGICA DE CONTROL 
void Tomas::controlarEntrada()
{
    // Controls: WASD
    velocitat.x = 0;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
    {
        velocitat.x = -speed;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
    {
        velocitat.x = speed;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) && !estaSaltant)
    {
        velocitat.y = forsaSaltant;
        estaSaltant = true;
    }
}