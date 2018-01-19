#include <sstream>
#include "pila_max_vd.h"

ostream & operator << (ostream & os, const elemento & e) {
	os << "(" << e.ele << " | " << e.maximo << ")";
	return os;
}

void Pila_max::forcePush(int e, int max) {
	if (nelem == reservados) resize(2 * reservados);
	datos[nelem].ele = e;
	datos[nelem].maximo = max;
	nelem++;
}

void Pila_max::resize(int n) {
	if (nelem < n) {
		elemento *p;
		p = new elemento[n];
		for (int i = 0; i < nelem; i++)
			p[i] = datos[i];

		delete[] datos;
		datos = p;
		reservados = n;
	}
}

Pila_max::Pila_max() {
	nelem = 0;
	// Reservamos espacio para diez elementos
	reservados = 10;
	datos = new elemento[reservados];
}

Pila_max::Pila_max(const Pila_max & pm) {
	reservados = pm.reservados;
	nelem = pm.nelem;
	datos = new elemento[pm.reservados];

	for (int i = 0; i < nelem; i++)
		datos[i] = pm.datos[i];
}

Pila_max::~Pila_max() {
	// ¿ESTO ES CORRECTO?
	delete[] datos;
}

Pila_max & Pila_max::operator = (const Pila_max & pm) {
	if (this != &pm) {
		nelem = pm.nelem;

		if (pm.reservados != reservados) {
			reservados = pm.reservados;
			resize(reservados);
		}

		for (int i = 0; i < nelem; i++) {
			datos[i].ele = pm.datos[i].ele;
			datos[i].maximo = pm.datos[i].maximo;
		}
		return *this;
	}
}

void Pila_max::push(int e) {
	if (nelem == reservados) resize(2*reservados);
	datos[nelem].ele = e;

	// Si es el unico elemento de la pila es el maximo
	if (nelem == 0) datos[nelem].maximo = e;
	// Si no es el unico elemento en la pila, comprobamos si es el maximo
	else {
		int maximoAnterior = datos[nelem - 1].maximo;
		if (maximoAnterior < e)
			datos[nelem].maximo = e;
		else
			datos[nelem].maximo = maximoAnterior;
	}
	nelem++;
}

void Pila_max::pop() {
	nelem--;
	if (nelem < reservados/4) resize(reservados / 2);
}

void Pila_max::clear() {
	delete[] datos;
	nelem = 0;
	// Reservamos espacio para diez elementos
	reservados = 10;
	datos = new elemento[reservados];
}

ostream & operator << (ostream & os, const Pila_max & pm) {
	Pila_max aux1 = pm;
	Pila_max aux2 = pm;
	aux2.clear();

	while (!aux1.empty()) {
		aux2.forcePush(aux1.elem(), aux1.max());
		aux1.pop();
	}

	while (!aux2.empty()) {
		os << aux2.peek() << endl;
		aux2.pop();
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
