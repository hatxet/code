package katas;

import static org.junit.Assert.assertEquals;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

import org.junit.Test;

public class SqInRectTest {

	@Test
	public void test1() {
		List<Integer> res = new ArrayList<Integer>(Arrays.asList(3, 2, 1, 1));
		assertEquals(res, SqInRect.sqInRect(5, 3));
	}

	@Test
	public void test2() {
		assertEquals(null, SqInRect.sqInRect(5, 5));
	}

	@Test
	public void test3() {
		List<Integer> res = new ArrayList<Integer>(Arrays.asList(14, 6, 6, 2, 2, 2));
		assertEquals(res, SqInRect.sqInRect(20, 14));
	}

	@Test
	public void test4() {
		List<Integer> res = new ArrayList<Integer>(Arrays.asList(10, 2, 2, 2, 2, 2));
		assertEquals(res, SqInRect.sqInRect(10, 12));
	}
}