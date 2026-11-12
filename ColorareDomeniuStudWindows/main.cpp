#pragma comment(lib, "user32.lib")
#pragma comment(lib, "gdi32.lib")
#pragma comment(lib, "shell32.lib")

#include "Queue.hpp"
#include <iostream>
#include "CImg.h"
#include <queue>  // Pentru coada BFS
#include <chrono> // Pentru a implementa o intarziere
#include <thread> // Pentru sleep_for
#include <array>

using namespace std;
using namespace cimg_library;
using namespace std::chrono;

struct Pozitie
{
    int x, y;

    bool operator==(const Pozitie &p) const = default;
    friend Pozitie operator+(const Pozitie &p1, const Pozitie &p2)
    {
        Pozitie temp = {temp.x = p1.x + p2.x, temp.y = p1.y + p2.y};
        return temp;
    }
};

Pozitie directii[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

array<Pozitie, 4> GetNeighbours(CImg<unsigned char> &in, const Pozitie &pixelCurent)
{
    array<Pozitie, 4> temp;

    if (pixelCurent.x == 0 && pixelCurent.y == 0)
    {
        temp = {pixelCurent + directii[2], pixelCurent + directii[3], {-1, -1}, {-1, -1}};
    }
    else if (pixelCurent.x == 0 && pixelCurent.y == in.height() - 1)
    {
        temp = {pixelCurent + directii[0], pixelCurent + directii[3], {-1, -1}, {-1, -1}};
    }
    else if (pixelCurent.x == in.width() - 1 && pixelCurent.y == 0)
    {
        temp = {pixelCurent + directii[1], pixelCurent + directii[2], {-1, -1}, {-1, -1}};
    }
    else if (pixelCurent.x == in.width() - 1 && pixelCurent.y == in.height() - 1)
    {
        temp = {pixelCurent + directii[0], pixelCurent + directii[1], {-1, -1}, {-1, -1}};
    }

    temp = {pixelCurent + directii[0], pixelCurent + directii[1],
            pixelCurent + directii[2], pixelCurent + directii[3]};

    return temp;
}

CImg<unsigned char> ColoreazaDomeniu(CImg<unsigned char> &in, Pozitie init, unsigned char colour, CImgDisplay &dispOut)
{
    CImg<unsigned char> imgOut = in; // imgOut este o copie a lui in

    // dimensiunile imaginii
    int width = in.width();
    int height = in.height();

    unsigned char culoareDomeniu = in(init.x, init.y); // obtinem valoarea pixelului de la pozitia initiala
    cout << "Color: " << (unsigned int)culoareDomeniu << "( " << init.x << ", " << init.y << ")" << endl;

    //... adaugati logica aplicatiei aici
    // afisati imaginea dupa fiecare pas pentru a vedea cum se modifica culoarea domeniului in timp real

    Queue<Pozitie> Queue;
    Queue.Enqueue(init);
    in(init.x, init.y) = colour;
    while (!Queue.IsEmpty())
    {
        Pozitie pixelCurent = Queue.Dequeue();

        auto vecini = GetNeighbours(in, pixelCurent);
        for (int i = 0; i < 4; i++)
        {
            if (vecini[i] == Pozitie{-1, -1})
                break;
            if (in(vecini[i].x, vecini[i].y) == culoareDomeniu)
            {
                in(vecini[i].x, vecini[i].y) = colour;
                Queue.Enqueue(vecini[i]);
            }
        }
        // if (vecini[2] != Pozitie{-1, -1})
        // {
        //     for (int i = 0; i < 4; i++)
        //     {
        //         if (in(vecini[i].x, vecini[i].y) == culoareDomeniu)
        //         {
        //             in(vecini[i].x, vecini[i].y) = colour;
        //             Queue.Enqueue(vecini[i]);
        //         }
        //     }
        // }
        // else
        // {
        //     for (int i = 0; i < 2; i++)
        //     {
        //         if (in(vecini[i].x, vecini[i].y) == culoareDomeniu)
        //         {
        //             in(vecini[i].x, vecini[i].y) = colour;
        //             Queue.Enqueue(vecini[i]);
        //         }
        //     }
        // }
    }
    in.display();

    cout << "DONE!" << endl;
    return imgOut;
}

int main()
{
    CImg<unsigned char> imgIn("C:\\Users\\matei\\Documents\\VSCode\\SDA\\ColorareDomeniuStudWindows\\img.bmp"); // Incarca imaginea, de specificat calea completa

    // Creati o fereastra pentru a vizualiza imaginile
    CImgDisplay dispIn(imgIn, "Input");
    CImgDisplay dispOut;

    Pozitie posInit;
    posInit.x = imgIn.width() / 2;
    posInit.y = imgIn.height() / 2;

    // imgIn este o imagine grayscale (fiecare pixel este reprezentat de o valoare pe 8 biti, in [0,255])
    CImg<unsigned char> imgOut = ColoreazaDomeniu(imgIn, posInit, (unsigned char)12, dispOut);

    // Afisarea imaginilor
    dispOut = CImgDisplay(imgOut, "Output");

    // Asteptam ca utilizatorul sa inchida fereastra
    while (!dispIn.is_closed() && !dispOut.is_closed())
    {
        dispIn.wait();
        dispOut.wait();
    }

    return 0;
}
