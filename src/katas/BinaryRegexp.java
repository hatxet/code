package katas;

import java.util.regex.Pattern;

/*
 * In this kata, your task is to create a regular expression capable of evaluating
 * binary strings (strings with only 1s and 0s) and determining whether the given string
 * represents a number divisible by 3.
 * 
 * https://www.codewars.com/kata/binary-multiple-of-3
 * https://math.stackexchange.com/questions/140283/why-does-this-fsm-accept-binary-numbers-divisible-by-three
 */
public class BinaryRegexp {

	public static Pattern multipleOf3() {
		// Regular expression that matches binary numbers that are multiple of 3
		// 101111000110000101001110
		return Pattern.compile("(0*(1(0(1)*0)*1)+0*)+|0+");
	}

}
