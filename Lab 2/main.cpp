#include <iostream>
#include <memory>
#include <vector>
#include "Bakery.h"
#include "Product.h"
#include "Supplier.h"
#include "Store.h"
#include "Order.h"

int main() {
    std::cout << "Хлебопекарня: Демонстрационная программа" << std::endl;

    auto bakery = std::make_shared<Bakery>();

    auto bread = std::make_shared<Product>("Хлеб белый", 35.0);
    auto bun = std::make_shared<Product>("Булочка с изюмом", 25.0);
    auto cake = std::make_shared<Product>("Пирожное Наполеон", 80.0);

    bakery->addProduct(bread);
    bakery->addProduct(bun);
    bakery->addProduct(cake);

    auto supplier1 = std::make_shared<Supplier>("Мельница Зерно");
    supplier1->addProduct(bread);
    supplier1->addProduct(bun);

    auto supplier2 = std::make_shared<Supplier>("Кондитерская Сладко");
    supplier2->addProduct(cake);

    bakery->addSupplier(supplier1);
    bakery->addSupplier(supplier2);

    auto store1 = std::make_shared<Store>("Магазин У дома");
    auto store2 = std::make_shared<Store>("Супермаркет 'Городской'");

    auto order1 = std::make_shared<Order>(bread, 20);
    auto order2 = std::make_shared<Order>(cake, 15);

    store1->addOrder(order1);
    store2->addOrder(order2);

    bakery->addStore(store1);
    bakery->addStore(store2);

    std::cout << "\n Задание 1: Ассортимент " << std::endl;
    bakery->displayAssortment();

    std::cout << "\n Задание 2: Заказы у поставщика " << std::endl;
    double amount = supplier1->getTotalOrderAmountForPeriod("Хлеб белый", 30);
    std::cout << "Сумма заказа Хлеб белый у поставщика " << supplier1->getName()
              << " за 30 дней: " << amount << " руб." << std::endl;

    std::cout << "\n Задание 3: Заказы магазина " << std::endl;
    store1->displayOrderSummary();

    std::cout << "\n Задание 4: Произведено товара " << std::endl;
    int produced = bakery->getProducedQuantity("Хлеб белый");
    std::cout << "Произведено Хлеб белый: " << produced << " шт." << std::endl;

    std::cout << "\n Программа завершена " << std::endl;

    return 0;

}
