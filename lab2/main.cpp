#include <iostream>
#include <chrono>

void BubbleSort(int *a, int n);
void SelectionSort(int *a, int n);
template <typename T>
void InsertionSort(T *a, int n);
bool BruteForceSearch(int *a, int n, int elem);
bool BinarySearch(int *a, int n, int elem);
bool BinarySearchRecursive(int *a, int elem, int st, int dr);

void pb1()
{
    int n = 100000;
    int *a = new int[n];
    for (int i = 0; i < n; i++)
    {
        a[i] = rand() % 100 + 1;
    }
    auto start = std::chrono::system_clock::now();

    // BubbleSort(a,n);
    // SelectionSort(a,n);
    InsertionSort(a, n);

    auto end = std::chrono::system_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() << " ns\n";

    // for (int i = 0; i < n; i++)
    // {
    //     std::cout << a[i] << " ";
    // }

    delete a;
    a = nullptr;
}
void pb2()
{
    double *vect = new double[]{5, -3.2, 1.25, 7.69, 4.21, -6.29, 11.2, 3.57, 9.99, -10.87, -2.69};
    int n = 11; // sizeof(vect) / sizeof(double);
    // InsertionSort(vect, n);
    double smax = 0;
    for (int i = 0; i < n; i++)
        std::cout << vect[i] << " ";
    std::cout << "\n";
    for (int i = 0; i < n - 1; i++)
    {
        double s = vect[i];
        for (int j = i + 1; j < n; j++)
        {
            s += vect[j];
            if (s > smax)
                smax = s;
        }
    }
    std::cout << smax << "\n";

    delete vect;
    vect = nullptr;
    return 0;
}
int main()
{
    // pb1();
    pb2();
}

void BubbleSort(int *a, int n)
{
    int nrOperatii = 0;
    bool swapped = true;
    int j = 0;
    while (swapped)
    {
        swapped = false;
        ++j;
        for (int i = 0; i < n - j; i++)
        {
            if (a[i] > a[i + 1])
            {
                int tmp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = tmp;
                swapped = true;
                nrOperatii++;
            }
        }
    }
}

void swapA(int *a, int idx1, int idx2)
{
    auto temp = a[idx1];
    a[idx1] = a[idx2];
    a[idx2] = temp;
}
void SelectionSort(int *a, int n)
{
    int nrOperatii = 0;
    int i, j, m;
    for (int i = 0; i < n - 1; i++)
    {
        m = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[m])
                m = j;
            nrOperatii++;
        }
        nrOperatii++;
        swapA(a, i, m);
    }
}
template <typename T>
void InsertionSort(T *a, int n)
{
    int nrOperatii = 0;
    for (int k = 1; k < n; k++)
    {
        auto temp = a[k];
        int i = k - 1;
        while (a[i] > temp && i >= 0)
        {
            a[i + 1] = a[i];
            i--;
            nrOperatii++;
        }
        nrOperatii++;
        a[i + 1] = temp;
    }
}

// Cautare

bool BruteForceSearch(int *a, int n, int elem)
{
    int nrOperatii = 0;
    int i = 0;
    while (i < n)
    {
        if (a[i] == elem)
            return true;
        ++i;
        nrOperatii++;
    }
    return false;
}

bool BinarySearch(int *a, int n, int elem)
{
    int nrOperatii = 0;
    int st = 0, dr = n - 1;
    while (st <= dr)
    {
        int m = (st + dr) / 2;
        if (a[m] == elem)
            return true;
        if (a[m] > elem)
            dr = m - 1;
        else if (a[m] < elem)
            st = m + 1;
        nrOperatii++;
    }
    return false;
}

bool BinarySearchRecursive(int *a, int elem, int st, int dr)
{
    int m = (st + dr) / 2;
    if (a[m] == elem)
        return true;
    if (a[m] > elem)
        return BinarySearchRecursive(a, elem, m + 1, st);
    else
        return BinarySearchRecursive(a, elem, st, m - 1);
}