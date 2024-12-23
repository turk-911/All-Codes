import { useState, useCallback, useEffect, useRef } from 'react'
import './App.css' 
function App() {
  const [length, setLength] = useState(8);
  const [numberAllowed, setNumberAllowed] = useState(false);
  const [charAllowed, setCharAllowed] = useState(false);
  const [password, setPassword] = useState("");
  const passwordRef = useRef(null);
  const passwordGenerator = useCallback(() => {
    let pass = "";
    let str = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    if (numberAllowed) str += "0123456789";
    if (charAllowed) str += "!@#$%^&*()_+-={}[]";
    for (let i = 1; i <= length; i++) {
      let char = Math.floor(Math.random() * str.length + 1);
      pass += str.charAt(char);
    }
    setPassword(pass);
  }, [length, numberAllowed, charAllowed, setPassword]); 
  const copyPasswordToClipBoard = useCallback(() => {
    passwordRef.current?.select()
    window.navigator.clipboard.writeText(password);
  }, [password])
  useEffect(() => {
    passwordGenerator() 
  }, [length, numberAllowed, charAllowed, passwordGenerator]);
  return (
    <>
      <div className="outer">
        <div className="main">
          <div className="inner-box">
            <h1>Password Generator</h1>
            <div className="inner-inner-box">
              <input
                type="text"
                placeholder="password"
                className="input-box"
                readOnly
                value={password}
              /> 
              <button className="copy-button" onClick={copyPasswordToClipBoard}>Copy</button>
            </div>
          </div>
          <div className="second-box">
            <div className="range-bar">
              <input
                type="range"
                min={6}
                max={100}
                onChange={(e) => {
                  setLength(e.target.value);
                }}
                className="range"
              />
              <br />
              <label>Length: {length}</label>
            </div>
            <div className="check">
              <input
                type="checkbox"
                defaultChecked={numberAllowed}
                id="numberChecked"
                onChange={() => {
                  setNumberAllowed((prev) => !prev);
                }}
              />
              <label htmlFor="numberInput">Numbers</label>
            </div>
            <div className="check">
              <input
                type="checkbox"
                defaultChecked={charAllowed}
                id="charChecked"
                onChange={() => {
                  setCharAllowed((prev) => !prev);
                }}
              />
              <label htmlFor="numberInput">Characters</label>
            </div>
          </div>
        </div>
      </div>
    </>
  );
}

export default App
