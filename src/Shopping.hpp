#ifndef SHOPPING_HPP
#define SHOPPING_HPP
#include "ItemChild.hpp"
#include <vector>
#include <iostream>

class Shopping{

    friend std::ostream& operator<<(std::ostream& , const Shopping&); // عملگر درج در جریان برای چاپ رسید

    private:
    struct Feature{ // اینجا یه ساختمان داریم که:
        Item* item_ptr; // اشاره گر به کالای خریداری شده
        int amount; // مقداری که از اون کالا خریداری شده
        unsigned int freeItems; // مقداری از کالا که با توجه به قانون تخفیف به کاربر داده شده
        Feature(Item* i, int a, unsigned int f = 0):item_ptr(i), freeItems(f){
            if(a <= 0){
                throw std::runtime_error("Amounts goods can only be positive!\n");
            }
            amount = a;
        }
 //کانستراکتور برای ست کردن صفت های استراکت
    };

    std::vector<Feature> items; // این در اصل سبد خریده که وکتوری از اون استراکت رو نگه میداره
 
    public:
    void addItem(Item*, int); // اضافه کردن یک کالا به سبد خرید
    void delItem(Item*, int); // حذف یک کالا از سبد خرید
    float calculateTotal() const; // به درست اوردن هزینه کل کالاهای خریداری شده
    bool isEmpty() const;
};


#endif