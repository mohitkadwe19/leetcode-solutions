
var StockSpanner = function () {

  this.stack = []

};

/** 
 * @param {number} price
 * @return {number}
 */
StockSpanner.prototype.next = function (price) {

  let res = 1;

  while (this.stack.length && this.stack[this.stack.length - 1][0] <= price) {
    res += this.stack[this.stack.length - 1][1];
    this.stack.pop()
  }

  this.stack.push([price, res])

  return res;

};

/** 
 * Your StockSpanner object will be instantiated and called as such:
 * var obj = new StockSpanner()
 * var param_1 = obj.next(price)
 */

let price = [[], [100], [80], [60], [70], [60], [75], [85]];
let obj = new StockSpanner();
for (let i = 0; i < price.length; i++) {
  console.log(obj.next(price[i]));
}