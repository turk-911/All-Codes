const os = require('os');

// info about current user

const user = os.userInfo();
console.log(user);

// method returns the uptime of the system
console.log(`the system is up for ${os.uptime()} seconds`);

const currentOS = {
    name : os.type(),
    release : os.release(),
    totalMem : os.totalmem(),
    free : os.freemem()
};

console.log(currentOS);


// path module
console.log("The path is: ");
const path = require('path');
console.log(path.sep);

const filePath = path.join('/content','subfolder', 'text.txt');
console.log(filePath);

// method to access only the last of the file path -- text.txt in this case
const base = path.basename(filePath);
console.log(`the base name is: ${base}`);

// method to get the absolute path
const absolute = path.resolve(__dirname, 'content', 'subfolder', 'text.txt');

console.log(absolute);


// FS module(sync)
const {readFileSync, writeFileSync} = require('fs');
console.log("Reading the first file");
const first = readFileSync('text.txt', 'utf8');
console.log("reading the second file");
const second = readFileSync('text.txt', 'utf8');
console.log(`the first file was ${first} and the second file was ${second}`, second);

const {readFile, writeFile} = require('fs');
writeFileSync(
    'newFile.txt', `the concatenea.. file is: ${first}....${second}`
); 

// buffer value is provided if we do not provide the character set utf-8
// setting up callback hell
readFile('text.txt', 'utf8', (err, result) => {
    if(err){
        console.log(err);
        return;
    }
    const first = result;
    readFile('newFile.txt', 'utf8', (err, result) => {
        if(err){
            console.log(err);
            return;
        }
        const second = result;
        writeFile('newFile2.txt', `Here is the result...${first}....${second}`, (err, result) => {
            if(err){
                console.log(err);
                return;
            }
            console.log(result);
        });
    })
})