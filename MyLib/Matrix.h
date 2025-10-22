#pragma once

#include <vector>
#include <string>
#include <iostream>
#include <cstdlib>
#include <sstream>
#include "Generator.h"

// Matrix - одномерный массив (несмотря на название)
template<class T>
class Matrix
{
protected:
    std::unique_ptr<T[]> items;

    // Размер массива
    size_t count;
public:
    // Создаёт массив из 10 элементов.
    Matrix() : count(10) {
        // По умолчанию используем массив из 10 элементов,
        // т.к. из 0 элементов не имеет смысла.
        items = std::make_unique<T[]>(10);
    }

    Matrix(const Matrix& other) : count(other.count) {
        items = std::make_unique<T[]>(count);
        for (size_t i = 0; i < count; i++) {
            items[i] = other.items[i];
        }
    }

    // Создаёт массив из count нулевых элементов.
    Matrix(const int count) : count(count) {
        items = std::make_unique<T[]>(count);
    }

    // Конструктор перемещения
    Matrix(Matrix&& other) noexcept : items(std::move(other.items)), count(other.count) {
        other.count = 0;
    }

    ~Matrix() {
        /*
        в деструкторе делать ничего не требуется,
        т.к. умные указатели сами управляют памятью
        */
    }

    // toString() выдаёт массив в следующем виде: [12 3 5 8]
    std::string toString() const {
        std::ostringstream oss;
        oss << "[";
        for (size_t i = 0; i < count; i++) {
            if (i > 0) {
                oss << " ";
            }
            oss << items[i];
        }
        oss << "]";
        return oss.str();
    }

    //// Задаёт в качестве значений всех элементов
    //// рандомные значения.
    //void randomize(int minVal, int maxVal) {
    //    for (int i = 0; i < items.size(); i++) {
    //        int value = rand() % (maxVal - minVal + 1) + minVal;
    //        items[i] = value;
    //    }
    //}

    Matrix& operator=(const Matrix& other) {
        if (this != &other) {
            count = other.count;
            items = std::make_unique<T[]>(count);
            for (size_t i = 0; i < count; i++) {
                items[i] = other.items[i];
            }
        }
        return *this;
    }

    // Оператор перемещения
    Matrix& operator=(Matrix&& other) noexcept {
        if (this != &other) {
            items = std::move(other.items);
            count = other.count;
            other.count = 0;
        }
        return *this;
    }

    size_t getCount() const {
        return count;
    }

    // Доступ к элементам по индексу
    T& operator[](const size_t index) {
        if (index >= count || index < 0) {
            throw std::out_of_range("Index out of range");
        }
        return items[index];
    }

    // Константный доступ к элементам по индексу
    const T& operator[](const size_t index) const {
        if (index >= count || index < 0) {
            throw std::out_of_range("Index out of range");
        }
        return items[index];
    }

    // Ожидаем из потока ввода is items.size() целых чисел,
    // отделённых друг от друга пробельными символами.
    friend std::istream& operator>>(std::istream& is, Matrix& matr) {
        for (size_t i = 0; i < matr.count; i++) {
            if (!(is >> matr.items[i])) {
                throw std::runtime_error("Invalid input");
            }
        }
        return is;
    }

    // Выводит в поток также как toString();
    friend std::ostream& operator<<(std::ostream& os, const Matrix& matr) {
        os << matr.toString();
        return os;
    }

    // generateValues задаёт в элементы массива
    // значения, генерируя их с помощью генератора generator.
    //
    // generator не объявлен с модификатором const,
    // т.к. он может менять значения своих полей при вызове generate(),
    // например, для того, чтобы хранить, какое значение должно быть
    // сгенерировано следующим.
    void generateValues(Generator<T>& generator) {
        for (size_t i = 0; i < count; i++) {
            items[i] = generator.generate();
        }
    }
};

