import express from "express";
import { classModel } from "../models/classModel";
const router = express.Router();

// Function to generate a random string for class code
function generateRandomString() {
  const str = "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM1234567890";
  let finalStr = "";
  for (let i = 0; i < 8; i++) {
    let randomIndex = Math.floor(Math.random() * 62);
    finalStr += str[randomIndex];
  }
  return finalStr;
}
// Router to create a new class
router.post("/class/", async (req, res) => {
  try {
    if (
      !req.body.author ||
      !req.body.startingTime ||
      !req.body.studentsAssigned
    ) {
      return res.status(400).send({ message: "send all required fields" });
    }
    const newClass = {
      author: req.body.author,
      startingTime: req.body.startingTime,
      studentsAssigned: req.body.studentsAssigned,
      classCode: generateRandomString(),
    };
    const Class = new cla
  } catch (error) {
    console.log(error.message);
    res.status(500).send({ message: error.message });
  }
});

// Route to get all classes from database
router.get("/class/all", async (req, res) => {
  try {
    const classes = await classModel.find({});
    return res.status(200).json({
      count: classes.length,
      data: classes,
    });
  } catch (error) {
    console.log(error.message);
    res.status(500).send({ message: error.message });
  }
});

// Route to get one class from database by id
router.get("/class/:id", async (req, res) => {
  try {
    const { id } = req.params;
    const Class = await classModel.findById(id);
    return res.status(200).json(Class);
  } catch (error) {
    console.log(error.message);
    res.status(500).send({ message: error.message });
  }
});

// Route for updating a class
router.put("/class/:id", async (req, res) => {
  try {
    if (
      !req.body.author ||
      !req.body.startingTime ||
      !req.body.studentsAssigned
    ) {
      return res.status(400).send({
        message: "Send all required fields",
      });
    }
    const { id } = req.params;
    const result = await classModel.findByIdAndUpdate(id, req.body);
    if (!result) {
      return res.status(404).json({
        message: "Class not found",
      });
    }
    return res.status(200).send({
      message: "Class updated successfully",
    });
  } catch (error) {
    console.log(error.message);
    res.status(500).send({ message: error.message });
  }
});

// Route to delete a class
router.delete("/class/:id", async (req, res) => {
  try {
    const { id } = req.params;
    const result = await classModel.findByIdAndDelete(id);
    if (!result) {
      return res.status(404).json({
        message: "Class not found",
      });
    }
    return res.status(200).send({
      message: "Class deleted successfully",
    });
  } catch (error) {
    console.log(error.message);
    res.status(500).send({
      message: error.message,
    });
  }
});

export default router;
