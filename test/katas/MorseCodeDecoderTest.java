package katas;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertTrue;

import org.junit.jupiter.api.Test;

class MorseCodeDecoderTest {

	@Test
	public void decodeMorseSimple() {
		assertTrue(MorseCodeDecoder.decodeMorse(".-").equals("A"));
		assertTrue(MorseCodeDecoder.decodeMorse(".").equals("E"));
		assertTrue(MorseCodeDecoder.decodeMorse("..").equals("I"));
		assertTrue(MorseCodeDecoder.decodeMorse(". .").equals("EE"));
		assertTrue(MorseCodeDecoder.decodeMorse(".   .").equals("E E"));
		assertTrue(MorseCodeDecoder.decodeMorse("...---...").equals("SOS"));
		assertTrue(MorseCodeDecoder.decodeMorse("... --- ...").equals("SOS"));
	}

	@Test
	public void decodeMorseExtra() {
		assertTrue(MorseCodeDecoder.decodeMorse(".   .").equals("E E"));
		assertTrue(MorseCodeDecoder.decodeMorse(" . ").equals("E"));
		assertTrue(MorseCodeDecoder.decodeMorse("   .   . ").equals("E E"));
		assertTrue(MorseCodeDecoder.decodeMorse(
				"      ...---... -.-.--   - .... .   --.- ..- .. -.-. -.-   -... .-. --- .-- -.   ..-. --- -..-   .--- ..- -- .--. ...   --- ...- . .-.   - .... .   .-.. .- --.. -.--   -.. --- --. .-.-.-  ")
				.equals("SOS! THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG."));
	}

	@Test
	public void decodeBitsSimple() throws Exception {
		String[] expectedBin = new String[] { "1110111", "000000000000", "011111111110", "111111",
				"0000111000111111111000000000111000000", "000011000000111111",
				"00001110000000000000000000001110000000000000000000000" };
		String[] expectedMorse = new String[] { "--", "", ".", ".", ".- .", ". -", ".   .   " };

		for (int i = 0; i < expectedBin.length; ++i) {
			assertTrue("(" + i + ")=> " + expectedMorse[i],
					MorseCodeDecoder.decodeBits(expectedBin[i]).equals(expectedMorse[i]));
		}
	}

	@Test
	public void decodeBitsHeyJude() throws Exception {
		assertTrue(MorseCodeDecoder.decodeMorse(MorseCodeDecoder.decodeBits(
				"00001100110011001100000011000000111111001100111111001111110000000000000011001111110011111100111111000000110011001111110000001111110011001100000011"))
				.equals("HEY JUDE"));
	}

	@Test
	public void decodeLongMessage() {
		assertEquals("THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG.",
				MorseCodeDecoder.decodeMorse(MorseCodeDecoder.decodeBits(
						"00011100010101010001000000011101110101110001010111000101000111010111010001110101110000000111010101000101110100011101110111000101110111000111010000000101011101000111011101110001110101011100000001011101110111000101011100011101110001011101110100010101000000011101110111000101010111000100010111010000000111000101010100010000000101110101000101110001110111010100011101011101110000000111010100011101110111000111011101000101110101110101110")));
	}

}
