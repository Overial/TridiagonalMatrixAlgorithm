// IDB-19-07
// Afanasyev Vadim
// Tridiagonal matrix algorithm

#include <iostream>
#include <iomanip>
#include <vector>

void alloc_matr(float**& matr, int iRowCount, int iColCount) {
	// Rows
	matr = new float* [iRowCount];
	// Columns
	for (int i = 0; i < iRowCount; ++i) {
		matr[i] = new float[iColCount];
	}
}

void del_matr(float**& matr, int iRowCount, int iColCount) {
	// Columns
	for (int i = 0; i < iRowCount; ++i) {
		delete[] matr[i];
	}
	// Rows
	delete[] matr;
}

void fill_matr(float**& matr, int iRowCount, int iColCount) {
	std::cout << '\n';
	for (int i = 0; i < iRowCount; ++i) {
		for (int j = 0; j < iColCount; ++j) {
			std::cout << "Enter [" << i << "][" << j << "] element: ";
			std::cin >> matr[i][j];
		}
	}
}

void print_matr(float**& matr, int iRowCount, int iColCount) {
	std::cout << '\n';
	for (int i = 0; i < iRowCount; ++i) {
		for (int j = 0; j < iColCount; ++j) {
			std::cout << std::setw(4) << std::setprecision(5) << matr[i][j] << '|';
		}
		std::cout << '\n';
	}
}

void my_tridiagonal_matrix_algorithm(float**& matr, int iRowCount, int iColCount) {
	// Temporary vectors for algorithm
	std::vector<float> y;
	std::vector<float> alpha;
	std::vector<float> beta;

	////// Forward sweep //////

	// Row 0 (the first)
	y.push_back(matr[0][0]);
	alpha.push_back(-matr[0][1] / y[0]);
	beta.push_back(matr[0][iColCount - 1] / y[0]);

	// Rows 1 to n - 2
	for (int i = 1; i <= iRowCount - 2; ++i) {
		y.push_back(matr[i][i] + matr[i][i - 1] * alpha[i - 1]);
		alpha.push_back(-matr[i][i + 1] / y[i]);
		beta.push_back((matr[i][iColCount - 1] - matr[i][i - 1] * beta[i - 1]) / y[i]);
	}

	// Row n - 1 (the last)
	int iLastRow = iRowCount - 1;
	y.push_back(matr[iLastRow][iColCount - 2] + matr[iLastRow][iColCount - 3] * alpha[iLastRow - 1]);
	beta.push_back((matr[iLastRow][iColCount - 1] - matr[iLastRow][iColCount - 3] * beta[iLastRow - 1]) / y[iLastRow]);

	////// Reverse sweep //////

	std::vector<float> x;

	// Row n - 1 (the last)
	x.push_back(beta[iRowCount - 1]);
	int iTempIndex = 0;

	// Rows n - 1 to 0
	for (int i = iLastRow - 1; i >= 0; --i) {
		x.push_back(alpha[i] * x[iTempIndex] + beta[i]);
		iTempIndex++;
	}

	// Print result
	std::cout << "\nOutput:\n\n";
	for (int i = 0; i < iRowCount; ++i) {
		std::cout << std::setw(4) << std::setprecision(5) << x[i] << '|';
	}
	std::cout << '\n';
}

int main() {
	{
		std::cout << "Tridiagonal matrix algorithm. Input carefully!!! (cause it's not being handled)\n\n";

		std::cout << "Enter the amount of rows: ";
		int iRowCount = 0;
		std::cin >> iRowCount;

		std::cout << "Enter the amount of columns: ";
		int iColCount = 0;
		std::cin >> iColCount;

		float** matr = 0;
		alloc_matr(matr, iRowCount, iColCount);
		fill_matr(matr, iRowCount, iColCount);
		print_matr(matr, iRowCount, iColCount);
		my_tridiagonal_matrix_algorithm(matr, iRowCount, iColCount);
		del_matr(matr, iRowCount, iColCount);

		return 0;
	}

	_CrtDumpMemoryLeaks();

	return 0;
}
