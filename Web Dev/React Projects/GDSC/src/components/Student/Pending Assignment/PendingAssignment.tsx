import React from "react";
import "./PendingAssignment.css";
interface PendingAssignmentCardProps {
  title: string;
  dueDate?: string;
  subject: string;
  darkMode: boolean;
}
const PendingAssignmentCard: React.FC<PendingAssignmentCardProps> = ({
  title,
  dueDate,
  subject,
  darkMode,
}) => {
  return (
    <div className={`pending-assignment-card ${darkMode ? "dark": ""}`}>
      <h3 className={`${darkMode ? "dark-heading": "light-heading"}`}>{title}</h3>
      <p className={`${darkMode ? "dark-p": "light-p"}`}>
        <strong>Subject:</strong> {subject}
      </p>
      <p>
        <strong>Due Date:</strong> {dueDate}
      </p>
      <button type="button">View Assignment</button>
    </div>
  );
};
export default PendingAssignmentCard;
