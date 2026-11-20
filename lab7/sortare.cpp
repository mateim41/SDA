#include <iostream>
#include <vector>
#include <algorithm>
#include <exception>

template <typename T>
class SortMethods
{
private:
    int Instances = 0;

public:
    SortMethods() { Instances = 1; }
    void MakeSortMethods()
    {
        if (Instances < 1)
            SortMethods();
        else
            throw std::exception();
    }

    void swap(T *&arr, const int &index1, const int &index2) const
    {
        T aux = arr[index1];
        arr[index1] = arr[index2];
        arr[index2] = aux;
    }

    void BubbleSort(T *&arr, int n)
    {
        bool swapped = true;
        while (swapped)
        {
            swapped = false;
            for (int i = 0; i < n - 1; i++)
            {
                if (arr[i] > arr[i + 1])
                {
                    swapped = true;
                    swap(arr, i, i + 1);
                }
            }
        }
    }

    void SelectionSort(T *&arr, int n)
    {
        for (int i = 0; i < n - 1; i++)
        {
            int k = i;
            for (int j = i + 1; j < n; j++)
            {
                if (arr[j] > arr[k])
                    k = j;
            }
            swap(arr, i, k);
        }
    }

    void InsertionSort(T *&arr, int n)
    {
        for (int i = 1; i < n; i++)
        {
            T temp = arr[i];
            int j = i - 1;
            while (arr[j] > temp && j >= 0)
            {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = temp;
        }
    }

    // Standard sequence
    // Other sequences offer better complexity
    void ShellSort(T *&arr, int n)
    {
        for (int gap = n / 2; gap > 0; gap /= 2)
        {
            for (int i = gap; i < n; i++)
            {
                T temp = arr[i];
                int j = i;
                while (arr[j - gap] > temp && j >= gap)
                {
                    arr[j] = arr[j - gap];
                    j -= gap;
                }
                arr[j] = temp;
            }
        }
    }

    void Merge(std::vector<T> &arr, int left, int mid, int right)
    {
        int n1 = mid - left + 1;
        int n2 = right - mid;

        std::vector<T> leftArr(n1);
        std::vector<T> rightArr(n2);
        int i = 0, j = 0;

        for (int i = 0; i < n1; i++)
        {
            leftArr[i] = arr[left + i];
        }
        for (int i = 0; i < n2; i++)
        {
            rightArr[i] = arr[right + j];
        }

        i = 0;
        j = 0;
        int k = left;
        while (i < n1 && j < n2)
        {
            if (leftArr[i] > rightArr[j])
            {
                arr[k++] = rightArr[j++];
            }
            else
                arr[k++] = leftArr[i++];
        }
        while (i < n1)
            arr[k++] = leftArr[i++];
        while (j < n2)
            arr[k++] = rightArr[j++];
    }
    void MergeSort(std::vector<T> &arr, int left, int right)
    {
        if (left > right)
            return;
        int mid = left + (right - left) / 2;
        MergeSort(arr, left, mid);
        MergeSort(arr, right, mid + 1);
        Merge(arr, left, mid, right);
    }
};