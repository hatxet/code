package katas;

import static org.junit.jupiter.api.Assertions.assertEquals;

import org.junit.jupiter.api.Test;

class RowSumOddNumbersTest {

	@Test
	public void test1() {
		assertEquals(1, RowSumOddNumbers.rowSumOddNumbers(1));
		assertEquals(8, RowSumOddNumbers.rowSumOddNumbers(2));
		assertEquals(74088, RowSumOddNumbers.rowSumOddNumbers(42));
	}

}
