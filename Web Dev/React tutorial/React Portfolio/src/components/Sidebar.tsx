function Sidebar() {
  return (
    <div className="p-3 text-xl cursor-pointer h-screen w-[300px] bg-black text-white fixed z-2">
      <div className="flex items-center p-1 hover:translate-y-2 duration-[120ms]">
        <i className="fa-solid fa-house p-1"></i>
        <span className="p-1">Home</span>
      </div>
      <div className="flex items-center p-1 hover:translate-y-2 duration-[120ms]">
        <i className="fa-solid fa-code p-1"></i>
        <span className="p-1">About</span>
      </div>
      <div className="flex items-center p-1 hover:translate-y-2 duration-[120ms]">
        <i className="fa-brands fa-instagram p-1"></i>
        <span className="p-1">Instagram</span>
      </div>
      <div className="flex items-center p-1 hover:translate-y-2 duration-[120ms]">
        <i className="fa-brands fa-linkedin p-1"></i>
        <span className="p-1">LinkedIn</span>
      </div>
      <div className="flex items-center p-1 hover:translate-y-2 duration-[120ms]">
        <i className="fa-brands fa-youtube p-1"></i>
        <span className="p-1">Youtube</span>
      </div>
      <div className="flex items-center p-1 hover:translate-y-2 duration-[120ms]">
        <i className="fa-brands fa-github p-1"></i>
        <span className="p-1">Github</span>
      </div>
      <hr className="mt-4 md-4" />
      <div className="">
        <h3 className="text-2xl p-2 mt-2">Projects &gt;</h3>
        <div>
          <ul>
            <li className="p-1">
              <a
                href="https://qwerty-type.netlify.app"
                target="_blank"
                className="p-2 hover:translate-y-2 duration-[120ms]"
              >
                Qwerty Type Typing Test
              </a>
            </li>
            <li className="p-1">
                <a href="" className=" p-2 hover:translate-y-2 duration-[120ms]">Amazon UI Clone</a>
            </li>
            <li className="p-1">
                <a href="" className=" p-2 hover:translate-y-2 duration-[120ms]">Draw on Computer</a>
            </li>
            <li className="p-1">
                <a href="" className="p-2 hover:translate-y-2 duration-[120ms]">Expense Management App</a>
            </li>
          </ul>
        </div>
        <hr className="mt-4"/>
      </div>
    </div>
  );
}

export default Sidebar