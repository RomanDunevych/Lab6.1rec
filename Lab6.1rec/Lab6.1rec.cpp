#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

void generateArray(int t[], int size, int lowerBound, int upperBound) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        t[i] = rand() % (upperBound - lowerBound + 1) + lowerBound;
    }
}

void printArray(int t[], int size) {
    for (int i = 0; i < size; i++) {
        cout << setw(3) << t[i] << " ";
    }
    cout << endl;
}

void countAndSumRecursive(int t[], int size, int& count, int& sum, int index) {
    
    if (index >= size) {
        return;
    }

    if (t[index] < 0 && index % 3 != 0) {
        count++;
        sum += t[index];
        t[index] = 0;
    }

    countAndSumRecursive(t, size, count, sum, index + 1);
}

int main() {
    const int SIZE = 25;
    int t[SIZE];
    int lowerBound = -11;
    int upperBound = 13;
    int count = 0, sum = 0;

    generateArray(t, SIZE, lowerBound, upperBound);
    cout << "The generated array is: " << endl;
    printArray(t, SIZE);

    countAndSumRecursive(t, SIZE, count, sum, 0);

    cout << "The number of elements that satisfy the criterion is: " << count << endl;
    cout << "The sum of elements that satisfy the criterion is: " << sum << endl;

    cout << "The modified array is: " << endl;
    printArray(t, SIZE);

    return 0;
}
