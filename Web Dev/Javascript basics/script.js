// fetch API





// // Immediately invoked function expression ---- IIFE
// (async function (){
//     console.log("getting data 1 ...");
//     await getData(1);
//     console.log("getting data 2..");
//     await getData(2);
//     console.log("this was an example of immediately invoked function expression---IIFE");
// })();


// function getData(dataId){
//     return new Promise((resolve, reject) => {
//         setTimeout(() => {
//             console.log("data", dataId);
//             resolve("success");
//         }, 2000);
//     });
// }

// // Async - Await

// async function getAllData(){
//     await getData(1);
//     console.log("First function call completed");
//     await getData(2);
//     console.log("Second function call completed");
// }



// async function hello(){
//     console.log("hello");
// }
// function api(){
//     return new Promise((resolve, reject) => {
//         setTimeout(() => {
//             console.log("Weather data");
//             resolve(200);
//         }, 2000);
//     });
// }
// async function getWeather(){
//     await api();
//     console.log("First function call completed");
//     await api();
//     console.log("Second function call completed");
// }
// function asyncFunc(){
//     return new Promise((resolve, reject) => {
//         setTimeout(()=>{
//             console.log("some data");
//             resolve("success");
//         }, 4000)
//     })
// }
// function asyncFunc2(){
//     return new Promise((resolve, reject) =>{
//         setTimeout(()=>{
//             console.log("some data 2");
//             resolve("success");
//         }, 4000);
//     })
// }
// console.log("This is the example of a promise chain");
// console.log("Fetching data 1...");
// let promise1 = asyncFunc();
// promise1.then((res)=>{
//     console.log(res);
//     console.log("first promise completed, start for promise 2");
//     console.log("fetching some data 2...");
//     let promise2 = asyncFunc2();
//     promise2.then((res)=>{
//         console.log(res);
//         console.log("Fetching of data stopped.");
//     })
// })

// // better way of writing the above code:
// // asyncFunc().then((res) => {
// //     return asyncFunc2();
// // }).then((res) => {
// //     console.log(res);
// // });

// // const getPromise = ()=>{
// //     return new Promise((resolve, reject) =>{
//         console.log("I am a promise");
//         reject("error");
//     });
// }
// let promise = getPromise();
// promise.then((res)=>{
//     console.log("Promise has been succesfully resolved", res);
// });
// promise.catch((err)=>{
//     console.log("Promise has not been fulfilled", err);
// })

// let promise = new Promise((resolve, reject) =>{
//     console.log("hello, i am a new promise");
//     reject("some error");
// })


// function hello(){
//     console.log("hello");
// }
// setTimeout(()=>{
//     console.log("hello");
// }, 2000); // setTimeout sets the interval of time for a function to get executed


// function sum(a, b){
//     // return a + b;
//     console.log(a + b);
// }
// function calculator(a, b, sum){
//     sum(a, b);
// }
// calculator(3, 4, sum);
// calculator(5, 6, (a, b)=>{
//     console.log(a + b);
// })

// function getData(dataID, getNextData){
//     setTimeout(()=>{
//         console.log("data", dataID);
//         if(getNextData){
//             getNextData();
//         }
//     }, 2000);
// }
// console.log("getting data1...");
// getData(1, ()=>{
//     console.log("getting data2...");
//     getData(2, ()=>{
//         console.log("getting data3...");
//         getData(3, ()=> {
//             console.log("getting data4...");
//             getData(4);
//         })
//     });
// })