function functionByPassValue(a){
    a+=5;
    console.log("Value a in Value Function is : ", a);
    return ;
}
function functionByPassReference(arr){
    for(let i=0;i<arr.length;i++){
        arr[i]*=2;
    }
}
let a=10;
console.log("Intial Value in parent Function is : ", a);
functionByPassValue(a);
console.log("Intial Value in parent Function after Pass by Value Funcion is : ", a);


/*
In JavaScript, all function arguments are passed by value. 
However, when you pass an object (including arrays and functions) as an argument to a 
function, you are actually passing a reference to that object.
This can create a behavior similar to pass-by-reference seen in other languages like C++.
*/
let arr=[1,2,3];

console.log("Intial Value in parent Function is : ", arr);
functionByPassReference(arr);
console.log("Intial Value in parent Function after Pass by Reference Funcion is : ", arr);

