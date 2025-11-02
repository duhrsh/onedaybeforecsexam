/*

Enter value of n: 4
10 9 8 7 
6 5 4 
3 2 
1 

*/

#include <iostream>
using namespace std;

int main()
{

    int n;
    cout << "Enter value of n: ";
    cin >> n;

    int x = (n * (n + 1)) / 2;

    for (int i = n; i>= 1 && x>=1; i--) {
        for(int j = 1; j <= i; j++)
        {
            cout << x << " "; // while adding string to an integer in CPP, dont use + and use << because " " is C-string literal and will add integer, wont concatenate 
            x--;
        }
        cout << endl;
    }
    return 0;
}
