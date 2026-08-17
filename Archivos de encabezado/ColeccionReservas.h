#pragma once

#include <iostream>
#include <string>
#include "Reserva.h"
#include "Cancha.h"
#include "ColeccionEspera.h"
using namespace std;

class ColeccionReservas {
private:
	Reserva** reservas; //puntero a un arreglo dinamico de punteros a reserva
	int capacidad;
	int cantidad;

public:
	ColeccionReservas();
	~ColeccionReservas();

	bool agregarReserva(Cliente* cliente, Cancha* cancha, int franjaInicio, int cantidadHoras);
	Reserva* buscarPorConsecutivo(int consecutivo) const;
	bool cancelarReserva(int consecutivo, ColeccionEspera* espera);

	int getCantidad() const;
	Reserva* getReservaAt(int index) const;//retorna un puntero a reserva, o NULL si no encuentra
};


