#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <iomanip>
using namespace std;

const int N = 1000000;
const int IT = 500;

long long a[N], b[N];

long long sum() {
    long long ans = 0; int len = N;
    while (len > 0) {
        if (len == 1) { ans = b[1]; break; }
        else if (len == 2) { ans = b[1] + b[2]; break; }
        for (int i = 1;i <= (len + 1) / 2;i++) {
            if (len == N)
                b[i] = a[i * 2 - 1] + ((i * 2 > len) ? 0 : a[i * 2]);
            else
                b[i] = b[i * 2 - 1] + ((i * 2 > len) ? 0 : b[i * 2]);
        }
        len = (len + 1) / 2;
    }
    return ans;
}

int main() {
    for (int i = 1;i <= N;i++)
        a[i] = (long long)(i);

    long long startTime, endTime, Freq;
    QueryPerformanceFrequency((LARGE_INTEGER*)&Freq);
    QueryPerformanceCounter((LARGE_INTEGER*)&startTime);
    long long ans = 0;
    for (int it = 1;it <= IT;it++)
        ans = sum();
    QueryPerformanceCounter((LARGE_INTEGER*)&endTime);
    cout << "Sum: " << ans << endl;
    cout << std::fixed << setprecision(2) << "Total Time: \t" << (double)(endTime - startTime) * 1000.0 / Freq << " ms" << endl;
    cout << std::fixed << setprecision(4) << "Avg Time:   \t" << (double)(endTime - startTime) * 1000.0 / (1.0 * IT * Freq) << " ms" << endl;
    return 0;
}