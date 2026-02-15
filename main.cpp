#include <iostream>
#include "Juego.h"

int main()
{

    Jugador *tail = nullptr;
    int op;
    string carnet;
    string nombre;
    do
    {
        cout << "--- Prototipo Juego ---"<< endl;
        cout << "1. Introduccir jugadores a la partida"<< endl;
        cout << "2. Mostrar Tutorial"<< endl;
        cout << "3. Programadores del juego"<< endl;
        cout << "4. Empezar juego"<<endl;
        cout << "5. Salir " << endl;
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
            tutorial(tail); // llamamos al archivo .h "Juegopt1"
            break;
        case 3:
            Creditos(tail); // llamamos al archivo .h "Juegopt1"
            break;
        case 4:

            int op2;
            do
            {

                cout << "--- Prototipo SubMenu ---"<< endl;
                cout << "1. Empezar la partida"<< endl;
                cout << "2. Mostrar los jugadores de la partida" << endl;
                cout << "3. Volver al menu principal " << endl;
                cin >> op2;

                switch (op2)
                {
                case 1:
                    jugar(tail);
                    break;
                case 2:
                    mostrar(tail);
                    break;
                }
            } while (op2 != 3);
            break;
        }
    } while (op != 5);
    return 0;
}
