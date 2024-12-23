function addTwo(num: number): number{
    return num + 2; 
    // return "hello"
}
addTwo(5);

function getUpper(val: string) {
    return val.toUpperCase();
}
getUpper("mokshe");

function signUpUser(name: string, email: string, password: string, isPaid: boolean){

}
signUpUser("mokshe", "jainmokshejain2005@gmail.com", "12345678", true);

// arrow function and adding a default value to an argument
let loginUser = (email: string, name: string, isPaid: boolean = false) => {}
loginUser("mokshe", "m@m.com");

// function getValue(myVal: number) {
//     if(myVal < 5){
//         return true;
//     }
//     return "200 OK";
// }

const getHello = (s: string): string => {
    return ""
}

const heros = ["thor", "spiderman", "iron man"];
heros.map((hero): string => {
    return `hero is ${hero}`
})

function consoleError(errmsg: string): void{
    console.log(errmsg);
}
// never is used for the time when the function never returns a value
function handleError(errmsg: string): never{
    throw new Error(errmsg);
}
export {}