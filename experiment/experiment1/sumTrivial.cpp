#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <iomanip>
using namespace std;

const int N = 1000000;
const int IT = 500;

int a[N + 5];
int main() {
    for (int i = 1;i <= N;i++)
        a[i] = i;

    long long startTime, endTime, Freq;
    QueryPerformanceFrequency((LARGE_INTEGER*)&Freq);
    QueryPerformanceCounter((LARGE_INTEGER*)&startTime);

    long long sum = 0;
    for (int it = 1;it <= IT;it++) {
        sum = 0;
        for (int i = 1;i <= N;i++)
            sum += (long long)(a[i]);
    }

    QueryPerformanceCounter((LARGE_INTEGER*)&endTime);
    cout << "Sum: " << sum << endl;
    cout << std::fixed << setprecision(2) << "Total Time: \t" << (double)(endTime - startTime) * 1000.0 / Freq << " ms" << endl;
    cout << std::fixed << setprecision(4) << "Avg Time:   \t" << (double)(endTime - startTime) * 1000.0 / (1.0 * IT * Freq) << " ms" << endl;
    return 0;
}