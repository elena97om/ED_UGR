#include <iostream>
#include <fstream>
#include <sstream>
#include "pila_max_vd.h"

using namespace std;

int main(int argc, char * argv[]) {
	cout << "hola";
	Pila_max pm1;
	Pila_max pm2;

    ifstream infile;
	infile.open("pila_max.txt");
	if (infile.is_open()) {
		infile >> pm1;
		infile.close();
	}

	for (int i = 10; i >= 0; i--)
		pm2.push(i);

	//pm1.clear();
	pm2.clear();

	pm2.push(102);
	pm2.push(20);
	pm2.push(15);
	pm2.push(30);

	for (int i = 10; i < 19; i++)
		pm2.push(i);

	pm2.pop();
	cout << pm2.peek() << endl;

	string outs = pm1 > pm2 ? "True" : "False";
	cout << pm1.max() << endl << pm2.max() << endl << outs << endl;

	cout << pm1;
	cout << endl << endl << endl;

	cout << pm2 << endl;

	//pm2.clear();
	cout << pm2.empty() << endl << pm2.elem() << endl << pm2.max() << endl << pm2.peek() << endl;

	pm1 = pm2;

	pm1.pop();
	cout << pm1;

	return 0;
}
