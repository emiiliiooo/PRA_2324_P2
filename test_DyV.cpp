#include <iostream>
#include "DyV.h"
#include <vector>

using namespace std;

int main(){
	std::vector<int> a{1, 2, 3, 4, 5, 6, 7, 8};
	std::vector<double> b{1.1, 2.3, 3.0, 4.6, 5.7, 6.8, 7.2,};
	std::vector<char> c{ 'a', 'b', 'c', 'd', 'e', 'f', 'g' };

	std::vector<int> d{7, 6, 5, 4, 3, 2, 1};
        std::vector<double> e{7.2, 6.8, 5.7, 4.6, 3.0, 2.3, 1.1};
        std::vector<char> f{ 'g', 'f', 'e', 'd', 'c', 'b', 'a' };

	std::cout << "Busqueda Binaria INT = " << BusquedaBinaria(5, a, 0, 7) << std::endl;
	std::cout << "Busqueda Binaria DOUBLE = " << BusquedaBinaria(1.1, b, 0, 6) << std::endl;
	std::cout << "Busqueda Binaria CHAR = " << BusquedaBinaria('b', c, 0, 6) << std::endl;

	cout << endl;

	std::cout << "Busqueda Binaria INT = " << BusquedaBinaria(9, a, 0, 7) << std::endl;
        std::cout << "Busqueda Binaria DOUBLE = " << BusquedaBinaria(1.2, b, 0, 6) << std::endl;
        std::cout << "Busqueda Binaria CHAR = " << BusquedaBinaria('t', c, 0, 6) << std::endl;	


	cout << endl;

        std::cout << "Busqueda Binaria Inversa INT = " << BusquedaBinaria_INV(5, d, 0, 6) << std::endl;
        std::cout << "Busqueda Binaria Inversa DOUBLE = " << BusquedaBinaria_INV(1.1, e, 0, 6) << std::endl;
        std::cout << "Busqueda Binaria Inversa CHAR = " << BusquedaBinaria_INV('b', f, 0, 6) << std::endl;

        cout << endl;

        std::cout << "Busqueda Binaria Inversa INT = " << BusquedaBinaria_INV(9, d, 0, 6) << std::endl;
        std::cout << "Busqueda Binaria Inversa DOUBLE = " << BusquedaBinaria_INV(1.2, e, 0, 6) << std::endl;
        std::cout << "Busqueda Binaria Inversa CHAR = " << BusquedaBinaria_INV('t', f, 0, 6) << std::endl;

	cout << endl;

	std::vector<int> g{4, 2, 7, 5, 8, 1, 9, 3, 6};
        std::vector<double> h{3.3, 7.7, 1.1, 8.8, 9.9, 2.2, 5.5, 4.4, 6.6};
        std::vector<char> i{ 'i', 'h', 'e', 'a', 'f', 'c', 'b', 'd', 'g'};


	cout << "Vector INT desordenado: ";
        print_vector(g, 9);
	
	QuickSort(g, 0, 8);
	
	cout << "Vector INT ordenado: ";
	print_vector(g, 9);
	cout << endl;


	cout << "Vector FLOAT desordenado: ";
        print_vector(h, 9);

	QuickSortINI(h, 0, 8);
	
	cout << "Vector FLOAT ordenado: ";
	print_vector(h, 9);
        cout << endl;


	cout << "Vector CHAR desordenado: ";
        print_vector(i, 9);	
	
	QuickSortMED(i, 0, 8);

	
	cout << "Vector CHAR ordenado: ";
	print_vector(i, 9);
        cout << endl;

	return 0;
}
