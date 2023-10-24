#include <iostream>
#include <vector>

template <typename T>

int BusquedaBinaria(T X, std::vector<T>& V, int ini, int fin){
	if(ini > fin){
		std::cout << "No se encuentra en el array" << std::endl;
		return -1;
	}

	int medio = (ini + fin) / 2;

	if(V[medio] == X){
		return medio;
	}

	else if(V[medio] > X){
		return BusquedaBinaria(X, V, ini, medio-1);
	}

	else{
		return BusquedaBinaria(X, V, medio+1, fin);
	}
}

template <typename T>

int BusquedaBinaria_INV(T X, std::vector<T>& V, int ini, int fin){
        if(ini > fin){
                std::cout << "No se encuentra en el array" << std::endl;
		return -1;
        }

        int medio = (ini + fin) / 2;

        if(V[medio] == X){
                return medio;
        }

        else if(V[medio] > X){  // Vector: 4,3,2,1,0 y busco el 1 -> Medio:2 ; 2>1 ; buscars en medio+1 a fin
		return BusquedaBinaria_INV(X, V, medio+1, fin);
        }

        else{
                return BusquedaBinaria_INV(X, V, ini, medio-1);
        }
}

