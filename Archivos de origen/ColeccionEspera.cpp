#include "../Archivos de encabezado/ColeccionEspera.h"

ColeccionEspera::ColeccionEspera()
	: capacidad(10), cantidad(0)
{
	registros = new RegistroEspera * [capacidad];//crea un arreglo dinámico de punteros a RegistroEspera con capacidad inicial de 10
	for (int i = 0; i < capacidad; ++i) registros[i] = NULL;//asigna NULL a cada posición del arreglo para indicar que no hay registros aún
}

ColeccionEspera::~ColeccionEspera(){
	// Eliminar cada RegistroEspera* almacenado y luego liberar el arreglo
	if (registros != NULL) {
		for (int i = 0; i < cantidad; ++i) {
			if (registros[i] != NULL) {
				delete registros[i];
				registros[i] = NULL;
			}
		}
		delete[] registros;
		registros = NULL;
	}
}

bool ColeccionEspera::agregarRegistro(RegistroEspera* reg) {//recibe un puntero a un objeto RegistroEspera y lo agrega al arreglo dinámico de registros si hay espacio disponible
	if (reg == NULL) return false;
	if (cantidad >= capacidad) return false;
	registros[cantidad++] = reg;
	return true;
}

bool ColeccionEspera::agregarSiFranjaO(Cliente* cliente, Cancha* cancha, int franja){
	if (cancha == NULL || cliente == NULL) return false;//verifica que los punteros a Cancha y Cliente no sean nulos
	char estado = cancha->getFranja(franja);
	if (estado == 'M') return false; // no permite si está en mantenimiento
	if (estado != 'O') return false; // solo si está ocupada

	RegistroEspera* reg = new RegistroEspera(cliente, cancha, franja);//crea un nuevo objeto RegistroEspera con el cliente, la cancha y la franja especificados
	return agregarRegistro(reg);//agrega el registro al arreglo dinámico de registros
}

RegistroEspera* ColeccionEspera::buscarPorCanchaYFranja(Cancha* cancha, int franja) const{
	for (int i = 0; i < cantidad; ++i) {
		if (registros[i] != NULL && registros[i]->getCancha() == cancha && registros[i]->getPosicionFranja() == franja && registros[i]->getEstado() == 1) {//si el registro no es nulo, la cancha coincide, la franja coincide y el estado es "Esperando"
			return registros[i];//devuelve el puntero al registro encontrado
		}
	}
	return NULL;
}

int ColeccionEspera::getCantidad() const { return cantidad; }//devuelve la cantidad de registros en espera
