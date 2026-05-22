#ifndef ENTIDAD_H_
#define ENTIDAD_H_

#include"movimiento.h"

#include <string>
#include <vector>
#include <sstream>

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
    nombrePokemon(""), tipo(""), vidaMax(0), vidaActual(0){};

  //Constructor con parametros
  Entidad(std::string n, std::string t, int vM, int vA):
    nombrePokemon(n), tipo(t), vidaMax(vM), vidaActual(vA){};

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
std::string Entidad::getNombrePokemon() { return nombrePokemon; }
std::string Entidad::getTipo() { return tipo; }
int Entidad::getVidaMax(){ return vidaMax; }
int Entidad::getVidaActual(){ return vidaActual; }

//Funciones
// Resta vida a esta entidad y evita que baje de 0
void Entidad::recibirDano(int d) {
    vidaActual -= d;
    if (vidaActual < 0) {
        vidaActual = 0;
    }
}
// Cura a la entidad sin que sobrepase su vida máxima
void Entidad::sanar(int s) {
    vidaActual += s;
    if (vidaActual > vidaMax) {
        vidaActual = vidaMax;
    }
}
// Devuelve true si tiene más de 0 de vida, false si llegó a 0
bool Entidad::estaVivo() {
    return vidaActual > 0;
}

//Clase hija
class Pokemon : public Entidad{
    private:
    int escudo;
    std::vector<Movimiento> movimientos

    public:
    //Constructor vacio
    Pokemon()
        : nombre(""), vidaMax(0), vidaActual(0), movimientos() {};
    // Constructor con parametros
    Pokemon(std::string nom, int v, std::vector<Movimiento> listaMovs)
        : nombre(nom), vidaMax(v), vidaActual(v), movimientos(listaMovs) {};

    //Declaracion de Getters
    int getEscudo();

    //Declaracion de Funciones
    std::string mostrarMovimientos();
    void ganarEscudo(int e);
    void resetearEscudo();
};
//Getter
int Pokemon::getEscudo() { return escudo; }

//Funciones
void mostrarMovimientos(){
    std::stringstream aux;
        aux << "Movimientos de " << nombre << "\n";
        // Usamos un ciclo para recorrer el vector
        for (int i = 0; i < movimientos.size(); ++i) {
            aux << i + 1 << ". " << movimientos[i].getNombre()
               << " (" << movimientos[i].getTipo() << ")\n";
        }
        return aux.str();
}

void ganarEscudo(int e){
    escudo += e;
}

void resetearEscuro(){
    escudo = 0;
}

#endif //ENTIDAD_H_
