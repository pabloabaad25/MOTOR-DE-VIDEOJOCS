#include "Enemic.h"

// CONSTRUCTOR 
Enemic::Enemic(float x, float y, float spd) : Personatge(x, y, spd, 0.0f)
{
	forma.setFillColor(sf::Color::Red);
	iniciX = x;
	direccio = 1;
	distanciaEnemic = 150.0f;
}

void Enemic::controlarEntrada()
{
	// 1. Límit dret
	if (posicio.x > iniciX + distanciaEnemic) direccio = -1;

	// 2. Límit esquerre
	if (posicio.x < iniciX - distanciaEnemic) direccio = 1;

	// 3. Apliquem la velocitat
	velocitat.x = speed * direccio;
}