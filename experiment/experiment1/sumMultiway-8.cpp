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

    long long sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0, sum5 = 0, sum6 = 0, sum7 = 0, sum8 = 0;
    long long sum = 0;
    for (int it = 1;it <= IT;it++) {
        sum1 = sum2 = sum3 = sum4 = sum5 = sum6 = sum7 = sum8 = sum = 0;
        for (int i = 1;i <= N;i += 8) {
            sum1 += a[i];
            sum2 += a[i + 1];
            sum3 += a[i + 2];
            sum4 += a[i + 3];
            sum5 += a[i + 4];
            sum6 += a[i + 5];
            sum7 += a[i + 6];
            sum8 += a[i + 7];
        }
        sum = sum1 + sum2 + sum3 + sum4 + sum5 + sum6 + sum7 + sum8;
    }

    QueryPerformanceCounter((LARGE_INTEGER*)&endTime);
    cout << "Sum: " << sum << endl;
    cout << std::fixed << setprecision(2) << "Total Time: \t" << (double)(endTime - startTime) * 1000.0 / Freq << " ms" << endl;
    cout << std::fixed << setprecision(4) << "Avg Time:   \t" << (double)(endTime - startTime) * 1000.0 / (1.0 * IT * Freq) << " ms" << endl;
    return 0;
}