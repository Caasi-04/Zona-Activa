#pragma once

#include <iostream>
#include <string>
#include "RegistroEspera.h"
#include "Cancha.h"
using namespace std;

class ColeccionEspera {
private:
	RegistroEspera** registros; //puntero a un arreglo dinámico de punteros a RegistroEspera. lo expliqué mejor en otro archivo
	int capacidad;
	int cantidad;

public:
	ColeccionEspera();
	~ColeccionEspera();

	bool agregarRegistro(RegistroEspera* reg); 
	bool agregarSiFranjaO(Cliente* cliente, Cancha* cancha, int franja);

	RegistroEspera* buscarPorCanchaYFranja(Cancha* cancha, int franja) const;

	int getCantidad() const;
};


