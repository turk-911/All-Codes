import React from "react";
import { useTheme } from "../Context/ThemeContext";
import SpaceCanvas from "../../Canvas/SpaceCanvas";
import DayLightCanvas from "../../Canvas/DayLightCanvas";

const CategoryPapers: React.FC = () => {
  const { isDarkMode } = useTheme();
  return (
    <div className="auth-wrapper">
      {isDarkMode ? <SpaceCanvas /> : <DayLightCanvas />}
      <div className="main-div">
        <h2 className={`${isDarkMode ? "dark-h": "light-h"}`}>Category-wise Papers</h2>
        <p className={`${isDarkMode ? "dark-h": "light-h"}`}>
          This is the page where students can view papers sorted by category.
        </p>
      </div>
    </div>
  );
};

export default CategoryPapers;
