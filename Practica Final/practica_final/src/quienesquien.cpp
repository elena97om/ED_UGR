// Julian Arenas Guerrero
// Ana Isabel Guerrero Tejada


#include "../include/quienesquien.h"
#include <sstream>
#include <iostream>
#include <iterator>
#include <math.h>
#include <algorithm>

QuienEsQuien::QuienEsQuien(){
	//TODO :)
}
QuienEsQuien::QuienEsQuien(const QuienEsQuien &quienEsQuien){
	//TODO :)
}
QuienEsQuien& QuienEsQuien::operator= (const QuienEsQuien &quienEsQuien){
	//TODO :)
	return *this;
}
QuienEsQuien::~QuienEsQuien(){
	this->limpiar();
}

void QuienEsQuien::limpiar(){
	//TODO :)
}

template <typename T>
std::ostream& operator<< (std::ostream& out, const std::vector<T>& v) {
  if ( !v.empty() ) {
    out << '[';
    std::copy (v.begin(), v.end(), std::ostream_iterator<T>(out, ", "));
    out << "\b\b]";
  }
  return out;
}

void QuienEsQuien::mostrar_estructuras_leidas(){
	cout << "personajes: "<< (this->personajes) << endl;
	cout << "atributos:  "<< (this->atributos)  << endl;
	cout << "tablero:    "<< endl;

	// Escribe la cabecera del tablero
	for(vector<string>::iterator it_atributos = this->atributos.begin();
		it_atributos != this->atributos.end();
		it_atributos++){
		cout << *it_atributos << "\t";
	}
	cout <<endl;

	int indice_personaje = 0;
	for(vector<vector<bool>>::iterator it_tablero_atributos = tablero.begin();
		it_tablero_atributos!= tablero.end();
		it_tablero_atributos++){

		string personaje = this->personajes[indice_personaje];
		int indice_atributo = 0;
		for(vector<bool>::iterator it_atributos_personaje = (*it_tablero_atributos).begin();
			it_atributos_personaje != (*it_tablero_atributos).end();
			it_atributos_personaje++){

			cout << *it_atributos_personaje<<"\t";

			indice_atributo++;
		}

		cout << personaje << endl;

		indice_personaje++;
	}

}

/**
  * @brief Devuelve una copia de la cadena original sin las subcadenas no deseadas.
  *
  * @param cadena_original Cadena de la que se eliminan las subcadenas no deseadas.
  * @param cadena_a_eliminar Subcadena que se busca y se elimina.
  *
  * @return Copia de la cadena original sin las subcadenas no deseadas.
  */
string limpiar_string(string cadena_original,string cadena_a_eliminar){
	string linea(cadena_original);

	while(linea.find_first_of(cadena_a_eliminar) != std::string::npos){
		linea.erase(linea.find_first_of(cadena_a_eliminar),cadena_a_eliminar.length());
	}

	return linea;
}

istream& operator >> (istream& is, QuienEsQuien &quienEsQuien) {
	quienEsQuien.limpiar();

  	if(is.good()){
  		string linea;
    	getline(is, linea, '\n');

    	linea = limpiar_string(linea,"\r");

    	while(linea.find('\t') != string::npos ){
    		string atributo = linea.substr(0,linea.find('\t'));
			quienEsQuien.atributos.push_back(atributo);
    		linea = linea.erase(0,linea.find('\t')+1);
    	}

		assert(linea ==  "Nombre personaje");
	}

    while( is.good() ) {
    	string linea;
    	getline(is, linea, '\n');
    	linea = limpiar_string(linea,"\r");

    	//Si la linea contiene algo extrae el personaje. Si no lo es, la ignora.
    	if(linea != ""){;
	    	vector<bool> atributos_personaje;

	    	int indice_atributo=0;
	    	while(linea.find('\t') != string::npos){
	    		string valor = linea.substr(0,linea.find('\t'));

	    		assert(valor == "0" || valor == "1");

	    		bool valor_atributo = valor == "1";

	    		atributos_personaje.push_back(valor_atributo);

	    		linea = linea.erase(0,linea.find('\t')+1);
	    		indice_atributo++;
			}

			string nombre_personaje = linea;

	    	quienEsQuien.personajes.push_back(nombre_personaje);
	    	quienEsQuien.tablero.push_back(atributos_personaje);
	    }
  	}

	return is;
}

