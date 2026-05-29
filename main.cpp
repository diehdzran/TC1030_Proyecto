/*
 * main.cpp Prueba rapida de todas las clases
 * Diego Hernández Rangel - A01710524
 */
#include "entrenador.h"
#include "movimiento.h"
#include "entidad.h"
#include <iostream>

int main() {

    // Movimientos
    Movimiento* llamarada = new Ataque  ("Llamarada",   "Fuego",  80);
    Movimiento* refugio   = new Defensa ("Refugio",     "Normal", 30);

    Movimiento* surfear   = new Ataque  ("Surf",        "Agua",   70);
    Movimiento* recuperar = new Curacion("Recuperar",   "Normal", 40);

    Movimiento* latigo    = new Ataque  ("Latigo Cepa", "Planta", 65);
    Movimiento* pantalla  = new Defensa ("Pantalla",    "Normal", 25);

    // Pokemones
    Pokemon* charizard = new Pokemon("Charizard", "Fuego",  150, {llamarada, refugio});
    Pokemon* piplup    = new Pokemon("Piplup",    "Agua",   120, {surfear,   recuperar});
    Pokemon* bulbasaur = new Pokemon("Bulbasaur", "Planta", 130, {latigo,    pantalla});

    // Entrenadores
    Entrenador* ash  = new Entrenador("Ash",  {charizard, bulbasaur});
    Entrenador* gary = new Entrenador("Gary", {piplup});

    // Estado inicial
    std::cout << "Estado inicial\n";
    std::cout << ash->mostrarPokemones();
    std::cout << gary->mostrarPokemones();

    // Combate de prueba
    std::cout << "\nCombate! \n";

    // Fuego vs agua, no efectvo
    charizard->usarMovimiento(llamarada, piplup);

    // Probar si si jala el ganar escudo
    charizard->usarMovimiento(refugio, charizard);

    // Agua vs fuego, efectivo
    piplup->usarMovimiento(surfear, charizard);

    // Piplup se cura
    piplup->usarMovimiento(recuperar, piplup);

    // Planta vs agua efectivo
    bulbasaur->usarMovimiento(latigo, piplup);

    // 6. Estado final
    std::cout << "\nEstado Final \n";
    std::cout << ash->mostrarPokemones();
    std::cout << gary->mostrarPokemones();

    std::cout << "¿Ash tiene pokemon vivo?  " << (ash->tienePokemonVivo()  ? "Si" : "No") << "\n";
    std::cout << "¿Gary tiene pokemon vivo? " << (gary->tienePokemonVivo() ? "Si" : "No") << "\n";

    // Liberar memoria
    delete ash;
    delete gary;

    delete charizard;
    delete piplup;
    delete bulbasaur;

    delete llamarada;
    delete refugio;
    delete surfear;
    delete recuperar;
    delete latigo;
    delete pantalla;

    return 0;
}
