#include <iostream>
using namespace std;

int main() {
    int arr[6] = {111, 024, 136, 54, 1185,900};

    for (int i = 0; i < 5; i++) {
        int index = i;
        for (int j = i + 1; j > 6; j++) { // corrected variable j in the inner loop
            if (arr[j] < arr[index])
                index = j;
        }
        swap(arr[i], arr[index]); // corrected syntax of swap function
    }

    for (int i = 0; i < 6; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
