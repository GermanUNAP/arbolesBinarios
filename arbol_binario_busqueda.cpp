/*
1-3    Al recorrer el árbol cuantas llanadas recursivas
4-6    Encontrar el nivel del árbol
7-9    Encontrar el mayor elemento
10-12  Encontrar el menor elemento
13-15  Sumar y Hallar el Promedio
16-18  Mostrar de mayor a menor
19-21  Mostrar de menor a mayor
22-24  Al recorrer el árbol cuantas paradas hay
*/

#include <iostream>
#include <conio.h>
#include <stdlib.h>

using namespace std;

struct Nodo{
	int dato;
	Nodo *der;
	Nodo *izq;
	Nodo *padre;
};
Nodo *arbol = NULL;
Nodo *hoja = NULL;

//declaring global variables
int nivelArbol = 0;
int contRecursivo = 0;
float sum = 0;
float  prompt = 0;
int stop;

//declaring functions
void menu();
Nodo *crearNodo(int n, Nodo *);
void insertarNodo(Nodo *&, int, Nodo *);
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
int llamadasRecursivas(Nodo *);
int suma(Nodo *);
float promedio(Nodo *);
int paradas(Nodo *);
void eliminarNodo(Nodo *, int);
void eliminar(Nodo *arbol);
Nodo *minimo(Nodo *);
void reemplazar(Nodo *, Nodo *);
void destruirNodo (Nodo *);

int main(){
	system("color a");
	menu();
	
	return 0;
}

//funcion de menú
void menu(){
	
	int dato, opcion, cont = 0;
	do{
		nivelArbol = 0;
		contRecursivo = 0;
		sum = 0; 
		prompt = 0;
		stop = 0;
		cout<<"\tMENU: "<<endl;
		cout<<"1. Insertar un NUEVO NODO "<<endl;
		cout<<"2. MOSTRAR el arbol completo"<<endl;
		cout<<"3. BUSCAR un elemento en el arbol"<<endl;
		cout<<"4. Recorrido PRE ORDEN "<<endl;
		cout<<"5. Reorrido en IN ORDEN"<<endl;
		cout<<"6. Recorrido en POST ORDEN"<<endl;
		cout<<"7. Mostrar el arbol de manera ASCENDENTE"<<endl;
		cout<<"8. Mostrar el arbol de manera DESCENDENTE"<<endl;
		cout<<"9. Buscar el MAYOR valor del arbol"<<endl;
		cout<<"10. Buscar el MENOR valor del arbol"<<endl;
		cout<<"11. Encontrar el NIVEL del nodo de un arbol"<<endl;
		cout<<"12. Al recorrer el arbol cuantas LLAMADAS RECURSIVAS"<<endl;
		cout<<"13. SUMAR y halllar el PROMEDIO"<<endl;
		cout<<"14. Al recorrer el arbol cuantas PARADAS hay"<<endl;
		cout<<"15. ELIMINAR un nodo del arbol"<<endl;
		cout<<"18. Salir"<<endl;
		cin>>opcion;
		switch(opcion){
			case 1: 
				cout<<endl<<"Digite un numero: ";
				cin>>dato;
				insertarNodo(arbol, dato, NULL);
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
			case 12:
				cout<<"Encontrando las llamadas recursivas que se hace al arbol:"<<endl;
				cout<<"Es un total del: "<<llamadasRecursivas(arbol)<<endl;	
				system("pause");
				break;
			case 13:
				cout<<"La suma del arbol es: "<<suma(arbol)<<endl;
				cout<<"El promedio del arbol es: "<<promedio(arbol)<<endl;
				system("pause");
				break;
			case 14:
				cout<<"Las paradas que se realiza en el arbol"<<endl;
				cout<<"El numero de paradas es: "<<paradas(arbol)<<endl;
				system("pause");
				break;
			case 15:
				cout<<"Ingrese nodo a eliminar: "<<endl;
				cin>>dato;
				eliminarNodo(arbol, dato);
				cout<<endl;
				system("pause");
				break;
		}
		system("cls");
	}
	while (opcion != 18);
}


//funcion para crear nodo
Nodo *crearNodo(int n, Nodo *padre){
	Nodo *nuevo_nodo = new Nodo();
	
	nuevo_nodo->dato = n;
	nuevo_nodo->der = NULL;
	nuevo_nodo->izq = NULL;
	nuevo_nodo->padre = padre;
	
	return nuevo_nodo;
}

//funcion para insertar nodos en el arbol

