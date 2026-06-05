# TC1030_Proyecto - Pokémon
Este proyecto consiste en un sistema de batalla Pokémon en consola. El sistema cuenta con una estructura de clases que gestiona Entrenadores y Pokémon. Los Pokémon pueden aprender distintos tipos de Movimientos heredados: Ataque (hacen daño con multiplicadores por tipo), Defensa (generan un escudo para mitigar golpes) y Curación (recuperan vida actual).

## Funcionalidad
El programa gestiona el flujo de la batalla por turnos, permitiendo al Entrenador elegir las acciones de su Pokémon desde su lista de movimientos:
- Movimientos de Ataque
- Movimientos de Defensa
- Movimientos de Curación

También consta de un menú interactivo en consola para mostrar el estado de la batalla (vida, escudos y movimientos disponibles).

## Casos donde el código podría fallar

1. **Pokémon Derrotados:** Realmente nunca se quita los Pokemón derrotados, por lo que siguen en el vector dentro de entrenador, lo que podría causar problemas de lógica.
2. **Sensibilidad a Mayúsculas:** El cálculo de ventajas y descentajas por el tipo del Pokemón depende de comparaciones de texto ("Fuego", "Agua", "Planta").

## Consideraciones

El programa solo corre en la consola y está hecho con C++ estándar, por lo que funciona en todos los sistemas operativos. 

Para compilar, usa el siguiente comando en tu terminal:

g++ main.cpp
- correr en linux: "/a.out"
- correr en windows: "a.exe"
