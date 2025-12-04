#pragma once

#include <string>
#include <memory>

class Product {
protected:
    std::string name;
    double price;

public:
    Product(const std::string& name, double price);
    virtual ~Product() = default;

    std::string getName() const;
    double getPrice() const;

    virtual void displayInfo() const;
};