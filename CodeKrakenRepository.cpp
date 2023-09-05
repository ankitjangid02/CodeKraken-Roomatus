#include <iostream>
#include <vector>
#include <string>

struct Expense {
    std::string description;
    double amount;
};

std::vector<Expense> expenses;

void addExpense() {
    Expense expense;
    std::cout << "Enter expense description: ";
    std::cin.ignore();
    std::getline(std::cin, expense.description);
    std::cout << "Enter expense amount: ";
    std::cin >> expense.amount;
    expenses.push_back(expense);
    std::cout << "Expense added successfully.\n";
}

void listExpenses() {
    int sum=0;
    if (expenses.empty()) {
        std::cout << "No expenses to display.\n";
        return;
    }

    std::cout << "Expense List:\n";
    for (const auto& expense : expenses) {
        std::cout << "Description: " << expense.description << "\n";
        std::cout << "Amount: Rs." << expense.amount << "\n";
        sum=sum+expense.amount;
    }
    std::cout <<"\nTotal Expense = "<<sum<<"\n\n";
}

int main() {
    int choice;

    do {
        std::cout << "\nExpense Tracker Menu:\n";
        std::cout << "1. Add Expense\n";
        std::cout << "2. List Expenses\n";
        std::cout << "3. Quit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                addExpense();
                break;
            case 2:
                listExpenses();
                break;
            case 3:
                std::cout << "Exiting the program.\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 3);

    return 0;
}

