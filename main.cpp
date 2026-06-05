/*
 * main.cpp Prueba rapida de todas las clases
 * Diego Hernández Rangel - A01710524
 */
#include "entrenador.h"
#include "movimiento.h"
#include "entidad.h"
#include <iostream>

// Los movimientos son globales por conveniencia
Movimiento* llamarada = new Ataque  ("Llamarada",  80);
Movimiento* refugio = new Defensa ("Refugio", 20);

Movimiento* surf = new Ataque  ("Surf", 70);
Movimiento* recuperar = new Curacion("Recuperar", 40);

Movimiento* latigo = new Ataque  ("Latigo", 60);
Movimiento* pantalla  = new Defensa ("Pantalla", 10);

// Funciones que ayuden a la partida (main)
std::string iniciarPartida(){
    std::string nombre;
    std::cout << "¡Felicidades, el dia de hoy empezaras tu viaje como entrenador Pokemon!"
    << " Antes de escoger tu pokemon ¿Cómo te llamas? \n";
    std::cin >> nombre;
    return nombre;
}

std::string nombrarAmigo(){
    std::string nombre;
    std::cout << "Tu primera batalla sera con tu mejor amigo."
    << " ¿Cómo se llama tu mejor amigo? \n";
    std::cin >> nombre;
    return nombre;
}

void escogerPokemon(Entrenador* jugador){
    int opcion = 0;
        while (opcion < 1 || opcion > 3) {
            std::cout << "\nEscoge tu primer pokemon:\n(1) Charizard\n(2) Squirtle\n(3) Bulbasaur\nOpción:\n";
            std::cin >> opcion;
            if (opcion < 1 || opcion > 3) {
                std::cout << "Opción inválida. Intenta de nuevo.\n";
        }
    }
    if (opcion == 1){
        jugador->capturarPokemon(new Pokemon("Charmander", "Fuego",  150, {llamarada, refugio}));
    }
    else if (opcion == 2){
        jugador->capturarPokemon(new Pokemon("Squirtle", "Agua", 120, {surf, recuperar}));
    }
    else{
        jugador->capturarPokemon(new Pokemon("Bulbasaur", "Planta", 130, {latigo, pantalla}));
    }
}

void turno(Entrenador* jugador, Entrenador* rival) {
    // Por simplicidad, como solo hay un pokemon se escoge el primero
    Pokemon* miPok = jugador->getPokemones()[0];
    Pokemon* rivPok = rival->getPokemones()[0];

    std::cout << " \n¡Turno de " << jugador->getNombre() << "! \n";
    std::cout << jugador->mostrarPokemones();
    std::cout << rival->mostrarPokemones();
    std::cout << "Selecciona un movimiento:\n";
    std::cout << miPok->mostrarMovimientos();
    std::cout << "Opción: ";

    int seleccion = 0;

        // Validación, pero solo entre 1 y 2 debido a que solo
        // hay dos movimientos por pokemon (en esta simulación)
        while (seleccion < 1 || seleccion > 2) {
            std::cin >> seleccion;
            if (seleccion < 1 || seleccion > 2) {
                std::cout << "Opción inválida. Intenta de nuevo.\n";
            }
        }

    Movimiento* movElegido = miPok->getMovimientos()[seleccion - 1];

    /*
     * Si elige 1 el objetivo es el rival y si elige 2 se lo aplica a sí mismo
     * Esto es pq en movimientos el segundo es de apoyo y el primero de Ataque
     * en esta (simulación)
     */

    if (seleccion == 1) {
        miPok->usarMovimiento(movElegido, rivPok);
    } else {
        miPok->usarMovimiento(movElegido, miPok);
    }

    // Si el oponente se debilita, terminamos el turno inmediatamente
    if (!rivPok->estaVivo()) {
        std::cout << "\n¡El " << rivPok->getNombrePokemon() << " de " << rival->getNombre() << " se ha debilitado!\n";
        return;
    }

    // Turno del rival
    std::cout << "¡Turno de " << rival->getNombre() << "!" << "\n";
    Movimiento* movRival = rivPok->getMovimientos()[0]; // Solo ataca
    rivPok->usarMovimiento(movRival, miPok);

    if (!miPok->estaVivo()) {
        std::cout << "\n¡Tu " << miPok->getNombrePokemon() << " se ha debilitado!\n";
    }
}

int main() {
    // Inicializaciones
    std::string nombreJugador = iniciarPartida();
    Entrenador* Jugador  = new Entrenador(nombreJugador,  {});
    escogerPokemon(Jugador);
    std::string nombreAmigo = nombrarAmigo();
    Entrenador* mejorAmigo = new Entrenador(nombreAmigo, {new Pokemon("Piplup", "Agua", 120, {surf, recuperar})});

    while (Jugador->tienePokemonVivo() && mejorAmigo->tienePokemonVivo()) {
            turno(Jugador, mejorAmigo);
        }

        // Declarar ganador
        if (Jugador->tienePokemonVivo()) {
            std::cout << "¡Felicidades " << Jugador->getNombre() << ", ganaste tu primera batalla!\n";
        } else {
            std::cout << "¡Fin del juego! " << mejorAmigo->getNombre() << " te ha superado esta vez...\n";
        }

    return 0;
}
