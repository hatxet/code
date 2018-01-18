/*
* Make a function that can take any non-negative integer as a argument
* and return it with its digits in descending order.
* Essentially, rearrange the digits to create the highest possible number.
* Input: 21445 Output: 54421
* https://www.codewars.com/kata/5467e4d82edf8bbf40000155
*/

function descendingOrder(n) {
    return parseInt([...n.toString()].sort((a, b) => a < b).join(''))
}

// Maybe this works better for larger numbers
/*
function descendingOrder(n) {
    const sorted = [];
    const sortNumber = tobeSorted => {
        let current, index, p = 0, q = sorted.length;
        let found = false;
        while (p <= q && !found) {
            index = (p + q) / 2 >> 0;
            current = sorted[index];
            if (tobeSorted > current) {
                q = index - 1;
            } else if (tobeSorted < current) {
                p = index + 1;
            } else {
                found = true;
            }
        }
        if (!found && tobeSorted < current)++index;
        sorted.splice(index, 0, tobeSorted);
    }
    [...n.toString()].forEach(sortNumber);
    return parseInt(sorted.join(''));
}
*/