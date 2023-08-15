#include <iostream>
#include <cstdlib>

const int MAX_STUDENTS = 20;

class Student {
public:
    std::string name;
    std::string rollNo;
    std::string course;
    std::string studentClass;
    std::string contact;
};

class DataEntry {
public:
    void enterData(Student students[], int& totalStudents) {
        int ch = 0;
        std::cout << "How many students do you want to enter?" << std::endl;
        std::cin >> ch;

        if (totalStudents + ch > MAX_STUDENTS) {
            std::cout << "Not enough space to enter all students." << std::endl;
            return;
        }

        for (int i = totalStudents; i < totalStudents + ch; i++) {
            std::cout << "\nEnter the Data of student " << i + 1 << std::endl << std::endl;

            std::cout << "Enter name: ";
            std::cin >> students[i].name;

            std::cout << "Enter Roll no: ";
            std::cin >> students[i].rollNo;

            std::cout << "Enter course: ";
            std::cin >> students[i].course;

            std::cout << "Enter class: ";
            std::cin >> students[i].studentClass;

            std::cout << "Enter contact: ";
            std::cin >> students[i].contact;
        }

        totalStudents += ch;
    }
};

class DataDisplay {
public:
    void showData(Student students[], int totalStudents) {
        if (totalStudents == 0) {
            std::cout << "No data is entered" << std::endl;
        } else {
            for (int i = 0; i < totalStudents; i++) {
                std::cout << "\nData of Student " << i + 1 << std::endl << std::endl;
                std::cout << "Name: " << students[i].name << std::endl;
                std::cout << "Roll no: " << students[i].rollNo << std::endl;
                std::cout << "Course: " << students[i].course << std::endl;
                std::cout << "Class: " << students[i].studentClass << std::endl;
                std::cout << "Contact: " << students[i].contact << std::endl;
            }
        }
    }
};

class DataSearch {
public:
    void searchData(Student students[], int totalStudents) {
        if (totalStudents == 0) {
            std::cout << "No data is entered" << std::endl;
        } else {
            std::string rollNo;
            std::cout << "Enter the roll no of student" << std::endl;
            std::cin >> rollNo;

            bool found = false;
            for (int i = 0; i < totalStudents; i++) {
                if (students[i].rollNo == rollNo) {
                    std::cout << "\nData of Student " << i + 1 << std::endl << std::endl;
                    std::cout << "Name: " << students[i].name << std::endl;
                    std::cout << "Roll no: " << students[i].rollNo << std::endl;
                    std::cout << "Course: " << students[i].course << std::endl;
                    std::cout << "Class: " << students[i].studentClass << std::endl;
                    std::cout << "Contact: " << students[i].contact << std::endl;
                    found = true;
                    break;
                }
            }

            if (!found) {
                std::cout << "Student with Roll no " << rollNo << " not found." << std::endl;
            }
        }
    }
};

class DataUpdate {
public:
    void updateData(Student students[], int totalStudents) {
        if (totalStudents == 0) {
            std::cout << "No data is entered" << std::endl;
        } else {
            std::string rollNo;
            std::cout << "Enter the roll no of student you want to update" << std::endl;
            std::cin >> rollNo;

            bool found = false;
            for (int i = 0; i < totalStudents; i++) {
                if (students[i].rollNo == rollNo) {
                    std::cout << "\nPrevious data" << std::endl << std::endl;
                    std::cout << "Data of Student " << i + 1 << std::endl;
                    std::cout << "Name: " << students[i].name << std::endl;
                    std::cout << "Roll no: " << students[i].rollNo << std::endl;
                    std::cout << "Course: " << students[i].course << std::endl;
                    std::cout << "Class: " << students[i].studentClass << std::endl;
                    std::cout << "Contact: " << students[i].contact << std::endl;

                    std::cout << "\nEnter new data" << std::endl << std::endl;
                    std::cout << "Enter name: ";
                    std::cin >> students[i].name;

                    std::cout << "Enter Roll no: ";
                    std::cin >> students[i].rollNo;

                    std::cout << "Enter course: ";
                    std::cin >> students[i].course;

                    std::cout << "Enter class: ";
                    std::cin >> students[i].studentClass;

                    std::cout << "Enter contact: ";
                    std::cin >> students[i].contact;

                    std::cout << "Student data updated successfully." << std::endl;
                    found = true;
                    break;
                }
            }

            if (!found) {
                std::cout << "Student with Roll no " << rollNo << " not found." << std::endl;
            }
        }
    }
};

class DataDelete {
public:
    void deleteData(Student students[], int& totalStudents) {
        if (totalStudents == 0) {
            std::cout << "No data is entered" << std::endl;
        } else {
            int a;
            std::cout << "Press 1 to delete all records" << std::endl;
            std::cout << "Press 2 to delete a specific record" << std::endl;
            std::cin >> a;

            if (a == 1) {
                totalStudents = 0;
                std::cout << "All records have been deleted." << std::endl;
            } else if (a == 2) {
                std::string rollNo;
                std::cout << "Enter the roll no of the student you want to delete" << std::endl;
                std::cin >> rollNo;

                bool found = false;
                for (int i = 0; i < totalStudents; i++) {
                    if (students[i].rollNo == rollNo) {
                        for (int j = i; j < totalStudents - 1; j++) {
                            students[j] = students[j + 1];
                        }
                        totalStudents--;
                        std::cout << "Student record deleted successfully." << std::endl;
                        found = true;
                        break;
                    }
                }

                if (!found) {
                    std::cout << "Student with Roll no " << rollNo << " not found." << std::endl;
                }
            } else {
                std::cout << "Invalid input" << std::endl;
            }
        }
    }
};

int main() {
    Student students[MAX_STUDENTS];
    int totalStudents = 0;

    DataEntry dataEntry;
    DataDisplay dataDisplay;
    DataSearch dataSearch;
    DataUpdate dataUpdate;
    DataDelete dataDelete;

    int value;
    while (true) {
        std::cout << "\nPress 1 to enter data" << std::endl;
        std::cout << "Press 2 to show data" << std::endl;
        std::cout << "Press 3 to search data" << std::endl;
        std::cout << "Press 4 to update data" << std::endl;
        std::cout << "Press 5 to delete data" << std::endl;
        std::cout << "Press 6 to exit" << std::endl;
        std::cin >> value;

        switch (value) {
            case 1:
                dataEntry.enterData(students, totalStudents);
                break;
            case 2:
                dataDisplay.showData(students, totalStudents);
                break;
            case 3:
                dataSearch.searchData(students, totalStudents);
                break;
            case 4:
                dataUpdate.updateData(students, totalStudents);
                break;
            case 5:
                dataDelete.deleteData(students, totalStudents);
                break;
            case 6:
                exit(0);
                break;
            default:
                std::cout << "Invalid input" << std::endl;
                break;
        }
    }

    return 0;
}

