using namespace std;
struct Student{
    string firstname;
    string lastname;
    string ID;
    int grade_level;
};
void acceptStudent(Student& student){
    cout << " Enter student's name: ";
    cin >> student.firstname >> student.lastname;
    cout << " Enter ID: ";
    cin >> student.ID;
    cout << " Enter grade level: ";
    cin >> student.grade_level;
}
Student acceptStudent(){
    Student student;
    cout << " Enter student's name: ";
    cin >> student.firstname >> student.lastname;
    cout << " Enter ID: ";
    cin >> student.ID;
    cout << " Enter grade level: ";
    cin >> student.grade_level;
    return student;
}
Student* acceptStudents(int& n){
    cout << " Enter number of students: ";
    cin >> n;
    Student* students = new Student[n];
    cout << " Enter " << n << " Students' details: \n";
    for(int i = 0; i < n; i++){
        cout << " Student " << i + 1 << endl;
        students[i] = acceptStudent();
    }
    return students;
}
void displayStudents(Student* students, int size, int maxsize = 0, int minsize = 0){
    maxsize = (maxsize > 12 ? maxsize : 12);
    string* fullnames = new string[size];
    for(int i = 0; i < size; i++)fullnames[i] = students[i].firstname + ' ' + students[i].lastname;
    int length = largest_length(fullnames, size);
    minsize = (minsize > length ? minsize : length);
    int totalsize = 3 + minsize + 3 + 11 + 3 + 11 + 3;
    lateralsidebox(minsize + 1, "Name");
    lateralsidebox(12, "ID", 0);
    int indenter = (maxsize > 12 ? maxsize + 14 - totalsize : maxsize);
    lateralsidebox(indenter, "grade level", 0);
    cout << "\n ";
    printchar((maxsize > 12? maxsize: totalsize) , '-');
    cout << endl;
    for(int i = 0; i < size; i++){
        lateralsidebox(minsize+1, students[i].firstname + ' ' + students[i].lastname);
        lateralsidebox(12, students[i].ID, 0);
        lateralsidebox(indenter, to_str(students[i].grade_level), 0);
        if(i != size-1)cout << endl;
    }
}
void displayStudent(Student student, int maxsize = 0, int minsize = 0){
    maxsize = (maxsize > 12 ? maxsize : 12);
    int length = student.firstname.length() + student.lastname.length() + 1;
    minsize = (minsize > length ? minsize : length);
    int totalsize = 3 + minsize + 3 + 11 + 3 + 12;
    lateralsidebox(minsize + 1, "Name");
    lateralsidebox(12, "ID", 0);
    int indenter = (maxsize > 12 ? maxsize + 12 - totalsize : maxsize);
    lateralsidebox(indenter, "grade level", 0);
    cout << "\n ";
    printchar((maxsize > 12? maxsize: totalsize) , '-');
    cout << endl;
    lateralsidebox(minsize+1, student.firstname + ' ' + student.lastname);
    lateralsidebox(12, student.ID, 0);
    lateralsidebox(indenter, to_str(student.grade_level), 0);
}