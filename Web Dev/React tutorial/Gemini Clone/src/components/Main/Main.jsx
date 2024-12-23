import React, { useContext } from 'react'
import './Main.css'
import { assets } from '../../assets/assets'
import { Context } from '../../context/Context'
const Main = () => {
  const {onSend, recent, show, resData, setInput, input} = useContext(Context);
  return (
    <div className="main">
      <div className="nav">
        <p>Gemini</p>
        <img src={assets.gemini_icon} alt="" />
      </div>
      <div className="main-container">
        {!show ? (
          <>
            <div className="greet">
              <p>
                <span>Hello, Mokshe</span>
              </p>
              <p>How can I help you today?</p>
            </div>
            <div className="cards">
              <div className="card">
                <p>Suggest an itenary to Gangtok</p>
                <img src={assets.compass_icon} alt="" />
              </div>
              <div className="card">
                <p>What type of graph is Q?</p>
                <img src={assets.bulb_icon} alt="" />
              </div>
              <div className="card">
                <p>Who is the captain of Zimbabwe Men's cricket team?</p>
                <img src={assets.message_icon} alt="" />
              </div>
              <div className="card">
                <p>Can you give me your code?</p>
                <img src={assets.code_icon} alt="" />
              </div>
            </div>
          </>
        ) : (
          <div className="result">
            <div className="result-title">
              <img src={assets.user_icon} alt="" />
              <p>{recent}</p>
            </div>
            <div className="result-data">
              <img src={assets.gemini_icon} alt="" />

              {"}"}
              {/* {loading ? <div className="loader">
                      <hr />
                      <hr />
                      <hr />
                    </div> : 
                    <p dangerouslySetInnerHTML={{__html:resData}}></p>
              } */}
              <p dangerouslySetInnerHTML={{ __html: resData }}></p>
            </div>
          </div>
        )} 
        <div className="main-bottom">
          <div className="search-box">
            <input
              type="text"
              placeholder="Enter a prompt here"
              onChange={(e) => setInput(e.target.value)}
              value={input}
            />
            <div>
              <img src={assets.gallery_icon} alt="" />
              <img src={assets.mic_icon} alt="" />
              <img src={assets.send_icon} onClick={() => onSend()} />
            </div>
          </div>
          <p className="bottom-info">
            Gemini may provide inaccurate information, including about people,
            so double check it's responses. <u>Your privacy & Gemini Apps</u>
          </p>
        </div>
      </div>
    </div>
  );
}

export default Main