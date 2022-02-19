#include <iostream>
#include <fstream>
 
using namespace std;
 
int main() {
    ifstream in("knapsack.in");
    ofstream out("knapsack.out");
    int S, N;
    in >> S >> N;
    int weight[N+1];
    int A[N+1][S+1];
    for (int i = 1; i <= N; i++) in >> weight[i];
    for (int i = 0; i <= S; i++) A[0][i] = 0;
    for (int i = 0; i <= N; i++) A[i][0] = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= S; j++) {
            if (S >= weight[i] && j - weight[i] >= 0) {
                A[i][j] = max(A[i - 1][j], A[i - 1][j - weight[i]] + weight[i]);
            }
            else
                A[i][j] = A[i - 1][j];
        }
    }
    out << A[N][S];
    return 0;
}
