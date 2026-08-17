#include "../Archivos de encabezado/ColeccionCanchas.h"

ColeccionCanchas::ColeccionCanchas()
	: capacidad(10), cantidad(0)
{
	canchas = new Cancha * [capacidad];//crea un arreglo de punteros a Cancha, con tamaño capacidad
	for (int i = 0; i < capacidad; ++i) canchas[i] = NULL; //inicializa todos los punteros a NULL o sea vacios, solo para evitar errores de momoria
}

ColeccionCanchas::~ColeccionCanchas(){delete[] canchas;} // No se eliminan las Cancha* almacenadas aquí. solo el arreglo

bool ColeccionCanchas::agregarCancha(Cancha* cancha) {
	if (cancha == NULL) return false; //si el puntero es nulo, no se puede agregar
	if (cantidad >= capacidad) return false; //si ya se lleno el arreglo

	int codigo = cancha->getCodigo();	//buscamos el codigo de la cancha a agregar
	if (buscarPorCodigo(codigo) != NULL) return false; // ya existe

	canchas[cantidad++] = cancha;//agregamos la cancha al arreglo
	return true; //retornamos true si se agrego correctamente
}

Cancha* ColeccionCanchas::buscarPorCodigo(int codigo) const{
	for (int i = 0; i < cantidad; ++i) {
		// si el puntero no es nulo y ademas encuentra el codigo entonces retornamos la cancha
		if (canchas[i] != NULL && canchas[i]->getCodigo() == codigo) return canchas[i];
	}
	return NULL;//si no encontró nada, retornamos NULL
}

bool ColeccionCanchas::modificarPrecio(int codigo, double nuevoPrecio){
	Cancha* c = buscarPorCodigo(codigo);// c es un puntero a Cancha, si no encuentra la cancha retorna NULL
	if (c == NULL) return false;//no puede modificar el precio si no encuentra la cancha

	c->setPrecioPorHora(nuevoPrecio);// modifica el precio de la cancha
	return true; //exito
}

bool ColeccionCanchas::ponerMantenimiento(int codigo, int franja){
	Cancha* c = buscarPorCodigo(codigo);// c es un puntero a Cancha, si no encuentra la cancha retorna NULL
	if (c == NULL) return false;//no puede poner mantenimiento si no encuentra la cancha
	char actual = c->getFranja(franja); //esto es de Cancha.cpp
	if (actual == 'O') return false; // no se puede poner mantenimiento si está ocupada
	c->setFranja(franja, 'M');
	return true;
}

bool ColeccionCanchas::liberarMantenimiento(int codigo, int franja){
	Cancha* c = buscarPorCodigo(codigo);
	if (c == NULL) return false;
	char actual = c->getFranja(franja);
	if (actual != 'M') return false;//No puede liberar mantenimiento si no está en mantenimiento
	c->setFranja(franja, 'L');//libera la franja, pone 'L'
	return true;//exito
}

int ColeccionCanchas::getCantidad() const { return cantidad; }//cantidad empieza en 0 y se incrementa cuando se crea una cancha
