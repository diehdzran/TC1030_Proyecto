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
#include <iostream>
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
    nombre(""), tipo(""){}

  //Constructor con parametros
  Movimiento(std::string n, std::string t):
    nombre(n), tipo(t){}

  //Declarar Getters
  std::string getNombre();
  std::string getTipo();

  // Métodos virtuales
  virtual int getDano() { return 0; }
  virtual int getPuntosEscudo() { return 0; }
  virtual int getPuntosCuracion() { return 0; }
};

//Getters
std::string Movimiento::getNombre() { return nombre; }
std::string Movimiento::getTipo() { return tipo; }

//Clase de ataque
class Ataque : public Movimiento{
    private:
    int dano;

    public:
    //Constructor vacio
    Ataque() : Movimiento(), dano(0) {};

    //Constructor con parametros
    Ataque(std::string n, std::string t, int d) : Movimiento(n, t), dano(d) {};

    // Sobreescribe para regresar su daño
    int getDano();
};

int Ataque::getDano(){
    return dano;
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

    // Sobreescribe para regresar su escudo
    int getPuntosEscudo();
};

int Defensa::getPuntosEscudo(){
    return puntosEscudo;
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

    // Sobreescribe para regresar su curación
    int getPuntosCuracion();
};

int Curacion::getPuntosCuracion(){
    return puntosCuracion;
}

#endif // MOVIMIENTO_H_
