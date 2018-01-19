/**
  * @file pila_max_vd.h
  * @brief Fichero cabecera del TDA Pila max
  *
  * Gestiona una secuencia de elementos con facilidades para la insercion y
  * borrado de elementos en un extremo
  */

#ifndef __PILA_MAX_VD
#define __PILA_MAX_VD

#include <iostream>

using namespace std;

struct elemento {
	int ele;		// elemento a almacenar
	int maximo;		// el maximo
};

ostream& operator<<(ostream & os, const elemento & e);

/**
 *  @brief T.D.A. Pila_max
 *
 * Una instancia @e v del tipo de datos abstracto Pila_max sobre el tipo @c entero es
 * una lista de pares de elementos <entero,entero > con un funcionamiento @e LIFO (Last In,
 * First Out). En una pila, las operaciones de insercion y borrado de elementos
 * tienen lugar en uno de los extremos denominado @e Tope. Una pila_max de longitud
 * @e n la denotamos

 * - [<a1,max{a1...an}>,<a2,max{a2...an}>,<a3,max{a3...an}>,..,<an,an>>

 * donde @e ai es el elemento de la posicion i-esima. Y @e max{ai,...aj} es el maximo del conjunto de * elementos que van desde @e ai a @e aj
 * En esta pila, tendremos acceso unicamente al elemento del @e Tope, es decir,
 * a @e an. El borrado o consulta de un elemento sera sobre  @e an, y la
 * insercion de un nuevo elemento se hara sobre este. Quedando el elemento
 * insertado como @e Tope de la pila.

 * Si @e n=0 diremos que la pila esta vacia.

 * El espacio requerido para el almacenamiento es O(n). Donde n es el numero de
 * elementos de la Pila_max.
 *
 * @author Ana Isabel Guerrero Tejera
 * @author Julian Arenas Guerrero
 * @date Noviembre 2017
 */
class Pila_max {
private:
	elemento *datos;
	int reservados;
	int nelem;

	// Pushes an element, but forces the max to be a different number than the supposed to
	void forcePush(int e, int max);
	void resize(int n);

public:
	/**
     * @brief Constructor por defecto
     */
	Pila_max();

	/**
	* @brief Constructor de copias
	* @param pm La pila de la que se hara la copia.
	*/
	Pila_max(const Pila_max & pm);

	/**
	* @brief Destructor
	*/
	~Pila_max();

	/**
	* @brief Vacia la pila
	*/
	void clear();

	/**
	* @brief Operador de asignacion
	* @param pm La pila que se va a asignar.
	*/
	Pila_max & operator = (const Pila_max & pm);

	/**
	* @brief Aniade un elemento "encima" del tope de la pila
	* @param e Elemento que se va a aniadir.
	*/
	void push(int e);

	/**
	* @brief Quita el elemento del tope de la pila
	*/
	void pop();

	/**
	* @brief Devuelve el elemento del tope de la pila y el maximo
	*/
	elemento peek() const { return datos[nelem - 1]; }

	/**
	* @brief Devuelve el elemento del tope de la pila
	*/
	int elem() const { return datos[nelem - 1].ele; }

	/**
	* @brief Devuelve el maximo de la pila
	*/
	int max() const { return datos[nelem - 1].maximo; }

	/**
     * @brief Comprueba si la pila esta vacia
     */
	bool empty() const { return nelem == 0; }

	/**
     * @brief Devuelve el numero de elementos de la pila
     */
	int size() const { return nelem; }

	/**
	* @brief Operador de igualdad. Dos pilas son iguales si tienen los mismos maximos
	* @param pm La pila con la que comparar
	*/
	bool operator == (const Pila_max & pm) { return this->max() == pm.max(); };

	/**
	* @brief Operador de desigualdad. Dos pilas son distintas si tienen maximos distintos
	* @param pm La pila con la que comparar
	*/
	bool operator != (const Pila_max & pm) { return this->max() != pm.max(); };

	/**
	* @brief Operador de comparacion menor que. Una pila es menor que otra si su maximo es menor
	* @param pm La pila con la que comparar
	*/
	bool operator < (const Pila_max & pm) { return this->max() < pm.max(); }

	/**
	* @brief Operador de comparacion mayor que. Una pila es mayor que otra si su maximo es mayor
	* @param pm La pila con la que comparar
	*/
	bool operator > (const Pila_max & pm) { return this->max() > pm.max(); }

	/**
	* @brief Operador flujo de salida
	*/
	friend ostream & operator << (ostream & os, const Pila_max & pm);

	/**
	* @brief Operador flujo de entrada
	*/
	friend istream & operator >> (istream & is, Pila_max & pm);
};

#endif
