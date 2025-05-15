#include "ItemChild.hpp"
#include <iostream>
using namespace std;

Fruit::Fruit(std::string name, float price, int inventory):Item(name, price, inventory, Unit::Kg){}

std::string Fruit::getCategory() const { return "Fruit";}

void Fruit::display() const{
    cout << "~Category:  " << getCategory() << endl;
    cout << "\t Name:  " << get_name() << endl;
    cout << "\t Price:  " << get_price() << endl;
    cout << "\t Unit:  " << show_unit() << endl;
}


Seasoning::Seasoning(std::string name, float price, int inventory):Item(name, price, inventory, Unit::Kg){}

std::string Seasoning::getCategory() const { return "Seasoning";}

void Seasoning::display() const{
    cout << "~Category:  " << getCategory() << endl;
    cout << "\t Name:  " << get_name() << endl;
    cout << "\t Price:  " << get_price() << endl;
    cout << "\t Unit:  " << show_unit() << endl;
}


Snack::Snack(std::string name, float price, int inventory):Item(name, price, inventory, Unit::Kg){}

std::string Snack::getCategory() const { return "Snack";}

void Snack::display() const{
    cout << "~Category:  " << getCategory() << endl;
    cout << "\t Name:  " << get_name() << endl;
    cout << "\t Price:  " << get_price() << endl;
    cout << "\t Unit:  " << show_unit() << endl;
}
