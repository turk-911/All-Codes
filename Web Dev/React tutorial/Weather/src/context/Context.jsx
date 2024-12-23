import { createContext, useState } from "react";
export const Context = createContext();
const APIkey = "f5addd946f843104f1d1664078b157af";
const ContextProvider = (props) => {
    const [input, setInput] = useState("");
    const [recent, setRecent] = useState("");
    const [prevPrompt, setPrevPrompt] = useState([]);
    const [show, setShow] = useState(false);
    const [loading, setLoading] = useState(false);
    const [resultData, setResultData] = useState("");
    console.log("hello")
    const onSend = async (prompt) => {
        console.log("On send");
        setResultData("");
        setLoading(true);
        setShow(true);
        setRecent(input);
        const response = await fetch(
          `https://api.openweathermap.org/data/2.5/weather?q=${recent}&units=metric&appid=${APIkey}`
        );
        let data = await response.json();
        console.log(data);
        const typeOfWeather = response.weather[0].main;
        // console.log(typeOfWeather);
        const description = data.weather[0].description;
        const temperature = data.main.temp;
        const humidity = data.main.humidity;
        const visibility = data.visibility;
        setLoading(false);
        setInput("");
    }
    const contextValue = {prevPrompt, setPrevPrompt, onSend, setRecent, recent, show, loading, resultData, input, setInput};
    return (
        <Context.Provider value={contextValue}>
            {props.children}
        </Context.Provider>
    )
}
export default ContextProvider;