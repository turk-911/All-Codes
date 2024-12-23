"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
var score = 33; // Union datatype
score = 44;
;
// mokshe is a simple user here
var mokshe = {
    name: "mokshe",
    id: 334,
};
// mokshe becomes admin
mokshe = {
    username: "mokshe",
    id: 334,
};
function getDBId(id) {
    console.log("Database id is: ".concat(id));
    if (typeof id === "string") {
        id.toLowerCase();
    }
    else {
        id += 2;
    }
}
getDBId(3);
getDBId("3");
// It does not treat the variable as a number or a string only, it treats it as a new datatype which could eventually have new cases --> we cannot do id.toLowerCase()
// arrays with union datatypes
var data = [1, 2, 3];
var data1 = ["1", "2", "3"];
// if we do const data3: string[] | number[] = ["1", "2", 3] --> it gives an error, either it can be fully string or fully number not a mix match // classic mistake //
// to do a mix match
var data3 = [1, "2", true, false, "abcd", 3];
var pi = 3.14; // assignable to 3.14 only
var seatAllotment;
