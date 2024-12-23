const fs = require('fs');
// create a file
fs.writeFile('example.txt', 'this is an example\ni am a csk fan', (err)=>{
    if(err){
        console.log(err);
    }
    else{
        console.log('File created successfuly');
        fs.readFile('example.txt','utf8', (err, file)=>{
            if(err){
                console.log(err);
            }
            else{
                console.log(file);
            }
        })
    }
});
fs.appendFile('example.txt', '\nSome data being appended', (err)=>{
    if(err){
        console.log(err);
    }
    else{
        console.log('data appended succesfully');
    }
});
// fs.unlink('example.rs', (err)=>{
//     if(err){
//         console.log(err);
//     }
//     else{
//         console.log('File deleted successfuly...');
//     }
// });
fs.rename('example3.ex', 'example3.exs', (err)=>{
    if(err){
        console.log(err);
    }
    else{
        console.log('File renamed succesfully');
    }
});