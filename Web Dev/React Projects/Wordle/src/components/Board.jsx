import React from "react";
import "./Board.css";
export default function Board(props) {
  return (
    <div className="board">
      <div>
        {props.style === "completed" &&
          (props.myScore.lastPuzzleCompleted.answer === props.puzzle.answer &&
          props.myScore.lastScore ? (
            <div className="solvedTag">
              <h3>Solved! See you tomorrow 💪</h3>
            </div>
          ) : (
            <div className="solvedTag">
              <h3 className="answerWas">You say&nbsp; </h3>
              <h3>{props.puzzle.answer}!</h3>
              <h3 className="answerWas-2">See you tomorrow 💪</h3>
            </div>
          ))}
      </div>
      <div className={props.style === "completed" ? "rowBlur" : "row"}>
        <input
          value={props.currentGuess}
          placeholder={
            props.style === "completed"
              ? "-------------------------"
              : "YOU SAY"
          }
          className={"answerInput"}
          onChange={props.handleChange}
        />
      </div>
    </div>
  );
}
