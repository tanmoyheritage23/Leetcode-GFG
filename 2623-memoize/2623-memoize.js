/**
 * @param {Function} fn
 * @return {Function}
 */
function memoize(fn) {
  const memo = {};
  return function (...args) {
    const index = JSON.stringify(args);
    //console.log(index);

    // if memoized then return
    if (memo.hasOwnProperty(index)) return memo[index];

    return (memo[index] = fn(...args));
  };
}

/**
 * let callCount = 0;
 * const memoizedFn = memoize(function (a, b) {
 *	 callCount += 1;
 *   return a + b;
 * })
 * memoizedFn(2, 3) // 5
 * memoizedFn(2, 3) // 5
 * console.log(callCount) // 1
 */
