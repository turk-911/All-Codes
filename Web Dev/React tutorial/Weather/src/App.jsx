import { useState } from 'react'
import Sidebar from './components/Sidebar'
import Main from './components/Main'

function App() {
  const [count, setCount] = useState(0)
  console.log("Hello");
  return (
    <>
      <Sidebar/>
      <Main />
    </>
  )
}

export default App
