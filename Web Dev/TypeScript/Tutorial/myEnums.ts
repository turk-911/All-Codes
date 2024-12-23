// Enums exist to restrict the choice of users
enum SeatChoice {
    AISLE,
    MIDDLE,
    WINDOW,
    FOURTH
};

const seat = SeatChoice.AISLE

// Aisle has default value = 0 and subsequent value has increments
// if we assign the aisle as a string for eg

enum SeatChoiceDemo {
    AISLE = "aisle",
    MIDDLE = "middle",
    WINDOW = "window",
    FOURTH = "fourth",
}

export {}