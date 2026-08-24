#include "../Archivos de encabezado/ColeccionClientes.h"

ColeccionClientes::ColeccionClientes()
	: capacidad(100), cantidad(0)
{
	clientes = new Cliente * [capacidad];//crear arreglo de punteros a Cliente
	for (int i = 0; i < capacidad; ++i) clientes[i] = NULL;//inicializar punteros a NULL
}

ColeccionClientes::~ColeccionClientes(){
	// Eliminar cada Cliente* almacenado y luego liberar el arreglo
	if (clientes != NULL) {
		for (int i = 0; i < cantidad; ++i) {
			if (clientes[i] != NULL) {
				delete clientes[i];
				clientes[i] = NULL;
			}
		}
		delete[] clientes; //libera memoria del arreglo dinamico
		clientes = NULL;
	}
}

bool ColeccionClientes::registrarCliente(Cliente* cliente){
	if (cliente == NULL) { return false; }// no se puede registrar un cliente nulo
	if (cantidad >= capacidad) { return false; }
	if (buscarPorId(cliente->getId()) != NULL) { return false; } // ya existe

	clientes[cantidad++] = cliente;//agregar al final del arreglo
	return true;//exito
}

Cliente* ColeccionClientes::buscarPorId(const string& id) const {
	for (int i = 0; i < cantidad; ++i) {
		if (clientes[i] != NULL && clientes[i]->getId() == id) { return clientes[i]; }//encontrado
	}
	return NULL;//no encontrado
}

void ColeccionClientes::listarClientes() const{
	for (int i = 0; i < cantidad; i++) {
		if (clientes[i] != NULL) {
			cout << "Cedula: " << clientes[i]->getId() << endl <<"Nombre: " << clientes[i]->getNombreCompleto() <<endl<< "Tel: " << clientes[i]->getTelefono() << endl<<endl;//despliega informacion de los clientes con un espacio en blanco para separarlos
		}
	}
}

int ColeccionClientes::getCantidad() const { return cantidad; }//retorna la cantidad de clientes registrados

//retorna el cliente en la posicion index, o NULL si index es invalido
Cliente* ColeccionClientes::getClienteAt(int index) const {
	if (index < 0 || index >= cantidad) {return NULL;}
	return clientes[index];
}
