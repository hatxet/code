package katas;

import static org.junit.jupiter.api.Assertions.assertEquals;

import org.junit.jupiter.api.Test;

class KataTest {
	@Test
	public void findShort() throws Exception {
		assertEquals(3, Kata.findShort("bitcoin take over the world maybe who knows perhaps"));
		assertEquals(3, Kata.findShort("turns out random test cases are easier than writing out basic ones"));
		assertEquals(0, Kata.findShort(""));
		assertEquals(0, Kata.findShort("     "));
		assertEquals(1, Kata.findShort("aa  a"));
		assertEquals(5, Kata.findShort("aaaaa"));
		assertEquals(1, Kata.findShort("a"));
		assertEquals(2, Kata.findShort("abc abcd    ab abcder   "));
		assertEquals(2, Kata.findShort("ab  abcde   abcdefghi   "));
		assertEquals(3, Kata.findShort("  abcd abcde    aab"));
		assertEquals(2, Kata.findShort("  abcd ab    aab"));
		assertEquals(1, Kata.findShort("aba abcdea     a    abcdefghia"));
	}
}
