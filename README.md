# Motor de Videojocs SFML - Ampliació

**Autor:** Pablo Abad Ortega  
**Data:** 03/02/2026  

---

## Millores que he posat

### 1. Nou Personatge: `Pablito`
* **Herència:** Creat a partir de la classe `Personatge`.
* **Controls:** Fletxes de direcció (diferents dels de Thomas).
* **Atributs:** Velocitat i salt personalitzats; color Magenta.

### 2. Sistema d'Enemics
* **Gestió Dinàmica:** Ús de punters (`Enemic*`) i `std::vector` per a múltiples enemics.
* **Cicle de vida:** Actualització, dibuix i alliberament de memòria dinàmica.

### 3. Sistema de Pausa
* **Control:** Tecla **P** per aturar la lògica.
* **Feedback:** Bloqueig de moviment i col·lisions amb avís visual a pantalla.

### 4. HUD (Interfície)
* **Informació:** Vides, Puntuació, Temps de joc i Rècord.
* **Temps Real:** Actualització constant dels valors al frame.



---

## Persistència (Save/Load)
* **Dades desades:** Puntuació màxima i últim nivell assolit (`save.dat`).
* **Justificació:** Es guarda el **HighScore** per reptar el jugador i el **Nivell** per mantenir la progressió entre partides.

---

## Arquitectura POO
* **Herència:** `GameObject` → `Personatge` → `Pablito` / `Tomas`.
* **Polimorfisme:** Mètodes virtuals per a entrades i actualitzacions.
* **Encapsulament:** Lògica centralitzada a la classe `Joc`.
