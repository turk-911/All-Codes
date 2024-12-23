// const superHeros = [];
// superHeros.push("spiderman");
// If we try to do this it gives an error because a string is not assignable to type never

// Correct way
const superHeros: string[] = [];
const heroPower: Array<number> = [];
superHeros.push("spiderman");

type User = {
    name: string,
    isActive: boolean,
};

const allUsers: Array<User> = [];
heroPower.push(2);

allUsers.push({name: "mokshe", isActive: true});

const MLModels: number[][] = [
    [255, 255, 255],
    [],
];

export{};