#include <iostream>
using namespace std;

const int MAXLIST = 1000; //số lượng tối đa các phần tử mà danh sách có thể lưu trữ
struct List{
    int arr[MAXLIST + 1]; //mảng lưu các phần tử có kiểu int
    int count; //số lượng các phần tử đang có trong danh sách
};

void initialization(List &L){
    L.count = 0;
}

bool isEmpty(List L){
    if (L.count == 0) return true; // Nếu số lượng phần tử trong danh sách bằng 0 -> true 
    return false; 
}

bool isFull(List L){
    if (L.count == MAXLIST) return true; // Nếu số lượng bằng số lượng tối đa -> true
    return false;
}

bool read(List &L, int value){
    if (isFull(L)) return false;
    L.arr[++L.count] = value;
    return true;
}

bool deletion(List &L, int p){
    if(isEmpty(L)) return false; // Danh sách rông -> false
    if (p < 1 || p > L.count) return false; // p không thuộc đoạn [1,L.count] -> false
    // Xóa phần tử tại vị trí p bằng cách lưu lại từ vị trí p +1 đến L.count vào vị trí p đến L.count - 1
    for(int i = p; i < L.count; i++){
        L.arr[i] = L.arr[i+1];
    }
    L.count -= 1;
    return true;
}

bool insertion(List &L, int p, int value){
    if (isFull(L)) return false; // Danh sách đầy -> false
    if (p < 1 || p > L.count) return false; // p không thuộc đoạn [1,L.count] -> false
    // Chèn giá trị tại vị trí p bằng cách lưu lại từ vị trí p đến L.count vào vị trí p + 1 đến L.count + 1
    for (int i = L.count + 1; i > p; i--){
        L.arr[i] = L.arr[i-1];
    }
    L.arr[p] = value; // Gián giá trị cần chèn cho vị trí p
    L.count += 1; // Tăng số lượng phần tử trong danh sách lên 1 đơn vị
    return true;
}

void print(List L){
    if (isEmpty(L)){
        cout << "Linear list is empty" << endl;
        return;
    }
    for(int i =1 ; i <= L.count; i++){
        cout << L.arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    freopen("input.txt", "r", stdin);
    // Init linear list
    List list;
    initialization(list);
    // read value to linear list
    int n, value;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> value;
        read(list,value);
    }
    // Print linear list
    print(list);
    // Remove element in linear list
    deletion(list, 4);
    // Print linear list
    print(list);
    // Insert value to linear list
    insertion(list, 4, 50);
    // Print linear list
    print(list);
}