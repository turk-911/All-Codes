// const student = {
//     fullName : "Mokshe Jain",
//     age : 18, 
//     enrollmentNumber : "IIB2023034",
//     cgpa : 8.2,
//     isPass : true
// };
// let a = 5;
// let b = 2;
// console.log("a ** b =", a ** b);
// console.log("The type is:", typeof student);
// console.log("The age of student is:", student["age"]);
// console.log("Name of the student is: ", student.fullName);
// console.log("The enrollment number of the student is:", student.enrollmentNumber);
// if(student.isPass){
//     console.log("The student is passed");
//     console.log("The CGPA of the student is:", student.cgpa);
// }
// else{
//     console.log("the student is failed");
// }

// for(let i = 0; i < 5; i++){
//     console.log("i =", i);
// }

// let str = "Mokshe Jain";
// let len = 0;
// for(let i of str){
//     len = len + 1;
// }
// console.log("Length of string", str, "is", len);

// for(let key in student){
//     console.log(key, ":", student[key]);
// }

// for(let i = 2; i <= 100; i = i + 2){
//     console.log(i);
// }

// function sum(x, y){
//     s = x + y;
//     console.log("Before returning");
//     return s;
//     console.log("After returning");
// }

// let x = 1000000;
// let y = 111111;
// sum = sum(x, y);
// console.log(sum);

// const arrowSum = (a, b) => {
//     console.log(a + b);
// };

// console.log(arrowSum(1, 2));

// let print = () => console.log("Hello World");
// print();

// arrow function to count vowels in a string
const countVowels = (str) => {
    let count = 0;
    for(char in str){
        if(char == 'a' || char == 'e' || char == 'i' || char == 'o' || char == 'u'){
            count = count + 1;
        }
    }
    return count;
}
let str = "a quick brown fox jumps over the lazy dog";
let numOfVowels = countVowels("mokshe");
console.log("number of vowels =", numOfVowels);