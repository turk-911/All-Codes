const tutorial = require('./tutorial');
// console.log(tutorial);
// console.log(tutorial.sum(1, 1));
// console.log(tutorial.PI);
// console.log(new tutorial.math());

const EventEmitter = require('events');
const eventEmitter = new EventEmitter();
// eventEmitter.on(tutorial, () => {
//     console.log('tutorial event has occured');
// });
// eventEmitter.emit(tutorial);

eventEmitter.on('tutorial', (num1, num2) => {
    console.log(num1 + num2);
});
eventEmitter.emit('tutorial', 14, 2);

class Person extends EventEmitter{
    constructor(name){
        super();
        this._name = name;
    }
    get name(){
        return this._name;
    }
}
// Person is the extension of the event emitter class
let mokshe = new Person('Mokshe');
let sidham = new Person('Sidham');
sidham.on('name', ()=>{
    console.log('my name is ' + sidham.name);
});
mokshe.on('name', ()=>{
    console.log('my name is ' + mokshe.name);
});
sidham.emit('name');
mokshe.emit('name');