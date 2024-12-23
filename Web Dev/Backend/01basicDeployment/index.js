require('dotenv').config();
const express = require('express');
const app = express();
const port = 3000;
app.get('/', (req, res) => {
    res.send('Hello World');
});
app.get('/mokshe', (req, res) => {
    res.send('Hello Mokshe');
});
app.get('/login', (req, res) => {
    res.send('Login here');
})
app.listen(process.env.PORT, () => {
    console.log(`App listening at ${port}`);
})