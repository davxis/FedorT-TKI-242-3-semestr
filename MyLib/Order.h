#pragma once

#include <memory>
#include <string>

class Product;

class Order {
private:
    std::shared_ptr<Product> product;
    int quantity;
    double totalPrice;

public:
    Order(const std::shared_ptr<Product>& product, const int quantity);

    std::shared_ptr<Product> getProduct() const;
    int getQuantity() const;
    double getTotalAmount() const;

    void displayInfo() const;

};
