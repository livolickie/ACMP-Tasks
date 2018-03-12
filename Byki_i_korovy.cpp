#include <fstream>
using namespace std;
int main()
{
	int a, b, x = 0, y = 0,a1,b1,i,j;
	ifstream in("input.txt");
	in >> a1 >> b1;
	in.close();
	a = a1;
	b = b1;
	for (i = 0; i < 4; i++)
	{
		if (a % 10 == b % 10)
			x++;
		a = a / 10;
		b = b / 10;
	}
	a = a1;
	for (i = 0; i < 4; i++)
	{
		b = b1;
		for (j = 0; j < 4; j++)
		{
			if (a % 10 == b % 10 && i == j) break;
			if (a % 10 == b % 10) y++;
			b = b / 10;
		}
		a = a / 10;
	}
	ofstream out("output.txt");
	out << x << " " << y;
	out.close();
	return 0;
}