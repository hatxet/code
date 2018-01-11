package katas;

/*
 * You need to return a string that displays a diamond shape on the screen using asterisk ("*") characters.
 * 
 * https://www.codewars.com/kata/give-me-a-diamond/
 */
public class Diamond {
	// Appends s spaces and a asterisks
	public static void line(StringBuilder sb, int s, int a) {
		for (int i = 0; i < s; ++i)
			sb.append(' ');
		for (int i = 0; i < a; ++i)
			sb.append('*');
		sb.append('\n');
	}

	public static String print(int n) {
		if (n < 0 | (n % 2) == 0)
			return null;

		StringBuilder result = new StringBuilder();
		// Top
		for (int asterisks = 1; asterisks < n; asterisks += 2) {
			int pad = (n - asterisks) / 2;
			line(result, pad, asterisks);
		}
		// Bottom
		for (int asterisks = n; asterisks > 0; asterisks -= 2) {
			int pad = (n - asterisks) / 2;
			line(result, pad, asterisks);
		}

		return result.toString();
	}
}
