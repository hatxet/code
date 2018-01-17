package katas;

import java.util.HashMap;
import java.util.Map;
/*
 * Given two arrays a and b write a function comp(a, b) 
 * that checks whether the two arrays have the "same" elements,
 * with the same multiplicities.
 * "Same" means, here, that the elements in b are the elements in a squared, regardless of the order.
 * 
 * https://www.codewars.com/kata/550498447451fbbd7600041c
 */

public class AreSame {

	public static boolean comp(int[] a, int[] b) {
		if (a.length != b.length)
			return false;
		if (a.length == 0)
			return true;

		boolean areSame = true;
		// Fill a map with the numbers we find in the first array
		Map<Integer, Integer> occurrences = new HashMap<>(a.length);
		for (int i = 0; i < a.length; ++i) {
			int sqr = a[i] * a[i];
			// If the square isn't in the map, insert it with 1 occurrence
			// Else increment the number of occurrences
			occurrences.merge(sqr, 1, Integer::sum);
		}

		// Check if the numbers in the second array are in the map
		for (int i = 0; i < b.length && areSame; ++i) {
			Integer matchedSqr = occurrences.get(b[i]);
			if (matchedSqr == null) {
				areSame = false;
			} else {
				// Decrease the number of occurrences or remove the entry if it's zero
				occurrences.compute(b[i], (k, v) -> (v - 1 == 0) ? null : v - 1);
			}
		}
		return areSame;
	}
}
