#include <iostream>

using namespace std;

int main() {
    int a;
    unsigned int c;
    cin >> a >> c;
    for (unsigned int i = 1; i <= c; i++) {
        int b;
        cin >> b;
        if (a % b == 0) {
            cout << "TAK" << endl;
        } else {
            cout << "NIE" << endl;
        }
    }
}