ostream& operator << (ostream& os, const QuienEsQuien &quienEsQuien){
	//Escribimos la cabecera, que contiene los atributos y al final una columna para el nombre
	for(vector<string>::const_iterator it_atributos = quienEsQuien.atributos.begin();
		it_atributos != quienEsQuien.atributos.end();
		it_atributos++){

		os  << *it_atributos << "\t";
	}
	os << "Nombre personaje" << endl;

	//Rellenamos con ceros y unos cada l�nea y al final ponemos el nombre del personaje.
	for(int indice_personaje=0;indice_personaje<quienEsQuien.personajes.size();indice_personaje++){
		for(int indice_atributo=0;indice_atributo<quienEsQuien.atributos.size();indice_atributo++){

			os  << quienEsQuien.tablero[indice_personaje][indice_atributo] << "\t";
		}
		os  << quienEsQuien.personajes[indice_personaje] << endl;
	}

	return os;
}

/**
  * @brief Convierte un n�mero a un vector de bool que corresponde
  *        con su representaci�n en binario con un numero de digitos
  *        fijo.
  *
  * @param n N�mero a convertir en binario.
  * @param digitos N�mero de d�gitos de la representaci�n binaria.
  *
  * @return Vector de booleanos con la representaci�n en binario de @e n
  *      con el n�mero de elementos especificado por @e digitos.

  */
vector<bool> convertir_a_vector_bool(int n, int digitos) {
  vector<bool> ret;
  while(n) {
    if (n&1){
      ret.push_back(true);
    } else{
      ret.push_back(false);
    }
    n>>=1;
  }

  while(ret.size()<digitos){
  	ret.push_back(false);
  }

  reverse(ret.begin(),ret.end());
  return ret;
}

bintree<Pregunta> QuienEsQuien::crear_arbol() {
	bintree<Pregunta> Arb(Pregunta(atributos[0], tablero.size()));
	construir_arbol(Arb, Arb.root(), 0, tablero, personajes);

	return Arb;
}

void QuienEsQuien::construir_arbol(bintree<Pregunta> & Arb, bintree<Pregunta>::node n, int index_atributo, const vector<vector<bool> > &tableroAux, const vector<string> &personajes){
	// Nos traemos tambien un vector con los personajes para no tener que hacer una búsqueda del nombre cuando llegamos a los nodos hoja
	vector<vector<bool> > tablero_left, tablero_right;
	vector<string> personajes_left, personajes_right;

	for (int i = 0; i < tableroAux.size(); i++) {
		if (tableroAux[i][index_atributo]) {	// 1 evaluates to true, 0 evaluates to false
			tablero_left.push_back(tableroAux[i]);
			personajes_left.push_back(personajes[i]);
		}
		else {
			tablero_right.push_back(tableroAux[i]);
			personajes_right.push_back(personajes[i]);
		}
	}

	index_atributo = index_atributo + 1;

	if (personajes_left.size() == 1)
		Arb.insert_left(n, Pregunta(personajes_left[0], 1));
	else if (personajes_left.size() > 1)
		Arb.insert_left(n, Pregunta(atributos[index_atributo], tablero_left.size()));

	if (personajes_right.size() == 1)
		Arb.insert_right(n, Pregunta(personajes_right[0], 1));
	else if (personajes_right.size() > 1)
		Arb.insert_right(n, Pregunta(atributos[index_atributo], tablero_right.size()));

	if (index_atributo < atributos.size()) {// Si todavia quedan atributos (preguntas)
		if (personajes_left.size() > 1)
			construir_arbol(Arb, n.left(), index_atributo, tablero_left, personajes_left);
		if (personajes_right.size() > 1)
			construir_arbol(Arb, n.right(), index_atributo, tablero_right, personajes_right);
	}
}

void QuienEsQuien::usar_arbol(bintree<Pregunta> arbol_nuevo){
	arbol = arbol_nuevo;
}

void QuienEsQuien::iniciar_juego(){
	set<string>::iterator it;
	string respuesta = "si";
	jugada_actual = arbol.root();

	while (respuesta == "si") {
		while (!(*jugada_actual).es_personaje()) {
			cout << preguntas_formuladas(jugada_actual);

			cout << "Personajes levantados: ";
			set<string> personajes_levantados = informacion_jugada(jugada_actual);
			int contador = 1;
			for (it=personajes_levantados.begin(); it!=personajes_levantados.end(); ++it) {
    			cout << (*it);
				if (contador < personajes_levantados.size()) cout << ", ";
				else cout << ".";
				contador++;
			}

			cout << endl << *jugada_actual << endl << "Respuesta: ";
			cin >> respuesta;
			while (respuesta != "si" && respuesta != "no") {
				cout << "Introduce una respuesta válida (si/no): ";
				cin >> respuesta;
			}
			cout << endl;

			if (respuesta == "si")
				jugada_actual = jugada_actual.left();
			else if (respuesta == "no")	// no need for this if condition, bit code is easier to understand
				jugada_actual = jugada_actual.right();
		}

		cout << "¡Ya lo sé! tu personaje es " << (*jugada_actual).obtener_personaje() << "." << endl << endl << endl;

		jugada_actual = arbol.root();

		cout << "¿Quieres empezar otra partida?: ";
		cin >> respuesta;
		while (respuesta != "si" && respuesta != "no") {
			cout << "Introduce una respuesta válida (si/no): ";
			cin >> respuesta;
	}

		if (respuesta == "si") {
			jugada_actual = arbol.root();
			cout << endl << endl;
		}
		else if (respuesta == "no")	// no need for this if condition, bit code is easier to understand
			cout << "¡Hasta otra!" << endl;
	}
}

