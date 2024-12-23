"use strict";
// you want a specific ordering in elements --> [String, Number, Boolean] --> maybe an API Call
// let user: (string | number)[] = [1, "mj"] -> no restriction
Object.defineProperty(exports, "__esModule", { value: true });
var user;
user = ["string", 1, true];
var rgb = [255, 123, 112]; // no opacity allowed
var newUser = [112, "example@example.com"];
newUser[1] = "newMail@mail.com"; // it is const but we can change the values --> tuples are not well implemented in typescript 
