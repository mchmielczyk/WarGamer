#ifndef PLAYER
#define PLAYER
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>
#include <cstdlib>
#include <climits>

// Struktura reprezentująca punkt na mapie gry
struct Point {
    int x;
    int y;
    int type;
};

// Klasa bazowa reprezentująca jednostkę w grze
class Unit
{
protected:
    int W; // Wytrzymałość
    int P; // Prędkość
    int K; // Koszt jednostki
    int Z; // Zasięg ataku
    int B; // Czas budowy
public:
    // Konstruktor
    Unit(int W, int P, int K, int Z, int B) : W(W), P(P), K(K), Z(Z), B(B) {}

    // Wirtualny destruktor
    virtual ~Unit() {}
};

// Klasy pochodne reprezentujące konkretne typy jednostek w grze

class Knight : public Unit
{
public:
    Knight() : Unit(70, 5, 400, 1, 5) {}
};

class Swordsman : public Unit
{
public:
    Swordsman() : Unit(60, 2, 250, 1, 3) {}
};

class Archer : public Unit
{
public:
    Archer() : Unit(40, 2, 250, 5, 3) {}
};

class Pikeman : public Unit
{
public:
    Pikeman() : Unit(50, 2, 200, 2, 3) {}
};

class Ram : public Unit
{
public:
    Ram() : Unit(90, 2, 500, 1, 4) {}
};

class Catapult : public Unit
{
public:
    Catapult() : Unit(50, 2, 800, 7, 6) {}
};

class Worker : public Unit
{
public:
    Worker() : Unit(20, 2, 100, 1, 2) {}
};

class Base : public Unit
{
public:
    Base() : Unit(200, 0, INT_MAX, 0, INT_MAX) {}
};

#endif