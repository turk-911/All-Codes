const mongoose = require('mongoose');

const assignmentSchema = mongoose.Schema({
    name: {
        type: String,
        required: true,
    },
    content: {
        type: String,
        required: true,
    },
    dueDate: {
        type: Date,
        required: false,
    },
    credits: {
        type: Number,
        required: false,
    }
});

const assignmentModel = mongoose.model('assignments', assignmentSchema);

module.exports = assignmentModel;