set<string> QuienEsQuien::informacion_jugada(bintree<Pregunta>::node jugada_actual){
	set<string> personajes_levantados;

	calcular_informacion_jugada(arbol, jugada_actual, personajes_levantados);

	return personajes_levantados;
}

void QuienEsQuien::calcular_informacion_jugada(const bintree<Pregunta> &a, bintree<Pregunta>::node n, set<string> &nombres){
	if (!n.null()) {	// In case we use the function in a raw tree
		if ((*n).es_personaje())
			nombres.insert((*n).obtener_personaje());
	    else if (!n.right().null() || !n.left().null()) {// Si no es una hoja
		    calcular_informacion_jugada (a, n.right(), nombres);
	      	calcular_informacion_jugada (a, n.left(), nombres);
	    }
	}
}

string QuienEsQuien::preguntas_formuladas(bintree<Pregunta>::node jugada){
	// Como el enunciado no pide ningun orden concreto en el que mostrar las preguntas realizadas
	// vamos a mostrar primero las más recientes. Si quiésemos mostrar primero las más antiguas, podrívamos
	// haberlo hecho con una pila de strings, o haber hecho una función recursiva ...
	bintree<Pregunta>::node parentAux;
	string info = "";

	if (jugada != arbol.root())
		info = "El personaje oculto tiene las siguientes características:\n";

	while (jugada != arbol.root()) {
		parentAux = jugada.parent();
		info += "    ";
		info += (*parentAux).obtener_pregunta();
		if (parentAux.left() == jugada)
			info += " - si\n";
		else if (parentAux.right() == jugada)	// This if condition is not neccessary, but makes code easier to understand :)
			info += " - no\n";

		jugada = parentAux;
	}

	return info;
}

void QuienEsQuien::aniade_personaje(string nombre, vector<bool> caracteristicas){
	// Precondition: there has to be at least one remaining attribute, which makes the new character unique
	// Precondition: root node must be at least one Pregunta (this means root node is a Pregunta and not a Personaje)
	// Precondition: the Pregunta which makes the personaje to add unique, cannot be a question which was deleted when we did eliminar_nodos_redundantes()

	bintree<Pregunta>::node n = arbol.root();
	int contador = 0, personajeHojaIndex = -1, siguienteAtributoIndex = -1;
	string ultimoAtributo = "";
	bool atributoValidoEncontrado = false;

	personajes.push_back(nombre);
	tablero.push_back(caracteristicas);

	while (!(*n).es_personaje()) {
		if (atributos[contador] == (*n).obtener_pregunta()) {	// If this Pregunta was deleted when we did eliminar_nodos_redundantes(), go to next
			if (caracteristicas[contador]) {
				(*n) = Pregunta((*n).obtener_pregunta(), (*n).obtener_num_personajes() + 1);  // Update num_personajes of Pregunta
				n = n.left();
			}
			else {
				(*n) = Pregunta((*n).obtener_pregunta(), (*n).obtener_num_personajes() + 1);  // Update num_personajes of Pregunta
				n = n.right();
			}
		}
		contador++;
	}

	for (int i = 0; i < personajes.size(); i++)	// Find the index of the character in tablero
		if (personajes[i] == (*n).obtener_personaje())
			personajeHojaIndex = i;

	ultimoAtributo = (*(n.parent())).obtener_pregunta();

	for (int i = 0; i < atributos.size() - 1; i++)
		if ((atributos[i] == ultimoAtributo))
			siguienteAtributoIndex = i + 1;

	while (!atributoValidoEncontrado) {
		if (tablero[personajeHojaIndex][siguienteAtributoIndex] != tablero[tablero.size() - 1][siguienteAtributoIndex])
			atributoValidoEncontrado = true;
		else
			siguienteAtributoIndex++;
	}

	(*n) = Pregunta(atributos[siguienteAtributoIndex], 2);
	if (tablero[tablero.size() - 1][siguienteAtributoIndex]) {
		arbol.insert_left(n, Pregunta(nombre, 1));
		arbol.insert_right(n, Pregunta(personajes[personajeHojaIndex], 1));
	}
	else {
		arbol.insert_left(n, Pregunta(personajes[personajeHojaIndex], 1));
		arbol.insert_right(n, Pregunta(nombre, 1));
	}
}

