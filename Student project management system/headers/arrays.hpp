using namespace std;
template <class T>
struct array{
    T* p;
    int size;
};
template <class T>
void copy_array(T* list1, T** list2, int size){
    for(int i = 0; i < size; i++){
        list2[0][i] = list1[i];
    }
}
template <class T>
void display(T* list, int size){
    for(int i = 0; i < size; i++){
        cout << ' ' << (i + 1) << ". " << list[i] << endl;
    }
}
template <class T>
void display(array<T> list){
    display(list.p, list.size);
}
template <class T>
void sort(T** list, int size){
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            if(list[0][i] < list[0][j]){
                swap(list[0][i], list[0][j]);
            }
        }
    }
}
template <class T>
void sort(array<T>* list){
    sort(&list->p, list->size);
}
template <class T>
void dup_rem(array<T>* list){
    sort(&list->p, list->size);
    int* duplicate_indices = new int[list->size];
    int count = 0;
    for(int i = 0; i < list->size; i++){
        for(int j = 0; j < list->size; j++){
            if(i == j)continue;
            if(list->p[i] == list->p[j]){
                if(i > j){
                    break;
                }
                duplicate_indices[count++] = j;
            }
        }
    }
    int original_size = list->size;
    T* temporary_list = new T[original_size - count];
    int count2 = 0;
    for(int i = 0; i < list->size; i++){
        bool not_duplicate = true;
        for(int j = 0; j < count; j++){
            if(i == duplicate_indices[j]){
                not_duplicate = false;
                break;
            }
        }
        if(not_duplicate){
            temporary_list[count2++] = list->p[i];
        }
    }
    delete list->p;
    list->p = new int[original_size - count];
    list->size = original_size - count;
    copy_array(temporary_list, &list->p, original_size - count);
}
template <class T>
void accept(array<T>* list){
    cout << " Enter " << list->size << " elements:\n";
    for(int i = 0; i < list->size; i++){
        cout << ' ' << (i + 1) <<". ";
        cin >> list->p[i];
    }
}
template <class T>
int search(T* list, T item, int n){
    for(int i = 0; i < n; i++){
        if(item == list[i])return i;
    }
    return -1;
}