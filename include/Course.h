// Course.h
#pragma once
#include <string>
#include <vector>
#include <memory>

class Course {
private:
    std::string code;
    std::string name;
    int credits;

public:
    Course(const std::string& code, const std::string& name, int credits);

    std::string getCode() const;
    std::string getName() const;
    int getCredits() const;

    void setName(const std::string& name);
    void setCredits(int credits);

    void display() const;
    void input();

    static std::vector<std::shared_ptr<Course>> loadFromFile(const std::string& filename);
    static void saveToFile(const std::string& filename, const std::vector<std::shared_ptr<Course>>& courses);

    static void displayAll(const std::vector<std::shared_ptr<Course>>& courses);
    static void searchByCode(const std::vector<std::shared_ptr<Course>>& courses);
    static void sortByName(std::vector<std::shared_ptr<Course>>& courses);
    static void sortByCode(std::vector<std::shared_ptr<Course>>& courses);
    static void searchByName(const std::vector<std::shared_ptr<Course>>& courses);
};
