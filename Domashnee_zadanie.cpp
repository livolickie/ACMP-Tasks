#include <fstream>
using namespace std;
int main()
{
	int n,sum = 0,sum1 = 0,maxI,minI,i;
	short max = -32000, min = sizeof(short);
	ifstream in("input.txt");
	in >> n;
	short * a = new short[n];
	for (i = 0; i < n; i++)
	{
		in >> a[i];
		if (a[i] > 0)
			sum += a[i];
		if (a[i] > max)
		{
			maxI = i;
			max = a[i];
		}
		if (a[i] < min)
		{
			minI = i;
			min = a[i];
		}
	}
	if (minI > maxI)
	{
		maxI = maxI + minI;
		minI = maxI - minI;
		maxI = maxI - minI;
	}
	sum1 = a[minI + 1];
	for (i = minI + 2; i < maxI; i++)
	{
		sum1 = sum1 * a[i];
	}
	in.close();
	ofstream out("output.txt");
	out << sum << " " << sum1;
	out.close();
	delete[] a;
	return 0;
}