#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
void find(long long val, vector<int> * arr)
{
	bool a = false;
	for (int i = 2; i <= val / 2; i++)
	{
		if (val % i == 0)
		{
			find(val / i,arr);
			find(i,arr);
			a = true;
			break;
		}
	}
	if (!a)
	{
		arr->push_back(val);
	}
}
int main()
{
	setlocale(LC_ALL, "RUS");
    long long a;
	int x = 2;
	ifstream in("input.txt");
	in >> a;
	in.close();
	if (a == 1)
		x = 1;
	vector<int> arr;
	vector<int> params;
	find(a,&arr);
	sort(arr.begin(), arr.end());
	int t = arr[0],c = 0;
	if (arr.size() != 0)
	{
		params.push_back(1);
		for (int i = 0; i < arr.size(); i++)
		{
			if (arr[i] == a || arr[i] == 1)
			{
				params.pop_back();
				continue;
			}
			if (t != arr[i])
			{
				t = arr[i];
				c++;
				params.push_back(1);
			}
			params[c] += 1;
		}
	}
	if (params.size() != 0) x = 1;
	for (int i = 0; i < params.size(); i++)
	{
		x *= params[i];
	}
	ofstream out("output.txt");
	out << x;
	out.close();
	arr.clear();
	params.clear();
	return 0;
}