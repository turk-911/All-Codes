// CommonJS, every file is module (by default)
// Modules - Encapsulated Code(only share minimum)
// We only share what we want
// Encapsulated meaning - enclosed by a protective coating or membrane
const secret = 'SUPER SECRET';
const john = 'john';
const peter = 'peter';
const sayHi = (name) => {
    console.log(`Hello there ${name}`);
}
sayHi('susan');
sayHi(john);
sayHi(peter);

const names = require('./intoToNode');
console.log(names.harry);

// module.exports = {sayHi};

console.log(names.tom);