void QuienEsQuien::elimina_personaje(string nombre){
	// Pre: nombre must be valid (must be in Personajes)
	bintree<Pregunta>::node n = arbol.root();
	Pregunta preguntaAux;
	int personajeIndex = 0, contador = 0;
	bool isLeftChild = true;	// Keep track of the previous step, so we do not have to do something more complicated later to check if it was left or right child

	for (int i = 0; i < personajes.size(); i++)	// Find Personaje index
		if (personajes[i] == nombre)
			personajeIndex = i;

	while (!(*n).es_personaje()) {
		if (atributos[contador] == (*n).obtener_pregunta()) {	// If this Pregunta was deleted when we did eliminar_nodos_redundantes(), go to next
			if (tablero[personajeIndex][contador]) {
				(*n) = Pregunta((*n).obtener_pregunta(), (*n).obtener_num_personajes() - 1);  // Update num_personajes of Pregunta
				n = n.left();
				isLeftChild = true;
			}
			else {
				(*n) = Pregunta((*n).obtener_pregunta(), (*n).obtener_num_personajes() - 1);  // Update num_personajes of Pregunta
				n = n.right();
				isLeftChild = false;
			}
		}
		contador++;
	}

	if (isLeftChild)
		preguntaAux = Pregunta((*(n.parent().right())).obtener_personaje(), 1);
	else
		preguntaAux = Pregunta((*(n.parent().left())).obtener_personaje(), 1);

	bintree<Pregunta> Arb(preguntaAux);
	arbol.replace_subtree(n.parent(), Arb, Arb.root());

	personajes.erase(personajes.begin() + personajeIndex);
	tablero.erase(tablero.begin() + personajeIndex);
}

void escribir_esquema_arbol(ostream& ss,
					  const bintree<Pregunta>& a,
		    		  bintree<Pregunta>::node n,
					  string& pre){
	if (n.null()){
	    ss << pre << "-- x" << endl;
	} else {
	    ss << pre << "-- " << (*n) << endl;
	    if ( !n.right().null() || !n.left().null()) {// Si no es una hoja
			pre += "   |";
	    	escribir_esquema_arbol(ss,a, n.right(), pre);
	     	pre.replace(pre.size()-4, 4, "    ");
	      	escribir_esquema_arbol (ss,a, n.left(), pre);
	      	pre.erase(pre.size()-4, 4);
	    }
  	}
}

void QuienEsQuien::escribir_arbol_completo() const{
	string pre = "";
	escribir_esquema_arbol(cout,this->arbol,this->arbol.root(),pre);
}

void QuienEsQuien::eliminar_nodos_redundantes(){
	eliminar_nodos_redundantes(arbol, arbol.root());

	// This is not a part of this function. I have this here to test aniade_personaje() and elimina_personaje()
	/*
	vector<bool> caracteristicas;
	caracteristicas.push_back(1);
	caracteristicas.push_back(0);
	caracteristicas.push_back(0);
	caracteristicas.push_back(0);
	caracteristicas.push_back(1);
	caracteristicas.push_back(0);
	caracteristicas.push_back(0);
	caracteristicas.push_back(0);
	caracteristicas.push_back(1);
	caracteristicas.push_back(1);
	aniade_personaje("Paloma", caracteristicas);
	caracteristicas.clear();
	caracteristicas.push_back(0);
	caracteristicas.push_back(1);
	caracteristicas.push_back(1);
	caracteristicas.push_back(1);
	caracteristicas.push_back(1);
	caracteristicas.push_back(1);
	caracteristicas.push_back(1);
	caracteristicas.push_back(1);
	caracteristicas.push_back(1);
	caracteristicas.push_back(0);
	aniade_personaje("Julian", caracteristicas);
	caracteristicas.clear();
	caracteristicas.push_back(0);
	caracteristicas.push_back(1);
	caracteristicas.push_back(1);
	caracteristicas.push_back(1);
	caracteristicas.push_back(0);
	caracteristicas.push_back(1);
	caracteristicas.push_back(1);
	caracteristicas.push_back(1);
	caracteristicas.push_back(1);
	caracteristicas.push_back(0);
	aniade_personaje("Alberto", caracteristicas);
	//elimina_personaje("Julian");
	//elimina_personaje("Paloma");
	//elimina_personaje("Alberto");
	*/
}

