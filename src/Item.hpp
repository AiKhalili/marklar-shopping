#ifndef ITEM_HPP
#define ITEM_HPP
#include <iostream>
#include <string>
#include <stdexcept>

class Shopping;

enum class Unit{Kg, g, pakage}; // واحد هارو بر اساس enum نوشتیم تا راحت تر باشه

class Item{

    private:
    std::string name; // اسم کالا
    float price; // قیمت کالا
    int inventory; // موجودی کالا در انبار
    Unit unit; // واحد محاسبه قیمت کالا

    protected:
    Shopping* cart = nullptr; //اینجا یک اشاره گر به یک سبد خرید میزاریم (برای سربارگزاری عملگر ++ احتیاج بود)

    public:
    Item(std::string, float, int, Unit); // کانستراکتور
    virtual ~Item() = default;

    std::string get_name() const; // برگرداندن اسم
    float get_price() const; // برگرداندن قیمت
    int get_inventory() const; // برگرداندن موجودی کالا
    Unit get_unit() const; // برگرداندن واحد
    void set_price(float); // چک کردن منفی نبودن قیمت
    void set_inventory(int); // چک کردن منفی نبودن موجودی کالا
    void set_cart(Shopping*);

    std::string show_unit() const; // واحد کالا رو چی چاپ کنه

    void reduce_inventory(int count); // کم کردن موجودی کالا هنگام خرید
    void increased_inventory(int count); // افزایش موجودی کالا

    virtual float getTotalPrice(int count) const; // محاسبه قیمت کل بر اساس تعدادی که میخره
    virtual void display() const = 0; // چاپ ویژگی های هر کالا
    virtual std::string getCategory() const = 0; // این تابع دسته بندی هر شی تعریف شده رو بر میگردونه
    Item& operator++(); // موجودی کالا رو در سبد خرید کاربر یکی افزایش میده
    Item& operator--(); // موجودی کالا رو در سبد خرید کاربر یکی کاهش میده

};
#endif