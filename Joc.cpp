// PROGRAMA --> MOTOR DE VIDEOJOCS
// AUTOR --> Pablo Abad Ortega
// DATA --> 3/2/2026

#include "Joc.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;
using namespace sf;

// CONSTRUCTOR
Joc::Joc() :
    window(VideoMode({ 800u, 600u }), "JOC DE PLATAFORMES AMB C++"),
    jugador(100.0f, 100.0f),
    pablito(200.0f, 100.0f),
    font("KOMIKAP_.ttf"),
    instruccionsText(font),
    textPausa(font),
    hudText(font),
    jocEnPausa(false),
    vides(3),
    puntuacio(0),
    acumulacioTemps(0.0f),
    puntuacioAlta(0),
    ultimNivell(1)
{
    // Carregar estat anterior des de fitxer
    carregarPartida();

    window.setFramerateLimit(60);

    // Configuració de textos i interfície (HUD)
    textPausa.setString("JOC EN PAUSA\nPrem P per continuar");
    textPausa.setCharacterSize(40);
    textPausa.setFillColor(Color::Red);
    textPausa.setPosition({ 250.0f, 250.0f });

    hudText.setCharacterSize(18);
    hudText.setFillColor(Color::Blue);
    hudText.setPosition({ 10.0f, 75.0f });

    instruccionsText.setString("Thomas: WASD | Pablito: Fletxes\nArribeu els dos a la meta!\nEnemics: Vermells | P: Pausa");
    instruccionsText.setCharacterSize(16);
    instruccionsText.setFillColor(Color::Black);
    instruccionsText.setPosition({ 10.0f, 10.0f });

    // Càrrega dinàmica del nivell segons el progrés guardat
    string nomFitxer = "level" + to_string(ultimNivell) + ".txt";
    if (carregadorNivells.carregaDesdeFitxer(nomFitxer, window))
    {
        Vector2f posInici = carregadorNivells.getPosicioInicialJugador();
        jugador.setPosicio(posInici.x, posInici.y);
        pablito.setPosicio(posInici.x + 50.0f, posInici.y);
    }

    // 4. Enemics inicials
    enemics.push_back(new Enemic(400.0f, 300.0f, 100.0f));
    enemics.push_back(new Enemic(600.0f, 300.0f, 120.0f));
}

// DESTRUCTOR
Joc::~Joc()
{
    if (puntuacio > puntuacioAlta) puntuacioAlta = puntuacio;
    guardarPartida();

    for (auto e : enemics)
    {
        delete e;
    }
    enemics.clear();
}

// GAME LOOP
void Joc::run()
{
    while (window.isOpen())
    {
        float dt = rellotge.restart().asSeconds();
        controlarEntrada();
        actualitzacio(dt);
        draw();
    }
}

// SISTEMA D'ENTRADES: Teclat i esdeveniments de finestra
void Joc::controlarEntrada()
{
    while (const std::optional event = window.pollEvent())
    {
        if (event->is<Event::Closed>()) window.close();

        if (const auto* key = event->getIf<Event::KeyPressed>())
        {
            if (key->scancode == Keyboard::Scancode::Escape) window.close();
            if (key->scancode == Keyboard::Scancode::P) jocEnPausa = !jocEnPausa;
        }
    }

    if (!jocEnPausa)
    {
        jugador.controlarEntrada();
        pablito.controlarEntrada();
    }
}
// Actualització d'estats
void Joc::actualitzacio(float dt)
{
    if (jocEnPausa) return;
    acumulacioTemps += dt;

    jugador.actualitzacio(dt, (float)window.getSize().x, (float)window.getSize().y);
    pablito.actualitzacio(dt, (float)window.getSize().x, (float)window.getSize().y);

    string informacioHUD = "VIDES: " + to_string(vides) +
        " | PUNTS: " + to_string(puntuacio) +
        " | TEMPS: " + to_string((int)acumulacioTemps) + "s" +
        " | RECORD: " + to_string(puntuacioAlta);
    hudText.setString(informacioHUD);

    for (auto e : enemics)
    {
        e->controlarEntrada();
        e->actualitzacio(dt, (float)window.getSize().x, (float)window.getSize().y);
    }
    carregadorNivells.actualitzacio(dt);

    comprovarColisions(jugador);
    comprovarColisions(pablito);
    for (auto e : enemics)
    {
        comprovarColisions(*e);
    }
    comprovarObjectiu(carregadorNivells.getobjectiu());
}

// RENDERITZAT
void Joc::draw()
{
    window.clear(Color::White);

    carregadorNivells.dibuixar(window);
    jugador.dibuixar(window);
    pablito.dibuixar(window);

    for (auto e : enemics) e->dibuixar(window);

    window.draw(instruccionsText);
    window.draw(hudText);

    if (jocEnPausa) window.draw(textPausa);

    window.display();
}

// COL·LISIONS
void Joc::comprovarColisions(Personatge& p)
{
    FloatRect limits_caracter = p.getLimits();
    const vector<Plataforma>& conjuntPlataformes = carregadorNivells.getPlataforma();

    for (const auto& plataforma : conjuntPlataformes)
    {
        FloatRect limits_plataforma = plataforma.getLimits();
        if (const std::optional intersection = limits_caracter.findIntersection(limits_plataforma))
        {
            if (limits_caracter.position.y < limits_plataforma.position.y &&
                limits_caracter.position.y + limits_caracter.size.y < limits_plataforma.position.y + 15.0f)
            {
                p.stopFalling(limits_plataforma.position.y - limits_caracter.size.y);
            }
        }
    }
}

// Canvi de nivell
void Joc::comprovarObjectiu(Plataforma objectiu)
{
    if (jugador.getLimits().findIntersection(objectiu.getLimits()) &&
        pablito.getLimits().findIntersection(objectiu.getLimits()))
    {
        puntuacio += 500;
        if (ultimNivell == 1)
        {
            ultimNivell = 2;
            if (carregadorNivells.carregaDesdeFitxer("level2.txt", window))
            {
                Vector2f posInici = carregadorNivells.getPosicioInicialJugador();
                jugador.setPosicio(posInici.x, posInici.y);
                pablito.setPosicio(posInici.x + 50.0f, posInici.y);

                for (auto e : enemics) delete e;
                enemics.clear();
                enemics.push_back(new Enemic(200.0f, 200.0f, 150.0f));
            }
        }
        else
        {
            std::cout << "HAS GUANYAT EL JOC!" << std::endl;
        }
    }
}

// PERSISTÈNCIA (Sortida)
void Joc::guardarPartida() const
{
    ofstream fitxerSortida("save.dat");
    if (fitxerSortida.is_open())
    {
        fitxerSortida << puntuacioAlta << endl;
        fitxerSortida << ultimNivell << endl;
        fitxerSortida.close();
    }
}

// PERSISTÈNCIA (Entrada)
void Joc::carregarPartida()
{
    ifstream fitxerEntrada("save.dat");
    if (fitxerEntrada.is_open())
    {
        fitxerEntrada >> puntuacioAlta;
        fitxerEntrada >> ultimNivell;
        fitxerEntrada.close();
    }
}