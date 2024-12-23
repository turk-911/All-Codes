// you want a specific ordering in elements --> [String, Number, Boolean] --> maybe an API Call
// let user: (string | number)[] = [1, "mj"] -> no restriction

let user: [string, number, boolean];
user = ["string", 1, true];

let rgb: [number, number, number] = [255, 123, 112]; // no opacity allowed

type User = [number, string]

const newUser: User = [112, "example@example.com"]
newUser[1] = "newMail@mail.com"; // it is const but we can change the values --> tuples are not well implemented in typescript 

export {}
