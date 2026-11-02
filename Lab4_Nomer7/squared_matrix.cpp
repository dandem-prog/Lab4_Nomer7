#include <iostream>
#include <random>
using std::cout;
using std::cin;
int main() {

	cout << "enter how numbers for array will be received. from keybord - 1/ randomly - 2\n";
	int how_num;
	cin >> how_num;
	if (how_num < 1 || how_num > 2) {
		cout << "error";
		return 0;
	}
	int number1;
	cout << "enter width of squared matrix\n";
	if (!(cin >> number1)) {
		cout << "error";
		return 0;
	}
	if (number1 < 0 || number1 > 100) {
		cout << "error";
		return 0;
	}


	int** matrix = new int*[number1];
	for (int i = 0; i < number1; ++i) {
		matrix[i] = new int[number1] {};
	}
	if (how_num == 1) {
		cout << "enter elements of arr\n";
		for (int i = 0; i < number1; ++i) {
			for (int j = 0; j < number1; ++j) {
				cin >> matrix[i][j];
			}
		}

	}
	if (how_num == 2) {
		cout << "how we will random numbers? rand() - 1/Mersenne Twister - 2\n";
		int rand_type;
		cin >> rand_type;
		if (rand_type < 1 || rand_type > 2) {
			cout << "error is not 1 or 2";
			return 0;
		}
		cout << "enter borders a,b (a<b)\n";
		int a, b;
		cin >> a >> b;
		if (a > b) {
			cout << "error a>b\n";
			return 0;
		}
		if (rand_type == 1) {
			srand(time(0));
			for (int i = 0; i < number1; ++i) {
				for (int j = 0; j < number1; ++j) {
					matrix[i][j] = a + rand() % (b - a + 1);
				}
			}
		}
		if (rand_type == 2) {
			std::random_device rd;
			std::mt19937 gen(rd());
			std::uniform_int_distribution<int> distrib(a, b);
			for (int i = 0; i < number1; ++i) {
				for (int j = 0; j < number1; ++j) {
					matrix[i][j] = distrib(gen);
				}
			}
		}
		cout << "matrix : \n";
		for (int i = 0; i < number1; ++i) {
			for (int j = 0; j < number1; ++j) {
				cout << matrix[i][j] << " ";
			}
			cout << '\n';
		}
	}

	int min_el = matrix[0][0];
	int min_el_counter = 0;
	int max_el = matrix[0][0];
	int max_el_counter = 0;
	for (int i = 0; i < number1; ++i) {
		for (int j = 0; j < number1; ++j) {
			if (matrix[i][j] > max_el) {
				max_el = matrix[i][j];
				max_el_counter = i;
			}
			if (matrix[i][j] < min_el) {
				min_el = matrix[i][j];
				min_el_counter = j;
			}
		}
	}
	int scalar_prod = 0;
	int i = 0;
	int j = 0;
	while (i < number1 && j < number1) {
		scalar_prod += matrix[min_el_counter][j] * matrix[i][max_el_counter];
		++i;
		++j;
	}
	cout << "scalar product = " << scalar_prod << '\n';


	int min_max = matrix[0][0];
	for (int i = 0; i < number1; ++i) {
		int current_max = matrix[i][0];
		for (int j = 0; j < number1; ++j) {
			if (current_max < matrix[i][j]) current_max = matrix[i][j];
		}
		if (min_max > current_max) min_max = current_max;
	}
	++min_max;
	cout << "lowest number K = " << min_max << '\n';
	for (int i = 0; i < number1; ++i) {
		delete[] matrix[i];
	}
	delete[] matrix;
	return 0;
}