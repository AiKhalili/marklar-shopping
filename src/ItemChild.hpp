#ifndef ITEMCHILD_HPP
#define ITEMCHILD_HPP
#include "Item.hpp"
#include <iostream>

class Fruit : public Item{ // میوه که از کلاس item به ارث می بره
    public:
    Fruit(std::string, float, int);
    std::string getCategory() const; //برگرداندن دسته بندی که اینجا میوه است
    void display() const; // چاپ ویژگی های هر کالا
};

class Seasoning: public Item{ // ادویه که از کلاس item به ارث می بره
    public:
    Seasoning(std::string, float, int);
    std::string getCategory() const; //برگرداندن دسته بندی که اینجا ادویه است
    void display() const; // چاپ ویژگی های هر کالا
};

class Snack : public Item{ // خوراکی که از کلاس item به ارث می بره
    public:
    Snack(std::string, float, int);
    std::string getCategory() const; //برگرداندن دسته بندی که اینجا خوراکی است
    void display() const; // چاپ ویژگی های هر کالا
};

#endif