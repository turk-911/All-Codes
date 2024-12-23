"use client"
import { useRouter } from "next/navigation";

export default function OrderProduct() {
    const router = useRouter();
    const handleClick = () => {
        console.log("Placed order");
        router.push("/forgot-password");
    }
    return (
        <>
            <h1>Order Product</h1>
            <button onClick={handleClick} className="p-5 bg-slate-300">Order now</button>
        </>
    )
}