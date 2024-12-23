import React from "react";
import './ReviewSubmission.css'
import ReviewSubmissionCard from "./ReviewSubmissionCard";
import SpaceCanvas from "../../Canvas/SpaceCanvas";
import { useTheme } from "../Context/ThemeContext";
import DayLightCanvas from "../../Canvas/DayLightCanvas";
const ReviewsSubmission: React.FC = () => {
    const { isDarkMode } = useTheme();
    return (
      <div className="div-wrapper">
        { isDarkMode ? <SpaceCanvas />: <DayLightCanvas />}
        <div className="top-div">
          <h2 className={`${isDarkMode ? "dark-h": "light-h"}`}>Review submissions</h2>
          <div className="something">
            <ReviewSubmissionCard
              title="Assignment 1"
              subject="Operating Systems"
              submissionDate="2024-9-10"
              isChecked={true}
              darkMode={isDarkMode}
            />
            <ReviewSubmissionCard
              title="Assignment 2"
              subject="Operating Systems"
              submissionDate="2024-9-10"
              isChecked={true}
              darkMode={isDarkMode}
            />
            <ReviewSubmissionCard
              title="Assignment 3"
              subject="Operating Systems"
              submissionDate="2024-9-10"
              isChecked={false}
              darkMode={isDarkMode}
            />
          </div>
        </div>
      </div>
    );
}
export default ReviewsSubmission;