import { useEffect, useState } from 'react'
import reactLogo from './assets/react.svg'
import viteLogo from '/vite.svg'
import './App.css'
import axios from 'axios'
function App() {
  const [jokes, setJokes] = useState([])
  useEffect(() => {
    axios.get("/api/jokes").then((res) => {
      setJokes(res.data)
    }).catch((err) => {
      console.log(err);
    });
  })
  return (
    <>
      <h1>Joke Application</h1>
      <p>Number of jokes: {jokes.length}</p>
      {
        jokes.map((joke, index) => (
          <div key={joke.id}>
            <h3>{joke.name}</h3>
            <p>{joke.content}</p>
          </div>
        ))
      }
    </>
  )
}

export default App
