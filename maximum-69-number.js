/**
 * @param {number} num
 * @return {number}
 */
var maximum69Number = function (num) {
  const str = num.toString();
  const arr = str.split('');
  for (let i = 0; i < arr.length; i++) {
    if (arr[i] === '6') {
      arr[i] = '9';
      break;
    }
  }
  return Number(arr.join(''));
};

let num = 9669;
console.log(maximum69Number(num));