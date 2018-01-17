package katas;

// Given the triangle of consecutive odd numbers:
//
// 1
// 3     5
// 7     9    11
// 13    15    17    19
// 21    23    25    27    29
// ...
//
// Calculate the row sums of this triangle from the row index (starting at index 1) e.g.:
//
// rowSumOddNumbers(1); // 1
// rowSumOddNumbers(2); // 3 + 5 = 8
//
// https://www.codewars.com/kata/55fd2d567d94ac3bc9000064

// Optimal solution: n^3

public class RowSumOddNumbers {
	// This problem can be solved easier than this
	// but it's a good way to practice arithmetic series.
	public static int rowSumOddNumbers(int n) {
		// Used to find the index from where we start the sum i.e. row 4 -> index 6
		int oddIndex = n * (n - 1) / 2;
		// Odd series is 1,3,5,7,9,... a(n) = n*2+1
		// For example, if the index is 6 we start the sum from 13
		int oddSeries = oddIndex * 2 + 1;
		// Sum of arithmetic series adding 2 -> 0,2,6,12,20,32... a(n) = (n*(2*n-2)) / 2
		// 13+15+17+19
		// (13+0)+(13+2)+(13+4)+(13+6)
		// 4*13 + (0+2+4+6) // 4*13 + 12
		int doubleSeries = (n * (2 * n - 2)) / 2;
		return n * oddSeries + doubleSeries;
	}
}
