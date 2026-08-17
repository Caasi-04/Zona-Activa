#include "../Archivos de encabezado/Cliente.h"

Cliente::Cliente()//inicia con valores por defecto 
	: id(""), nombreCompleto(""), telefono("")
{}

Cliente::Cliente(const string& id, const string& nombre, const string& telefono)
	: id(id), nombreCompleto(nombre), telefono(telefono)
{}

Cliente::~Cliente() {}
// Getters y setters con const porque no modifican nada
string Cliente::getId() const { return id; }
string Cliente::getNombreCompleto() const { return nombreCompleto; }
string Cliente::getTelefono() const { return telefono; }

void Cliente::setId(const string& v) { id = v; }
void Cliente::setNombreCompleto(const string& v) { nombreCompleto = v; }
void Cliente::setTelefono(const string& v) { telefono = v; }
