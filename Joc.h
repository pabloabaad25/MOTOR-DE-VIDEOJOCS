// PROGRAMA --> MOTOR DE VIDEOJOCS
// AUTOR --> Pablo Abad Ortega
// DATA --> 3/2/2026

#pragma warning(disable : 4275) // Desactiva l'avís de la interfície DLL
#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Tomas.h"
#include "Pablito.h"
#include "Enemic.h"
#include "Plataforma.h"

using namespace std;
using namespace sf;

// CLASSE JOC
class Joc
{
private: 
    // Finestra i Renderitzat
    sf::RenderWindow window;

    // Entitats del Joc 
    Tomas jugador;
    Pablito pablito;
    std::vector<Enemic*> enemics;

    // Sistema de joc
    sf::Clock rellotge;
    sf::Font font;
    sf::Text instruccionsText;
    sf::Text textPausa;
    bool jocEnPausa;

    // Dades de la Partida (Estat i Persistència) 
    int vides;
    int puntuacio;
    float acumulacioTemps;
    int puntuacioAlta;
    int ultimNivell;

    // Gestió de Fitxers
    void guardarPartida() const;
    void carregarPartida();

    // Interfície d'Usuari (HUD)
    sf::Text hudText;

    // Nivells 
    MapaPlataformes carregadorNivells;

public:
    // Mètodes Públics
    Joc();
    ~Joc();
    void run();

private:
    // Lògica Interna
    void controlarEntrada();
    void actualitzacio(float dt);
    void draw();
    void comprovarColisions(Personatge& p);
    void comprovarObjectiu(Plataforma objectiu);
};