#pragma once

#include <iostream>
#include <string>
#include "Cliente.h"
#include "Cancha.h"
using namespace std;

class Reserva {
private:
	static int siguienteConsecutivo; //esto ya lo usamos en el registro de espera, cumple la misma funcion aqui	
	int consecutivo;
	Cliente* cliente;
	Cancha* cancha;
	int franjaInicio; // de 0 a 11
	int cantidadHoras;
	double montoTotal;
	int estado; // 1=Activa, 0=Cancelada

public:
	Reserva();
	Reserva(Cliente* cliente, Cancha* cancha, int franjaInicio, int cantidadHoras);
	~Reserva();

	int getConsecutivo() const;
	Cliente* getCliente() const;
	Cancha* getCancha() const;
	int getFranjaInicio() const;
	int getCantidadHoras() const;
	double getMontoTotal() const;
	int getEstado() const;

	void cancelar();
};

