#include <fstream>
using namespace std;
int main()
{
	int n,i,j,x = 0;
	ifstream in("input.txt");
	in >> n;
	int ** a = new int * [n];
	for (i = 0; i < n; i++)
	{
		a[i] = new int[n];
		for (j = 0; j < n; j++)
			in >> a[i][j];
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (a[i][j] == 1)
				x++;
		}
	}
	x = x / 2;
	for (i = 0; i < n; i++) delete[] a[i];
	delete[] a;
	in.close();
	ofstream out("output.txt");
	out << x;
	out.close();
	return 0;
}