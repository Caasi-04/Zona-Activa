#include "../Archivos de encabezado/ColeccionReservas.h"

ColeccionReservas::ColeccionReservas()
	: capacidad(200), cantidad(0)
{
	reservas = new Reserva * [capacidad];// arreglo dinámico de punteros a Reserva
	for (int i = 0; i < capacidad; ++i) reservas[i] = NULL;// inicializamos a NULL todo
}

ColeccionReservas::~ColeccionReservas(){
	// Eliminar cada Reserva* almacenada y luego liberar el arreglo
	if (reservas != NULL) {
		for (int i = 0; i < cantidad; ++i) {
			if (reservas[i] != NULL) {
				delete reservas[i];
				reservas[i] = NULL;
			}
		}
		delete[] reservas;
		reservas = NULL;
	}
}

bool ColeccionReservas::agregarReserva(Cliente* cliente, Cancha* cancha, int franjaInicio, int cantidadHoras){
	if (cliente == NULL || cancha == NULL) { return false; }// validamos que no sean nulos
	if (cantidad >= capacidad) { return false; }// validamos que no se exceda la capacidad
	if (franjaInicio < 0 || franjaInicio >= 12) { return false; }// validamos que la franja de inicio esté dentro del rango permitido
	if (cantidadHoras <= 0 || franjaInicio + cantidadHoras > 12) { return false; }// validamos que la cantidad de horas sea positiva y que no exceda el límite de franjas

	
	for (int i = franjaInicio; i < franjaInicio + cantidadHoras; ++i) {// todo el tiempo que se va a reservar debe estar libre
		if (cancha->getFranja(i) != 'L') { return false; }// si alguna franja no está libre, no se puede reservar
	}

	//-si llega aqui entonces está disponible, entonces se puede reservar
	for (int i = franjaInicio; i < franjaInicio + cantidadHoras; ++i) {
		cancha->setFranja(i, 'O');//marca ocupado todo el tiempo que se va a reservar
	}

	Reserva* r = new Reserva(cliente, cancha, franjaInicio, cantidadHoras);//hace la reserva
	reservas[cantidad++] = r;//la agrega a la colección de reservas
	return true;//exito
}

Reserva* ColeccionReservas::buscarPorConsecutivo(int consecutivo) const {//busca una reserva por su numero de consecutivo (el "ID" acumulable)
	for (int i = 0; i < cantidad; ++i) {
		if (reservas[i] != NULL && reservas[i]->getConsecutivo() == consecutivo) { return reservas[i]; }//si encuentra la reserva, la retorna
	}
	return NULL;//si no encuentra la reserva, retorna NULL
}

bool ColeccionReservas::cancelarReserva(int consecutivo, ColeccionEspera* espera) {

	Reserva* r = buscarPorConsecutivo(consecutivo);//busca la reserva por su consecutivo

	if (r == NULL) { return false; }// no existe la reserva
	if (r->getEstado() == 0) { return false; } // ya cancelada

	Cancha* cancha = r->getCancha(); // obtenemos la cancha asociada a la reserva
	int inicio = r->getFranjaInicio(); 
	int horas = r->getCantidadHoras(); 


	for (int i = inicio; i < inicio + horas; ++i) {
		if (cancha->getFranja(i) == 'O') {//si la cancha estaba ocupada
			cancha->setFranja(i, 'L'); //se libera la franja

			if (espera != NULL) {//si hay lista de espera
				//se busca si hay alguien en lista de espera para esa cancha y franja
				RegistroEspera* reg = espera->buscarPorCanchaYFranja(cancha, i);

				if (reg != NULL) {//si hay alguien en lista de espera para esa cancha y franja
					cout << "Se liberó la franja " << i << " en la cancha " << cancha->getCodigo() << ". Hay personas en lista de espera."<< endl;
				}
			}
		}
	}

	r->cancelar(); //cambia el estado de la reserva a cancelada
	return true;//exito
}

int ColeccionReservas::getCantidad() const { return cantidad; }//retorna la cantidad de reservas registradas

//retorna la reserva en la posición index del arreglo de reservas, o NULL si el index es inválido
Reserva* ColeccionReservas::getReservaAt(int index) const {
	if (index < 0 || index >= cantidad) {return NULL;}
	return reservas[index];
}
