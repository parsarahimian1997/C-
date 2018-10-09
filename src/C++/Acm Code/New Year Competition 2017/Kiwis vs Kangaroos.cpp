#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	int kiwi = 0, kangaroo = 0, z;
	string s;
	getline(cin >> ws, s);
	z = s.size();
	for (int i = 0; i < z; i++)
		switch (s[i])
		{
		case 'a':	kangaroo += 2;	break;
		case 'b':	kiwi++;	break;
		case 'd':	kiwi++;	break;
		case 'g':	kangaroo++;	break;
		case 'i':	kiwi += 3;	break;
		case 'k':	kiwi++;	kangaroo++;	break;
		case 'n':	kangaroo++;	break;
		case 'o':	kangaroo += 2;	break;
		case 'r':	kangaroo++;	kiwi++;	break;
		case 'w':	kiwi++; break;
		case 'A':	kangaroo += 2;	break;
		case 'B':	kiwi++;	break;
		case 'D':	kiwi++;	break;
		case 'G':	kangaroo++;	break;
		case 'I':	kiwi += 3;	break;
		case 'K':	kiwi++;	kangaroo++;	break;
		case 'N':	kangaroo++;	break;
		case 'O':	kangaroo += 2;	break;
		case 'R':	kangaroo++;	kiwi++;	break;
		case 'W':	kiwi++; break;
		}
	if (kangaroo>kiwi)
		printf("Kangaroos\n");
	else if (kangaroo<kiwi)
		printf("Kiwis\n");
	else
		printf("Feud continues\n");
	return 0;
}