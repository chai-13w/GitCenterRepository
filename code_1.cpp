#include<iostream>
#include<stdlib.h>
#include<Windows.h>
#include<ctime>
using namespace std;

void InsertSort(int arr[], int N)
{
    int i, j, temp;
    for (i = 1; i < N; i++)
    {
        temp = arr[i];
        for (j = i - 1; j >= 0; j--)
        {
            if (temp < arr[j])
                arr[j + 1] = arr[j];
            else break;
        }
        arr[j + 1] = temp;
    }
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

    cout << "----------插入排序-----------" << endl;
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
        InsertSort(arr, N);
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
    cout << "----------插入排序-----------" << endl;
    return 0;
}