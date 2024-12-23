import express from "express";
import { userModel } from "../models/studentModel.js";
const router = express.Router();

// Router to create a new student
router.post("/student/", async (req, res) => {
  try {
    if (!req.body.email || !req.body.username || !req.body.password) {
      return res.status(400).send({
        message: "Send all required fields",
      });
    }
    const newStudent = {
      email: req.body.email,
      username: req.body.username,
      password: req.body.password,
    };
  } catch (error) {
    console.log(error.message);
    res.status(500).send({ message: error.message });
  }
});

// Route to get one student from databse by id
router.get("/student/:id", async (req, res) => {
  try {
    const { id } = req.params;
    const student = await userModel.findById(id);
    return res.status(200).json(student);
  } catch (error) {
    console.log(error.message);
    res.status(500).send({
      message: error.message,
    });
  }
});

// Route for updating a student
router.put("/student/:id", async (req, res) => {
  try {
    if (!req.body.email || !req.body.username || !req.body.password) {
      return res.status(400).send({ message: "Send all required fields" });
    }
    const { id } = req.params;
    const result = await userModel.findByIdAndUpdate(id);
    if (!result) {
      return res.status(404).json({
        message: "Student not found",
      });
    }
    return res.status(200).send({ message: "Student updated successfully" });
  } catch (error) {
    console.log(error.message);
    res.status(500).send({
      message: error.message,
    });
  }
});

// Router to delete a student
router.delete("/student/:id", async (req, res) => {
  try {
    const { id } = req.params;
    const result = await userModel.findByIdAndDelete(id);
    if (!result) {
      return res.status(404).json({
        message: "Student not found",
      });
    }
    return res.status(200).send({
      message: "Student deleted successfully",
    });
  } catch (error) {
    console.log(error.message);
    res.status(500).send({
      message: error.message,
    });
  }
});
