const express = require('express');
const classroomModel = require('../models/classroomModel');
const router = express.Router();

// Router to create a new classroom
router.get("/classroom", async (req, res) => {
    try {
        if (!req.body.name || !req.body.classIncharge || !req.body.numberOfStudents) {
            return res.status(400).json({
                message: "Send all required fields"
            });
        }

    } catch (error) {
        console.log(error.message);
    }
});

// Router to update an existing classroom
router.put("/classroom/:id", async (req, res) => {
    try {
        if (!req.body.name || !req.body.classIncharge || !req.body.numberOfStudents) {
            return res.status(400).json({
                message: "Send all required fields"
            });
        }
        const { id } = req.params;
        const result = await classroomModel.findByIdAndUpdate(id);
        if (!result) {
            return res.status(404).json({
                message: "Classroom not found",
            });
        }
        return res.status(200).json({
            message: "Classroom updated successfully"
        })
    } catch (error) {
        console.log(error.message);
        res.status(500).json({
            message: error.message,
        })
    }
})