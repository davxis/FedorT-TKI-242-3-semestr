#include "Ex2.h"

Ex2::Ex2(std::unique_ptr<Matrix<int>> matrix,
    std::unique_ptr<Generator<int>> generator)
    : Excercise<int>(std::move(matrix), std::move(generator)) {}

void Ex2::Task2() {
    if (matrix->getCount() == 0) {
        return;
    }
    int maxValue = (*matrix)[0];
    for (size_t i = 1; i < matrix->getCount(); i++) {
        if ((*matrix)[i] > maxValue) {
            maxValue = (*matrix)[i];
        }
    }
    // Íà÷èíàåì ñ êîíöà, ÷òîáû â ñëó÷àå, êîãäà ìàêñèìàëüíûé
    // ýëåìåíò ñàì ïî ñåáå ñîäåðæèò öèôðó 1, âñå îñòàëüíûå
    // ïîñëå íåãî ýëåìåíòû íå áûëè çàäàíû â ìàêñèìàëüíûé.
    //
    // Óñëîâèå i >= 0 íå áóäåò ðàáîòàòü, ò.ê. ïåðåìåííàÿ òèïà size_t âñåãäà >= 0.
    for (size_t i = matrix->getCount() - 2; i != static_cast<size_t>(-1); i--) {
        if (Contains1((*matrix)[i])) {
            (*matrix)[i + 1] = maxValue;
        }
    }
}

// Contains1 ïðîâåðÿåò, åñòü ëè öèôðà 1 â ÷èñëå value
bool Ex2::Contains1(int value) {
    if (value < 0) {
        value = -value;
    }
    while (value) {
        int digit = value % 10;
        if (digit == 1) {
            return true;
        }
        value /= 10;
    }
    return false;
}
