// PROGRAMA --> MOTOR DE VIDEOJOCS
// AUTOR --> Pablo Abad Ortega
// DATA --> 3/2/2026

#pragma once
#include "GameObject.h"

// Classe DERIVADA
class Personatge : public GameObject
{
protected:
    Vector2f velocitat;
    bool estaSaltant;

    // Paràmetres físics
    const float GRAVETAT = 800.0f;
    float speed;
    float forsaSaltant;
private:
    // Sobreescriptura privada
    void actualitzacio(float dt) override;
public:
    // Constructor
    Personatge(float x, float y, float spd, float jmp);

    // Mètode virtual
    virtual void controlarEntrada() = 0;  // Cada personatge té els seus controls

    // Actualització avançad
    void actualitzacio(float dt, int MaxX, int MaxY);

    // Modifica la posició
    void setPosition(float x, float y);

    // Atura el personatge quan toca terra
    void stopFalling(float groundY);
};