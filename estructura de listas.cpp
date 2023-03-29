#include<iostream>
#include<stdlib.h>
#include "listas.h"
using namespace std;
/*Este es un programa en C++ que implementa una lista enlazada simple, con un menú que permite al usuario realizar diversas operaciones en la lista. A continuación, se detallan las funciones implementadas:

Funciones de la lista enlazada:

insertarInicio: permite insertar un nuevo elemento al inicio de la lista.
insertarFinal: permite insertar un nuevo elemento al final de la lista.
insertarElemento: permite insertar un nuevo elemento en una posición determinada de la lista.
mostraLista: permite mostrar todos los elementos de la lista.
buscarElemento: permite buscar un elemento en la lista y mostrar su posición.
eliminarElemento: permite eliminar un elemento específico de la lista.
eliminarRepetidos: permite eliminar todos los elementos repetidos en la lista.
datosRepetidos: permite contar cuántas veces aparece un elemento específico en la lista.
invertirLista: permite invertir el orden de los elementos de la lista.
promedio: permite calcular el promedio de todos los elementos de la lista.
datoMayor: permite encontrar el elemento mayor de la lista.
orden: permite verificar si la lista está ordenada en orden ascendente.
Funciones principales:

menu: función que muestra el menú de opciones al usuario.
main: función principal del programa que permite al usuario seleccionar una opción del menú y ejecutar la operación correspondiente en la lista.
El programa utiliza la estructura de datos Tlista, que es un puntero a un nodo de la lista enlazada, y la estructura de datos Tnodo, que representa un nodo de la lista enlazada con un valor y un puntero al siguiente nodo.

El programa incluye la biblioteca iostream para la entrada y salida de datos, la biblioteca stdlib.h para utilizar la función system, y un archivo de cabecera listas.h, que contiene la definición de las funciones de la lista enlazada.*/

void menu(){
	cout<<"\n\t\timplementacion de lista enlazada simple en c++\n\n";
	cout<<"1. insertar al inicio"<<endl;
	cout<<"2. insertar al final"<<endl;
	cout<<"3. insertar en una posicion "<<endl;
	cout<<"4. mostrar lista"<<endl;
	cout<<"5. buscar dato "<<endl;
	cout<<"6. eliminar dato "<<endl;
	cout<<"7. eliminar datos repetidos"<<endl;
	cout<<"8. numero de veces de un valor "<<endl;
	cout<<"9. invertir lista "<<endl;
	cout<<"10. promedio de valores "<<endl;
	cout<<"11. dato mayor de la lista "<<endl;
	cout<<"12. verificar si la lista esta en orden ascendente "<<endl;
	cout<<"13. salir "<<endl;
	cout<<"ingrese la opcion: ";
	
	
}

int main(){
	Tlista lista = NULL;
	int op;
	int dato;
	int pos;
	
	
	do{

	menu();
	
	cin>>op;
	
	switch(op){
		case 1: 
		cout<<"\n numero  a insertar: ";
		cin>>dato;
		insertarInicio(lista,dato);
		break;
		
		case 2:
		cout<<"\n numero  a insertar: ";
		cin>>dato;
		insertarFinal(lista,dato);
		break;
		
		case 3:
		cout<<"\n numero  a insertar: ";
		cin>>dato;
		cout<<" posicion ";
		cin>>pos;
		insertarElemento(lista,dato,pos);
		break;
		
		case 4:
		cout<<"\n\n lista \n\n";
		mostraLista(lista);
		break;
		
		case 5:
		cout<<"\n valor a buscar: ";
		cin>>dato;
		buscarElemento(lista,dato);
		break;
		
		case 6:
		cout<<"\n valor a eliminar: ";
		cin>>dato;
		eliminarElemento(lista,dato);
		break;
		
		case 7:
		cout<<"\n valor repetido a eliminar: ";
		cin>>dato;
		eliminarRepetidos(lista,dato);
		break;
		
		case 8:
		cout<<"\n valor a verificar: ";
		cin>>dato;
		datosRepetidos(lista,dato);
		break;	
		
		case 9:
		cout<<"\n invertir lista: \n";
		invertirLista(lista);
		break;
		
		case 10:
		cout<<"\n promedio de valores: \n";
		promedio(lista);
		break;
		
		case 11:
		cout<<"\n dato mayor: \n";
		datoMayor(lista);
		break;
		
		case 12:
		orden(lista);
		break;
	}
	
	cout<<endl<<endl;
	system("pause");
	system("cls");
	
	}while (op!=13);
	system("pause");
	return 0;
}


