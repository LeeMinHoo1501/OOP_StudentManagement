// main.cpp
#include <iostream>
using namespace std;

void showMainMenu() {
    cout << "\n==============================\n";
    cout << " STUDENT MANAGEMENT SYSTEM\n";
    cout << "==============================\n";
    cout << "1. Student Management\n";
    cout << "2. Course Management\n";
    cout << "3. Enrollment\n";
    cout << "4. GPA Calculation\n";
    cout << "5. Search / Sort\n";
    cout << "6. Save Data\n";
    cout << "0. Exit\n";
    cout << "------------------------------\n";
    cout << "Enter your choice: ";
}

int main() {
    int choice;
    bool running = true;

    while (running) {
        showMainMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "[Feature] Student Management\n";
                break;
            case 2:
                cout << "[Feature] Course Management\n";
                break;
            case 3:
                cout << "[Feature] Enrollment\n";
                break;
            case 4:
                cout << "[Feature] GPA Calculation\n";
                break;
            case 5:
                cout << "[Feature] Search / Sort\n";
                break;
            case 6:
                cout << "[Feature] Save Data\n";
                break;
            case 0:
                cout << "Exiting...\n";
                running = false;
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
