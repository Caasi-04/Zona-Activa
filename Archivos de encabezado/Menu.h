#pragma	once
#include <iostream>
#include <string>
#include "ColeccionCanchas.h"
#include "ColeccionClientes.h"
#include "ColeccionReservas.h"
#include "ColeccionEspera.h"
#include "Reportes.h"
using namespace std;

class Menu {
private:
	// Punteros a las colecciones de canchas, clientes, reservas y espera
	ColeccionCanchas* canchas;
	ColeccionClientes* clientes;
	ColeccionReservas* reservas;
	ColeccionEspera* espera;
	Reportes reportes;

	// Funciones auxiliares para leer datos del usuario y que sea valido lo que escribe
	int leerEntero(const string& prompt);
	double leerDouble(const string& prompt);
	string leerLinea(const string& prompt);

public:
	Menu();
	~Menu();

	void mostrarMenu();
};

#endif // MENU_H
