// main.cpp
#include "SystemManager.h"
#include <iostream>

int main()
 {
    SystemManager manager;

    while (true) {
        std::cout << "\n===== MAIN MENU =====\n";
        std::cout << "1. Student Management\n";
        std::cout << "2. Course Management\n";
        std::cout << "3. Enrollment & GPA\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter your choice: ";

        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1:
                manager.studentMenu();
                break;
            case 2:
                manager.courseMenu();
                break;
            case 3:
                manager.enrollmentMenu();
                break;
            case 0:
                std::cout << "Exiting program...\n";
                return 0;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
