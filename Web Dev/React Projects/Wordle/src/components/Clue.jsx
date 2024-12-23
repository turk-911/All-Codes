import React from "react";
import "./Clue.css";

export default function Clue(props) {
  return (
    <div className="clueComponent">
      <h3 className={props.darkMode ? "newPuzzle--dark" : "newPuzzle"}>
        NEW PUZZLE EVERY DAY
      </h3>
      <div className="whenISayYouSay">
        <div className="youSay">
          <h6>MAKE THE CORRECT MATCH TO THE WORD</h6>
        </div>
      </div>

      {props.guess.length > 0 ? (
        props.guess.includes("correct") ? (
          <div className="guessInfo">
            <h5
              className={
                props.darkMode ? "guessInfo--dark" : "guessInfo--light"
              }
            >
              {props.guess.length > 1
                ? `YOU GOT IT IN ${props.guess.length} GUESSES 🎉`
                : `YOU GOT IT IN ${props.guess.length} GUESS 🎉`}
            </h5>
            <button className="shareButton" onClick={props.handleShare}>
              SHARE
            </button>
          </div>
        ) : null
      ) : null}
      <div className="guessBoxParent">
        <h6 className="guessesText">GUESSES</h6>
        <div className="guessesBox">
          <div
            className={
              props.guess[0] === "correct"
                ? "trueStyle"
                : props.guess[0] === "incorrect"
                ? "falseStyle"
                : "guess"
            }
          ></div>
          <div
            className={
              props.guess[1] === "correct"
                ? "trueStyle"
                : props.guess[1] === "incorrect"
                ? "falseStyle"
                : "guess"
            }
          ></div>
          <div
            className={
              props.guess[2] === "correct"
                ? "trueStyle"
                : props.guess[2] === "incorrect"
                ? "falseStyle"
                : "guess"
            }
          ></div>
          <div
            className={
              props.guess[3] === "correct"
                ? "trueStyle"
                : props.guess[3] === "incorrect"
                ? "falseStyle"
                : "guess"
            }
          ></div>
          <div
            className={
              props.guess[4] === "correct"
                ? "trueStyle"
                : props.guess[4] === "incorrect"
                ? "falseStyle"
                : "guess"
            }
          ></div>
        </div>
      </div>
      <h1 className={props.darkMode ? "toggleDark" : "toggleLight"}>
        I SAY <span className="clueSpan">{props.clue}</span>
      </h1>
    </div>
  );
}
