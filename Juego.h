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
    Jugador *sig;
};

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
        return " ";
    }
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

    archivo << "----- Nueva Partida -----" << endl;

    Jugador *aux = cabeza;

    if (cabeza == nullptr)
        return;

    do
    {
        archivo << "Jugador: " << aux->Nombre << endl;
        archivo << "Jugada: " << Movimientos(aux->jugada) << endl;

        if (aux->eliminar)
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