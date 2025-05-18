#include <iostream>
#include "bankAccount.hpp"
#include "currency.hpp"
#include "USD.hpp"
#include "EUR.hpp"
#include "IRR.hpp"
#include "Item.hpp"
#include "ItemChild.hpp"
#include "Shopping.hpp"
#include <iomanip>
#include <stdexcept>
#include <algorithm>
#include <memory>

using namespace std;

void menu()
{
    cout << "\n";
    cout << "****************************************\n";
    cout << "*               SHOP MENU              *\n";
    cout << "****************************************\n";
    cout << "* 1. View Items                        *\n";
    cout << "* 2. Add item to cart                  *\n";
    cout << "* 3. Remove item from cart             *\n";
    cout << "* 4. View cart and receipt             *\n";
    cout << "* 5. Checkout and pay                  *\n";
    cout << "* 6. View account balance              *\n";
    cout << "* 7.Exit                               *\n";
    cout << "****************************************\n";
    cout << "Select an option to continue: ";
}

void boundary()
{
    cout << setw(50) << "_________________________________________________" << endl;
}

void viewItem(const vector<Item *> &stock)
{
    boundary();
    cout << setw(35) << "Available Items\n";
    boundary();
    if (stock.empty())
    {
        cout << "No items available in the shop.\n";
        boundary();
        return;
    }
    for (size_t i = 0; i < stock.size(); ++i)
    {
        cout << i + 1 << ". ";
        stock[i]->display();
        cout << "\t Inventory: " << stock[i]->get_inventory() << "\n";
        cout << "-------------------------------------------\n";
    }
    boundary();
}

void addItemToCart(vector<Item *> &stock, Shopping &cart)
{
    cout << "\nSelect item to add to cart:\n";

    viewItem(stock);

    if (stock.empty())
    {
        cout << "No items available in the shop.\n";
        boundary();
        return;
    }
    int selection;
    cout << "Enter item number (1-" << stock.size() << "): ";
    cin >> selection;
    if (cin.fail() || selection < 1 || selection > static_cast<int>(stock.size()))
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Invalid selection!\n";
        return;
    }
    int count;
    cout << "Enter quantity: ";
    cin >> count;
    if (cin.fail() || count <= 0)
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Quantity must be a positive number.\n";
        return;
    }
    Item *selectedItem = stock[selection - 1];
    try
    {
        cart.addItem(selectedItem, count);
        int i = count / 5;
        count += i;
        cout << count << " of " << selectedItem->get_name() << " added to cart successfully.\n";
    }
    catch (const exception &e)
    {
        cerr << "Error: " << e.what() << endl;
    }
}

void removeItemFromCart(std::vector<Item *> &stock, Shopping &cart)
{
    string name;
    int count;

    cout << "\nEnter full item name to remove (case-insensitive): ";

    cin.ignore();
    getline(cin, name);

    transform(name.begin(), name.end(), name.begin(), ::tolower);

    cout << "Enter quantity to remove: ";
    cin >> count;

    if (cin.fail() || count <= 0)
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Quantity must be a positive number.\n";
        return;
    }
    for (auto item : stock)
    {
        string itemName = item->get_name();
        transform(itemName.begin(), itemName.end(), itemName.begin(), ::tolower);

        if (itemName == name)
        {
            try
            {
                cart.delItem(item, count);
                cout << count << " of " << item->get_name() << " removed from cart.\n";
            }
            catch (const exception &e)
            {
                cerr << "Error: " << e.what() << "\n";
            }
            return;
        }
    }
    cout << "Item not found in the store.\n";
}

void viewCartReceipt(const Shopping &cart)
{
    if (cart.isEmpty())
    {
        cout << "\nYour cart is empty.\n";
        return;
    }
    cout << "=====  Cart & Receipt  =====\n";
    cout << cart;
}

void checkoutAndPay(BankAccount *customer, BankAccount *shop, Shopping &cart)
{
    if (!customer || !shop)
    {
        cerr << "Error: Invalid bank accounts.\n";
        return;
    }
    float total = cart.calculateTotal();
    unique_ptr<Currency> cost = make_unique<USD>(total);

    cout << "\n===== Checkout =====\n";
    cout << "Total amount to pay: " << total << " USD\n";

    if (customer->withdraw(cost.get()))
    {
        shop->deposit(cost.get());
        cout << "Payment successful! Thank you for your purchase.\n";
        cout << "Remaining balance: " << customer->getBalance() << " " << customer->getCurrencyCode() << endl;
    }
    else
    {
        cout << "Payment failed! Not enough balance or daily limit exceeded.\n";
    }
}

void viewAccountBalance(const BankAccount *account)
{
    if (!account)
    {
        cerr << "Error: Invalid account.\n";
        return;
    }

    cout << "\n========== Account Balance ==========\n";
    cout << std::left << std::setw(15) << "Owner:"
         << account->getName() << "\n";
    cout << std::left << std::setw(15) << "Balance:"
         << std::right << std::fixed << std::setprecision(2)
         << account->getBalance() << " " << account->getCurrencyCode() << "\n";
    cout << "=====================================\n";
}

int main()
{

    vector<Item *> stock;
    stock.push_back(new Fruit("Apple", 2.5, 100));
    stock.push_back(new Snack("Chips", 1.2, 50));
    stock.push_back(new Seasoning("Salt", 0.8, 80));
    stock.push_back(new Fruit("Banana", 20, 80));

    Shopping cart;
    for (auto &item : stock)
    {
        item->set_cart(&cart);
    }

    USD *userCurrency = new USD(1000);
    USD *shopCurrency = new USD(0);

    BankAccount customer("Marklar", "123", accountType::PERSONAL, userCurrency);
    BankAccount shop("SuperShop", "999", accountType::ORGANIZATIONAL, shopCurrency);

    int choice;
    do
    {
        menu();
        cin >> choice;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input. Please enter a number.\n";
            continue;
        }
        cout << "\n";
        switch (choice)
        {
        case 1:
            viewItem(stock);
            break;
        case 2:
            addItemToCart(stock, cart);
            break;
        case 3:
            removeItemFromCart(stock, cart);
            break;
        case 4:
            viewCartReceipt(cart);
            break;
        case 5:
            checkoutAndPay(&customer, &shop, cart);
            break;
        case 6:
            viewAccountBalance(&customer);
            break;
        case 7:
            cout << "Thank you for visiting the shop. Goodbye!\n";
            break;
        default:
            cout << "Invalid option. Please try again.\n";
        }
        cout << "\n";
    } while (choice != 7);

    for (auto &item : stock)
    {
        delete item;
    }

    return 0;
}