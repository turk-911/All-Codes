const mongoose = require('mongoose');

// Class happening in the classroom
const classSchema = mongoose.Schema({
    author: {
        type: String,
        required: true,
    },
    startingTime: {
        type: Date,
        required: true,
    },
    studentsAssigned: {
        type: Array,
        required: true,
    },
    classCode: {
        type: String,
        required: true,
    },
});

const classModel = mongoose.model('classes', classSchema);

module.exports = classSchema;