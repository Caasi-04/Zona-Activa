#include "../Archivos de encabezado/Cancha.h" //ruta diferente a la vista en clase solo para mas orden

Cancha::Cancha() //este constructor inicializa el arreglo de franjas con 'L' (libre) y los demás atributos con valores predeterminados
	: codigo(0), deporte(""), precioPorHora(0.0)
{
	for (int i = 0; i < 12; ++i) franjas[i] = 'L';
}

Cancha::Cancha(int codigo, const string& deporte, double precio) //este contructore pone franjas libres y el resto segun se proporcione
	: codigo(codigo), deporte(deporte), precioPorHora(precio)
{
	for (int i = 0; i < 12; ++i) franjas[i] = 'L';
}

Cancha::~Cancha() {}//destructor

int Cancha::getCodigo() const { return codigo; } //const por ser lectura, no modifica el objeto
string Cancha::getDeporte() const { return deporte; }
double Cancha::getPrecioPorHora() const { return precioPorHora; }

void Cancha::setCodigo(int c) { codigo = c; }
void Cancha::setDeporte(const string& d) { deporte = d; }//const para que no se modifique el string original por si acaso basicamente
void Cancha::setPrecioPorHora(double p) { precioPorHora = p; }

char Cancha::getFranja(int index) const {// const basicamente porque es un get, prefiero trabajarlos asi por si acaso para no modificar nada
	if (index < 0 || index >= 12) { return 'X'; }//si se sale de los parametros retorna una X como para decir error
	return franjas[index];
}

void Cancha::setFranja(int index, char valor) {
	if (index < 0 || index >= 12) { return; } //para no salirse de lo permitido, si se sale no hace nada
	franjas[index] = valor;
}
