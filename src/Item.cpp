#include "Item.hpp"
#include "Shopping.hpp"
#include <iostream>
using namespace std;

Item::Item(std::string name, float price,int inventory, Unit unit){
    this->name = name;
    this->unit = unit;
    set_price(price);
    set_inventory(inventory);
}

string Item::get_name() const{return name;}
float Item::get_price() const{return price;}
int Item::get_inventory() const{return inventory;}
Unit Item::get_unit() const{return unit;}

void Item::set_price(float PRICE){
    if(PRICE <=0 ){
        throw invalid_argument("Price can only be postivie!\n");
    }
    this->price = PRICE;
}

void Item::set_inventory(int INVENTORY){
    if(INVENTORY <= 0){
        throw invalid_argument("Inventory can only be postivie!\n");
    }
    this->inventory = INVENTORY;
}

void Item::set_cart(Shopping* cart){
    this->cart = cart;
}

string Item::show_unit() const {
    if(get_unit() == Unit::Kg){
        return "Kg";
    }
    if(get_unit() == Unit::g){
        return "g";
    }
    if(get_unit() == Unit::pakage){
        return "pakage";
    }
    throw runtime_error("Unknown unit");
}

void Item::reduce_inventory(int count){
    if(count > inventory){
        throw invalid_argument("The requested amount of inventory is greater!\n");
    }
    inventory -= count; // کم کردن مقدار خریداری شده از انبار
}

void Item::increased_inventory(int count){
    inventory += count; // اضافه کردن مقدار حذف شده از سبد خرید به انبار
}

float Item::getTotalPrice(int count) const{
    return count*price ; // برگرداندن قیمت کل یک کالا بر اساس مقدار خریداری شده و قیمت
}


Item& Item::operator++() {
    if(cart) {
        cart->addItem(this, 1); // اضافه کردن یک عدد از این کالا به سبد خرید
    } 
    else{
        cerr << "Shopping cart is not set for this item!" << endl;
    }
    return *this;
}

Item& Item::operator--() {
    if(cart) {
        cart->delItem(this, 1); // کم کردن یک عدد از این کالا از سبد خرید
    } 
    else{
        cerr << "Shopping cart is not set for this item!" << endl;
    }
    return *this;
}