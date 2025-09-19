#include "Student.hpp"
#include "Course.hpp"
#include "LinkedList.hpp"

// Constructor Implementation
Student::Student(int studentId, string studentName, double gpa) : studentId(studentId), studentName(studentName), gpa(gpa) {}
Student::~Student() {}

// Setter Methods
void Student::setStudentId(int id) { 
    studentId = id; 
}

void Student::setStudentName(string name) { 
    studentName = name; 
}

void Student::setGpa(double gpa) { 
    this->gpa = gpa; 
}

// Getter Methods
int Student::getStudentId() const { 
    return studentId; 
}

string Student::getStudentName() const { 
    return studentName; 
}

double Student::getGpa() const { 
    return gpa; 
}

LinkedList<Course>& Student::getEnrolledCourses() {
    return enrolledCourses;
}

// Additional Methods
void Student::addCourse(const Course& newCourse) {
    enrolledCourses.append(newCourse);
}

// Display a single student and their courses
void Student::displayStudent() {
    cout << studentId << " " << studentName << " " << gpa;
    if (enrolledCourses.getLength() == 0) {
        cout << " None" << endl;
    } else {
        cout << endl; 
        cout << "Courses: ";
        enrolledCourses.displayAll(); 
    }
}

// Add a course to a student in a LinkedList<Student>
void Student::addCourseToStudent(int id, const Course& newCourse, LinkedList<Student>& list) {
    for (int i = 0; i < list.getLength(); i++) {
        Student& s = list.getElement(i);
        if (s.getStudentId() == id) {
            s.addCourse(newCourse);
            return;
        }
    }
    throw string("addCoursetoStudent: error, student not found");
}


