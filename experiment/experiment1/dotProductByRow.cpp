#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <iomanip>


using namespace std;

const int IT = 20;
const int N = 5000;

long long mat[N + 5][N + 5], vec[N + 5], sum[N + 5];

int main() {
    for (int i = 1;i <= N;i++) {
        vec[i] = i;
        for (int j = 1;j <= N;j++)
            mat[i][j] = i + j;
    }

    long long startTime, endTime, Freq;
    QueryPerformanceFrequency((LARGE_INTEGER*)&Freq);
    QueryPerformanceCounter((LARGE_INTEGER*)&startTime);

    for (int iter = 1;iter <= IT;iter++) {
        for (int i = 1;i <= N;i++) sum[i] = 0;
        for (int r = 1;r <= N;r++)
            for (int c = 1;c <= N;c++)
                sum[c] += mat[r][c] * vec[c];
    }

    QueryPerformanceCounter((LARGE_INTEGER*)&endTime);

    cout << std::fixed << setprecision(2) << "Total Time: \t" << (double)(endTime - startTime) * 1000.0 / Freq << " ms" << endl;
    cout << std::fixed << setprecision(4) << "Avg Time:   \t" << (double)(endTime - startTime) * 1000.0 / (1.0 * IT * Freq) << " ms" << endl;
    return 0;
}