#pragma once

#include <vector>
#include <memory>

class Product;
class Supplier;
class Store;

class Bakery {
private:
    std::vector<std::shared_ptr<Product>> assortment;
    std::vector<std::shared_ptr<Supplier>> suppliers;
    std::vector<std::shared_ptr<Store>> stores;

public:
    void addProduct(const std::shared_ptr<Product>& product);
    void addSupplier(const std::shared_ptr<Supplier>& supplier);
    void addStore(const std::shared_ptr<Store>& store);

    void displayAssortment() const;

    int getProducedQuantity(const std::string& productName) const;
};