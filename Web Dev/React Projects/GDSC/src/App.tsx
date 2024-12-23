import React from "react";
import {
  BrowserRouter as Router,
  Route,
  Routes,
} from "react-router-dom";
import SignupPage from "./components/Authentication/SignupPage";
import LoginPage from "./components/Authentication/LoginPage";
import "./App.css";
import HeroPage from "./components/Hero/HeroPage";
import AdminPortal from "./components/Admin/AdminPage";
import StudentPortal from "./components/Student/StudentPortal";
import AssignmentUpload from "./components/Student/Assignment Upload/AssignmentUpload";
import ReviewsSubmission from "./components/Student/Review Submissions/ReviewSubmission";
import CategoryPapers from "./components/Student/Category Papers/CategoryPapers";
import ViewAllPapers from "./components/Student/View All Papers/ViewAllPapers";
import { ThemeProvider } from "./components/Student/Context/ThemeContext";
import PDFUpload from "./components/Admin/PDFUpload/PDFUpload";
const App: React.FC = () => {
  return (
    <ThemeProvider>
      <Router>
        <Routes>
          <Route path="/" element={<HeroPage />} />
          <Route path="/login" element={<LoginPage />} />
          <Route path="/signup" element={<SignupPage />} />
          <Route path="/admin" element={<AdminPortal />} />
          <Route path="/student" element={<StudentPortal />} />
          <Route path="/upload" element={<AssignmentUpload />} />
          <Route path="/review" element={<ReviewsSubmission />} />
          <Route path="/category" element={<CategoryPapers />} />
          <Route path="/view" element={<ViewAllPapers />} />
        </Routes>
      </Router>
    </ThemeProvider>
    // <StudentPortal />
  );

};

export default App;
