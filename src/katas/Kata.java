package katas;

public class Kata {
	/*
	 * Given a string of words, return the length of the shortest word(s).
	 * String will never be empty and you do not need to account for different data types.
	 * https://www.codewars.com/kata/shortest-word
	 */
	public static int findShort(String s) {

		int len = 0, minLen = s.length();
		for (int i = 0; i < s.length(); ++i) {
			char c = s.charAt(i);
			if (c != ' ') {
				// If it's not a space, keep counting characters
				++len;
			} else {
				if (len > 0 && len < minLen) {
					// If it's smaller than the smallest we found, save it
					minLen = len;
				}
				// Reset the character count
				len = 0;
			}
		}

		if (len == 0 && minLen == s.length()) {
			// S is filled only with spaces
			minLen = 0;
		} else if (len > 0 && len < minLen) {
			// In case the last word is the shortest
			minLen = len;
		}
		return minLen;
	}
}