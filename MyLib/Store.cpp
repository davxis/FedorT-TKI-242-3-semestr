#include "Store.h"
#include "Order.h"
#include <iostream>
#include <iomanip>

Store::Store(const std::string& name) : name(name) {}

std::string Store::getName() const {
    return name;
}

void Store::addOrder(const std::shared_ptr<Order>& order) {
    orders.push_back(order);
}

const std::vector<std::shared_ptr<Order>>& Store::getOrders() const {
    return orders;
}

void Store::displayOrderSummary() const {
    std::cout << "=== Заказы магазина " << name << "" << std::endl;
    double totalSum = 0.0;
    for (const auto& order : orders) {
        order->displayInfo();
        totalSum += order->getTotalAmount();
    }
    std::cout << "Общая сумма заказа: " << std::fixed << std::setprecision(2) << totalSum << " руб" << std::endl;

}
