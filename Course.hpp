#ifndef COURSE_HPP
#define COURSE_HPP

// TODO:  Course class definitins go here.
#include <iostream>
#include <string>

using namespace std;

class Course {
private:
    string courseName;
    int courseLocation;

public:
    // Constructors
    Course(string courseName, int courseLocation);
    ~Course();

    // Setter Methods
    void setCourseName(string name);
    void setCourseLoc(int num);

    // Getter Methods
    string getCourseName() const;
    int getCourseLoc() const;

    // Display Method
    void display() const;

};

#endif