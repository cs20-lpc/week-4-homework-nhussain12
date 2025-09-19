// TODO:  Course class methods implementation here.
#include "Course.hpp"

// Constructor Implementation
Course::Course(string courseName, int courseLocation) : courseName(courseName), courseLocation(courseLocation) {}

// Destructor Implementation
Course::~Course() {}

// Setter Methods Implementation
void Course::setCourseName(string name) {
    courseName = name;
}

void Course::setCourseLoc(int num) {
    courseLocation = num;
}

// Getter Methods Implementation 
string Course::getCourseName() const {
    return courseName;
}

int Course::getCourseLoc() const {
    return courseLocation;
}

// Display Method Implementation
void Course::display() const {
    cout << courseName << " " << courseLocation << endl;
}