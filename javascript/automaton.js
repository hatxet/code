/*
 * Design a simple automaton
 * A = { 
 *    Q: {q1, q2, q3},
 *    sigma: {0,1},
 *    delta: { {q1, 0, q1}, {q1, 1, q2}, {q2, 0, q3}, {q2, 1, q2}, {q3, 0, q2}, {q3, 1, q2} },
 *    q0: q1,
 *    F: q2,
 * }
 * https://www.codewars.com/kata/design-a-simple-automaton-finite-state-machine
 */

function Automaton() {
  this.Q = ['q1', 'q2', 'q3'];
  this.sigma = [0, 1];
  this.initial = this.Q[0];
  this.final = this.Q[1];
  this.delta = {};
  this.delta[[this.Q[0], this.sigma[0]]] = this.Q[0];
  this.delta[[this.Q[0], this.sigma[1]]] = this.Q[1];
  this.delta[[this.Q[1], this.sigma[0]]] = this.Q[2];
  this.delta[[this.Q[1], this.sigma[1]]] = this.Q[1];
  this.delta[[this.Q[2], this.sigma[0]]] = this.Q[1];
  this.delta[[this.Q[2], this.sigma[1]]] = this.Q[1];
}

Automaton.prototype.readCommands = function (commands) {
  // Return true if we end in our accept state, false otherwise.
  let q = this.initial;
  for (let sigma of commands) {
    q = this.delta[[q, sigma]];
  }
  return (q === this.final) ? true : false;
}

var myAutomaton = new Automaton();
[["1"], ["1", "0", "0", "1"], '00000'].forEach(n => {
  if (myAutomaton.readCommands(n)) {
    console.log('ACCEPT: ' + n);
  } else {
    console.log('FAIL: ' + n);
  }
});

/*
 * Other solutions
 * return /^0*1(1|00|01)*$/.test(commands.join(''));
 *
 * function Automaton() {
 *    this.trans = {
 *      'q1': { '0': 'q1', '1': 'q2' },
 *      'q2': { '0': 'q3', '1': 'q2' },
 *      'q3': { '0': 'q2', '1': 'q2' }
 *    };
 * }
 * Automaton.prototype.readCommands = function(commands)
 * {
 *    var state = 'q1';
 *    var that = this;
 *    commands.forEach( command => state = that.trans[state][command]);
 *    return (state === 'q2');
 * }
 */
