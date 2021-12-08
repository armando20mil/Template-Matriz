#include<iostream>
using namespace std;

template<class Type_Class>
class Matriz{
	private:
		Type_Class valor; //tipo de elemento genérico T
		Type_Class **ptrMatriz; //matriz de punteros de tipo T
		int fila, columna;//filas y columnas
	public:
		Matriz(int, int); //constructor
		void imprimeMatriz(); //para imprimir una matriz genérica de tipo T
		void ingresaMatriz(); //para leer una matriz genércia de tipo T
};

template<typename Type>//constructor de la clase Matriz
Matriz<Type>::Matriz(int filas, int columnas){
	this->fila = filas;
	this->columna = columnas;
	this->ptrMatriz = new Type*[this->fila]; //creamos un puntero T a filas;
	for (int i=0; i<columnas; i++) {
		this->ptrMatriz[i] = new Type[this->columna]; //creamos un puntero T a columnas;
	}
}

template<typename Type>//Llenar una matriz genérica desde el teclado
void Matriz<Type> :: ingresaMatriz(){
	cout<<"\n--- INGRESAR DATOS ---\n";
	for (int i=0; i<this->fila; i++) {
		for (int j=0; j<this->columna; j++){
			cout<<"->[" << (j+1) <<"]["<< (i+1) <<"] = ";
			cin>>this->valor;
			this->ptrMatriz[i][j] = this->valor;
		}
	}
	cout<<endl;
}

template<typename Type>//imprimir la Matriz
void Matriz<Type> :: imprimeMatriz(){
	for(int i=0; i<this->fila; i++){
		for(int j=0; j<this->columna; j++){
			cout<<"[ "<<this->ptrMatriz[i][j]<<" ] ";
		}
		cout<<endl;
	}
	cout<<endl<<endl;
}

int main(){
	int fil, col;
	cout<< "Ingresa el nro de filas: ";
	cin>> fil;
	cout<< "Ingresa el nro de columnas: ";
	cin>> col;
	
	Matriz<char> a(fil, col);//crea una matriz de tipo generico
	
	a.ingresaMatriz();
	cout << "Matriz a " << endl;
	a.imprimeMatriz();

	return 0;
}