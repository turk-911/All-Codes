const fs = require('fs');
const readStream = fs.createReadStream('./example.txt', 'utf8');
const writeStream = fs.createWriteStream('example2.txt')
readStream.on('data', (chunk)=>{
    console.log(chunk);
    writeStream.write(chunk);
});

/*Benefits of using read stream method: Stream uses less buffer and reads the file */