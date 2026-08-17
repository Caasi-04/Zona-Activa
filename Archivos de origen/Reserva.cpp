#include "../Archivos de encabezado/Reserva.h"

int Reserva::siguienteConsecutivo = 1;

Reserva::Reserva()//crea con valores por defecto para que no agarre valores basura de la memoria
	: consecutivo(0), cliente(NULL), cancha(NULL), franjaInicio(0), cantidadHoras(0), montoTotal(0.0), estado(0)//insisto que se ve feo y no me gusta, pero es mas rapido
{}

Reserva::Reserva(Cliente* cliente, Cancha* cancha, int franjaInicio, int cantidadHoras)
	: cliente(cliente), cancha(cancha), franjaInicio(franjaInicio), cantidadHoras(cantidadHoras)
{
	consecutivo = siguienteConsecutivo++;
	estado = 1; // activa
	if (cancha != NULL) { //si no esta vacia
		montoTotal = cancha->getPrecioPorHora() * cantidadHoras;//total es lo que vale la cancha por la cantidad de horas, facil
	} else {
		montoTotal = 0.0;
	}
}

Reserva::~Reserva() {}

int Reserva::getConsecutivo() const { return consecutivo; }
Cliente* Reserva::getCliente() const { return cliente; }
Cancha* Reserva::getCancha() const { return cancha; }
int Reserva::getFranjaInicio() const { return franjaInicio; }
int Reserva::getCantidadHoras() const { return cantidadHoras; }
double Reserva::getMontoTotal() const { return montoTotal; }
int Reserva::getEstado() const { return estado; }

void Reserva::cancelar() { estado = 0; }
