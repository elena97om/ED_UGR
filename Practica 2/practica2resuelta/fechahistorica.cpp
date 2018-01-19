#include "fechahistorica.h"
#include <sstream>
#include <cassert>

using namespace std;

fechahistorica::fechahistorica() {
	this->fch = 0;
}

fechahistorica::fechahistorica(int fch) {
	this->fch = fch;
}

fechahistorica::fechahistorica(int fch, const vector<string>& aconts) {
	this->fch = fch;
	this->aconts = aconts;
}

fechahistorica::fechahistorica(const fechahistorica& fchhst) {
	this->fch = fchhst.fch;
	this->aconts = fchhst.aconts;
}

void fechahistorica::setFecha(int fecha) {
	this->fch = fecha;
}

int fechahistorica::getFecha() {
	return this->fch;
}

string& fechahistorica::getAcontecimiento(int pos) {
	return this->aconts.at(pos);
}

void fechahistorica::setAcontecimientos(const vector<string>aconts) {
	this->aconts = aconts;
}

void fechahistorica::addAcontecimiento(string acont) {
	this->aconts.push_back(acont);
}

vector<string>fechahistorica::getAcontecimientos() {
	return this->aconts;
}

void fechahistorica::deleteAcontecimiento(int pos) {
	aconts.erase(aconts.begin() + pos);
}

void fechahistorica::deleteAcontecimiento(const string& acont) {
	for (int i = 0; i < this->aconts.size(); i++)
		if (this->aconts[i] == acont)
			this->aconts.erase(aconts.begin() + i);
}

void fechahistorica::asignar(int fch, vector<string> aconts) {
	this->fch = fch;
	this->aconts = aconts;
}

fechahistorica& fechahistorica::operator=(const fechahistorica& fchhst) {
	this->fch = fchhst.fch;
	this->aconts = fchhst.aconts;

	return *this;
}

bool fechahistorica::comparar(fechahistorica fchhst) {
	return (this->fch == fchhst.fch);
}

void fechahistorica::print() {
	cout << this->fch;

	for (int i = 0; i < this->aconts.size(); i++)
		cout << ("#" + this->aconts[i]);

	cout << endl;
}

fechahistorica fechahistorica::operator+(const fechahistorica fchhst) {
	if (this->fch == fchhst.fch)
		for (int i = 0; i < fchhst.aconts.size(); i++)
			this->aconts.push_back(fchhst.aconts[i]);

	return *this;
}

void fechahistorica::operator+=(const fechahistorica fchhst) {
	if (this->fch == fchhst.fch)
		for (int i = 0; i < fchhst.aconts.size(); i++)
			this->aconts.push_back(fchhst.aconts[i]);
}

bool fechahistorica::operator== (const fechahistorica & fchhst) {
	if (this->fch != fchhst.fch) return false;
	if (this->aconts.size() != fchhst.aconts.size()) return false;

	for (int i = 0; i < this->aconts.size(); i++)
		if (this->aconts[i] != fchhst.aconts[i])
			return false;
		
	return true;
}

bool fechahistorica::operator!= (const fechahistorica & fchhst) {
	fechahistorica aux = fechahistorica(this->getFecha(), this->getAcontecimientos());
	
	return !(aux == fchhst);
}

ostream& operator<< (ostream & os, const fechahistorica & fchhst) {
	string fchaconts;
	fchaconts = to_string(fchhst.fch);

	for (int i = 0; i < fchhst.aconts.size(); i++)
		fchaconts += ("#" + fchhst.aconts[i]);

	fchaconts += '\n';
	return os << fchaconts;
}

istream& operator >> (istream& is, fechahistorica& fchhst) {
	string aux;
	vector<string> acontecimientosLeidos = {};

	getline(is, aux, '#');

	fchhst.fch = stoi(aux);

	getline(is, aux);
	istringstream ss(aux);

	while (getline(ss, aux, '#'))
		acontecimientosLeidos.push_back(aux);
	fchhst.aconts = acontecimientosLeidos;

	return is;
}

int fechahistorica::numberOfAcontecimientos() {
	return aconts.size();
}

bool fechahistorica::isAcontecimiento(string acont){
	for (int i = 0; i < acont.size(); i++)
		if (aconts[i] == acont)
			return true;
	return false;
}

bool fechahistorica::operator<(const fechahistorica& fchhst) {
	return (this->fch < fchhst.fch);
}

bool fechahistorica::operator>(const fechahistorica& fchhst) {
	return (this->fch > fchhst.fch);
}

