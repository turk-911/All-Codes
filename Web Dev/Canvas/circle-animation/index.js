let canvas = document.querySelector("canvas");
canvas.width = window.innerWidth;
canvas.height = window.innerHeight;
let w = window.innerWidth;
let h = window.innerHeight;
// alert("Hello")
let c = canvas.getContext("2d");
let colors = ['#12355b', '#420039', '#d72638', '#ff570a', '#9dcbba', '#04f06a', '#454545', '#0b132b']
// function animate() {
//     requestAnimationFrame(animate);
//     let index = Math.floor(Math.random() * 9);
//     c.beginPath();
//     c.arc(x, y, r, 0, Math.PI * 2, false);
//     c.strokeStyle = colors[index];
//     c.stroke();
//     // c.clearRect(0, 0, innerWidth, innerHeight)
//     // y--;
//     c.closePath();
//     c.beginPath();
//     c.arc(x, y2, r, 0, Math.PI * 2, false);
//     c.strokeStyle = colors[index];
//     c.stroke();
//     y2++;
//     y--;
//     c.closePath();
//     r+=1;
//     console.log(y)
// }
// animate();
// let dy = dx;
// function animate() {
//     requestAnimationFrame(animate);
//     c.clearRect(0, 0, innerWidth, innerHeight);
//     c.beginPath();
//     c.arc(x, y, r, 0, Math.PI * 2, false);
//     c.strokeStyle = 'blue';
//     c.stroke()
//     if(x + r > innerWidth || x - r < 0) {
//         dx = -dx;
//     }
//     if(y + r > innerHeight || y - r < 0) {
//         dy = -dy;
//     }
//     y += dy;
//     x += dx;
// }

var mouse = {
    x: undefined,
    y: undefined,
}

window.addEventListener('mousemove', function(event) {
    mouse.x = event.x;
    mouse.y = event.y;
})

let radius = 4;

function Circle(x, y, dx, dy, radius, color) {
    this.x = x;
    this.y = y;
    this.dx = dx;
    this.dy = dy;
    this.radius = radius;
    this.color = color;
    this.draw = function() {
        c.beginPath();
        c.arc(this.x, this.y, this.radius, 0, Math.PI * 2, false);
        // c.strokeStyle = 'blue'; 
        c.fillStyle = color
        c.fill()
        c.strokeStyle = this.color;
        c.stroke();
    }
    this.update = function() {
        if(this.x + this.radius > innerWidth || this.x - this.radius < 0) {
            this.dx = -this.dx;
        }
        if(this.y + this.radius > innerHeight || this.y - this.radius < 0) {
            this.dy = -this.dy;
        }
        this.x += this.dx;
        this.y += this.dy;
        this.draw();
        if(Math.abs(mouse.x - this.x) <= 50 && Math.abs(mouse.y - this.y) <= 50 && this.radius < 40) {
            this.radius += 1;
        }
        else if(this.radius > 2) {
            this.radius /= 2;
        }
    }
}
// var circleArray = [];
// for(var i = 0; i < 1000; i++) {
//     var x = Math.random() * innerWidth;
//     var y = Math.random() * innerHeight;
//     var dx = Math.random() * 4;
//     var dy = Math.random() * 4;
//     var circle = new Circle(x, y, dx, dy, Math.random() * 10 + 1, colors[i % 8]);
//     circleArray.push(circle);
// }
var circleArray = [];
function animate() {
    requestAnimationFrame(animate);
    c.clearRect(0, 0, innerWidth, innerHeight)
    for(let i = 0; i < circleArray.length; i++) {
        circleArray[i].update();
    }
}
animate()
window.addEventListener('resize', function() {
    canvas.width = window.innerWidth;
    canvas.height = window.innerHeight;

    init();
});
function init() {
    circleArray = []
    for (var i = 0; i < 10000; i++) {
      var x = Math.random() * innerWidth;
      var y = Math.random() * innerHeight;
      var dx = Math.random() * 4;
      var dy = Math.random() * 4;
      var circle = new Circle(
        x,
        y,
        dx,
        dy,
        Math.random() * 10 + 1,
        colors[i % 8]
      );
      circleArray.push(circle);
    }
}
init()