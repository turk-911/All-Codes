const sum = (num1, num2) => {num1 + num2};
const PI = 3.14;
class someMathObject{
    constructor(){
        console.log("Object created..");
    }
};
module.exports = {sum : sum, PI : PI, math : someMathObject};