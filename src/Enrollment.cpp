#include "../include/Enrollment.h"
#include "../include/Student.h"
#include "../include/Course.h"

#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>

Enrollment::Enrollment(const std::string& studentId, const std::string& courseCode, float grade)
    : studentId(studentId), courseCode(courseCode), grade(grade) {}

std::string Enrollment::getStudentId() const { return studentId; }
std::string Enrollment::getCourseCode() const { return courseCode; }
float Enrollment::getGrade() const { return grade; }
void Enrollment::setGrade(float g) { grade = g; }

void Enrollment::display() const {
    std::cout << "Student ID: " << studentId << " | Course: " << courseCode
              << " | Grade: " << std::fixed << std::setprecision(2) << grade << '\n';
}

void Enrollment::input() {
    std::cout << "Enter student ID: ";
    std::cin.ignore();
    std::getline(std::cin, studentId);
    std::cout << "Enter course code: ";
    std::cin.ignore();
    std::getline(std::cin, courseCode);
    std::cout << "Enter grade: ";
    std::cin >> grade;
    std::cin.ignore();
}

std::vector<std::shared_ptr<Enrollment>> Enrollment::loadFromFile(const std::string& filename) {
    std::vector<std::shared_ptr<Enrollment>> list;
    std::ifstream file(filename);
    if (!file.is_open()) return list;

    std::string sid, cid;
    float grade;
    while (std::getline(file, sid) && std::getline(file, cid) && file >> grade) {
        file.ignore();
        list.push_back(std::make_shared<Enrollment>(sid, cid, grade));
    }
    file.close();
    return list;
}

void Enrollment::saveToFile(const std::string& filename, const std::vector<std::shared_ptr<Enrollment>>& enrollments) {
    std::ofstream file(filename);
    for (const auto& e : enrollments) {
        file << e->getStudentId() << '\n'
             << e->getCourseCode() << '\n'
             << e->getGrade() << '\n';
    }
    file.close();
}

void Enrollment::displayAll(const std::vector<std::shared_ptr<Enrollment>>& enrollments) {
    for (const auto& e : enrollments) {
        e->display();
    }
}

std::vector<std::shared_ptr<Enrollment>> Enrollment::getByStudentId(const std::vector<std::shared_ptr<Enrollment>>& enrollments, const std::string& studentId) {
    std::vector<std::shared_ptr<Enrollment>> result;
    for (const auto& e : enrollments) {
        if (e->getStudentId() == studentId)
            result.push_back(e);
    }
    return result;
}

float Enrollment::calculateGPA(const std::vector<std::shared_ptr<Enrollment>>& enrollments) {
    if (enrollments.empty()) return 0;

    float total = 0;
    for (const auto& e : enrollments) {
        total += e->getGrade();
    }
    return total / enrollments.size();
}

// ---------- Extra Methods ----------

void Enrollment::addEnrollment(std::vector<std::shared_ptr<Enrollment>>& enrollments,
                               const std::vector<std::shared_ptr<Student>>& students,
                               const std::vector<std::shared_ptr<Course>>& courses) {
    std::string sid, cid;
    std::cout << "Enter student ID: ";
    std::cin>>sid;
    std::cout << "Enter course code: ";
    std::cin>>cid;

    // Check student and course existence
    auto studentIt = std::find_if(students.begin(), students.end(), [&](const auto& s) {
        return s->getId() == sid;
    });
    auto courseIt = std::find_if(courses.begin(), courses.end(), [&](const auto& c) {
        return c->getCode() == cid;
    });

    if (studentIt == students.end()) {
        std::cout << "Student ID not found.\n";
        return;
    }
    if (courseIt == courses.end()) {
        std::cout << "Course code not found.\n";
        return;
    }

    enrollments.push_back(std::make_shared<Enrollment>(sid, cid, 0.0));
    std::cout << "Enrollment added with grade = 0.0\n";
}

void Enrollment::inputGPA(std::vector<std::shared_ptr<Enrollment>>& enrollments) {
    std::string sid, cid;
    std::cout << "Enter student ID: ";
    std::cin>>sid;
    std::cout << "Enter course code: ";
    std::cin>>cid;

    for (auto& e : enrollments) {
        if (e->getStudentId() == sid && e->getCourseCode() == cid) {
            float g;
            std::cout << "Enter new grade: ";
            std::cin >> g;
            std::cin.ignore();
            e->setGrade(g);
            std::cout << "Grade updated.\n";
            return;
        }
    }
    std::cout << "Enrollment not found.\n";
}

void Enrollment::calculateGPAByStudent(const std::vector<std::shared_ptr<Enrollment>>& enrollments,
                                       const std::vector<std::shared_ptr<Student>>& students,
                                       const std::vector<std::shared_ptr<Course>>& courses) {
    std::string sid;
    std::cout << "Enter student ID: ";
    std::cin>>sid;

    auto sub = getByStudentId(enrollments, sid);
    if (sub.empty()) {
        std::cout << "No enrollments found for this student.\n";
        return;
    }

    float gpa = calculateGPA(sub);
    std::cout << "GPA for student " << sid << ": " << std::fixed << std::setprecision(2) << gpa << '\n';
}

void Enrollment::calculateGPAAll(const std::vector<std::shared_ptr<Enrollment>>& enrollments,
                                 const std::vector<std::shared_ptr<Student>>& students,
                                 const std::vector<std::shared_ptr<Course>>& courses) {
    for (const auto& s : students) {
        auto sid = s->getId();
        auto sub = getByStudentId(enrollments, sid);
        float gpa = calculateGPA(sub);
        std::cout << "Student ID: " << sid << " | GPA: " << std::fixed << std::setprecision(2) << gpa << '\n';
    }
}
