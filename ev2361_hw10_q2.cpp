#include <iostream>
#include <vector>
using namespace std;
int* findMissing(int arr[], int n, int& resArrSize) {
    vector<int> containingVector;
    vector<int> temporaryArray(n + 1, -1);

    for (int i = 0; i < n; i++) {
        temporaryArray[arr[i]] = 1;
    }

    for (int i = 0; i <= n; i++) {
        if (temporaryArray[i] == -1) {
            containingVector.push_back(i);
        }
    }

    resArrSize = containingVector.size();
    int* resultingArray = new int[resArrSize];
    for (int i = 0; i < resArrSize; i++) {
        resultingArray[i] = containingVector[i];
    }

    return resultingArray;
}
int main() {
    int test[] = {3, 1, 3, 0, 6, 4};
    int arrSize;
    int* resultArr = findMissing(test, 6, arrSize);
    for (int i = 0; i < arrSize; i++) {
        cout << *resultArr << endl;
        resultArr++;
    }
}