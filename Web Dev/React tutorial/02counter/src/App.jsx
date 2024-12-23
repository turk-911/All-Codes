import { Fragment, useState } from 'react' // Use state is used to change the use state
// import reactLogo from './assets/react.svg'
// import viteLogo from '/vite.svg'
import './App.css'
// Use state se 2 chize milti hai ek array ke form mei
// write like this --> const [variable, func] = useState(15)
function App() {
  let [counter, setCounter] = useState(5);
  const addValue = () => {
    counter = counter + 1;
    setCounter(counter);
  };
  const subtractValue = () => {
    counter = counter - 1;
    setCounter(counter);
  };
  return (
    <>
      <h1>Counter using React</h1>
      <h3>Counter value: {counter}</h3>
      <button onClick={addValue}>Add 1</button>
      <button onClick={subtractValue}>Subtract 1</button>
    </>
  )
}

export default App
