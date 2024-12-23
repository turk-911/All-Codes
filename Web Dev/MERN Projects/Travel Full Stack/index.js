const mongoose = require("mongoose");
const express = require("express");
const ejs = require("ejs");
const session = require("express-session");
const bcrypt = require("bcrypt");
const bodyParser = require("body-parser");

const port = 5173;

mongoose.connect("mongodb+srv://vansh:vansh123@cluster0.po6d5co.mongodb.net/");

const app = express();
app.use(express.json());
app.use(bodyParser.urlencoded({ extended: true }));
app.use(bodyParser.json());
app.set("view engine", "ejs");
app.use(express.static("public"));
app.use(
  session({
    secret: "123456",
    resave: false,
    saveUninitialized: true,
  })
);

const userSchema = new mongoose.Schema({
  name: {
    type: String,
    requred: true,
  },
  email: {
    type: String,
    requried: true,
  },
  password: {
    type: String,
    required: true,
  },
});

const User = mongoose.model("Users", userSchema);

app.get("/", (req, res) => {
  res.render("signup");
});
app.get("/signup", (req, res) => {
  res.render("signup");
});

app.get("/login", (req, res) => {
  res.render("login");
});

app.get("/home", (req, res) => {
  if (req.session.email) {
    res.render("home");
  } else {
    res.render("signup");
  }
});

app.get("/search", (req, res) => {
  res.render("aftersearch");
});

app.post("/", async function (req, res) {
  const { name, email, password } = req.body;
  req.session.email = email;
  req.session.name = name;

  if (!name || !email || !password) {
    return res.send(
      "<script>alert('Please Enter All Fields');window.location.href='/signup'</script>;"
    );
  }

  const userEmail = await User.findOne({ email: email });
  if (userEmail) {
    return res.send(
      "<script>alert('Email Already Exists');window.location.href='/signup'</script>;"
    );
  }

  if (password.length < 8) {
    return res.send(
      "<script>alert('Password Length Should Be Atleast 8');window.location.href = '/signup'</script>"
    );
  }

  try {
    const hashPass = await bcrypt.hash(password, 10);
    const user = new User({
      name,
      email,
      password: hashPass,
    });
    await user.save();
    return res.redirect("/home");
  } catch (err) {
    console.log(err);
    return res.redirect("/signup");
  }
});

app.post("/login", async function (req, res) {
  const { email, password } = req.body;
  req.session.email = email;
  if (!email || !password) {
    return res.send(
      "<script>alert('Please Enter All Fields');window.location.href='/signup'</script>;"
    );
  }

  const userEmail = await User.findOne({ email: email });
  if (!userEmail) {
    return res.send(
      "<script>alert('Email doesn't exists');window.location.href = '/login'</script>"
    );
  }

  const userPass = await bcrypt.compare(password, userEmail.password);
  if (!userPass) {
    return res.send(
      "<script>alert('Invalid Password');window.location.href = '/login'</script>"
    );
  }
  return res.redirect("/home");
});

app.listen(port, () => {
  console.log("Listening...");
});
