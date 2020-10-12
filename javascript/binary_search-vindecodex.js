let BS = function (arr, targetValue) { 
   
    let start=0, end=arr.length-1; 
          
    while (start<=end){ 
        let mid=Math.floor((start + end)/2); 
        if (arr[mid]===targetValue) return true; 
        else if (arr[mid] < targetValue)  
             start = mid + 1; 
        else
             end = mid - 1; 
    } 
    return false; 
}
   
   // Examples inputs

let arr = [1, 3, 5, 7, 8, 9]; 
let targetValue = 5; 

if (BS(arr, targetValue, 0, arr.length-1)) 
    console.log(`${targetValue} was found!`)
else console.log(`${targetValue} was not found!`)
