import React, { useEffect, useRef } from "react";

const DeveloperPage = () => {
  const canvasRef = useRef(null);

  useEffect(() => {
    const canvas = canvasRef.current;
    const ctx = canvas.getContext("2d");

    canvas.width = window.innerWidth;
    canvas.height = window.innerHeight;

    const stars = Array.from({ length: 300 }, () => ({
      x: Math.random() * canvas.width,
      y: Math.random() * canvas.height,
      radius: Math.random() * 2,
      alpha: Math.random(),
      speed: Math.random() * 0.02,
    }));

    function drawStars() {
      ctx.clearRect(0, 0, canvas.width, canvas.height);
      stars.forEach((star) => {
        ctx.beginPath();
        ctx.arc(star.x, star.y, star.radius, 0, Math.PI * 2);
        ctx.fillStyle = `rgba(255, 255, 255, ${star.alpha})`;
        ctx.fill();
        star.alpha += star.speed;
        if (star.alpha > 1 || star.alpha < 0) star.speed *= -1;
      });
      requestAnimationFrame(drawStars);
    }

    drawStars();

    const handleResize = () => {
      canvas.width = window.innerWidth;
      canvas.height = window.innerHeight;
    };
    window.addEventListener("resize", handleResize);
    return () => window.removeEventListener("resize", handleResize);
  }, []);

  return (
    <div className="relative flex items-center justify-center min-h-screen text-center text-white bg-gradient-to-br from-purple-900 via-purple-700 to-indigo-900 overflow-hidden">
      <canvas
        ref={canvasRef}
        className="absolute inset-0 z-[-1] w-full h-full"
      />

      <div className="container mx-auto p-4">
        <h1 className="text-4xl md:text-5xl font-bold mb-2 animate-pulse">
          GDSC Web Dev Team
        </h1>
        <p className="text-lg md:text-xl mb-6">
          Meet the creators of this website!
        </p>

        <div className="space-y-10">
          <div>
            <h2 className="text-3xl text-yellow-400 mb-4">Heads</h2>
            <div className="flex flex-wrap justify-center gap-5">
              {[...Array(3)].map((_, index) => (
                <div
                  key={index}
                  className="group w-[150px] h-[150px] rounded-lg overflow-hidden bg-white/10 backdrop-blur-sm border border-white/20 transition-all transform group-hover:scale-105 shadow-lg"
                >
                  <img
                    src="https://via.placeholder.com/150"
                    alt={`Head ${index + 1}`}
                    className="w-full h-full object-cover"
                  />
                </div>
              ))}
            </div>
          </div>

          <div>
            <h2 className="text-3xl text-yellow-400 mb-4">Members</h2>
            <div className="flex flex-wrap justify-center gap-5">
              {[...Array(5)].map((_, index) => (
                <div
                  key={index}
                  className="group w-[150px] h-[150px] rounded-lg overflow-hidden bg-white/10 backdrop-blur-sm border border-white/20 transition-all transform group-hover:scale-105 shadow-lg"
                >
                  <img
                    src="https://via.placeholder.com/150"
                    alt={`Member ${index + 1}`}
                    className="w-full h-full object-cover"
                  />
                </div>
              ))}
            </div>
          </div>
        </div>
      </div>
    </div>
  );
};

export default DeveloperPage;
