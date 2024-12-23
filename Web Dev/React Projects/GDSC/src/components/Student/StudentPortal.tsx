import React, { useState } from "react";
import SpaceCanvas from "../Canvas/AdminCanvas";
import DaylightCanvas from "../Canvas/DayLightCanvas";
import "./Student.css";
import PendingAssignmentCard from "./Pending Assignment/PendingAssignment";
import { Link } from "react-router-dom";
import { useTheme } from "./Context/ThemeContext";
const StudentPortal: React.FC = () => {
  const { isDarkMode, toggleTheme } = useTheme();
  const [menuOpen, setMenuOpen] = useState(false);
  const [searchQuery, setSearchQuery] = useState("");
  const toggleMenu = () => {
    setMenuOpen(!menuOpen);
  };
  const handleSearchChange = (e: React.ChangeEvent<HTMLInputElement>) => {
    setSearchQuery(e.target.value);
  };
  return (
    <div className="auth-wrapper">
      {isDarkMode ? <SpaceCanvas /> : <DaylightCanvas />}
      <div
        className={`student-portal ${isDarkMode ? "dark-mode" : "light-mode"}`}
      >
        <header className="portal-header">
          <h1 className={`${isDarkMode ? "dark-h" : "light-h"}`}>
            Alien's Portal 👽
          </h1>
          <button className="hamburger" onClick={toggleMenu}>
            &#9776;
          </button>
          <nav className={menuOpen ? "nav-open" : "nav-closed"}>
            <button
              className={`${isDarkMode ? "dark-span" : "light-span"}`}
              onClick={() => {
                setMenuOpen(false);
              }}
            >
              <Link to="/upload">Upload Comets</Link>
            </button>
            <button
              className={`${isDarkMode ? "dark-span" : "light-span"}`}
              onClick={() => {
                setMenuOpen(false);
              }}
            >
              <Link to="/review">Review Submissions</Link>
            </button>
            <button
              className={`${isDarkMode ? "dark-span" : "light-span"}`}
              onClick={() => {
                setMenuOpen(false);
              }}
            >
              <Link to="/category">Category-wise Papers</Link>
            </button>
            <button
              className={`${isDarkMode ? "dark-span" : "light-span"}`}
              onClick={() => {
                setMenuOpen(false);
              }}
            >
              <Link to="/view">View all Papers</Link>
            </button>
          </nav>
          <button className="theme-toggle" onClick={toggleTheme}>
            {isDarkMode ? "🌞" : "🌝"}
          </button>
        </header>

        <div className="search-bar">
          <input
            type="text"
            placeholder="Search the galaxy of academics"
            value={searchQuery}
            onChange={handleSearchChange}
          />
          <button type="button">🔍</button>
        </div>
        <h2 className={`pending-heading ${isDarkMode ? "dark-h" : "light-h"}`}>
          Pending comets assigned by the Guardians 🧑‍🚀
        </h2>
        <div className="pending-assignments">
          <PendingAssignmentCard
            title="Fork() examples"
            dueDate="2024-9-15"
            subject="Operating Systems"
            darkMode={isDarkMode}
          />
          <PendingAssignmentCard
            title="Class inheritance"
            dueDate="2024-9-15"
            subject="OOPS"
            darkMode={isDarkMode}
          />
          <PendingAssignmentCard
            title="Presentation"
            dueDate="2024-9-15"
            subject="FinTech"
            darkMode={isDarkMode}
          />
          <PendingAssignmentCard
            title="Mid sems"
            dueDate="2024-9-15"
            subject="All sbujects"
            darkMode={isDarkMode}
          />
        </div>
        <main></main>
      </div>
    </div>
  );
};

export default StudentPortal;
