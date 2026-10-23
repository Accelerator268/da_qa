#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int getMax(const std::vector<int>& a) {
    int mx = a[0];
    for (int i = 1; i < a.size(); i++) {
        if (a[i] > mx) {
            mx = a[i];
        };
    };
};

void CountingSort(vector<int>& a, int k) {
    vector<int> count(k+1, 0);

    for (int x : a) {
        count[x]++;
    };

    int i = 0;
    for (int v = 0; v <= k; v++) {
        for (int j = 0; j < count[v]; j++) {
            a[i++] = v;
        };
    };
};

void CountingSortByDigit(vector<int>& a, int exp) {
    vector<int> output(a.size());
    int count[10] = {0};

    for (int x : a) {
        count[(x / exp) % 10]++;
    };

    for (int i = 1; i < 10; i++) {
        count[i] += count[i-1];
    };

    for (int i = a.size() - 1; i >= 0; i--) {
        int d = (a[i] / exp) % 10;
        output[--count[d]] = a[i]; //т.к. в прошлом блоке сделали их стакающимися
    };

    a = output;
}

void radixSort(vector<int>& a) {
    if (a.empty()) {
        return;
    };
    int mx = getMax(a);

    for (int exp = 1; mx / exp > 0; exp *= 10) {
        CountingSortByDigit(a, exp);
    }
}

void bucketSort(vector<int>& a) {
    if (a.empty()) {
        return;
    }

    int n = a.size();
    vector<vector<int>> buckets(n);

    for (int x : a) {
        buckets[x*n].push_back(x);
    }
    
    a.clear();
    for (auto& b : buckets) {
        sort(b.begin(), b.end());
        for (int x : b) {
            a.push_back(x);
        };
    };
}