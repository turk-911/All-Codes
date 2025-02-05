const express = require('express');
const path = require('path');
const bodyParser = require('body-parser')
const app = express();
app.use('/public', express.static(path.join(__dirname, 'post')));
app.use(bodyParser.urlencoded({extended : false}));
app.get('/', (req, res)=>{
    res.sendFile(path.join(__dirname, 'post', 'index.html'));
});
app.post('/', (req, res)=>{
    console.log(req.body);
    // database work here
    res.send('Succesfully posted data');
});
app.listen(3000);