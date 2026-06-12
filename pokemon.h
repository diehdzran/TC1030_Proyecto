/*
 * Proyecto Pokemon
 * Diego Hernández Rangel
 * A01710524
 * Aqui se define la clase pokemon como
 * hija de entidad para separar funciones
 */

#ifndef POKEMON_H_
#define POKEMON_H_
#include "movimiento.h"
#include <string>
#include <vector>
#include <sstream>
#include <iostream>

//Declaracion de la clase madre
class Entidad {
protected:
  // Atributos
  std::string nombrePokemon;
  std::string tipo;
  int vidaMax;
  int vidaActual;
public:
  //Constructor vacío
  Entidad():
    nombrePokemon(""), tipo(""), vidaMax(0), vidaActual(0) {}
  //Constructor con parametros
  Entidad(std::string n, std::string t, int v):
    nombrePokemon(n), tipo(t), vidaMax(v), vidaActual(v) {}
  //Declarar Getters
  std::string getNombrePokemon();
  std::string getTipo();
  int getVidaMax();
  int getVidaActual();
  //Declarar Funciones
  void recibirDano(int d);
  void sanar(int s);
  bool estaVivo();
};
//Getters
std::string Entidad::getNombrePokemon() {
    return nombrePokemon;
}
std::string Entidad::getTipo() {
    return tipo;
}
int Entidad::getVidaMax() {
    return vidaMax;
}
int Entidad::getVidaActual() {
    return vidaActual;
}

//Funciones
// Resta vida a esta entidad y evita que sea menos de 0
void Entidad::recibirDano(int d) {
    vidaActual -= d;
    if (vidaActual < 0) {
        vidaActual = 0;
    }
}
// Cura a la entidad sin que sobrepase
void Entidad::sanar(int s) {
    vidaActual += s;
    if (vidaActual > vidaMax) {
        vidaActual = vidaMax;
    }
}
// Devuelve true si tiene más de 0 de vida
bool Entidad::estaVivo() {
    return vidaActual > 0;
}

// Clase hija
// Solo existira Charizard, Piplup y Bulbasaur
class Pokemon : public Entidad{
    private:
    int escudo;
    std::vector<Movimiento*> movimientos;
    public:
    //Constructor vacio
    Pokemon()
        : Entidad(), escudo(0), movimientos() {}
    // Constructor con parametros
    Pokemon(std::string nom, std::string tip, int v, std::vector<Movimiento*> movs)
        : Entidad(nom, tip, v), escudo(0), movimientos(movs) {}
    //Declaracion de Getters
    int getEscudo();
    //Declaracion de Funciones
    void ganarEscudo(int e);
    void resetearEscudo();
    std::string mostrarMovimientos();
    void usarMovimiento(Movimiento* mov, Pokemon* objetivo);
    std::vector<Movimiento*> getMovimientos();
};
//Getter
int Pokemon::getEscudo() {
    return escudo;
}

//Funciones
// Funcio para que el pokemon gane escudo
void Pokemon::ganarEscudo(int e) {
    escudo += e;
}

//Funcion que vuelve el escudo a 0
void Pokemon::resetearEscudo() {
    escudo = 0;
}

//Guardar en string la lista de movimientos
std::string Pokemon::mostrarMovimientos() {
    std::stringstream aux;
    aux << "Movimientos de " << nombrePokemon << ":\n";
    // Usamos un ciclo para recorre
    for (size_t i = 0; i < movimientos.size(); i++) {
        aux << i + 1 << ". " << movimientos[i]->getNombre()
           << " (" << movimientos[i]->getTipoMov() << ")\n";
    }
    return aux.str();
}

//Pokemon usa un movimiento contra otro pokemon, aqui se usa la clase
// Movimiento (polimorfismo)
void Pokemon::usarMovimiento(Movimiento* mov, Pokemon* objetivo) {
    std::cout << "¡" << nombrePokemon << " uso " << mov->getNombre() << "!" << "\n";
    // La logica aqui es, como tiene metodos virtuales que regresan 0, si no regresa
    // 0 significa que es un movimiento de ese tipo
    // 1. Daño
    if (mov->getDano() > 0) {
        float multiplicador = 1.0;

        if (getTipo() == "Fuego" && objetivo->getTipo() == "Planta")
        { multiplicador = 2.0; std::cout << "¡Es super efectivo!" << "\n"; }

        else if (getTipo() == "Fuego" && objetivo->getTipo() == "Agua")
        { multiplicador = 0.5; std::cout << "No es muy efectivo..." << "\n"; }

        else if (getTipo() == "Agua" && objetivo->getTipo() == "Fuego")
        { multiplicador = 2.0; std::cout << "¡Es super efectivo!" << "\n"; }

        else if (getTipo() == "Agua" && objetivo->getTipo() == "Planta")
        { multiplicador = 0.5; std::cout << "No es muy efectivo..." << "\n"; }

        else if (getTipo() == "Planta" && objetivo->getTipo() == "Agua")
        { multiplicador = 2.0; std::cout << "¡Es super efectivo!" << "\n"; }

        else if (getTipo() == "Planta" && objetivo->getTipo() == "Fuego")
        { multiplicador = 0.5; std::cout << "No es muy efectivo..." << "\n"; }

        int danoFinal = mov->getDano() * multiplicador;
        if (objetivo->getEscudo() > 0) {
            danoFinal = danoFinal / (1+ 0.1 * objetivo->getEscudo());
        }
        objetivo->recibirDano(danoFinal);
        std::cout << "¡" << objetivo->getNombrePokemon() << " recibio " << danoFinal << " puntos de daño!" << "\n";
    }

    // 2. Escudo
    if (mov->getPuntosEscudo() > 0) {
        ganarEscudo(mov->getPuntosEscudo());
        std::cout << "¡El escudo de " << nombrePokemon << " aumento en " << mov->getPuntosEscudo() << " puntos!" << "\n";
    }

    // 3. Curacion
    if (mov->getPuntosCuracion() > 0) {
        sanar(mov->getPuntosCuracion());
        std::cout << "¡" << nombrePokemon << " se curo " << mov->getPuntosCuracion() << " puntos de vida!" << "\n";
        std::cout << "Vida actual de " << nombrePokemon << ": " << vidaActual << "\n";
    }
}

//Para poder usar los movimientos del pokemon se tiene que acceder a estos
std::vector<Movimiento*> Pokemon::getMovimientos() {
    return movimientos;
}

#endif //POKEMON_H_
