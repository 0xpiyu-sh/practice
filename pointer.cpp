#include <iostream>
using namespace std;

int main() {

    int numbers[] = {10, 20, 30, 40, 50};
    cout << "First element of array: " << numbers[0] << endl;


    int value = 100;
    int* ptr = &value; 

    cout << "Value: " << value << endl;
    cout << "Address of value: " << &value << endl;
    cout << "Value through pointer: " << *ptr << endl;

  
    int* dynamicArray = new int[3];
    dynamicArray[0] = 1;
    dynamicArray[1] = 2;
    dynamicArray[2] = 3;

    cout << "Dynamic array elements: ";
    for (int i = 0; i < 3; ++i) {
        cout << dynamicArray[i] << " ";
    }
    cout << endl;

   

    return 0;
}
