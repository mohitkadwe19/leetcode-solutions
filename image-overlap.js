let img1 = [[1, 1, 0], [0, 1, 0], [0, 1, 0]], img2 = [[0, 0, 0], [0, 1, 1], [0, 0, 1]];

/**
 * @param {number[][]} img1
 * @param {number[][]} img2
 * @return {number}
 */



var largestOverlap = function (img1, img2) {

  const listA = [];
  const listB = [];

  for (let i = 0; i < img1.length; i++) {
    for (let j = 0; j < img1[0].length; j++) {
      if (img1[i][j]) listA.push([i, j]);
      if (img2[i][j]) listB.push([i, j]);
    }
  }

  const cache = {};
  let max = 0;
  for (let i = 0; i < listA.length; i++) {
    for (let j = 0; j < listB.length; j++) {
      const str = `${listA[i][0] - listB[j][0]}_${listA[i][1] - listB[j][1]}`;
      cache[str] = cache[str] || 0;
      cache[str] += 1;
      max = Math.max(max, cache[str]);
    }
  }
  return max;
};

console.log(largestOverlap(img1, img2));