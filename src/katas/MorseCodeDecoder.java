package katas;

import java.util.HashMap;
import java.util.Map;

/*
 * Part 1/3
 * Decode the Morse code
 * The Morse code table is preloaded for you as a dictionary.
 * 
 * https://www.codewars.com/kata/54b724efac3d5402db00065e/
 * 
 * Part 2/3 
 * For this kata we assume the message receiving is performed automatically by the hardware that checks the line periodically.
 * If the line is connected 1 is recorded. If the line is not connected 0 is recorded.
 * After the message is fully received, it gets to you for decoding as a string containing only symbols 0 and 1.
 * If you have trouble discerning if the particular sequence of 1's is a dot or a dash, assume it's a dot.
 * For example, the message HEY JUDE, that is ···· · −·−−   ·−−− ··− −·· · may be received as follows:
 * 1100110011001100000011000000111111001100111111001111110000000000000011001111110011111100111111000000110011001111110000001111110011001100000011
 * 
 * http://www.codewars.com/kata/decode-the-morse-code-advanced
 */
public class MorseCodeDecoder {
	public static final String WORD_DELIMITER = "   ";
	public static final char LETTER_DELIMITER = ' ';
	public static final char DOT = '.';
	public static final char DASH = '-';
	public static final char ONE = '1';
	public static final char ZERO = '0';
	public static final char INVALID = 'X';
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
	 * Converts a string of bits to Morse code
	 */
	private static class BitsConverter {
		public int pulseLength, repeatedPulses, currentBitIndex;
		public char lastPulse, currentPulse;
		String bits;
		StringBuilder morse;

		public BitsConverter(String bits) {
			this.repeatedPulses = 1;
			this.currentBitIndex = 0;
			this.bits = bits;
			this.morse = new StringBuilder();
			convert();
		}

		private void convert() {
			if (bits.isEmpty()) return;

			// Skip leading 0s
			while (currentBitIndex < bits.length() && bits.charAt(currentBitIndex) == '0') {
				++currentBitIndex;
			}
			// Only 0s
			if (currentBitIndex == bits.length()) return;

			calculatePulseLength();

			// Only 1s
			if (pulseLength == bits.length()) {
				morse.append(DOT);
				return;
			}

			// Start scanning from first positive pulse
			lastPulse = ZERO;
			currentPulse = ONE;
			scanPulses();
		}

		// A pulse is the minimum time unit that can be considered a dot.
		// Find the smallest substring of 1s between 0s.
		private void calculatePulseLength() {
			char prev, curr = ONE;
			int repeatedOnes = 0;
			// Max length is the length of the whole string
			pulseLength = bits.length();
			// Assuming we start from a 1 since we skipped all 0s
			// Stop if length is 1 or it's the end of the string
			for (int index = currentBitIndex; index < bits.length() && pulseLength > 1; ++index) {
				prev = curr;
				curr = bits.charAt(index);
				if (prev == curr) {
					++repeatedOnes;
				} else {
					if (repeatedOnes < pulseLength) {
						pulseLength = repeatedOnes;
					}
					repeatedOnes = 1;
				}
			}
		}

		private void scanPulses() {
			while (isValidPulse()) {
				parsePulse();
				calculateNextPulse();
			}
			if (lastPulse == ONE && repeatedPulses == 1) morse.append(DOT);
		}

		private void calculateNextPulse() {
			currentBitIndex += pulseLength;
			lastPulse = currentPulse;
			try {
				currentPulse = bits.charAt(currentBitIndex);
			} catch (StringIndexOutOfBoundsException e) {
				currentPulse = INVALID;
			}

		}

		/*
		 * 1x ONE pulse = dot
		 * 3x ONE pulses = dash
		 * 1x ZERO pulse = dots/dashes delimiter
		 * 3x ZERO pulses = letter delimiter
		 * 7x ZERO pulses = word delimiter
		 */
		private void parsePulse() {
			if (currentPulse == lastPulse) {
				++repeatedPulses;
				if (currentPulse == ZERO) {
					if (repeatedPulses % 7 == 0) {
						morse.append(WORD_DELIMITER);
					}
				} else {
					if (repeatedPulses % 3 == 0) {
						morse.append(DASH);
					}
				}
			} else {
				// Previous pulse is different
				if (currentPulse == ZERO) {
					if (repeatedPulses == 1) {
						morse.append(DOT);
					}
				} else if (repeatedPulses % 3 == 0) {
					morse.append(LETTER_DELIMITER);
				}
				repeatedPulses = 1;
			}
		}

		private boolean isValidPulse() {
			// return currentPulse != INVALID
			return currentPulse == ZERO || currentPulse == ONE;
		}

		@Override
		public String toString() {
			return morse.toString();
		}

	}

	public static String decodeBits(String bits) {
		return new BitsConverter(bits).toString();
	}

	/*
	 * Third try: Iterating over string with less checks.
	 * It can't be faster than my second try but it's more readable.
	 * Server timed out once again. I give up.
	 */
	public static String decodeMorse(String morseCode) {
		String cleanMorseCode = morseCode.trim();
		StringBuffer message = new StringBuffer();
		String[] words = cleanMorseCode.split(WORD_DELIMITER);
		for (String word : words) {
			String[] letters = word.split(Character.toString(LETTER_DELIMITER));
			for (String letter : letters) {
				message.append(MorseCode.get(letter));
			}
			message.append(LETTER_DELIMITER);
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
	//			if (c != DOT) {
	//				letter.append(c);
	//				countSpaces = 0;
	//			} else {
	//				countSpaces++;
	//				if (letter.length() > 0) {
	//					message.append(MorseCode.get(letter.toString()));
	//					letter = new StringBuffer();
	//				} else if (countSpaces == 2) {
	//					message.append(DOT);
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
	//			message.append(DOT);
	//		}
	//		// Remove last space
	//		message.setLength(message.length() - 1);
	//		return message.toString();
	//	}
}
