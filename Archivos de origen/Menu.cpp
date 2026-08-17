#include "../Archivos de encabezado/Menu.h"

Menu::Menu(){
	// Inicializa las colecciones de canchas, clientes, reservas y espera
	canchas = new ColeccionCanchas();
	clientes = new ColeccionClientes();
	reservas = new ColeccionReservas();
	espera = new ColeccionEspera();
}

void Menu::limpiarPantalla(){
	/*
	
	- Seria mas facil con el #include "windows.h" y system("cls") pero las indicaciones del proyecto lo impiden

	- Evitar usar system("cls") para cumplir restricciones de encabezados.

	- Imprime varias líneas en blanco para simular limpieza de pantalla.
	
	*/
	cout << string(100, '\n');
}

void Menu::esperarEnter()
{
	cout << "\nPresione Enter para continuar...";
	string tmp;
	getline(cin, tmp);
}

Menu::~Menu(){
	// Libera la memoria de las colecciones (verificar punteros antes de eliminar)
	if (canchas != NULL) { delete canchas; canchas = NULL; }
	if (clientes != NULL) { delete clientes; clientes = NULL; }
	if (reservas != NULL) { delete reservas; reservas = NULL; }
	if (espera != NULL) { delete espera; espera = NULL; }
}

int Menu::leerEntero(const string& prompt){//esto lo vimos en fundamentos de programacion

	int value;
	while (true) {//No pasa hasta que se ingrese algo valido segun lo solicitado

		cout << prompt;//muestra el mensaje de prompt
		cin >> value;
		if (!cin.fail()) {//si no hay error en la entrada
			cin.ignore(1000, '\n');//ignora el resto de la linea
			return value;//retorna el valor leido
		}

		//si algo falla vuelve a intentar

		cin.clear();//limpia el estado de error de cin
		cin.ignore(1000, '\n');//ignora el resto de la linea
		cout << "Entrada invalida. Intente de nuevo."<<endl;//muestra mensaje de error
	}
}

double Menu::leerDouble(const string& prompt) {//lo mismo, pero con otro tipo de dato, double
	double value;
	while (true) {
		cout << prompt;
		cin >> value;
		if (!cin.fail()) {
			cin.ignore(1000, '\n');
			return value;
		}
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Entrada invalida. Intente de nuevo.\n";
	}
}

string Menu::leerLinea(const string& prompt){
	//aca como basicamente cualquier cosa que ponga es valida entonces solo lo lee
	cout << prompt;
	string s;
	getline(cin, s);
	return s;
}

