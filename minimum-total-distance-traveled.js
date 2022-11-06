/**
 * @param {number[]} robot
 * @param {number[][]} factory
 * @return {number}
 */
var minimumTotalDistance = function (robot, factory) {

  //   You are given an array of integers robot and an array of arrays of integers factory. The ith element of factory is a 2 - dimensional array of integers[factory[i][0], factory[i][1]] representing the location of the ith factory on a 2D map.
  //   You are also given an integer array robot representing the location of the robot on the same 2D map.
  //   The robot is initially located at the location specified by robot. In one step, the robot can move one unit to the left, right, up, or down. The robot cannot move to a location outside of the grid.
  //   The robot wants to visit all the factories in the factory array. The robot will visit the ith factory if Manhattan distance between the location of the robot and the location of the ith factory is less than or equal to factory[i][2]. Otherwise, the robot will not visit the ith factory.
  //   Return the minimum total distance the robot needs to travel to visit all the factories. If the robot cannot visit all the factories, return -1.
  //   The Manhattan distance between two points[a, b] and[c, d] is abs(a - c) + abs(b - d).

  let minDistance = [];

  for (let i = 0; i < factory.length; i++) {

    const factoryX = factory[i][0];
    const factoryY = factory[i][1];
    const factoryDistance = factory[i][2];

    const robotX = robot[0];
    const robotY = robot[1];

    const distance = Math.abs(factoryX - robotX) + Math.abs(factoryY - robotY);

    if (distance > factoryDistance) {
      return -1;
    }
    else {
      minDistance.push(distance);
    }
  }

  // return minimum element 
  return Math.min(...minDistance);
};

let robot = [1, -1], factory = [[-2, 1], [2, 1]];
let result = minimumTotalDistance(robot, factory);
console.log(result);