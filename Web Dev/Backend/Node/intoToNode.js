// Globals -> No window
// __dirname - path to current directory
// __filename - file name
// require - function to use modules[Common JS]
// module - info about current module (file)
// process - info about env where the program is being exceuted
const amount = 9;
if(amount < 10){
    console.log("it is a small number");
}
else{
    console.log("large number");
}
// console.log("First node program");
// console.log(__dirname);
// setInterval(() => {
//     console.log("hello world");
// }, 1000);

const tom = 'tom';
const harry = 'harry';
module.exports = {tom, harry};

// const sayHi = require('./modulesInNodes');

// console.log(sayHi);