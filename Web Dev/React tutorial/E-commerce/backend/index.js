const mongoose = require('mongoose');
const express = require('express');
const session = require('express-session');
const bodyParser = require('body-parser');
const PORT = 5500;
const mongoDBURL = "mongodb+srv://jainmokshejain2005:tooweakpass123@cluster0.rxwdatn.mongodb.net/";
mongoose.connect(mongoDBURL);

const userSchema = mongoose.Schema({
    username: {
        type: String,
        required: true,
    },
    phoneNumber: {
        type: Number,
        required: true,
    },
    email: {
        type: String,
        required: true,
    },
});

const User = mongoose.model('Users', userSchema);
const app = express();
app.use(express.json());
app.use(cors());

app.get('/', (req, res) => {
    res.send({message: 'Express Server ready'});
});
app.listen(PORT, () => {
    console.log(`App listening at ${PORT}`);
})
