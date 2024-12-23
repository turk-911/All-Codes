let canvas = document.querySelector("canvas");
canvas.width = window.innerWidth;
canvas.height = window.innerHeight;
console.log(canvas);
// stands for context
let c = canvas.getContext("2d");
// c.fillRect(x, y, width, height)
c.fillStyle = "pink";
c.fillRect(100, 100, 300, 100);
// c.fillRect(100, 400, 500, 100);
// c.fillRect(200, 100, 100, 100);
c.fillRect(100, 200, 100, 400);
c.fillRect(100, 500, 300, 100);
c.fillRect(300, 300, 100, 200);
c.fillRect(200, 300, 200, 100);

// lines
c.beginPath();
c.moveTo(1000, 300);
c.lineTo(100, 500);
c.lineTo(300, 786);
c.strokeStyle = "#ab2ba2"
c.stroke();

// arcc
c.beginPath()
c.arc(300, 300, 30, 0, Math.PI * 2, false);
c.stroke()