struct Group{
    Student* members;
    int members_size, rep_index;
    Project project;
    string groupname;
    string phonenumber;
};
void accept_group(Group& group){
    cout << " Enter group project details: \n";
    acceptProject(group.project);
    cout << " Enter number of members: ";
    cin >> group.members_size;
    cout << " Enter " << group.members_size << " students' details:\n";
    for(int i = 0; i < group.members_size; i++){
        cout << " Student " << (i + 1) << endl;
        group.members[i] = acceptStudent();
    }
    cout << " Enter represtentative's index: ";
    cin >> group.rep_index;
    cout << " Enter representative's phone number: ";
    cin >> group.phonenumber;
    cout << " Enter group name: ";
    cin >> group.groupname;
}
Group accept_group(){
    Group group;
    cout << " Enter group project details: \n";
    acceptProject(group.project);
    cout << " Enter number of members: ";
    cin >> group.members_size;
    group.members = new Student[group.members_size];
    cout << " Enter " << group.members_size << " students' details:\n";
    for(int i = 0; i < group.members_size; i++){
        cout << " Student " << (i + 1) << endl;
        acceptStudent(group.members[i]);
    }
    cout << " Enter represtentative's index: ";
    cin >> group.rep_index;
    cout << " Enter representative's phone number: ";
    cin >> group.phonenumber;
    cout << " Enter group name: ";
    cin >> group.groupname;
    return group;
}
bool add_group(string filename, Group group){
    const string mainpath = "../files/Group/";
    string path = mainpath + filename;
    ofstream file(path);
    if(!file)return 0;
    file << " Group name: " << group.groupname << endl;
    file << " Number of members: " << group.members_size << endl;
    file << " rep_index: " << group.rep_index << endl;
    file << " Members info:\n";
    int count = 0;
    for(int i = 0; i < group.members_size; i++){
        if(i + 1 != group.rep_index){
            file << " Student " << (i + 1) << " :\n";
            file << " Name: " << group.members[i].firstname << ' ' << group.members[i].lastname << endl;
            file << " ID_no: " << group.members[i].ID << endl;
            file << " Grade level: " << group.members[i].grade_level << endl;
        }
    }
    file << " Representative info:\n";
    file << " Name: " << group.members[group.rep_index-1].firstname << ' ' << group.members[group.rep_index-1].lastname << endl;
    file << " ID_no: " << group.members[group.rep_index-1].ID << endl;
    file << " Grade level: " << group.members[group.rep_index-1].grade_level << endl;
    //
    file << " Phone number: " << group.phonenumber << endl;
    file << " Project info:\n";
    file << " Project name: " << group.project.project_name << endl;
    file << " Project year: " << group.project.year << endl;
    file << " Project description:" << endl;
    for(int i = 0; i < 3; i++)file << ' ' << group.project.description[i] << endl;
    file.close();
    return 1;
}
void del_group(string filename){
    const string mainpath = "../files/Group/";
    string path = mainpath + filename;
    remove(path.c_str());
}
bool read_group(string filename, Group& group){
    const string mainpath = "../files/Group/";
    string path = mainpath + filename;
    ifstream file(path);
    if(!file)return 0; // check if file opened, if not display error message and quit using return;
    string buff;
    while(file){
        file >> buff;
        if(buff == "Group"){
            file >> buff;
            file >> group.groupname;
        }
        if(buff == "Number"){
            file >> buff >> buff;
            file >> group.members_size;
        }
        if(buff == "rep_index:"){
            file >> group.rep_index;
        }
        if(buff == "Members"){
            file >> buff;
            group.members = new Student[group.members_size];
            while(buff != "Representative"){
                file >> buff;
                if(buff == "Student"){
                    int indexer;
                    file >> indexer;
                    if(file.fail())return 0;
                    file >> buff >> buff >> group.members[indexer-1].firstname >> group.members[indexer-1].lastname;
                    file >> buff;
                    file >> group.members[indexer-1].ID;
                    file >> buff >> buff;
                    file >> group.members[indexer-1].grade_level;
                }
            }
            file >> buff >> buff;
            file >> group.members[group.rep_index-1].firstname >> group.members[group.rep_index-1].lastname;
            file >> buff >> group.members[group.rep_index-1].ID;
            file >> buff >> buff;
            file >> group.members[group.rep_index-1].grade_level;
            file >> buff >> buff;
            file >> group.phonenumber;
            char name[100];
            file >> buff >> buff >> buff >> buff;
            file.getline(name, 30);
            group.project.project_name = name;
            file >> buff >> buff;
            file >> group.project.year;
            file.getline(name, 100);
            file.getline(name, 100);
            for(int i = 0; i < 3; i++){
                file.getline(name, 100);
                group.project.description[i] = name;
            }
            
            file.close();
            return 1;
        }
    }
}
bool update_group(string filename){
    Group group;
    if(!read_group(filename, group))return 0;
    label:
    char choice;
    cout << " What do you want to change:\n";
    cout << " 1. Members details\n";
    cout << " 2. Project details\n";
    cout << " 3. Single member details\n";
    cout << " Choice: ";
    cin >> choice;
    switch (choice){
        case '1':{
            system("cls");
            cout << " Enter number of members: ";
            cin >> group.members_size;
            cout << " Enter " << group.members_size << " students' details:\n";
            delete group.members;
            group.members = new Student[group.members_size];
            for(int i = 0; i < group.members_size; i++){
                cout << " Student " << (i + 1) << endl;
                group.members[i] = acceptStudent();
            }
            cout << " Enter represtentative's index: ";
            cin >> group.rep_index;
            cout << " Enter representative's phone number: ";
            cin >> group.phonenumber;
            break;
        }
        case '2':{
            system("cls");
            acceptProject(group.project);
            break;
        }
        case '3':{
            system("cls");
            label2:
            int index;
            cout << " Enter index number to edit: ";
            cin >> index;
            if(index + 1 <= 0 || index > group.members_size){
                cout << " Enter appropriate index!!!\a\n";
                goto label2;
            }
            group.members[index - 1] = acceptStudent();
            break;
        }
        default:{
            cout << " No changes made\n";
            break;
        }
    }
    if(!add_group(filename, group))return 0;
    return 1;
}
void display_group(Group group, int maxsize = 100, int minsize = 0){
    cout << ' ';
    printchar(maxsize, '-');
    cout << endl;
    sidebox(maxsize, "Group info:");
    cout << "\n ";
    printchar(maxsize, '-');
    cout << endl;
    sidebox(maxsize, "Number of members: " + to_str(group.members_size));
    cout << endl;
    sidebox(maxsize, "Group name: " + group.groupname);
    cout << "\n ";
    printchar(maxsize, '-');
    cout << endl;
    sidebox(maxsize, "Representative info: ");
    cout << "\n ";
    printchar(maxsize, '-');
    cout << endl;
    string *names = new string[group.members_size];
    for(int i = 0; i < group.members_size; i++){
        names[i] = group.members[i].firstname + ' ' + group.members[i].lastname;
    }
    int largest = largest_length(names, group.members_size);
    minsize = (minsize < largest ? largest : minsize);
    displayStudent(group.members[group.rep_index-1], maxsize, minsize);
    cout << "\n ";
    printchar(maxsize, '-');
    cout << endl;
    sidebox(maxsize, "Members info:");
    cout << "\n ";
    printchar(maxsize, '-');
    cout << endl;
    displayStudents(group.members, group.members_size, maxsize);
    cout << "\n ";
    printchar(maxsize, '-');
    cout << endl;
    displayProject(group.project);
}