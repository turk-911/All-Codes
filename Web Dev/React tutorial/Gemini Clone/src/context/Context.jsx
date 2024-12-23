import { createContext, useState } from "react";
import runChat from "../config/config";
export const Context = createContext();
const ContextProvider = (props) => {
    const [input, setInput] = useState("");
    const [recent, setRecent] = useState("");
    const [previousPrompt, setPreviousPrompt] = useState([]);
    const [show, setShow] = useState(false); 
    // const [loading, setLoading] = useState(false);
    const [resData, setResData] = useState("");
    const delayResponse = (index, nextWord) => {
        setTimeout(function (){
            setResData(prev => prev + nextWord)
        }, 75)
    };
    const onSend = async(prompt) => {
        setResData("");
        // setLoading(true);
        setShow(true)
        setRecent(input);
        const response = await runChat(input);
        let responseArr = response.split("**");
        let newArr;
        for(let i = 0; responseArr.length; i++){
            if(i == 0 || !i&1){
                newArr += responseArr[i];
            }
            else{
                newArr += "<b>" + responseArr[i] + "</b>"
            } 
        }
        let newResponse = newArr.split("*").join("<br/>")
        let newResponseArray = newResponse.split(" ");
        for(let i = 0; i < newResponseArray.length; i++){
            const nextWord = newResponseArray[i];
            delayResponse(i, nextWord + " ");
        }
        // setLoading(false);
        setInput("");
    }
    
    const contextValue = {previousPrompt, setPreviousPrompt, onSend, setRecent, recent, show, resData, input, setInput};
    return (
        <Context.Provider value={contextValue}>
            {props.children}
        </Context.Provider>
    )
}
export default ContextProvider