let score: number | string = 33 // Union datatype
score = 44

type User = {
    name: string,
    id: number,
};;

type Admin = {
    username: string,
    id: number,
};

// mokshe is a simple user here
let mokshe: User | Admin = {
    name: "mokshe",
    id: 334,
};

// mokshe becomes admin
mokshe = {
    username: "mokshe",
    id: 334,
};

function getDBId(id: number | string) {
    console.log(`Database id is: ${id}`);
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
const data: number[] = [1, 2, 3];
const data1: string[] = ["1", "2", "3"];

// if we do const data3: string[] | number[] = ["1", "2", 3] --> it gives an error, either it can be fully string or fully number not a mix match // classic mistake //

// to do a mix match
const data3: (string | number | boolean)[] = [1, "2", true, false, "abcd", 3];

let pi: 3.14 = 3.14 // assignable to 3.14 only
let seatAllotment: "aisle" | "middle" | "window"
// seatAllotment = "crew" --> error

export {};
