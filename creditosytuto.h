#include <iostream>
#include <string>
#include "Juego.h"
using namespace std;

void tutorial(Jugador *tail)
{
    cout << "===== TUTORIAL: PIEDRA, PAPEL O TIJERA =====" << endl
         << endl;

    cout << "Piedra, Papel o Tijera es un juego sencillo que se juega entre dos o mas jugadores." << endl;
    cout << "El juego funciona con la siguiente logica: " << endl;
    cout << "1. Todos los jugadores reciben una jugada aleatoria." << endl;
    cout << "2. Se determina cual es la jugada ganadora." << endl;
    cout << "3. Los jugadores que no tengan la jugada ganadora son eliminados." << endl;
    cout << "4. Si quedan varios jugadores con la jugada ganadora, se repite la ronda." << endl;
    cout << "5. El ultimo jugador que quede sin ser eliminado es el ganador y suma una cantidad de puntos." << endl
         << endl;

    cout << "Cada jugador tiene las siguientes opciones:" << endl;
    cout << "Piedra" << endl;
    cout << "Papel" << endl;
    cout << "Tijera" << endl
         << endl;

    cout << "Reglas del juego:" << endl;
    cout << "- Piedra le gana a Tijera porque la rompe." << endl;
    cout << "- Tijera le gana a Papel porque lo corta." << endl;
    cout << "- Papel le gana a Piedra porque la envuelve." << endl
         << endl;

    cout << "Si ambos jugadores tienen la misma opcion, la ronda termina en empate." << endl
         << endl;

    cout << "===== FIN DEL TUTORIAL =====" << endl;
}

void Creditos(Jugador *tail)
{
    cout << endl;
    cout << "ADRIAN EMANUEL ESCOBAR AVILES " << endl;
    cout << " RODRIGO JOSE VILLEDA RODEZNO " << endl;
    cout << " MANUEL TOBAR GARCIA " << endl;
}
