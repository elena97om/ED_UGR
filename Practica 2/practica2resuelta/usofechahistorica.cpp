#include<iostream>
#include <fstream>
#include "cronologia.h"

using namespace std;

int main() {
	
	ifstream infile;
	string file1 = "timeline_science.txt";
	string file2 = "timeline_algorithms.txt";

	cronologia cronologia1;
	cronologia cronologia2;
	cronologia cronologia3;

	infile.open(file1);
	if (infile.is_open()) {
		infile >> cronologia1;
		infile.close();
	}

	infile.open(file2);
	if (infile.is_open()) {
		infile >> cronologia2;
		infile.close();
	}

	cronologia cronologia4(cronologia1.getFechashistoricas());

	(cronologia2 == cronologia4) ? cout << "equal" << endl : cout << "not equal" << endl;
	(cronologia1 == cronologia4) ? cout << "equal" << endl : cout << "not equal" << endl;

	cout << endl << "Prueba de operadores =, == y +" << endl;
	cronologia1 += cronologia2;
	cronologia4 = cronologia4 + cronologia2;
	(cronologia1 == cronologia4) ? cout << "equal" << endl : cout << "not equal" << endl;

	fechahistorica fec(2007);
	fec.addAcontecimiento("Primer acont");
	cronologia1.addFechahistorica(fec);
	cronologia1.addAcontToFechahistorica(2007, "Segundo acont");
	cronologia1.addAcontToFechahistorica(2007, "Tercer acont");

	(cronologia1.isFechahistorica(2007)) ? cout << "is" << endl : cout << "isn't" << endl;
	cronologia1.deleteFechahistorica(2007);
	(cronologia1.isFechahistorica(2007)) ? cout << "is" << endl : cout << "isn't" << endl;
	
	fechahistorica fecha1(2008);
	fecha1.addAcontecimiento("aaa");
	fechahistorica fecha2(2008);
	fecha2.addAcontecimiento("bbb");
	(fecha1 == fecha2) ? cout << "is" << endl : cout << "isn't" << endl;
	fechahistorica fecha3(2008);
	fecha3.addAcontecimiento("ccc");
	fecha3.deleteAcontecimiento("ccc");

	fecha1 = fecha2 + fecha3;
	fecha1.print();

	return 0;
}
