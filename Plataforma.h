// PROGRAMA --> MOTOR DE VIDEOJOCS
// AUTOR --> Pablo Abad Ortega
// DATA --> 3/2/2026

#include <SFML/Graphics.hpp>    
#include <vector>
#include <fstream>
#include <iostream>
#include <string>
#include "GameObject.h"

using namespace std;
using namespace sf;

// Classe per a plataformes (també hereta de GameObject)
class Plataforma : public GameObject
{
public:
    Plataforma(float x, float y, float width, float height);
    Plataforma(float x, float y);
    void actualitzacio(float dt) override;
};

// Classe per gestionar el mapa complet de plataformes
class MapaPlataformes
{
private:
    std::vector<Plataforma> Plataformas;
    const int TILE_SIZE = 40;
    Vector2f PosicioInicialJugador;
    Plataforma objectiu;

public:
    MapaPlataformes();
    // Carrega el mapa des d'un fitxer
    bool carregaDesdeFitxer(const std::string& filename, RenderWindow& window);

    // Getters
    const std::vector<Plataforma>& getPlataforma() const;
    Vector2f getPosicioInicialJugador() const;
    Plataforma getobjectiu();

    // Dibuixa totes les plataformes
    void dibuixar(RenderWindow& window);

    // Actualitza totes les plataformes (per si hi ha plataformes mòbils)
    void actualitzacio(float dt);
};