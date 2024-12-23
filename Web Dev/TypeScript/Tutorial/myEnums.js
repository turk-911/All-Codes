// Enums exist to restrict the choice of users
var SeatChoice;
(function (SeatChoice) {
    SeatChoice[SeatChoice["AISLE"] = 0] = "AISLE";
    SeatChoice[SeatChoice["MIDDLE"] = 1] = "MIDDLE";
    SeatChoice[SeatChoice["WINDOW"] = 2] = "WINDOW";
    SeatChoice[SeatChoice["FOURTH"] = 3] = "FOURTH";
})(SeatChoice || (SeatChoice = {}));
;
var seat = SeatChoice.AISLE;
// Aisle has default value = 0 and subsequent value has increments
// if we assign the aisle as a string for eg
var SeatChoiceDemo;
(function (SeatChoiceDemo) {
    SeatChoiceDemo["AISLE"] = "aisle";
    SeatChoiceDemo["MIDDLE"] = "middle";
    SeatChoiceDemo["WINDOW"] = "window";
    SeatChoiceDemo["FOURTH"] = "fourth";
})(SeatChoiceDemo || (SeatChoiceDemo = {}));
