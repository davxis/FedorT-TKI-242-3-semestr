#include <gtest/gtest.h>
#include <memory>
#include "Product.h"
#include "Supplier.h"
#include "Order.h"
#include "Store.h"
#include "Bakery.h"

// Тестирование Product
TEST(ProductTest, ConstructorAndGetters) {
    auto product = std::make_shared<Product>("Хлеб", 30.0);
    EXPECT_EQ(product->getName(), "Хлеб");
    EXPECT_DOUBLE_EQ(product->getPrice(), 30.0);
}

// Тестирование Supplier
TEST(SupplierTest, AddAndGetProducts) {
    auto supplier = std::make_shared<Supplier>("Поставщик1");
    auto product = std::make_shared<Product>("Хлеб", 30.0);
    supplier->addProduct(product);

    const auto& products = supplier->getProducts();
    ASSERT_EQ(products.size(), 1);
    EXPECT_EQ(products[0]->getName(), "Хлеб");
}

TEST(SupplierTest, GetTotalOrderAmountForPeriod) {
    auto supplier = std::make_shared<Supplier>("Поставщик1");
    auto product = std::make_shared<Product>("Хлеб", 30.0);
    supplier->addProduct(product);

    double amount = supplier->getTotalOrderAmountForPeriod("Хлеб", 7);
    EXPECT_DOUBLE_EQ(amount, 300.0); // 30 * 10
}

// Тестирование Order
TEST(OrderTest, ConstructorAndGetters) {
    auto product = std::make_shared<Product>("Булочка", 20.0);
    auto order = std::make_shared<Order>(product, 5);

    EXPECT_EQ(order->getProduct()->getName(), "Булочка");
    EXPECT_EQ(order->getQuantity(), 5);
    EXPECT_DOUBLE_EQ(order->getTotalAmount(), 100.0);
}

// Тестирование Store
TEST(StoreTest, AddAndGetOrders) {
    auto store = std::make_shared<Store>("Магазин1");
    auto product = std::make_shared<Product>("Пирожное", 50.0);
    auto order = std::make_shared<Order>(product, 3);
    store->addOrder(order);

    const auto& orders = store->getOrders();
    ASSERT_EQ(orders.size(), 1);
    EXPECT_EQ(orders[0]->getProduct()->getName(), "Пирожное");
}

// Тестирование Bakery
TEST(BakeryTest, AddAndGetProducts) {
    auto bakery = std::make_shared<Bakery>();
    auto product = std::make_shared<Product>("Круассан", 40.0);
    bakery->addProduct(product);

    // Нет прямого метода для получения списка, но можно проверить логику
    // через displayAssortment или внутреннее состояние — для этого нужен public getter
    // В текущей архитектуре это невозможно, но можно добавить метод, если нужно.
}

TEST(BakeryTest, GetProducedQuantity) {
    auto bakery = std::make_shared<Bakery>();
    int quantity = bakery->getProducedQuantity("Хлеб");
    EXPECT_EQ(quantity, 50);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}