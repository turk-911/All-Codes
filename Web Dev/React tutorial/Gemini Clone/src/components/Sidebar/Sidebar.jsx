import React, { useContext, useState } from "react";
import './Sidebar.css';
import {assets} from "../../assets/assets.js"
import { Context } from "../../context/Context";
const Sidebar = () => {
  const [extendedSideBar, setExtendedSideBar] = useState(false);
  const {onSend, previousPrompt, setRecent} = useContext(Context);
  return (
    <div className="sidebar">
      <div className="top">
        <img src={assets.menu_icon} alt="" className="menu" onClick={() => setExtendedSideBar(prev => !prev)}/>
        <div className="new-chat">
          <img src={assets.plus_icon} alt="" />
          {extendedSideBar ? <p>New Chat</p> : null}
        </div>
        {extendedSideBar ? (
          <div className="recent-chats">
            <p className="recent-chats-title">Recent</p>
            {previousPrompt.map((item, index) => {
              return (
                <div className="recent-entry">
                  <img src={assets.message_icon} alt="" />
                  <p>{item.slice(0, 18)}</p>
                </div>
              );
            })}
            <div className="recent-entry">
              <img src={assets.message_icon} alt="" />
              <p>What is React?</p>
            </div>
          </div>
        ) : null}
      </div>
      <div className="bottom">
        <div className="bottom-item recent-entry">
          <img src={assets.question_icon} alt="" />
          {extendedSideBar ? <p>Help</p> : null}
        </div>
        <div className="bottom-item recent-entry">
          <img src={assets.history_icon} alt="" />
          {extendedSideBar ? <p>History</p> : null}
        </div>
        <div className="bottom-item recent-entry">
          <img src={assets.setting_icon} alt="" />
          {extendedSideBar ? <p>Settings</p> : null}
        </div>
      </div>
    </div>
  );
}
export default Sidebar