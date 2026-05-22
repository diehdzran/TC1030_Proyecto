/*
 * Proyecto Pokemon Roguelike
 * Diego Hernández Rangel
 * A01710524
 * 21/05/26
 * Esta clase define los movimientos de los pokemones y las clases heredadas
 * Atque, Defensa, Curación
 */
#ifndef MOVIMIENTO_H_
#define MOVIMIENTO_H_
#include "entidad.h"

#include <string>

//Declaracion de la clase madre
class Movimiento {
protected:
  // Atributos
  std::string nombre;
  std::string tipo;

public:
  //Constructor vacío
  Movimiento():
    nombre(""), tipo(""){};

  //Constructor con parametros
  Movimiento(std::string n, std::string t):
    nombre(n), tipo(t){};

  //Declarar Getters
  std::string getNombre();
  std::string getTipo();

  //Funcion usar
  void usar(Pokemon* usuario, Pokemon* objetivo);
};

//Funciones
std::string Movimiento::getNombre() { return nombre; }
std::string Movimiento::getTipo() { return tipo; }


//Clase de ataque
class Ataque : public Movimiento{
    private:
    int daño;

    public:
    //Constructor vacio
    Ataque() : Movimiento(), daño(0) {};

    //Constructor con parametros
    Ataque(std::string n, std::string t, int d) : Movimiento(n, t), daño(d) {};

    //Funcion sobreescrita
    void usar(Pokemon* usuario, Pokemon* objetivo);

};

void Ataque::usar(Pokemon* usuario, Pokemon* objetivo) {
    std::cout << "¡" << usuario->getNombre() << " uso " << nombre << "!" << "\n";

    float multiplicador = 1.0;

    if (tipo == "Fuego" && objetivo->getTipo() == "Planta") {
        multiplicador = 2.0;
        std::cout << "¡Es super efectivo!" << "\n";
    }
    else if (tipo == "Fuego" && objetivo->getTipo() == "Agua") {
        multiplicador = 0.5;
        std::cout << "No es muy efectivo..." << "\n";
    }

    else if (tipo == "Agua" && objetivo->getTipo() == "Fuego") {
        multiplicador = 2.0;
        std::cout << "¡Es super efectivo!" << "\n";
    }
    else if (tipo == "Agua" && objetivo->getTipo() == "Planta") {
        multiplicador = 0.5;
        std::cout << "No es muy efectivo..." << "\n";
    }

    else if (tipo == "Planta" && objetivo->getTipo() == "Agua") {
        multiplicador = 2.0;
        std::cout << "¡Es super efectivo!" << "\n";
    }
    else if (tipo == "Planta" && objetivo->getTipo() == "Fuego") {
        multiplicador = 0.5;
        std::cout << "No es muy efectivo..." << "\n";
    }

    int danoFinal = dano * multiplicador;

    objetivo->recibirDano(danoFinal);

    std::cout << "¡El enemigo " << objetivo->getNombre() << " recibio " << danoFinal << " puntos de daño!" << "\n";
}

// Clase de defensa
class Defensa : public Movimiento {
private:
    int puntosEscudo;

public:
    // Constructor vacio
    Defensa() : Movimiento(), puntosEscudo(0) {};

    // Constructor con parametros
    Defensa(std::string n, std::string t, int e) : Movimiento(n, t), puntosEscudo(e) {};

    // Funcion
    void usar(Pokemon* usuario, Pokemon* objetivo);
};

void Defensa::usar(Pokemon* usuario, Pokemon* objetivo) {
    std::cout << "¡" << usuario->getNombre() << " uso " << nombre << "!" << "\n";

    usuario->ganarEscudo(puntosEscudo);

    std::cout << "¡El escudo de " << usuario->getNombre() << " aumento en " << puntosEscudo << " puntos!" << "\n";
}

// Clase de curacion
class Curacion : public Movimiento {
private:
    int puntosCuracion;

public:
    // Constructor vacio
    Curacion() : Movimiento(), puntosCuracion(0) {};

    // Constructor con parametros
    Curacion(std::string n, std::string t, int c) : Movimiento(n, t), puntosCuracion(c) {};

    // Funcion
    void usar(Pokemon* usuario, Pokemon* objetivo);
};

void Curacion::usar(Pokemon* usuario, Pokemon* objetivo) {
    std::cout << "¡" << usuario->getNombre() << " uso " << nombre << "!" << "\n";

    // Aplicamos la curación al USUARIO
    usuario->sanar(puntosCuracion);

    // Mostramos cómo quedó su barra de vida actual
    std::cout << "¡" << usuario->getNombre() << " se curo " << puntosCuracion << " puntos de vida!" << "\n";
    std::cout << "Vida actual de " << usuario->getNombre() << ": " << usuario->getVidaActual() << "\n";
}

#endif // MOVIMIENTO_H_
