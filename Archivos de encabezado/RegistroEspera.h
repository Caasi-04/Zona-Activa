#pragma once

#include <iostream>
#include <string>
#include "Cliente.h"
#include "Cancha.h"
using namespace std;

class RegistroEspera {
private:
	static int siguienteConsecutivo;//static para que sea compartido entre todas las instancias de la clase con el fin de generar un consecutivo único para cada registro de espera y que no se reinicie cada vez que se crea un nuevo objeto de la clase RegistroEspera.
	int consecutivo;//int para almacenar el consecutivo único para cada registro de espera
	Cliente* cliente;
	Cancha* cancha;
	int posicionFranja; // 0..11
	int estado; // 1=Esperando, 2=Atendido, 3=Cancelado

public:
	RegistroEspera();
	RegistroEspera(Cliente* cliente, Cancha* cancha, int posicionFranja);
	~RegistroEspera();

	int getConsecutivo() const; //const para decir que es de lectura, se usa en todos los getters entonces ya no lo comento más
	Cliente* getCliente() const;
	Cancha* getCancha() const;
	int getPosicionFranja() const;
	int getEstado() const;

	void setEstado(int e); 
};


