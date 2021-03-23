// IDB-19-07
// Afanasyev Vadim
// Tridiagonal matrx algorithm

#include <iostream>
#include <iomanip>

void alloc_matr(float**& matr, int n) {
	// Rows
	matr = new float* [n];
	// Columns
	for (int i = 0; i < n; i++) {
		matr[i] = new float[n];
	}
}

void del_matr(float**& matr, int n) {
	// Columns
	for (int i = 0; i < n; i++) {
		delete[] matr[i];
	}
	// Rows
	delete[] matr;
}

void fill_matr(float**& matr, int n) {
	std::cout << '\n';
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			std::cout << "Enter [" << i << "][" << j << "] element: ";
			std::cin >> matr[i][j];
		}
	}
}

void print_matr(float**& matr, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			std::cout << std::setw(4) << std::setprecision(5) << matr[i][j] << '|';
		}
		std::cout << '\n';
	}
}

void my_tridiagonal_matrix_algorithm(float**& matr, int n) {
	// TODO: Implement tridiagonal matrix algorithm


}

int main() {
	std::cout << "Tridiagonal matrix algorithm\n";

	std::cout << "Enter dimension of matrix: ";
	int n = 0;
	std::cin >> n;

	float** matr = 0;
	alloc_matr(matr, n);
	fill_matr(matr, n);
	print_matr(matr, n);
	my_tridiagonal_matrix_algorithm(matr, n);
	del_matr(matr, n);

	return 0;
}
