#include <iostream>
#include <stack>
using namespace std;

#include "../minStack.cpp"

int main() {

    MinStack minStack;

    minStack.push(5);
    minStack.push(2);
    minStack.push(3);

    // Test 1
    int expected = 2;
    int result = minStack.getMin();

    if (result == expected) {
        cout << "Test 1: PASS" << endl;
    } else {
        cout << "Test 1: FAIL | Expected: "
             << expected << " | Got: " << result << endl;
    }

    // Test 2
    minStack.pop();

    expected = 2;
    result = minStack.getMin();

    if (result == expected) {
        cout << "Test 2: PASS" << endl;
    } else {
        cout << "Test 2: FAIL | Expected: "
             << expected << " | Got: " << result << endl;
    }

    // Test 3
    minStack.pop();

    expected = 5;
    result = minStack.getMin();

    if (result == expected) {
        cout << "Test 3: PASS" << endl;
    } else {
        cout << "Test 3: FAIL | Expected: "
             << expected << " | Got: " << result << endl;
    }

    return 0;
}