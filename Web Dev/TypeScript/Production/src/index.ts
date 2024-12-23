// class User {
//     email: string
//     name: string
//     private readonly city: string = "Mumbai" // cannot access it 
//     constructor(email: string, name: string) {
//         this.email = email;
//         this.name = name;
//     }
// }
// more professional way of writing the same thing

class User {
    protected _courseCount = 1;
    readonly city: string = "Ludhiana";
    constructor(
        public email: string,
        public name: string,
        // private userId: string,
    ) {}

    // getters and setters
    get getAppleEmail(): string {
        return `apple${this.email}`
    }

    get CourseCount(): number {
        return this._courseCount
    }

    set courseCount(courseNumber: number) {
        if(courseNumber <= 1) {
            throw new Error("course count should be more than 1")
        }
        this._courseCount = courseNumber
    }
}

class subUser extends User {
    isFamily: boolean = true
    changeCourseCount() {
        this._courseCount = 4
    }
}
const mokshe = new User("","");

// everything you don't mark is public and for private you have to write private
// protected keyword makes the property accessible in the same class as well as all the classes which extends that class
