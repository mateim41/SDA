#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "BinaryTree.hpp"

static char car = 0;

static void eroare()
{
	printf("Sirul de intrare este eronat!\n");
	printf("Apasati tasta o tasta...");
	getchar();
	exit(1);
}

static char readchar()
{
	char c;
	do
	{
		c = getchar();
	} while (c == ' ');
	return c;
}

static char citesteNume()
{
	char c;
	if (!isalpha(car))
		eroare();
	c = car;
	car = readchar();
	return c;
}

static Node<char> *citesteArbore()
{
	Node<char> *rad;
	if (car == '-')
	{
		rad = 0;
		car = readchar();
	}
	else
	{
		rad = new Node<char>;
		rad->data = citesteNume();
		if (car != '(')
		{
			rad->st = nullptr;
			rad->dr = nullptr;
		}
		else
		{
			car = readchar();
			rad->st = citesteArbore();
			if (car != ',')
			{
				rad->dr = nullptr;
			}
			else
			{
				car = readchar();
				rad->dr = citesteArbore();
			}
			if (car != ')')
				eroare();
			car = readchar();
		}
	}
	return rad;
}

Node<char> *creareArbore()
{
	printf("Exemplu: A(B(-,C),D(E(F,-),G(H,-)))\n");
	printf("Introduceti arborele:");
	car = readchar();
	return citesteArbore();
}
