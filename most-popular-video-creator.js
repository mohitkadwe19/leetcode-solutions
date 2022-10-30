/**
 * @param {string[]} creators
 * @param {string[]} ids
 * @param {number[]} views
 * @return {string[][]}
 */


var mostPopularCreator = function (creators, ids, views) {

  const map = {};

  for (let i = 0; i < ids.length; i++) {

    if (map[creators[i]]) {
      let {
        popularity,
        maxPopularity,
        mostViewed
      } = map[creators[i]];

      if (views[i] > maxPopularity) {

        maxPopularity = views[i];
        mostViewed = ids[i];
      }
      else if (views[i] === maxPopularity) {
        mostViewed = ids[i] < mostViewed ? ids[i] : mostViewed;
      }

      map[creators[i]] = {
        popularity: popularity + views[i],
        maxPopularity,
        mostViewed
      }

    } else {

      map[creators[i]] = {
        popularity: views[i],
        maxPopularity: views[i],
        mostViewed: ids[i]
      }
    }

  }

  let maxPopularVideoCreator = 0;

  for (let key in map) {
    if (map[key].popularity > maxPopularVideoCreator) {
      maxPopularVideoCreator = map[key].popularity;
    }
  }

  const ans = [];

  for (let key in map) {
    if (map[key].popularity === maxPopularVideoCreator) {
      ans.push([key, map[key].mostViewed]);
    }
  }

  return ans;

};


let creators = ["alice", "alice", "alice"], ids = ["a", "b", "c"], views = [1, 2, 2];
console.log(mostPopularCreator(creators, ids, views));
