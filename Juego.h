#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace std;


//creamos un struct probicional para probar las funciones del juego
struct Jugador
{
    string Nombre;
    string Carnet;
    int jugada;
    bool eliminar;
    int puntos;
    Jugador *sig;
};

void insertarJugador( Jugador*&tail, string carnet, string nombre)
{
    Jugador *nuevo = new Jugador();
    nuevo->Nombre = nombre;
    nuevo->Carnet = carnet;
    if (tail == nullptr)
    {
        tail = nuevo;
        nuevo->sig = nuevo;
    }
    else
    {
        nuevo->sig = tail->sig;
        tail->sig = nuevo;
        tail = nuevo; // nuevo se vuelve el último
    }
}

void mostrar(Jugador *tail)
{
    if (tail == nullptr)
    {
        cout << endl;
        cout << "No hay jugadores en la partida" << endl;
        return;
    }

    Jugador *head = tail->sig;
    Jugador *aux = head;
    
        cout << endl;
        cout << "--LISTA DE JUGADORES--" << endl;
    do
    {
        cout << "Nombre: " << aux->Nombre << endl;
        cout << "Carnet: " << aux->Carnet << endl;
        cout << "-----------------------" << endl;
        aux = aux->sig;
    } while (aux != head);
    cout << endl;
}

string Movimientos(int accion)
{ //creamos un switch con las opciones del jugador
    switch (accion)
    {
    case 0:
        return "Piedra";
    case 1:
        return "Papel";
    case 2:
        return "Tijera";
    default:
        return " "; // el default nos permite que la funcion no quede sin valor asignado
    }
} 

void mostrarPuntuaciones(Jugador *cabeza)
{
    if (cabeza == nullptr)
    {
        cout << endl;
        cout << "No hay jugadores puntuando" << endl;
        return;
    }

    cout << "\n===== PUNTUACIONES FINALES =====" << endl;

    Jugador *aux = cabeza;
    do
    {
        cout << "Jugador: " << aux->Nombre
             << " | Puntos: " << aux->puntos << endl;

        aux = aux->sig;
    } while (aux != cabeza);
}

void guardarEstadisticas(Jugador *cabeza)
{
    // Creamos/buscamos el archivo donde vamos a estar guardando 
    //los datos de las partidas que vamos jugando
    ofstream archivo("estadisticas.txt", ios::app);

    if (!archivo.is_open())
    {
        cout << "Error al abrir el archivo de estadisticas." << endl;
        return;
    }

    archivo << "----- Partidas Jugadas -----" << endl;

    Jugador *aux = cabeza;

    if (cabeza == nullptr)
        return;

    do
    {
        //guardamos el nombre junto al movimiento que le toco al jugador
        archivo << "Jugador: " << aux->Nombre << endl;
        archivo << "Jugada: " << Movimientos(aux->jugada) << endl;

        if (aux->eliminar)
        //le asiganmos un estado a los jugadores a la hora de guardarlos en el archivo .txt
            archivo << "Estado: Eliminado" << endl;
        else
            archivo << "Estado: Ganador" << endl;

        archivo << endl;

        aux = aux->sig;

    } while (aux != cabeza);

    archivo.close();
}

void mostrarEstadisticas()
{
    //En esta funcion imprimimos el historial de partidas que guardamos anteriormente
    //en el archivo .txt
    ifstream archivo("estadisticas.txt");
    string linea;

    if (!archivo.is_open())
    {
        cout << "No hay estadisticas guardadas." << endl;
        return;
    }

    cout << "===== HISTORIAL DE ESTADISTICAS =====" << endl;

    while (getline(archivo, linea))
    {
        cout << linea << endl;
    }

    archivo.close();
}

void jugar(Jugador *cabeza)
{
    if (cabeza == nullptr)
    {
        cout << "No hay jugadores para iniciar una partida" << endl;
        return;
    }

    //reiniciamos el estado de los jugadores para iniciar la partida
    Jugador *aux = cabeza;
    do
    {
        aux->eliminar = false;
        aux = aux->sig;
    } while (aux != cabeza);

    bool hayGanador = false;

    while (!hayGanador)
    {
        bool hayPiedra = false, hayPapel = false, hayTijera = false;

        cout << " Resumen de la ronda: " << endl;

       //asignamos jugadas a los jugadores mientras no hayan perdido anteriormente
        aux = cabeza;
        do
        {
            if (!aux->eliminar)
            {
                aux->jugada = rand() % 3;

                cout << aux->Nombre << " obtuvo: " << Movimientos(aux->jugada) << endl;

                if (aux->jugada == 0) hayPiedra = true;
                if (aux->jugada == 1) hayPapel = true;
                if (aux->jugada == 2) hayTijera = true;
            }

            aux = aux->sig;

        } while (aux != cabeza);

        cout << "Resultado de la partida: " << endl;

        //creamos un primer if donde ponemos el primer caso donde todos si hay tres jugadores
        //puede haber un empate tecnico ya que todos se eliminan entre todos
        if (hayPiedra && hayPapel && hayTijera)
        {
            cout << "Empate tecnico, se repite la ronda. " << endl;
            continue;
        }

        //creamos un segundo if donde creamos un segundo caso en el cual todos los jugadores escojen
        //la misma jugada en la partida probocando un empate entre los n jugadores
        if ((hayPiedra && !hayPapel && !hayTijera) ||
            (!hayPiedra && hayPapel && !hayTijera) ||
            (!hayPiedra && !hayPapel && hayTijera))
        {
            cout << "Todos eligieron lo mismo, se repite la ronda. " << endl;
            continue;
        }

        int accionGanadora;

        if (hayPiedra && hayTijera)
            accionGanadora = 0;
        else if (hayPapel && hayPiedra)
            accionGanadora = 1;
        else
            accionGanadora = 2;

        int EnPartida = 0;

        // eliminamos a los jugadores que van perdiendo en la partida para irlos saltando 
        //para que el programa siga ejecutandose sin contar a los jugadores que perdieron
        aux = cabeza;
        do
        {
            if (!aux->eliminar)
            {
                if (aux->jugada != accionGanadora)
                {
                    cout << "Eliminado: " << aux->Nombre << endl;
                    aux->eliminar = true;
                }
                else
                {
                    EnPartida++;
                    //vamos sumando la cantidad de jugadores que aun no han sido eliminados
                }
            }

            aux = aux->sig;

        } while (aux != cabeza);

       //Si EnPartida solo queda un jugador se le declara como ganador del set del juego
        if (EnPartida == 1)
        {
            aux = cabeza;
            do
            {
                if (!aux->eliminar)
                {
                    cout << " El ganador es: " << aux->Nombre << endl;
                    aux->puntos++;
                    hayGanador = true;
                    break;
                }

                aux = aux->sig;

            } while (aux != cabeza);
        }
        else
        //Siendo lo contrario seguimos jugando hasta que se cumpla el primer if de la funcion
        {
            cout << "Quedan " << EnPartida
                 << " jugadores, sigue la partida..." << endl;
        }
    }

    //Llamamos y Guardamos los datos en el archivo .txt
    mostrarPuntuaciones(cabeza);
    guardarEstadisticas(cabeza);
    mostrarEstadisticas();
}