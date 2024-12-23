let rock = document.getElementById("rock");
let paper = document.getElementById("paper");
let scissor = document.getElementById("Scissor");
let wins = {
    rock : 0,
    paper: 1,
    scissor : 2
};
let score = 0;
rock.addEventListener("click", move1);
paper.addEventListener("click", move2);
scissor.addEventListener("click", move3);
function move1(){
    let chaal = Math.floor(Math.random() * 3);
    document.getElementById("you-choose").innerHTML = "You chose rock"
    if(chaal == 1){
        document.getElementById("hidden").innerHTML = "Computer won"
        document.getElementById("computer-choose").innerHTML = "Computer chose paper";
    }
    if(chaal == 0){
        document.getElementById("hidden").innerHTML = "This round was a draw";
        document.getElementById("computer-choose").innerHTML = "Computer chose rock";
    }
    if(chaal == 2){
        score++;
        document.getElementById("hidden").innerHTML = "Congrats you won!!"
        document.getElementsById("score").innerHTML = score;
        document.getElementById("computer-choose").innerHTML = "Computer chose scissor";
    }
}
function move2(){
    let chaal2 = Math.floor(Math.random() * 3);
    document.getElementById("you-choose").innerHTML = "You chose paper"
    if (chaal2 == 1) {
        document.getElementById("hidden").innerHTML = "This round was a draw";
        document.getElementById("computer-choose").innerHTML = "Computer chose paper"
    }
    if (chaal2 == 0) {
        document.getElementById("hidden").innerHTML = "Congrats you won!!";
        document.getElementById("computer-choose").innerHTML = "Computer chose rock"
    }
    if (chaal2 == 2) {
        score++;
        document.getElementById("hidden").innerHTML = "Computer won";
        document.getElementsById("score").innerHTML = score;
        document.getElementById("computer-choose").innerHTML = "Computer chose scissors"
    }
}
function move3(){
    let chaal3 = Math.floor(Math.random() * 3);
    document.getElementById("you-choose").innerHTML = "You chose scissors"
    if (chaal3 == 1) {
        document.getElementById("hidden").innerHTML = "Congrats you won !!";
        document.getElementById("computer-choose").innerHTML = "Computer chose paper"
    }
    if (chaal3 == 0) {
        document.getElementById("hidden").innerHTML = "Computer won";
        document.getElementById("computer-choose").innerHTML = "Computer chose rock";
    }
    if (chaal3 == 2) {
        score++;
        document.getElementById("hidden").innerHTML = "This round was a draw";
        document.getElementsById("score").innerHTML = score;
        document.getElementById("computer-choose").innerHTML = "Computer chose scissors"
    }
}