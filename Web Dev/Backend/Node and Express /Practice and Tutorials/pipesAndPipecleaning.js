const fs = require('fs');
const zlib = require('zlib'); // compress a file
const gzip = zlib.createGzip();
const gunzip = zlib.createGunzip();
const readStream = fs.createReadStream('./example3.txt.gz');
const writeStream = fs.createWriteStream('./uncompressed.txt', 'utf8');
// readStream.pipe(writeStream);

readStream.pipe(gzip).pipe(writeStream);