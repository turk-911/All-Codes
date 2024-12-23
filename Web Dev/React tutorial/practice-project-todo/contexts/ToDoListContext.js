import { createContext, useContext } from "react";

export const ToDoContext = createContext({
    todos: [{
        id: 1,
        todo: "Todo message",
        completed: false,
    }],
    addTodo: (todo) => {},
    updatedTodo: (todo) => {},
    deleteTodo: (todo) => {},
    toggleComplete: (todo) => {},
});

export const useTodo = () => {
    useContext(ToDoContext);
}

export const TodoProvider = ToDoContext.Provider;