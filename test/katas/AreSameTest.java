package katas;

import static org.junit.jupiter.api.Assertions.assertEquals;

import org.junit.jupiter.api.Test;

class AreSameTest {

	@Test
	public void test1() {
		int[] a = new int[] { 121, 144, 19, 161, 19, 144, 19, 11 };
		int[] b = new int[] { 121, 14641, 20736, 361, 25921, 361, 20736, 361 };
		assertEquals(AreSame.comp(a, b), true);
	}

	@Test
	public void test2() {
		int[] a = new int[] { 121, 144, 19, 161, 19, 144, 19, 11 };
		int[] b = new int[] { 132, 14641, 20736, 361, 25921, 361, 20736, 361 };
		assertEquals(AreSame.comp(a, b), false);
	}

	@Test
	public void test3() {
		int[] a = new int[] { 121, 144, 19, 161, 19, 144, 19, 11 };
		int[] b = new int[] { 121, 14641, 20736, 36100, 25921, 361, 20736, 361 };
		assertEquals(AreSame.comp(a, b), false);
	}

}
