package katas;

import static org.junit.jupiter.api.Assertions.assertEquals;

import org.junit.jupiter.api.Test;

/*
 * The tests that came in the instructions won't compile.
 */
class HumanReadableTimeTest {

	@Test
	public void SafeTests() {
		assertEquals("00:00:00", HumanReadableTime.makeReadable(0), "makeReadable(0)");
		assertEquals("00:00:05", HumanReadableTime.makeReadable(5), "makeReadable(5)");
		assertEquals("00:01:00", HumanReadableTime.makeReadable(60), "makeReadable(60)");
		assertEquals("23:59:59", HumanReadableTime.makeReadable(86399), "makeReadable(86399)");
		assertEquals("99:59:59", HumanReadableTime.makeReadable(359999), "makeReadable(359999)");
	}

	@Test
	public void UnsafeTests() {
		assertEquals(null, HumanReadableTime.makeReadable(-1), "makeReadable(-1)");
		assertEquals(null, HumanReadableTime.makeReadable(360000), "makeReadable(360000)");
	}

}
