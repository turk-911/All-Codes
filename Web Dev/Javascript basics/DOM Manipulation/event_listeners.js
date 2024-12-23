// DOM Manipulation
// Event listeners
// element.addEventListener("click", function);

const buttonTwo = document.querySelector('.btn-2');
const box3 = document.querySelector('.box3');
function alertBtn() {
    alert('I also love JavaScript');
};

buttonTwo.addEventListener("click", alertBtn);

const buttonThree = document.querySelector('.btn-3');
function alertBtn3 () {
    alert('1 + 1 = 3 by mistake')
};

buttonThree.addEventListener("click", alertBtn3);

function changeColor () {
    box3.style.backgroundColor = 'black';
    box3.style.color = 'white';
}
box3.addEventListener("mouseover", changeColor);