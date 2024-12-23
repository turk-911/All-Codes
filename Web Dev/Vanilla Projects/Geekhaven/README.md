# DSA Sheet

This is a web-based application that provides a DSA sheet with problems, solutions, and video links, pulled from a remote API. The project includes several features, such as search functionality, dark mode, and the ability to mark questions as done, which persist across page reloads.

## Features

### 1. **Question Display Format**

- Overall topics are given by a banner.
- Clicking on a section expands it, revealing the questions within.

### 2. **Dark Mode Toggle**

- Users can switch between light and dark modes.
- The selected mode persists even after closing or reloading the browser.

### 3. **Mark as Done**

- Each question can be marked as "done" using a checkbox.
- The state of the checkbox (checked/unchecked) is saved in `localStorage` to ensure persistence across page reloads.

### 4. **Search Functionality**

- Users can search for specific questions using a search bar.
- Matching questions are displayed as a list of search results (similar to Google search results).

## API

The data for the DSA sheet is fetched from the following API:

`https://test-data-gules.vercel.app/data.json`

The data includes:

- Section titles (categories)
- Questions within each section (title, video link, problem links)

## Tech Stack

- **HTML**: Structure of the webpage.
- **CSS**: Styling of the webpage (including light and dark mode).
- **JavaScript**: Logic for the search functionality, dark mode toggle, and accordion.
- **localStorage**: Used to persist dark mode preferences and checkbox states.
- **Fetch API**: Used to retrieve data from the external API.

## How to Use

1. **Clone the Repository**:

   ```bash
   git clone https://github.com/turk-911/WebD-Selection-Task-1-IIB2023034.git
   cd dsa-sheet
   ```
2. **Open the Project**:
   Open the `index.html` file in your browser. You can do this by:

   - Double-clicking the `index.html` file, or
   - Running a simple HTTP server like `live-server` or using `http-server` in your terminal.
3. **Interacting with the Application**:

   - **Browse DSA Problems**: Use the accordion to navigate different categories of problems.
   - **Toggle Dark Mode**: Click the moon button next to the heading to switch between light and dark themes.
   - **Mark Questions as Done**: Check the box next to any question to mark it as done. This state will persist even after the page is reloaded.
   - **Search for Questions**: Use the search bar to find specific questions. The search results will be appended at the bottom of the page, and the accordion will be hidden during the search.

## Project Structure

```bash
.
├── index.html    # The main HTML file for the project
├── index.css     # CSS styling 
├── index.js     # JavaScript logic for search, dark mode, and localStorage
└── README.md     # Project documentation
```


# Live demo

https://turk-911.github.io/WebD-Selection-Task-1-IIB2023034/
