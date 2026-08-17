#pragma once

#include <iostream>
#include <string>
using namespace std;

class Cancha {
private:
	int codigo;
	string deporte;
	double precioPorHora;
	char franjas[12];

public:
	Cancha();
	Cancha(int codigo, const string& deporte, double precio);
	~Cancha();

	int getCodigo() const; //El const para decir que no modifica el objeto
	string getDeporte() const;
	double getPrecioPorHora() const;

	void setCodigo(int c);
	void setDeporte(const string& d);
	void setPrecioPorHora(double p);

	char getFranja(int index) const;
	void setFranja(int index, char valor);
};


