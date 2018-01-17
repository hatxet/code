package katas;

import static org.junit.jupiter.api.Assertions.assertEquals;

import org.junit.jupiter.api.Test;

class MaskifyTest extends Maskify {

	@Test
	void testMaskify() {
		assertEquals(Maskify.maskify("4556364607935616"), "############5616");
		assertEquals(Maskify.maskify("64607935616"), "#######5616");
		assertEquals(Maskify.maskify("1"), "1");
		assertEquals(Maskify.maskify(""), "");

		// "What was the name of your first pet?"
		assertEquals(Maskify.maskify("Skippy"), "##ippy");
		assertEquals(Maskify.maskify("Nananananananananananananananana Batman!"),
				"####################################man!");
	}

}
