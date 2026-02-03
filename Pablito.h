// PROGRAMA --> MOTOR DE VIDEOJOCS
// AUTOR --> Pablo Abad Ortega
// DATA --> 3/2/2026

#ifndef PABLITO_H
#define PABLITO_H

#include "Personatge.h"

// Classe Pablito
class Pablito : public Personatge
{
public:
    // Constructor
    Pablito(float x, float y);

    // Gestió de controls
    void controlarEntrada() override; 
};

#endif