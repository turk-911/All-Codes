import { createContext, useContext } from "react"

export const ToDoContext = createContext({
    todos: [
        {
            id: 1,
            todo: "Todo message",
            completed: false
        }
    ],
    addTodo: (todo) => {},
    updatedTodo: (id, todo) => {},
    deleteTodo: (id) => {},
    toggleComplete: (id) => {},
})

export const useTodo = () => {
    return useContext(ToDoContext)
}
export const ToDoProvider = ToDoContext.Provider;