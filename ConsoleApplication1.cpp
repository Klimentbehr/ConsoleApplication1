#include <iostream>
#include <vector>
#include <string>

struct SavingPool {
    std::string name;
    double yearlyAmount;
};

struct Bill {
    std::string name;
    double monthlyAmount;
};

void getInput(double& yearlyIncome, std::vector<SavingPool>& savingPools, std::vector<Bill>& bills) {
    std::cout << "Enter your yearly income after taxes: ";
    std::cin >> yearlyIncome;

    int numSavingPools;
    std::cout << "Enter number of saving pools: ";
    std::cin >> numSavingPools;
    for (int i = 0; i < numSavingPools; ++i) {
        SavingPool pool;
        std::cout << "Enter name of saving pool " << i + 1 << ": ";
        std::cin >> pool.name;
        std::cout << "Enter yearly amount for " << pool.name << ": ";
        std::cin >> pool.yearlyAmount;
        savingPools.push_back(pool);
    }

    int numBills;
    std::cout << "Enter number of monthly bills/needs: ";
    std::cin >> numBills;
    for (int i = 0; i < numBills; ++i) {
        Bill bill;
        std::cout << "Enter name of bill/need " << i + 1 << ": ";
        std::cin >> bill.name;
        std::cout << "Enter monthly amount for " << bill.name << ": ";
        std::cin >> bill.monthlyAmount;
        bills.push_back(bill);
    }
}

void suggestBudget(double yearlyIncome, std::vector<SavingPool>& savingPools, std::vector<Bill>& bills) {
    double totalYearlySavings = 0, totalMonthlyBills = 0;

    for (const auto& pool : savingPools) {
        totalYearlySavings += pool.yearlyAmount;
    }

    for (const auto& bill : bills) {
        totalMonthlyBills += bill.monthlyAmount;
    }

    double totalYearlyBills = totalMonthlyBills * 12;
    double totalYearlyExpenses = totalYearlySavings + totalYearlyBills;
    double leftoverIncome = yearlyIncome - totalYearlyExpenses;

    if (totalYearlyExpenses > yearlyIncome) {
        std::cout << "Warning: Your total yearly expenses exceed your yearly income.\n";
        double excess = totalYearlyExpenses - yearlyIncome;
        std::cout << "You need to reduce your expenses by $" << excess << " per year.\n";
    }
    else {
        std::cout << "Your budget is balanced.\n";
    }

    std::cout << "Yearly Income: $" << yearlyIncome << "\n";
    std::cout << "Yearly Savings:\n";
    for (const auto& pool : savingPools) {
        std::cout << "  " << pool.name << ": $" << pool.yearlyAmount << "\n";
    }

    std::cout << "Monthly Bills/Needs:\n";
    for (const auto& bill : bills) {
        std::cout << "  " << bill.name << ": $" << bill.monthlyAmount << "\n";
    }

    std::cout << "Total Monthly Bills: $" << totalMonthlyBills << "\n";
    std::cout << "Total Yearly Bills: $" << totalYearlyBills << "\n";
    std::cout << "Total Yearly Savings: $" << totalYearlySavings << "\n";
    std::cout << "Total Yearly Expenses: $" << totalYearlyExpenses << "\n";
    std::cout << "Leftover Income: $" << leftoverIncome << "\n";

    if (leftoverIncome > 0) {
        std::cout << "You could improve your savings by allocating more funds to your saving pools.\n";
    }
}

int main() {
    double yearlyIncome;
    std::vector<SavingPool> savingPools;
    std::vector<Bill> bills;

    getInput(yearlyIncome, savingPools, bills);
    suggestBudget(yearlyIncome, savingPools, bills);

    return 0;
}
