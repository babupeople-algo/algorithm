// sorting.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <cstdlib>
#include <array>

#define ARR_SIZE 30

void swap(int& a, int& b)
{
	int temp = b;
	b = a;
	a = temp;
}
void print(const std::array<int, ARR_SIZE>& arr)
{
	for (auto it = arr.begin(); it != arr.end(); it++)
		std::cout << *it << ", ";
	std::cout << std::endl;
}

void bubble_sorting(std::array<int, ARR_SIZE> &arr)
{
	std::cout << "==== bubble sotring ====" << std::endl;	print(arr);
	int swap_count = 0;

	for (int i = 0; i < ARR_SIZE; i++)
	{
		for (int j = 0; j < ARR_SIZE - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				swap_count++;
				swap(arr[j], arr[j + 1]);
			}
		}
	}

	std::cout << "number of sorting : " << swap_count << std::endl;	;
	std::cout << "after sotring " << std::endl;	print(arr);
}
void selection_sorting(std::array<int, ARR_SIZE>& arr)
{
	std::cout << "==== selection sotring ====" << std::endl;	print(arr);

	int swap_count = 0;
	int min_index = 0;
	for (int i = 0; i < ARR_SIZE-1; i++)
	{
		for (int j = i; j < ARR_SIZE - 1; j++)
		{
			if (j == i)
				min_index = (arr[j] < arr[j + 1]) ? j : j + 1;
			else
				min_index = (arr[min_index] < arr[j + 1]) ? min_index : j + 1;
		}

		//std::cout << min_index << " : "<< arr[min_index] << ",  " << i << " : " << arr[i] << std::endl;
		if (arr[min_index] < arr[i])
		{
			swap_count++;
			swap(arr[min_index], arr[i]);
		}
		print(arr);
	}
	std::cout << "number of sorting : " << swap_count << std::endl; ;
	std::cout << "after sotring " << std::endl;	print(arr);

}

void insersion_sorting(std::array<int, ARR_SIZE>& arr)
{
	std::cout << "==== insersion sotring ====" << std::endl;	print(arr);
	int swap_count = 0;
	int temp_value;

	for (int i = 1; i < ARR_SIZE; i++)
	{
		temp_value = arr[i];
		for (int j = i; j >= 1; j--)
		{
			if (temp_value < arr[j-1])
			{
				swap_count++;
				arr[j] = arr[j - 1];
				arr[j - 1] = temp_value;
			}
		}
		
	}

	std::cout << "number of sorting : " << swap_count << std::endl; ;
	std::cout << "after sotring " << std::endl;	print(arr);
}

void quick_partition(std::array<int, ARR_SIZE>& arr, int start, int end)
{
	int size = end - start;

	if (size <= 0) return;

	

	int pivot = arr[start + (int)((end - start) / 2)];

	int n_start = start;
	int n_end = end;

	std::cout << " start = " << start << ", end = " << end << ", pivot = "<< pivot << std::endl;

	while (n_start <= n_end)
	{
		while (arr[n_start] <= pivot && n_start < n_end)
			n_start++;
		while (arr[n_end] >= pivot && n_start <= n_end)
		{
			n_end--;
			if (n_end < 0) { n_end = 0; break; }
		}
		if (n_start < n_end)
			swap(arr[n_start], arr[n_end]);
		else
			break;
	}
	print(arr);
	
	quick_partition(arr, start, n_end-1);	// smaller group
	quick_partition(arr, n_start+1, end);	// bigger group
}

void quick_sorting(std::array<int, ARR_SIZE>& arr)
{
	quick_partition(arr, 0, arr.size()-1 );
}

int main()
{

	std::array<int, ARR_SIZE> arr;
	for (int i = 0; i < arr.size(); i++)
	{
		arr[i] = rand()%1000;
	}
	print(arr);

	//bubble_sorting(arr);
	std::cout << std::endl;
	//selection_sorting(arr);
	//insersion_sorting(arr);
	

	quick_sorting(arr);
	print(arr);
}
