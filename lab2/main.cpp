#include <iostream>
#include <chrono>
#include <tuple>

void BubbleSort(int *a, int n);
void SelectionSort(int *a, int n);
template <typename T>
void InsertionSort(T *a, int n);
bool BruteForceSearch(int *a, int n, int elem);
bool BinarySearch(int *a, int n, int elem);
bool BinarySearchRecursive(int *a, int elem, int st, int dr);

int *CreateMatrix(int &nl, int &nc);
void DisplayElement(int *matr, int nl, int nc, int nrLin, int nrCol);
void DisplayMatrice(int *matr, int nrLin, int nrCol);
std::tuple<int, int> DetermineMaximumIndexes(int *matr, int nrLin, int nrCol);

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

    delete[] a;
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

    delete[] vect;
    vect = nullptr;
}
void pb3()
{
    int nl, nc;
    int *Matrice = CreateMatrix(nl, nc);
    /*
        1 2 3
        4 5 6
        7 8 9
    */
    int nrLinie, nrColoana;
    std::cout << "Introduceti linia : ";
    std::cin >> nrLinie;
    std::cout << "Introduceti coloana: ";
    std::cin >> nrColoana;
    DisplayElement(Matrice, nl, nc, nrLinie, nrColoana);
    std::cout << "\n";
    DisplayMatrice(Matrice, nl, nc);

    std::tuple<int, int> indiciValMaxima = DetermineMaximumIndexes(Matrice, nl, nc);
    int linie, coloana;
    std::tie(linie, coloana) = indiciValMaxima;
    std::cout << linie << " " << coloana << "\n";

    delete[] Matrice;
    Matrice = nullptr;
}

// vom presupune ca matricea este alocata dinamica intr-o zona continua de memorie
void pb4()
{
    int nl, nc;
    int *Matrice = CreateMatrix(nl, nc);
    


    delete[] Matrice;
    Matrice = nullptr;
}
int main()
{
    // pb1();
    // pb2();
    // pb3();
    pb4();

    return 0;
}

int *CreateMatrix(int &nl, int &nc)
{
    std::cout << "Introduceti nr linii: ";
    std::cin >> nl;
    std::cout << "Introduceti nr coloane: ";
    std::cin >> nc;

    int *Matrice = new int[nl * nc];
    std::cout << "Introduceti elementele matricei\n";
    int linCurenta = 0;
    for (int i = 0; i < nc; i++)
    {
        std::cin >> Matrice[linCurenta * nc + i];
        if (i == nc - 1)
        {
            linCurenta++;
            i = -1; // deoarece la finalul for-ului i-ul creste si il aduce inapoi la 0
            if (linCurenta == nl)
                break;
        }
    }
    return Matrice;
    // pointerul Matrice se distruge dupa terminarea functiei
    // daca as fi lasat signatura int *& as fi returnat o referinta
    // la un pointer care s-o distrus
}
void DisplayElement(int *matr, int nl, int nc, int nrLin, int nrCol)
{
    int linCurenta = 0;
    for (int i = 0; i < nc; i++)
    {
        if (linCurenta == nrLin && i == nrCol)
        {
            std::cout << matr[linCurenta * nc + i] << "\n";
            break;
        }
        if (i == nc - 1)
        {
            linCurenta++;
            i = 0;
        }
    }
}
void DisplayMatrice(int *matr, int nrLin, int nrCol)
{
    int linCurenta = 0;
    for (int i = 0; i < nrLin; i++)
    {
        std::cout << matr[linCurenta * nrCol + i] << " ";
        if (i == nrCol - 1)
        {
            i = -1;
            linCurenta++;
            std::cout << "\n";
            if (linCurenta == nrLin)
                break;
        }
    }
}
int DeterminaElemMax(int *matr, int nrLin, int nrCol)
{
    int max = 0;
    for (int i = 0; i < nrLin * nrCol; i++)
    {
        if (matr[i] > max)
            max = matr[i];
    }
    return max;
}
std::tuple<int, int> DetermineMaximumIndexes(int *matr, int nrLin, int nrCol)
{
    std::tuple<int, int> indiciValMaxima = std::make_tuple(0, 0);
    int linCurenta = 0;
    int max = DeterminaElemMax(matr, nrLin, nrCol);
    for (int i = 0; i < nrCol; i++)
    {
        if (matr[linCurenta * nrCol + i] == max)
        {
            std::get<0>(indiciValMaxima) = linCurenta;
            std::get<1>(indiciValMaxima) = i;
            break;
        }
        if (i == nrCol - 1)
        {
            linCurenta++;
            i = -1;
            // if (linCurenta == nrLin)
            //     break;
            // nu-i nevoie, deoarece inevitabil vom gasi elem maxim si vom iesi
        }
    }
    return indiciValMaxima;
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