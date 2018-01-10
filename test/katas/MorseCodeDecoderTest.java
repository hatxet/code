package katas;

import static org.junit.Assert.assertTrue;

import org.junit.jupiter.api.Test;

class MorseCodeDecoderTest {

	@Test
	public void testSimple() {
		assertTrue(MorseCodeDecoder.decode(".-").equals("A"));
		assertTrue(MorseCodeDecoder.decode(".").equals("E"));
		assertTrue(MorseCodeDecoder.decode("..").equals("I"));
		assertTrue(MorseCodeDecoder.decode(". .").equals("EE"));
		assertTrue(MorseCodeDecoder.decode(".   .").equals("E E"));
		assertTrue(MorseCodeDecoder.decode("...---...").equals("SOS"));
		assertTrue(MorseCodeDecoder.decode("... --- ...").equals("SOS"));
	}

	@Test
	public void testMore() {
		assertTrue(MorseCodeDecoder.decode(" . ").equals("E"));
		assertTrue(MorseCodeDecoder.decode("   .   . ").equals("E E"));
		assertTrue(MorseCodeDecoder.decode(
				"      ...---... -.-.--   - .... .   --.- ..- .. -.-. -.-   -... .-. --- .-- -.   ..-. --- -..-   .--- ..- -- .--. ...   --- ...- . .-.   - .... .   .-.. .- --.. -.--   -.. --- --. .-.-.-  ")
				.equals("SOS! THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG."));
	}

}
