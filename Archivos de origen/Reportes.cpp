#include "../Archivos de encabezado/Reportes.h"

int Reportes::canchaMasReservada(ColeccionCanchas* cc, ColeccionReservas* cr) const{
	if (cc == NULL || cr == NULL) { return -1; }//si no hay canchas o reservas, retorna -1
	int maxCount = -1;//inicializa el contador maximo de reservas a -1
	int codigoMax = -1;//inicializa el codigo de la cancha con mas reservas a -1

	int nc = cc->getCantidad();//obtiene la cantidad de canchas

	for (int i = 0; i < nc; ++i) {//recorre todas las canchas

		Cancha* cancha = cc->getCanchaAt(i);//obtiene la cancha en la posicion i

		if (cancha == NULL) { continue; }//si la cancha es NULL, continua con la siguiente iteracion

		int codigo = cancha->getCodigo();
		int count = 0;

		int nr = cr->getCantidad();//obtiene la cantidad de reservas

		for (int j = 0; j < nr; ++j) {
			Reserva* r = cr->getReservaAt(j);
			//si la reserva es valida, activa y corresponde a la cancha actual, incrementa el contador
			if (r != NULL && r->getEstado() == 1 && r->getCancha() == cancha) { ++count; }
		}
		//si el contador de reservas para la cancha actual es mayor que el maximo, actualiza el maximo y el codigo de la cancha
		if (count > maxCount) { maxCount = count; codigoMax = codigo; }
	}

	return codigoMax;//retorna el codigo de la cancha con mas reservas
}

//viene siendo la misma ciencia y logica que lo anterior, pero ahora con clientes y reservas
string Reportes::clienteMasFrecuente(ColeccionClientes* clientes, ColeccionReservas* cr) const{
	if (clientes == NULL || cr == NULL) return string("");
	int maxCount = -1;
	string idMax = "";

	int nc = clientes->getCantidad();
	for (int i = 0; i < nc; ++i) {
		Cliente* c = clientes->getClienteAt(i);
		if (c == NULL) continue;
		int count = 0;
		int nr = cr->getCantidad();
		for (int j = 0; j < nr; ++j) {
			Reserva* r = cr->getReservaAt(j);
			if (r != NULL && r->getEstado() == 1 && r->getCliente() == c) ++count;
		}
		if (count > maxCount) { maxCount = count; idMax = c->getId(); }
	}

	return idMax;
}

double Reportes::ingresosTotales(ColeccionReservas* cr) const{
	if (cr == NULL) return 0.0;
	double suma = 0.0;
	int nr = cr->getCantidad();//obtiene el numero de reservas
	for (int i = 0; i < nr; ++i) {
		Reserva* r = cr->getReservaAt(i);//obtiene la reserva en la posicion i
		//si la reserva es valida y activa, suma su monto total a la suma
		if (r != NULL && r->getEstado() == 1) { suma += r->getMontoTotal(); }
	}
	return suma;
}

double Reportes::porcentajeOcupacion(ColeccionCanchas* cc) const{
	if (cc == NULL) { return 0.0; }//si no hay canchas, retorna 0.0
	int nc = cc->getCantidad();
	if (nc == 0) { return 0.0; }//si no hay canchas, retorna 0.0

	int totalFranjas = nc * 12;//cada cancha tiene 12 franjas, entonces el total de franjas es nc * 12
	int ocupadas = 0;
	for (int i = 0; i < nc; ++i) {
		Cancha* c = cc->getCanchaAt(i);//obtiene la cancha en la posicion i
		if (c == NULL) { continue; }//si la cancha es NULL, continua con la siguiente iteracion
		for (int f = 0; f < 12; ++f) {
			if (c->getFranja(f) == 'O') { ++ocupadas; }//si la franja esta ocupada, incrementa el contador de franjas ocupadas
		}
	}

	//los casteos tambien lo vimos en fundamentos de programacion
	return (double)ocupadas * 100.0 / (double)totalFranjas;//retorna el porcentaje de ocupacion
}

//recibe un puntero a la coleccion de reservas y dos referencias a enteros para almacenar las horas mas y menos demandadas
void Reportes::franjasMasMenosDemandadas(ColeccionReservas* cr, int& horaMas, int& horaMenos) const{
	horaMas = -1; horaMenos = -1;
	if (cr == NULL) return;

	int counts[12];
	for (int i = 0; i < 12; ++i) counts[i] = 0;

	int nr = cr->getCantidad();
	for (int i = 0; i < nr; ++i) {
		Reserva* r = cr->getReservaAt(i);
		if (r == NULL || r->getEstado() != 1) { continue; }
		int inicio = r->getFranjaInicio();
		int horas = r->getCantidadHoras();
		for (int h = inicio; h < inicio + horas && h < 12; ++h) ++counts[h];
	}

	int maxC = -1; //como el minimo es 0 entonces cualquier contador lo reemplaza
	int minC = 1 << 30;	//2^30. 1073741824, totalmente arbitrario, pero suficientemente grande para que cualquier contador de franjas sea menor
	//el maximo del int es 2^31-1, entonces 2^30 es suficientemente "pequeño" para usar int

	for (int i = 0; i < 12; ++i) {//recorre las 12 franjas horarias
		//si el contador de la franja actual es mayor que el maximo, actualiza el maximo y la hora mas demandada
		if (counts[i] > maxC) { maxC = counts[i]; horaMas = i; }

		//si el contador de la franja actual es menor que el minimo, actualiza el minimo y la hora menos demandada
		if (counts[i] < minC) { minC = counts[i]; horaMenos = i; }
	}
}
