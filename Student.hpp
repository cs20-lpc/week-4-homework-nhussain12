#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <iostream>
#include <string>
#include "Course.hpp"
#include "LinkedList.hpp"

using namespace std;

class Student {
private:
    int studentId;
    string studentName;
    double gpa;

    LinkedList<Course> enrolledCourses;

public:
    // Constructors
    Student(int studentId, string studentName, double gpa);
    ~Student();

    // Setter Methods
    void setStudentId(int id);
    void setStudentName(string name);
    void setGpa(double gpa);

    // Getter Methods
    int getStudentId() const;
    string getStudentName() const;
    double getGpa() const;
    LinkedList<Course>& getEnrolledCourses();

    // Additional Methods
    void addCourse(const Course&);
    void addCourseToStudent(int id, const Course& newCourse, LinkedList<Student>& list);
    void displayStudent();
};

#endif

