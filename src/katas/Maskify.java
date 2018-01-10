package katas;

/*
 * Your task is to write a function maskify, which changes all but the last four characters into '#'.
 * 
 * https://www.codewars.com/kata/5412509bd436bd33920011bc
 */
public class Maskify {
	public static String maskify(String str) {
		int revealedCharacters = 4;

		if (str.length() <= revealedCharacters)
			return str;

		int maskedCharacters = str.length() - revealedCharacters;
		StringBuffer buffer = new StringBuffer(str.substring(maskedCharacters));
		for (int i = 0; i < maskedCharacters; ++i) {
			buffer.insert(0, '#');
		}

		return buffer.toString();
	}
}
