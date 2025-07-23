// Student.h
#pragma once
#include <string>
#include <vector>
#include <memory>

class Student {
private:
    std::string id;
    std::string name;
    int year;

public:
    Student(const std::string& id, const std::string& name, int year);

    std::string getId() const;
    std::string getName() const;
    int getYear() const;

    void setName(const std::string& name);
    void setYear(int year);

    void display() const;
    void input();

    static std::vector<std::shared_ptr<Student>> loadFromFile(const std::string& filename);
    static void saveToFile(const std::string& filename, const std::vector<std::shared_ptr<Student>>& students);

    static void displayAll(const std::vector<std::shared_ptr<Student>>& students);
    static void searchById(const std::vector<std::shared_ptr<Student>>& students);
    static void searchByName(const std::vector<std::shared_ptr<Student>>& students);
    static void sortByName(std::vector<std::shared_ptr<Student>>& students);
    static void sortById(std::vector<std::shared_ptr<Student>>& students);
};