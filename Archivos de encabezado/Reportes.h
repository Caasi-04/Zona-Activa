#pragma once
#include <iostream>
#include <string>
#include "ColeccionCanchas.h"
#include "ColeccionClientes.h"
#include "ColeccionReservas.h"
using namespace std;

class Reportes {
public:
	int canchaMasReservada(ColeccionCanchas* cc, ColeccionReservas* cr) const;
	string clienteMasFrecuente(ColeccionClientes* clientes, ColeccionReservas* cr) const;
	double ingresosTotales(ColeccionReservas* cr) const;
	double porcentajeOcupacion(ColeccionCanchas* cc) const;
	void franjasMasMenosDemandadas(ColeccionReservas* cr, int& horaMas, int& horaMenos) const;
};


