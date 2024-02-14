using namespace std;
struct Project{
    string project_name;
    string description[3];
    int year;
};
void acceptProject(Project& project){
    char* name = new char[100];
    cin.clear();
    cout << " Enter project description:\n";
    cin.getline(name, 100);
    for(int i = 0; i < 3; i++){
        cout << ' ';
        cin.getline(name, 100);
        project.description[i] = name;
    }
    cout << " Enter project name: ";
    //cin.getline(name, 30);
    cin.getline(name, 30);
    project.project_name = name;
    cout << " Enter project year: ";
    cin >> project.year;
}
Project acceptProject(){
    Project project;
    cout << " Enter project name: ";
    char* name = new char[100];
    //cin.getline(name, 30);
    cin.getline(name, 30);
    project.project_name = name;
    cout << " Enter project description:\n ";
    for(int i = 0; i < 3; i++){
        cout << ' ';
        cin.getline(name, 100);
        project.description[i] = name;
    }
    cout << " Enter project year: ";
    cin >> project.year;
    return project;
}
void displayProject(Project project, int main_space = -1){
    main_space = (main_space < 0 ? 100 : main_space);
    sidebox(main_space, "Project info:");
    //printchar(main_space - 17, '-');
    cout << "\n ";
    printchar(main_space, '-');
    cout << endl;
    sidebox(main_space, "Project name: " + project.project_name);
    cout << "\n ";
    printchar(main_space, '-');
    cout << endl;
    for(int i = 0; i < 3; i++){
        sidebox(main_space, project.description[i]);
        cout << endl;
    }
    cout << ' ';
    printchar(main_space, '-');
    cout << endl;
    sidebox(main_space, "Year: " + to_str(project.year));
    cout << "\n ";
    printchar(main_space, '-');
}