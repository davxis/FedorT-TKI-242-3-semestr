#pragma once

#include <vector>
#include <string>
#include <iostream>
#include <cstdlib>
#include <sstream>
#include "Generator.h"

// Matrix - îäíîìåðíûé ìàññèâ (íåñìîòðÿ íà íàçâàíèå)
template<class T>
class Matrix
{
protected:
    std::unique_ptr<T[]> items;

    // Ðàçìåð ìàññèâà
    size_t count;
public:
    // Ñîçäà¸ò ìàññèâ èç 10 ýëåìåíòîâ.
    Matrix() : count(10) {
        // Ïî óìîë÷àíèþ èñïîëüçóåì ìàññèâ èç 10 ýëåìåíòîâ,
        // ò.ê. èç 0 ýëåìåíòîâ íå èìååò ñìûñëà.
        items = std::make_unique<T[]>(10);
    }

    Matrix(const Matrix& other) : count(other.count) {
        items = std::make_unique<T[]>(count);
        for (size_t i = 0; i < count; i++) {
            items[i] = other.items[i];
        }
    }

    // Ñîçäà¸ò ìàññèâ èç count íóëåâûõ ýëåìåíòîâ.
    Matrix(const int count) : count(count) {
        items = std::make_unique<T[]>(count);
    }

    // Êîíñòðóêòîð ïåðåìåùåíèÿ
    Matrix(Matrix&& other) noexcept : items(std::move(other.items)), count(other.count) {
        other.count = 0;
    }

    ~Matrix() {
        /*
        â äåñòðóêòîðå äåëàòü íè÷åãî íå òðåáóåòñÿ,
        ò.ê. óìíûå óêàçàòåëè ñàìè óïðàâëÿþò ïàìÿòüþ
        */
    }

    // toString() âûäà¸ò ìàññèâ â ñëåäóþùåì âèäå: [12 3 5 8]
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

    //// Çàäà¸ò â êà÷åñòâå çíà÷åíèé âñåõ ýëåìåíòîâ
    //// ðàíäîìíûå çíà÷åíèÿ.
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

    // Îïåðàòîð ïåðåìåùåíèÿ
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

    // Äîñòóï ê ýëåìåíòàì ïî èíäåêñó
    T& operator[](const size_t index) {
        if (index >= count || index < 0) {
            throw std::out_of_range("Index out of range");
        }
        return items[index];
    }

    // Êîíñòàíòíûé äîñòóï ê ýëåìåíòàì ïî èíäåêñó
    const T& operator[](const size_t index) const {
        if (index >= count || index < 0) {
            throw std::out_of_range("Index out of range");
        }
        return items[index];
    }

    // Îæèäàåì èç ïîòîêà ââîäà is items.size() öåëûõ ÷èñåë,
    // îòäåë¸ííûõ äðóã îò äðóãà ïðîáåëüíûìè ñèìâîëàìè.
    friend std::istream& operator>>(std::istream& is, Matrix& matr) {
        for (size_t i = 0; i < matr.count; i++) {
            if (!(is >> matr.items[i])) {
                throw std::runtime_error("Invalid input");
            }
        }
        return is;
    }

    // Âûâîäèò â ïîòîê òàêæå êàê toString();
    friend std::ostream& operator<<(std::ostream& os, const Matrix& matr) {
        os << matr.toString();
        return os;
    }

    // generateValues çàäà¸ò â ýëåìåíòû ìàññèâà
    // çíà÷åíèÿ, ãåíåðèðóÿ èõ ñ ïîìîùüþ ãåíåðàòîðà generator.
    //
    // generator íå îáúÿâëåí ñ ìîäèôèêàòîðîì const,
    // ò.ê. îí ìîæåò ìåíÿòü çíà÷åíèÿ ñâîèõ ïîëåé ïðè âûçîâå generate(),
    // íàïðèìåð, äëÿ òîãî, ÷òîáû õðàíèòü, êàêîå çíà÷åíèå äîëæíî áûòü
    // ñãåíåðèðîâàíî ñëåäóþùèì.
    void generateValues(Generator<T>& generator) {
        for (size_t i = 0; i < count; i++) {
            items[i] = generator.generate();
        }
    }
};



