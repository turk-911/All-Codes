import { useState } from 'react'
import './App.css'
import {InputBox} from './components/InputBox' 
import 

function App() {
  const [count, setCount] = useState(0)

  return (
    <>
      <h1 className='text-3xl bg-orange-500'>Welcome to Currency Convertor app</h1>
    </>
  )
} 

export default App
