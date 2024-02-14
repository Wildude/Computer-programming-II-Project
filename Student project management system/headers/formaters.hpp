using namespace std;
void printchar(int n, char c = ' '){
    for(int i = 0; i < n; i++)
    cout << c;
}
void lateralsidebox(int n, string text, bool lside = 1){
    if(lside){
        cout << " | " << text;
        printchar(n - (text.length()), ' ');
    }
    else{
        cout << ' ' << text;
        printchar(n - (text.length()), ' ');
    }
    cout << '|';
}
void sidebox(int n, string text, bool lside = 1){
    if(lside){
        cout << " | " << text;
        printchar(n - (3 + text.length()), ' ');
    }
    else{
        cout << ' ' << text;
        printchar(n - (1 + text.length()), ' ');
    }
    cout << '|';
}
int numdigits(int num){
    int digits = 0;
    for(int i = 1; ; i *= 10){
        if(i == 1 && !(num/i))return 1;
        else if(!(num/i))return digits;
        digits++;
    }
    return digits;
}
int largest_length(string* strings, int size){
    int longest = 0;
    for(int i = 0; i < size; i++){
        longest = (longest < strings[i].length() ? strings[i].length() : longest);
    }
    return longest;
}
int count_bytes(string filename){
    ifstream file(filename, ios::binary);
    file.seekg(0, ios::end);
    int lastpos = file.tellg();
    file.seekg(0, ios::beg);
    if(!file)return -1;
    int count = 0;
    while(file.tellg() != lastpos){
        char c;
        file.get(c);
        count++;
    }
    cout << endl;
    file.close();
    return count;
}
string to_str(int num){
    string str;
    int digits = numdigits(num);
    for(int i = digits-1; i >= 0 ;i--){
        int targetnum = num / pow(10, i);
        //cout << targetnum << ' ';
        str += (char)(targetnum % 10 + 48);
    }
    return str;
}

int copy_contents(string file1, string& file2, int size = -1){
    size = (size <= 0 ? count_bytes(file1) : size);
    ifstream copy_from(file1, ios::binary);
    ofstream copy_to(file2, ios::binary);
    int return_message = 1;
    if(!copy_from && !copy_to)return_message = -3;
    else if(!copy_from)return_message = -1;
    else if(!copy_to)return_message = -2;
    while(copy_from.tellg() != size){
        char c;
        copy_from.get(c);
        copy_to.put(c);
    }
    copy_from.close();
    copy_to.close();
    return return_message;
}
int copy_from(string file1, string& file2, int pos = 0){
    pos = (pos <= 0 ? 0 : pos);
    ifstream copy_from(file1, ios::binary);
    copy_from.seekg(0,ios::end);
    int lastpos = copy_from.tellg();
    copy_from.seekg(pos);
    ofstream copy_to(file2, ios::binary);
    int return_message = 1;
    if(!copy_from)return_message = -1;
    if(!copy_to)return_message = -2;
    while(copy_from.tellg() != lastpos){
        char c;
        copy_from.get(c);
        copy_to.put(c);
    }
    copy_from.close();
    copy_to.close();
    return return_message;
}
int app_contents(string file1, string& file2, int size = -1){
    size = (size <= 0 ? count_bytes(file1) : size);
    ifstream copy_from(file1, ios::binary);
    ofstream copy_to(file2, ios::binary|ios::app);
    int return_message = 1;
    if(!copy_from)return_message = -1;
    if(!copy_to)return_message = -2;
    while(copy_from.tellg() != size){
        char c;
        copy_from.get(c);
        copy_to.put(c);
    }
    copy_from.close();
    copy_to.close();
    return return_message;
}
int app_from(string file1, string& file2, int pos = 0){
    pos = (pos <= 0 ? 0 : pos);
    int size = count_bytes(file1);
    ifstream copy_from(file1, ios::binary);
    ofstream copy_to(file2, ios::binary|ios::app);
    int return_message = 1;
    if(!copy_from)return_message = -1;
    if(!copy_to)return_message = -2;
    while(copy_from.tellg() != size){
        char c;
        copy_from.get(c);
        copy_to.put(c);
    }
    copy_from.close();
    copy_to.close();
    return return_message;
}