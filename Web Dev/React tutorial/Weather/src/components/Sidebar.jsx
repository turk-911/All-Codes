import React, { useState } from 'react';
import './Sidebar.css';
import { assets } from '../assets/assets.js';
const Sidebar = () => {
  const [extended, setExtended] = useState(false);
  return (
    <div className="sidebar">
      <div className="top">
        <img src={assets.menu_icon} alt="" className='menu' onClick={() => setExtended(prev => !prev)}/>
        <div className="new-search">
          <img src={assets.plus_icon} alt="" />
          {extended ? <p>New Search</p> : null}
        </div>
        {extended ? 
        <div className="recent-searches">
          <p className="recent-search-title">You previously looked for: </p>
          <div className="recent-entry">
            <img src={assets.compass_icon} alt="" />
            <p>New York</p>
          </div>
        </div> 
        : 
        null}
      </div>
    </div>
  )
}

export default Sidebar