import { useState } from 'react'
// import Naitik from './Naitik'
// import CustomRender from './CustomReact.js'
function App() {
  const [count, setCount] = useState(0)
  const userName = 'Mokshe';
  return (
    <>
      <h1>Hello {userName}</h1>
    </>
  )
}

export default App
