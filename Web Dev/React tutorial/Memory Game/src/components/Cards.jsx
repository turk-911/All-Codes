import React, { useState } from 'react'
import assets from '../assets/assets';
import Card from './Card';
import '../index.css'
function Cards() {
    const [items, setItems] = useState([
      { id: 1, img: assets.india, stat: "" },
      { id: 2, img: assets.afg, stat: "" },
      { id: 3, img: assets.russia, stat: "" },
      { id: 4, img: assets.albania, stat: "" },
      { id: 5, img: assets.spain, stat: "" },
      { id: 6, img: assets.denmark, stat: "" },
      { id: 1, img: assets.india, stat: "" },
      { id: 2, img: assets.afg, stat: "" },
      { id: 3, img: assets.russia, stat: "" },
      { id: 4, img: assets.albania, stat: "" },
      { id: 5, img: assets.spain, stat: "" },
      { id: 6, img: assets.denmark, stat: "" },
    ].sort(() => Math.random() - 0.5));
    const [prev, setPrev] = useState(-1);
    function check(current) {
        if(items[current].id === items[prev].id){
            items[current].stat = "correct";
            items[prev].stat = "correct";
            setItems([...items]);
            setPrev(-1);
        }
        else{
            items[current].stat = "wrong";
            items[prev].stat = "wrong";
            setItems([...items]);
            {
                setTimeout(() => {
                    items[current].stat = "";
                    items[prev].stat = "";
                    setItems([...items]);
                    setPrev(-1);
                }, 1000)
            }
        }
    }
    function handleClick(id) {
        if(prev === -1){
            items[id].stat = "active";
            setItems([...items]);
            setPrev(id);
        }
        else{
            check(id);
        }
    }
  return (
    <div className="container">
        { items.map((item, index) => (
            <Card key={index} item={item} id={index} handleClick={handleClick } />
        ))}
    </div>
  )
}

export default Cards