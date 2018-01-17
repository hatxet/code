package katas;

public class ASum {

	/*
	 * Build a pile of cubes The parameter of the function findNb will be an integer
	 * m and you have to return the integer n such as n^3 + (n-1)^3 + ... + 1^3 = m
	 * if such a n exists or -1 if there is no such n. findNb(1071225) --> 45
	 * findNb(91716553919377) --> -1
	 */

	// Solving with math skills
	// The sum of the first n cubes is the square of the sum of the first n natural
	// numbers
	// So cubeSum(n) = m = (n*(n+1)/2) ^ 2,
	// there has to be a sum of n natural numbers that is naturalSum(n) = sqrt(m) =
	// n*(n+1)/2

	// Example. For m = 225, sqr(m) = 15
	// is 15 a sum of natural numbers?
	// naturalSum(n) = n*(n+1) /2 = x
	// n = (sqr(1+8x)-1) / 2
	// replacing x with 15 we get n = 5
	// is cubeSum(5) == m?
	// yes, so we return n = 5

	public static long findNb(long m) {
		double r = Math.sqrt(m);
		long n = (long) (Math.sqrt(r * 8 + 1) - 1) / 2;
		long newM = ((n + 1) * n / 2) * ((n + 1) * n / 2);
		return (newM == m) ? n : -1;
	}
}