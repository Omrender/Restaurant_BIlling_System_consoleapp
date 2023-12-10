#include <bits/stdc++.h>

using namespace std;

class MenuItem {
private:
    string itemName;
    double price;
    string category;

public:
    MenuItem(string name, double itemPrice, string itemCategory) {
        itemName = name;
        price = itemPrice;
        category = itemCategory;
    }

    string getItemName() const {
        return itemName;
    }

    double getPrice() const {
        return price;
    }

    string getCategory() const {
        return category;
    }
};

class Order {
private:
    vector<MenuItem> itemsOrdered;

public:
    void addItem(MenuItem item, int quantity) {
        for (int i = 0; i < quantity; ++i) {
            itemsOrdered.push_back(item);
        }
    }

    double calculateTotal() const {
        double total = 0.0;
        for (const auto &item : itemsOrdered) {
            total += item.getPrice();
        }
        return total;
    }
};

class Customer {
private:
    string name;

public:
    Customer(string customerName) : name(customerName) {}

    Order createOrder() {
        return Order();
    }
};

class BillingSystem {
private:
    vector<Order> orders;

public:
    void takeOrder(Customer customer, Order order) {
        orders.push_back(order);
    }

    void generateBill() {
        double total = 0.0;
        for (const auto &order : orders) {
            total += order.calculateTotal();
        }
        cout << "Total bill amount: $" << total << endl;
    }
};

int main() {
    vector<MenuItem> menu = {
        {"Burger", 5.99, "Main Course"},
        {"Salad", 3.49, "Starter"},
        {"Pizza", 8.99, "Main Course"},
        {"Ice Cream", 2.99, "Dessert"},
        {"Pasta", 6.49, "Main Course"}
    };

    BillingSystem restaurantBillingSystem;
    cout << "Welcome to the Restaurant!" << endl;

    string customerName; // Variable to store customer name
    cout << "Please enter your name: ";
    cin.ignore(); // Ignore newline character in buffer
    getline(cin, customerName); // Input customer name

    while (true) {
        // Display menu items with numbers and prices
        cout << "Menu:" << endl;
        for (int i = 0; i < menu.size(); ++i) {
            cout << i + 1 << ". " << menu[i].getItemName() << " - $" << menu[i].getPrice() << endl;
        }

        int choice, quantity;
        cout << "Enter the number of the dish you want to order (0 to finish): ";
        cin >> choice;

        if (choice < 1 || choice > menu.size()) {
            if (choice == 0) {
                break; // Exit loop if user enters 0
            } else {
                cout << "Invalid choice. Please select a number from the menu." << endl;
                continue;
            }
        }

        cout << "Enter the quantity: ";
        cin >> quantity;

        Customer customer(customerName); // Use the entered name for customer
        Order order = customer.createOrder();
        order.addItem(menu[choice - 1], quantity);
        restaurantBillingSystem.takeOrder(customer, order);

        char moreItems;
        cout << "Anything more you want to buy? (y/n): ";
        cin >> moreItems;

        if (moreItems == 'n' || moreItems == 'N') {
            break; // Exit loop if user doesn't want to buy more items
        }
    }

    // Generate bill
    restaurantBillingSystem.generateBill();
    cout << "Thank you for visiting!" << endl;

    return 0;
}
