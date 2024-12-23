import React, { useState } from 'react'
import assets from '../../assets/assets'
import axios from 'axios'

function Login() {
  
  const [email, setEmail] = useState('');
  const [password, setPassword] = useState('');
  const sendLoginDetails = async (e) => {
    e.preventDefault();
    console.log(email, password);
    axios.post('http://localhost:5500/login', {email, password})
    .then((result) => {
      console.log('Login details sent successfully');
    })
    .catch((error) => {
      console.log(error);
    })
  }
  return (
    <div className="box-border flex flex-col justify-center items-center h-[100vh]">
      <div className=''>
        <div className="w-[220px] mb-4">
          <img src={assets.logo} alt="" />
        </div>
      </div>
      <form action="" className="border">
        <div className="flex justify-between p-6">
          <label htmlFor="email" className="mr-6">
            User Email
          </label>
          <input type="email" className="border" name='email' onChange={(e) => setEmail(e.target.value)}/>
        </div>
        <div className="flex justify-between p-6">
          <label htmlFor="password">Password</label>
          <input type="password" className="border" name='password' onChange={(e) => setPassword(e.target.value)}/>
        </div>
      </form>
      <div className='flex justify-center items-center'>
        <button className='border p-3 m-3 w-[328.06px] bg-blue-600 text-white rounded-sm' onClick={sendLoginDetails}>Login </button>
      </div>
      <p className='p-2 underline'>Don't have an account? Create one</p>
    </div>
  );
}

export default Login