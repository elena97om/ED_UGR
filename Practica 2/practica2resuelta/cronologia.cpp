#include "fechahistorica.h"
#include "cronologia.h"
#include <vector>
#include <iostream>
#include <string>

using namespace std;

cronologia::cronologia() {
}

void cronologia::setCronologia(const vector<fechahistorica>& fechashistoricas) {
	this->fchhsts = fechashistoricas;
}

cronologia::cronologia(const vector<fechahistorica>& fechashistoricas) {
	setCronologia(fechashistoricas);
}

void cronologia::order() {
	for (int i = 0; i < this->fchhsts.size() - 1; i++) {
		int minimo = i;
		for (int j = i + 1; j < this->fchhsts.size(); j++)
			if (this->fchhsts[j].getFecha() < this->fchhsts[minimo].getFecha())
				minimo = j;
		swap(this->fchhsts[i], this->fchhsts[minimo]);
	}
}

int cronologia::binarySearch(int fecha) {
	int middle;
	int bot = 0;
	int top = this->fchhsts.size() - 1;
	bool found = false;

	while ((bot <= top) && !found) {
		middle = (bot + top) / 2;
		if (this->fchhsts[middle].getFecha() == fecha)
			found = true;
		else if (this->fchhsts[middle].getFecha() < fecha)
			bot = middle + 1;
		else
			top = middle - 1;
	}

	if (found)
		return middle;
	else
		return this->fchhsts.size() - 1;
}

void cronologia::swap(fechahistorica& fch1, fechahistorica& fch2) {
	fechahistorica a = fch2;
	fch2 = fch1;
	fch1 = a;
}

cronologia cronologia::operator+(const cronologia& crnlg) {
	cronologia aux;
	for (int i = 0; i < this->fchhsts.size(); i++)
		aux.fchhsts.push_back(this->fchhsts[i]);

	for (int i = 0; i < crnlg.fchhsts.size(); i++)
		aux.addFechahistorica(crnlg.fchhsts[i]);

	int i = 0;
	while (i + 1 < this->fchhsts.size()) {
		if (this->fchhsts[i] == this->fchhsts[i + 1]) {
			this->fchhsts[i] = this->fchhsts[i] + this->fchhsts[i + 1];
			i--;
		}
		i++;
	}
	return aux;
}

vector<fechahistorica> cronologia::getFechashistoricas() {
	return this->fchhsts;
}

void cronologia::addFechahistorica(fechahistorica fchhst) {
	int pos = binarySearch(fchhst.getFecha());
	if (this->fchhsts[pos].getFecha() == fchhst.getFecha())
		this->fchhsts[pos] += fchhst;
	else {
		this->fchhsts.push_back(fchhst);
		order();
	}
}

void cronologia::setFechahistorica(int fecha, const vector<string>& fechhistorcas) {
	this->fchhsts[binarySearch(fecha)] = fechahistorica(fecha, fechhistorcas);
}

void cronologia::deleteFechahistorica(int fecha) {
	for (int i = 0; i < this->fchhsts.size(); i++)
		if (this->fchhsts[i].getFecha() == fecha)
			this->fchhsts.erase(this->fchhsts.begin() + i);
}

bool cronologia::isFechahistorica(int fecha) {
	for (int i = 0; i < this->fchhsts.size(); i++)
		if (this->fchhsts[i].getFecha() == fecha)
			return true;
	return false;
}

fechahistorica cronologia::getFechahistorica(int fecha) {
	for (int i = 0; i < this->fchhsts.size(); i++)
		if (this->fchhsts[i].getFecha() == fecha)
			return this->fchhsts[i];

	// No se deberia llegar aqui
	return fechahistorica();
}

ostream& operator<<(ostream& os, const cronologia& crnlg) {
	for (int i = 0; i < crnlg.fchhsts.size(); i++)
		os << crnlg.fchhsts[i] << '\n';
	return os;
}

istream& operator >> (istream& is, cronologia& crnlg) {
	if (is)
		while (is.peek() != '\0' && !is.eof()) {
			fechahistorica fchhistorica;
			is >> fchhistorica;
			crnlg.fchhsts.push_back(fchhistorica);
			crnlg.order();
		}
	return is;
}

void cronologia::addAcontToFechahistorica(int fecha, string acontecimiento) {
	fechahistorica aux = getFechahistorica(fecha);
	aux.addAcontecimiento(acontecimiento);
	setFechahistorica(fecha, aux.getAcontecimientos());
}

bool cronologia::operator==(const cronologia & crnlg) {
	if (this->fchhsts.size() != crnlg.fchhsts.size()) return false;

	for (int i = 0; i < this->fchhsts.size(); i++)
		if (this->fchhsts[i] != crnlg.fchhsts[i])
			return false;
	return true;
}

bool cronologia::operator!=(const cronologia & crnlg) {
	cronologia aux = cronologia(this->getFechashistoricas());

	return !(aux == crnlg);
}

void cronologia::operator+=(const cronologia crnlg) {
	cronologia aux;
	for (int i = 0; i < this->fchhsts.size(); i++)
		aux.fchhsts.push_back(this->fchhsts[i]);

	for (int i = 0; i < crnlg.fchhsts.size(); i++)
		aux.addFechahistorica(crnlg.fchhsts[i]);

	int i = 0;
	while (i + 1 < this->fchhsts.size()) {
		if (this->fchhsts[i] == this->fchhsts[i + 1]) {
			this->fchhsts[i] = this->fchhsts[i] + this->fchhsts[i + 1];
			i--;
		}
		i++;
	}
	this->setCronologia(aux.getFechashistoricas());
}
