#include<iostream>
#include<stdlib.h>
#include <iomanip>
using namespace std; 

/*Este es un programa en C++ que implementa una lista enlazada simple. 
La lista tiene nodos que contienen un valor entero y un puntero al siguiente nodo en la lista. 
El programa incluye funciones para insertar elementos al inicio o al final de la lista, 
insertar elementos antes o después de una posición determinada en la lista, buscar elementos en la lista, 
eliminar elementos de la lista y eliminar elementos repetidos de la lista. También hay funciones para invertir la lista, 
calcular el promedio de los valores en la lista y encontrar el valor máximo en la lista. El programa utiliza punteros y 
memoria dinámica para crear y manipular los nodos de la lista.*/

struct nodo{
	int dato;
	struct nodo *sgte;
};

typedef nodo *Tlista;

void insertarInicio(Tlista &lista, int valor){
	Tlista q;
	q = new(struct nodo);
	q->dato = valor;
	q->sgte = lista;
	lista = q;
}

void insertarFinal(Tlista &lista, int valor){
	Tlista t,q = new (struct nodo);
	q->dato = valor;
	q->sgte = NULL;
	if(lista == NULL){
		lista = q;
	}else{
		t = lista;
		while(t->sgte != NULL){
			t = t->sgte;
		}
		t->sgte = q;
	}
}

int insertarAntesDespues(){
	int _op, band;
	
	cout<<endl;
	cout<<"\t1. antes de la posicion "<<endl;
	cout<<"\t2. despues de la posicion "<<endl;
	cout<<"\n\t opcion: "; cin>>_op;
	
	if(_op==1){
		band = -1;
	}else{
		band = 0;
	}
	
	return band;
}

void insertarElemento(Tlista &lista, int valor, int pos){
	Tlista q, t;
	
	int i;
	q = new(struct nodo);
	q->dato = valor;
	
	if(pos==1){
		q->sgte = lista;
		lista = q;
	}else{
		int x = insertarAntesDespues();
		t = lista;
		for(i=1; t!=NULL;i++){
			if(i==pos+x){
				q->sgte = t->sgte;
				t->sgte = q;
				return;
			}
			t = t->sgte;
		}
	}
	cout<<"error posicion no encontrada"<<endl;
}

void buscarElemento(Tlista lista, int valor){
	Tlista q = lista;
	int i = 1, band = 0;
	while(q != NULL){
		if(q->dato == valor){
			cout<<endl<<" encontrada en posicion "<< i <<") "<< q->dato <<endl;
		    band = 1;
		}
		
		q = q->sgte;
	    i++;
	}
	
	if(band==0){
		cout<<"\n\n numero no encontrado "<<endl;
	}
	
}

void mostraLista(Tlista lista){
	int i = 0;
	
	while(lista != NULL){
		cout<<' '<< i+1 <<") "<< lista->dato <<endl;
		lista = lista->sgte;
		i++;
	}
}

void eliminarElemento(Tlista &lista, int valor){
	Tlista p, ant;
	p = lista;
	
	if(lista != NULL){
		while(p!=NULL){
			if(p->dato == valor){
				if(p==lista){
					lista = lista->sgte;
					
				}else{
					ant->sgte = p->sgte;
					delete(p);
					return;
				}
			}
			ant = p;
			p = p->sgte;
		}
	}else{
		cout<<"lista vacia";
	}
}

void eliminarRepetidos(Tlista &lista, int valor){
	Tlista p, ant;
	p = lista;
	
	while(p!=NULL){
		if(p->dato == valor){
			if(p==lista){
				lista = lista->sgte;
				delete(p);
				p = lista;
			}else{
				ant->sgte = p->sgte;
				delete(p);
				p = ant->sgte;
			}
		}else{
			ant = p;
		    p = p->sgte;
		}	
	}
	
	cout<<"\n\n valores eliminados "<<endl;
}

void datosRepetidos (Tlista &lista, int valor){
	Tlista p, ant;
	p = lista;
	int cont = 0;
	
	while(p!=NULL){
		if(p->dato == valor){
			cont++;
			if(p==lista){
				lista = lista->sgte;
				p = lista;
			}else{
				ant->sgte = p->sgte;
				p = ant->sgte;
			}
		}else{
			ant = p;
		    p = p->sgte;
		}	
	}
	
	cout<<"el numero "<<valor<<" se repite "<<cont<<endl;
}

void push(Tlista &p, int valor){

    Tlista aux;
    aux = new(struct nodo);
    aux -> dato = valor;
    aux ->sgte = p;
    p = aux;
}

int pop ( Tlista &p){

    int num;
    Tlista aux;

    aux = p;
    num = aux->dato;
    p = aux -> sgte;
    delete(aux);
    return num;  
}

void invertirpila(Tlista &p){
	
	Tlista paux;
	paux = NULL;
	while(p != NULL){
		push(paux,pop(p));
	}
	p=paux;
	
	cout<<"\tlista invertida"<<endl;
	mostraLista(p);
	
}


void invertirLista(Tlista &lista){
	Tlista p;
	p = lista;
	invertirpila(p);

}

void promedio(Tlista &lista){
	
	Tlista p;
	p = lista;
	int num = 0,i=0;
	
	for(i; p!=NULL;i++){
		num += p->dato;
		p=p->sgte;
	}
	
	float prom = num/i;
	
	cout<<"el promedio de los datos en la lista es: "<<fixed<<setprecision(2)<<prom<<endl;
}

void datoMayor(Tlista &lista){
	Tlista p;
	
	p = lista;
	
	int mayor = 0;
	
	while(p!=NULL){
		int num = p->dato;
				
		if(num>mayor){
			mayor = num;
		}
		p = p->sgte;
	}
	
	cout<<"el dato mayor de la lista es: "<<mayor;
}

void orden(Tlista &lista){
	Tlista p;
	p = lista->sgte;
	bool orden = true;
    int num2 = lista->dato;
	
	while(p != NULL){
		int num = p->dato;
		if(num2>num){
			orden = false;
			break;
		}
		num2 = num;
		p= p->sgte;
	}
	
	if(orden){
		cout<<"la lista esta en forma ascendente";
	}else{
		cout<<"no esta ordenada ";
	}
}
