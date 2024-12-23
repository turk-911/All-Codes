const express = require('express'); // we get a function which returns a object
const bodyParser = require('body-parser');
const Joi = require('joi');
const path = require('path');
const app = express();
app.use('/public', express.static(path.join(__dirname, 'example')));
app.get('/', (req, res)=>{
    res.sendFile(path.join(__dirname, 'example', 'index.html'));
});
app.get('/example', (req, res)=>{
    res.send('hitting example route');
});
app.get('/example/:name/:age', (req, res)=>{
    console.log(req.params);
    console.log(req.query);
    res.send(req.params.name + ' : ' + req.params.age);
});
app.listen(3000); 
