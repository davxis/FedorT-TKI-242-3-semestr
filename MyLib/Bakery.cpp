#include "Bakery.h"
#include <iostream>
#include <algorithm>

void Bakery::addProduct(const std::shared_ptr<Product>& product) {
    assortment.push_back(product);
}

void Bakery::addSupplier(const std::shared_ptr<Supplier>& supplier) {
    suppliers.push_back(supplier);
}

void Bakery::addStore(const std::shared_ptr<Store>& store) {
    stores.push_back(store);
}

void Bakery::displayAssortment() const {
    std::cout << " Ассортимент хлебопекарни " << std::endl;
    for (const auto& product : assortment) {
        product->displayInfo();
    }
}

int Bakery::getProducedQuantity(const std::string& productName) const {
    return 50;

}
