#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "binary_tree.hpp"

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

// static int citesteNume(int _)
// {
// 	int c;
// 	if (strchr("0123456789", car))
// 	{
// 		c = car - '0';
// 	}
// 	else
// 		eroare();
// 	car = readchar();
// 	return c;
// }

static Node *citesteArbore()
{
	Node *rad;
	if (car == '-')
	{
		rad = 0;
		car = readchar();
	}
	else
	{
		rad = new Node;
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

Node *creareArbore()
{
	printf("Exemplu: A(B(-,C),D(E(F,-),G(H,-)))\n");
	printf("Introduceti arborele:");
	car = readchar();
	return citesteArbore();
}

// pt int-uri

// static Node<int> *citesteArbore(int _)
// {
// 	Node<int> *rad;
// 	if (car == '-')
// 	{
// 		rad = 0;
// 		car = readchar();
// 	}
// 	else
// 	{
// 		rad = new Node<int>;
// 		rad->data = citesteNume(_);
// 		if (car != '(')
// 		{
// 			rad->st = nullptr;
// 			rad->dr = nullptr;
// 		}
// 		else
// 		{
// 			car = readchar();
// 			rad->st = citesteArbore(_);
// 			if (car != ',')
// 			{
// 				rad->dr = nullptr;
// 			}
// 			else
// 			{
// 				car = readchar();
// 				rad->dr = citesteArbore(_);
// 			}
// 			if (car != ')')
// 				eroare();
// 			car = readchar();
// 		}
// 	}
// 	return rad;
// }

// Node<int> *creareArbore(int _)
// {
// 	printf("Exemplu: A(B(-,C),D(E(F,-),G(H,-)))\n");
// 	printf("Introduceti arborele:");
// 	car = readchar();
// 	return citesteArbore(_);
// }
