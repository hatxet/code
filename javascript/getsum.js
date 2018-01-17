// Given two integers a and b, which can be positive or negative,
// find the sum of all the numbers between including them too and return it.
// If the two numbers are equal return a or b. a and b are not ordered.
//
// http://www.codewars.com/kata/55f2b110f61eb01779000053
//
// Best answer (sigh): GetSum = (a, b) => (a + b) * (Math.abs(a - b) + 1) / 2;

const naturalSum = n => n * (n + 1) / 2;

function GetSum(a, b) {
    if (a === b) return a
    let result = 0
    let [min, max] = [a, b]
    // Max sure min is lower than max
    if (min > max)[min, max] = [max, min]
    if (max <= 0) {
        result = -1 * (naturalSum(--min) - naturalSum(max))
    } else {
        result = naturalSum(max) - naturalSum(--min)
    }
    return result
}