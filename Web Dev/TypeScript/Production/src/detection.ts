function detectType(val: number | string) {
    if(typeof val === "string") {
        return val.toLowerCase()
    }
    return val + 3
}

// typeof Array => object
function provideId(id: string | null) {
    if(!id) {
        alert("Please provide an id");
        return
    }
    id.toLowerCase()
}

// do not do this => breaks in case of strs === ""
function printAll(strs: string | Array<string> | null) {
    if(strs) {
        if(typeof strs === "object") {
            for(const s of strs) {
                console.log(s);
            }
        }
        else if(typeof strs === "string") {
            console.log(strs);
        }
    }
}

// type narrowing
interface User {
    name: string,
    email: string,
}

interface Admin {
    name: string,
    email: string,
    isAdmin: string,
}

function isAdminAccount(account: User | Admin) {
    if("isAdmin" in account) {
        return account.isAdmin
    }
    return false
}

// instanceof is a keyword which checks the type of data is an instance of a class or not, very similar to typeof
function logValue(x: Date | string) {
    if(x instanceof Date) {
        console.log(x.toUTCString);
    } else {
        console.log(x.toUpperCase());
    }
}

type Fish = {
    swim: () => void
};

type Bird = {
    fly: () => void
};

function isFish(pet: Fish | Bird): pet is Fish { // new syntax 
    return (pet as Fish).swim !== undefined
}

function getFood(pet: Fish | Bird) {
    if(isFish(pet)) {
        pet
        return "fish food"
    } else {
        pet // type of pet is still not clear if it is fish or bird or both 
        // after pet is Fish it is very clear
        return "bird food"
    }
}

interface Circle {
    kind: "Circle",
    radius: number
}

interface Square {
    kind: "Square",
    side: number
}

interface Rectangle {
    kind: "Rectangle",
    length: number,
    breadth: number
}

type Shape = Circle | Square | Rectangle

function getTrueShape(shape: Shape) {
    if(shape.kind === "Circle") {
        return Math.PI * shape.radius ** 2
    } else {
        // return shape.side ** 2
    }
}

function getArea(shape: Shape) {
    switch(shape.kind) {
        case "Circle": 
            return Math.PI * shape.radius ** 2
        case "Square":
            return shape.side ** 2
        case "Rectangle":
            return shape.breadth * shape.length
        default:
            const _exhaustiveCheck: never = shape
            return _exhaustiveCheck
    }
}
