package katas;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/*
 * Given a list lst and a number N,
 * create a new list that contains each number of lst at most N times without reordering.
 * 
 * https://www.codewars.com/kata/554ca54ffa7d91b236000023
 */
public class EnoughIsEnough {
	public static int[] deleteNth(int[] elements, int maxOccurrences) {
		if (maxOccurrences < 1)
			return new int[0];
		Map<Integer, Integer> map = new HashMap<>();
		List<Integer> result = new ArrayList<>();

		for (int i = 0; i < elements.length; ++i) {
			Integer occurrence = map.get(elements[i]);
			if (occurrence == null) {
				map.put(elements[i], 1);
				result.add(elements[i]);
			} else if (occurrence < maxOccurrences) {
				map.put(elements[i], occurrence + 1);
				result.add(elements[i]);
			}
		}

		return result.stream().mapToInt(Integer::intValue).toArray();
	}
}
