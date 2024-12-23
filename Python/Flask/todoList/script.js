const apiUrl = "http://127.0.0.1:5000/tasks";
function fetchTasks() {
  fetch(apiUrl)
    .then((response) => response.json())
    .then((tasks) => {
      const taskList = document.getElementById("taskList");
      taskList.innerHTML = "";
      tasks.forEach((task) => {
        const taskItem = document.createElement("li");
        taskItem.className = task.completed ? "completed" : "";
        taskItem.innerHTML = `
                            <span>${task.title}</span>
                            <button onclick="deleteTask(${
                              task.id
                            })">Delete</button>
                            <input type="checkbox" ${
                              task.completed ? "checked" : ""
                            } onchange="toggleTask(${task.id}, this.checked)">
                        `;
        taskList.appendChild(taskItem);
      });
    });
}
document.getElementById("addTaskBtn").addEventListener("click", () => {
  const taskInput = document.getElementById("taskInput");
  const newTask = { title: taskInput.value };
  fetch(apiUrl, {
    method: "POST",
    headers: { "Content-Type": "application/json" },
    body: JSON.stringify(newTask),
  })
    .then((response) => response.json())
    .then(() => {
      taskInput.value = "";
      fetchTasks();
    });
});
function deleteTask(taskId) {
  fetch(`${apiUrl}/${taskId}`, { method: "DELETE" }).then(() => fetchTasks());
}
function toggleTask(taskId, completed) {
  fetch(`${apiUrl}/${taskId}`, {
    method: "PUT",
    headers: { "Content-Type": "application/json" },
    body: JSON.stringify({ completed: completed }),
  }).then(() => fetchTasks());
}
fetchTasks();
