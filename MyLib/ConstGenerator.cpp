#include "ConstGenerator.h"

ConstGenerator::ConstGenerator(const int value) : value(value) {
    /* ничего */
}

int ConstGenerator::generate() {
    return value;
}
