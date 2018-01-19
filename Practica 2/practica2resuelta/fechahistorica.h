/**
* @file fechahistorica.h
* @brief A header file implementing an historical date
* @Author Ana Isabel Guerrero Tejera
* @Author Julián Arenas Guerrero
* @date 07/11/2017
**/

#ifndef __FECHAHISTORICA
#define __FECHAHISTORICA

#include <iostream>
#include <vector>
#include <string>

using namespace std;

/**
* @brief Tipo Abstracto de Datos para una fecha historica
* Una instancia del TDA fechahistorica.cpp en la que representamos mediante un vector de strings, los sucesos que tuvieron lugar ese año (
* El objeto está compuesto por un entero que representa la fecha del evento (Negativos para años antes de Cristo)
*/
class fechahistorica{
private:
	int fch;
	vector<string> aconts;

public:

	/**
	* @brief Constructor de fecha historica por defecto
	*/
	fechahistorica();
	
	/**
	* @brief Constructor de fecha historica
	* @param fch año de la fecha historica
	*/
	fechahistorica(int fch);

	/**
	* @brief Constructor de fechas historica
	* @param fch año de la feha historica
	* @param aconts acontecimientos de la fecha historica
	*/
	fechahistorica(int fch, const vector<string>& aconts);

	/**
	* @brief Constructor de copias para fechas historicas
	* @param fch fecha historica a copiar
	*/
	fechahistorica(const fechahistorica& fch);

	/**
	* @brief Devuelve el año de la fecha historica
	* @return Año de la fecha historica
	*/
	int getFecha();

	/**
	* @brief Devuelve un acontecimiento dada su posición en el vector
	* @param pos posición del acontencimiento que se quiere consultar en el vector
	* @return Acontecimiento en la posición indicada
	*/
	string& getAcontecimiento(int pos);

	/**
	* @brief Devuelve un vector con los acontecimientos que forman la fecha historica
	* @return Vector de los acontecimientos que forman la fecha historica
	*/
	vector<string> getAcontecimientos();

	/**
	* @brief Sustituye el año de la fecha historica por el facilitado por parametro
	* @param fch año de la fecha historica
	*/
	void setFecha(int fch);

	/**
	* @brief Cambia el vector de acontecimientos por uno nuevo
	* @param aconts vector de los nuevos acontecimientos a establecer
	*/
	void setAcontecimientos(const vector<string>aconts);

	/**
	* @brief Añade un nuevo acontecimiento a la fecha historica
	* @param acont string del acontecimiento a añadir a la fecha histórica
	*/
	void addAcontecimiento(string acont);

	/**
	* @brief Elimina un acontecimiento de la fecha historica dado el string del acontecimiento
	* @param acont string del acontecimiento a eliminar
	*/
	void deleteAcontecimiento(const string& acont);

	/**
	* @brief Elimina un acontecimiento de la fecha historica dada la posicion del acontecimiento
	* @param pos posicion del acontecimiento a eliminar
	*/
	void deleteAcontecimiento(int pos);

	/**
	* @brief Devuelve el numero de acontecimientos de la fecha historica
	* @return Numero de acontecimientos de la fecha historica
	*/
	int numberOfAcontecimientos();

	/**
	* @brief Devuelve si el acontecimiento dado esta en la fecha historica
	* @param acont string del acontecimiento a consultar
	* @return True si el acontecimiento está en la fecha historica
	*/
	bool isAcontecimiento(string acont);

	/**
	* @brief Asigna a la fecha historica un nuevo año y unos acontecimientos dados por parametros
	* @param fch año de la fecha historica 
	* @param aconts acontecimientos de la fecha historica
	*/
	void asignar(int fch, vector<string> aconts);
	
	/**
	* @brief Operador de asignacion de fechas histoicas
	* @param fchhst fecha historica a asignar
	* @return Referencia a la fecha historica asignada
	*/
	fechahistorica& fechahistorica::operator=(const fechahistorica& fchhst);

	/**
	* @brief Compara dos fechas historicas (deben ser iguales el año y los acontecimientos en el mismo orden)
	* @param fch fecha historica a comparar
	* @return True si las fechas historicas son iguales
	*/
	bool comparar(fechahistorica fch);

	/**
	* @brief Muestra por pantalla una fecha historica
	*/
	void print();

	/**
	* @brief Suma de dos fechas historicas
	* @param fchhst fecha historica a sumar
	* @return Fecha historica resultante de la suma
	*/
	fechahistorica operator+(const fechahistorica fchhst);

	/**
	* @brief Operador suma y asignacion de fechas historicas
	* @param fchhst fecha historica a añadir
	*/
	void operator += (const fechahistorica fchhst);

	/**
	* @brief Operador de igualdad de fechas historicas (dos fechas historicas son iguales si coinciden el año y los acontecimientos)
	* @param fch fecha historica a comparar
	* @return True si las fechas historicas son iguales
	*/
	bool operator ==(const fechahistorica &fch);

	/**
	* @brief Operador de desigualdad de fechas historicas (dos fechas historicas son distintas si no coinciden el año o los acontecimientos)
	* @param fch fecha historica a comparar
	* @return True si las fechas historicas son ditintas
	*/
	bool operator !=(const fechahistorica &fch);

	/**
	* @brief Operador flujo de salida de una fecha historica
	* @param os flujo de salida
	* @param fch fecha historica a imprimir
	* @return Referencia al flujo de salida
	*/
	friend ostream& operator<< (ostream& os, const fechahistorica& fch);

	/**
	* @brief Operador flujo de entrada de una fecha historica
	* @param is flujo de entrada
	* @param fch fecha historica a leer
	* @return Referencia al flujo de entrada
	*/
	friend istream& operator>> (istream& is, fechahistorica& fch);

	/**
	* @brief Operador menor que para fecha historica (una fecha es menor que otra si el año de la fecha historica es anterior al de la otra)
	* @param fchhst fecha historica a comparar
	* @return True si la fecha historica es menor a la pasada por parametro
	*/
	bool operator<(const fechahistorica& fchhst);

	/**
	* @brief Operador mayor que para fecha historica (una fecha es mayor que otra si el año de la fecha historica es posterior al de la otra)
	* @param fchhst fecha historica a comparar
	* @return True si la fecha historica es mayor a la pasada por parametro
	*/
	bool operator>(const fechahistorica& fchhst);
};

#endif
