// Rajshree Mondal github: rajshree2000
/* Subset sum problem is to find subset of elements that are selected from a given set whose sum adds up to a given number K. We are considering the set contains non-negative values. It is assumed that the input set is unique (no duplicates are presented).
Using exhaustive search we consider all subsets irrespective of whether they satisfy given constraints or not. Backtracking can be used to make a systematic consideration of the elements to be selected.
*/

#include <stdio.h> 
#include <stdlib.h> 

#define ARRAYSIZE(a) (sizeof(a))/(sizeof(a[0])) 

static int total_nodes; 
// prints subset found 
void printSubset(int A[], int size) 
{ 
	for(int i = 0; i < size; i++) 
	{ 
		printf("%*d", 5, A[i]); 
	} 

	printf("n"); 
} 

// inputs 
// s		 - set vector 
// t		 - tuplet vector 
// s_size	 - set size 
// t_size	 - tuplet size so far 
// sum		 - sum so far 
// ite		 - nodes count 
// target_sum - sum to be found 
void subset_sum(int s[], int t[], 
				int s_size, int t_size, 
				int sum, int ite, 
				int const target_sum) 
{ 
	total_nodes++; 
	if( target_sum == sum ) 
	{ 
		// We found subset 
		printSubset(t, t_size); 
		// Exclude previously added item and consider next candidate 
		subset_sum(s, t, s_size, t_size-1, sum - s[ite], ite + 1, target_sum); 
		return; 
	} 
	else
	{ 
		// generate nodes along the breadth 
		for( int i = ite; i < s_size; i++ ) 
		{ 
			t[t_size] = s[i]; 
			// consider next level node (along depth) 
			subset_sum(s, t, s_size, t_size + 1, sum + s[i], i + 1, target_sum); 
		} 
	} 
} 

// Wrapper to print subsets that sum to target_sum 
// input is weights vector and target_sum 
void generateSubsets(int s[], int size, int target_sum) 
{ 
	int *tuplet_vector = (int *)malloc(size * sizeof(int)); 

	subset_sum(s, tuplet_vector, size, 0, 0, 0, target_sum); 

	free(tuplet_vector); 
} 

int main() 
{ 
	int weights[] = {10, 7, 5, 18, 12, 20, 15}; 
	int size = ARRAYSIZE(weights); 

	generateSubsets(weights, size, 35); 
	printf("Nodes generated %dn", total_nodes); 
	return 0; 
} 
