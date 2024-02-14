using namespace std;
struct Individual{
    Student student;
    Project project;
    string phonenumber;
};
void accept_individual(Individual& individual){
    cout << " Enter individual project details: \n";
    acceptStudent(individual.student);
    cout << " Enter phone number: ";
    cin >> individual.phonenumber;
    acceptProject(individual.project);
}
Individual accept_individual(){
    Individual individual;
    cout << " Enter individual project details: \n";
    acceptProject(individual.project);
    individual.student = acceptStudent();
    cout << " Enter phone number: ";
    cin >> individual.phonenumber;
    return individual;
}
bool add_individual(string filename, Individual individual){
    const string mainpath = "../Files/Individual/";
    string path = mainpath + filename;
    ofstream file(path);
    if(!file)return 0;
    file << " Students name: " << individual.student.firstname << ' ' << individual.student.lastname << endl;
    file << " ID_no: " << individual.student.ID << endl;
    file << " Phone number: " << individual.phonenumber << endl;
    file << " Grade level: " << individual.student.grade_level << endl;
    file << " Project name: " << individual.project.project_name << endl;
    file << " Project year: " << individual.project.year << endl;
    file << " Project description:" << endl; 
    for(int i = 0; i < 3; i++){
        file << ' ' << individual.project.description[i] << endl;
    }
    file.close();
    return 1;
}
void del_individual(string filename){
    const string mainpath = "../Files/Individual/";
    string path = mainpath + filename;
    remove(path.c_str());
}
bool read_individual(string filename, Individual& individual){
    const string mainpath = "../Files/Individual/";
    string path = mainpath + filename;
    ifstream ifs(path);
    if(!ifs)return 0; // check if file opened, if not display error message and quit using return;
    string buff;
    char name[100];
    while(ifs){
        ifs >> buff;
        if(buff == "Students"){
            ifs >> buff;
            ifs >> individual.student.firstname >> individual.student.lastname;
        }
        if(buff == "ID_no:"){
            ifs >> individual.student.ID;
        }
        if(buff == "Phone"){
            ifs >> buff;
            ifs >> individual.phonenumber;
        }
        if(buff == "Grade"){
            ifs >> buff;
            ifs >> individual.student.grade_level;
        }
        if(buff == "Project"){
            ifs >> buff;
            ifs.getline(name, 30);
            individual.project.project_name = name;
            ifs >> buff;
            ifs >> buff;
            ifs >> individual.project.year;
            ifs >> buff;
            ifs >> buff;
            ifs.getline(name, 100);
            for(int i = 0; i < 3; i++){
                ifs.getline(name, 100);
                individual.project.description[i] = name;
            }
        }
    }
    ifs.close();
    return 1;
}
bool update_individual(string filename){
    Individual individual;
    if(!read_individual(filename, individual))return 0;
    label:
    char choice;
    cout << " What do you want to change:\n";
    cout << " 1. Student details\n";
    cout << " 2. Project details\n";
    cout << " Choice: ";
    cin >> choice;
    switch (choice){
        case '1':{
            system("cls");
            individual.student = acceptStudent();
            cout << " Enter phone number: ";
            cin >> individual.phonenumber;
            break;
        }
        case '2':{
            system("cls");
            acceptProject(individual.project);
            break;
        }
        default:{
            system("cls");
            cout << " No changes made\n";
            break;
        }
    }
    if(!add_individual(filename, individual))return 0;
    return 1;
}
void display_individual(Individual individual, int maxsize = 100, int minsize = 0){
    int length = individual.student.firstname.length() + individual.student.lastname.length() + 1;
    minsize = (minsize < length ? length : minsize);
    int totalsize = 3 + minsize + 3 + 11 + 3 + 11 + 1;
    cout << ' ';
    printchar(maxsize, '-');
    cout << endl;
    sidebox(maxsize, "Individual info:");
    cout <<"\n ";
    printchar(maxsize, '-');
    cout << endl;
    displayStudent(individual.student, maxsize);
    cout <<"\n ";
    printchar(maxsize, '-');
    cout << endl;
    sidebox(maxsize, "Phone number: " + individual.phonenumber);
    cout << "\n ";
    printchar(maxsize, '-');
    cout << endl;
    displayProject(individual.project);
}