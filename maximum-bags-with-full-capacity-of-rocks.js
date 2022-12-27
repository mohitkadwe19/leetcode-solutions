/**
 * @param {number[]} capacity
 * @param {number[]} rocks
 * @param {number} additionalRocks
 * @return {number}
 */
var maximumBags = function (capacity, rocks, additionalRocks) {

  let arr = [];
  let ans = 0;

  for (let i = 0; i < capacity.length; i++) {
    arr.push([capacity[i], rocks[i], capacity[i] - rocks[i]]);
  }

  arr.sort((a, b) => a[2] - b[2]); // sorting in ascending order on the based of remaining capacity (capacity[i] - rocks[i])

  for (let i = 0; i < arr.length; i++) {
    let [cap, rock, rem] = arr[i];
    if (cap - rock == 0) {  // full capacity
      ans++;
    } else {               // remaining capacity
      let temp = cap - rock;

      if (additionalRocks > 0 && temp <= additionalRocks) {
        additionalRocks -= temp;
        ans++;
      }
    }
  }

  return ans;


};

let capacity = [2, 3, 4, 5], rocks = [1, 2, 4, 4], additionalRocks = 2;
console.log(maximumBags(capacity, rocks, additionalRocks));