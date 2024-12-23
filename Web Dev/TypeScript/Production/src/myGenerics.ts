const score: Array<number> = []
const names: Array<string> = []

function idenityOne(val: boolean | number): boolean | number {
    return val
}

function identityTwo(val: any): any {
    return val
}

function identityThree<Type> (val: Type): Type {
    return val
}

identityThree(0)

function idenityFour<T> (val: T): T {
    return val
}

interface Bottle {
    brand: string,
    type: string,
}

idenityFour<Bottle>({
    brand: "Tupperware",
    type: "gym"
})

function getSearchProducts<T>(products: Array<T>): T {
    // do some database operations
    let myIndex = 3
    return products[myIndex]
}

// how do we convert the above function to an arrow function
const getSearchProductsArrowFunction = <T>(products: Array<T>): T => {
    // do some database operations
    let myIndex = 3
    return products[myIndex]
}

// <T,> --> used to specify that it is not a JSX syntax 

function anotherFunction<T, U extends number>(val1: T, val2: U):object {
    return {
        val1, val2
    }
}

anotherFunction(3, 18)

interface Database {
    connection: string,
    username: string,
    password: string,
}

interface Quiz {
    name: string,
    type: string,
}

interface Course {
    name: string,
    author: string,
    subject: string,
}

class Sellable<T> {
    public cart: Array<T> = []
    addToCart(product: T) {
        this.cart.push(product)
    }
}
