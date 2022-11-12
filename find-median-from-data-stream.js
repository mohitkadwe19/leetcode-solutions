
function binarySearch(arr, target, left, right) {

  if (left === right) {
    return arr[left] > target ? left : left + 1;
  }

  let mid = Math.floor((left + right) / 2);

  if (arr[mid] < target) {
    return binarySearch(arr, target, mid + 1, right);
  }
  if (arr[mid] > target) {
    return binarySearch(arr, target, left, mid);
  }
  return mid;
}


var MedianFinder = function () {
  this.arr = [];
};

/** 
 * @param {number} num
 * @return {void}
 */
MedianFinder.prototype.addNum = function (num) {

  if (this.arr.length === 0) {
    this.arr.push(num);
    return;
  }

  let index = binarySearch(this.arr, num, 0, this.arr.length - 1);

  this.arr.splice(index, 0, num);

};

/**
 * @return {number}
 */
MedianFinder.prototype.findMedian = function () {

  if (this.arr.length === 0) {
    return null;
  }
  let mid = this.arr.length / 2;

  if (this.arr.length % 2 === 0) {
    return ((this.arr[mid] + this.arr[mid - 1]) / 2);
  }

  return this.arr[Math.floor(mid)];

};

/** 
 * Your MedianFinder object will be instantiated and called as such:
 * var obj = new MedianFinder()
 * obj.addNum(num)
 * var param_2 = obj.findMedian()
 */