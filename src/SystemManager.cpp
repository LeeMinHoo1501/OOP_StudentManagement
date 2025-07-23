// SystemManager.cpp
#include "SystemManager.h"
#include <iostream>
using namespace std;

void SystemManager::loadAll() {
    students = Student::loadFromFile("data/students.txt");
    courses = Course::loadFromFile("data/courses.txt");
    enrollments = Enrollment::loadFromFile("data/enrollments.txt");
}

void SystemManager::saveAll() {
    Student::saveToFile("data/students.txt", students);
    Course::saveToFile("data/courses.txt", courses);
    Enrollment::saveToFile("data/enrollments.txt", enrollments);
}

void SystemManager::studentMenu() {
    int choice;
    do {
        cout << "\n--- Student Management ---\n";
        cout << "1. Display all students\n";
        cout << "2. Add new student\n";
        cout << "3. Search by ID\n";
        cout << "4. Search by name\n";
        cout << "5. Sort by name\n";
        cout << "6. Sort by ID\n";
        cout << "0. Back\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1: Student::displayAll(students); break;
            case 2: {
                auto s = make_shared<Student>("", "", 0);
                s->input();
                students.push_back(s);
                break;
            }
            case 3: Student::searchById(students); break;
            case 4: Student::searchByName(students); break;
            case 5: Student::sortByName(students); break;
            case 6: Student::sortById(students); break;
        }
    } while (choice != 0);
}

void SystemManager::courseMenu() {
    int choice;
    do {
        cout << "\n--- Course Management ---\n";
        cout << "1. Display all courses\n";
        cout << "2. Add new course\n";
        cout << "3. Search by code\n";
        cout << "4. Search by name\n";
        cout << "5. Sort by name\n";
        cout << "6. Sort by code\n";
        cout << "0. Back\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1: Course::displayAll(courses); break;
            case 2: {
                auto c = make_shared<Course>("", "", 0);
                c->input();
                courses.push_back(c);
                break;
            }
            case 3: Course::searchByCode(courses); break;
            case 4: Course::searchByName(courses); break;
            case 5: Course::sortByName(courses); break;
            case 6: Course::sortByCode(courses); break;
        }
    } while (choice != 0);
}

void SystemManager::enrollmentMenu() {
    int choice;
    do {
        cout << "\n--- Enrollment Management ---\n";
        cout << "1. Display enrollments\n";
        cout << "2. Add enrollment\n";
        cout << "3. Input GPA\n";
        cout << "4. Calculate GPA by student\n";
        cout << "5. Calculate GPA for all students\n";
        cout << "0. Back\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1: Enrollment::displayAll(enrollments); break;
            case 2: Enrollment::addEnrollment(enrollments, students, courses); break;
            case 3: Enrollment::inputGPA(enrollments); break;
            case 4: Enrollment::calculateGPAByStudent(enrollments, students, courses); break;
            case 5: Enrollment::calculateGPAAll(enrollments, students, courses); break;
        }
    } while (choice != 0);
}

void SystemManager::mainMenu() {
    loadAll();
    int choice;
    do {
        cout << "\n=== MAIN MENU ===\n";
        cout << "1. Student Management\n";
        cout << "2. Course Management\n";
        cout << "3. Enrollment Management\n";
        cout << "4. Save data\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1: studentMenu(); break;
            case 2: courseMenu(); break;
            case 3: enrollmentMenu(); break;
            case 4: saveAll(); break;
        }
    } while (choice != 0);
    saveAll();
    cout << "Exiting program.\n";
}
