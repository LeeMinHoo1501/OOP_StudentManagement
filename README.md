# OOP_StudentManagement
A command-line based Student Management System implemented in C++ using Object-Oriented Programming (OOP). This project allows managing students, courses, enrollments, and GPA, with support for file persistence and user-friendly menu navigation.
✨ Features

👨‍🎓 Student Management
Add new students
Search students by ID or name
Sort students by ID or name
Display all students

📚 Course Management
Add new courses
Search courses by code or name
Sort courses by code or name
Display all courses

📝 Enrollment & GPA Management
Enroll students into courses
Input and edit grades
Calculate GPA per student or for all students
Display all enrollments

🧰 Requirements
C++17-compatible compiler (g++, clang++, MSVC, etc.)
Standard terminal/console
Create the data/ directory manually if it doesn't exist (optional)

⚙️ Build & Run Instructions

🧱 Build with Makefile
On Windows (with MinGW): mingw32-make
On Linux/macOS: make
🚀 Run the application
./bin/main.exe

💾 Notes
All data is automatically loaded from and saved to the data/ directory.
Smart pointers (std::shared_ptr) are used to manage memory efficiently.
Clean and modular OOP design for easy maintenance and extension.