function createCalcFunction(n) {
  let c = 999;
  return function() {
    console.log(c)
    console.log(111 * n)
  }
}


const calc = createCalcFunction(4)
calc()












