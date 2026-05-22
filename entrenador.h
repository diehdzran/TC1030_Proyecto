#ifndef ENTRENADOR_H_
#define ENTRENADOR_H_

#include <string>

class Entrenador {
private:
  // Atributos
  std::string nombre;
  std::vector<Pokemon> Pokemones;

public:
  //Constructor vacío
  Entrenador():
    nombre(""), Pokemones(){};

  //Constructor con parametros
  Entrenador(std::string n, std::vector<Pokemon> listaPok):
    nombre(n), Pokemones(listaPok){};

  //Declarar Getters
  std::string getNombre();
  std::string mostrarPokemones();

  //Declarar Funciones
  void capturarPokemon(Pokemon p);
  bool tienePokemonVivo();

};

//Getters
std::string Entrenador::getNombre(){
    return nombre;
}
std::string Entrenador::mostrarPokemones(){
    std::stringstream aux;
        aux << "Pokemones de " << nombre << "\n";
        // Usamos un ciclo para recorrer el vector
        for (int i = 0; i < Pokemones.size(); ++i) {
            aux << i + 1 << ". " << Pokemones[i].getNombre()
               << " (" << Pokemones[i].getTipo() << ")\n";
        }
        return aux.str();
}

//Funciones
void Entrenador::capturarPokemon(Pokemon p) {
    Pokemones.push_back(p);
}
bool Entrenador::tienePokemonVivo() {
    for (int i = 0; i < Pokemones.size(); ++i) {
        if (Pokemones[i].getVidaActual() > 0) {
            return true;
        }
    }
    return false;
}

#endif //ENTRENADOR_H_