void QuienEsQuien::eliminar_nodos_redundantes(bintree<Pregunta>& a, bintree<Pregunta>::node n){
	bintree<Pregunta> arbAux(Pregunta("", 0));
	bool eliminado = false;

	if (!n.left().null()) {
		if (n.left().right().null() && !n.left().left().null()) {
			arbAux.assign_subtree(a, n.left().left());
			a.insert_left(n, arbAux);
			eliminado = true;
		}
		else if (!n.left().right().null() && n.left().left().null()) {
			arbAux.assign_subtree(a, n.left().right());
			a.insert_left(n, arbAux);
			eliminado = true;
		}
	}
	if (!n.right().null()) {
		if (n.right().right().null() && !n.right().left().null()) {
			arbAux.assign_subtree(a, n.right().left());
			a.insert_right(n, arbAux);
			eliminado = true;
		}
		else if (!n.right().right().null() && n.right().left().null()) {
			arbAux.assign_subtree(a, n.right().right());
			a.insert_right(n, arbAux);
			eliminado = true;
		}
	}

	if (eliminado)
		eliminar_nodos_redundantes(a, n);
	if (!n.right().null()) // Si no es una hoja
		eliminar_nodos_redundantes(a, n.right());
	if (!n.left().null()) // Si no es una hoja
		eliminar_nodos_redundantes(a, n.left());
}

float QuienEsQuien::profundidad_promedio_hojas(){
	float totalProfundidad = 0;	// use float, so that when we divide it by personajes.size() we get decimals
	calcular_profundidad_promedio_hojas(arbol, arbol.root(), totalProfundidad, 0);

	return (totalProfundidad / personajes.size());
}

void QuienEsQuien::calcular_profundidad_promedio_hojas(const bintree<Pregunta> &a, bintree<Pregunta>::node n, float &totalProfundidad, int profundidadActual) {
	// This implementation is valid for raw trees
	if (!n.null()) {
		if ((*n).es_personaje())
			totalProfundidad += profundidadActual;
	    else if (!n.right().null() || !n.left().null()) {// Si no es una hoja
	    	calcular_profundidad_promedio_hojas (a, n.right(), totalProfundidad, profundidadActual + 1);
	      	calcular_profundidad_promedio_hojas (a, n.left(), totalProfundidad, profundidadActual + 1);
	    }
	}
}

/**
 * @brief Genera numero enteros positivos aleatorios en el rango [min,max).
**/

int generaEntero(int min, int max){
    int tam= max -min;
    return ((rand()%tam)+min);
}

void QuienEsQuien::tablero_aleatorio(int numero_de_personajes){
	srand(0);

	this->limpiar();

	float log_2_numero_de_personajes = log(numero_de_personajes)/log(2);

	int numero_de_atributos = ceil(log_2_numero_de_personajes);

	cout << "Petici�n para generar "<< numero_de_personajes<<" personajes ";
	cout << "con "<<numero_de_atributos<< " atributos"<<endl;
	cout << "Paso 1: generar "<< pow(2,numero_de_atributos) << " personajes"<<endl;

	//Fase 1: completar el tablero con todos los personajes posibles
	//Completo el tablero y los nombres de personajes a la vez
	for(int indice_personaje=0;indice_personaje< pow(2,numero_de_atributos);indice_personaje++){
		vector<bool> atributos_personaje = convertir_a_vector_bool(indice_personaje,numero_de_atributos);
		string nombre_personaje = "Personaje_"+to_string(indice_personaje);

		this->personajes.push_back(nombre_personaje);
		this->tablero.push_back(atributos_personaje);
	}

	// Completo los nombres de los atributos.
	for(int indice_atributo=0;indice_atributo<numero_de_atributos;indice_atributo++){
		string nombre_atributo = "Atr_"+to_string(indice_atributo);
		this->atributos.push_back(nombre_atributo);
	}

	cout << "Paso 2: eliminar "<< (pow(2,numero_de_atributos)-numero_de_personajes) << " personajes"<<endl;
	//Fase 2. Borrar personajes aleatoriamente hasta que quedan solo los que hemos pedido.
	while(personajes.size()>numero_de_personajes){
		int personaje_a_eliminar = generaEntero(0,personajes.size());

		personajes.erase(personajes.begin()+personaje_a_eliminar);
		tablero.erase(tablero.begin()+personaje_a_eliminar);
	}
}
