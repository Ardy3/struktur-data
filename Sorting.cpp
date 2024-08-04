/* Nama        : Nico Ardy Hermawan */
/* NIM         : 230401010076 */
/* Kelas       : IT201 */
/* Mata Kuliah : Struktur Data dan Algoritma */

#include <iostream>
#include <string>
using namespace std;

struct Profile {
    string name, address;
};

// Fungsi Bubble Sort
void bubbleSort(Profile arr[], int limit){
    for (int i = 0; i < limit - 1; i++) {
        for (int j = 0; j < limit - i - 1; j++) {
            if (arr[j].name.compare(arr[j + 1].name) > 0) {
                Profile temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Fungsi Selection Sort
void selectionSort(Profile arr[], int limit){
    for (int i = 0; i < limit - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < limit; j++) {
            if (arr[j].name.compare(arr[minIndex].name) < 0) {
                minIndex = j;
            }
            
        }
        if (minIndex != i) {
            Profile temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

// Fungsi unutk mencetak Array
void printArray(Profile arr[], int size){
    for (int i = 0; i < size; i++) {
        cout << "Name: " << arr[i].name << ", Address: " << arr[i].address << endl;
    }
    cout << endl;
}

int main(){
    Profile arr[] = {
        {"Fahmi", "Jakarta"},
        {"Romi", "Solo"},
        {"Andri", "Jakarta"},
        {"Fadillah", "Banyuwangi"},
        {"Ruli", "Bandung"},
        {"Rudi", "Bali"},
        {"Dendi", "Purwokerto"},
        {"Zaki", "Madiun"}
    };
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Before Sort: " << endl;
    printArray(arr, n);

    cout << "Bubble Sort: " << endl;
    bubbleSort(arr, n);
    printArray(arr, n);

    cout << "After Selection Sort: " << endl;
    selectionSort(arr, n);
    printArray(arr, n);

    return 0;
}