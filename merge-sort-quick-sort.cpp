/** \link
 * \comments 熟悉一下归并排序和快速排序
 */

#include <iostream>
#include <vector>
#include <stack>
using namespace std;
void MergeArray(vector<int> &a, vector<int> &b, int begin, int mid, int end);
void MergeSort(vector<int> &a, vector<int> &b, int begin, int end)
{
    if (begin < end){
        int mid = (begin + end) >> 1;
        MergeSort(a, b, begin, mid);
        MergeSort(a, b, mid + 1, end);
        MergeArray(a, b, begin, mid, end);
    }
}

void MergeArray(vector<int> &a, vector<int> &b, int begin, int mid, int end)
{
    int i = begin, j = mid;
    int m = mid + 1, n = end;
    int k = begin;
    while (i <= j && m <= n){
        if (a[i] < a[m])
            b[k++] = a[i++];
        else
            b[k++] = a[m++];
    }
    while (i <= j){
        b[k++] = a[i++];
    }
    while (m <= n){
        b[k++] = a[m++];
    }
    while (begin <= end){
        a[begin] = b[begin];
        begin++;
    }
}

void QSort(vector<int> &a, int begin, int end)
{
    int i = begin, j = end, mid = (begin + end) >> 1;
    while (i <= j){
        while (a[i] < a[mid]) i++;
        while (a[j] > a[mid]) j--;
        if (i <= j){
            int tmp = a[i];
            a[i] = a[j];
            a[j] = tmp;
            i++;
            j--;
        }
    }
    if (begin < j)
        QSort(a, begin, j);
    if (i < end)
        QSort(a, i, end);
}

void QSortNoRecursion(vector<int> &a, int begin, int end)
{
    stack<pair<int, int> > myStack;
    int i, j, mid, b, e;
    myStack.push(make_pair(begin, end));
    while (!myStack.empty()){
        b = i = myStack.top().first;
        e = j = myStack.top().second;
        mid = (i + j) >> 1;
        myStack.pop();
        while (i <= j){
            while (a[i] < a[mid]) i++;
            while (a[j] > a[mid]) j--;
            if (i <= j){
                int tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
                i++;
                j--;
            }
        }
        if (b < j) myStack.push(make_pair(b, j));
        if (i < e) myStack.push(make_pair(i, e));
    }
}

int main(void)
{
    int n, c;
    vector<int> a;
    vector<int> b;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> c;
        a.push_back(c);
        b.push_back(c);
    }
    //MergeSort(a, b, 0, n - 1);
    //QSort(a, 0, n - 1);
    QSortNoRecursion(a, 0, n - 1);
    for (int i = 0; i < n; i++){
        cout << a[i] << ' ';
    }
    return 0;
}
