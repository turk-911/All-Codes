import React, { useState } from "react";
import { useTodo } from "../../10toDoListContext/src/contexts/ToDoContexts";

function ToDoItem(todo) {
  const [isEditable, setIsEditable] = useState(false);
  const [todoMsg, setTodoMsg] = useState(todo.todo);
  const { updateTodo, deleteTodo, toggleComplete } = useTodo();
  return <></>;
}

export default ToDoItem;
