// SystemManager.h
#pragma once
#include "Student.h"
#include "Course.h"
#include "Enrollment.h"

class SystemManager {
private:
    std::vector<std::shared_ptr<Student>> students;
    std::vector<std::shared_ptr<Course>> courses;
    std::vector<std::shared_ptr<Enrollment>> enrollments;

public:
    void loadAll();
    void saveAll();

    void studentMenu();
    void courseMenu();
    void enrollmentMenu();

    void mainMenu();
};
