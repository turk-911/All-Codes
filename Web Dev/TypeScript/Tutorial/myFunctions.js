"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
function addTwo(num) {
    return num + 2;
    // return "hello"
}
addTwo(5);
function getUpper(val) {
    return val.toUpperCase();
}
getUpper("mokshe");
function signUpUser(name, email, password, isPaid) {
}
signUpUser("mokshe", "jainmokshejain2005@gmail.com", "12345678", true);
// arrow function and adding a default value to an argument
var loginUser = function (email, name, isPaid) {
    if (isPaid === void 0) { isPaid = false; }
};
loginUser("mokshe", "m@m.com");
// function getValue(myVal: number) {
//     if(myVal < 5){
//         return true;
//     }
//     return "200 OK";
// }
var getHello = function (s) {
    return "";
};
var heros = ["thor", "spiderman", "iron man"];
heros.map(function (hero) {
    return "hero is ".concat(hero);
});
function consoleError(errmsg) {
    console.log(errmsg);
}
// never is used for the time when the function never returns a value
function handleError(errmsg) {
    throw new Error(errmsg);
}
