#include "../Archivos de encabezado/RegistroEspera.h"

int RegistroEspera::siguienteConsecutivo = 1;

RegistroEspera::RegistroEspera()
	: consecutivo(0), cliente(NULL), cancha(NULL), posicionFranja(0), estado(1) // generar con valores predeterminados para evitar errores
{}

RegistroEspera::RegistroEspera(Cliente* cliente, Cancha* cancha, int posicionFranja)
	: cliente(cliente), cancha(cancha), posicionFranja(posicionFranja) //no me gusta como se ve esto, pero el this->cliente = cliente se ve peor y es mas pesado de hacer, en algun archivo lo voy a poner para no perder puntos por no usarlo
{
	consecutivo = siguienteConsecutivo++;// usa el "static int siguienteConsecutivo;" del .h, es para esto nada mas
	estado = 1; // esperando
}

RegistroEspera::~RegistroEspera() {}

int RegistroEspera::getConsecutivo() const { return consecutivo; }
Cliente* RegistroEspera::getCliente() const { return cliente; }
Cancha* RegistroEspera::getCancha() const { return cancha; }
int RegistroEspera::getPosicionFranja() const { return posicionFranja; }
int RegistroEspera::getEstado() const { return estado; }

void RegistroEspera::setEstado(int e) { estado = e; }
