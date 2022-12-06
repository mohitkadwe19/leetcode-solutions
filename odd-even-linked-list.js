
function ListNode(val, next) {
  this.val = (val === undefined ? 0 : val)
  this.next = (next === undefined ? null : next)
}

/**
 * @param {ListNode} head
 * @return {ListNode}
 */

let oddEvenList = function (head) {

  if (!head) return null;

  let odd = head;
  let even = head.next;
  let evenHead = even;

  while (even && even.next) {
    odd.next = even.next;
    odd = odd.next;
    even.next = odd.next;
    even = even.next;
  }

  odd.next = evenHead;

  return head;

};

let head = [1, 2, 3, 4, 5];

for (let i = 0; i < head.length; i++) {
  head[i] = new ListNode(head[i]);
}

console.log(oddEvenList(head));
