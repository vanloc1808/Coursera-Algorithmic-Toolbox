#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/** This function partitions a[] in three parts
    * all elements smaller than pivot
    * all elements equal to pivot
    * all elements greater than pivot */
void partition(vector<int>& a, int l, int r, int& i, int& j)
{
	i = l - 1, j = r;
	int p = l - 1, q = r;
	int v = a[r];

	while (true) {
		while (a[++i] < v);

		while (v < a[--j])
			if (j == l)
				break;

		if (i >= j)
			break;

		swap(a[i], a[j]);

		if (a[i] == v) {
			p++;
			swap(a[p], a[i]);
		}

		if (a[j] == v) {
			q--;
			swap(a[j], a[q]);
		}
	}

	swap(a[i], a[r]);

	j = i - 1;
	for (int k = l; k < p; k++, j--)
		swap(a[k], a[j]);

	i = i + 1;
	for (int k = r - 1; k > q; k--, i++)
		swap(a[i], a[k]);
}

void quickSort(vector<int>& a, int l, int r)
{
	if (r <= l)
		return;

	int i, j;

	partition(a, l, r, i, j);

	quickSort(a, l, j);
	quickSort(a, i, r);
}

void printArr(vector<int>& a, int n)
{
	for (int i = 0; i < n; ++i)
		cout << a[i] << " ";
	cout << "\n";
}

int main()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    quickSort(a, 0, n - 1);

    printArr(a, n);

	return 0;
}
