const http = require('http');
const fs = require('fs');
http.createServer((req, res)=>{
    const readStream = fs.createReadStream('./example/main.cpp');
    res.writeHead(200, {'Content-type': 'text-cpp'});
    readStream.pipe(res);
}).listen(3000);