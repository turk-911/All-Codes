const express = require("express");
import { assignmentModel } from "../models/assignmentModel.js";
const router = express.Router();

// Route to add a new assignment to a particular class
router.post("/class/assignment/", async (req, res) => {
  try {
    if (!req.body.name || !req.body.content) {
      return res.status(400).send({
        message: "Send all required fields",
      });
    }
    const newAssignment = {
      name: req.body.name,
      content: req.body.content,
      dueDate: req.body.date || Date.now(),
      credits: req.body.content || 0,
    };
  } catch (error) {
    console.log(error.message);
    res.status(500).send({
      message: error.message,
    });
  }
});

// Route to update an assignment for a particular class
router.put("/class/assignment/:id", async (req, res) => {
  try {
    if (!req.body.name || !req.body.content) {
      return res.status(400).send({
        message: "Send all required fields",
      });
    }
    const { id } = req.params;
    const result = await assignmentModel.findByIdAndUpdate(id);
    if (!result) {
      return res.status(404).send({
        message: "Assignment not found",
      });
    }
    return res.status(200).send({
      message: "Assignment updated successfully",
    });
  } catch (error) {
    console.log(error.message);
    res.status(500).send({
      message: error.message,
    });
  }
});

// Route to delete a assignment from a particular class
router.delete("/class/assignment/:id", async (req, res) => {
  try {
    const { id } = req.params;
    const result = await assignmentModel.findByIdAndDelete(id);
    if (!result) {
      return res.status(404).send({
        message: "Assignment not found",
      });
    }
    return res.status(200).send({
      message: "Assignment deleted successfully",
    });
  } catch (error) {
    console.log(error.message);
    res.status(500).send({
      message: error.message,
    });
  }
});
