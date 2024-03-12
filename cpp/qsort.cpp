#include <algorithm>
#include <iostream>
#include <valarray>
#include <vector>

std::vector<size_t> merge(std::vector<size_t>, std::vector<size_t> b);



void func1(const size_t &p);
int main() {
	std::vector<size_t> arr1 = {1, 2, 7, 10};
	std::vector<size_t> arr2 = {3, 6, 8, 9, 10, 45};
	int v1 = 7;
	int v2 = 8;
	int v3;
	int &ref = v1;

	std::cout << &ref << " " << &v1 << " " << &v2 << " " << v1 << " " << v2 << std::endl;
	ref = v2;

	std::cout << &ref << " " << &v1 << " " << &v2 << " " << v1 << " " << v2 << std::endl;

	func1(3);
	int array[7] = { 10, 8, 6, 5, 4, 3, 1 };
	for (auto &element: array) // символ амперсанда делает element ссылкой на текущий элемент массива, предотвращая копирование
	{  
		std::cout << element << ' '; 
		v3 = element;
		element = 3;
		std::cout << v3 << std::endl;
	}
	std::cout << "merge function" << std::endl;
	merge(arr1, arr2);






	std::vector<int> vec = {};
	return 0;
}

std::vector<size_t> merge(std::vector<size_t> a, std::vector<size_t> b) {
	int i = 0;
	int j = 0;
	std::vector<size_t> result = {};
	//std::cout << *(&a + 1) << a << std::endl;
	while (i < a.size() && j < b.size()) {
		if (a[i] < b[j]) {
			result.push_back(a[i]);
			i++;

		} else {
			result.push_back(b[j]);
			j++;

		}

	}

	auto s1 = std::vector<size_t>(a.begin() + i, a.end());
	auto s2 = std::vector<size_t>(b.begin() + j, b.end());

	result.reserve(result.size() + std::distance(a.begin(), a.end()));
	result.reserve(result.size() + std::distance(b.begin(), b.end()));
	result.insert(result.end(), s1.begin(), s1.end());
	result.insert(result.end(), s2.begin(), s2.end());

	std::cout << "result: " << std::endl;
	for (auto element : result) 
		std::cout << element << " ";
	std::cout << std::endl;


	return result;


}

void func1(const size_t &p) 
{
	std::cout << p << std::endl;
}
