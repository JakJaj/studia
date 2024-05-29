/**
 * Converts a Roman numeral string to an integer.
 *
 * @param {string} roman - The Roman numeral string to convert.
 * @returns {number} The integer representation of the Roman numeral.
 */
const romanToNumber = (roman) => {
    const romanNumerals = {
        I: 1,
        V: 5,
        X: 10,
        L: 50,
        C: 100,
        D: 500,
        M: 1000
    };

    let result = 0;

    for (let i = 0; i < roman.length; i++) {
        const currentNumeral = romanNumerals[roman[i]];
        const nextNumeral = romanNumerals[roman[i + 1]];

        if (nextNumeral && currentNumeral < nextNumeral) {
            result -= currentNumeral;
        } else {
            result += currentNumeral;
        }
    }

    return result;
};

/**
 * Converts an integer to a Roman numeral string.
 *
 * @param {number} number - The integer to convert.
 * @returns {string} The Roman numeral representation of the integer.
 */
function numberToRoman(number) {
    const romanNumerals = [
        { value: 1000, symbol: 'M' },
        { value: 900, symbol: 'CM' },
        { value: 500, symbol: 'D' },
        { value: 400, symbol: 'CD' },
        { value: 100, symbol: 'C' },
        { value: 90, symbol: 'XC' },
        { value: 50, symbol: 'L' },
        { value: 40, symbol: 'XL' },
        { value: 10, symbol: 'X' },
        { value: 9, symbol: 'IX' },
        { value: 5, symbol: 'V' },
        { value: 4, symbol: 'IV' },
        { value: 1, symbol: 'I' }
    ];

    let result = '';

    for (const numeral of romanNumerals) {
        while (number >= numeral.value) {
            result += numeral.symbol;
            number -= numeral.value;
        }
    }

    return result;
}

module.exports = {
    romanToNumber,
    numberToRoman
};