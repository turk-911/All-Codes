"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
var User = {
    name: "mokshe",
    email: "something",
    isActive: true,
};
function createUser(_a) {
    var string = _a.name, boolean = _a.isPaid;
}
createUser({ name: "mokshe", isPaid: false });
function createCourse() {
    return { name: "typescript", price: 1500 };
}
function createSomething(user) {
    return user;
}
createSomething({ name: "", email: "", isActive: true });
function printCoordinates(pt) {
    console.log("the x-coordinate of the point is: ".concat(pt.x));
    console.log("the y-coordinate of the point is: ".concat(pt.y));
}
printCoordinates({ x: 100, y: 20 });
var myDemoUser = {
    _id: "123455",
    name: "mokshe",
    email: "",
    isActive: false,
};
