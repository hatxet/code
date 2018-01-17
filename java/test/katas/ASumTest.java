package katas;

import static org.junit.jupiter.api.Assertions.assertEquals;

import org.junit.jupiter.api.Test;

class ASumTest {

	@Test
	public void test9() {
		assertEquals(5, ASum.findNb(225));
	}

	@Test
	public void test5() {
		assertEquals(-1, ASum.findNb(2304422822859502501L));
	}

	//
	@Test
	public void test6() {
		assertEquals(-1, ASum.findNb(1618679466942035717L));
	}

	@Test
	public void test1() {
		assertEquals(2022, ASum.findNb(4183059834009L));
	}

	@Test
	public void test2() {
		assertEquals(-1, ASum.findNb(24723578342962L));
	}

	@Test
	public void test3() {
		assertEquals(4824, ASum.findNb(135440716410000L));
	}

	@Test
	public void test4() {
		assertEquals(3568, ASum.findNb(40539911473216L));
	}

}
