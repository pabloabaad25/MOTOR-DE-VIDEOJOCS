#include "GameObject.h"

using namespace std;
using namespace sf;

// Constructor amb posició, amplada i alçada
GameObject::GameObject(float x, float y, float amplada, float alcada)
{
    posicio = Vector2f(x, y);
    forma.setSize(Vector2f(amplada, alcada));
    forma.setPosition(posicio);
}

// Dibuixa l'objecte a la finestra
void GameObject::dibuixar(RenderWindow& finestra)
{
    finestra.draw(forma);
}

// Retorna l'àrea de col·lisió (bounding box)
FloatRect GameObject::getLimits() const
{
    return forma.getGlobalBounds();
}

// Obté la posició actual de l'objecte
Vector2f GameObject::getPosicio() const
{
    return posicio;
}

// Canvia la ubicació de l'objecte
void GameObject::setPosicio(float x, float y)
{
    posicio = Vector2f(x, y);
    forma.setPosition(posicio);
}