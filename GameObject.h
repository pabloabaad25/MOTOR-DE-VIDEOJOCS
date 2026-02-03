// PROGRAMA --> MOTOR DE VIDEOJOCS
// AUTOR --> Pablo Abad Ortega
// DATA --> 3/2/2026

#pragma once
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

// Defineix les propietats comunes de qualsevol objecte
class GameObject
{
protected:
    Vector2f posicio;
    RectangleShape forma;

public:
    // Configura la posició inicial i la mida del rectangle
    GameObject(float x, float y, float amplada, float alcada);

    // Destructor virtual
    virtual ~GameObject() {}

    // Mètode virtual
    virtual void actualitzacio(float dt) = 0;

    // Renderitzat
    virtual void dibuixar(RenderWindow& finestra);
    
    // Getters amb 'const'
    FloatRect getLimits() const;

    // Retorna la posició actual de l'objecte.
    Vector2f getPosicio() const;

    // Setter
    void setPosicio(float x, float y);
};