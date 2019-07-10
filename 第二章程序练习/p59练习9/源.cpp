// compute element ranks

#include <iostream>
#include <algorithm> // has copy
#include <iterator>
using namespace std;


template<class T>
void rank_customize(T a[], int n, int r[])
{// Rank the n elements a[0:n-1].
 // Element ranks returned in r[0:n-1]
	for (int i = 0; i < n; i++)
		r[i] = 0;  // initialize

				   // compare all element pairs
	for (int i = 1; i < n; i++)
		for (int j = 0; j < i; j++)
			if (a[j] <= a[i]) r[i]++;
			else r[j]++;
}

int main()
{
	int a[9] = { 3,2,6,5,9,4,7,1,8 };
	int r[9];

	// output the elements
	cout << "a[0:8] = ";
	copy(a, a + 9, ostream_iterator<int>(cout, " "));
	cout << endl;

	// determine the ranks
	rank_customize(a, 9, r);

	// output the ranks
	cout << "r[0:8] = ";
	copy(r, r + 9, ostream_iterator<int>(cout, " "));
	cout << endl;
	system("pause");
	return 0;
}