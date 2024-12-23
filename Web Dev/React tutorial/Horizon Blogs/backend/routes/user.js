const express = require('express');
const User = require('../models/userModel.js');
const bcrypt = require('bcrypt');
const jwt = require('jsonwebtoken');

const router = express.Router();

router.post('/signup', (req, res, next) => {
    bcrypt.hash(req.body.password, 10).then(hash => {
        const user = new User({
            username: req.body.username,
            email: req.body.email,
            password: hash,
        });
        User.findOne({email: req.body.email}).then(user1 => {
            if (user1) {
                return res.status(401).json({
                    message: "User already exists",
                });
            }
            user.save().then(result => {
                if (!result) {
                    return res.status(500).json({
                        message: "Error creating user",
                    })
                }
                res.status(201).json({
                    message: "User Created",
                    result: result
                });
            });
        }).catch(err => {
            res.status(500).json({
                error: err,
            });
        });
    });
});

router.post("/login", (req, res, next) => {
    let fetchedUser;
    User.findOne({email: req.body.email}).then(user => {
        if (!user) {
            return res.status(401).json({
                message: "Authentication failed, no such user"
            });
        }
        fetchedUser = user;
        return bcrypt.compare(req.body.password, user.password);
    }).then(result => {
        console.log(fetchedUser);
    })
})