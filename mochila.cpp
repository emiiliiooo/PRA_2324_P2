#include <iostream>
#include <vector>
#include <limits>
#include<algorithm>

int mochila(std::vector<int>peso , int M,int tam, std::vector<int>& valor , int tabla[5][6], std::vector<int>& dev){
	
	for(int i = 0; i < tam+1; i++){          // Inicializa a -1
    		for(int j = 0; j < M+1; j++){
            		tabla[i][j] = -1;
    		}
  	}

	for(int i = 0; i <  tam+1; i++){     	 // Primera columna a 0
                tabla[i][0] = 0;
		
        }

        for(int j = 0; j < M+1; j++){		// Primera fila a 0
	  tabla[0][j] = 0;
	}


	for(int i = 1; i< tam+1; i++){		// Rellenar el resto de filas y columnas
		for(int j = 1; j < M+1; j++){
			if(j - peso[i-1] >= 0){ // Si cabe en la mochila
				tabla[i][j] = std::max(tabla[i-1][j], tabla[i-1][j-peso[i-1]] + valor[i-1]);
			}
			else{			// Si no cabe en la mochila
				tabla[i][j] = tabla[i-1][j];
			}
		}
	}

	int i = tam;
	int j = M;
	
	while(j > 0){
	  	if(tabla[i][j]  == tabla[i-1][j])
	    		i--;
	  	else{
			dev[i] = 1;
			j = j -  peso[i];
			i--;
	  	}
	}

	return tabla[tam][M];
	
	
}
int main(){

  int M = 5;
  int tam = 4;
  std::vector<int>peso = {1, 3, 2, 4};
  std::vector<int> valor = {10, 20, 15, 20};
  int tabla [5][6];
  std::vector<int> dev= {0,0,0, 0};
  
  int resultado = mochila(peso, M,tam, valor, tabla, dev);
  
  for(int i = 0; i< tam+1; i++){
    	for(int j = 0; j < M+1; j++){
     		std::cout << tabla[i][j] << " ";
	}
    	std::cout<<std::endl;
  }
  
  std::cout << "Máximo beneficio obtenido: " << resultado << " usando: " << std::endl;
  
  for(int i = 0; i < tam; i++){
  	std::cout << dev[i]<<" Obejeto  " << i+1 << std::endl;
  }	
  	
  return 0;

}
