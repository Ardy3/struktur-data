/* Nama        : Nico Ardy Hermawan */
/* NIM         : 230401010076 */
/* Kelas       : IT201 */
/* Mata Kuliah : Struktur Data dan Algoritma */

#include <iostream>
#include <algorithm>
using namespace std;

struct Element {
    int value, index;
};

// Fungsi untuk membandingkan element
bool compareElement(Element a, Element b){
    return a.value < b.value;
}

// Fungsi Binary Search
int binarySearch(Element arr[], int l, int r, int x){
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (arr[mid].value == x) {
            return mid;
        }
        if (arr[mid].value < x) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return -1;   
}

// Fungsi mencari index element
void searchElement(int arr[], int n, int x){
    Element elements[n];
    for (int i = 0; i < n; i++) {
        elements[i].value = arr[i];
        elements[i].index = i + 1;
    }

    sort(elements, elements + n, compareElement);

    int result = binarySearch(elements, 0, n - 1, x);

    // Jika elemen ditemukan
    if (result != -1) {
        cout << "Angka " << x << " ada di indeks ke " << elements[result].index;
        // Cek elemen sebelum dan sesudah untuk menangani duplikasi
        int left = result - 1;
        while (left >= 0 && elements[left].value == x) {
            cout << " dan " << elements[left].index;
            left--;
        }
        int right = result + 1;
        while (right < n && elements[right].value == x) {
            cout << " dan " << elements[right].index;
            right++;
        }
        cout << endl;
    } else {
        cout << "Angka " << x << " tidak ada dalam array" << endl;
    }
}

int main(){
    int arr[] = {19, 40, 10, 90, 2, 50, 60, 50, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Test case 1
    int x = 1;
    cout << "Input: " << x << endl;
    searchElement(arr, n, x);
    cout << endl;

    // Test case 2
    x = 50;
    cout << "Input: " << x << endl;
    searchElement(arr, n, x);
    cout << endl;

    // Test case 3
    x = 80;
    cout << "Input: " << x << endl;
    searchElement(arr, n, x);
    cout << endl;

    return 0;
}