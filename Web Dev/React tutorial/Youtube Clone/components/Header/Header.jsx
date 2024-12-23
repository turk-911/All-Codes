import React from 'react'
import assets from '../../src/assets/assets';
import './Header.css'
const Header = () => {
  return (
    <div className="header">
      <div className="logo">
        <i class="fa-solid fa-bars"></i>
        <img src={assets.logo} alt="" />
      </div>
      <div className="search-box">
        <input type="text" placeholder="Search" />
        <button className='search-button'>
          <i class="fa-solid fa-magnifying-glass"></i>
        </button>
        <div className="mic">
          <button>
            <i class="fa-solid fa-microphone"></i>
          </button>
        </div>
      </div>
      <div className="icons">
        <i class="fa-solid fa-video"></i>
        <i class="fa-solid fa-bell"></i>
        <i class="fa-solid fa-user"></i>
      </div>
    </div>
  );
}

export default Header