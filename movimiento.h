/*
 * Proyecto Pokemon
 * Diego Hernández Rangel
 * A01710524
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

public:
  //Constructor vacío
  Movimiento():
    nombre(""){}

  //Constructor con parametros
  Movimiento(std::string n):
    nombre(n){}

  //Declarar Getters
  std::string getNombre();

  // Métodos virtuales
  virtual int getDano();
  virtual int getPuntosEscudo();
  virtual int getPuntosCuracion();

  // Función para volverlo abstracta
  virtual std::string getTipoMov()=0;
};

int Movimiento::getDano() { return 0; }
int Movimiento::getPuntosEscudo() { return 0; }
int Movimiento::getPuntosCuracion() { return 0; }


//Getters
std::string Movimiento::getNombre() { return nombre; }

//Clase de ataque
class Ataque : public Movimiento{
    private:
    int dano;

    public:
    //Constructor vacio
    Ataque() : Movimiento(), dano(0) {};

    //Constructor con parametros
    Ataque(std::string n, int d) : Movimiento(n), dano(d) {};

    // Sobreescribe para regresar su daño
    int getDano();

    // Sobrescritura de la funcion abstracta
    virtual std::string getTipoMov();
};
std::string Ataque::getTipoMov(){
    return "Ataque";
}

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
    Defensa(std::string n, int e) : Movimiento(n), puntosEscudo(e) {};

    // Sobreescribe para regresar su escudo real
    int getPuntosEscudo();

    //Sobrescritura de la funcion abstracta
    virtual std::string getTipoMov();
};
std::string Defensa::getTipoMov(){
    return "Defensa";
}

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
    Curacion(std::string n, int c) : Movimiento(n), puntosCuracion(c) {};

    // Sobreescribe para regresar su curación real
    int getPuntosCuracion();

    //Sobrescritura de la funcion abstracta
    virtual std::string getTipoMov();
};
std::string Curacion::getTipoMov(){
    return "Curación";
}

int Curacion::getPuntosCuracion(){
    return puntosCuracion;
}

#endif // MOVIMIENTO_H_
