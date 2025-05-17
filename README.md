# Marklar Goes Shopping

## Profiles
- [Zeinab Khalili] [40312358011] (https://github.com/AiKhalili)
- [Fatemeh Shabani] [40312358022] (https://github.com/ftmshab)

## Overview
This project is a simulation of a shopping system for a futuristic supermarket. It supports different product types and units, currency conversions, discount rules, and manages both personal and organizational bank accounts for transactions.

Built with C++ using OOP, inheritance, and operator overloading.

---

## Features

### 1. Item Management
- Base Class: Item
- Derived Classes:
  - Fruit (measured in kilograms)
  - Seasoning (measured in grams)
  - Snack (measured in packages)
- Each item has:
  - Name
  - Price
  - Available stock
  - Unit of measurement

### 2. Currency System
- Base Class: Currency
- Derived Classes:
  - USD, EUR, IRR
- Supports automatic conversion between currencies

### 3. Operator Overloading
- ++ operator: Adds one unit of an item to the shopping cart
- Discount: For every 5 units, the customer gets 1 extra unit free
- << stream operator: Prints item receipt line
- Arithmetic operators (+, -, *, /) for currency operations
- Comparison operators (==, !=, <, >) for comparing currency values

### 4. Bank Account System
- Supports:
  - Personal accounts (daily limit: $1000)
  - Organizational accounts (daily limit: $10,000)
- Zero transaction fees
- Basic operations:
  - deposit(amount)
  - withdraw(amount)
  - getBalance()

---

## How to Build & Run (with CMake)

git clone https://github.com/AiKhalili/marklar-shopping.git
git clone https://github.com/ftmshab/marklar-shopping.git
cd marklar-shopping
mkdir build
cd build
cmake ..
make
./app
---

## Project Structure

.
├── src/
│   ├── Item.hpp / Item.cpp
│   ├── currency.hpp / currency.cpp
│   ├── bankAccount.hpp / bankAccount.cpp
│   ├── shopping.hpp / shopping.cpp
│   ├── ItemChild.hpp / ItemChild.cpp
│   ├── USD.hpp / USD.cpp
│   ├── IRR.hpp / IRR.cpp
│   ├── EUR.hpp / EUR.cpp
│   └── main.cpp
├── CMakeLists.txt
├── build/ (generated after running cmake)
├── README.md
└── .gitignore
---

