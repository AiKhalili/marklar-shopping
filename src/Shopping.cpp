#include "Shopping.hpp"
#include <iostream>
using namespace std;

void Shopping::addItem(Item* item, int amount){

    int freeItem = amount / 5 ; //حساب کردن مقدار کالای داده شده بر  اساس تخفیف

    item->reduce_inventory(amount + freeItem); // کم کردن از موجودی این کالا از انبار

    for(auto it = items.begin(); it != items.end(); ++it){
        if (it->item_ptr == item) {
            it->amount += amount;
            return;
        }
    }
    items.emplace_back(item, amount, freeItem); // اگر این کالا از قبل وجود نداشته باشه می سازه و به سبد خرید اضافه میکنه
}

void Shopping::delItem(Item* item, int amount){
    
    for (auto it = items.begin(); it != items.end(); ++it) {

        if (it->item_ptr == item) {

            if (amount > it->amount) { // اگر مقداری که می خواد حذف کنه بیشتر از مقداری باشه که خریداری کرده
                throw runtime_error("Cannot remove more than what's in good!\n");
            }

            int freeToReturn = (amount * it->freeItems) / it->amount; // مقدار تخفیف رو که داده بود بر می گردونه

            item->increased_inventory(amount + freeToReturn); // به موجودی کالا تو انبار اضافه می کنه
            
            if (amount == it->amount) { // اگر مقداری که خریداری کرده با مقداری که می خواد حذف کنه از اون کالا برابر باشه کالا رو کلا از سبد خرید حذف می کنه
                items.erase(it);
            } 
            else {
                it->amount -= amount;
                it->freeItems -= freeToReturn;
            }
            return;
        }
    }
    
    throw runtime_error("Item not found in good!\n"); // اگر کالا پیدا نشه خطا پرت می کنه

}

float Shopping::calculateTotal() const {
    float total = 0.0;
    for (const auto& item : items) {
        total += item.item_ptr->getTotalPrice(item.amount);
    }
    return total;
}

ostream& operator<<(std::ostream& output, const Shopping& buy){
    output << "===== Receipt =====\n";
    for (size_t i = 0; i < buy.items.size(); ++i) {
        const auto& item = buy.items[i];
        output << (i+1) << ". ";
        item.item_ptr->display(); 
        
        output << "\t Quantity: " << item.amount; // تعداد خریداری شده از اون کالا
        if (item.freeItems > 0) {
            output << " (+" << item.freeItems << " free)";
        }
        output << "\n\t Subtotal: " 
              << item.item_ptr->getTotalPrice(item.amount) << "\n\n"; // محاصبه قیمت کل اون کالا بر اساس تعداد و قیمت هر یه عدد اون کالا
    }
    output << "-------------------\n";
    output << "TOTALPRICE: " << buy.calculateTotal() << "\n";
    output << "===================\n";
    return output;
}

