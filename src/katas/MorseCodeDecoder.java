package katas;

import java.util.HashMap;
import java.util.Map;

/*
 * Decode the Morse code
 * The Morse code table is preloaded for you as a dictionary.
 * 
 * https://www.codewars.com/kata/54b724efac3d5402db00065e/
 */
public class MorseCodeDecoder {
	public static final Map<String, String> MorseCode;
	static {
		MorseCode = new HashMap<>();
		MorseCode.put("-.-.--", "!");
		MorseCode.put(".-..-.", "\"");
		MorseCode.put("...-..-", "$");
		MorseCode.put(".-...", "&");
		MorseCode.put(".----.", "'");
		MorseCode.put("-.--.", "(");
		MorseCode.put("-.--.-", ")");
		MorseCode.put(".-.-.", "+");
		MorseCode.put("--..--", ",");
		MorseCode.put("-....-", "-");
		MorseCode.put(".-.-.-", ".");
		MorseCode.put("-..-.", "/");
		MorseCode.put("-----", "0");
		MorseCode.put(".----", "1");
		MorseCode.put("..---", "2");
		MorseCode.put("...--", "3");
		MorseCode.put("....-", "4");
		MorseCode.put(".....", "5");
		MorseCode.put("-....", "6");
		MorseCode.put("--...", "7");
		MorseCode.put("---..", "8");
		MorseCode.put("----.", "9");
		MorseCode.put("---...", ":");
		MorseCode.put("-.-.-.", ";");
		MorseCode.put("-...-", "=");
		MorseCode.put("..--..", "?");
		MorseCode.put(".--.-.", "@");
		MorseCode.put(".-", "A");
		MorseCode.put("-...", "B");
		MorseCode.put("-.-.", "C");
		MorseCode.put("-..", "D");
		MorseCode.put(".", "E");
		MorseCode.put("..-.", "F");
		MorseCode.put("--.", "G");
		MorseCode.put("....", "H");
		MorseCode.put("..", "I");
		MorseCode.put(".---", "J");
		MorseCode.put("-.-", "K");
		MorseCode.put(".-..", "L");
		MorseCode.put("--", "M");
		MorseCode.put("-.", "N");
		MorseCode.put("---", "O");
		MorseCode.put(".--.", "P");
		MorseCode.put("--.-", "Q");
		MorseCode.put(".-.", "R");
		MorseCode.put("...", "S");
		MorseCode.put("-", "T");
		MorseCode.put("..-", "U");
		MorseCode.put("...-", "V");
		MorseCode.put(".--", "W");
		MorseCode.put("-..-", "X");
		MorseCode.put("-.--", "Y");
		MorseCode.put("--..", "Z");
		MorseCode.put("..--.-", "_");
		MorseCode.put("...---...", "SOS");
	}

	/*
	 * Third try: Iterating over string with less checks.
	 * It can't be faster than my second try but it's more readable.
	 * Server timed out once again. I give up.
	 */
	public static String decode(String morseCode) {
		String cleanMorseCode = morseCode.trim();
		StringBuffer message = new StringBuffer();
		String[] words = cleanMorseCode.split("   ");
		for (String word : words) {
			String[] letters = word.split(" ");
			for (String letter : letters) {
				message.append(MorseCode.get(letter));
			}
			message.append(' ');
		}
		message.setLength(message.length() - 1);
		return message.toString();
	}

	/*
	 * Second try: Iterating over string.
	 * Server timed out again
	 */
	//	public static String decode(String morseCode) {
	//		StringBuffer letter = new StringBuffer();
	//		StringBuffer message = new StringBuffer();
	//		int countSpaces = 2;
	//
	//		for (int i = 0; i < morseCode.length(); ++i) {
	//			char c = morseCode.charAt(i);
	//			if (c != ' ') {
	//				letter.append(c);
	//				countSpaces = 0;
	//			} else {
	//				countSpaces++;
	//				if (letter.length() > 0) {
	//					message.append(MorseCode.get(letter.toString()));
	//					letter = new StringBuffer();
	//				} else if (countSpaces == 2) {
	//					message.append(' ');
	//				}
	//			}
	//		}
	//		if (letter.length() > 0)
	//			message.append(MorseCode.get(letter.toString()));
	//		if (countSpaces > 2)
	//			message.setLength(message.length() - 1);
	//		//// System.out.println(message);
	//		return message.toString();
	//	}

	/*
	 * First try: Regex
	 * Server timed out
	 */
	//	public static String decode(String morseCode) {
	//		StringBuffer message = new StringBuffer();
	//		// Regex for any group of dots or dashes that might have a space in between
	//		// So basically a group of letters
	//		String regex = "([\\.\\-]+\\s?)+";
	//		Pattern pattern = Pattern.compile(regex);
	//		Matcher matcher = pattern.matcher(morseCode);
	//		List<String> words = new ArrayList<>();
	//		while (matcher.find()) {
	//			words.add(matcher.group());
	//		}
	//		for (String word : words) {
	//			String[] letters = word.split(" ");
	//			for (String letter : letters) {
	//				message.append(MorseCode.get(letter));
	//			}
	//			message.append(' ');
	//		}
	//		// Remove last space
	//		message.setLength(message.length() - 1);
	//		return message.toString();
	//	}
}
