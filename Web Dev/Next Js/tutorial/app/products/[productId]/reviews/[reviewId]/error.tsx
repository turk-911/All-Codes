"use client";
export default function Error({ error, reset }: {
    error: Error,
    reset: () => void
}) {
    return (
        <div>
            {error.message} <button onClick={reset} className="bg-slate-500">Try Again</button>
        </div>
    )
}