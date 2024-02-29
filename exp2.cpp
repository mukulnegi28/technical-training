#include <iostream>
#include <vector>
using namespace std;
// Function to left rotate an array by d steps
vector<int> rotateLeft(int d, const vector<int>& arr) {
 int n = arr.size();
 vector<int> rotatedArray(n);
 // Perform left rotation
 for (int i = 0; i < n; i++) {
 int newIndex = (i + n - d) % n;
 rotatedArray[newIndex] = arr[i];
 }
 return rotatedArray;
}
int main() {
 int n, d;
 cout << "Enter the size of the array and the number of left rotations (n d): ";
 cin >> n >> d;
 vector<int> arr(n);
 cout << "Enter the elements of the array: ";
 for (int i = 0; i < n; i++) {
 cin >> arr[i];
 }
 vector<int> result = rotateLeft(d, arr);
 cout << "Rotated Array: ";
 for (int i = 0; i < n; i++) {
 cout << result[i] << " ";
 }
 return 0;
}