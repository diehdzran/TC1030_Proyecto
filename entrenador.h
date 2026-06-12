/*
 * Proyecto Pokemon
 * Diego Hernández Rangel
 * A01710524
 * Aqui se define la clase entrenador
 * que tiene varios pokemones
 */

#ifndef ENTRENADOR_H_
#define ENTRENADOR_H_

#include "pokemon.h"
#include <string>
#include <vector>
#include <sstream>

class Entrenador {
    private:
    // Atributos
    std::string nombre;
    std::vector<Pokemon*> Pokemones;

    public:
    //Constructor vacío
    Entrenador():
        nombre(""), Pokemones(){}

    //Constructor con parametros
    Entrenador(std::string n, std::vector<Pokemon*> listaPok):
        nombre(n), Pokemones(listaPok){}

    //Declarar Getters
    std::string getNombre();
    std::string mostrarPokemones();

    //Declarar Funciones
    void capturarPokemon(Pokemon* p);
    bool tienePokemonVivo();
    std::vector<Pokemon*> getPokemones();

};

//Getters
std::string Entrenador::getNombre(){
    return nombre;
}

//Guardar la lista de pokemones en un string
std::string Entrenador::mostrarPokemones(){
    std::stringstream aux;
        aux << "Pokemones de " << nombre << "\n";
        // Usamos un ciclo para recorrer el vector
        for (int i = 0; i < Pokemones.size(); ++i) {
            aux << i + 1 << ". " << Pokemones[i]->getNombrePokemon()
               << " (" << Pokemones[i]->getTipo() << ")"
              << " Con " << Pokemones[i]->getVidaActual() << " puntos de vida! \n";
        }
        return aux.str();
}

//Funciones
// Agregar un nuevo pokemon al vector de pokemones
void Entrenador::capturarPokemon(Pokemon* p) {
    Pokemones.push_back(p);
}

//Regresa true si hay algun pokemon con vida mayor a 0
bool Entrenador::tienePokemonVivo() {
    for (int i = 0; i < Pokemones.size(); ++i) {
        if (Pokemones[i]->getVidaActual() > 0) {
            return true;
        }
    }
    return false;
}

//Para poder usar pokemones es necesario tener acceso al vector
std::vector<Pokemon*> Entrenador::getPokemones() {
    return Pokemones;
}

#endif //ENTRENADOR_H_
