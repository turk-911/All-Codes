import React, { useState } from "react";
import { Link, useNavigate } from "react-router-dom";
import SpaceCanvas from "../Canvas/SpaceCanvas";
import "./Auth.css";
const LoginPage: React.FC = () => {
  const [login, setLogin] = useState('');
  const navigate = useNavigate();
  function handleClick() {
    if(login === 'admin@gmail.com') navigate('/admin');
    else navigate('/student');
  }
  return (
    <div className="auth-wrapper">
      <SpaceCanvas />
      <div className="auth-container">
        <div className="auth-box">
          <h1 className="auth-title">Login</h1>
          <form>
            <div className="input-container">
              <input
                type="text"
                placeholder="Enter your email"
                value={login}
                required
                onChange={(e) => setLogin(e.target.value)}
              />
            </div>
            <div className="input-container">
              <input
                type="password"
                placeholder="Enter your password"
                required
              />
            </div>
            <button type="submit" className="auth-button" onClick={handleClick}>
              Login 🚀
            </button>
          </form>
          <div className="signup-link">
            <p>
              Don't have an account? <Link to="/signup">Sign Up</Link>
            </p>
          </div>
        </div>
      </div>
    </div>
  );
};

export default LoginPage;
