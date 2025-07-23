#include "../include/Course.h"
#include <iostream>
#include <fstream>
#include <algorithm>

Course::Course(const std::string& code, const std::string& name, int credits)
    : code(code), name(name), credits(credits) {}

std::string Course::getCode() const { return code; }
std::string Course::getName() const { return name; }
int Course::getCredits() const { return credits; }

void Course::setName(const std::string& newName) { name = newName; }
void Course::setCredits(int newCredits) { credits = newCredits; }

void Course::display() const {
    std::cout << "Code: " << code << " | Name: " << name << " | Credits: " << credits << '\n';
}

void Course::input() {
    std::cout << "Enter course code: ";
    std::cin>>code;
    std::cout << "Enter course name: ";
    std::cin.ignore();
    std::getline(std::cin, name);
    std::cout << "Enter course credits: ";
    std::cin >> credits;
    std::cin.ignore();
}

std::vector<std::shared_ptr<Course>> Course::loadFromFile(const std::string& filename) {
    std::vector<std::shared_ptr<Course>> courses;
    std::ifstream file(filename);
    if (!file.is_open()) return courses;

    std::string code, name;
    int credits;
    while (std::getline(file, code) && std::getline(file, name) && file >> credits) {
        file.ignore();
        courses.push_back(std::make_shared<Course>(code, name, credits));
    }
    file.close();
    return courses;
}

void Course::saveToFile(const std::string& filename, const std::vector<std::shared_ptr<Course>>& courses) {
    std::ofstream file(filename);
    for (const auto& c : courses) {
        file << c->getCode() << '\n' << c->getName() << '\n' << c->getCredits() << '\n';
    }
    file.close();
}

void Course::displayAll(const std::vector<std::shared_ptr<Course>>& courses) {
    for (const auto& c : courses) {
        c->display();
    }
}

void Course::searchByCode(const std::vector<std::shared_ptr<Course>>& courses) {
    std::string keyword;
    std::cout << "Enter course code to search: ";
    std::cin>>keyword;
    int flag=0;
    for (const auto& c : courses) {
        if (c->getCode() == keyword) {
            c->display();
            flag=1;
        }
    }
    if (flag==0) {
        std::cout << "Course not found.\n";
    }
}

void Course::searchByName(const std::vector<std::shared_ptr<Course>>& courses) {
    std::string target;
    std::cout << "Enter course name to search: ";
    std::cin.ignore();
    std::getline(std::cin, target);

    bool found = false;
    for (const auto& c : courses) {
        if (c->getName().find(target) != std::string::npos) {
            c->display();
            found = true;
        }
    }

    if (!found) {
        std::cout << "No matching course found.\n";
    }
}


void Course::sortByName(std::vector<std::shared_ptr<Course>>& courses) {
    std::sort(courses.begin(), courses.end(),
              [](const std::shared_ptr<Course>& a, const std::shared_ptr<Course>& b) {
                  return a->getName() < b->getName();
              });
    std::cout << "Sorted by course name.\n";
}

void Course::sortByCode(std::vector<std::shared_ptr<Course>>& courses) {
    std::sort(courses.begin(), courses.end(),
              [](const std::shared_ptr<Course>& a, const std::shared_ptr<Course>& b) {
                  return a->getCode() < b->getCode();
              });
    std::cout << "Sorted by course code.\n";
}
