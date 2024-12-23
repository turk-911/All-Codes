interface User {
    readonly dbId: number,
    email: string,
    userId: number,
    googleId?: string,
    // startTrial: () => string --> method 1
    startTrial(): string // method 2
    getCoupon(couponName: string): number
}

const mokshe: User = {
    dbId: 221,
    email: "",
    userId: 2,
    startTrial: () => {
        return "hello world"
    },
    getCoupon: (name: "mokshe10") => {
        return 10
    }
}

interface AnotherInterface {
    something: "something"
}

interface Admin extends User, AnotherInterface {
    role: "admin" | "ta" | "learner"
}

const moksheJain: Admin = {
    dbId: 221,
    email: "",
    userId: 2,
    startTrial: () => {
        return "hello world"
    },
    getCoupon: (name: "mokshe10") => {
        return 10
    },
    role: "admin",
    something: "something",
}

// type cannot be changed after being defined, interface can be

export {}
