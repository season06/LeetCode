#include<iostream>
#include<string>
#include<vector>
using namespace std;
int n;
void print(vector<int> &data)
{
	for (int i = 0; i < data.size(); i++)
		cout << data[i] << " ";
	cout << "\n";
}
void Bubble(vector<int> data)
{
	for (int i = n - 1; i > 0; i--) // scan time: n-1
	{
		int change = 0; // if no change, sort complete, and jump out of loop (increase performance)
		for (int j = 0; j < i; j++)
		{
			if (data[j] > data[j + 1])
			{
				swap(data[j], data[j + 1]);
				change = 1;
			}
		}
		if (!change) return;
		print(data);
	}
}
void Select(vector<int> data)
{
	for (int i = 0; i < n - 1; i++) // scan time: n-1
	{
		int change = 0;
		for (int j = i + 1; j < n; j++)
		{
			if (data[i] > data[j])
			{
				swap(data[i], data[j]);
				change = 1;
			}
		}
		if (!change) return;
		print(data);
	}
}
void Insert(vector<int> data)
{
	for (int i = 1; i < n; i++) // scan time: n-1
	{
		int temp = data[i];
		int j = i - 1;
		while (j >= 0 && temp < data[j])
		{
			data[j + 1] = data[j];
			j--;
		}
		data[j + 1] = temp;
		print(data);
	}
}
int Partition(vector<int> &data, int front, int end)
{
	int pivot = data[end];
	int i = front - 1;
	for (int j = front; j < end; j++)
	{
		if (data[j] < pivot)
		{
			i++;
			swap(data[i], data[j]);
		}
	}
	print(data);
	i++;
	swap(data[i], data[end]);
	return i;
}
void Quick(vector<int> &data, int front, int end)
{
	if (front < end)
	{
		int pivot = Partition(data, front, end);
		Quick(data, front, pivot - 1);
		Quick(data, pivot + 1, end);
	}
}
void Merge(vector<int> arr, int start, int mid, int end)
{
	vector<int> left(arr.begin() + start, arr.begin() + mid + 1);
	vector<int> right(arr.begin() + mid + 1, arr.begin() + end + 1);
	int i_n = mid - start + 1, j_n = end - mid;
	int i = 0, j = 0, k = start;
	while (i < i_n && j < j_n)
	{
		if (left[i] <= right[j])
			arr[k++] = left[i++];
		else
			arr[k++] = right[j++];
	}
	while (i < i_n)
		arr[k++] = left[i++];
	while (j < j_n)
		arr[k++] = right[j++];

	for (int i = 0; i < k; i++)
		cout << arr[i] << " ";
	cout << "\n";
}
void Mergesort(vector<int> arr, int front, int end)
{
	if (front < end)
	{
		int mid = (front + end) / 2;
		Mergesort(arr, front, mid);
		Mergesort(arr, mid + 1, end);
		Merge(arr, front, mid, end);
	}
}
void Create_tree(vector<int> data, int i, int size)
{
	int j = 2 * i, temp = data[i], ck = 1;
	while (j <= size && ck)
	{
		if (j < size)
		{
			if (data[j] < data[j + 1])
				j++;
		}
		if (temp >= data[j])
			ck = 0;
		else
		{
			data[j / 2] = data[j];
			j = 2 * j;
		}
	}
	data[j / 2] = temp;
}
void Heap(vector<int> data)
{
	for (int i = n / 2; i > 0; i--)
		Create_tree(data, i, n - 1);
	for (int i = 0; i < n; i++)
		cout << data[i] << " ";
	cout << "\n";
	for (int i = n - 2; i > 0; i--) // sort
	{
		swap(data[1], data[i + 1]);
		Create_tree(data, 1, i);
		for (int j = 0; j < n; j++)
			cout << data[j] << " ";
		cout << "\n";
	}
}
void Radix(vector<int> data)
{
	for (int radix = 1; radix <= 100; radix *= 10)
	{
		int temp[10][100] = { 0 }; // [0~9 digit][number of data]
		for (int i = 0; i < n; i++)
		{
			int x = (data[i] / radix) % 10;
			temp[x][i] = data[i];
		}
		int k = 0;
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (temp[i][j] != 0)
				{
					data[k++] = temp[i][j];
				}
			}
		}
		cout << "經過" << radix << "位數排序: ";
		for (int j = 0; j < n; j++)
			cout << data[j] << " ";
		cout << "\n";
	}
}
void Count(vector<int> arr)
{
	vector<int> count;
	count.resize(1000);
	int min = 0, max = 0;
	for (int i = 0; i < arr.size(); i++)
	{
		count[arr[i]]++;
		if (arr[i] > max)
			max = arr[i];
		if (arr[i] < min)
			min = arr[i];
	}
	int n = 0;
	for (int i = min; i <= max; i++)
	{
		if (count[i] != 0)
		{
			for (int j = 0; j < count[i]; j++)
				arr[n++] = i;
		}
	}

	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << "\n";
}

int main()
{
	while (cin >> n)
	{
		vector<int> data;
		data.resize(n);
		for (int i = 0; i < n; i++)
			cin >> data[i];

		// Bubble Sort : n / n^2
		cout << "Bubble Sort\n";
		Bubble(data);

		// Select Sort : n^2
		cout << "\nSelect Sort\n";
		Select(data);

		// Insert Sort : n / n^2
		cout << "\nInsert Sort\n";
		Insert(data);

		// Quick Sort : NlogN / n^2
		cout << "\nQuick Sort\n";
		Quick(data, 0, n - 1);

		// Merge Sort : NlogN
		cout << "\nMerge Sort\n";
		Mergesort(data, 0, n - 1);

		// Heap Sort : NlogN
		cout << "\nHeap Sort\n";
		Heap(data);

		// Radix Sort : 
		cout << "\nRadix Sort\n";
		Radix(data);

		// Count Sort : n / n+k
		cout << "\nCount Sort\n";
		Count(data);
	}
	system("pause");
	return 0;
}

// sort
// https://medium.com/@totoroLiu/%E6%8E%92%E5%BA%8F%E6%BC%94%E7%AE%97%E6%B3%95-sorting-algorithm-dfd8af673f3a
// quick sort
// http://alrightchiu.github.io/SecondRound/comparison-sort-quick-sortkuai-su-pai-xu-fa.html
// merge sort
// https://alrightchiu.github.io/SecondRound/comparison-sort-merge-sorthe-bing-pai-xu-fa.html
// heap sort
// https://medium.com/codeda/%E6%BC%94%E7%AE%97%E6%B3%95%E7%AD%86%E8%A8%98-%E4%BA%8C-heap-sort-and-quick-sort%E5%AF%A6%E4%BD%9Cin-java-5b66c6322777
