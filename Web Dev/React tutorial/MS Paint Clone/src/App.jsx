import { useEffect, useRef, useState } from 'react'
import Menu from './Menu';
import './App.css'

function App() {
  const [count, setCount] = useState(0)
  const canvasRef = useRef(null);
  const contextRef = useRef(null);
  const [drawing, setDrawing] = useState(false);
  const [lineWidth, setLineWidth] = useState(3);
  const [lineColor, setLineColor] = useState("black");
  const [lineOpacity, setLineOpacity] = useState(0.1);
  useEffect(() => {
    const canvas = canvasRef.current;
    const ctx = canvas.getContext("2d");
    ctx.lineCap = "round";  
    ctx.lineJoin = "round";
    ctx.globalAlpha = lineOpacity;
    ctx.strokeStyle = lineColor;
    ctx.lineWidth = lineWidth;
    contextRef.current = ctx;
  }, [lineColor, lineOpacity, lineWidth]);
  const startDrawing = (e) => {
    contextRef.current.beginPath();
    contextRef.current.moveTo(
      e.nativeEvent.offsetX, 
      e.nativeEvent.offsetY,
    );
    setDrawing(true);
  }
  const endDrawing = () => {
    contextRef.current.closePath();
    setDrawing(false);
  }
  const draw = (e) => {
    if(!drawing){
      return;
    }
    contextRef.current.lineTo(
      e.nativeEvent.offsetX,
      e.nativeEvent.offsetY,
    );
    contextRef.current.stroke();
  }
  return (
    <div className="container">
      <h1>MS Paint Clone - Sasta version</h1>
      <div className="main-area">
        <Menu setLineColor={setLineColor} setLineOpacity={setLineOpacity} setLineWidth={setLineWidth}/>
        <canvas onMouseDown={startDrawing} onMouseUp={endDrawing} onMouseMove={draw} ref={canvasRef} width={`1000px`} height={`700px`}></canvas>
      </div>
    </div>
  )
}

export default App
