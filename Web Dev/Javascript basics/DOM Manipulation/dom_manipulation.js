// // // DOM Manipulation
// // // Get Element by ID
// // const title = document.getElementById('main-heading');
// // console.log(title);

// // // Get element by class name
// // const listItems = document.getElementsByClassName('list');
// // console.log(listItems);

// // // Get element by tag name
// // const tag = document.getElementsByTagName('h1');
// // console.log(tag);

// // // Get element by query
// // const container = document.querySelector('div');
// // console.log(container);

// // // Query selector all
// // const selector = document.querySelectorAll('div');
// // console.log(selector);


// const title = document.getElementById('main-heading');
// title.style.color = 'red';
// console.log(title);

// const listItems = document.querySelectorAll('.list-items');
// // listItems.style.color = 'blue'; --> will not happen like this
// for(i = 0; i < listItems.length; i++){
//     listItems[i].style.fontSize = '3rem';
// }

// const ul = document.querySelector('ul');
// const li = document.createElement('li');

// // Adding the elements
// ul.append(li);

// const firstListItem = document.querySelector('.list-items');
// console.log(firstListItem.innerText);
// console.log(firstListItem.textContent);
// console.log(firstListItem.innerHTML);

// // Modifying the elements
// li.innerText = 'X-Men';

// // Modifying attributes and classes

// // li.setAttribute('class', 'main-heading');
// // li.removeAttribute('class');

// // const title = document.querySelector('#main-heading');
// // console.log(title.getAttribute('class'));

// // li.classList.remove('list-items');
// // console.log(li.classList.contains('list-items'));

// // li.classList.add('list-items');
// // console.log(li.classList.contains('list-items'));


// // // Removing the elements
// // li.remove();

// let ul = document.querySelector('ul');
// console.log(ul);
// console.log(ul.parentNode.parentNode); // grandparent node
// console.log(ul.parentElement);


// const html = document.documentElement;
// console.log(html.parentNode);
// console.log(html.parentElement);


// // Child node traversal --> we will traverse downward in the DOM;
// let ul = document.querySelector('ul');
// console.log(ul.childNodes);
// console.log(ul.firstChild);
// console.log(ul.lastChild);

// ul.childNodes[1].style.backgroundColor = 'yellow';

// console.log(ul.children);
// console.log(ul.firstElementChild);
// console.log(ul.lastElementChild);


// Sibling Node traversal
let ul = document.querySelector('ul');
console.log(ul);
console.log(ul.previousSibling);
console.log(ul.nextSibling);

console.log(ul.previousElementSibling);
console.log(ul.nextElementSibling);
