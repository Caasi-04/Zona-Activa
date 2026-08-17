#pragma once

#include <iostream>
#include <string>
#include "Cancha.h"
using namespace std;

class ColeccionCanchas {
private:
	Cancha** canchas;//puntero de punteros. apunta a la direccion de memoria de un arreglo con direcciones de memoria. no es tan complicado
	int capacidad;
	int cantidad;

public:
	ColeccionCanchas();
	~ColeccionCanchas();

	bool agregarCancha(Cancha* cancha);
	
	Cancha* buscarPorCodigo(int codigo) const;// Cancha* es el tipo de retorno, retorna un puntero a Cancha, o NULL si no encuentra
	
	bool modificarPrecio(int codigo, double nuevoPrecio);

	bool ponerMantenimiento(int codigo, int franja); // pone 'M' si no está 'O'
	bool liberarMantenimiento(int codigo, int franja); // pone 'L'

	int getCantidad() const;
};


