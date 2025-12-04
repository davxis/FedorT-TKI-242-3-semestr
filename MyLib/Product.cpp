#include "Product.h"
#include <iostream>

Product::Product(const std::string& name, double price)
    : name(name), price(price) {}

std::string Product::getName() const {
    return name;
}

double Product::getPrice() const {
    return price;
}

void Product::displayInfo() const {
    std::cout << "Товар: " << name << ", Цена: " << price << " руб." << std::endl;
}