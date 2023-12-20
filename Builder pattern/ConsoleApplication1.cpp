// Виконав Іван Єнко
#include <Windows.h>
#include <iostream>
#include <string>

// Клас, який представляє складний об'єкт
class Product {
public:
    void setPartA(const std::string& partA) {
        partA_ = partA;
    }

    void setPartB(const std::string& partB) {
        partB_ = partB;
    }

    void setPartC(const std::string& partC) {
        partC_ = partC;
    }

    void show() const {
        std::cout << "Part A: " << partA_ << std::endl;
        std::cout << "Part B: " << partB_ << std::endl;
        std::cout << "Part C: " << partC_ << std::endl;
    }

private:
    std::string partA_;
    std::string partB_;
    std::string partC_;
};

// Абстрактний будівельник
class Builder {
public:
    virtual void buildPartA() = 0;
    virtual void buildPartB() = 0;
    virtual void buildPartC() = 0;
    virtual Product getResult() = 0;
};

// Конкретний будівельник
class ConcreteBuilder : public Builder {
public:
    ConcreteBuilder() {
        product_ = new Product();
    }

    void buildPartA() override {
        product_->setPartA("Part A");
    }

    void buildPartB() override {
        product_->setPartB("Part B");
    }

    void buildPartC() override {
        product_->setPartC("Part C");
    }

    Product getResult() override {
        return *product_;
    }

private:
    Product* product_;
};

// Директор, який використовує будівельник для конструювання об'єкта
class Director {
public:
    Product construct(Builder& builder) {
        builder.buildPartA();
        builder.buildPartB();
        builder.buildPartC();
        return builder.getResult();
    }
};

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    ConcreteBuilder builder;
    Director director;

    Product product = director.construct(builder);
    product.show();

    return 0;
}
