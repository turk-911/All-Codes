import React from "react";
import { useTheme } from "../Context/ThemeContext";
import SpaceCanvas from "../../Canvas/SpaceCanvas";
import DayLightCanvas from "../../Canvas/DayLightCanvas";

const ViewAllPapers: React.FC = () => {
  const { isDarkMode } = useTheme();
  return (
    <div className="auth-wrapper">
      {isDarkMode ? <SpaceCanvas /> : <DayLightCanvas />}
      <div>
        <h2 className={`${isDarkMode ? "dark-h": "light-h"}`}>View All Papers</h2>
        <p className={`${isDarkMode ? "dark-p": "light-h"}`}>
          This is the page where students can view all previous year papers.
        </p>
      </div>
    </div>
  );
};

export default ViewAllPapers;
