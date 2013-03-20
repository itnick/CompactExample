//
//  main.cpp
//  CompactExample
//
//  Created by itnick on 21/3/13.
//
//

#include <iostream>
using namespace std;

int compact(int *p, int size)
{
    int lastNumber;
    int numOfDuplicate = 0;
    
    int *compactNumbers = new int[size];
    
    for (int i = 0; i < size; i++) {
        if (i == 0) { // 1st item always shown
            compactNumbers[i] = p[i];
        } else { // 2nd to nth items
            if (lastNumber < p[i]) { // number not duplicate
                compactNumbers[i-numOfDuplicate] = p[i];
            } else {
                numOfDuplicate++;
            }
        }
        lastNumber = p[i];
    }
    
    std::cout << "Inside function:" << endl;
    for (int i = 0; i < size - numOfDuplicate; i++) {
        std::cout << compactNumbers[i] << endl;
    }
    
    *p *= *compactNumbers;
    delete[] compactNumbers;
    
    return size - numOfDuplicate;
}

int main(int argc, const char * argv[])
{
    int numbers[] = {1, 3, 7, 7, 8, 9, 9, 9, 10};
    
    std::cout << "Before:" << endl;
    for (int i = 0; i < 9; i++) {
        std::cout << numbers[i] << endl;
    }
    
    int size = sizeof(numbers) / sizeof(numbers[0]);
    //int size = sizeof(numbers);
    int compactSize = compact(numbers, size);
    std::cout << "After:" << endl;
    for (int i = 0; i < compactSize; i++) {
        std::cout << numbers[i] << endl;
    }
    
    // Other test cases:
    // TODO:
    return 0;
}

