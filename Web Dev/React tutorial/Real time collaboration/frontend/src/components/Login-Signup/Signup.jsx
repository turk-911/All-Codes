import React from "react";
import assets from "../../assets/assets";

function Signup() {
  return (
    <div className="box-border flex flex-col justify-center items-center h-[100vh]">
      <div className="">
        <div className="w-[220px] mb-4">
          <img src={assets.logo} alt="" />
        </div>
      </div>
      <form action="" className="border">
        <div className="flex justify-between p-6">
          <label htmlFor="email" className="mr-6">
            User Email
          </label>
          <input type="email" className="border" />
        </div>
        <div className="flex justify-between p-6">
          <label htmlFor="password">Password</label>
          <input type="password" className="border" />
        </div>
      </form>
      <div className="flex justify-center items-center">
        <button className="border p-3 m-3 w-[328.06px] bg-blue-600 text-white rounded-sm">
          Sign Up{" "}
        </button>
      </div>
    </div>
  );
}

export default Signup;
