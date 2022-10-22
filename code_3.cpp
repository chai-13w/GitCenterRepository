#include<iostream>
#include<stdlib.h>
#include<Windows.h>
#include<ctime>
using namespace std;


void QuickSort(int arr[], int low,int high)
{
    int i, j, Key;
    i = low;
    j = high;
    Key = *(arr + low);
    while (high > low)
    {
        while ((high > low) && (*(arr + high) >= Key))
            high--;
        if (high > low)
        {
            *(arr + low) = *(arr + high);
            low++;
        }
        else break;

        while ((high > low) && (*(arr + low) <= Key))
            low++;
        if (high > low)
        {
            *(arr + high) = *(arr + low);
        }
    }
    *(arr + low) = Key;
    if (i < low - 1)
        QuickSort(arr,i, low - 1);
    if (high + 1 < j)
        QuickSort(arr,high + 1, j);
}


int* SetValue(int N)
{
    int* _arr;
    _arr = new int[N];
    srand((unsigned)time(NULL)); //提供新的种子
    for (int i = 0; i < N; i++)
        *(_arr + i) = rand();
    return _arr;
}

int main()
{
    int N;
    int* arr;
    LARGE_INTEGER litmp;
    LONGLONG t1, t2;
    double dft, dff, dfm;
    double sum = 0, ave;

    cout << "----------快速排序-----------" << endl;
    cout << endl;
    cout << "请输入待排序数组的规模大小：";
    cin >> N;
    for (int i = 1; i <= 20; i++)
    {
        arr = new int[N];
        arr = SetValue(N);

        QueryPerformanceFrequency(&litmp);
        dff = (double)litmp.QuadPart;
        QueryPerformanceCounter(&litmp);
        t1 = litmp.QuadPart;
        QuickSort(arr, 0, N - 1);
        QueryPerformanceCounter(&litmp);
        t2 = litmp.QuadPart;
        dfm = (double)(t2 - t1);
        dft = dfm / dff;
        sum = sum + dft;
        if (i <= 9)
            cout << "第0" << i << "次运行时间为：" << dft << "s" << endl;
        else
            cout << "第" << i << "次运行时间为：" << dft << "s" << endl;

    }
    ave = sum / 20;
    cout << "20次排序的平均运行时间为：" << ave << "s" << endl;
    cout << endl;
    cout << "----------快速排序-----------" << endl;

    cout << "Insert a statement here for later testing" << endl;
    cout << "Added the first change" << endl;
    cout << "Added the second change" << endl;
    return 0;
}