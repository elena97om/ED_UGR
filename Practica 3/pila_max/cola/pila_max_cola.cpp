#include "pila_max_cola.h"
#include <sstream>

ostream & operator << (ostream & os, const elemento & e) {
	os << "(" << e.ele << " | " << e.maximo << ")";
	return os;
}

Pila_max::Pila_max(const Pila_max & pm) {
	datos = pm.datos;
}

Pila_max & Pila_max::operator = (const Pila_max & pm) {
	datos = pm.datos;
	return *this;
}

void Pila_max::push(int e) {
	elemento auxElem;
	int contador = 0;

	auxElem.ele = e;

	if (datos.vacia())
		auxElem.maximo = e;
	else
		while (contador < datos.num_elementos()) {
			contador++;
			if (contador == datos.num_elementos())
				if (datos.frente().maximo > e)
					auxElem.maximo = datos.frente().maximo;
				else
					auxElem.maximo = e;
			datos.poner(datos.frente());
			datos.quitar();
		}
	datos.poner(auxElem);
}

void Pila_max::pop() {
	int contador = 0;

	while (contador < datos.num_elementos()) {
		contador++;
		if (contador < datos.num_elementos())
			datos.poner(datos.frente());
		datos.quitar();
	}
}

elemento Pila_max::peek() {
	int contador = 0;
	elemento auxElem;

	while (contador < datos.num_elementos()) {
		contador++;
		if (contador == datos.num_elementos())
			auxElem = datos.frente();
		datos.poner(datos.frente());
		datos.quitar();
	}
	return auxElem;
}

int Pila_max::elem() {
	int contador = 0;
	int auxElem;

	while (contador < datos.num_elementos()) {
		contador++;
		if (contador == datos.num_elementos())
			auxElem = datos.frente().ele;
		datos.poner(datos.frente());
		datos.quitar();
	}
	return auxElem;
}

int Pila_max::max()  {
	int auxMax = 0, contador = 0;

	while (contador < datos.num_elementos()) {
		contador++;
		if (contador == datos.num_elementos())
			auxMax = datos.frente().maximo;
		datos.poner(datos.frente());
		datos.quitar();
	}
	return auxMax;
}

void Pila_max::clear() {
	// ¿ESTO ESTA BIEN HECHO?
	Pila_max aux;
	*this = aux;
}

ostream & operator << (ostream & os, const Pila_max & pm) {
	int contador = 0;
	Pila_max colaAux = pm;

	while (contador < colaAux.datos.num_elementos()) {
		contador++;
		os << colaAux.datos.frente() << endl;
		colaAux.datos.poner(pm.datos.frente());
		colaAux.datos.quitar();
	}
	return os;
}

istream & operator >> (istream & is, Pila_max & pm) {
	if (is)
		while (is.peek() != '\0' && !is.eof()) {
			int num;
			is >> num;
			pm.push(num);
		}
	return is;
}
