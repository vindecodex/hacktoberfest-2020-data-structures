// function to merge arrays
function merge(left, right) {
    let arr = []
    while (left.length && right.length) {
        // Pick the smaller among the smallest element of left and right sub arrays 
        if (left[0] < right[0]) {
            arr.push(left.shift())  
        } else {
            arr.push(right.shift()) 
        }
    }
    return [ ...arr, ...left, ...right ]
}

// function to split array
function mergeSort(array) {
  const half = array.length / 2
  
  // Base case or terminating case
  if(array.length < 2){
    return array 
  }
  
  const left = array.splice(0, half)
  return merge(mergeSort(left),mergeSort(array))
}

array = [400, 882, 349, 221, 191, 73, 33];
console.log(mergeSort(array));

//Output will be 33,73,191,221,349,400,882

// All Case Time Complexity will be O(nlogn)
