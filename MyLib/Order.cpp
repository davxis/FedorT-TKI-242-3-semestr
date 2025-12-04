#include "Order.h"
#include <iostream>

Order::Order(const std::shared_ptr<Product>& product, int quantity)
    : product(product), quantity(quantity) {
    totalPrice = product->getPrice() * quantity;
}

std::shared_ptr<Product> Order::getProduct() const {
    return product;
}

int Order::getQuantity() const {
    return quantity;
}

double Order::getTotalAmount() const {
    return totalPrice;
}

void Order::displayInfo() const {
    std::cout << "Товар: " << product->getName()
              << ", Количество: " << quantity
              << ", Сумма: " << totalPrice << " руб." << std::endl;
}