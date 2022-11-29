
class RandomizedSet {

  constructor() {

    this.set = new Set();

  }

  insert(val) {

    if (this.set.has(val)) return false;

    this.set.add(val);

    return true;

  }

  remove(val) {

    if (!this.set.has(val)) return false;

    this.set.delete(val);

    return true;

  }

  getRandom() {

    let arr = [...this.set];

    return arr[Math.floor(Math.random() * arr.length)];

  }


}

let obj = new RandomizedSet();
let arr = ["RandomizedSet", "insert", "remove", "insert", "getRandom", "remove", "insert", "getRandom"];
let arr2 = [[], [1], [2], [2], [], [1], [2], []];

for (let i = 0; i < arr.length; i++) {
  if (i === 0) {
    console.log(obj);
  } else {
    console.log(obj[arr[i]](arr2[i][0]));
  }
}


