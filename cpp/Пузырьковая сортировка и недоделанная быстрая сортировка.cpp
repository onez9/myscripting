#include <iostream>
#include <time.h>
#include <type_traits>
#include <vector>

void bubble_sort(size_t*, size_t);
void show_elements(size_t*, size_t);
void quick_sort(size_t*, size_t, size_t);
size_t partion(size_t* , size_t, size_t);



int main() {
	
	using namespace std;
	srand(time(NULL));
	//vector<int> t = {1, 2, 3, 4, 6};
	//int s;

	//for (int n : t) {
	//	s = t.back();
	//	cout << s << endl;
	//	// t.back();
	//	// t.shrink_to_fit();
	//	// t.pop_back();
	//	// cout << n << endl;
	//}
	


	size_t n;
	cin >> n;
	size_t* arr = new size_t[n];
	for (int i = 0; i < n; i++) {
		arr[i] = rand() % 10;
		cout << arr[i] << " ";

	}

	cout << endl;
	//bubble_sort(arr, n);
	quick_sort(arr, 0, n);
	show_elements(arr, n);




	
	return 0;
}







void show_elements(size_t* arr, size_t n) {


	//size_t n =  *(&arr1+1) - arr1;
	//std::cout << n << std::endl;

	for (int i=0;i<n;i++) {
		std::cout << i << ": " << *(arr + i) << "\n";
	}
	size_t sum = 0;

	/*
	for (int i=0;i<n;i++) {
		sum += *(arr+i);
	}
	std::cout << " = " << sum << "\n";
	*/

}


size_t partion(size_t* arr, size_t low, size_t high) {
	srand(time(NULL));
	return rand() % high - low;
}


void quick_sort(size_t* arr, size_t low, size_t high) {
	using namespace std;
	size_t p;
	size_t next, prev;
	next = low; prev = high;


	if (low < high) {
		p = int((low + high) / 2);


		std::cout << "\npppppp " << p << ": " << *(arr + p) << "\n";
		while (true) {
			if (arr[next] > arr[p]) {

				if (arr[prev] <= arr[p]) {
					swap(arr[next], arr[prev]);
					next++; prev--;

				} else {
					prev--;
				}

				

			} else {
				next++;

			}

			if (next == prev-1) {
				if (arr[next] > arr[prev]) {
					swap(arr[next], arr[prev]);
				}
				break;
			} 			
			//cout << endl;

		}
		
		quick_sort(arr, low, p);

		quick_sort(arr, p+1, high);

		show_elements(arr, 10);
		// return;
	}
	cout << p;
	show_elements(arr, 10);

}

void bubble_sort(size_t* arr, size_t n) {
	using namespace std;
	int F;
	for (int i = 0; i < n; i++) {
		F = 0;
		for (int j = 0; j < n - 1 - i; j++) {
			if (arr[j] > arr[j+1]) {
				swap(arr[j], arr[j+1]);
				F = 1;
			}
		}

		if (F == 0) {
			break;
		}
		
	}

}

