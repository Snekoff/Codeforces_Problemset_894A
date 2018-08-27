#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <malloc.h>



using namespace std;
int maxQAQ = 0;
bool v[100] = { false };

int dp_serach(int k, char* A,int n, bool st, bool midd) { // k - index , n - size of A
    if (st) {
        if (midd) {
            for (int h = k; h < n; h++) {
                if (A[h] == 'Q') {
                    maxQAQ++;
                }
            }
            return maxQAQ;
        }
        else {
            for (int i = k; i < n; i++) {
                if (A[i] == 'A') {
                    if (i < n - 1) {
                        int b = dp_serach(i + 1, A, n, true, true);
                    }
                    else return maxQAQ;
                }
            }
            return maxQAQ;
        }
    }
    else {
        for (int i = k; i < n; i++) {
            if (A[i] == 'Q' && !v[i]) {
                v[i] = true;
                if (i < n - 1) {
                    int b = dp_serach(i + 1, A, n, true, false);
                }
                else return maxQAQ;
            }
        }
        return 0;
    }

}

int main() {
    int starting = 0, middle = 0, ending = 0;
    char A[100];
    int n = 100;
    scanf("%s",A);
    for (int i = 0; i < 100; i++) {
        if ((int)A[i] > (int)'Z' || (int)'A' > (int)A[i]) {
            n = i;
            break;
        }
    }
    int b = dp_serach(0, A, n, false, false);
    printf("%d",maxQAQ);
    return 0;
}