void insertarNodo(Nodo *&arbol, int n, Nodo *padre){
	if(arbol == NULL){
		Nodo *nuevo_nodo = crearNodo(n, padre);
		arbol = nuevo_nodo;
	}
	else{
		int valorRaiz = arbol->dato;
		if(n < valorRaiz){
			insertarNodo(arbol->izq, n, arbol);
		}
		else{
			insertarNodo(arbol->der, n, arbol);
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

int llamadasRecursivas(Nodo *arbol){
	if(arbol == NULL){
		contRecursivo++;
		return contRecursivo;
	}
	else{
		contRecursivo++;
		llamadasRecursivas(arbol->izq);
		llamadasRecursivas(arbol->der);	
	}
}

int suma(Nodo *arbol){
	if(arbol == NULL){
		return sum;
	}
	else{
		sum += arbol->dato;
		suma(arbol->izq);
		suma(arbol->der);
	}
}

float promedio(Nodo *arbol){
	if(arbol == NULL){
		return sum/prompt;
	}
	else{
		prompt++;
		promedio(arbol->izq);
		promedio(arbol->der);
	}
}

//funcion para verificar las paradas que se realizan en el arbol
int paradas(Nodo *arbol){
	if(arbol == NULL){
		stop++;
		return stop;
	}
	else{
		paradas(arbol->izq);
		paradas(arbol->der);
	}
	
}

//funcion para eliminar un nodo del arbol
void eliminarNodo(Nodo *arbol, int n){
	if(arbol == NULL){
		return ;
	}
	else if(n == arbol->dato){
		//cout<<endl<<"Se encuentra en nodo a eliminar"<<endl;
		eliminar(arbol);
	}
	else if(n < arbol->dato){
		//cout<<endl<<"Se busca el lado izquierdo"<<endl;
		eliminarNodo(arbol->izq, n);
	}
	else if(n > arbol->dato){
		//cout<<endl<<"Se busca en el lado derecho"<<endl;
		eliminarNodo(arbol->der, n);
	}
	
}

//funcion para hallar el minimo elemento
Nodo *minimo (Nodo *arbol){
	if(arbol == NULL){
		return NULL;
	}
	if(arbol->izq){ //si tiene hijo izquierdo
		minimo(arbol->izq);
	}
	else{//si ya no tiene hijo, se retortan el Nodo
		return arbol;
	}
}

//funcion para reemplazar 
void reemplazar(Nodo *arbol, Nodo *nuevoNodo){
	if(arbol->padre){
		//hay que asignarle su hijo del nodo a eliminar
		if(arbol->dato == arbol->padre->der->dato){
			arbol->padre->der = nuevoNodo;
		}
		else if(arbol->dato == arbol->padre->izq->dato){
			arbol->padre->izq = nuevoNodo;
		}
	}
	else if(nuevoNodo != NULL){
		//se le asigna su nuevo padre
		nuevoNodo->padre = arbol->padre;
	}
}

//funcion para destruir nodo

void destruir(Nodo *nodo){
	nodo->izq = NULL;
	nodo->der=NULL;
	delete nodo;
}

//funcion para eliminar el nodo encontrado
void eliminar(Nodo *nodoEliminar){
	if(nodoEliminar->izq != NULL && nodoEliminar->der != NULL){//si tiene dos hijos
		Nodo *menor = minimo(nodoEliminar->der);
		nodoEliminar->dato = menor->dato;
		eliminar(menor);
		//cout<<endl<<"Se elimina el nodo con dos hijos"<<endl;
	}
	else if(nodoEliminar->izq && nodoEliminar->der == NULL){//si solo tiene hijo izquierdo
		reemplazar(nodoEliminar, nodoEliminar->izq);
		destruir(nodoEliminar);
		//cout<<endl<<"Se elimina el nodo con hijo izquierdo"<<endl;
	}
	else if(nodoEliminar->der && nodoEliminar->izq == NULL){//si tiene solo hijo izquierdo
		reemplazar(nodoEliminar, nodoEliminar->der);
		destruir(nodoEliminar);
		//cout<<endl<<"Se elimina el nodo con hijo derecho"<<endl;
	}
	else if(nodoEliminar->der == NULL && nodoEliminar->izq == NULL){//si no tieje hijos
		reemplazar(nodoEliminar, NULL);
		//cout<<endl<<"Se elimina el nodo hoja"<<endl;
		destruir(nodoEliminar);
		
	}
	
}
