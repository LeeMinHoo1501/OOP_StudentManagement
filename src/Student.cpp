// Student.cpp
#include "Student.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iomanip>

Student::Student(const std::string& id, const std::string& name, int year)
    : id(id), name(name), year(year) {}

std::string Student::getId() const { return id; }
std::string Student::getName() const { return name; }
int Student::getYear() const { return year; }

void Student::setName(const std::string& newName) { name = newName; }
void Student::setYear(int newYear) { year = newYear; }

void Student::display() const {
    std::cout << std::left << std::setw(10) << id
              << std::setw(25) << name
              << "Year: " << year << "\n";
}

void Student::input() {
    std::cout << "Enter ID: ";
    std::cin>>id;
    std::cout << "Enter name: ";
    std::getline(std::cin, name);
    std::cout << "Enter year: ";
    std::cin >> year;
    std::cin.ignore(); // clear newline
}

void Student::displayAll(const std::vector<std::shared_ptr<Student>>& students) {
    for (const auto& s : students) s->display();
}

std::vector<std::shared_ptr<Student>> Student::loadFromFile(const std::string& filename) {
    std::vector<std::shared_ptr<Student>> result;
    std::ifstream fin(filename);
    if (!fin) return result;

    std::string line;
    while (std::getline(fin, line)) {
        std::stringstream ss(line);
        std::string id, name;
        int year;
        std::getline(ss, id, ',');
        std::getline(ss, name, ',');
        ss >> year;
        result.push_back(std::make_shared<Student>(id, name, year));
    }
    return result;
}

void Student::saveToFile(const std::string& filename, const std::vector<std::shared_ptr<Student>>& students) {
    std::ofstream fout(filename);
    for (const auto& s : students) {
        fout << s->getId() << "," << s->getName() << "," << s->getYear() << "\n";
    }
}

void Student::searchById(const std::vector<std::shared_ptr<Student>>& students) {
    std::string id;
    std::cout << "Enter student ID to search: ";
    std::cin >> id;
    bool found = false;
    for (const auto& s : students) {
        if (s->getId() == id) {
            s->display();
            found = true;
        }
    }
    if (!found) std::cout << "Student not found!\n";
}

void Student::searchByName(const std::vector<std::shared_ptr<Student>>& students) {
    std::string keyword;
    std::cout << "Enter name or keyword to search: ";
    std::cin.ignore();
    std::getline(std::cin, keyword);

    bool found = false;
    for (const auto& s : students) {
        if (s->getName().find(keyword) != std::string::npos) {
            s->display();
            found = true;
        }
    }
    if (!found) std::cout << "Student not found!\n";
}

void Student::sortByName(std::vector<std::shared_ptr<Student>>& students) {
    std::sort(students.begin(), students.end(), [](const auto& a, const auto& b) {
        return a->getName() < b->getName();
    });
    std::cout << "Sorted by name successfully!\n";
}

void Student::sortById(std::vector<std::shared_ptr<Student>>& students) {
    std::sort(students.begin(), students.end(), [](const auto& a, const auto& b) {
        return a->getId() < b->getId();
    });
    std::cout << "Sorted by ID successfully!\n";
}
