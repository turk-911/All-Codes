const fs = require('fs');
// fs.mkdir('tutorial', (err)=>{
//     if(err){
//         console.log(err);
//     }
//     else{
//         // fs.rmdir('tutorial', (err)=>{ // remove directory
//         //     if(err){
//         //         console.log(err);
//         //     }
//         //     else{
//         //         console.log('succesfully deleted');
//         //     }
//         // })
//         fs.writeFile('./tutorial/example.txt', '123', (err)=>{
//             if(err){
//                 console.log(err);
//             }
//             else{
//                 console.log('succesfully created');
//             }
//         });
//         fs.unlink('./tutorial/example.txt', (err)=>{
//             if(err){
//                 console.log(err);
//             }
//             else{
//                 console.log('hogya kaam');
//             }
//         });
//         fs.rmdir('tutorial', (err)=>{ // remove directory
//             if(err){
//                 console.log(err);
//             }
//             else{
//                 console.log('succesfully deleted');
//             }
//         })
//     }
// });
// fs.rmdir is used to delete empty folders only
// fs.unlink('./tutorial/example.txt', (err) => {
//     if (err) {
//         console.log(err);
//     }
//     else {
//         console.log('hogya kaam');
//     }
// });
// fs.rmdir('tutorial', (err) => { // remove directory
//     if (err) {
//         console.log(err);
//     }
//     else {
//         console.log('succesfully deleted');
//     }
// })
fs.readdir('example', (err, files)=>{
    if(err){
        console.log(er);
    }
    else{
        for(let file of files){
            fs.unlink('./example/' + file, (err)=>{
                if(err){
                    console.log(err);
                }
                else{
                    console.log('succesfully deleted file' + file);
                }
            })
        }
    }
})