import React from 'react'
import assets from '../../assets/assets.js';
function Header() {
  return (
    <nav className="flex p-6 justify-between shadow-sm">
      <div className='flex'>
        <img src={assets.logo} alt="" className='w-72' />
        <ul className="flex ml-5">
          <li className="p-2">Why Horizon</li>
          <li className="p-2">Horizon Workspace for Education</li>
          <li className="p-2">HorizonBooks</li>
          <li className="p-2">Get Started</li>
          <li className="p-2">For Educators</li>
        </ul>
      </div>
      <div className="flex">
        <button className='mr-6'>
          {" "}
          <i className="fa-solid fa-magnifying-glass mr-7"></i>
          <span>Sign In</span>
        </button>
        <button className='bg-blue-600 p-2 text-white rounded-sm'>Contact Sales</button>
      </div>
    </nav>
  );
}

export default Header