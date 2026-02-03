#ifndef ENEMIC_H
#define ENEMIC_H

#include "Personatge.h"
// Classe Enemic: Defineix el comportament d'un adversari
class Enemic : public Personatge
{
private:
	// ATRIBUTS DE CONTROL DE MOVIMENT
	float distanciaEnemic;
	float iniciX;
	int direccio; 
public:
	// Constructor
	Enemic(float x, float y, float spd);

	// Sobreescriptura del mètode
	void controlarEntrada() override;
};

#endif 
