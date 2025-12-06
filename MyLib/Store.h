#pragma once

#include <string>
#include <vector>
#include <memory>

class Order;

class Store {
private:
    std::string name;
    std::vector<std::shared_ptr<Order>> orders;

public:
    Store(const std::string& name);

    std::string getName() const;
    void addOrder(const std::shared_ptr<Order>& order);
    const std::vector<std::shared_ptr<Order>>& getOrders() const;

    void displayOrderSummary() const;
};