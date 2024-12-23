const User = {
    name: "mokshe",
    email: "something",
    isActive: true,
};

function createUser({ name: string, isPaid: boolean}){

}

createUser({name: "mokshe", isPaid: false})

function createCourse(): {name: string, price: number}{
    return {name: "typescript", price: 1500}
}

// type aliases - creating a datatype
type User = {
    name: string,
    email: string,
    isActive: boolean,
}

function createSomething(user: User): User{
    return user
}

createSomething({name: "", email: "", isActive: true})

type Point = {
    x: number,
    y: number,
};

function printCoordinates(pt: Point) {
    console.log(`the x-coordinate of the point is: ${pt.x}`);
    console.log(`the y-coordinate of the point is: ${pt.y}`);
}

printCoordinates({x: 100, y: 20});


type demoUser = {
    readonly _id: string,
    name: string,
    email: string,
    isActive: boolean,
    // creditCardDetails?: number  // optional
};

let myDemoUser: demoUser = {
    _id: "123455",
    name: "mokshe",
    email: "",
    isActive: false,
};

// myDemoUser._id = "12"; --> readonly keyword

type cardNumber = {
    cardnumber: string,
};

type cardDate = {
    cardDate: Date,
};

type cardDetails = cardNumber & cardDate & {
    cvv: number,
}
export {}