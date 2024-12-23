import React, { useContext } from 'react'
import { assets } from '../assets/assets'
import './Main.css'
import { Context } from '../context/Context'
const Main = () => {
  const {onSend, recent, show, loading, resultData, setInput, input} = useContext(Context);
  return (
    <div className="main">
      <div className="nav">
        <p>Horizon Weather</p>
        <img src={assets.code_icon} alt="" />
      </div>
      <div className="main-container">
        {!show ? 
        <>
        <div className="greet">
          <p>
            <span>Hello, Mokshe</span>
          </p>
          <p>
            Sun kissed or rain drenched? What city's climate are you curious
            about?
          </p>
        </div>
        <div className="cards">
          <div className="card">
            <p>Cape Town, South Africa</p>
            <img src={assets.react_icon} alt="" />
          </div>
          <div className="card">
            <p>Canberra, Australia</p>
            <img src={assets.react_icon} alt="" />
          </div>
          <div className="card">
            <p>Srinagar, India</p>
            <img src={assets.react_icon} alt="" />
          </div>
          <div className="card">
            <p>Vienna, Austria</p>
            <img src={assets.react_icon} alt="" />
          </div>
        </div>
        </> : <div className='result'>
          <div className="result-title">
            <img src={assets.compass_icon} alt="" />
            <p>{recent}</p>
            </div></div>}
      <div className="main-bottom">
        <div className="search-box">
            <input type="text" placeholder='Name of the city' onChange={(e) => setInput(e.target.value)}/>
            <div>
                <img src={assets.send_icon} alt="" onClick={() => onSend()}/>
            </div>
        </div>
        <p className='bottom-info'>&copy; Horizon group of Companies</p> 
      </div>
      </div>
    </div>
  );
}

export default Main