package katas;

public class Solution {

	/*
	 * If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.
	 * Finish the solution so that it returns the sum of all the multiples of 3 or 5 below the number passed in.
	 * Note: If the number is a multiple of both 3 and 5, only count it once.
	 * 
	 * https://www.codewars.com/kata/514b92a657cdc65150000006
	 */

	// Server timed out. What a surprise.
	// Again, I'm pretty sure this solution works.
	// Sum of all the multiples of 3 below the limit,
	// plus same for the multiples of 5,
	// minus the sum of multiples of 3 and 5 so they are not repeated.

	// Sum of the first n numbers that are multiple of k
	public static int sumMult(int n, int k) {
		return k * n * (n + 1) / 2;
	}

	public int solution(int number) {
		int sumMult3, sumMult5, sumMult15;

		number--; // Upper bound not included

		sumMult3 = sumMult(number / 3, 3);

		sumMult5 = sumMult(number / 5, 5);

		sumMult15 = sumMult(number / 15, 15);

		return sumMult3 + sumMult5 - sumMult15;
	}
}
