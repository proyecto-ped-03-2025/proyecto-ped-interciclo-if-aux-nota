#include <iostream>
#include "creditosytuto.h"

int main()
{

    Jugador *tail = nullptr;
    int op;
    string carnet;
    string nombre;
    do
    {
        cout << "===== Menu ====="<< endl;
        cout << "1. Introduccir jugadores a la partida"<< endl;
        cout << "2. Mostrar Tutorial"<< endl;
        cout << "3. Programadores del juego"<< endl;
        cout << "4. Mostrar ultimas partidas" << endl;
        cout << "5. Empezar juego"<<endl;
        cout << "6. Salir " << endl;
        cout << "Opcion: ";
        cin >> op;
        cout << endl;

        switch (op)
        {
        case 1:
            cout << "Introduzca el nombre del juegador: " << endl;
            getline(cin >> ws, nombre);
            cout << "Introduzca el carnet del juegador: " << endl;
            cin >> carnet;
            insertarJugador(tail, carnet, nombre);
            break;
        case 2:
            tutorial(tail); // llamamos al archivo .h "Juego"
            break;
        case 3:
            Creditos(tail); // llamamos al archivo .h "Juego"
            break;
        case 4:
            mostrarEstadisticas();
            break;
        case 5:

            int op2;
            do
            {

                cout << "===== Menu de Juego ====="<< endl;
                cout << "1. Empezar la partida "<< endl;
                cout << "2. Mostrar los jugadores de la partida " << endl;
                cout << "3. Mostrar la puntuacion de los jugadores " << endl;
                cout << "4. Volver al menu principal " << endl;
                cin >> op2;

                switch (op2)
                {
                case 1:
                    jugar(tail);
                    break;
                case 2:
                    mostrar(tail);
                    break;
                case 3:
                    mostrarPuntuaciones(tail);
                    break;
                }
            } while (op2 != 4);
            break;
        }
    } while (op != 6);
    return 0;
}