void Menu::mostrarMenu() {
	int opcion = 0;

	while (opcion != 6) { // Mientras no seleccione salir

		limpiarPantalla();
		cout << endl << "--- Zona Activa - Menu Principal ---" << endl;
		cout << "1. Gestion Canchas" << endl;
		cout << "2. Gestion Clientes" << endl;
		cout << "3. Reservas" << endl;
		cout << "4. Registro de Espera" << endl;
		cout << "5. Reportes" << endl;
		cout << "6. Salir" << endl;

		opcion = leerEntero("Seleccione una opcion: ");

		switch (opcion) {
		case 1: { //Gestion Canchas
			limpiarPantalla();
			// Bloque encerrado con {} para declarar variables locales sin error
			cout << endl << "-- Gestion Canchas --" << endl;
			cout << endl << "1. Agregar Cancha\n2. Modificar Precio\n3. Poner Mantenimiento\n4. Liberar Mantenimiento\n5. Listar Canchas" << endl << endl;
			int s = leerEntero("Seleccione: ");
			if (s == 1) {//Agregar cancha

				/*iba a hacer otro switch, pero se ve demasiado raro un monton de
				switch, entonces dentro de los cases principales se usa if anidados*/

				//pide datos de la cancha para crearla
				int codigo = leerEntero("Codigo: ");
				string deporte = leerLinea("Deporte: ");
				double precio = leerDouble("Precio por hora: ");
				Cancha* c = new Cancha(codigo, deporte, precio);
				
				//si se agrega correctamente el metodo retorna true, si no, retorna false
				if (canchas->agregarCancha(c)) {cout << "Cancha agregada." << endl;}
				else {
					cout << "Error al agregar (codigo duplicado o lleno)."<< endl ;
					delete c;//elimina la cancha creada si no se pudo agregar a la coleccion
				}
				esperarEnter();

			}else if (s == 2) {//Modificar precio

				int codigo = leerEntero("Codigo: ");
				double precio = leerDouble("Nuevo precio: ");

				if (canchas->modificarPrecio(codigo, precio)) {cout << "Precio modificado." << endl;}
				else {cout << "Cancha no encontrada." << endl;}
				esperarEnter();
			
			}else if (s == 3) {//Poner mantenimiento

				int codigo = leerEntero("Codigo: ");
				int franja = leerEntero("Franja (0-11): ");

				if (canchas->ponerMantenimiento(codigo, franja)) { cout << "Puesta en mantenimiento." << endl; }
				else { cout << "No se pudo poner mantenimiento." << endl; }
				esperarEnter();

			}else if (s == 4) {//Liberar mantenimiento

				int codigo = leerEntero("Codigo: ");
				int franja = leerEntero("Franja (0-11): ");

				if (canchas->liberarMantenimiento(codigo, franja)) { cout << "Liberada de mantenimiento." << endl; }
				else { cout << "No se pudo liberar mantenimiento." << endl; }
				esperarEnter();
			
			}else if (s == 5) {//Listar canchas

				int nc = canchas->getCantidad();//obtiene la cantidad de canchas registradas

				for (int i = 0; i < nc; ++i) {
					Cancha* c = canchas->getCanchaAt(i);//obtiene la cancha en la posicion i
					if (c == NULL) continue;//si es NULL, pasa a la siguiente la ignora y va a la iteracion

					cout << "Codigo: " << c->getCodigo() << endl << "Deporte: " << c->getDeporte() << endl << "Precio: " << c->getPrecioPorHora() << endl << endl;
					cout << "Franjas: ";
					for (int f = 0; f < 12; ++f) { cout << c->getFranja(f) << " "; }
					cout << endl << "____________________________________________________________________" << endl;
				}
				esperarEnter();
			}
			break;

		}//cierra el bloque de case 1 para que las variables locales no den error

		case 2: {//Gestion Clientes
			limpiarPantalla();
			cout << endl << "-- Gestion Clientes --" << endl;
			cout << endl << "1. Registrar Cliente\n2. Buscar por Cedula\n3. Listar Clientes" << endl << endl;
			int s = leerEntero("Seleccione: ");
			if (s == 1) {//Registrar cliente
				string id = leerLinea("Cedula: ");
				string nombre = leerLinea("Nombre completo: ");
				string tel = leerLinea("Telefono: ");

				Cliente* cl = new Cliente(id, nombre, tel);
				
				if (clientes->registrarCliente(cl)) {//si se registra correctamente el metodo retorna true, si no, retorna false
					cout << "Cliente registrado.\n";
				}else {
					cout << "Error: Cedula duplicada o lleno.\n";
					delete cl;
				}
				esperarEnter();

			}else if (s == 2) {//Buscar por Cedula

				string id = leerLinea("Cedula: ");
				Cliente* cl = clientes->buscarPorId(id);
				//si el puntero es NULL, significa que no se encontró el cliente
			if (cl != NULL) {cout << "Encontrado: " << cl->getNombreCompleto() << endl << "Tel: " << cl->getTelefono() << endl << endl;}
			else { cout << "No encontrado." << endl; }
				esperarEnter();
			
			}else if (s == 3) { clientes->listarClientes(); }//Listar clientes
				if (s == 3) { clientes->listarClientes(); esperarEnter(); }//Listar clientes
			break;

		}//cierra el bloque de case 2 para que las variables locales no den error
		
		case 3: {//Reservas
			limpiarPantalla();
			cout << endl << "-- Reservas --" << endl;
			cout << "1. Agregar Reserva\n2. Cancelar Reserva" << endl;

			int s = leerEntero("Seleccione: ");

			if (s == 1) {//Agregar reserva

				string id = leerLinea("ID cliente: ");
				Cliente* cl = clientes->buscarPorId(id);

				if (cl == NULL) {cout << "Cliente no encontrado. Registrelo primero." << endl;}
				if (cl == NULL) {cout << "Cliente no encontrado. Registrelo primero." << endl; esperarEnter();}
				else {
					int codigo = leerEntero("Codigo cancha: ");
					Cancha* c = canchas->buscarPorCodigo(codigo);

					if (c == NULL) {cout << "Cancha no encontrada."<< endl; esperarEnter();}
					else {
						int inicio = leerEntero("Franja inicio (0-11): ");
						int horas = leerEntero("Cantidad de horas: ");

						//envia por parametros el puntero a cliente, el puntero a cancha, la franja de inicio y la cantidad de horas
						if (reservas->agregarReserva(cl, c, inicio, horas)) {cout << "Reserva agregada." << endl;}
						else {cout << "No se pudo agregar reserva (franjas no disponibles o datos invalidos)." << endl;}
						esperarEnter();
					}
				}
			}else if (s == 2) {//Cancelar reserva

				int cons = leerEntero("Consecutivo reserva: ");

				if (reservas->cancelarReserva(cons, espera)) { cout << "Reserva cancelada." << endl; }
				else { cout << "No se pudo cancelar." << endl; }
				esperarEnter();
			}
			break;
		
		}//cierra el bloque de case 3 para que las variables locales no den error

		case 4: {//Registro de espera

			cout << endl << "-- Registro de Espera --" << endl;
			string id = leerLinea("Cedula cliente: ");
			Cliente* cl = clientes->buscarPorId(id);

			if (cl == NULL) {cout << "Cliente no encontrado." << endl;}
			else {
				int codigo = leerEntero("Codigo cancha: ");
				Cancha* c = canchas->buscarPorCodigo(codigo);

				if (c == NULL) {cout << "Cancha no encontrada.\n";}
				else {
					int fr = leerEntero("Franja (0-11): ");
					//envia por parametros el puntero a cliente, el puntero a cancha y la franja
					if (espera->agregarSiFranjaO(cl, c, fr)) {cout << "Agregado a lista de espera." << endl;					}
					else {cout << "No se pudo agregar a la lista de espera (franja no ocupada o en mantenimiento)." << endl;}
				}
			}
			break;

		}//cierra el bloque de case 4 para que las variables locales no den error

		case 5: {//Reportes
			cout << endl << "-- Reportes --" << endl;
			int codigo = reportes.canchaMasReservada(canchas, reservas);
			if (codigo >= 0) {cout << "Cancha mas reservada: " << codigo << endl;}
			else {cout << "No hay datos." << endl;}

			string idMax = reportes.clienteMasFrecuente(clientes, reservas);
			if (idMax != "") {cout << "Cliente mas frecuente (Cedula): " << idMax << endl;}
			else {cout << "No hay datos de clientes." << endl;}

			double ingresos = reportes.ingresosTotales(reservas);
			cout << "Ingresos totales: " << ingresos << endl;

			double pct = reportes.porcentajeOcupacion(canchas);
			cout << "Porcentaje ocupacion: " << pct << "%\n" << endl;

			int horaMas, horaMenos;//las horas mas y menos demandadas
			//envia por parametro las variables horaMas y horaMenos para que el metodo las modifique
			reportes.franjasMasMenosDemandadas(reservas, horaMas, horaMenos);
			if (horaMas >= 0) {cout << "Franja mas demandada: " << horaMas << ", menos demandada: " << horaMenos << "\n";}
			else {cout << "No hay datos de franjas." << endl;}

			break;
		}//cierra el bloque de case 5 para que las variables locales no den error

		case 6://Salir
			cout << "Saliendo...\n";
			break;

		default://En caso de seleccionar una opcion no valida
			cout << "Opcion desconocida.\n";
			break;
		}
	}
}
