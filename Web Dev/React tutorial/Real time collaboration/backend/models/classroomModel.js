const mongoose = require('mongoose');

const classroomSchema = mongoose.Schema({
    name: {
        type: String,
        required: true,
    },
    classIncharge: {
        type: String,
        required: true,
    },
    numberOfStudents: {
        type: Number,
        required: trure,
    },
});

const classroomModel = mongoose.model('classrooms', classroomSchema);

module.exports = classroomModel;