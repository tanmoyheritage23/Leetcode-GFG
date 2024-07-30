/**
 * @param {Function[]} functions
 * @return {Function}
 */
var compose = function(functions) {
    
    return function(x) {
       const n = functions.length;
       for(let i = n-1; i >= 0; i--){
           const fn = functions[i];
           x = fn(x);
          
       }
        
        return x;
    }
};

/**
 * const fn = compose([x => x + 1, x => 2 * x])
 * fn(4) // 9
 */