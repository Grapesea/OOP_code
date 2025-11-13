#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <iomanip>
#include <sstream>

using namespace std;

struct student
{
    string name;
    map<string, int> scores;
    double average() const
    {
        int sum = 0;
        for (const auto &pair : scores) // similar to `for pair in scores:` in Python
            sum += pair.second;
        return static_cast<double>(sum) / scores.size();
    }
};

vector<string> coursename(const vector<student> &students)
{
    vector<string> courses;
    for (const auto &student : students)
        for (const auto &pair : student.scores)
            if (find(courses.begin(), courses.end(), pair.first) == courses.end())
                courses.push_back(pair.first); //
    return courses;
}

double get_score_mean(const vector<student> &students, const string &course)
{
    int sum = 0;
    int count = 0;
    for (const auto &student : students)
    {
        auto it = student.scores.find(course);
        if (it != student.scores.end())
        {
            sum += it->second;
            count++;
        }
    }
    return (static_cast<double>(sum) / count * 1.0000);
}

int get_score_min(const vector<student> &students, const string &course)
{
    int minScore = 100;
    bool found = false;
    for (const auto &student : students)
    {
        auto it = student.scores.find(course);
        if (it != student.scores.end())
        {
            minScore = min(minScore, it->second);
            found = true;
        }
    }
    return found ? minScore : 0;
}

int get_score_max(const vector<student> &students, const string &course)
{
    int maxScore = 0;
    for (const auto &student : students)
    {
        auto it = student.scores.find(course);
        if (it != student.scores.end())
            maxScore = max(maxScore, it->second);
    }
    return maxScore;
}

int get_max_length(const vector<student> &students)
{
    int maxLen = 4; // minimum length for "name"
    for (const auto &student : students)
        maxLen = max(maxLen, static_cast<int>(student.name.length()));
    return maxLen;
}

vector<student> get_input(const string &filename)
{
    vector<student> students;
    ifstream infile(filename);

    if (!infile)
    {
        cerr << "Error: Cannot open file " << filename << endl;
        return students;
    }

    string line;
    vector<string> courseNames;

    if (getline(infile, line))
    {
        istringstream iss(line);
        string token;
        iss >> token >> token; // skip "no" and "name" columns, by receiving but not using them

        while (iss >> token)
            courseNames.push_back(token);
    }

    while (getline(infile, line))
    {
        if (line.empty())
            continue;

        istringstream iss(line);
        student student;
        int studentNo;

        iss >> studentNo >> student.name;

        string score;
        for (size_t i = 0; i < courseNames.size(); i++)
            if (iss >> score)
                if (score != "-")
                    student.scores[courseNames[i]] = stoi(score);
        students.push_back(student);
    }

    infile.close();
    return students;
}

void print_result(const vector<student> &students)
{
    vector<string> courses = coursename(students);
    int namewidth = get_max_length(students);
    cout << left << setw(8) << "no"
         << setw(namewidth + 1) << "name";

    for (const auto &course : courses)
        cout << setw(8) << course;
    cout << "average" << endl;

    for (size_t i = 0; i < students.size(); i++)
    {
        cout << left << setw(8) << (i + 1)
             << setw(namewidth + 1) << students[i].name;

        // Print scores for each course (or dash if not taken)
        for (const auto &course : courses)
        {
            auto it = students[i].scores.find(course);
            if (it != students[i].scores.end())
                cout << setw(8) << it->second;
            else
                cout << setw(8) << "-";
        }
        double avg = students[i].average();
        if (avg == static_cast<int>(avg))
            cout << fixed << static_cast<int>(avg) << endl;
        else
            cout << fixed << setprecision(5) << avg << endl;
    }

    cout << string(8, ' ') << left << setw(namewidth + 1) << "average";
    for (const auto &course : courses)
    {
        double avg = get_score_mean(students, course);
        if (avg == static_cast<int>(avg))
            cout << setw(8) << static_cast<int>(avg);
        else
            cout << fixed << setprecision(1) << setw(8) << avg;
    }
    cout << endl;

    cout << string(8, ' ') << left << setw(namewidth + 1) << "min";
    for (const auto &course : courses)
    {
        int minScore = get_score_min(students, course);
        cout << setw(8) << minScore;
    }
    cout << endl;
    // Max row
    cout << string(8, ' ') << left << setw(namewidth + 1) << "max";
    for (const auto &course : courses)
    {
        int maxScore = get_score_max(students, course);
        cout << setw(8) << maxScore;
    }
    cout << endl;
}

int main()
{
    string filename;
    cout << "filename input:";
    cin >> filename;
    while (!filename.empty())
    {
        vector<student> students = get_input(filename);
        print_result(students);
        cout << "filename input:";
        cin >> filename;
    }
    return 0;
}