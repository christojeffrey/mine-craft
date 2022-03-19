#include <bits/stdc++.h>
using namespace std;
#define MAX_CAP 9

string get_cid(int idx) {
    // Get c_id from a index
    char num = idx + '0';
    string res = "C";
    res.push_back(num);
    return res;
};

int get_idx(string c_id) {
    int res = c_id[1] - '0';
    return res;
};

bool isCIDValid(string c_id) {
    int idx = get_idx(c_id);
    return (idx >= 0 && idx < MAX_CAP);
};


bool isSubArray(vector<string> A, vector<string> B, int n, int m) {
    // to check if B is subarray of A
    int i = 0, j = 0;
    while (i < n && j < m) {
        if (A[i] == B[j]) {
            i++;
            j++;
            if (j == m)
                return true;
        }
        else {
            i = i - j + 1;
            j = 0;
        }
    }
    return false;
}

vector<string> reflectYTable(vector<string> table) {
    swap(table[0], table[2]);
    swap(table[3], table[5]);
    swap(table[6], table[8]);
    return table;
}