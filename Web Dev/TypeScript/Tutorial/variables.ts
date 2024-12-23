let greetings: string = "Hello World";
greetings.toLowerCase();
console.log(greetings);

// number:
let userId: number = 334455;
// boolean
let isLoggedIn: boolean = false;

// any keyword
let hero: string;   
function getHero(){
    return "Iron Man";
}
hero = getHero();
// any is not a type, it is a keyword to skip type-checking , not a good practice
// NO Implicit Any: Use the compiler flag noImplicitAny to flag any implicit any as an error
export {}