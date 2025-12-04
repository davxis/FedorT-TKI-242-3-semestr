#include "Supplier.h"
#include "Product.h"
#include <algorithm>

Supplier::Supplier(const std::string& name) : name(name) {}

std::string Supplier::getName() const {
    return name;
}

void Supplier::addProduct(const std::shared_ptr<Product>& product) {
    products.push_back(product);
}

const std::vector<std::shared_ptr<Product>>& Supplier::getProducts() const {
    return products;
}

double Supplier::getTotalOrderAmountForPeriod(const std::string& productName, int periodDays) const {
    auto it = std::find_if(products.begin(), products.end(),
        [&productName](const std::shared_ptr<Product>& p) {
            return p->getName() == productName;
        });
    if (it != products.end()) {
        return (*it)->getPrice() * 10;
    }
    return 0.0;
}