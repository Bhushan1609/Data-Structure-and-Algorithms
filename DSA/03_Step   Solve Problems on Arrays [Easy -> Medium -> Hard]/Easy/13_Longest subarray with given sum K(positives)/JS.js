let v1 = [1, 2, 3, 1, 1, 1, 1, 4, 2, 3];
let v2 = [1, 2, 3, 1, 1, 1, 1, 4, 2, 3];
let v3 = [1, 2, 3, 1, 1, 1, 1, 4, 2, 3];
let v4 = [1, 2, 3, 1, 1, 1, 1, 4, 2, 3];
let k = 3;
brute(v1, k);
brute1(v2, k);
better(v3, k);
optimal(v4, k);
function brute(v, k) {
    let ans = 0;
    for (let i = 0; i < v.length; i++) {
        for (let j = i; j < v.length; j++) {
            let sum = 0;
            for (let l = i; l <= j; l++) {
                sum += v[l];
            }
            if (sum == k) {
                ans = Math.max(ans, j - i + 1);
            }
        }
    }
    console.log(ans);
}

function brute1(v, k) {
    let ans = 0;
    for (let i = 0; i < v.length; i++) {
        let sum = 0;
        for (let j = i; j < v.length; j++) {
            sum += v[j];
            if (sum == k) {
                ans = Math.max(ans, j - i + 1);
            }
        }
    }
    console.log(ans);
}

function better(v, k) {
    let mapp = new Map();
    let prefSum = 0;
    mapp.set(prefSum, 1);
    let ans = 0;
    
    for (let i = 0; i < v.length; i++) {
        prefSum += v[i];
        
        if (prefSum == k) {
            ans = Math.max(ans, i + 1);
        }
        
        let remaining = prefSum - k;
        if (mapp.has(remaining)) {
            ans = Math.max(ans, i - mapp.get(remaining));
        }
        
        if (!mapp.has(prefSum)) {
            mapp.set(prefSum, i);
        }
    }
    console.log(ans);
}

function optimal(v, k) {
    let n = v.length;
    let sum = v[0];
    let left = 0;
    let right = 0;
    let ans = 0;
    
    while (right < n) {
        while (left <= right && sum > k) {
            sum -= v[left];
            left++;
        }
        if (sum == k) {
            ans = Math.max(ans, right - left + 1);
        }
        right++;
        if (right < n) {
            sum += v[right];
        }
    }
    console.log(ans);
}
