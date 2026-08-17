#pragma once

#include <iostream>
#include <string>
using namespace std;

class Cliente {
private:
	string id;//cedula
	string nombreCompleto;
	string telefono;

public:
	Cliente();
	Cliente(const string& id, const string& nombre, const string& telefono);
	~Cliente();

	string getId() const;
	string getNombreCompleto() const;
	string getTelefono() const;

	void setId(const string& v);
	void setNombreCompleto(const string& v);
	void setTelefono(const string& v);
};

