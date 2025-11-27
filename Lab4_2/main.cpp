#include <iostream>
#include <Matrix.h>

#include <memory>
#include <limits>

#include <locale>
#include <cstdlib> // exit()

#include "Excercise.h"
#include "Ex1.h"
#include "Ex2.h"
#include "Ex3.h"
#include "IStreamGenerator.h"
#include "RandomGenerator.h"
#include "ConstGenerator.h"
#include "ZeroGenerator.h"

using namespace std;

enum class UserChoice { TASK_1 = 1, TASK_2, TASK_3, QUIT };
enum class MatrixInputWay { BY_HAND = 1, RANDOM, BY_CONST, BY_ZEROS };

void printMenu();
UserChoice promptChoice();
unique_ptr<Excercise<int>> createExcercise(UserChoice choice);
MatrixInputWay selectMatrixInputWay();
unique_ptr<Generator<int>> createGenerator(MatrixInputWay inputWay);
int selectConstValue();

template <typename T>
bool safeInput(T& value);


int main() {
	// Поддержка кириллицы
	setlocale(LC_ALL, "Rus");

	while (true) {
		printMenu();
		UserChoice choice = promptChoice();

		if (choice == UserChoice::QUIT) {
			// То, что пользователь решил выйти,
			// не является ошибкой.
			//
			// Поэтому используем нулевой код возврата
			return 0;
		}

		unique_ptr<Excercise<int>> ex = createExcercise(choice);
		ex->Do();
	}

	return 0;
}


void printMenu() {
	cout << (int)UserChoice::TASK_1 << ". Заменить максимальный на противоположный\n";
	cout << (int)UserChoice::TASK_2 << ". Вставить максимальный после элементов с цифрой 1\n";
	cout << (int)UserChoice::TASK_3 << ". Создать массив A на основе C, где A[i] = C[i] + i для чётных i, и A[i] = C[i] - i для нечётных i\n";
	cout << (int)UserChoice::QUIT << ". Выход\n";
}

UserChoice promptChoice() {
	cout << "Ваш выбор (1-4): ";
	int choice;
	if (!safeInput(choice)) {
		return UserChoice::QUIT;
	}
	if (choice < (int)UserChoice::TASK_1 || choice >= (int)UserChoice::QUIT) {
		return UserChoice::QUIT;
	}
	return UserChoice(choice);
}

unique_ptr<Excercise<int>> createExcercise(UserChoice choice) {
	cout << "Размер массива: ";
	int n;
	cin >> n;

	auto matrix = make_unique<Matrix<int>>(n);

	MatrixInputWay inputWay = selectMatrixInputWay();
	auto generator = createGenerator(inputWay);

	switch (choice) {
	case UserChoice::TASK_1:
		return make_unique<Ex1>(std::move(matrix), std::move(generator));
	case UserChoice::TASK_2:
		return make_unique<Ex2>(std::move(matrix), std::move(generator));
	case UserChoice::TASK_3:
		return make_unique<Ex3>(std::move(matrix), std::move(generator));
	default:
		throw new runtime_error("Bad choice value in createExcercise()");
	}
}


MatrixInputWay selectMatrixInputWay() {
	cout << "Выберите способ ввода матрицы:\n";
	cout << (int)MatrixInputWay::BY_HAND << ". Вручную\n";
	cout << (int)MatrixInputWay::RANDOM << ". Рандомом из диапазона [-1000; 1000]\n";
	cout << (int)MatrixInputWay::BY_CONST << ". Константой\n";
	cout << (int)MatrixInputWay::BY_ZEROS << ". Нулями\n";
	cout << "Ваш выбор (1-4): ";
	int choice;
	if (!safeInput(choice) || choice < (int)MatrixInputWay::BY_HAND
		|| choice > (int)MatrixInputWay::BY_ZEROS) {
		cout << "Не верный выбор. Нужно указать число от 1 до 4" << endl << endl;
		exit(EXIT_FAILURE);
	}
	return (MatrixInputWay)choice;
}

unique_ptr<Generator<int>> createGenerator(MatrixInputWay inputWay) {
	switch (inputWay) {
	case MatrixInputWay::BY_HAND:
		return make_unique<IStreamGenerator>(cin);
	case MatrixInputWay::RANDOM:
		return make_unique<RandomGenerator>(-1000, 1000);
	case MatrixInputWay::BY_CONST: {
		int constValue = selectConstValue();
		return make_unique<ConstGenerator>(constValue);
	}
	case MatrixInputWay::BY_ZEROS:
		return make_unique<ZeroGenerator>();
	default:
		throw new runtime_error("Bad input way value in createGenerator()");
	}
}

int selectConstValue() {
	while (true) {
		cout << "Выберите константу для наполнения массива: ";
		int val;
		if (!safeInput(val)) {
			cout << "Необходимо ввести число" << endl << endl;
			continue;
		}
		return val;
	}
}

// Обобщённая функция для безопасного ввода
template <typename T>
bool safeInput(T& value) {
	if (cin >> value) {
		// Успешный ввод
		return true;
	}
	// Сбрасываем флаг ошибки, иначе cin перестанет работать
	cin.clear();

	// Игнорируем остаток строки, иначе ввод зациклится
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	// Неудачный ввод
	return false;
}
