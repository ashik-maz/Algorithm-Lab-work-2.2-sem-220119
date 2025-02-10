#include <iostream>
using namespace std;
void bubbleSort(int arr[], int n) {
for (int i = 0; i < n - 1; i++) {
for (int j = 0; j < n - i - 1; j++) {
if (arr[j] > arr[j + 1]) {
swap(arr[j], arr[j + 1]);
}
}
}
}
void selectionSort(int arr[], int n) {
for (int i = 0; i < n - 1; i++) {
int minIndex = i;
for (int j = i + 1; j < n; j++) {
if (arr[j] < arr[minIndex]) {
minIndex = j;
}
}
swap(arr[i], arr[minIndex]);
}
}
int main() {
int arr1[] = {64, 25, 12, 22, 11};
int n1 = sizeof(arr1) / sizeof(arr1[0]);
bubbleSort(arr1, n1);
cout << "Bubble Sort: ";
for (int i : arr1) cout << i << " ";
cout << endl;int arr2[] = {64, 25, 12, 22, 11};
int n2 = sizeof(arr2) / sizeof(arr2[0]);
selectionSort(arr2, n2);
cout << "Selection Sort: ";
for (int i : arr2) cout << i << " ";
cout << endl;
return 0;
}