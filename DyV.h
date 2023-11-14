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



// Funciones para QUICKSORT

template<typename T>

void swap(std::vector<T> &V, int x, int y){
		T aux = V[x];
		V[x] = V[y];
		V[y] = aux;
}

template<typename T>

void print_vector(std::vector<T>& V,int tam){
	for(int i = 0;i < tam;i++){
		std::cout << V[i] << " ";
	}	
	std::cout << std::endl;
}


// QUICKSORT

template<typename T>

int PartitionINI(std::vector<T>& V, int ini, int fin){

	T x = V[ini];
	int i = ini;
	int j ;	

	for(j = ini ;j <= fin; j++){
		if(V[j] < x){
	       		swap(V, i, j);
			if(i == ini)ini = j;
			i = i +1;
	       }
	}

	swap(V, i, ini);

	return i;
}

template<typename T>

void QuickSortINI(std::vector<T>& V, int ini, int fin){

	if(ini < fin){
		int pivot = PartitionINI(V, ini, fin);
		QuickSortINI(V, ini, pivot-1);
		QuickSortINI(V, pivot +1, fin);
	}
}

template<typename T>

int PartitionMED(std::vector<T>& V, int ini, int fin){
  	int medio = (ini +fin) / 2;
  
  	T x = V[medio];
	int i = ini;
	int j ;	
	
	for(j = ini; j <= fin; j++){
	       if(V[j] < x){
			swap(V, i, j);
			//T aux = V[i];
			//V[i] = V[j];
 			//V[j] = aux;
			if(i==medio) medio=j;
	       		i = i +1;
	       }
	}

	swap(V, i, medio);
	//T aux1 = V[i];
	//V[i] = V[medio];
	//V[medio] = aux1;
	return i;
}

template<typename T>

void QuickSortMED(std::vector<T>& V, int ini, int fin){
	
	if(ini < fin){
		int pivot = PartitionMED(V, ini, fin);
		QuickSortMED(V, ini, pivot -1);
		QuickSortMED(V, pivot +1, fin);
	}
}

template<typename T>

int Partition(std::vector<T>& V, int ini, int fin){
        T x = V[fin];
        int i = ini;
        int j ;

	for(j = ini ;j < fin; j++){
               if(V[j] <= x){
               		swap(V, i, j);
                	i = i +1;
               }
        }

        swap(V, i, fin);

	return i;
}

template<typename T>

void QuickSort(std::vector<T>& V, int ini, int fin){
	if(ini < fin){
		int pivot = Partition(V, ini, fin);
		QuickSort(V, ini, pivot -1);
		QuickSort(V, pivot +1, fin);
	}
}

