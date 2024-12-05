#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <string>
#include <memory>
#include <numeric> // For aggregate functions

using namespace std;

class Student {
public:
    int Rno;
    string Name;
    int Age;
    int Marks;

    static int Generator;

    Student(const string& name, int age, int marks) {
        Rno = ++Generator;
        Name = name;
        Age = age;
        Marks = marks;
    }

    string toCSV() const {
        return to_string(Rno) + "," + Name + "," + to_string(Age) + "," + to_string(Marks);
    }

    static Student fromCSV(const string& csv) {
        stringstream ss(csv);
        string token;
        vector<string> tokens;

        while (getline(ss, token, ',')) {
            tokens.push_back(token);
        }

        Student student(tokens[1], stoi(tokens[2]), stoi(tokens[3]));
        student.Rno = stoi(tokens[0]);
        Generator = max(Generator, student.Rno);
        return student;
    }

    void Display() const {
        cout << Rno << " " << Name << " " << Age << " " << Marks << endl;
    }

    bool operator==(const Student& other) const {
        return Rno == other.Rno;
    }
};

int Student::Generator = 0;

class DBMS {
private:
    vector<Student> students;
    const string FILE_PATH = "students.txt";

    void LoadFromFile() {
        ifstream file(FILE_PATH);
        string line;
        while (getline(file, line)) {
            if (!line.empty())
                students.push_back(Student::fromCSV(line));
        }
    }

    void SaveToFile() const {
        ofstream file(FILE_PATH);
        for (const auto& student : students) {
            file << student.toCSV() << endl;
        }
    }

public:
    DBMS() {
        LoadFromFile();
    }

    void StartDBMS() {
        cout << "DBMS started successfully..." << endl;
        cout << "Table Schema created successfully..." << endl;

        string query;
        while (true) {
            cout << "DBMS : ";
            getline(cin, query);

            if (query == "exit") {
                SaveToFile();
                cout << "Thank you for using DBMS..." << endl;
                break;
            }

            istringstream iss(query);
            vector<string> tokens{istream_iterator<string>{iss}, istream_iterator<string>{}};

            if (tokens.size() >= 4 && tokens[0] == "insert" && tokens[1] == "into" && tokens[2] == "student" && tokens[3] == "values") {
                string name = tokens[4];
                int age = stoi(tokens[5]);
                int marks = stoi(tokens[6]);
                InsertIntoTable(name, age, marks);
            } else if (tokens.size() == 4 && tokens[0] == "select" && tokens[1] == "*" && tokens[2] == "from" && tokens[3] == "student") {
                SelectFrom();
            } else if (tokens.size() == 6 && tokens[0] == "delete" && tokens[1] == "from" && tokens[2] == "student" && tokens[3] == "where") {
                int rno = stoi(tokens[5]);
                DeleteRecord(rno);
            } else if (tokens.size() == 8 && tokens[0] == "update" && tokens[1] == "student" && tokens[2] == "set") {
                int rno = stoi(tokens[5]);
                int newMarks = stoi(tokens[7]);
                UpdateRecord(rno, newMarks);
            } else if (tokens[0] == "aggregate") {
                AggregateFunctions();
            } else if (tokens[0] == "sort") {
                string criterion = tokens[2];
                SortRecords(criterion);
            } else {
                cout << "Invalid query." << endl;
            }
        }
    }

    void InsertIntoTable(const string& name, int age, int marks) {
        for (const auto& student : students) {
            if (student.Name == name && student.Age == age && student.Marks == marks) {
                cout << "Duplicate record found. Insertion aborted." << endl;
                return;
            }
        }

        students.emplace_back(name, age, marks);
        SaveToFile();
        cout << "Record inserted successfully." << endl;
    }

    void SelectFrom() const {
        cout << "Records from the student table are:" << endl;
        for (const auto& student : students) {
            student.Display();
        }
    }

    void DeleteRecord(int rno) {
        auto it = remove_if(students.begin(), students.end(), [rno](const Student& s) { return s.Rno == rno; });
        if (it != students.end()) {
            students.erase(it, students.end());
            SaveToFile();
            cout << "Record deleted successfully." << endl;
        } else {
            cout << "Record not found." << endl;
        }
    }

    void UpdateRecord(int rno, int newMarks) {
        for (auto& student : students) {
            if (student.Rno == rno) {
                student.Marks = newMarks;
                SaveToFile();
                cout << "Record updated successfully." << endl;
                return;
            }
        }
        cout << "Record not found." << endl;
    }

    void AggregateFunctions() const {
        if (students.empty()) {
            cout << "No records available for aggregation." << endl;
            return;
        }
        int maxMarks = max_element(students.begin(), students.end(), [](const Student& a, const Student& b) { return a.Marks < b.Marks; })->Marks;
        int minMarks = min_element(students.begin(), students.end(), [](const Student& a, const Student& b) { return a.Marks < b.Marks; })->Marks;
        double avgMarks = accumulate(students.begin(), students.end(), 0, [](int sum, const Student& s) { return sum + s.Marks; }) / (double)students.size();
        int sumMarks = accumulate(students.begin(), students.end(), 0, [](int sum, const Student& s) { return sum + s.Marks; });

        cout << "Maximum Marks: " << maxMarks << endl;
        cout << "Minimum Marks: " << minMarks << endl;
        cout << "Average Marks: " << avgMarks << endl;
        cout << "Total Marks: " << sumMarks << endl;
    }

    void SortRecords(const string& criterion) {
        if (criterion == "age") {
            sort(students.begin(), students.end(), [](const Student& a, const Student& b) { return a.Age < b.Age; });
        } else if (criterion == "marks") {
            sort(students.begin(), students.end(), [](const Student& a, const Student& b) { return a.Marks < b.Marks; });
        } else {
            cout << "Invalid sorting criterion." << endl;
            return;
        }
        cout << "Records sorted by " << criterion << "." << endl;
        SaveToFile();
    }
};

int main() {
    DBMS dbms;
    dbms.StartDBMS();
    return 0;
}
