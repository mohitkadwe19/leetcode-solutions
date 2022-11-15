/**
 * @param {number} celsius
 * @return {number[]}
 */
var convertTemperature = function (celsius) {
  let fahrenheit = celsius * 1.80 + 32.00;
  let kelvin = celsius + 273.15;

  return [kelvin, fahrenheit];

};

let celsius = 36.50;

console.log(convertTemperature(celsius));