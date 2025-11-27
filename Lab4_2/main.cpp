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

  UserChoice choice;
  do {
    printMenu();
    choice = promptChoice();

    switch (choice) {
      case UserChoice::TASK_1:
      case UserChoice::TASK_2:
      case UserChoice::TASK_3: {
        unique_ptr<Excercise<int>> ex = createExcercise(choice);
        ex->Do();
        break;
      }
      case UserChoice::QUIT:
        cout << "Выход из программы.\n";
        return 0;
      default:
        cout << "Неизвестный выбор. Завершение.\n";
        return EXIT_FAILURE;
    }

    cout << "\n--- Нажмите Enter, чтобы продолжить ---\n";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();

  } while (true);
}


void printMenu() {
  cout << "\n";
  cout << (int)UserChoice::TASK_1 << ". Заменить максимальный на противоположный\n";
  cout << (int)UserChoice::TASK_2 << ". Вставить максимальный после элементов с цифрой 1\n";
  cout << (int)UserChoice::TASK_3 << ". Создать массив A на основе C: A[i] = C[i] + i (чётные i), A[i] = C[i] - i (нечётные i)\n";
  cout << (int)UserChoice::QUIT << ". Выход\n";
  cout << "\n";
}

UserChoice promptChoice() {
  cout << "Ваш выбор (1-4): ";
  int choice;
  if (!safeInput(choice)) {
    cout << "Ошибка ввода. Выход.\n";
    return UserChoice::QUIT;
  }

  switch (choice) {
    case (int)UserChoice::TASK_1: return UserChoice::TASK_1;
    case (int)UserChoice::TASK_2: return UserChoice::TASK_2;
    case (int)UserChoice::TASK_3: return UserChoice::TASK_3;
    case (int)UserChoice::QUIT:   return UserChoice::QUIT;
    default:
      cout << "Неверный ввод. Допустимые значения: 1–4.\n";
      return UserChoice::QUIT;
  }
}

unique_ptr<Excercise<int>> createExcercise(UserChoice choice) {
  cout << "Размер массива: ";
  int n;
  if (!safeInput(n) || n <= 0) {
    cout << "Некорректный размер. Должно быть целое положительное число.\n";
    exit(EXIT_FAILURE);
  }

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
      throw runtime_error("Некорректный выбор задачи в createExcercise()");
  }
}

MatrixInputWay selectMatrixInputWay() {
  cout << "\nСпособ заполнения массива:\n";
  cout << (int)MatrixInputWay::BY_HAND << ". Вручную\n";
  cout << (int)MatrixInputWay::RANDOM << ". Случайными числами [-1000; 1000]\n";
  cout << (int)MatrixInputWay::BY_CONST << ". Заданной константой\n";
  cout << (int)MatrixInputWay::BY_ZEROS << ". Нулями\n";
  cout << "Ваш выбор (1–4): ";

  int choice;
  if (!safeInput(choice)) {
    cout << "Ошибка ввода. Выход.\n";
    exit(EXIT_FAILURE);
  }

switch (choice) {
    case (int)MatrixInputWay::BY_HAND:  return MatrixInputWay::BY_HAND;
    case (int)MatrixInputWay::RANDOM:    return MatrixInputWay::RANDOM;
    case (int)MatrixInputWay::BY_CONST:  return MatrixInputWay::BY_CONST;
    case (int)MatrixInputWay::BY_ZEROS:  return MatrixInputWay::BY_ZEROS;
    default:
      cout << "Неверный выбор. Допустимые значения: 1–4.\n";
      exit(EXIT_FAILURE);
  }
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
      throw runtime_error("Некорректный способ ввода в createGenerator()");
  }
}

int selectConstValue() {
  constexpr int MAX_ATTEMPTS = 3;
  int attempts = 0;

  int val;
  do {
    cout << "Введите константу для заполнения массива: ";
    if (safeInput(val)) {
      return val;
    }
    ++attempts;
    cout << "Ошибка ввода. Попытка " << attempts << " из " << MAX_ATTEMPTS << ".\n";
  } while (attempts < MAX_ATTEMPTS);

  cout << "Слишком много ошибок. Завершение.\n";
  exit(EXIT_FAILURE);
}

// Обобщённая функция для безопасного ввода
template <typename T>
bool safeInput(T& value) {
  if (cin >> value) {
    // Успешный ввод
    return true;
  }
  // Сброс ошибки ввода
  cin.clear();
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  return false;
}
