#include <iostream>
#include <string>
#include "Student.hpp"
#include "Course.hpp"
#include "LinkedList.hpp"

using namespace std;

int main() {
    LinkedList<Student> studentList;
    int choice;

    do {
        cout << endl;
        cout << "1. Insert Student" << endl;
        cout << "2. Delete Student" << endl;
        cout << "3. Search Student" << endl;
        cout << "4. Display All" << endl;
        cout << "5. Count Students" << endl;
        cout << "6. Add a course" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1: {
                cout << endl;
                int id;
                string name;
                double gpa;

                cout << "Enter ID: ";
                cin >> id;
                cin.ignore();
                cout << "Enter Name: ";
                getline(cin, name);
                cout << "Enter GPA: ";
                cin >> gpa;
                cin.ignore();

                Student newStudent(id, name, gpa);
                studentList.append(newStudent);
                break;
            }

            case 2: {
                cout << endl;
                int id;
                cout << "Enter ID to delete: ";
                cin >> id;
                cin.ignore();
                try {
                    studentList.remove(id);
                    cout << "Deleted student with ID " << id << endl;
                } catch (string &e) {
                    cout << e << endl;
                }
                break;
            }

            case 3: {
                cout << endl;
                int id;
                cout << "Enter ID to search: ";
                cin >> id;
                cin.ignore();
                try {
                    studentList.search(id);
                } catch (string &e) {
                    cout << e << endl;
                }
                break;
            }

            case 4: {
                cout << endl;
                if (studentList.getLength() == 0) {
                    cout << "No students to display" << endl;
                } else {
                    for (int i = 0; i < studentList.getLength(); i++) {
                        studentList.getElement(i).displayStudent();
                    }
                }
                break;
            }

            case 5: {
                cout << endl;
                cout << "Total Students: " << studentList.getLength() << endl;
                break;
            }

            case 6: {
                cout << endl;
                int id;
                string cname;
                int loc;

                cout << "Enter Student ID: ";
                cin >> id;
                cin.ignore();
                cout << "Enter Course Name: ";
                getline(cin, cname);
                cout << "Enter Course Location: ";
                cin >> loc;
                cin.ignore();

                Course newCourse(cname, loc);
                try {
                    // Use any Student object to call this function
                    Student temp(0, "", 0);
                    temp.addCourseToStudent(id, newCourse, studentList);
                } catch (string &e) {
                    cout << e << endl;
                }
                break;
            }

            case 7: {
                cout << endl;
                cout << "Exiting..." << endl;
                break;
            }

            default:
                cout << endl;
                cout << "Invalid input, please try again" << endl;
        }

    } while (choice != 7);

    return 0;
}


