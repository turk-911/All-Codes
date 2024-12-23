const revealButton = document.querySelector('.revealButton');
const hiddenContent = document.querySelector('.hiddenContent');

function revealContent () {
    if(hiddenContent.classList.contains('revealButton')) {
        hiddenContent.classList.remove('revealButton');
    }
    else {
        hiddenContent.classList.add('revealButton');
    }
};

revealButton.addEventListener('click', revealContent);