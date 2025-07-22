#include <iostream>
#include <ctime>
using namespace std;

// Days in each month (non-leap year for simplicity)
int daysInMonth[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

// Function to check leap year
bool isLeap(int year) {
    return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

int main() {
    int birthYear, birthMonth, birthDay;
    
    cout << "Enter your birth year (e.g., 2000): ";
    cin >> birthYear;
    cout << "Enter your birth month (1-12): ";
    cin >> birthMonth;
    cout << "Enter your birth day (1-31): ";
    cin >> birthDay;

    // Get current date
    time_t now = time(0);
    tm *ltm = localtime(&now);
    int currentYear = 1900 + ltm->tm_year;
    int currentMonth = 1 + ltm->tm_mon;
    int currentDay = ltm->tm_mday;

    // Adjust February if current year is leap
    daysInMonth[1] = isLeap(currentYear) ? 29 : 28;

    int ageYear = currentYear - birthYear;
    int ageMonth = currentMonth - birthMonth;
    int ageDay = currentDay - birthDay;

    // Borrow days from previous month if needed
    if (ageDay < 0) {
        ageMonth--;
        int prevMonth = (currentMonth == 1) ? 12 : currentMonth - 1;
        int prevYear = (currentMonth == 1) ? currentYear - 1 : currentYear;
        daysInMonth[1] = isLeap(prevYear) ? 29 : 28;
        ageDay += daysInMonth[prevMonth - 1];
    }

    // Borrow months from previous year if needed
    if (ageMonth < 0) {
        ageMonth += 12;
        ageYear--;
    }

    cout << "\nYour exact age is: " 
         << ageYear << " years, " 
         << ageMonth << " months, and " 
         << ageDay << " days.\n";

    return 0;
}
