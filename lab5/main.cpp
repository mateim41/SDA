#include <iostream>
#include <string>
#include <cstring>
#include "StivaStatic.hpp"
#include "StivaDinamic.hpp"

void pb1()
{
    StivaStatic s;
    Init(s);

    int x = -1;
    std::cout << "Introdu x sau 0 pentru a iesi: ";
    std::cin >> x;
    while (x)
    {
        Push(s, x);
        std::cout << "Introdu x sau 0 pentru a iesi: ";
        std::cin >> x;
    }
    Pop(s);
    Pop(s);
    std::cout << Top(s) << "\n";

    Display(s);
}

void pb2()
{
}

bool IsOperand(const char &c)
{
    if (strchr("+-*/()", c))
        return true;
    return false;
}

int priority(const char &c)
{
    if (c == '(' || c == ')')
        return 0;
    if (c == '+' || c == '-')
        return 1;
    if (c == '*' || c == '/')
        return 2;
    return -1;
}

std::string ConvertExpression(std::string expresie)
{
    std::string exprs = std::string();
    StivaDinamic<char> *s = nullptr;

    for (auto &&i : expresie)
    {
        if (i == '(')
            Push(s, i);
        else if (!IsOperand(i))
        {
            exprs += i;
        }
        else
        {
            while (!IsEmpty(s) && priority(i) <= priority(Top(s)))
            {
                if (Top(s) != '(')
                    exprs += Top(s);
                Pop(s);
            }
            if (i != ')')
                Push(s, i);
        }
    }
    while (!IsEmpty(s))
    {
        exprs += Top(s);
        Pop(s);
    }
    return exprs;
}

void pb3()
{
    std::string expresie = "1+2*3-4-5+9*8/3+2"; // 123+*5*3+
    // std::cout << "Introduceti o expresie matematica: ";
    // std::getline(std::cin, expresie);
    std::string exprs = ConvertExpression(expresie);

    std::cout << exprs << "\n";
}

// int main()
// {
//     // pb1();
//     pb3();

//     return 0;
// }