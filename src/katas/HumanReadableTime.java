package katas;

/*
 * Write a function, which takes a non-negative integer (seconds) as input
 * and returns the time in a human-readable format (HH:MM:SS)
 * 
 *  HH = hours, padded to 2 digits, range: 00 - 99
 *  MM = minutes, padded to 2 digits, range: 00 - 59
 *  SS = seconds, padded to 2 digits, range: 00 - 59
 *  The maximum time never exceeds 359999 (99:59:59)
 *  
 *  https://www.codewars.com/kata/52685f7382004e774f0001f7
 */
public class HumanReadableTime {
	public static String makeReadable(int seconds) {
		if (seconds < 0 || seconds > 359999)
			return null;
		int sec, min, hour, rest = seconds;

		//Seconds
		sec = rest % 60;
		rest -= sec;

		// Minutes
		rest = rest / 60;
		min = rest % 60;
		rest -= min;

		// Hours
		hour = rest / 60;
		String result = String.format("%1$02d:%2$02d:%3$02d", hour, min, sec);
		return result;
	}
}
