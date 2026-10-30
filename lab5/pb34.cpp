#include <iostream>
#include <string>
#include <cstring>
#include "StivaDinamic.hpp"

bool IsOperand(char &c)
{
    if (strchr("+-*/()", c))
        return true;
    return false;
}

int Priority(const char &c)
{
    if (c == '(' || c == ')')
        return 0;
    if (c == '+' || c == '-')
        return 1;
    if (c == '*' || c == '/')
        return 2;
    return -1;
}

std::string ConvertExpressionPostFixed(std::string expresie)
{
    std::string convertedExpression = std::string();
    StivaDinamic<char> *s = nullptr;

    for (auto &&c : expresie)
    {
        if (!strchr(" ", c))
        {
            if (!IsOperand(c))
            {
                convertedExpression = convertedExpression + " " + c;
            }
            else
            {
                while (!IsEmpty(s) && Priority(c) <= Priority(Top(s)))
                {
                    convertedExpression = convertedExpression + " " + Top(s);
                    Pop(s);
                }
                Push(s, c);
            }
        }
    }
    while (!IsEmpty(s))
    {
        convertedExpression = convertedExpression + " " + Top(s);
        Pop(s);
    }

    return convertedExpression.substr(1);
}

int CalculateExpression(std::string expresie)
{
    std::string convExpr = ConvertExpressionPostFixed(expresie);
    int result = 0;
    StivaDinamic<int> *s = nullptr; // s - tine operanzii

    for (auto &&c : convExpr)
    {
        if (!strchr(" ", c))
        {
            if (!IsOperand(c))
            {
            }
        }
    }
}

int main()
{
    // 1 + 2 * 3 - 21 - 5 + 11 * 12 / 3 + 32
    std::string expresie = "1 + 2 * 3 - 4 - 5 + 9 * 8 / 3 + 2";
    // std::getline(std::cin, expresie);
    // expresie = ConvertExpressionPostFixed(expresie);
    // std::cout << expresie << "\n";
    

    return 0;
}