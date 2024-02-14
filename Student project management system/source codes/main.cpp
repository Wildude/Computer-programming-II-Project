#include "../headers/inclusions.hpp"
int main(){
    // control scheme 1
    page_1:
    // Clear the screen
    system("cls");
    
    // Print graphics (console) for appeal
    cout << "******************************" << endl;
    cout << "*       Welcome to          *" << endl;
    cout << "*       Addis Ababa university's project management system       *" << endl;
    cout << "******************************" << endl << endl;
    //
    cout << " Press any key to continue...";
    getch();
    // control scheme 2
    page_2:
    system("cls");
    char choice;
    int id, id2 = 0, index, idsize, *IDlist, largest;
    string filename;
    Individual individual;
    Group group;
    string username, firstname, secondname, password;
    do {
        cout << " Select an option:" << endl;
        cout << " 1. Manager" << endl;
        cout << " 2. User" << endl;
        cout << " 3. Back\n" << endl;
        cout << " Choice: ";
        cin >> choice;
        switch (choice) {
            case '1':
                goto page_3;
            case '2':
                goto page_7;
            case '3':
                goto page_1;
            default:
                cout << " Invalid choice. Please try again." << endl;
                cout << " Press any key to continue...";
                getch();
                break;
        }
    } while (choice != '1' && choice != '2' && choice != '3');
    //
    // control scheme 3
    page_3:
    system("cls");
    cout << " MANAGER MODE\n";
    cout << " Enter manager options: \n";
    cout << " 1. Login \n";
    cout << " 2. Update\n";
    cout << " 3. Delete\n";
    cout << " 4. Back\n";
    cout << " Choice: ";
    cin >> choice;
    switch (choice){
        case '1':{
            cout << " Enter login info:\n";
            cout << " Username: ";
            cin >> firstname >> secondname;
            username = firstname + ' ' + secondname;
            id = login(username);
            if(id < 0){
                cout << " login error\n\a";
                cout << " Press any key to continue...";
                getch();
                goto page_3;
            }
            cout << " Login successful\n";
            cout << " Press any key to continue...";
            getch();
            goto page_4;
        }
        case '2':{
            cout << " Enter username to update: ";
            cin >> firstname >> secondname;
            username = firstname + ' ' + secondname;
            id = update(username);
            if(id < 0){
                cout << " Updation failed\n\a";
                cout << " Press any key to continue...";
                getch();
                goto page_3;
            }
            cout << " Username updated successfully\n";
            cout << " Press any key to continue...";
            getch();
            goto page_3;
        }
        case '3':{
            cout << " Enter username to delete: ";
            cin >> firstname >> secondname;
            username = firstname + ' ' + secondname;
            id = searchManager(username);
            if(id < 0){
                cout << " Username not found\a\n";
                cout << " Press any key to continue...";
                getch();
                goto page_3;
            }
            int size1 = No_groupIDs(id), size2 = No_individualIDs(id);
            if(size1 < 0 || size2 < 0);
            int *gIDs = get_groupIDs(id), *iIDs = get_individualIDs(id);
            for(int i = 0; i < size1; i++){
                filename = "group" + to_str(id) + '_' + to_str(gIDs[i]) + ".dat";
                del_group(filename);
            }
            for(int i = 0; i < size2; i++){
                filename = "individual" + to_str(id) + '_' + to_str(iIDs[i]) + ".dat";
                del_individual(filename);
            }
            if(!del(username)){
                cout << " Deletion failed\n\a";
                cout << " Press any key to continue...";
                getch();
                goto page_3;
            }
            cout << " Username deleted successfully\n";
            cout << " Press any key to continue...";
            getch();
            goto page_3;
        }
        case '4':{
            goto page_2;
        }
        default:{
            cout << " choose only 1, 2, 3, 4 or 5\a\n";
            cout << " Press any key to continue...";
            getch();
            goto page_3;
        }
    }
    // control scheme 4
    page_4:
    system("cls");
    cout << " LOGGED IN as: " << username << endl;
    cout << " Enter your choice:\n";
    cout << " 1. Individual\n";
    cout << " 2. Group\n";
    cout << " 3. Back\n";
    cout << " Choice: ";
    cin >> choice;
    switch (choice){
        case '1':{
            goto page_5;
        }
        case '2':{
            goto page_6;
        }
        case '3':{    
            goto page_3;
        }
        default:{
            cout << " choose only 1, 2 or 3\a\n";
            cout << " Press any key to continue...";
            getch();    
            goto page_4;
        }
    }
    // control scheme 5
    page_5:
    system("cls");
    cout << " INDIVIDUAL PROJECT MODE\n";
    cout << " Enter your choice:\n";
    cout << " 1. Add Project\n";
    cout << " 2. Display Project\n";
    cout << " 3. Update Project\n";
    cout << " 4. Delete Project\n";
    cout << " 5. Back\n";
    cout << " Choice: ";
    cin >> choice;
    switch (choice){
        case '1':{
            goto page_8;
        }
        case '2':{
            goto page_10;
        }
        case '3':{
            goto page_12;
        }
        case '4':{
            goto page_14;
        }
        case '5':{
            goto page_4;
        }
        default:{
            cout << " choose only 1, 2, 3, 4 or 5\a\n";
            cout << " Press any key to continue...";
            getch();    
            goto page_5;
        }
    }
    //
    page_6:
    system("cls");
    cout << " GROUP PROJECT MODE\n";
    cout << " Enter your choice:\n";
    cout << " 1. Add Project\n";
    cout << " 2. Display Project\n";
    cout << " 3. Update Project\n";
    cout << " 4. Delete Project\n";
    cout << " 5. Back\n";
    cout << " Choice: ";
    cin >> choice;
    switch (choice){
        case '1':{
            goto page_9;
        }
        case '2':{
            goto page_11;
        }
        case '3':{
            goto page_13;
        }
        case '4':{
            goto page_15;
        }
        case '5':{
            goto page_4;
        }
        default:{
            cout << " choose only 1, 2, 3, 4 or 5\a\n";
            cout << " Press any key to continue...";
            getch();
            goto page_6;
        }
    }
    // control scheme 7
    page_7:
    // user implementation
    system("cls");
    cout << " USER MODE\n";
    cout << " 1. Individual\n";
    cout << " 2. Group\n";
    cout << " 3. Back\n";
    cout << " Choice: ";
    cin >> choice;
    switch (choice){
        case '1':{
            idsize = No_IDs();
            if(idsize < 0){
                cout << " Error loading manager information\a\n";
                cout << " Press any key to continue...";
                getch();
                goto page_7;
            }
            if(!idsize){
                cout << " No manager information stored\a\n";
                cout << " Press any key to continue...";
                getch();
                goto page_7;
            }
            IDlist = loadIDs();
            largest = 0;
            for(int i = 0; i < idsize; i++){
                int indsize = No_individualIDs(IDlist[i]);
                if(indsize < 0){
                    cout << " Error loading manager information (couldn't find individual assignments)\a\n";
                    cout << " Press any key to continue...";
                    getch();
                    goto page_7;
                }
                if(!indsize){
                    cout << " No manager information stored (no individual assignments found)\a\n";
                    cout << " Press any key to continue...";
                    getch();
                    goto page_7;
                }
                int* INDlist = get_individualIDs(IDlist[i]);
                Individual* individuals = new Individual[indsize];
                for(int j = 0; j < indsize; j++){
                    filename = "individual" + to_str(IDlist[i]) + '_' + to_str(INDlist[j]) + ".dat";
                    read_individual(filename,individuals[j]);
                }
                string* names = new string[indsize];
                for(int j = 0; j < indsize; j++)names[j] = individuals[j].student.firstname + ' ' + individuals[j].student.lastname;
                int longest = largest_length(names, indsize);
                largest = ((largest < longest) ? longest : largest);
            }
            for(int i = 0; i < idsize; i++){
                int indsize = No_individualIDs(IDlist[i]);
                if(indsize < 0){
                    cout << " Error loading manager information (couldn't load individual assignments)\a\n";
                    cout << " Press any key to continue...";
                    getch();
                    goto page_7;
                }
                if(!indsize){
                    cout << " No manager information stored (no individual assignments found)\a\n";
                    cout << " Press any key to continue...";
                    getch();
                    goto page_7;
                }
                int* INDlist = get_individualIDs(IDlist[i]);
                Individual* individuals = new Individual[indsize];
                for(int j = 0; j < indsize; j++){
                    filename = "individual" + to_str(IDlist[i]) + '_' + to_str(INDlist[j]) + ".dat";
                    read_individual(filename,individuals[j]);
                    display_individual(individuals[j], 100, largest);
                    cout << endl;
                }
                cout << " Press any key to continue...";
                getch();
                goto page_7;
            }
        }
        case '2':{
            largest = 0;
            idsize = No_IDs();
            if(idsize < 0){
                cout << " Error loading manager information\a\n";
                cout << " Press any key to continue...";
                getch();
                goto page_7;
            }
            if(!idsize){
                cout << " No manager information stored\a\n";
                cout << " Press any key to continue...";
                getch();
                goto page_7;
            }
            IDlist = loadIDs();
            largest = 0;
            for(int i = 0; i < idsize; i++){
                int grpsize = No_groupIDs(IDlist[i]);
                cout << " number of groups for ID("<<IDlist[i]<<") = "<<grpsize<<endl;
                if(grpsize < 0){
                    cout << " Error loading manager information (couldn't load group assignments)\a\n";
                    cout << " Press any key to continue...";
                    getch();
                    goto page_7;
                }
                if(!grpsize){
                    cout << " No manager information stored (no group assignments found)\a\n";
                    cout << " Press any key to continue...";
                    getch();
                    goto page_7;
                }
                int* GRPlist = get_groupIDs(IDlist[i]);
                Group* groups = new Group[grpsize];
                int largest1 = 0;
                for(int j = 0; j < grpsize; j++){
                    filename = "group" + to_str(IDlist[i]) + '_' + to_str(GRPlist[j]) + ".dat";
                    read_group(filename,groups[j]);
                    string* names = new string[groups[j].members_size];
                    for(int k = 0; k < groups[j].members_size; k++)names[k] = groups[j].members[k].firstname + ' ' + groups[j].members[k].lastname;
                    largest1 = (largest1 < largest_length(names, groups[j].members_size));
                }
                largest = (largest < largest1 ? largest1 : largest);
                
            }
            for(int i = 0; i < idsize; i++){
                int grpsize = No_groupIDs(IDlist[i]);
                cout << " number of groups for ID("<<IDlist[i]<<") = "<<grpsize<<endl;
                if(grpsize < 0){
                    cout << " Error loading manager information (couldn't load group assignments)\a\n";
                    cout << " Press any key to continue...";
                    getch();
                    goto page_7;
                }
                if(!grpsize){
                    cout << " No manager information stored (no group assignments found)\a\n";
                    cout << " Press any key to continue...";
                    getch();
                    goto page_7;
                }
                int* GRPlist = get_groupIDs(IDlist[i]);
                Group* groups = new Group[grpsize];
                int largest1 = 0;
                for(int j = 0; j < grpsize; j++){
                    filename = "group" + to_str(IDlist[i]) + '_' + to_str(GRPlist[j]) + ".dat";
                    read_group(filename,groups[j]);
                    display_group(groups[j], 100, largest);
                    cout << endl;
                }   
            }
            cout << " Press any key to continue...";
            getch();
            goto page_7;
        }
        case '3':{
            goto page_2;
        }
        default:{
            cout << " Press only 1, 2 or 3 only\n\a";
            cout << " Press any key to continue...";
            getch();
            goto page_7;
        }
    }
    //
    // control scheme 8
    page_8:
    system("cls");
    id2 = rand();
    filename = "individual" + to_str(id) + '_' + to_str(id2) + ".dat";
    if(search_individualID(id, id2) >= 0) goto page_8;
    add_individualID(id, id2);
    add_individual(filename, accept_individual());
    goto page_5;
    page_9:
    system("cls");
    id2 = rand();
    filename = "group" + to_str(id) + '_' + to_str(id2) + ".dat";
    if(search_groupID(id, id2) >= 0)goto page_9;
    add_groupID(id, id2);
    add_group(filename, accept_group());
    goto page_6;
    page_10:
    system("cls");
    cout << " Enter Identification number: ";
    cin >> id2;
    index = search_individualID(id, id2);
    if(index < 0){
        if(index == -5)cout << " Error fetching assignments list\a\n";
        if(index == -4)cout << " The list of assignments is empty\a\n";
        if(index == -3)cout << " Managerial error\a\n";
        if(index == -2)cout << " Couldn't open Manager file\a\n";
        if(index == -1)cout << " assignment not found\a\n";
        cout << " Press any key to continue...";
        getch();
        goto page_5;
    }
    filename = "individual" + to_str(id) + '_' + to_str(id2) + ".dat";
    read_individual(filename, individual);
    display_individual(individual);
    cout << "\n Press any key to continue...";
    getch();
    goto page_5;
    page_11:
    system("cls");
    cout << " Enter Identification number: ";
    cin >> id2;
    index = search_groupID(id, id2);
    if(index < 0){
        if(index == -5)cout << " Error fetching assignments list\a\n";
        if(index == -4)cout << " The list of assignments is empty\a\n";
        if(index == -3)cout << " Managerial error\a\n";
        if(index == -2)cout << " Couldn't open Manager file\a\n";
        if(index == -1)cout << " assignment not found\a\n";
        cout << " Press any key to continue...";
        getch();
        goto page_6;
    }
    filename = "group" + to_str(id) + '_' + to_str(id2) + ".dat";
    read_group(filename, group);
    display_group(group);
    cout << "\n Press any key to continue...";
    getch();
    goto page_6;
    page_12:
    system("cls");
    cout << " Enter Identification number: ";
    cin >> id2;
    index = search_individualID(id, id2);
    if(index < 0){
        if(index == -5)cout << " Error fetching assignments list\a\n";
        if(index == -4)cout << " The list of assignments is empty\a\n";
        if(index == -3)cout << " Managerial error\a\n";
        if(index == -2)cout << " Couldn't open Manager file\a\n";
        if(index == -1)cout << " assignment not found\a\n";
        cout << " Press any key to continue...";
        getch();
        goto page_5;
    }
    filename = "individual" + to_str(id) + '_' + to_str(id2) + ".dat";
    update_individual(filename);
    cout << " Press any key to continue...";
    getch();
    goto page_5;
    page_13:
    system("cls");
    cout << " Enter Identification number: ";
    cin >> id2;
    index = search_groupID(id, id2);
    if(index < 0){
        if(index == -5)cout << " Error fetching assignments list\a\n";
        if(index == -4)cout << " The list of assignments is empty\a\n";
        if(index == -3)cout << " Managerial error\a\n";
        if(index == -2)cout << " Couldn't open Manager file\a\n";
        if(index == -1)cout << " assignment not found\a\n";
        cout << " Press any key to continue...";
        getch();
        goto page_6;
    }
    filename = "group" + to_str(id) + '_' + to_str(id2) + ".dat";
    update_group(filename);
    cout << " Press any key to continue...";
    getch();
    goto page_6;
    page_14:
    system("cls");
    cout << " Enter Identification number: ";
    cin >> id2;
    index = search_individualID(id, id2);
    if(index < 0){
        if(index == -5)cout << " Error fetching assignments list\a\n";
        if(index == -4)cout << " The list of assignments is empty\a\n";
        if(index == -3)cout << " Managerial error\a\n";
        if(index == -2)cout << " Couldn't open Manager file\a\n";
        if(index == -1)cout << " assignment not found\a\n";
        cout << " Press any key to continue...";
        getch();
        goto page_5;
    }
    filename = "individual" + to_str(id) + '_' + to_str(id2) + ".dat";
    del_individualID(id, id2);
    del_individual(filename);
    cout << " Press any key to continue...";
    getch();
    goto page_5;
    page_15:
    system("cls");
    cout << " Enter Identification number: ";
    cin >> id2;
    index = search_groupID(id, id2);
    if(index < 0){
        if(index == -5)cout << " Error fetching assignments list\a\n";
        if(index == -4)cout << " The list of assignments is empty\a\n";
        if(index == -3)cout << " Managerial error\a\n";
        if(index == -2)cout << " Couldn't open Manager file\a\n";
        if(index == -1)cout << " assignment not found\a\n";
        cout << " Press any key to continue...";
        getch();
        goto page_6;
    }
    filename = "group" + to_str(id) + '_' + to_str(id2) + ".dat";
    del_groupID(id, id2);
    del_group(filename);
    cout << " Press any key to continue...";
    getch();
    goto page_6;
}