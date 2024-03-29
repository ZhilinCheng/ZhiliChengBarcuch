#include <list>
#include <vector>
#include <map>
#include <iostream>
using namespace std;
// Sum of the elements in a container
template <typename T>
double Sum(const T& t)
{
	double sum = 0;
	typename T::const_iterator i;
	for (i = t.begin(); i != t.end(); i++)
	{
		sum += *i;
	}
	return sum;
}
// Sum of the elements in a map
template <typename T1, typename T2>
double Sum(const map<T1, T2>& t)
{
	typename map<T1, T2>::const_iterator i;
	double sum = 0;
	// Iterate the container
	for (i = t.begin(); i != t.end(); ++i)
	{
		sum += (i->second);
	}

	return sum;

}

// Sum between two iterators in a container 
template <typename T>
double Sum(const typename T::const_iterator& start, const typename T::const_iterator& end)
{
	double sum = 0;
	typename T::const_iterator i;
	// Iterate the container
	for (i = start; i != end; ++i)
	{
		sum += *i;
	}

	return sum;
}
// Sum between two iterators in a map 
template <typename T1, typename T2>
double Sum(const typename map<T1, T2>::const_iterator& start, const typename map<T1, T2>::const_iterator& end)
{
	double sum = 0;
	typename map<T1, T2>::const_iterator i;
	// Iterate the container
	for (i = start; i != end; ++i)
	{
		sum += i->second;
	}

	return sum;
}
int main()
{
	// Sum of a list
	list <double> list1;
	for (int i = 0; i < 2; i++)
	{
		list1.push_back(i + 1);
	}
	cout << Sum(list1) << endl;
	cout<<Sum<list<double>>(list1.begin(), list1.end()) << endl;
	// Sum of a vector
	vector<double> vector1(5);
	for (int i = 0; i < 10; i++)
	{
		vector1.push_back(i + 1);
	}
	cout << Sum(vector1) << endl;
	cout << Sum<vector<double>>(vector1.begin(), vector1.end()) << endl;
	// Sum of a map
	map<string, double> map1;
	string str[4] = { "0", "1", "2", "3" };

	for (int i = 0; i < 4; i++)
	{
		map1[str[i]] = i + 1;
	}
	cout << Sum(map1) << endl;
	cout<< Sum<string, double>(map1.begin(), map1.end()) << endl;


	getchar();
}