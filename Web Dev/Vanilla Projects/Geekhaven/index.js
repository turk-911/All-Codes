const currentTheme = localStorage.getItem("theme") || "light-mode";
document.body.className = currentTheme;
const toggleBtn = document.getElementById("toggle-btn");
const youtube = "./assets/youtube.svg";
const practice = "./assets/practice.svg";
const url = "https://test-data-gules.vercel.app/data.json";
toggleBtn.addEventListener("click", function () {
  if (document.body.classList.contains("dark-mode")) {
    document.body.className = "light-mode";
    localStorage.setItem("theme", "light-mode");
  } else {
    document.body.className = "dark-mode";
    localStorage.setItem("theme", "dark-mode");
  }
});
fetch(url)
  .then((response) => {
    if (!response.ok) {
      throw new Error("something bad occurred");
    }
    return response.json();
  })
  .then((data) => {
    const container = document.getElementById("root");
    const containsSearchResults = document.querySelector(".search-results");
    let totalQuestions = 0;
    let completedQuestions = 0;
    const updateProgressBar = () => {
      const progressPercent = (completedQuestions / totalQuestions) * 100;
      const progressBarFill = document.getElementById("progress-bar-fill");
      const progressText = document.getElementById("progress-text");
      progressBarFill.style.width = `${progressPercent}%`;
      progressText.textContent = `${Math.round(progressPercent)}% completed`;
    };
    const initialDisplay = () => {
      data.data.forEach((section) => {
        const button = document.createElement("button");
        button.className = "banner";
        button.textContent = section.title;
        const expandedList = document.createElement("div");
        expandedList.className = "expandedList";
        totalQuestions += section.ques.length;
        section.ques.forEach((question) => {
          const mainDiv = document.createElement("div");
          const isChecked = localStorage.getItem(question.id) === "true";
          const isBookmarked = localStorage.getItem(`bookmark-${question.id}`) === "true";
          if (isChecked && document.body.className === "dark-mode")
            mainDiv.style.backgroundColor = "#009f93";
          if (isChecked && document.body.className === "light-mode")
            mainDiv.style.backgroundColor = "#2d936c";
          if (isChecked) completedQuestions++;
          mainDiv.innerHTML = `
                    <div class="top-div">
                    <div class="head-box">
                    <label>
                        <input type="checkbox" ${
                          isChecked ? "checked" : ""
                        } id="${question.id}">
                    </label>
                    <h3>${question.title}</h3>
                    </div>
                    <div class="icons">
                    <p><a href="${question.yt_link}" target="_blank">
                    <img src=${youtube} style="height: 40px; width: 50px" class="youtube" />
                    </a></p>
                    <p><a href="${
                      question.p1_link
                    }" target="_blank"><img src=${practice} style="height: 40px; width: 50px;" /></a></p>
                    ${
                      question.p2_link
                        ? `<p><a href="${question.p2_link}" target="_blank"><img src=${practice} style="height: 40px; width: 50px;" /></a></p>`
                        : `<p><a href="${question.p1_link}" target="_blank"><img src=${practice} style="height: 40px; width: 50px;" class="target" /></a></p>`
                    }
                    <p style="text-align: center;">
                      <img src="./assets/bookmark${
                        isBookmarked ? "-filled" : ""
                      }.svg" class="bookmark-icon" id="bookmark-${question.id}" style="height: 40px; width: 50px; cursor: pointer; margin-top: 10px;" />
                    </p>
                    </div>
                    </div>
                `;
          expandedList.appendChild(mainDiv);
          const checkbox = mainDiv.querySelector('input[type="checkbox"]');
          checkbox.addEventListener("change", function () {
            localStorage.setItem(question.id, checkbox.checked);
            if (checkbox.checked) {
              completedQuestions++;
            } else {
              completedQuestions--;
            }
            updateProgressBar();
          });
          const bookmarkIcon = mainDiv.querySelector(`#bookmark-${question.id}`);
          bookmarkIcon.addEventListener("click", function () {
            const isBookmarked = localStorage.getItem(`bookmark-${question.id}`) === "true";
            if (isBookmarked) {
              localStorage.removeItem(`bookmark-${question.id}`);
              bookmarkIcon.src = "./assets/bookmark.svg"; 
            } else {
              localStorage.setItem(`bookmark-${question.id}`, "true");
              bookmarkIcon.src = "./assets/bookmark-filled.svg"; 
            }
          });
        });
        container.appendChild(button);
        container.appendChild(expandedList);
      });
      const banners = document.querySelectorAll(".banner");
      banners.forEach((button) => {
        button.addEventListener("click", function () {
          this.classList.toggle("active");
          const expandedList = this.nextElementSibling;
          if (expandedList.style.display === "block") {
            expandedList.style.display = "none";
          } else {
            expandedList.style.display = "block";
          }
        });
      });
      updateProgressBar();
    };
    initialDisplay();
    const searchBar = document.querySelector(".search-bar");
    searchBar.addEventListener("input", function () {
      const searchTerm = this.value.toLowerCase();
      containsSearchResults.innerHTML = "";
      if (searchTerm === "") {
        container.style.display = "block";
        containsSearchResults.style.display = "none";
        return;
      }
      container.style.display = "none";
      containsSearchResults.style.display = "block";
      data.data.forEach((element) => {
        console.log('search');
        element.ques.forEach((question) => {
          if (question.title.toLowerCase().includes(searchTerm)) {
            const searchResult = document.createElement("div");
            searchResult.className = "search-result";
            searchResult.innerHTML = `
            <h3>${question.title}</h3>
            <p><a href="${question.p1_link}" target="_blank"><img src=${practice} style="height: 40px; width: 50px;" /></a></p>
            `;
            containsSearchResults.append(searchResult);
          }
        });
      });
    });
  })
  .catch((error) => {
    console.error(error);
  });