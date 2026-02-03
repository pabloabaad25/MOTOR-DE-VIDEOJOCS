#include "Personatge.h"

using namespace std;
using namespace sf;

// CONSTRUCTOR 
Personatge::Personatge(float x, float y, float spd, float jmp) : GameObject(x, y, 40, 60)
{
    velocitat = Vector2f(0, 0);
    estaSaltant = false;
    speed = spd;
    forsaSaltant = jmp;
}

void Personatge::actualitzacio(float dt) {}

// LÒGICA DE FÍSIQUES 
void Personatge::actualitzacio(float dt, int MaxX, int MaxY)
{
    // 1. Aplicar Gravetat
    velocitat.y += GRAVETAT * dt;

    // 2. Moviment
    posicio.x += velocitat.x * dt;
    posicio.y += velocitat.y * dt;

    // 3. Col·lisió bàsic
    if (posicio.y > MaxY - 100)
    {
        posicio.y = MaxY - 100;
        velocitat.y = 0;
        estaSaltant = false;
    }

    // 4. Límits de la pantalla
    if (posicio.x < 0) posicio.x = 0;
    if (posicio.x > MaxX) posicio.x = MaxX;

    // Actualitza la posició visual
    forma.setPosition(posicio);
}

// UTILITATS 
void Personatge::setPosition(float x, float y)
{
    posicio = Vector2f(x, y);
    forma.setPosition(posicio);
}

// Atura la caiguda quan es detecta una col·lisió
void Personatge::stopFalling(float groundY)
{
    posicio.y = groundY;
    velocitat.y = 0;
    estaSaltant = false;
    forma.setPosition(posicio);
}