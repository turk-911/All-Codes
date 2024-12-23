console.log("Welcome to tic tac toe");
let music = new Audio("");
let turnMusic = new Audio("ting_sms.mp3")
let gameOver = new Audio("wonTheGame.mp3");
let turn = "X";
let result = false;
// function to change the turn
function changeTurn() {
    return turn === "X" ?
        "0" : "X";
}
// function to check for a win
function checkWin() {
    let boxtext = document.getElementsByClassName("boxText");
    let wins = [[0, 1, 2], [3, 4, 5], [6, 7, 8], [0, 3, 6], [1, 4, 7], [2, 5, 8], [0, 4, 8], [2, 4, 6]]
    wins.forEach(e =>{
        if(boxtext[e[0]].innerText === boxtext[e[1]].innerText){
            if(boxtext[e[1]].innerText === boxtext[e[2]].innerText){
                if(boxtext[e[0]].innerText != ""){
                    document.querySelector('.info').innerText = boxtext[e[0]].innerText + " wins";
                    result = true;
                    document.querySelector('.imgbox').getElementsByTagName('img')[0].style.width = "200px"
                }
            }
        }
    })
}
let boxes = document.getElementsByClassName("box");
Array.from(boxes).forEach(element => {
    let boxText = element.querySelector('.boxText');
    element.addEventListener('click', () => {
        if (boxText.innerText === '') {
            boxText.innerText = turn;
            turn = changeTurn();
            turnMusic.play();
            checkWin();
            if (result === false) {
                document.getElementsByClassName("info")[0].innerText = "Turn for " + turn;
            }
        }
    })
})
// event listener for reset button
reset.addEventListener('click', ()=>{
    let boxtexts = document.querySelectorAll('.boxText')
        Array.from(boxtexts).forEach(element => {
            element.innerText = '';
        })
        turn = "X";
        document.getElementsByClassName("info")[0].innerText = "Turn for " + turn;
        document.querySelector('.imgbox').getElementsByTagName('img')[0].style.display = "none"
        result = false;
   
})