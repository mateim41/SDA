#include <iostream>
#include <vector>
#include <array>
#include <list>
#include <fstream>
#include <string>

using namespace std;

struct Pozitie
{
    int x, y;
    bool operator==(const Pozitie &p2) const = default;
    Pozitie operator+(const Pozitie &p2) const
    {
        return Pozitie{x + p2.x, y + p2.y};
    }
};
enum Tile
{
    Free,
    Wall,
    Init,
    End
};

array<Pozitie, 4> dir = {{Pozitie{-1, 0},
                          Pozitie{0, 1},
                          Pozitie{1, 0},
                          Pozitie{0, -1}}};

void CautaDrum(Tile matr[1000][1000], Pozitie &init, list<Pozitie> &s)
{
    static bool reachedEnd = false;
    if (!reachedEnd)
    {
        for (int i = 0; i < 4; i++)
        {
            Pozitie curent = init + dir[i]; // curent - vecinul punctului pe care lucrez
            if (matr[curent.x][curent.y] == Free)
            {
                matr[curent.x][curent.y] = Wall;
                s.push_back(curent);
                CautaDrum(matr, curent, s);
            }
            if (matr[curent.x][curent.y] == End)
            {
                s.push_back(curent);
                for (auto &&i : s)
                {
                    cout << "(" << i.x + 1 << ", " << i.y + 1 << ") ";
                }
            }
        }
        if (!s.empty())
            s.pop_back();
    }
}

int main()
{
    ifstream fin("intrare.txt");
    int n, m;
    fin >> n >> m; // reads everything until a whitespace ' '
    string discard = "";
    getline(fin, discard); // reads the whole line
    fin>>discard;
    fin>>discard;

    // Tile matr[1000][1000] = {
    //     {Wall, Wall, Wall, Wall, Wall, Wall, Wall, Wall, Wall},
    //     {Wall, Free, Free, Free, Free, Free, Wall, Free, Wall},
    //     {Wall, Wall, Wall, Init, Wall, Wall, Wall, Free, Wall},
    //     {Wall, Free, Free, Free, Free, Free, Wall, End, Wall},
    //     {Wall, Wall, Wall, Free, Wall, Free, Free, Free, Wall},
    //     {Wall, Wall, Wall, Wall, Wall, Wall, Wall, Wall, Wall}};
    // list<Pozitie> l;
    // Pozitie init = {2, 3};
    // l.push_back(init);
    // CautaDrum(matr, init, l);

    return 0;
}