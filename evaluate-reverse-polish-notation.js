/**
 * @param {string[]} tokens
 * @return {number}
 */
var evalRPN = function (tokens) {

  let st = []
  let ops = {
    '+': (a, b) => a + b,
    '-': (a, b) => a - b,
    '*': (a, b) => a * b,
    '/': (a, b) => a / b | 0,
  }

  for (let to of tokens)
    if (to in ops)
      st[st.length - 2] = ops[to](st[st.length - 2], st.pop())
    else
      st.push(parseInt(to))

  return st[0];

};

let tokens = ["2", "1", "+", "3", "*"];
console.log(evalRPN(tokens));