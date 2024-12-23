import React from 'react'
import './Menu.css'
const Menu = ({ setLineColor, setLineWidth, setLineOpacity }) => {
  return (
    <div className="menu">
      <div className="prop">
        <label>Brush Color</label>
      <input
        type="color"
        onChange={(e) => {
          setLineColor(e.target.value);
        }}
      />
      </div>
      <div className="prop">
        <label>Brush Width</label>
      <input type="range" min="3" max="20" onChange={(e) => {
          setLineWidth(e.target.value);
        }}
      />
      </div>
      <div className="prop">
        <label>Brush Opacity</label>
      <input type="range" min="1" max="100" onChange={(e) => {
        setLineOpacity(e.target.value / 100);
      }}/>
      </div>
    </div>
  );
}

export default Menu