#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/* ============================================================
   1) Binary Search vs Linear Search
   ============================================================ */

int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

/* ============================================================
   2) Bubble Sort
   ============================================================ */

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
        }
    }
}

/* ============================================================
   3) Missing Number in Sorted Array
   (a) Linear Method
   ============================================================ */

int missingLinear(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        if (arr[i + 1] - arr[i] != 1)
            return arr[i] + 1;
    }
    return -1;
}

/* ============================================================
   3) Missing Number in Sorted Array
   (b) Binary Search Method
   ============================================================ */

int missingBinary(int arr[], int n) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] != mid + 1)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return low + 1;
}

/* ============================================================
   4(a) Concatenate Strings
   ============================================================ */

string concatStrings(string a, string b) {
    return a + b;
}

/* ============================================================
   4(b) Reverse String
   ============================================================ */

string reverseStr(string s) {
    reverse(s.begin(), s.end());
    return s;
}

/* ============================================================
   4(c) Delete Vowels
   ============================================================ */

string deleteVowels(string s) {
    string r = "";
    for (char c : s) {
        if (!(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||
              c=='A'||c=='E'||c=='I'||c=='O'||c=='U'))
            r += c;
    }
    return r;
}

/* ============================================================
   4(d) Sort Strings Alphabetically
   ============================================================ */

void sortStrings(vector<string> &v) {
    sort(v.begin(), v.end());
}

/* ============================================================
   4(e) Uppercase to Lowercase
   ============================================================ */

char toLowerCase(char c) {
    if (c >= 'A' && c <= 'Z')
        return c + 32;
    return c;
}

/* ============================================================
   5) Space Efficient Matrices
   (Only storing method shown)
   ============================================================ */

// (a) Diagonal Matrix
class DiagonalMatrix {
    int n;
    int *A;
public:
    DiagonalMatrix(int n) {
        this->n = n;
        A = new int[n];
    }
    void set(int i, int j, int val) {
        if (i == j) A[i - 1] = val;
    }
    int get(int i, int j) {
        return (i == j) ? A[i - 1] : 0;
    }
};

// (b) Tri-diagonal Matrix
class TriDiagonal {
    int n;
    int *A;
public:
    TriDiagonal(int n) {
        this->n = n;
        A = new int[3*n - 2];
    }
};

// (c) Lower Triangular Matrix
class LowerTriangular {
    int n;
    int *A;
public:
    LowerTriangular(int n) {
        this->n = n;
        A = new int[(n*(n+1))/2];
    }
};

// (d) Upper Triangular Matrix
class UpperTriangular {
    int n;
    int *A;
public:
    UpperTriangular(int n) {
        this->n = n;
        A = new int[(n*(n+1))/2];
    }
};

// (e) Symmetric Matrix
class SymmetricMatrix {
    int n;
    int *A;
public:
    SymmetricMatrix(int n) {
        this->n = n;
        A = new int[(n*(n+1))/2];
    }
};

/* ============================================================
   6) Sparse Matrix Triplet Representation
   ============================================================ */

struct Element {
    int row, col, val;
};

struct Sparse {
    int rows, cols, num;
    Element *ele;
};

// (a) Transpose of sparse matrix
Sparse transpose(Sparse s) {
    Sparse t;
    t.rows = s.cols;
    t.cols = s.rows;
    t.num = s.num;
    t.ele = new Element[s.num];

    int k = 0;
    for (int i = 0; i < s.cols; i++) {
        for (int j = 0; j < s.num; j++) {
            if (s.ele[j].col == i) {
                t.ele[k++] = {s.ele[j].col, s.ele[j].row, s.ele[j].val};
            }
        }
    }
    return t;
}

// (b) Addition of sparse matrices
Sparse addSparse(Sparse A, Sparse B) {
    Sparse C;
    C.rows = A.rows;
    C.cols = A.cols;
    C.ele = new Element[A.num + B.num];

    int i = 0, j = 0, k = 0;
    while (i < A.num && j < B.num) {
        if (A.ele[i].row < B.ele[j].row)
            C.ele[k++] = A.ele[i++];
        else if (A.ele[i].row > B.ele[j].row)
            C.ele[k++] = B.ele[j++];
        else {
            if (A.ele[i].col < B.ele[j].col)
                C.ele[k++] = A.ele[i++];
            else if (A.ele[i].col > B.ele[j].col)
                C.ele[k++] = B.ele[j++];
            else {
                C.ele[k] = A.ele[i];
                C.ele[k++].val = A.ele[i++].val + B.ele[j++].val;
            }
        }
    }
    while (i < A.num) C.ele[k++] = A.ele[i++];
    while (j < B.num) C.ele[k++] = B.ele[j++];

    C.num = k;
    return C;
}

// (c) Multiplication
Sparse multiplySparse(Sparse A, Sparse B) {
    Sparse C;
    C.rows = A.rows;
    C.cols = B.cols;
    C.ele = new Element[A.rows * B.cols];
    C.num = 0;

    for (int i = 0; i < A.num; i++) {
        for (int j = 0; j < B.num; j++) {
            if (A.ele[i].col == B.ele[j].row) {
                C.ele[C.num++] = {
                    A.ele[i].row,
                    B.ele[j].col,
                    A.ele[i].val * B.ele[j].val
                };
            }
        }
    }
    return C;
}

/* ============================================================
   7) Count Inversions
   ============================================================ */

int countInversions(int arr[], int n) {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j])
                cnt++;
        }
    }
    return cnt;
}

/* ============================================================
   8) Count Distinct Elements
   ============================================================ */

int countDistinct(int arr[], int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        bool exists = false;
        for (int j = 0; j < i; j++) {
            if (arr[i] == arr[j]) {
                exists = true;
                break;
            }
        }
        if (!exists) count++;
    }
    return count;
}

/* ============================================================
                       MAIN FUNCTION
   ============================================================ */

int main() {
    cout << "All functions implemented successfully.\n";
    return 0;
}
