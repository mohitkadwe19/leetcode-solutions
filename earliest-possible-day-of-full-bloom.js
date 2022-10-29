/**
 * @param {number[]} plantTime
 * @param {number[]} growTime
 * @return {number}
 */



var earliestFullBloom = function (plantTime, growTime) {

  let timeArray = [];

  let totalPlantTime = 0, totalBloomTime = 0;

  for (let i in plantTime) {
    timeArray.push([plantTime[i], growTime[i]]);
  }
  timeArray.sort((a, b) => b[1] - a[1]);

  for (let [plantTime, growTime] of timeArray) {
    totalPlantTime += plantTime;
    totalBloomTime = Math.max(totalBloomTime, totalPlantTime + growTime);
  }
  return totalBloomTime;

};

let plantTime = [1, 2, 3, 2], growTime = [2, 1, 2, 1];

console.log(earliestFullBloom(plantTime, growTime));