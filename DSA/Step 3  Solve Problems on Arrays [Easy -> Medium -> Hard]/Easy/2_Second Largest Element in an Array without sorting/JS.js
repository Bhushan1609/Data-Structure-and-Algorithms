const cin=require("prompt-sync")();
let v=[5,67,890,1,23,345];
brute(v);
better(v);
optimal(v);
function brute(v){
    v.sort((a, b) => a - b); 
    let i=v.length-1,ans=-1;
    while(i>0){
        if(v[i-1] != v[i]){
		    ans=v[i-1];
            console.log(ans);
		    return ;
	    }
        i--;
    }
   
}
function better(v){
    let ans=-Infinity,ans2=-Infinity;
    for(let i=0;i<v.length;i++) ans=Math.max(ans,v[i]);
	for(let i=0;i<v.length;i++){
		if(v[i] != ans)ans2=Math.max(ans2,v[i]);
	}
    console.log(ans2);
}
function optimal(v){
    let ans=-Infinity,ans2=-Infinity;
    for(let i=0;i<v.length;i++){
		if(v[i]>ans){
			ans2=ans;
			ans=v[i];
		}
		else{
			if(v[i]>ans2)ans2=v[i];
		}
	}
    console.log(ans2);

}