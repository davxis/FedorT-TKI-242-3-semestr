#pragma once

#include <string>
#include <vector>
#include <memory>

class Product;

class Supplier {
private:
    std::string name;
    std::vector<std::shared_ptr<Product>> products;

public:
    Supplier(const std::string& name);

    std::string getName() const;
    void addProduct(const std::shared_ptr<Product>& product);
    const std::vector<std::shared_ptr<Product>>& getProducts() const;

    double getTotalOrderAmountForPeriod(const std::string& productName, int periodDays) const;
};