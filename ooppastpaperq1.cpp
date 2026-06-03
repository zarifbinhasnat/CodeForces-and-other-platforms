#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

class Teacher {
public:
    string name;
    string designation;
    int minContactHours;
    int currentLoad = 0;

    Teacher(const string& name, const string& designation, int minHours)
        : name(name), designation(designation), minContactHours(minHours) {}

    void display() const {
        cout << "Name: " << name << ", Designation: " << designation
                  << ", Minimum Contact Hours: " << minContactHours
                  << ", Current Load: " << currentLoad << "\n";
    }
};

class Course {
public:
    enum CourseCategory { Theory, Lab, ThesisOrProject };

    string title;
    string code;
    int effectiveContactHour;
    int numSections;
    CourseCategory category;
    int sectionsAssigned = 0;

    Course(const string& title, const string& code, int contactHour, int sections, CourseCategory category)
        : title(title), code(code), effectiveContactHour(contactHour), numSections(sections), category(category) {}

    void display() const {
        cout << "Course Title: " << title << ", Code: " << code
                  << ", Effective Contact Hour: " << effectiveContactHour
                  << ", Sections: " << numSections
                  << ", Sections Assigned: " << sectionsAssigned
                  << ", Category: " << (category == Theory ? "Theory" : (category == Lab ? "Lab" : "Thesis/Project"))
                  << "\n";
    }
};

class CourseAssignmentManager {
private:
    map<Teacher*, map<Course*, int>> teacherCourseMap;
    map<Course*, int> courseRemainingSections;

public:
    void assignCourse(Teacher* teacher, Course* course, int sections) {
        if (course->sectionsAssigned + sections > course->numSections) {
            cout << "Error: Cannot assign more sections than available.\n";
            return;
        }
        
        if (course->category == Course::Lab && sections > 2) {
            cout << "Error: A lab section can have at most two teachers.\n";
            return;
        }

        teacherCourseMap[teacher][course] += sections;
        course->sectionsAssigned += sections;
        teacher->currentLoad += sections * course->effectiveContactHour;

        cout << "Course " << course->code << " assigned to Teacher " << teacher->name << " for " << sections << " section(s).\n";
    }

    void detachCourse(Teacher* teacher, Course* course, int sections) {
        if (teacherCourseMap[teacher][course] < sections) {
            cout << "Error: Teacher is not assigned to that many sections of the course.\n";
            return;
        }

        teacherCourseMap[teacher][course] -= sections;
        course->sectionsAssigned -= sections;
        teacher->currentLoad -= sections * course->effectiveContactHour;

        if (teacherCourseMap[teacher][course] == 0) {
            teacherCourseMap[teacher].erase(course);
        }

        cout << "Course " << course->code << " detached from Teacher " << teacher->name << " for " << sections << " section(s).\n";
    }

    void displayUnderloadedTeachers() const {
        cout << "Teachers with load lower than their minimum contact hours:\n";
        for (const auto& entry : teacherCourseMap) {
            const Teacher* teacher = entry.first;
            if (teacher->currentLoad < teacher->minContactHours) {
                teacher->display();
            }
        }
    }

    void displayUnassignedCourses(const vector<Course*>& courses) const {
        cout << "Courses not fully assigned:\n";
        for (const Course* course : courses) {
            if (course->sectionsAssigned < course->numSections) {
                course->display();
                cout << "Sections yet to be assigned: "
                          << course->numSections - course->sectionsAssigned << "\n";
            }
        }
    }

    void displayCurrentAssignments() const {
        cout << "Current course assignments:\n";
        for (const auto& teacherEntry : teacherCourseMap) {
            const Teacher* teacher = teacherEntry.first;
            cout << "Teacher: " << teacher->name << "\n";
            for (const auto& courseEntry : teacherEntry.second) {
                const Course* course = courseEntry.first;
                int sections = courseEntry.second;
                cout << "  Course: " << course->code << " - Sections: " << sections << "\n";
            }
        }
    }
};

int main() {
    // Example usage
    Teacher t1("Alice", "Lecturer", 6);
    Teacher t2("Bob", "Assistant Professor", 8);

    Course c1("Data Structures", "CSE101", 3, 2, Course::Theory);
    Course c2("Physics Lab", "CSE102", 2, 3, Course::Lab);
    Course c3("Final Year Project", "CSE103", 5, 1, Course::ThesisOrProject);

    vector<Course*> courses = { &c1, &c2, &c3 };

    CourseAssignmentManager manager;

    manager.assignCourse(&t1, &c1, 1);
    manager.assignCourse(&t2, &c2, 2);
    manager.assignCourse(&t1, &c3, 1);

    manager.displayCurrentAssignments();
    manager.displayUnderloadedTeachers();
    manager.displayUnassignedCourses(courses);

    manager.detachCourse(&t1, &c1, 1);
    manager.displayCurrentAssignments();

    return 0;
}
