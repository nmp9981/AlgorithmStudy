#include <vector>
#include <iostream>

const inline int find_maxmin(const std::vector<int>& vec_students, const int j, const int i) 
{
	int max = -1, min = 1<<30;
	for (int idx = j; idx <= i; idx++) 
	{
		max = std::max(max,vec_students[idx]);
		min = std::min(min,vec_students[idx]);
	}

	return max - min;
}

int main() {
	
	int N;
	std::cin >> N;
	std::vector<int> vec_students(N+1);
	std::vector<int> vec_best_scores(N+1); // dp
	
	for (int i = 1; i <= N; i++) 
	{
		std::cin >> vec_students[i];
	}

	for(int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			vec_best_scores[i] = std::max(vec_best_scores[i], vec_best_scores[j - 1] + find_maxmin(vec_students, j, i));
		}
		
		//print
		/*
		for (int a : vec_best_scores) 
		{
			std::cout << a << " ";
		}
		std::cout << "\n\n";
		*/
	}

	std::cout << vec_best_scores[N];

	return 0;
}
