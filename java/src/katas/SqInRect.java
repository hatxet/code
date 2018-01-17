package katas;

import java.util.ArrayList;
import java.util.List;

/*
 * Cut a given "true" rectangle into squares ("true" rectangle meaning that the two dimensions are different).
 * 
 * http://www.codewars.com/kata/55466989aeecab5aac00003e
 */
public class SqInRect {
	public static List<Integer> sqInRect(int lng, int wdth) {
		// your code
		if (lng == wdth)
			return null;
		List<Integer> l = new ArrayList<>();
		while (lng > 1 && wdth > 1) {
			if (lng < wdth) {
				wdth -= lng;
				l.add(lng);
			} else {
				lng -= wdth;
				l.add(wdth);
			}
		}
		if (lng == 1) {
			for (int i = 0; i < wdth; ++i)
				l.add(1);
		} else {
			for (int i = 0; i < lng; ++i)
				l.add(1);
		}
		return l;
	}
}
