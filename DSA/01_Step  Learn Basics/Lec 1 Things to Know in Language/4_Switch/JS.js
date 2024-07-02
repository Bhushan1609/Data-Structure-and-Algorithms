const cin=require("prompt-sync")();
console.log("Enter 2 integer");
let a=parseInt(cin()),b=parseInt(cin());
console.log("1.Add\n2.Sub\n3.Mul\n4.Div\n");
let choice=parseInt(cin());
switch (choice){
    case 1:
        console.log(a+b);
        break;
    case 2:
        console.log(a-b);
        break;
    case 3:
        console.log(a*b);
        break;
    case 4:
        console.log(a/b);
        break;
    default:
        console.log("Wrong Input");
}