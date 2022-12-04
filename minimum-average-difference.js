/**
 * @param {number[]} nums
 * @return {number}
 */
var minimumAverageDifference = function (nums) {

  const avgDiff = []; // store all average difference

  let leftSum = 0; // to store the sum of the elements on the left side

  let rightSum = nums.reduce((a, b) => a + b, 0); // to store the sum of the rest of the elements

  for (let i = 0; i < nums.length; i++) {

    leftSum += nums[i]; // adjusting the sum of the left side elements

    rightSum -= nums[i]; // adjusting the sum of the rest of the elements

    const leftSide = Math.floor(leftSum / (i + 1)); // rounded down the average to the nearest integer

    const rightSide = Math.floor(rightSum / (nums.length - (i + 1))); // rounded down the average to the nearest integer

    avgDiff.push(Math.abs((leftSide ? leftSide : 0) - (rightSide ? rightSide : 0))); // store the absolute difference
  }


  return avgDiff.indexOf(Math.min(...avgDiff)); // return the index of the minimum average difference

};

let nums = [2, 5, 3, 9, 5, 3];
console.log(minimumAverageDifference(nums));