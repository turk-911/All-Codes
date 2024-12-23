require('dotenv').config();

const mongoose = require('mongoose');
const express = require('express');
const cors = require('cors')
const app = express();
app.use(express.json())

const port = process.env.PORT;
const MONGODBURL = "mongodb+srv://jainmokshejain2005:newdbpass123@cluster0.wo5ulcu.mongodb.net/";

mongoose.connect(MONGODBURL).then(() => {
    console.log('App is connected to database');
})
app.use(cors());
app.get("/hello", (req, res) => {
    res.send("hello world");
});
app.get("/", (req, res) => {
    const { email, password } = req.body;
    console.log(email);
    res.json('done')
})
app.post("/login", (req, res) => {
    const {email, password} = req.body;
    console.log(email);
    res.json("done");
})
app.listen(5500, (req, res) => {
    console.log("server up and running");
})
