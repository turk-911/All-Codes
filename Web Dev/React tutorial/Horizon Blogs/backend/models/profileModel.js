const mongoose = require("mongoose");
const profileSchema = mongoose.Schema({
    username: {
        type: String,
        required: true,
    },
    bio: {
        type: String,
        required: true,
    },
    imagePath: {
        type: String,
        required: true,
    },
});
module.exports = mongoose.model('Profile', profileSchema);