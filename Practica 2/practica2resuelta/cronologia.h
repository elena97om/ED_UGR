#ifndef __CRONOLOGIA
#define __CRONOLOGIA

#include <iostream>
#include <string>
#include "fechahistorica.h"

using namespace std;

class cronologia {

private:
	vector<fechahistorica> fchhsts;


	/**
	* @brief Ordena la cronologia por fecha creciente
	*/
	void order();

	/**
	* @brief Intercanbia la posicion de dos fechas historicas en el vector de fechas historicas de la cronologia
	* @param fch1 fecha a intercambiar
	* @param fch2 fecha a intercambiar
	*/
	void swap(fechahistorica& fch1, fechahistorica& fch2);

public:

	/**
	* @brief Constructor de cronologia por defecto
	*/
	cronologia();

	/**
	* @brief Constructor de cronologia dado un conjunto de fechas historicas
	* @param fechashistoricas conjunto de fechas historicas
	*/
	cronologia(const vector<fechahistorica>& fechashistoricas);

	/**
	* @brief Operador de suma para cronologias
	* @param crnlg cronologia sumar
	* @return fecha historica resultante de la suma de las fechas historicas
	*/
	cronologia operator+(const cronologia& crnlg);

	/**
	* @brief Devuelve un vector con las fechas historicas de la cronologia
	* @return Vector con las fechas historicas de la cronologia
	*/
	vector<fechahistorica> getFechashistoricas();

	/**
	* @brief Añade una fecha historica a la cronologia
	* @param fchhst fecha historica a añadir
	*/
	void addFechahistorica(fechahistorica fchhst);

	/**
	* @brief Devuelve la posicion de una fecha historica en el vector de cronologia dado el año
	* @param fecha año de la fecha historica a consultar
	* @return Posicion de la fecha historica del año dado en la cronologia
	*/
	int binarySearch(int fecha);

	/**
	* @brief Añade un acontecimiento a una fecha historica de la cronologia dado el año
	* @param fecha año de la fecha historica a la que añadir el acontecimiento
	* @param acontecimiento acontecimiento a añadir
	*/
	void addAcontToFechahistorica(int fecha, string acontecimiento);

	/**
	* @brief Elimina una fecha historica de la cronologia dada el año de la fechahistorica
	* @param fecha año de la fecha historica a eliminar
	*/
	void deleteFechahistorica(int fecha);

	/**
	* @brief Devuelve si el año facilitado coincide con el de alguna fecha historica incluida en la cronologia
	* @param fecha año de la fecha historica a consultar
	* @return True si el año facilitado coincide con el de alguna fecha historica de la cronologia
	*/
	bool isFechahistorica(int fecha);

	/**
	* @brief Devuelve una fecha de la cronologia dadoo el año
	* @param fecha año de la fecha historica a obtener
	* @return fecha historica de la cronologia que coincide con el año facilitado
	*/
	fechahistorica getFechahistorica(int fecha);

	/**
	* @brief Operador flujo de salida de una cronologia
	* @param os flujo de dalida
	* @param crnlg cronologia a imprimir
	* @return Referencia al flujo de salida
	*/
	friend ostream& operator << (ostream& os, const cronologia& crnlg);

	/**
	* @brief Operador flujo de entrada de una cronologia
	* @param is flujo de entrada
	* @param crnlg cronologia a leer
	* @return Referencia al flujo de entrada
	*/
	friend istream& operator >> (istream& is, cronologia& crnlg);

	/**
	* @brief Sustituye el vector de fechas historicas de la cronologia por el facilitado por parametro
	* @param fechashistoricas vector de fechas historicas a asignar a la cronologia
	*/
	void setCronologia(const vector<fechahistorica>& fechashistoricas);

	/**
	* @brief Asigna el vector de acontecimientos facilitado por parametro a la fecha historica de la cronologia que coincide con el año facilitado por parametro
	* @param fecha año de la fecha historica de la cronologia a modificar
	* @param fechahistorica vector de acontecimientos que asignar a la fecha historica a modificar
	*/
	void setFechahistorica(int fecha, const vector<string>& fechahistorica);

	/**
	* @brief Operador de igualdad de cronologia (dos cronologias son iguales si todas sus fechas historicas son iguales)
	* @param crnlg cronologia a comparar
	* @return True si las dos cronologias son iguales
	*/
	bool operator ==(const cronologia &crnlg);

	/**
	* @brief Operador de desigualdad de cronologia (dos cronologias son distintas si alguna de sus fechas historicas son distintas)
	* @param crnlg cronologia a comparar
	* @return True si las dos cronologias son distintas
	*/
	bool operator !=(const cronologia &crnlg);

	/**
	* @brief Operador suma y asignación de dos cronologias
	* @param crnlg cronologia a añadir
	*/
	void operator += (const cronologia crnlg);
};

#endif
