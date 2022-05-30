//

#include <iostream>
#include <conio.h>
#include <stdlib.h>

using namespace std;

struct Nodo{
	int dato;
	Nodo *der;
	Nodo *izq;
};
Nodo *arbol = NULL;

int nivelArbol = 0;

void menu();
Nodo *crearNodo(int n);
void insertarNodo(Nodo *&, int);
void mostrarArbol(Nodo *, int);
bool busqueda(Nodo *, int);
void preOrden(Nodo *);
void inOrden(Nodo *);
void postOrden(Nodo *);
void ascendente(Nodo *);
void descendente(Nodo *);
int mayorValor(Nodo *);
int menorValor(Nodo *);
int nivel(Nodo *, int);


int main(){
	menu();
	
	return 0;
}

//funcion de menú
void menu(){
	int dato, opcion, cont = 0;
	do{
		nivelArbol = 0;
		cout<<"\tMENU: "<<endl;
		cout<<"1. Insertar un nuevo nodo "<<endl;
		cout<<"2. Mostrar el arbol completo"<<endl;
		cout<<"3. Buscar un elemento en el arbol"<<endl;
		cout<<"4. Recorrido Pre Orden "<<endl;
		cout<<"5. Reorrido en In Orden"<<endl;
		cout<<"6. Recorrido en Post Orden"<<endl;
		cout<<"7. Mostrar el arbol de manera ascendente"<<endl;
		cout<<"8. Mostrar el arbol de manera descendente"<<endl;
		cout<<"9. Buscar el mayor valor del arbol"<<endl;
		cout<<"10. Buscar el menor valor del arbol"<<endl;
		cout<<"11. Encontrar el nivel del nodo de una rbol"<<endl;	
		cout<<"12. Salir"<<endl;
		cin>>opcion;
		switch(opcion){
			case 1: 
				cout<<endl<<"Digite un numero: ";
				cin>>dato;
				insertarNodo(arbol, dato);
				break;
			case 2: 
				cout<<endl<<"Mostrando el arbol completo"<<endl;
				mostrarArbol(arbol, cont);
				cout<<endl,
				system("pause");
				break;
			case 3: 
				cout<<"\nDigite el elemento a buscar"<<endl;
				cin>>dato;
				if(busqueda(arbol, dato)== true){
					cout<<endl<<"El elemento "<<dato<<" ha sido encontrado en el arbol"<<endl;
				}
				else{
					cout<<"El elemento no se encuentra en el arbol"<<endl;
				}
				system("pause");
				break;
			case 4: 
				cout<<"Recorrido en Pre Orden: "<<endl;
				preOrden(arbol);
				cout<<endl<<endl;
				system("pause");
				break;
			case 5:
				cout<<"Recorrido en In Orden"<<endl;
				inOrden(arbol);
				cout<<endl;
				system("pause");
				break;
			case 6:
				cout<<"Recorrido en Post Orden"<<endl;
				postOrden(arbol);
				cout<<endl;
				system("pause");
				break;
			case 7:
				cout<<"Mostrar el arobl de manera ascentende:"<<endl;
				ascendente(arbol);
				cout<<endl,
				system("pause");
				break;
			case 8:
				cout<<"Mostrar el arobl de manera descendente: "<<endl;
				descendente(arbol);
				cout<<endl;
				system("pause");
				break;
			case 9:
				cout<<"Buscar el mayor valor del arbol: "<<endl;
				cout<<"El mayor valor es: "<<mayorValor(arbol);
				cout<<endl;
				system("pause");
				break;
			case 10:
				cout<<"Mostrar el menor valor del arbol"<<endl;
				cout<<"El menor valor es: "<<menorValor(arbol);
				cout<<endl;
				system("pause");
				break;
			case 11:
				cout<<"Encontrando el nivel de un nodo del arbol"<<endl;
				cin>>dato;
				cout<<"El nivel del nodo es: "<<nivel(arbol, dato)<<endl;
				system("pause");
				break;	
		}
		system("cls");
	}
	while (opcion != 12);
}


//funcion para crear nodo
Nodo *crearNodo(int n){
	Nodo *nuevo_nodo = new Nodo();
	
	nuevo_nodo->dato = n;
	nuevo_nodo->der = NULL;
	nuevo_nodo->izq = NULL;
	
	return nuevo_nodo;
}

//funcion para insertar nodos en el arbol

void insertarNodo(Nodo *&arbol, int n){
	if(arbol == NULL){
		Nodo *nuevo_nodo = crearNodo(n);
		arbol = nuevo_nodo;
	}
	else{
		int valorRaiz = arbol->dato;
		if(n < valorRaiz){
			insertarNodo(arbol->izq, n);
		}
		else{
			insertarNodo(arbol->der, n);
		}
	}
}

//funcion para mostrar arbol

void mostrarArbol(Nodo *arbol, int cont){
	if(arbol==NULL){
		return;
	}
	else{
		mostrarArbol(arbol->der, cont+1);
		for(int i = 0; i < cont; i++){
			cout<<"    ";
		}
		cout<<arbol->dato<<endl;
		mostrarArbol(arbol->izq, cont+1);
	}
}

//funcion para buscar un elemento en el arbol
bool busqueda(Nodo *arbol, int n){
	if(arbol == NULL){
		return false;
	}
	else if(arbol->dato==n){
		return true;
	}
	else if(arbol->dato > n){
		busqueda(arbol->izq,n);
	}
	else if(arbol->dato < n){
		busqueda(arbol->der,n);
	}
	
}

void preOrden(Nodo *arbol){
	if(arbol==NULL){
		return;
	}
	else{
		cout<<arbol->dato<<" - ";
		preOrden(arbol->izq);
		preOrden(arbol->der);
	}

}

void inOrden(Nodo *arbol){
	if(arbol==NULL){
		return;
	}
	else{
		inOrden(arbol->izq);
		cout<<arbol->dato<<" - ";
		inOrden(arbol->der);	
	}
}

void postOrden(Nodo *arbol){
	if(arbol == NULL){
		return;
	}
	else{
		postOrden(arbol->izq);
		postOrden(arbol->der);
		cout<<arbol->dato<<" - ";
	}
}

void ascendente(Nodo *arbol){
	if(arbol == NULL){
		return;
	}	
	else{
		ascendente(arbol->izq);
		cout<<arbol->dato<<" - ";
		ascendente(arbol->der);
		
	}
}
void descendente(Nodo *arbol){
	if(arbol == NULL){
		return;
	}	
	else{
		descendente(arbol->der);
		cout<<arbol->dato<<" - ";
		descendente(arbol->izq);
		
	}
}
int mayorValor(Nodo *arbol){
	if(arbol->der == NULL){
		return arbol->dato;
	}	
	else{
		mayorValor(arbol->der);
	}
}
int menorValor(Nodo *arbol){
	if(arbol->izq == NULL){
		return arbol->dato;
	}	
	else{
		menorValor(arbol->izq);
	}
}
int nivel(Nodo *arbol, int n){
	if(arbol->dato==n){
		return nivelArbol;
	}
	else if(arbol->dato > n){
		nivel(arbol->izq,n);
	}
	else if(arbol->dato < n){
		nivel(arbol->der,n);
	}
	else{
		cout<<"Error";
	}
	nivelArbol++;
}

