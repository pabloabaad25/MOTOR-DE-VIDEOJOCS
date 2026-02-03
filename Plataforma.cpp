// PROGRAMA --> MOTOR DE VIDEOJOCS
// AUTOR --> Pablo Abad Ortega
// DATA --> 3/2/2026

#include "Plataforma.h"

using namespace std;
using namespace sf;

// CONSTRUCTOR DE PLATAFORMA 
Plataforma::Plataforma(float x, float y, float width, float height) : GameObject(x, y, width, height)
{
    forma.setFillColor(Color(100, 100, 100));
}

// Sobrecàrrega del constructor
Plataforma::Plataforma(float x, float y) : GameObject(x, y, 50, 50)
{
    forma.setFillColor(Color::Yellow);
}

void Plataforma::actualitzacio(float dt)
{
    // Les plataformes no es mouen
}

// CLASSE MAPA
MapaPlataformes::MapaPlataformes() : objectiu(150, 150)
{
    PosicioInicialJugador = Vector2f(100, 100);
}

Plataforma MapaPlataformes::getobjectiu()
{
    return objectiu;
}

// CARREGA DEL NIVELL
bool MapaPlataformes::carregaDesdeFitxer(const std::string& filename, RenderWindow& window)
{
    Plataformas.clear();
    std::ifstream file(filename);

    if (!file.is_open())
    {
        std::cout << "No s'ha pogut obrir el fitxer: " << filename << std::endl;
        std::cout << "Creant mapa per defecte..." << std::endl;
        return false;
    }

    std::string line;
    int y = 0;
    int xtotal = 0;

    std::cout << "Carregant mapa des de: " << filename << std::endl;

    while (std::getline(file, line))
    {
        for (int x = 0; x < line.length(); x++)
        {
            char tile = line[x];
            xtotal = x * TILE_SIZE;
            if (tile == '1')
            {
                // Crea una plataforma
                Plataformas.push_back(Plataforma(
                    x * TILE_SIZE,
                    y * TILE_SIZE,
                    TILE_SIZE,
                    TILE_SIZE
                ));
            }

            else if (tile == 'P')
            {
                // Marca la posició inicial del jugador
                PosicioInicialJugador.x = x * TILE_SIZE;
                PosicioInicialJugador.y = y * TILE_SIZE;
                std::cout << "  Posició jugador: (" << x << ", " << y << ")" << std::endl;
            }

            else if (tile == 'G')
            {
                // Marca la posició de la meta
                objectiu.setPosicio(x * TILE_SIZE, y * TILE_SIZE);
                std::cout << "  Posició meta: (" << x << ", " << y << ")" << std::endl;
            }
        }
        y++;
    }
    file.close();
    std::cout << "Mapa carregat: " << Plataformas.size() << " plataformes" << std::endl;
    return true;
}

// GETTERS 
const std::vector<Plataforma>& MapaPlataformes::getPlataforma() const
{
    return Plataformas;
}

// RENDERITZAT 
Vector2f MapaPlataformes::getPosicioInicialJugador() const
{
    return PosicioInicialJugador;
}

// Dibuixa totes les plataformes
void MapaPlataformes::dibuixar(RenderWindow& window)
{
    for (auto& platform : Plataformas)
    {
        platform.dibuixar(window);
    }
    objectiu.dibuixar(window);

}

// ACTUALITZACIÓ 
void MapaPlataformes::actualitzacio(float dt)
{
    for (auto& platform : Plataformas)
    {
        platform.actualitzacio(dt);
    }
}