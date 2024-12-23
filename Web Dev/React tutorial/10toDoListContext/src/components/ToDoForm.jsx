import React, { useState } from 'react'
import { useTodo } from "../contexts/ToDoContexts.js"

function ToDoForm() {
    const [todo, setTodo] = useState("");
    const {addTodo} = useTodo();

    const add = (e) => {
        e.preventDefault()
        if (!todo) {
            return 
        }
        addTodo({ todo, completed: false})
        setTodo("")
    }
  return (
    <form className="flex" onSubmit={add}>
        <input type="text" 
        placeholder="Write tasks"
        value={todo}
        onChange={(e) => setTodo(e.target.value)}
        className="w-full border border-black/10 rounded-l-lg px-3 outline-none duration-150 bg-white/20 py-1.5"/>
        <button className="rounded-r-lg px-3 py-1 bg-green-600 text-white shrink-0" type="submit">
            Add
        </button>
    </form>
  )
}

export default ToDoForm