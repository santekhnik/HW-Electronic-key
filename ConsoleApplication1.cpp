#include <iostream>
using namespace std;


int main()
{
    const int n = 10;
    int bnm[n + 1];
    int k = 0;
    bnm[0] = 1;

    cout << bnm[0] << "  ";

    while (k < n) {

        bnm[k + 1] = bnm[k] * (n - k) / (k + 1);
        cout << bnm[k + 1] << "  ";
        k++;
    }

    cout << endl;

    cin.get();
    return 0;
}