let arr=[1,2,3,1,1,1,1,4,2,3];
let target = 3;
callBrute(arr,target);
optimizedBrute(arr,target);
callBetter(arr,target);
callOptimal(arr,target);
function callBrute(arr, target) {
    let ans = 0;
    for (let i = 0; i < arr.length; i++) {
        for (let j = i; j < arr.length; j++) {
            let sum = 0;
            for (let k = i; k <= j; k++) {
                sum += arr[k];
            }
            if (sum == target) {
                ans = Math.max(ans, j - i + 1);
            }
        }
    }
    console.log(ans);
}

function optimizedBrute(arr, target) {
    let ans = 0;
    for (let i = 0; i < arr.length; i++) {
        let sum = 0;
        for (let j = i; j < arr.length; j++) {
            sum += arr[j];
            if (sum == target) {
                ans = Math.max(ans, j - i + 1);
            }
        }
    }
    console.log(ans);
}

function callBetter(arr, target) {
    let mapp = new Map();
    let prefSum = 0;
    mapp.set(prefSum, 1);
    let ans = 0;
    
    for (let i = 0; i < arr.length; i++) {
        prefSum += arr[i];
        
        if (prefSum == target) {
            ans = Math.max(ans, i + 1);
        }
        
        let remaining = prefSum - target;
        if (mapp.has(remaining)) {
            ans = Math.max(ans, i - mapp.get(remaining));
        }
        
        if (!mapp.has(prefSum)) {
            mapp.set(prefSum, i);
        }
    }
    console.log(ans);
}

function callOptimal(arr, target) {
    let n = arr.length;
    let sum = arr[0];
    let left = 0;
    let right = 0;
    let ans = 0;
    
    while (right < n) {
        while (left <= right && sum > target) {
            sum -= arr[left];
            left++;
        }
        if (sum == target) {
            ans = Math.max(ans, right - left + 1);
        }
        right++;
        if (right < n) {
            sum += arr[right];
        }
    }
    console.log(ans);
}
