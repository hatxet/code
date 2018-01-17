package katas;

/*
 * 
 * Write a function that takes an (unsigned) integer as input, and returns the number of bits that are equal to one in the binary representation of that number.
 * Example: The binary representation of 1234 is 10011010010, so the function should return 5 in this case
 * 
 * https://www.codewars.com/kata/526571aae218b8ee490006f4
 * 
 * Well, I'll be hamed.
 * http://grepcode.com/file/repository.grepcode.com/java/root/jdk/openjdk/6-b14/java/lang/Integer.java#Integer.bitCount%28int%29
 */
public class BitCounting {
	public static int countBits(int n) {

		int count = 0;
		while (n > 0) {
			if (n % 2 != 0)
				++count;
			n = n / 2;
		}
		return count;
	}
}