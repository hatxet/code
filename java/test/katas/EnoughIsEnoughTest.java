package katas;

import static org.junit.jupiter.api.Assertions.assertArrayEquals;

import org.junit.jupiter.api.Test;

class EnoughIsEnoughTest {
	@Test
	public void deleteNth() throws Exception {
		assertArrayEquals(new int[] {}, EnoughIsEnough.deleteNth(new int[] { 20, 37, 20, 21 }, 0));
		assertArrayEquals(new int[] { 20, 37, 21 }, EnoughIsEnough.deleteNth(new int[] { 20, 37, 20, 21 }, 1));
		assertArrayEquals(new int[] { 1, 1, 3, 3, 7, 2, 2, 2 },
				EnoughIsEnough.deleteNth(new int[] { 1, 1, 3, 3, 7, 2, 2, 2, 2 }, 3)

		);
		assertArrayEquals(new int[] { 1, 2, 3, 1, 1, 2, 2, 3, 3, 4, 5 },
				EnoughIsEnough.deleteNth(new int[] { 1, 2, 3, 1, 1, 2, 1, 2, 3, 3, 2, 4, 5, 3, 1 }, 3));
		assertArrayEquals(new int[] { 1, 1, 1, 1, 1 }, EnoughIsEnough.deleteNth(new int[] { 1, 1, 1, 1, 1 }, 5));
		assertArrayEquals(new int[] {}, EnoughIsEnough.deleteNth(new int[] {}, 5));
		assertArrayEquals(
				new int[] { 37, 27, 14, 14, 30, 14, 14, 14, 30, 27, 30, 37, 14, 37, 30, 27, 30, 27, 30, 37, 27, 14, 37,
						27, 44, 37, 30, 27, 27, 37, 14, 27, 37, 14, 44, 27 },
				EnoughIsEnough.deleteNth(new int[] { 37, 27, 14, 14, 30, 14, 14, 14, 30, 27, 30, 37, 14, 37, 30, 27, 30,
						27, 30, 37, 27, 14, 37, 27, 44, 37, 30, 27, 27, 37, 14, 27, 37, 14, 44, 27 }, 10));

	}

}
