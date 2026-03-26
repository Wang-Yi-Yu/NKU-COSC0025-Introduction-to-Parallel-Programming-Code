#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <iomanip>
using namespace std;

const int N = 1000000;
const int IT = 500;

int a[N];

long long sum(int l, int r) {
    if (l == r) return (long long)(a[l]);
    else if (l + 1 == r) return (long long)(a[l]) + (long long)(a[r]);
    int mid = (l + r) >> 1;
    return sum(l, mid) + sum(mid + 1, r);
}

int main() {
    for (int i = 1;i <= N;i++)
        a[i] = i;

    long long startTime, endTime, Freq;
    QueryPerformanceFrequency((LARGE_INTEGER*)&Freq);
    QueryPerformanceCounter((LARGE_INTEGER*)&startTime);
    long long ans = 0;
    for (int it = 1;it <= IT;it++) {
        ans = sum(1, N);
    }
    QueryPerformanceCounter((LARGE_INTEGER*)&endTime);
    cout << "Sum: " << ans << endl;
    cout << std::fixed << setprecision(2) << "Total Time: \t" << (double)(endTime - startTime) * 1000.0 / Freq << " ms" << endl;
    cout << std::fixed << setprecision(4) << "Avg Time:   \t" << (double)(endTime - startTime) * 1000.0 / (1.0 * IT * Freq) << " ms" << endl;
    return 0;
}