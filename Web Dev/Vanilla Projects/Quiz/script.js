const quizData = [
    {
        question : "What is the capital of Maldives?",
        a : "Mauritius",
        b : "Male",
        c : "Colombo",
        d : "Thiruvanatampuram",
        correct : "b"
    },
    {
        question : "What is the capital of Australia?",
        a : "Melbourne",
        b : "Sydney",
        c : "Canberra",
        d : "Brisbane",
        correct : "c"
    },
    {
        question : "Which country is considered as the natural habitat of both tigers and lions?",
        a : "South Africa",
        b : "Madagascar",
        c : "United States of America",
        d : "India",
        correct : "d"
    },
    {
        question : "Which of these countries does not border China?",
        a : "Uzbekistan",
        b : "Kyrgystan",
        c : "Russia",
        d : "Kazakhastan",
        correct : "d"
    },
    {
        question : "Which country has the most number of time zones? ",
        a : "USA", 
        b : "China",
        c : "Russia",
        d : "India",
        correct : "c"
    }
];
const quiz = document.getElementById('quiz');
const answerEls = document.querySelectorAll('.answer');
const questionEl = document.getElementById('question');
const aOptn = document.getElementById('a-text');
const bOptn = document.getElementById('b-text');
const cOptn = document.getElementById('c-text');
const dOptn = document.getElementById('d-text');
const submit = document.getElementById('submit');
let current = 0;
let score = 0;
loadQuiz();
function loadQuiz(){
    deselectAnswers();
    const currentQuizData = quizData[current];
    questionEl.innerText = currentQuizData.question;
    aOptn.innerText = currentQuizData.a;
    bOptn.innerText = currentQuizData.b;
    cOptn.innerText = currentQuizData.c;
    dOptn.innerText = currentQuizData.d;
}
function deselectAnswers(){
    answerEls.forEach(answerEl => answerEl.checked = false);
}
function getSelected(){
    let answer;
    answerEls.forEach(answerEl => {
        if(answerEl.checked){
            answer = answerEl.id;
        }
    })
    return answer;
}
submit.addEventListener('click', ()=>{
    const answer = getSelected();
    if(answer){
        if(answer === quizData[current].correct){
            score++;
        }
        current++;
        if(current < quizData.length){
            loadQuiz();
        }
        else{
            quiz.innerHTML = `<h2>You answered ${score}/${quizData.length} questions correctly</h2><button onclick="location.reload()">Reload</button>`
        }
    }
})