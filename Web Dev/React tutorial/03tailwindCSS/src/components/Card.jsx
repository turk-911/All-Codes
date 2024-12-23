import React from "react";
function Card({username}) {
    console.log(username);
  return (
    <figure className="bg-slate-100 rounded-xl p-8 dark:bg-slate-800">
      <img
        className="w-24 h-24 rounded-full mx-auto"
        src="/sarah-dayan.jpg"
        alt=""
        width="384"
        height="512"
      />
      <div className="pt-6 space-y-4">
        <blockquote>
          <p className="text-lg font-medium">
            Lorem ipsum dolor sit amet consectetur adipisicing elit. Delectus facilis, voluptates illo animi placeat voluptas fuga. Saepe molestias dolore est laborum mollitia at. Officiis deserunt repudiandae inventore ullam aut nostrum.
          </p>
        </blockquote>
        <figcaption className="font-medium">
          <div className="text">{username}</div>
          <div>Staff Engineer, Algolia</div>
        </figcaption>
      </div>
    </figure>
  );
}
export default Card;