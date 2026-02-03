// PROGRAMA --> MOTOR DE VIDEOJOCS
// AUTOR --> Pablo Abad Ortega
// DATA --> 3/2/2026

#include "Pablito.h"
#include <SFML/Graphics.hpp>

using namespace sf;

// CONSTRUCTOR: Defineix la posició inicial i els atributs físics
Pablito::Pablito(float x, float y) : Personatge(x, y, 350.0f, -500.0f)
{
    forma.setFillColor(Color::Magenta);
}

// GESTIÓ D'ENTRADA: Escolta el teclat i modifica la velocitat
void Pablito::controlarEntrada()
{
    velocitat.x = 0;

    if (Keyboard::isKeyPressed(Keyboard::Key::Left))
    {
        velocitat.x = -speed;
    }

    if (Keyboard::isKeyPressed(Keyboard::Key::Right))
    {
        velocitat.x = speed;
    }

    if (Keyboard::isKeyPressed(Keyboard::Key::Up) && !estaSaltant)
    {
        velocitat.y = forsaSaltant;
        estaSaltant = true;
    }
}