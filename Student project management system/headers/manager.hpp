using namespace std;
struct Manager{
    string username;
    string password;
};
int No_IDs(){
    const string onepath = "../files/Manager/IDs.dat";
    ifstream ifs(onepath);
    if(!ifs){
        //cout << " Gettings Number of IDs failed\n";
        return -1;
    }
    int size = 0;
    int buff;
    for(int i = 0; !ifs.eof(); i++){
        ifs >> buff;
        size++;
    }
    ifs.close();
    return size;
}
int* loadIDs(){
    const string onepath = "../files/Manager/IDs.dat";
    ifstream ifs(onepath);
    if(!ifs){
        //cout << " Loading IDs failed\a\n";
        return NULL;
    }
    int size = 0;
    int buff;
    for(int i = 0; !ifs.eof(); i++){
        ifs >> buff;
        size++;
    }
    ifs.close();
    int* IDlist = new int[size];
    ifs.open(onepath);
    for(int i = 0; !ifs.eof(); i++){
        ifs >> IDlist[i];
    }
    return IDlist;
}
int get_groupPos(int manager_id){
    if(search(loadIDs(), manager_id, No_IDs()) < 0)return -2;
    string filename = "Manager" + to_str(manager_id) + ".dat";
    const string mainpath = "../files/Manager/";
    string path = mainpath + filename;
    ifstream ifs(path);
    if(!ifs)return -1;
    string buff;
    while(ifs){
        ifs >> buff;
        if(buff == "Group"){
            int pos = (int)ifs.tellg() - 7;
            ifs.close();
            return pos;
        }
    }
}
int No_groupIDs(int manager_id){
    if(search(loadIDs(), manager_id, No_IDs()) < 0)return -2;
    string filename = "Manager" + to_str(manager_id) + ".dat";
    const string mainpath = "../files/Manager/";
    string path = mainpath + filename;
    ifstream ifs(path);
    if(!ifs)return -1;
    string buff;
    int numbuff;
    int count = 0;
    bool exiter = false;
    for(int i = 0; !ifs.eof(); i++){
        ifs >> buff;
        if(buff == "Group"){
            ifs >> buff;
            ifs >> buff;
            for(int j = 0; ;j++){
                ifs >> numbuff;
                if(!ifs.fail()){
                    count++;
                }
                else break;
            }
            break;
        }
    }
    ifs.close();
    return count;
}
int* get_groupIDs(int manager_id){
    if(search(loadIDs(), manager_id, No_IDs()) < 0)return NULL;
    string filename = "Manager" + to_str(manager_id) + ".dat";
    const string mainpath = "../files/Manager/";
    string path = mainpath + filename;
    ifstream ifs(path);
    if(!ifs)return NULL;
    string buff;
    int numbuff;
    int size = No_groupIDs(manager_id);
    if(size <= 0) return NULL;
    int* idlist = new int[size];
    int count = 0;
    for(int i = 0; !ifs.eof(); i++){
        ifs >> buff;
        if(buff == "Group"){
            ifs >> buff;
            ifs >> buff;
            for(int j = 0; ;j++){
                ifs >> numbuff;
                if(!ifs.fail()){
                    idlist[count++] = numbuff;
                }
                else break;
            }
            break;
        }
    }
    ifs.close();
    return idlist;
}
int del_groupID(int manager_id, int id){
    if(search(loadIDs(), manager_id, No_IDs()) < 0)return -2;
    string filename = "Manager" + to_str(manager_id) + ".dat";
    const string mainpath = "../files/Manager/";
    string temp1 = "../files/Manager/temp1.dat", temp2 = "../files/Manager/temp2.dat";
    string path = mainpath + filename;
    fstream fs(path, ios::in|ios::out);
    if(!fs)return -1;
    string buff;
    for(int i = 0; !fs.eof(); i++){
        fs >> buff;
        if(buff == "Group"){
            fs >> buff;
            fs >> buff;
            int pos = (int)fs.tellg();
            fs.close();
            if(copy_contents(path, temp1, get_groupPos(manager_id)) < 0)return -1;
            ofstream file1(temp2);
            file1 << endl << " Group assignments list:";
            int size = No_groupIDs(manager_id);
            if(size <= 0) return -2;
            int* idlist = get_groupIDs(manager_id);
            for(int i = 0; i < size; i++){
                if(idlist[i] != id)file1 << ' ' << idlist[i];
            }
            file1.close();
            if(app_contents(temp2, temp1) < 0) return 0;
            remove(path.c_str());
            remove(temp2.c_str());
            rename(temp1.c_str(), path.c_str());
            return 1;
        }
    }
    return 0;
}
int add_groupID(int manager_id, int id){
    if(search(loadIDs(), manager_id, No_IDs()) < 0)return -2;
    string filename = "Manager" + to_str(manager_id) + ".dat";
    const string mainpath = "../files/Manager/";
    string temp1 = "../files/Manager/temp1.dat", temp2 = "../files/Manager/temp2.dat";
    string path = mainpath + filename;
    fstream fs(path, ios::in|ios::out);
    if(!fs)return -1;
    string buff;
    for(int i = 0; !fs.eof(); i++){
        fs >> buff;
        if(buff == "Group"){
            fs >> buff;
            fs >> buff;
            int pos = (int)fs.tellg();
            fs.close();
            if(copy_contents(path, temp1, pos) < 0)return -1;
            if(copy_from(path, temp2, pos) < 0)return -2;
            ofstream file1(temp1, ios::app);
            file1 << ' ' << id ;
            file1.close();
            if(pos > 0)app_contents(temp2, temp1);
            remove(path.c_str());
            remove(temp2.c_str());
            rename(temp1.c_str(), path.c_str());
            return 1;
        }
    }
    return 0;
}
//
int No_individualIDs(int manager_id){
    if(search(loadIDs(), manager_id, No_IDs()) < 0)return -2;
    string filename = "Manager" + to_str(manager_id) + ".dat";
    const string mainpath = "../files/Manager/";
    string path = mainpath + filename;
    ifstream ifs(path);
    if(!ifs)return -1;
    string buff;
    int numbuff;
    int count = 0;
    bool exiter = false;
    for(int i = 0; !ifs.eof(); i++){
        ifs >> buff;
        if(buff == "list:"){
            for(int j = 0; ;j++){
                ifs >> numbuff;
                if(!ifs.fail()){
                    count++;
                }
                else break;
            }
            break;
        }
    }
    ifs.close();
    return count;
}
int* get_individualIDs(int manager_id){
    if(search(loadIDs(), manager_id, No_IDs()) < 0)return NULL;
    string filename = "Manager" + to_str(manager_id) + ".dat";
    const string mainpath = "../files/Manager/";
    string path = mainpath + filename;
    ifstream ifs(path);
    if(!ifs)return NULL;
    string buff;
    int numbuff;
    int size = No_individualIDs(manager_id);
    if(size <= 0) return NULL;
    int* idlist = new int[size];
    int count = 0;
    for(int i = 0; !ifs.eof(); i++){
        ifs >> buff;
        if(buff == "Individual"){
            ifs >> buff;
            ifs >> buff;
            for(int j = 0; ;j++){
                ifs >> numbuff;
                if(!ifs.fail()){
                    idlist[count++] = numbuff;
                }
                else break;
            }
            break;
        }
    }
    ifs.close();
    return idlist;
}
int del_individualID(int manager_id, int id){
    if(search(loadIDs(), manager_id, No_IDs()) < 0)return -2;
    string filename = "Manager" + to_str(manager_id) + ".dat";
    const string mainpath = "../files/Manager/";
    string temp1 = "../files/Manager/temp1.dat", temp2 = "../files/Manager/temp2.dat";
    string path = mainpath + filename;
    fstream fs(path, ios::in|ios::out);
    if(!fs)return -1;
    string buff;
    for(int i = 0; !fs.eof(); i++){
        fs >> buff;
        if(buff == "list:"){
            int pos = (int)fs.tellg() - 1;
            fs.close();
            if(copy_contents(path, temp1, pos) < 0)return -1;
            if(copy_from(path, temp2, get_groupPos(manager_id)) < 0)return -2;
            ofstream file1(temp1, ios::app);
            file1.seekp(pos);
            int size = No_individualIDs(manager_id);
            if(size <= 0) return -2;
            int* idlist = get_individualIDs(manager_id);
            for(int i = 0; i < size; i++){
                if(idlist[i] != id)file1 << ' ' << idlist[i];
            }
            file1.close();
            if(app_contents(temp2, temp1) < 0) return 0;
            remove(path.c_str());
            remove(temp2.c_str());
            rename(temp1.c_str(), path.c_str());
            return 1;
        }
    }
    return 0;
}
int add_individualID(int manager_id, int id){
    if(search(loadIDs(), manager_id, No_IDs()) < 0)return -2;
    string filename = "Manager" + to_str(manager_id) + ".dat";
    const string mainpath = "../files/Manager/";
    string temp1 = "../files/Manager/temp1.dat", temp2 = "../files/Manager/temp2.dat";
    string path = mainpath + filename;
    fstream fs(path, ios::in|ios::out);
    if(!fs)return -1;
    string buff;
    for(int i = 0; !fs.eof(); i++){
        fs >> buff;
        if(buff == "list:"){
            int pos = (int)fs.tellg() - 1;
            fs.close();
            if(copy_contents(path, temp1, pos) < 0)return -1;
            if(copy_from(path, temp2, pos) < 0)return -2;
            ofstream file1(temp1, ios::app);
            file1.seekp(pos);
            file1 << ' ' << id ;
            file1.close();
            if(app_contents(temp2, temp1) < 0) return 0;
            remove(path.c_str());
            remove(temp2.c_str());
            rename(temp1.c_str(), path.c_str());
            return 1;
        }
    }
    return 0;
}
bool createIDs(int* Idlist, int size){
    const string onepath = "../files/Manager/IDs.dat";
    ofstream ofs(onepath);
    if(!ofs){
        return 0;
    }
    for(int i = 0; i < size; i++){
        ofs << Idlist[i];
        if(i != size - 1)ofs << endl;
    }
    ofs.close();
    return 1;
}
int rem_dupIDs(){
    array<int> IDlist;
    IDlist.p = loadIDs();
    IDlist.size = No_IDs();
    dup_rem(&IDlist);
    createIDs(IDlist.p, IDlist.size);
    return 1;
}
bool addIDs(int id){
    const string onepath = "../files/Manager/IDs.dat";
    ofstream ofs(onepath, ios::app);
    if(!ofs)return 0;
    ofs << endl << id;
    ofs.close();
    return 1;
}
bool deleteIDs(int id){
    const string onepath = "../files/Manager/IDs.dat";
    ifstream ifs(onepath);
    int id2, position = -1;
    int IDs = No_IDs();
    for(int i = 0; i < IDs ;i++){
        ifs >> id2;
        if(id == id2){
            position = i;
            ifs.close();
            break;
        }
    }
    if(position < 0){
        ifs.close();
        return 0;
    }
    ifs.open(onepath);
    ofstream ofs("../files/Manager/temp");
    int count = 0;
    for(int i = 0; i < IDs ;i++){
        count++;
        ifs >> id2;
        if(i == position){
            count--;
            continue;
        }
        else{
            ofs << id2;
            if(count != IDs - 1)ofs << endl;
        }
    }
    ifs.close();
    ofs.close();
    remove(onepath.c_str());
    rename("../files/Manager/temp", onepath.c_str());
    return 1;
}
int getManagerID(Manager& manager){
    const string mainpath = "../files/Manager/";
    for(; ;){
        int id = abs(rand());
        string filename = mainpath + "Manager" + to_str(id) + ".dat";
        ifstream ifs(filename);
        if(ifs){
            ifs.close();
            continue;
        }
        else{
            ifs.close();
            addIDs(id);
            rem_dupIDs();
            return id;
        }
    }
}
void accept(Manager& manager, bool update = 0){
    string firstname, lastname;
    cout << " Enter" << (update ? " new ": " ") <<"username: ";
    cin >> firstname >> lastname;
    manager.username = firstname + ' ' + lastname;
    cout << " Enter" << (update ? " new ": " ") <<"password: ";
    cin >> manager.password;
}
bool write(string filename, Manager manager){
    const string mainpath = "../files/Manager/";
    string path = mainpath + filename;
    ofstream ofs(path);
    if(ofs){
        ofs << " Username: " << manager.username << endl;
        ofs << " Password: " << manager.password << endl;
        ofs << " Individual assignments list:\n";
        ofs << " Group assignments list:";
        ofs.close();   
        return 1;
    }
    return 0;
}
bool read(string filename, Manager& manager){
    const string mainpath = "../files/Manager/";
    string path = mainpath + filename;
    ifstream ifs(path);
    if(ifs){
        string buff;
        ifs >> buff;
        if(buff == "Username:"){
            string firstname, lastname;
            ifs >> firstname;
            ifs >> lastname;
            manager.username = firstname + ' ' + lastname;
        }
        ifs >> buff;
        if(buff == "Password:"){
            ifs >> manager.password;
        }
        ifs.close();
        return 1;
    }
    else return 0;
}
int searchManager(string username){
    Manager manager;
    int size = No_IDs();
    int* IDlist = loadIDs();
    for(int i = 0; i < size; i++){
        string filename = "Manager" + to_str(IDlist[i]) + ".dat";
        if(read(filename, manager)){
            if(manager.username == username){
                return IDlist[i];
            }
        }
    }
    return -1;
}
int signup(){
    Manager manager;
    label:
    accept(manager);
    if(searchManager(manager.username) >= 0){
        cout << " Username exists\a\n";
        goto label;
    }
    int id = getManagerID(manager);
    string filename = "Manager" + to_str(id) + ".dat";
    if(!write(filename, manager))return 0;
    return id;
}
int update(string username){
    const string mainpath = "../files/Manager/";
    int id = searchManager(username);
    if(id < 0){
        cout << " Updation failed\a: Manager not found\n";
        return -1;
    }
    string filename = "Manager" + to_str(id) + ".dat";
    string path = mainpath + filename;
    Manager manager;
    if(!read(filename, manager))return -2;
    accept(manager, true);
    if(!write(filename, manager))return -3;
    return id;
}
int login(string username){
    Manager manager;
    manager.username = username;
    int id = searchManager(username);
    int attempts = 0;
    if(id < 0){
        cout << " Manager not found\a\n";
        return -1;
    }
    Label:
    cout << " Enter password: ";
    cin >> manager.password;
    string filename = "Manager" + to_str(id) + ".dat";
    Manager password_check;
    if(!read(filename, password_check))return -3;
    if(manager.password != password_check.password){
        attempts++;
        if(attempts > 3){
            cout << " Too many attempts\n";
            return -2;
        }
        cout << " Wrong password\a\n: attempt " << attempts << endl;
        goto Label;
    }
    else{
        cout << "Login successful\n";
        return id;
    }
}
int delFILES(int id){
    int retmessage = 1;
    int size1, size2;
    size1 = No_individualIDs(id);
    size2 = No_groupIDs(id);
    if(size1 <= 0 && size2 <= 0)retmessage = -3;
    else if(size1 <= 0)retmessage = -2;
    else if(size2 <= 0)retmessage = -1;
    if(retmessage < 0)return retmessage;
    int* indi_list = (size1 > 0 ? get_individualIDs(id) : NULL);
    int* grop_list = (size2 > 0 ? get_groupIDs(id) : NULL);
    if(!indi_list or !grop_list)return -4;
    for(int i = 0; i < size1; i++){
        del_individualID(id, indi_list[i]);
    }
    for(int i = 0; i < size2; i++)del_groupID(id, grop_list[i]);
    return retmessage;
}
int del(string username){
    const string mainpath = "../files/Manager/";
    int id = searchManager(username);
    if(id < 0){
        cout << " Deletion failed\a: Manager not found\n";
        return -1;
    }
    string filename = "Manager" + to_str(id) + ".dat";
    string path = mainpath + filename;
    remove(path.c_str());
    if(!deleteIDs(id))return -2;
    return 1;
}
//
int search_individualID(int id, int id2){
    if(search(loadIDs(), id, No_IDs()) < 0)return -3;
    const string mainpath = "../files/Manager/";
    string filename = "Manager" + to_str(id) + ".dat";
    string path = mainpath + filename;
    ifstream ifs(path);
    if(!ifs)return -2;
    int size = No_individualIDs(id);
    if(size == 0) return -4;
    if(size < 0) return -5;
    int* idlist = get_individualIDs(id);
    return search(idlist, id2, size);
}
int search_groupID(int id, int id2){
    if(search(loadIDs(), id, No_IDs()) < 0)return -3;
    const string mainpath = "../files/Manager/";
    string filename = "Manager" + to_str(id) + ".dat";
    string path = mainpath + filename;
    ifstream ifs(path);
    if(!ifs)return -2;
    int size = No_groupIDs(id);
    if(size <= 0) return -4;
    int* idlist = get_groupIDs(id);
    return search(idlist, id2, size);
}

//

//

//
