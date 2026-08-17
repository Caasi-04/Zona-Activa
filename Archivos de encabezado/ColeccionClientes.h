#pragma once

#include <iostream>
#include <string>
#include "Cliente.h"
using namespace std;

class ColeccionClientes {
private:
	Cliente** clientes;// puntero aarreglo de punteros a Cliente
	int capacidad;
	int cantidad;

public:
	ColeccionClientes();
	~ColeccionClientes();

	bool registrarCliente(Cliente* cliente); // valida ID unico
	Cliente* buscarPorId(const string& id) const;
	void listarClientes() const;

	int getCantidad() const;
};


