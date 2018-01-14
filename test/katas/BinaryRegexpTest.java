package katas;

import static org.junit.jupiter.api.Assertions.assertEquals;

import org.junit.jupiter.api.Test;

class BinaryRegexpTest {

	@Test
	public void positiveTests() {
		String[] toTestArray = new String[] { "000", "110", "1001", "1011111111101", "00000011", "11000000",
				"0000110000", "00010010000", "00001011111010000", Integer.toBinaryString(12345678) };
		for (String str : toTestArray) {
			assertEquals(true, BinaryRegexp.multipleOf3().matcher(str).matches(), str);
		}
	}

	@Test
	public void negativeTests() {
		String[] toTestArray = new String[] { " 0", "abc", "111" };
		for (String str : toTestArray) {
			assertEquals(false, BinaryRegexp.multipleOf3().matcher(str).matches(), str);
		}
	}
}
