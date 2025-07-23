// Enrollment.h
#pragma once
#include <string>
#include <vector>
#include <memory>

class Student;
class Course;

class Enrollment {
private:
    std::string studentId;
    std::string courseCode;
    float grade;

public:
    Enrollment(const std::string& studentId, const std::string& courseCode, float grade);

    std::string getStudentId() const;
    std::string getCourseCode() const;
    float getGrade() const;
    void setGrade(float grade);

    void display() const;
    void input();

    static std::vector<std::shared_ptr<Enrollment>> loadFromFile(const std::string& filename);
    static void saveToFile(const std::string& filename, const std::vector<std::shared_ptr<Enrollment>>& enrollments);

    static void displayAll(const std::vector<std::shared_ptr<Enrollment>>& enrollments);
    static std::vector<std::shared_ptr<Enrollment>> getByStudentId(const std::vector<std::shared_ptr<Enrollment>>& enrollments, const std::string& studentId);
    static float calculateGPA(const std::vector<std::shared_ptr<Enrollment>>& enrollments);

    // New methods
    static void addEnrollment(std::vector<std::shared_ptr<Enrollment>>& enrollments,
                               const std::vector<std::shared_ptr<Student>>& students,
                               const std::vector<std::shared_ptr<Course>>& courses);

    static void inputGPA(std::vector<std::shared_ptr<Enrollment>>& enrollments);

    static void calculateGPAByStudent(const std::vector<std::shared_ptr<Enrollment>>& enrollments,
                                      const std::vector<std::shared_ptr<Student>>& students,
                                      const std::vector<std::shared_ptr<Course>>& courses);

    static void calculateGPAAll(const std::vector<std::shared_ptr<Enrollment>>& enrollments,
                                const std::vector<std::shared_ptr<Student>>& students,
                                const std::vector<std::shared_ptr<Course>>& courses);
};
