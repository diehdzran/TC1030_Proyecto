# TC1030_Proyecto 
Este proyecto trata sobre un sistema de batalla de cartas entre un Jugador y un Jefe. Genera una estructura de clases para manejar diferentes tipos de cartas: Cartas de ataque (restan vida al jefe), cartas de defensa (suman escudo al jugador) y cartas de curación (restan daño recibido). Cada turno el jugador tendra una nueva carta que pueda usar y tras acabar su turno agregara una carta al azar al usuario.

## Funcionalidad
El programa gestiona el flujo de la batalla, permitiendo al usuario elegir sus acciones desde su mano:
- Acciones de Ataque: Reducen la vida del jefe.
- Acciones de Defensa: Aumentan el escudo para mitigar golpes.
- Acciones de Curación: Recuperan salud perdida.

También consta de un menú interactivo para seleccionar las cartas de la mano y mostrar el estado de la batalla en la consola.

## Consideraciones

El programa solo corre en la consola y esta hecho con c++ standard por lo que corre en todos los sistemas operativos compilar con: 

"g++ ..."

- correr en linux: "/a.out"
- correr en windows: "a.exe"
