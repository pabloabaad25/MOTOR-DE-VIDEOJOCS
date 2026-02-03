// PROGRAMA --> MOTOR DE VIDEOJOCS
// AUTOR --> Pablo Abad Ortega
// DATA --> 3/2/2026

#pragma once
#include "Personatge.h"

// Classe Tomas
class Tomas : public Personatge
{
public:
    // Constructor
    Tomas(float x, float y);

    // Polimorfisme
    void controlarEntrada() override;
};
